# 栈（数组实现）
## [Stack](https://github.com/AkashiNeko/DataStructure/tree/main/Stack)

✨栈接口（C语言实现）

### 栈的结构
~~~c
typedef struct Stact
{
    DataType* data;
    int top;
    int capacity;
}ST, * pST;
~~~

###### 初始化和销毁
~~~c
void STInit(pST ps);
void STDestroy(pST ps);
~~~

###### 压栈
~~~c
void STPush(pST ps, DataType data);
~~~

###### 出栈
~~~c
void STPop(pST ps);
~~~

###### 取栈顶元素
~~~c
DataType STTop(pST ps);
~~~

###### 判空
~~~c
int STEmpty(pST ps);
~~~

###### 取栈中元素个数
~~~c
int STSize(pST ps);
~~~