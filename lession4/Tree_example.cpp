#include <stdio.h>
#include <stdlib.h>
struct Node{
	int id;
	Node* leftMostChild;
	Node* rightSibling;
};
Node* root;

Node* makeNode(int v){
	Node* p=(Node*)malloc(sizeof(Node));
	p->id=v;
	p->leftMostChild=NULL;
	p->rightSibling=NULL;
	return p;
}

Node* find(Node* r,int v){
	if(r==NULL) return NULL;
	if(r->id == v) return r;
	Node* q=r->leftMostChild;
	while(q!=NULL){
		Node* h=find(q,v);
		if(h!=NULL) return h;
		q=q->rightSibling;
	}
	return NULL;
}

void insert(int u,int v){
	//tao 1 nut co id =v, chen cao cuoi ds nut con cua nut co id=u;
	Node* p=find(root,u);
	if(p==NULL) return;
	Node* tmp=p->leftMostChild;
	if(tmp==NULL){
		p->leftMostChild=makeNode(v);
		return;
	}
	while(tmp->rightSibling!=NULL){
		tmp=tmp->rightSibling;
	}
	tmp->rightSibling=makeNode(v);
	return;
}

void printTree(Node* r){
	if(r==NULL) return;
	printf("%d: ",r->id);//print root;
	Node* tmp=r->leftMostChild;
	while(tmp !=NULL){
		printf("%d ",tmp->id);
		tmp=tmp->rightSibling;
	}
	printf("\n");
	//goi de quy cac cay cua r
	tmp=r->leftMostChild;
	while(tmp !=NULL){
		printTree(tmp);
		tmp=tmp->rightSibling;
	}
}

void preOrder(Node* r){
	if(r==NULL) return;
	printf("%d ",r->id);
	Node* tmp=r->leftMostChild;
	while(tmp!= NULL){
		preOrder(tmp);
		tmp=tmp->rightSibling;
	}
}

void inOrder(Node* r){
	if(r==NULL) return;
	Node* tmp=r->leftMostChild;
	inOrder(tmp);
	printf("%d ",r->id);
	if(tmp !=NULL){
		tmp=tmp->rightSibling;
	}
	while(tmp !=NULL){
		inOrder(tmp);
		tmp=tmp->rightSibling;
	}
	return;
}

void postOrder(Node* r){
	if(r==NULL) return;
	Node* tmp=r->leftMostChild;
	while(tmp != NULL){
		postOrder(tmp);
		tmp=tmp->rightSibling;
	}
	printf("%d ",r->id);
}

//dem so nut tren cay
int count(Node* r){
	if(r==NULL) return 0;
	int s=1;
	Node* tmp=r->leftMostChild;
	while(tmp!=NULL){
		s+=count(tmp);
		tmp=tmp->rightSibling;
	}
	return s;	
}
// dem nut la
int countLeaves(Node* r){
	if(r==NULL) return 0;
	int s=0;
	Node* tmp=r->leftMostChild;
	if(tmp==NULL) s=1;
	while(tmp!=NULL){
		s+=countLeaves(tmp);
		tmp=tmp->rightSibling;
	}
	return s;
}
// height
int heightNode(Node* p){
	if(p==NULL) return 0;
	int maxh=0;
	Node* a=p->leftMostChild;
	while(a!=NULL){
		int h=heightNode(a);
		if(h>maxh) maxh=h;
		a=a->rightSibling;
	}
	return maxh+1;
}

int height(int v){
	Node* p=find(root,v);
	return heightNode(p);
}
Node* parent(Node* p,Node* r){
	if(r==NULL) return NULL;
	Node* q=r->leftMostChild;
	while(q!=NULL){
		if(p==q) return r;
		Node* pp=parent(p,q);
		if(pp!=NULL) return pp;
		q=q->rightSibling;
	}
	return NULL;
}
int main(){
	root=makeNode(10);
	insert(10,11);
	insert(10,1);
	insert(10,3);
	insert(11,5);
	insert(11,4);
	insert(4,6);
	insert(4,9);
	insert(3,8);
	insert(3,2);
	insert(3,7);	
	printTree(root);
	printf("pre order:");
	preOrder(root);
	printf("\n");
	printf(" in order:");
	inOrder(root);
	printf("\n");
	printf("post order:");
	postOrder(root);
	printf("\nso nut tren cay: %d",count(root));
	printf("\nso nut la tren cay: %d",countLeaves(root));
	printf("\ndo cao cua nut %d: %d",4,height(4));
	Node* child=find(root,3);
	Node* x=parent(child,root);
	printf("\n%d",x->id);
	return 0;
} 
