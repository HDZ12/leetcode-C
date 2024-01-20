# 哈希表
通过建立`key`与`value`之间的映射，实现高效查询，输入一个`key`,在$O(1)$时间内获取相应的`value`。
## 哈希表简单实现
### 简单数组实现
```c
typedf struct {
	int key;
	char *val;
}Pair;
/*基于数组建议实现的哈希表*/
typedf struct {
	Pair *buckets[HASHTABLE_CAPACITY];
}ArrayHashMap;
/*构造函数*/
ArrayHsahMap *newArrayHashMap(){
		ArrayHashMap *hmap = malloc(sizeof(ArrayHashMap));
		return hmap;
}
/*删除函数*/
void delArrayHashMap(ArrayHashMap *hmap){
		for(int i=0;i<HASHTABLE_CAPACITY;i++){
			if(hmap->buckets[i] != NULL){
				free(hmap->buckets[i]->val);
				free(hmap->buckets[i]);
			}
		}
		free(hmap);
}
/*添加操作*/
void push(ArrayHashMap *hmap,const int key,const char *val){
		Pair  *Pair = malloc(sizeof(Pair));
		pair->key = key;
		Pair->val = malloc(strlen(val)+1);
		strcpy(Pair->val,val);
		int index = hashFunc(key);
		hash->buckets[index] = Pair;
}
/*删除操作*/
void removeITem(ArrayHashMap *hmap,const int key){
		int index = hashFunc(key);
		free(hmap->buckets[index]->val);
		free(hmap->buckets[index]);
		hmap->buckets[index] = NULL;
}
/*获取所有键值对*/
void pairSet(ArrayHashMap *hmap,MapSet *set) {
		Pair *entries;
		int  i = 0,index = 0;
		int total = 0;
		/*统计有效键值对数量*/
		for(int i=0;i<HASHTABLE_CAPACITY;i++){
			if(hmap->buckets[i] != NULL){
				total++;
			}
		}  
		entries = malloc(sizeof(Pair)*total);
		for(int i=0;i<HASHTABLE_CAPACITY;i++){
			if(hmap->buckets[i] !=NULL){
				entries[index].key = hmap->buckets[i]->key;
				entries[index].val = malloc(strlen(hmap->buckets[i]->val+1));
				strcpy(entries[index].val,hmap->buckets[i]->val);
				index++;
			}
		}
		set->set=entries;
		set->len=total;
}
/*获取所有键*/
void keySet(ArrayHashMap *hmap,MapSet *set){
		int *kets;
		int i =0,total=0;
		int index = 0;
		for(int i=0;i<hmap->HASHTABLE_CAPACITY;i++){
			if(hmap->buckets[i] !=NULL){
				total++;
			}
		}
		keys  = malloc(sizeof(int)*total);
		for(i=0;i<hmap->HASHTABLE_CAPACITY;i++){
			if(hmap->buckets[i] != NULL){
				keys[index] = hmap->buckets[i]->key;
				index++;
			}
		}
		set->set = keys;
		set->size = total;
}
```