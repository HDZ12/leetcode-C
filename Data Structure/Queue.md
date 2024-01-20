# Queue-队列

Queue 是一个 FIFO（先进先出）的数据结构，并发中使用较多，可以安全地将对象从一个任务传给另一个任务。
# 队列常用操作
## 基于链表的实现

```C
typedef struct{
		int val;
		struct ListNode *next;
}ListNode;
typedef struct {
		ListNode *front,*rear;
		int queSize;	
} LinkedListQueue;
/*构造函数*/
LinkedListQueue *newLinkedListQueue(){
		LinkedListQueue *queue = (LinkedListQueue *)malloc(sizeof(LinkedListQueue));
		queue->front = NULL;
		queue->rear = NULL;
		queue->queSize = 0;
		return queue; 
}

/*释放队列*/
void delLinkedListQueue(LinkedListQueue *queue){
		for(int i = 0 ; i< queue->queSize && queue->front != NULL; i++ ){
				ListNode *temp = queue->front;
				queue->front = queue->front->next;
				free(temp);
		}
		free(queue);
}

/*获取队列的长度*/
int size(LinkedListQueue *queue){
		return queue->queSize;
}

/*判断队列是否为空*/
bool empty(LinkedListQueue *queue){
		return (size(queue) == 0);
}
/* 入队*/
void push(LinkedListQueue *queue,int num){
		ListNode *node = new ListNode(num);
		if(queue->front ==NULL){
			queue->front = node;
			queue->rear = node;
		}
		else{
			queue->rear->next = node;
			queue->rear = node;
		}
		queue->queSize++;
}
/* 访问队首元素*/
int peek(LinkeListQueue *queue){
		assert(size(queue)&&queue->front);
		return queue->front->val;
}
/* 出队*/
void pop(LinkedListQueue *queue){
		int num = peek(queue);
		ListNode *tmp = queue->front;
		queue->front = queue->front->next;
		free(tmp);
		queue->queSize--;
}
/* 打印队列 */
void printLinkeListQueue(LinkedListQueue *queue){
		int arr[queue->queSize];
		int i;
		ListNode *node;
		for(i=0,node=queue->front;i<queue->queSize;i++){
		arr[i] = node->val;
		node = node->next;
		}
		printArray(arr,queue->queSize);
}
```
## 基于数组的实现
由于数组删除首元素的时间复杂度为 `𝑂(𝑛)` ，这会导致出队操作效率较低。然而，我们可以采用以下巧妙方 法来避免这个问题。
我们可以使用一个变量 `front`指向队首元素的索引，并维护一个变量 `size` 用于记录队列长度。定义 `rear = front + size` ，这个公式计算出的 `rear` 指向队尾元素之后的下一个位置。 基于此设计，数组中包含元素的有效区间为`[front, rear - 1]`  
- **入队操作** ：将元素赋值给`rear`处，并将`size`+1。
- **出队操作** ：将`front`+1,size-1。
入队与出队均为一次操作，时间复杂度均为$O(1)$
在不断进行入队和出队的过程中，`front` 和 `rear` 都在向右移动，当它们到达数组尾 部时就无法继续移动了。为解决此问题，我们可以将数组视为首尾相接的“环形数组”。
对于环形数组，我们需要让 `front` 或 `rear` 在越过数组尾部时，直接回到数组头部继续遍历。这种周期性规律 可以通过“取余操作”来实现。
```C
typedef struct{
	int *nums;
	int front;
	int queSize;
	int queCapacity;
}ArrayQueue;
/* 构造函数*/
ArrayQueue *newArrayQueue(int capacity){
		ArrayQueue *queue = (ArrayQueue *)malloc(sizeof(ArrayQueue));
		queue->queCapacity = capacity;
		queue->nums = (int *)malloc(sizeof(int) * queue->queCapacity);
		que->front = queue->quesize = 0;
		return queue;
}
/*释放队列*/
void delArrayQueue(ArrayQueue *queue){
		free(queue->nums);
		free(queue);
}
/*获取队列的容量*/
int capacity(ArrayQueue *queue){
		return queue->queCapacity;
}
/* 获取队列的容量*/
int size(ArrayQueue *queue){
		returm queue->queSize;
}
/*判断队列是否为空*/
bool empty(ArrayQueue *queue){
		return (queue->queSize ==0);
}
/* 访问队首元素*/
int peek(ArrayQueue *queue){
		assert(size(queue) != 0 );
		return queue->nums[queue->front];
}
/*入队*/
void push(ArrayQueue *queue,int num){
		if(size(queue) == capacity(queue)){
			printf("队列已满\r\n");
			return;
		}
		int rear = (queue->front+queue->queSize) % queue->queCapacity;
		queue->nums[rear] = num;
		queue->queSize++;
}
/*出队*/
void pop(ArrayQueu *queue){
		int num = peek(queue);
		queue->front = (queue->front + 1) % queue->queCapacity
		queue->queueSize--;
}
/*打印队列*/
void printArrayQueue(ArrayQueue *queue){
	int arr[que->queSize];
	for(int i = 0, j = queue -> front ; i < queSize;i++,j++){
		arr[i] = queue->nums[j % queue->queCapacity];
	}
	printArray(arr,que->queSize);
}
```
# 双向队列
在队列中，我们仅能在头部删除或在尾部添加元素。提供 了更高的灵活性，允许在头部和尾部执行元素的添加或删除操作。
## 常用操作
### 链表实现
```c
/*双向链表节点*/
typedef struct DoublyListNode{
		int val;
		DoblyListNode *next;
		DoblyListNode *prev;
}DoublyListNode;

/*构造函数*/
DoublyListNode *newDoublyListNode(int num){
		DoublyListNode *new = (DoublyListNode *)malloc(sizeof(DoublyListNode));
		new->val = num;
		new->next = NULL;
		new->prev = NULL;
		return new;
}

/*删除函数*/
val delDoublyListNode(DoublyListNode *node){
		free(node)
}
/*基于双向节点的双向队列*/
typedef struct {
		DoublyListNode *front, *rear;
		int queSize;
}LinkedListQueue;

/*构造函数*/
LinkedListQueue *newLinkedListqueue(){
		LinkedListQueue *deque = (LinkedListQueue *)malloc(sizeof(LinkedListQueue));
		deque->front = NULL;
		deque->rear = NULL;
		deque->queSize = 0;
		return deque;
}
/*删除队列*/
void delLinkedListdeque(LinkedListQueue *deque){
		for(int i=0;i < deque->queSize;i++){
			DoublyListNode *tmp = deque->front;
			deque->front = deque->front->next;
		}
		free(deque);
}

int size(LinkedListQueue *deque){
		return deque->quesize;
}
/*判断队列是否为空*/
bool empty(LinkedListQueue *deque){
		return ((deque->queSize)==0);
}
/*入队*/
void push(LinkedListQueue *deque,int num,bool isFront){
		DoublyListNode *node = newDoublyListNode(num);
		if(empty(deque)){
			deque->front = deque->rear = node;
		}
		else if(isFront){
			deque->front->prev = node;
			node->next = deque->front;
			deque->front = node;
		}
		else{
			deque->rear->next = node;
			node->prev = deque->rear;
			deque->rear = node;
		}
		deque->queSize++;
}
/*队首入队*/
void pushFirst(LinkedListQueue *deque,int num){
		push(deque,num,true);
}
/*访问队首元素*/
int peekFirst(LinkedListQueue *deque){
		assert(size(deque) && deque->front);
		return deque->front->val;
}
/*访问队尾元素*/
int peekLast(LinkedListQueue *deque){
		assert(size(deque)&&deque->rear);
		return deque->rear->val;
}
/*出队*/
void pop(LinkedListQueue *deque,bool isFront){
		if(empty(deque))
			return -1;
		int val;
		if(isFront){
			val = peekFirst(deque);
			DoublyListNode *fnext = deque->front->next;
			if(fnext){
				fnext->prev = NULL;
				deque->front->next = NULL;
				delDoublyListNode(deque->front);
			}
			deque->front = fnext;
		}
		else{
			val = peekLast(deque);
			DoublyListNode *rprev = deque->rear->prev;
			if(rprev){
				rprev->next = NULL;
				deque->rear->prev =NULL;
				delDoublyListNode(deque->rear);
			}
			deque->rear = rprev;
		}
		deque->queSize---;
		return val;
}
/*打印队列*/
void printLinkedListQueue(LinkedListQueue *queue){
		int arr[deque->queSize];
		for(int i = 0 ; i < deque->queSize;i++){
			arr[0] = deque->front->val;
			deque->front = deque->front->next;
		}
		printArray(arr,deque->queSize);
}
```
## 基于数组实现
```c
typedef struct{
	int *nums;
	int front;
	int queSize;
	int queCapacity;
} ArrayDeque;
/*构造函数*/
ArrayDeque *newArrayDeque(int capacity){
		ArrayDeque *deque = (ArrayDeque *)malloc(sizeof(ArrayDeque));
		deque->queCapacity = capacity;
		deque->nums = (int *)malloc(sizeof(int) *deque->queCapacity);
		deque->front = deque->queSize = 0;
		return deque
}
/*删除函数*/
void delArrayDeque(ArrqyDeque *deque){
		free(deque->nums);
		free(deque);
}
/*获取容量*/
int capacity(ArrayDeque *deque){
		return deque->queCapacity;
}
/*获取长度*/
int size(ArrayDeque *deque){
		return deque->queSize;
}
/*判断是否为空*/
bool empty(ArrayDeque *deque){
		return (deque->queSize)==0;
}
/*计算环形数组索引*/
int dequeindex(ArrayDeque *deque,int i){
	return (i+capacity(deque)) % capacity(deque);
}
/*队首入队*/
void pushFirst(ArrayDeque *deque,int num){
		if(deque->queSize == capacity(queue)){
			printf("双向队列已满/r/n");
			return;
		}
		deque->front = dequeIndex(deque,deque->front-1);
		deque->nums[deque->front] = num;
		deque->queSize++;
}
/*队尾入队*/
void pushLast(ArrayDeque *deque,int num){
		if(deque->queSize==capacity(deque))
			return;
		int rear = dequeIndex(deque,que->front +que->queSize);
		deque->nums[rear] = num;
		deque->queSize++;
}
/*访问队首元素*/
int peekFirst(ArrayDeque *deque){
		assert(empty(deque)==0);
		return deque->nums[deque->front];
}
/*访问队尾元素*/
int peekLast(ArrayDeque *deque){
		assert(emprt(deque)==0);
		int last = dequeIndex(deque,deque->front+deque->queSize-1);
		return deque->nums[last];
}
/*队首出队*/
int popFirst(ArrayDeque *deque){
		int num = peekFirst(deque);
		deque->front = dequeIndex(deque,deque->front+1);
		deque->queSize--;
		return num;
}
/*队尾出队*/
int popLast(ArrayDeque *deque){
		int num = peekLast(deque)
		deque->queSize--;
		return num;
}
/*打印队列*/
void printArrayDeque(ArrayDeque *deque){
		int arr[deque->queSize];
		for(int i=0,j=deque->front;i<deque->queSize;i++){
			arr[i] = deque->nums[j%deque->capacity];
		}
		printArray(arr,deque->queSize);
}
```