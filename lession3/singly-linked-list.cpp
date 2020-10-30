#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	Node* next;
}Node;

Node* head;

void printList(Node* h){
	Node* p=h;
	while(p!=NULL){
		printf("%d ",p->value);
		p=p->next;
	}
}
Node* makeNode(int v){
	Node* q=(Node*)malloc(sizeof(Node));//OS cap phat bo nho
	q->value=v;
	q->next=NULL;
		return q;
}
Node* insertLast(Node* h,int v){
	Node* q=makeNode(v);
	Node* p=h;
	if(h==NULL){
		return q;
	}
	while(p->next != NULL){
		p=p->next;
	}
	p->next=q;
	return h;
}
Node* insertBefore(Node* h,int v,int u){
	Node* p=h;
	Node* q=makeNode(v);
	if(h==NULL) return h;
	if(h->value==u){
		q->next=p;
		return q;
	}
	while(p->next !=NULL){
		if(p->next->value==u) break;
		p=p->next;
	}
	q->next=p->next;
	p->next=q;
	return h;
}
Node* remove(Node* h,int u){
	if(h==NULL) return h;
	if(h->value==u){
		Node* tmp=h->next;
		free(h);
		return tmp;
	}
	Node* p=h;
	while(p->next!=NULL){
		if(p->next->value==u) break;
		p=p->next;
	}
	if(p->next==NULL) return h;
	Node* tmp=p->next;
	p->next=p->next->next;
	free(tmp);
	return h;
}
Node* removeRecursion(Node* h,int u){
	if(h==NULL) return h;
	if(h->value==u){
		Node* tmp=h->next;
		free(h);
		return tmp;
		
		
	}
	h->next=removeRecursion(h->next,u);
	return h;
}
Node* removeRecursionAll(Node* h,int u){
	if(h==NULL) return h;
	if(h->value==u){
		h=h->next;
		h=removeRecursionAll(h,u);
		return h;
	}else{
		h->next=removeRecursionAll(h->next,u);
		return h;
	}

}

Node* removeAll(Node* h,int u){
	if(h->value==u){
		Node* tmp=h->next;
		free(h);
		Node* q=tmp;
		while(q->next!=NULL){
			if(q->next->value==u){
				Node* x=q->next;
				q->next=x->next;
				free(x);
			}
			else{
				q=q->next;
			}
		}
		return tmp;
	}
		else{
		Node* q=h;
	
	    while(q->next!=NULL){
		if(q->next->value==u){
			Node* x=q->next;
			q->next=x->next;
			free(x);
		}
		else{
			q=q->next;
		}
	}
	return h;
}
}
Node* insertBeforeRecursion(Node* h,int v,int u){
	if(h==NULL) return h;
	if(h->value==u){
		Node* x=makeNode(v);
		x->next=h;
		return x;
	}
	h->next=insertBeforeRecursion(h->next,v,u);
	return h;
	
}
void freeList(Node* h){
	if(h==NULL) return;
	free(h->next);
	return;
}
int main(){
	for(int v=1;v<=10;v++){
		head=insertLast(head,v);
	}
	for(int v=1;v<=10;v++){
		head=insertLast(head,v);
	}
	for(int v=1;v<=10;v++){
		head=insertLast(head,v);
	}
	head=insertLast(head,3);
	//head=insertLast(head,1);
	
	//head=insertBefore(head,5,3);
	//head=removeRecursion(head,3);
	//head=removeRecursion(head,1);
	printList(head);
	printf("\n");
	//head=removeAll(head,1);
	//head=removeAll(head,2);
	//head=insertBeforeRecursion(head,6,1);
	head=removeRecursionAll(head,3);
	//head=removeAll(head,1);
	printList(head);
	freeList(head);
	return 0;
}
