#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
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

int main(){
	int cnt=0,j;
	scanf("%d",&cnt);
	LinkList l;
	CreatList(l,cnt);
	scanf("%d",&j);
	//string str;
	char str[10];
	int e,pos;
	while(j--){
        cin >> str;
        if (!strcmp(str,"show")) {
            if (!ListShow(l)) printf("Link list is empty");
            printf("\n");
        } else if (!strcmp(str,"get")) {
            scanf("%d", &pos);
            if (!GetElem(l, pos, e)) printf("get fail\n");
            else printf("%d\n", e);
        } else if (!strcmp(str,"insert")) {
            scanf("%d %d", &pos, &e);
            if (!ListInsert(l, pos, e)) printf("insert fail\n");
            else printf("insert OK\n");
        } else if (!strcmp(str,"delete")) {
            scanf("%d", &pos);
            if (!ListDelete(l, pos)) printf("delete fail\n");
            else printf("delete OK\n");
        }
	}
	return 0;
}

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

