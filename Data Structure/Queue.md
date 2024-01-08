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

```