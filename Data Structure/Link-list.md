# Link List-链表
<img src="https://github.com/HDZ12/leetcode-C/assets/99587726/d1761c6b-63c2-48bc-9a8d-7ac3a1381e0a" width=50% height=50%><img src="https://github.com/HDZ12/leetcode-C/assets/99587726/0454108e-b8dd-4f8a-accc-ecb84907fc50" width=50% height=50%>
链表是线性表的一种。线性表是最基本、最简单、也是最常用的一种数据结构。线性表中数据元素之间的关系是一对一的关系，即除了第一个和最后一个数据元素之外，其它数据元素都是首尾相接的。线性表有两种存储方式，一种是顺序存储结构，另一种是链式存储结构。我们常用的数组就是一种典型的顺序存储结构。

相反，链式存储结构就是两个相邻的元素在内存中可能不是相邻的，每一个元素都有一个指针域，指针域一般是存储着到下一个元素的指针。这种存储方式的优点是定点插入和定点删除的时间复杂度为 O(1)，不会浪费太多内存，添加元素的时候才会申请内存，删除元素会释放内存。缺点是访问的时间复杂度最坏为 O(n)。

顺序表的特性是随机读取，也就是访问一个元素的时间复杂度是O(1)，链式表的特性是插入和删除的时间复杂度为O(1)。

链表就是链式存储的线性表。根据指针域的不同，链表分为单向链表、双向链表、循环链表等等。
```C
#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode{
  int val;
  struct ListNode *next;
} ListNode;
/*构造函数*/
ListNode *newListNode(int val){
  ListNode *node, *next;
  node = (ListNode *)malloc(sizeof(ListNode));
  node->val = val;
  node->next = NULL;
  return node;
}
```
## 链表基本操作
![image](https://github.com/HDZ12/leetcode-C/assets/99587726/fa6a21b9-e5d6-4764-b6e9-9eac47c913c0)

1. **初始化链表**
```C
ListNode* n0=newListNode(1);
ListNode* n1=newListNode(3);
ListNode* n2=newListNode(2);
ListNode* n3=newListNode(5);
ListNode* n4=newListNode(4);
n0->next = n1;
n1->next = n2;
n2->next = n3;
n3->next = n4;
```
2. **插入节点P**
```C
void insert(ListNode *n0,ListNode *p){
    ListNode *n1 = n0->next;
    p->next = n1;
    n0->next = p;
}
```
3. **删除节点**
```C
void removeeItem(ListNode *n0){
  if(!n0->next)
    return;
  ListNode *p = n0->next;
  ListNode *n1 = p->next;
  n0->next = n1;
  free(p);
}
```
4. **访问节点**
```C
/*访问索引为index的节点*/
ListNode *acess(ListNode *head, int index){
  while(head && head->next && index){
    head = head->next;
    index--;
}
return head;
}
```
5. **查找节点**
```C
void find(ListNode *head,int target){
  int index = 0;
  while(head){
      if(head->val == target)
          return index;
      head = head->next;
      index++;
}
return -1;
}
```
6. **反转链表**

    1. _单向链表_ \
    链表的基本形式是：1 -> 2 -> 3 -> null，反转需要变为3 -> 2 -> 1 -> null。这里要注意：
    - 访问某个节点 curt.next 时，要检验 curt 是否为 null
    - 要把反转后的最后一个节点（即反转前的第一个节点）指向 null。
     ```C
   ListNode *reverse(ListNode *head){
     ListNode *prev = NULL;
     ListNode *temp = NULL;
     while(head){
       temp = head->next;
       head->next = prev;
       prev = head;
       head = temp;
     }
     return prev;
   }
   ```
   2. _双向链表_\
   和单向链表的区别在于：双向链表的反转核心在于next和prev域的交换，还需要注意的是当前节点和上一个节点的递推。
  ```C
  typedef struct DListNode{
    int val;
    DListNode *prev;
    DlistNode *next;
  }DlistNode;

  DListNode* reverse(DListNode *head){
    DListNode *temp = NULL;
    while(head){
      temp = head->next;
      head->next = head->prev;
      head->prev = temp;
      if(temp == NULL){
        break;
      }
      head = temp;
  }
  return head;
  }
  ```
## 快慢指针
  快慢指针也是一个可以用于很多问题的技巧。所谓快慢指针中的快慢指的是指针向前移动的步长，每次移动的步长较大即为快，步长较小即为慢，常用的快慢指针一般是在单链表中让快指针每次向前移动2，慢指针则每次向前移动1。快慢两个指针都从链表头开始遍历，于是快指针到达链表末尾的时候慢指针刚好到达中间位置，于是可以得到中间元素的值。快慢指针在链表相关问题中主要有两个应用：

- 快速找出未知长度单链表的中间节点
设置两个指针 *fast、*slow 都指向单链表的头节点，其中*fast的移动速度是*slow的2倍，当*fast指向末尾节点的时候，slow正好就在中间了。
- 判断单链表是否有环
利用快慢指针的原理，同样设置两个指针 *fast、*slow 都指向单链表的头节点，其中 *fast的移动速度是*slow的2倍。如果 *fast = NULL，说明该单链表 以 NULL结尾，不是循环链表；如果 *fast = *slow，则快指针追上慢指针，说明该链表是循环链表。
```C
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

// 创建新的链表节点
ListNode* newListNode(int val) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// 使用快慢指针找出链表的中间节点
ListNode* findMiddle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// 使用快慢指针判断链表是否有环
int hasCycle(ListNode *head) {
    if (head == NULL) return 0;
    ListNode *slow = head, *fast = head->next;
    while (slow != fast) {
        if (fast == NULL || fast->next == NULL) return 0;
        slow = slow->next;
        fast = fast->next->next;
    }
    return 1;
}
```
  
        

  
  
