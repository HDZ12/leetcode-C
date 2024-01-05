> 数组是一种线性数据结构，将同类型元素存储在连续的内存空间中。我们将元素在数组中的位置称为索引(index)。
# 数组常用操作
## 初始化数组
- 无初始值赋值为0
```C
int arr[3] = {0};
int nums[3] = { 0, 1, 2};
```
## 插入元素
如果想要在数组中间 插入一个元素，则需要将该元素之后的所有元素都向后移动一位，之后再把元素赋值给该索引。
```C
void insert(int *nums, int size, int num, int index){
  for(int i = size-1; i > index; i--){
    nums[i] = nums[i-1];
}
nums[index] = num;
}
```
## 删除元素
```C
void removeeItem(int *nums, int size, int index){
  for(int i = index;i<size-1,i++){
    nums[i] = nums[i+1];
  }
}
```
总的来看，数组的插入与删除操作有以下缺点。
- 时间复杂度高：数组的插入和删除的平均时间复杂度均为 𝑂(𝑛) ，其中 𝑛 为数组长度。
- 丢失元素：由于数组的长度不可变，因此在插入元素后，超出数组长度范围的元素会丢失。 
- 内存浪费：我们可以初始化一个比较长的数组，只用前面一部分，这样在插入数据时，丢失的末尾元素 都是“无意义”的，但这样做也会造成部分内存空间的浪费。
## 遍历数组
```C
void traverse(int *nums, int size){
  int count = 0;
  for(int i = 0;i < size;i++){
      count++;
  }
}
```
## 查找元素
```C
int find(int *nums,int size, int target){
    for(int i = 0;i < size;i++){
        if(i==target)
          return i;
  }
  return -1;
}
```
## 扩容数组
```C
int *extend(int *nums,int size, int enlarge){
  int *res = (int *)malloc(sizeof(size+enlarge));
  for(int i=0;i<size;i++){
      res[i] = nums[i];
  }
  for(int i=size;i<size+enlarge;i++){
      res[i] = 0;
}
retirn res;
}
```
# 数组优缺点
**数组存储在连续的内存空间内，且元素类型相同。这种做法包含丰富的先验信息，系统可以利用这些信息来 优化数据结构的操作效率**
- 空间效率高: 数组为数据分配了连续的内存块，无须额外的结构开销。 
- 支持随机访问: 数组允许在 𝑂(1) 时间内访问任何元素。
- 缓存局部性: 当访问数组元素时，计算机不仅会加载它，还会缓存其周围的其他数据，从而借助高速缓 存来提升后续操作的执行速度。\
**连续空间存储是一把双刃剑，其存在以下缺点。**
- 插入与删除效率低: 当数组中元素较多时，插入与删除操作需要移动大量的元素。 
- 长度不可变: 数组在初始化后长度就固定了，扩容数组需要将所有数据复制到新数组，开销很大。
- 空间浪费: 如果数组分配的大小超过了实际所需，那么多余的空间就被浪费了。
