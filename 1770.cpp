#include<iostream>
#include<malloc.h>
using namespace std;
typedef int Element;
typedef struct Student{
	Element number;
	struct Student* next;
}*node,Node;
typedef pair<node,node> CirculList;

CirculList CreatList(int n);
void GameBegin(CirculList list,int n);
void DelNode(node pos,node prev);
void PrintList(CirculList list);

int main(){
	int n;
	scanf("%d",&n);
	CirculList list=CreatList(n);
	//node& head=list.first;
	//node& tail=list.second;
	//PrintList(list);
	GameBegin(list,n);
	//PrintList(list);
	return 0;
}
CirculList CreatList(int n){
	node head=(node)malloc(sizeof(Node));
	head->number=1;
	head->next=head;
	node tail=head;
	node temp=NULL;
	for(int i=2;i<=n;i++){
		temp=(node)malloc(sizeof(Node));
		temp->number=i;
		temp->next=tail->next;
		tail->next=temp;
		tail=temp;
	}
	CirculList list(head,tail);
	return list;
}
/*void DelNode(node pos){
	node temp=pos->next;
	pos=temp->next;
	free(temp);
}*/
void DelNode(node pos,node prev){
	node temp=pos;
	prev->next=pos->next;
	pos=pos->next;	
	free(temp);
	//pos=prev->next;
}
void GameBegin(CirculList list,int n){
	node pos=list.first;
	node prev=list.second;
	int i=1;
	while(n>1){
		if(i%3==0){
			DelNode(pos,prev);
			n--;
		}else {
			prev=pos;
			pos=pos->next;
		}
		i++;
	}
	printf("%d",pos->number);
}
void PrintList(CirculList list){
	node& head=list.first;
	node& tail=list.second;
	node temp=head;
	while(temp!=tail){
		printf("%d->",temp->number);
		temp=temp->next;
	}
	printf("%d\n",temp->number);
	printf("\n");
}
