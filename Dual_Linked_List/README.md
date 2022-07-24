# 双链表
## [Dual Linked List](https://github.com/AkashiNeko/DataStructure/tree/main/Dual_Linked_List)

✨双链表接口（C语言实现）

### 双链表节点结构
~~~c
typedef struct DLinkList
{
	struct DLinkList* next;
	struct DLinkList* prev;
	DataType data;
}DL, * pDL;
~~~

###### 初始化头节点（哨兵位）
~~~c
pDL DLInit();
~~~

###### 遍历打印
~~~c
void DLPrint(pDL phead);
~~~

###### 头插、尾插
~~~c
void DLPushFront(pDL phead, DataType data);
void DLPushBack(pDL phead, DataType data);
~~~

###### 头删、尾删
~~~c
void DLPopFront(pDL phead);
void DLPopBack(pDL phead);
~~~

###### 查找节点
~~~c
pDL DLFindNode(pDL phead, DataType data);
~~~

###### 指定位置插入和删除
~~~c
void DLInsert(pDL pos, DataType data);
void DLErase(pDL pos);
~~~

###### 链表的销毁
~~~c
void DLDestroy(pDL phead);
~~~