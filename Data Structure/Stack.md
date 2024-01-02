# Stack-栈
栈是一种 **LIFO(Last In First Out)** 的数据结构，常用方法有添加元素，取栈顶元素，弹出栈顶元素，判断栈是否为空。
# 编程实现
## 数组实现
```C
#include<stdio.h>
#define MAXSIZE 20
typedef int ElemType
typedef struct{
  ElemType data[MAXSIZE];
  int top;
}SqStack;
/*初始化栈*/
SqStack* initStack(SqStack *S){
  S->top=-1;
  return S;
}
/*入栈操作*/
void push(SqStack *S,ElemType e){
  if(S->top == MAXSIZE - 1){
    printf("Stack overflow\n");
    return
  }
  S->data[++S->top] = e;
}
/*出栈操作*/
ElemType pop(SqStack *S){
  if(S->top == -1){
    printf("Empty Stack\n");
    return -1;
  }
  return s->data[S->top--];
}
```
## 链表实现
```C
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct lineStack{
    ElemType data;
    struct lineStack *next;
}lineStack;

/*入栈操作*/
lineStack* push(lineStack *stack,ElemType a){
  lineStack *line = (lineStack*)malloc(sizeof(lineStack));
  line->data = a;
  line->next = stack;
  stack = line;
  return stack;
}
/*出栈操作*/
ElemType pop(lineStack **stack){
    if(stack == NULL){
        printf("栈空，无法出栈\n");
        return -1;
    }
    lineStack *p = *stack;
    ElemType x = p->data;
    *stack = p->next;
    free(p);
    return x;
}
```
