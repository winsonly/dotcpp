#include<iostream>
#include<malloc.h>
using namespace std;
typedef int Element;
typedef struct Student{
	Element number;
	Element grade;
	struct Student* next;
}*node,Node;

node CreatLink(int n);
void DelNodes(node head,Element e);
void FreeLink(node head);
node GetExcept(node head1,node head2);
void PrintLink(node head);
int CountNodes(node head){
	int count=0;
	node p=head;
	while(p->next){
		p=p->next;
		count++;
	}
	return count;
}
int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	node head1=CreatLink(m);
	node head2=CreatLink(n);
	head1=GetExcept(head1,head2);
	int count=CountNodes(head1);
	printf("%d\n",count);
	PrintLink(head1);
	return 0;
}

node CreatLink(int n){
	node head=(node)malloc(sizeof(Node));
	head->next=NULL;
	node p=head;
	node q=NULL;
	for(int i=0;i<n;i++){
		q=(node)malloc(sizeof(Node));
		scanf("%d %d",&q->number,&q->grade);
		q->next=p->next;
		p->next=q;
		p=q;
	}
	return head;
}
void DelNodes(node head,Element e){
	node p=head;
	node temp=NULL;
	while(p->next){
		temp=p->next;
		if(temp->number==e){
			p->next=temp->next;
			free(temp);
		
		}
		p=p->next;
	}
	temp=NULL;	//·ÀÖ¹Ò°Ö¸Õë 
}
void FreeLink(node head){
	node temp=head;
	while(head){
		head=head->next;
		free(temp);
		temp=head;
	}
}

node GetExcept(node head1,node head2){
	node p2=head2->next;
	while(p2){
		DelNodes(head1,p2->number);
		p2=p2->next;
	}
	return head1;
}
void PrintLink(node head){
	node p=head->next;
	while(p) {
		printf("%d %d\n",p->number,p->grade);
		p=p->next;
	}
}

