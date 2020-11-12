#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node{
	char c;
	Node* next;
};
typedef struct Stack{
	Node* top;
	Stack(){
		top=NULL;
	}
	void push(char c){
		Node* q=(Node*)malloc(sizeof(Node));
		q->c=c;
		q->next=top;
		top=q;
		
	}
	char pop(){
		if(empty()) return ' ';
		Node* tmp=top;
		char x=tmp->c;
		top=top->next;
		free(tmp);
		return x;
	}
	bool empty(){
		return top==NULL;
	}
};
bool match(char a,char b){
	if(a=='(' && b==')') return true;
	if(a=='{' && b=='}') return true;
	if(a=='[' && b==']') return true;
	return false;
}
bool check(char* s){
	Stack stack;
	for(int i=0;i<strlen(s);i++){
		if(s[i]=='[' || s[i]=='(' || s[i]=='{'){
			stack.push(s[i]);
		}else{
			if(stack.empty()) return false;
			char a=stack.pop();
			if(!match(a,s[i])) return false;
		}
	
	}
	return stack.empty();
}
int main(){
	char* s = "[({})[]()()[()(){}]]";
	char* s1="{{{})";
    bool ok = check(s);
    if(ok) printf("Y\n"); else printf("N\n");
	return 0;
}
