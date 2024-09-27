#include<iostream>
#include<malloc.h>
typedef int Element;
typedef struct LNode{
	Element data;
	struct LNode *next;
}*node,Node;

node CreatLink(int n);
void DelNode(node head,Element e);
node GetPosition(node head,Element e);
void FreeLink(node head);
void PrintLink(node head);

int main(){
	int n,e;
	scanf("%d",&n);
	node head=CreatLink(n);
	//PrintLink(head);
	scanf("%d",&e);
	for(int i=0;i<n;i++){
		DelNode(head,e);
	}
	//node p=GetPosition(head,e);
	//printf("%d\n",p->data);
	//DelNode(head,e);
	//FreeLink(head);
	PrintLink(head);
	return 0;
}
node CreatLink(int n){
	node head=(node)malloc(sizeof(Node));
	head->next=NULL;
	node p=head;
	node q=NULL;
	for(int i=0;i<n;i++){
		q=(node)malloc(sizeof(Node));
		scanf("%d",&(q->data));
		q->next=p->next;
		p->next=q;
		p=q;
	}
	return head;
}

void DelNode(node head,Element e){
	node pos=GetPosition(head,e);
	//printf("%d\n",pos->data);
	if(pos){
		node front_pos=head;
		while(front_pos->next!=pos) front_pos=front_pos->next;
		front_pos->next=pos->next;
		free(pos);
		pos=NULL;
	}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
}
node GetPosition(node head,Element e){
	node pos=head->next;
	while(pos&&(pos->data!=e)){
		pos=pos->next;
	}
	return pos;
}

void FreeLink(node head){
	node p=head;
	while(p){
		p=p->next;
		free(head);
		head=p;
	}
}
void PrintLink(node head){
	if(head){
		node p=head->next;
		while(p){
			printf("%d ",p->data);
			p=p->next;
		}
		printf("\n");
	}else printf("Link list has no node\n");

}

