# 顺序表
## [Sequential List](https://github.com/AkashiNeko/DataStructure/tree/main/Sequential_List)

?顺序表接口（C语言实现）

### 顺序表结构
~~~c
typedef struct SeqList
{
    int* list;
    int len;
    int size;
}SL, * pSL;
~~~

###### 初始化和销毁
~~~c
void SLInit(pSL ps);
void SLDestory(pSL ps);
~~~

###### 遍历打印
~~~c
void SLPrint(const pSL ps);
~~~

###### 头插、尾插
~~~c
void SLPushFront(pSL ps, int new);
void SLPushBack(pSL ps, int new);
~~~

###### 头删、尾删
~~~c
void SLPopFront(pSL ps);
void SLPopBack(pSL ps);
~~~