#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int key;
	Node* prev;
	Node* next;
	//constructor
	Node(int k){
		key=k;
		prev=NULL;
		next=NULL;
	}
};
typedef struct DoublyLinkedList{
	Node* first;
	Node* last;
	DoublyLinkedList(){
		//constructor
		first=NULL;
		last=NULL;
	}
	void addLast(int k){
		Node* p=new Node(k);
		if(first==NULL && last==NULL){
			first=p;
			last=p;
			return;
		}
		last->next=p;
		p->prev=last;
		last=p;
		
	}
	void printLeft2Right(){
		Node* x;
		for(x=first;x!=NULL;x=x->next){
			printf("%d ",x->key);
		}
		printf("\n");
	}
	void printRight2Left(){
		Node* x;
		for(x=last;x!=NULL;x=x->prev){
			printf("%d ",x->key);
		}
		printf("\n");
	}
	void addFirst(int k){
		Node* p=new Node(k);
		if(first==NULL && last==NULL){
			first=p;
			last=p;
			return;
		}
		p->next=first;
		first->prev=p;
		first=p;
	}
	void insertAfter(int k,int k1){
		//node key=k after node key=k1;
		if(first==NULL && last==NULL) return;
		Node* x=new Node(k);
		if(last->key==k1){
			last->next=x;
			x->prev=last;
			last=x;
			return;
		}
		Node* q=first;
		while(q!=NULL){
			if(q->key==k1) break;
			q=q->next;
		}
		Node* y=q->next;
		q->next=x;
		x->next=y;
		y->prev=x;
		x->prev=q;
		return;
	}
	void insertBefore(int k,int k1){
		if(first==NULL && last==NULL) return;
		Node* x=new Node(k);
		if(first->key==k1){
			x->next=first;
			first->prev=x;
			first=x;
			return;
		}
		Node* q=first;
		while(q!=NULL){
			if(q->key==k1) break;
			q=q->next;
		}
		Node* y=q->prev;
		y->next=x;
		x->next=q;
		q->prev=x;
		x->prev=y;
		return;
	}
	void insertAtPosition(int k,int index){
		Node* p=first;
		int i=1;
		while(i<index && p!=NULL){
			p=p->next;
			i++;
		}
		Node* x=new Node(k);
		if(p==first){
			//chen vao first
			x->next=p;
			p->prev=x;
			first=x;
		}else if(p==NULL){
			//chen vao cuoi cung
			x->prev=p;
			p->next=x;
			last=x;
		}else{
			x->next=p;
			x->prev=p->prev;
			p->prev->next=x;
			p->prev=x;			
			
		}
	}
	void freeList(){
		Node* p=first;
		while(p!=NULL){
			Node* np=p->next;
			free(p);
			p=np;
		}
	}
	
};
int main(){

	DoublyLinkedList L;
	for(int i=1;i<=10;i++){
		L.addLast(i);
	}
	
	//L.insertAfter(6,1);
	//L.insertBefore(2,10);
	L.insertAtPosition(0,1);
	L.insertAtPosition(2,3);
	L.printLeft2Right();
	L.printRight2Left();
	L.freeList();
	return 0;
	
}
