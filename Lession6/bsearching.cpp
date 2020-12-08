#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000000
#define MAX_L 100

typedef struct Node{
	char* en_word;
	char* vn_meaning;
	Node* leftChild;
	Node* rightChild;
} Node;

char words[MAX][MAX_L];
int N;//so luong tu
Node* root;//root -> BST

Node* makeNode(char* k){
	Node* p=(Node*)malloc(sizeof(Node));
	p->en_word=k;
	p->vn_meaning=NULL;
	p->leftChild=NULL;
	p->rightChild=NULL;
	return p;
}

void loadData(char* filename){
	FILE* f=fopen(filename,"r");
	N=0;
	while(!feof(f)){
		fscanf(f,"%s",&words[N]);
		N++;
	}
	fclose(f);
}

void swap(int i,int j){
	char tmp[MAX_L];//tmp=a[i] a[i]=a[j] a[j]=tmp
	strcpy(tmp,words[i]);
	strcpy(words[i],words[j]);
	strcpy(words[j],tmp);
}

int partition(int L,int R,int index){
	char pivot[MAX_L];
	strcpy(pivot,words[index]);
	swap(index,R);
	int  storeIndex=L;
	for(int i=L;i<=R-1;i++){
		int c=strcmp(words[i],pivot);
		if(c<0){
			swap(storeIndex,i);
			storeIndex++;
		}
	}
	swap(storeIndex,R);
	return storeIndex;
}
void quickSort(int L,int R){
	if(L<R){
		int index=(L+R)/2;
		index=partition(L,R,index);
		quickSort(L,index-1);
		quickSort(index+1,R);
	}
}
Node* makeBST(int L,int R){
	if(L>R) return NULL;
	if(L==R) return makeNode(words[L]);
	int m=(L+R)/2;
	Node* r=makeNode(words[m]);
	r->leftChild=makeBST(L,m-1);
	r->rightChild=makeBST(m+1,R);
	return r;
}

int height(Node* r){
	if(r==NULL) return 0;
	int hl=height(r->leftChild);
	int hr=height(r->rightChild);
	return hl>hr?hl+1:hr+1;
}

Node* find(Node* r,char* w){
	if(r==NULL) return NULL;
	int c=strcmp(w,r->en_word);
	if(c==0) return r;
	else if(c<0) return find(r->leftChild,w);
	else return find(r->rightChild,w);
}
int main(){
	loadData("words.txt");
	quickSort(0,N-1);
	root=makeBST(0,N-1);
	printf("chieu cao cua cay: %d\n",height(root));
	while(1){
		char cmd[50];
		printf("enter command (find/set/quit):");
		scanf("%s",cmd);
		if(strcmp(cmd,"find")==0){
			//find a word
			char w[MAX_L];
			printf("word:");
			scanf("%s",w);
			Node* p=find(root,w);
			if(p==NULL) printf("word not found\n");
			printf("Found words %s : %s\n",p->en_word,p->vn_meaning);
		}
		if(strcmp(cmd,"set")==0){
			//set meaning
			char mean[MAX_L];
			char w[MAX_L];
			printf("word: ");
			scanf("%s",w);
			printf("vietnam meaning:");
			scanf("%s",mean);
			Node* p=find(root,w);
			if(p==NULL){
				printf("not found\n");
			}else{
				p->vn_meaning=mean;
			}
		}
		if(strcmp(cmd,"quit")==0){
			break;
		}
	}
	return 0;
}
