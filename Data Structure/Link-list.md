# Link List-链表
<img src="https://github.com/HDZ12/leetcode-C/assets/99587726/d1761c6b-63c2-48bc-9a8d-7ac3a1381e0a" width=50% height=50%><img src="https://github.com/HDZ12/leetcode-C/assets/99587726/0454108e-b8dd-4f8a-accc-ecb84907fc50" width=50% height=50%>
链表是线性表的一种。线性表是最基本、最简单、也是最常用的一种数据结构。线性表中数据元素之间的关系是一对一的关系，即除了第一个和最后一个数据元素之外，其它数据元素都是首尾相接的。线性表有两种存储方式，一种是顺序存储结构，另一种是链式存储结构。我们常用的数组就是一种典型的顺序存储结构。

相反，链式存储结构就是两个相邻的元素在内存中可能不是相邻的，每一个元素都有一个指针域，指针域一般是存储着到下一个元素的指针。这种存储方式的优点是定点插入和定点删除的时间复杂度为 O(1)，不会浪费太多内存，添加元素的时候才会申请内存，删除元素会释放内存。缺点是访问的时间复杂度最坏为 O(n)。

顺序表的特性是随机读取，也就是访问一个元素的时间复杂度是O(1)，链式表的特性是插入和删除的时间复杂度为O(1)。

链表就是链式存储的线性表。根据指针域的不同，链表分为单向链表、双向链表、循环链表等等。
```C
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
  int data;
  struct Node *next;
} Node;

typedef struct LinkedList {
  Node* head;
  int size;
} LinkedList;
```
## 链表基本操作
1. **创建链表**
```C
Node *initlink(){
  Node *p = (Node *)malloc(sizeof(Node));
  Node *temp = p; //声明指针指向头节点，用于遍历链表
  for(int i=0;i<5;i++){
    Node *a = (Node *)malloc(sizeof(Node));
    a->data = i;
    a->next = NULL;
    temp->next = a;
    temp = temp->next;
  }
  return p;
}
```
2. **插入元素**
```C
Node *insertdata(Node *p ,int data,int add){
  
