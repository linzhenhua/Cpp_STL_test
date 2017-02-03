#include <stdio.h>
#include <stdlib.h>

#define OK      0
#define ERROR   -1
#define TRUE    1
#define FALSE   0

typedef int Status;
typedef int ElementType;

/********************************************************************************/
/*声明链表*/
/********************************************************************************/
typedef struct Node           //节点的具体结构
{
    ElementType data;
    struct Node *next;
}Position;

typedef struct          
{
    Position *head;   //头指针
	Position *rear;   //尾指针
	int length;       //链表当前的长度
}List;

Status LinkListInit( List *L);   //初始化链表
Status Add(List *L, ElementType *X);  //向链表加入元素
Status Insert(List *L, int site, ElementType *X);  //插入元素
Status Delete( List *L, ElementType *X);   //删除元素
void DestroyLinkList( List *L);  //销毁链表 

/********************************************************************************/
/*初始化链表*/
/********************************************************************************/
Status LinkListInit(List *L)   
{
	L->rear = L->head = (Position *)malloc(sizeof(Node));
	if( NULL == L->head )
		return ERROR;

	L->length  = 0;
    L->head->next = NULL;
	L->rear->next = NULL;

	return OK;
}

/********************************************************************************/
/*向链表加入元素*/
/********************************************************************************/
//工作原理：就是尾指针向后移动来加入元素
Status Add(List *L, ElementType *X)
{
	Position *TmpCell;

	TmpCell = (Position *)malloc(sizeof(Node));
	if(NULL == TmpCell)
		return ERROR;

	TmpCell->data = *X;
	TmpCell->next = NULL;
	L->rear->next = TmpCell;
	L->rear = TmpCell;

	L->length ++;

	return OK;
}

/********************************************************************************/
/*遍历链表*/
/********************************************************************************/
Status TraverseLinkList( List *L )
{
	Position *P = L->head->next ;

	while( NULL != P )
	{
		printf("%d ", P->data );
		P = P->next;
	}

    printf("\n");
	printf("当前链表长度为：%d\n", L->length );

   return OK;
}

/********************************************************************************/
/*插入元素*/
/********************************************************************************/
Status Insert( List *L, int site, ElementType *X)
{
	Position *p = L->head->next;//第一个结点是头结点，不使用，方便操作
	Position *TmpCell;
	int i = 0;

	// site不在合理范围
	if(L->length < site || site < 1) return ERROR;

	while( p != NULL && i < site)
	{
		p = p->next ;
		++i;
	}

	//if(p == NULL || i > site)
	//	return ERROR;

   TmpCell = (Position *)malloc( sizeof( Node ) );
	if(NULL == TmpCell)
		return ERROR;

    TmpCell->data = *X;
	TmpCell->next = p->next ;
	p->next = TmpCell;
	L->length++;
	
	return OK;
}

/********************************************************************************/
/*删除链表*/
/*--删除链表结点by元素--*/
/********************************************************************************/
Status Delete( List *L, ElementType *X)
{
	Position *p = L->head;
	Position *TmpCell;
	
	while(p->next != NULL && p->next ->data != *X)
		p= p->next ;

	if( p->next == L->rear )// 假如所求为尾指针
	{
		free(p->next);
		L->rear=p;//重置尾指针
		L->length--;
	}

    if( p->next != NULL )       //测试当前位置是否是链表的末尾的函数，当链表是空表时就有用了。。
	{
        TmpCell = p->next ;
		p->next = TmpCell->next ;
		free(TmpCell);
		L->length--;
	}

	return OK;
}

/********************************************************************************/
/*销毁链表*/
/********************************************************************************/
void DestroyLinkList(List *L)
{
	Position *p, *TmpCell;
   
	p = L->head ->next ;
	L->head ->next = NULL;
	
	while( p != NULL)
	{
		TmpCell = p->next;
		free(p);
		p = TmpCell;
	}
}
	
/********************************************************************************/
/*主函数*/
/********************************************************************************/
int main()
{
	List L;
	ElementType X ;
	int site;
	ElementType insertCell, deleteCell;

    LinkListInit( &L );

	printf("请输入链表元素，按0结束：");
	scanf("%d",&X);
    while(X)
	{
		Add( &L, &X);
		scanf("%d", &X);
	}

	TraverseLinkList( &L );

	printf("请输入要插入的元素：");
	scanf("%d", &insertCell);
	printf("请输入要插入的位置：");
	scanf("%d", &site);
    Insert( &L, site, &insertCell);

	TraverseLinkList( &L );

	printf("请输入要删除的元素：");
	scanf("%d", &deleteCell);
    Delete( &L, &deleteCell);

	TraverseLinkList( &L );

	DestroyLinkList( &L );

	return 0;
}