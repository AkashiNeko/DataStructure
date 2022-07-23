# 单链表
## [Singly Linked List](https://github.com/AkashiNeko/DataStructure/tree/main/Singly_Linked_List)

✨单链表接口（C语言实现）

### 单链表节点结构
~~~c
typedef struct SLinkList
{
    DataType data;
    struct SLinkList* next;
}SL, * pSL;
~~~

###### 遍历打印
~~~c
void SLPrint(pSL ps);
~~~

###### 头插、尾插
~~~c
void SLPushFront(pSL* ppHead, DataType data);
void SLPushBack(pSL* ppHead, DataType data);
~~~

###### 头删、尾删
~~~c
void SLPopFront(pSL* ppHead);
void SLPopBack(pSL* ppHead);
~~~

###### 查找节点
~~~c
pSL SLFindNode(pSL* ppHead, DataType data);
~~~

###### 指定位置插入和删除
~~~c
void SLInsert(pSL* ppHead, pSL pos, DataType data);
void SLErase(pSL* ppHead, pSL pos);
~~~

###### 指定位置之后插入和删除
~~~c
void SLInsertAfter(pSL pos, DataType data);
void SLEraseAfter(pSL pos);
~~~

###### 链表的销毁
~~~c
void SLDestroy(pSL* ppHead);
~~~