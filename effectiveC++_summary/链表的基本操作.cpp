#include <stdio.h>
#include <stdlib.h>

#define OK      0
#define ERROR   -1
#define TRUE    1
#define FALSE   0

typedef int Status;
typedef int ElementType;

/********************************************************************************/
/*��������*/
/********************************************************************************/
typedef struct Node           //�ڵ�ľ���ṹ
{
    ElementType data;
    struct Node *next;
}Position;

typedef struct          
{
    Position *head;   //ͷָ��
	Position *rear;   //βָ��
	int length;       //����ǰ�ĳ���
}List;

Status LinkListInit( List *L);   //��ʼ������
Status Add(List *L, ElementType *X);  //���������Ԫ��
Status Insert(List *L, int site, ElementType *X);  //����Ԫ��
Status Delete( List *L, ElementType *X);   //ɾ��Ԫ��
void DestroyLinkList( List *L);  //�������� 

/********************************************************************************/
/*��ʼ������*/
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
/*���������Ԫ��*/
/********************************************************************************/
//����ԭ������βָ������ƶ�������Ԫ��
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
/*��������*/
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
	printf("��ǰ������Ϊ��%d\n", L->length );

   return OK;
}

/********************************************************************************/
/*����Ԫ��*/
/********************************************************************************/
Status Insert( List *L, int site, ElementType *X)
{
	Position *p = L->head->next;//��һ�������ͷ��㣬��ʹ�ã��������
	Position *TmpCell;
	int i = 0;

	// site���ں���Χ
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
/*ɾ������*/
/*--ɾ��������byԪ��--*/
/********************************************************************************/
Status Delete( List *L, ElementType *X)
{
	Position *p = L->head;
	Position *TmpCell;
	
	while(p->next != NULL && p->next ->data != *X)
		p= p->next ;

	if( p->next == L->rear )// ��������Ϊβָ��
	{
		free(p->next);
		L->rear=p;//����βָ��
		L->length--;
	}

    if( p->next != NULL )       //���Ե�ǰλ���Ƿ��������ĩβ�ĺ������������ǿձ�ʱ�������ˡ���
	{
        TmpCell = p->next ;
		p->next = TmpCell->next ;
		free(TmpCell);
		L->length--;
	}

	return OK;
}

/********************************************************************************/
/*��������*/
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
/*������*/
/********************************************************************************/
int main()
{
	List L;
	ElementType X ;
	int site;
	ElementType insertCell, deleteCell;

    LinkListInit( &L );

	printf("����������Ԫ�أ���0������");
	scanf("%d",&X);
    while(X)
	{
		Add( &L, &X);
		scanf("%d", &X);
	}

	TraverseLinkList( &L );

	printf("������Ҫ�����Ԫ�أ�");
	scanf("%d", &insertCell);
	printf("������Ҫ�����λ�ã�");
	scanf("%d", &site);
    Insert( &L, site, &insertCell);

	TraverseLinkList( &L );

	printf("������Ҫɾ����Ԫ�أ�");
	scanf("%d", &deleteCell);
    Delete( &L, &deleteCell);

	TraverseLinkList( &L );

	DestroyLinkList( &L );

	return 0;
}