#include<iostream>
#include<malloc.h>
typedef struct Student{
	double number;
	double gread;
	struct Student * next;
} *node,Node;
//typedef Student* node;
node CreatLink(int n);
node MergeLinks(node L1,node L2);
void Order(node L);
void PrintLink(node head);
int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	node head1=CreatLink(m);
	
	node head2=CreatLink(n);
	//PrintLink(head1);
	//PrintLink(head2);
	head1=MergeLinks(head1,head2);
	Order(head1);
	PrintLink(head1);
	return 0;
}
node CreatLink(int n){		// 尾插法建立链表 
	node h=(node)malloc(sizeof(Node));
	h->next = NULL;
	node q=h;
	node p;
	for(int i=0;i<n;i++){
		p = (node)malloc(sizeof(Node));
		scanf("%lf %lf",&(p->number),&(p->gread));
		p->next = q->next;
		q->next = p;
		q = p;
	}
	return h;
}
node MergeLinks(node head1,node head2){
	node temp=head1;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	// head2 = head2->next;
	temp->next = head2->next;
	free(head2);
	return head1;
}
void Order(node head){		// 选择排序法
	int temp_number,temp_gread; 
	node p=head->next;

	while(p!=NULL){
		node min=p;
		node q=p->next;
		while(q!=NULL){
			if(min->number>q->number){
				min=q;
			}
			q=q->next;
		}
		temp_number=min->number;
		min->number=p->number;
		p->number=temp_number;
		
		temp_gread=min->gread;
		min->gread=p->gread;
		p->gread=temp_gread;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
		p = p->next;
	}
}
void PrintLink(node head){
	node p=head->next;
	free(head);
	while(p!=NULL){
		printf("%.0lf %.0lf\n",p->number,p->gread);
		head=p;
		p=p->next;
		free(head);
	}
}
