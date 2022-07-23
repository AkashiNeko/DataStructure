# ˳���
## [Sequential List](https://github.com/AkashiNeko/DataStructure/tree/main/Sequential_List)

?˳���ӿڣ�C����ʵ�֣�

### ˳���ṹ
~~~c
typedef struct SeqList
{
    int* list;
    int len;
    int size;
}SL, * pSL;
~~~

###### ��ʼ��������
~~~c
void SLInit(pSL ps);
void SLDestory(pSL ps);
~~~

###### ������ӡ
~~~c
void SLPrint(const pSL ps);
~~~

###### ͷ�塢β��
~~~c
void SLPushFront(pSL ps, int new);
void SLPushBack(pSL ps, int new);
~~~

###### ͷɾ��βɾ
~~~c
void SLPopFront(pSL ps);
void SLPopBack(pSL ps);
~~~