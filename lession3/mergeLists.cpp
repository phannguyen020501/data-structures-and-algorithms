#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int value;
	Node* next;
} Node;
Node* head1;
Node* head2;
void printList(Node* h){
	Node* p=h;
	while(p!=NULL){
		printf("%d ",p->value);
		p=p->next;
	}
}
Node* makeNode(int v){
	Node* p=(Node*)malloc(sizeof(Node));
	p->value=v;
	p->next=NULL;
	return p;
}
Node* insertLast(Node* h,int v){
	Node* p=makeNode(v);
	if(h==NULL){
		return p;
	}
	Node* q=h;
	while(q->next!=NULL){
		q=q->next;
	}
	q->next=p;
	return h;
}
Node* mergeLists(Node* head1,Node* head2){
	Node* result=NULL;
	if(head1==NULL) return head2;
	else if(head2==NULL) return head1; 	
	//recursively merging two list
	if(head1->value <= head2->value){
		result=head1;
		result->next=mergeLists(head1->next,head2);
	}else{
		result=head2;
		result->next=mergeLists(head1,head2->next);
	}
	return result;
}
int main(){
	for(int v=0;v<=20;v=v+2){
		head1=insertLast(head1,v);
	}
	for(int v=1;v<=9;v+=2){
		head2=insertLast(head2,v);
	}
	for(int v=1;v<=19;v++){
		head2=insertLast(head2,v);
	}
	printList(head1);
	printf("\n");
	printList(head2); 	
	Node* result=mergeLists(head1,head2);
	printf("\n");
	printList(result);
	
}
