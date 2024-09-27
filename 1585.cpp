#include<iostream>
#include<malloc.h>

typedef struct Complex *node,Node;
struct Complex{
	double real;
	double image;
	node next;
};
node CreatLink(int n);
void FreeLink(node head);
std::pair<double,double> SumNodes(node head);
int main(){
	int n=10;
	// scanf("%d",&n);
	node head=CreatLink(n);
	std::pair<double,double> l=SumNodes(head);
	printf("%.0lf+%.0lfi\n",l.first,l.second);
	FreeLink(head);	
	return 0;
}
node CreatLink(int n){
	node head=(node)malloc(sizeof(Node));
	head->next=NULL;
	node q=NULL,p=head;
	for(int i=0;i<n;i++){
		q=(node)malloc(sizeof(Node));
		scanf("%lf %lf",&(q->real),&(q->image));
		p->next=p->next;
		p->next=q;
		p=q;
	}
	return head;
}
void FreeLink(node head){
	node p=head;
	while(p!=NULL){
		p=p->next;
		free(head);
		head=p;
	}
}
std::pair<double,double> SumNodes(node head){
	std::pair<double,double> l;
	int sumReal=0,sumImage=0;
	node p=head->next;
	while(p){
		sumReal += p->real;
		sumImage += p->image;
		p=p->next;
	}
	l.first=sumReal;
	l.second=sumImage;
	return l;
}

