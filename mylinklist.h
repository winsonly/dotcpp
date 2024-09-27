#ifndef _MYLINKLIST_H
#define _MYLINKLIST_H 
#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
} LNode,*LinkList; 

void CreatList(LinkList &L,int n);
Status ListInsert(LinkList &L,int i,ElemType &e);
Status ListDelete(LinkList &L,int i);
Status GetElem(LinkList &L,int i,ElemType &e);
Status ListShow(LinkList &L);


void CreatList(LinkList &L,int n){
	LinkList p=NULL;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	for(int i=0;i<n;i++){
		p=(LinkList)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		p->next=L->next;
		L->next=p;
	}
}
Status ListInsert(LinkList &L,int i,ElemType &e){
	LinkList pre=L,q;
	int cnt=0;
	while(pre && cnt<i-1){
		pre=pre->next;
		cnt++;
	}
	if(pre==NULL || cnt > i-1){
		return ERROR;
	}
	q=(LinkList)malloc(sizeof(LNode));
	q->data=e;
	q->next=pre->next;
	pre->next=q;
	return OK; 
}
Status ListDelete(LinkList& L,int i){
	LinkList pre=L;
	LinkList temp=NULL;
	int cnt=0;
	while(pre->next && cnt<i-1){
		pre=pre->next;
		cnt++;
	}
	if(cnt>i || pre->next==NULL) return ERROR;
	temp=pre->next;
	pre->next=temp->next;
	free(temp);
	return OK;
}
Status GetElem(LinkList& L,int i,ElemType& e){
	LinkList pos=L;
	int cnt=0;
	while(pos->next && cnt<i){
		pos=pos->next;
		cnt++;
	}
	if(!pos || cnt>i) return ERROR;
	e=pos->data;
	return OK;
}
Status ListShow(LinkList &L){
	LinkList pos=L->next;
	int cnt=0;
	while(pos){
		printf("%d ",pos->data);
		pos=pos->next;
		cnt++;
	}
	if(!cnt) return ERROR;
	return OK;
}

