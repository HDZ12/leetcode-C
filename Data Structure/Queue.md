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