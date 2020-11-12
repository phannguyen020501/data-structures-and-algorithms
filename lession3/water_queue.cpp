#include <stdio.h>
#include <stdlib.h>
typedef struct State{
	int x,y;
	State* next;
	State* parent;
	State(int ix,int iy){
		//constructor
		x=ix;
		y=iy;
		next=NULL;
		parent=NULL;
	}
};
typedef struct Queue{
	State* head;
	State* tail;
	Queue(){
		//constructor
		head=NULL;
		tail=NULL;
	}
	void push(State* s){
		if(empty()){
			head=s;
			tail=s;
			return;
		}
		tail->next=s;
		tail=s;
		
	}
	State* pop(){
		if(empty()) return NULL;
		if(head==tail){
			State* x=head;
			head=NULL;
			tail=NULL;
			return x;
		}
		State* tmp=head;
		head=head->next;
		return tmp;
	}
	bool empty(){
		return head==NULL&& tail==NULL;
	}
};
Queue Q;
bool visited[1000][1000];//check visited[x][y]==true meaned (x,y) was appeared
State* target;
State* start;
int a,b,c;
bool finalState(State* s){
	return s->x==c || s->y==c;
}
bool fill1(State* s){
	if(visited[a][s->y]) return false;
	State* p=new State(a,s->y);
	p->parent=s;
	Q.push(p);
	visited[p->x][p->y]=true;
	if(finalState(p)){
		target=p;
		return true;
	}
	return false;
}
bool fill2(State* s){
	if(visited[s->x][b]) return false;
	State* p=new State(s->x,b);
	p->parent=s;
	Q.push(p);
	visited[p->x][p->y]=true;
	if(finalState(p)){
		target=p;
		return true;
	}
	return false;
}
bool pour1to2(State* s){
	if(s->x+s->y > b){
		if(visited[s->x + s->y- b][b]) return false;
		State* p=new State(s->x + s->y -b,b);
		p->parent=s;
		Q.push(p);
		visited[p->x][p->y]=true;
		if(finalState(p)){
			target=p;
			return true;
		}
		return false;	
	}else{
		if(visited[0][s->x + s->y]) return false;
		State* p=new State(0,s->x + s->y );
		p->parent=s;
		Q.push(p);
		visited[p->x][p->y]=true;
		if(finalState(p)){
			target=p;
			return true;
		}
		return false;
	}
}
bool pour2to1(State* s){
	if(s->x + s->y >a){
		if(visited[a][s->x + s->y -a]) return false;
		State* p=new State(a, s->x + s->y -a);
		p->parent=s;
		Q.push(p);
		visited[p->x][p->y]=true;
		if(finalState(p)){
			target=p;
			return true;
		}
		return false;
	}else{
		if(visited[s->x + s->y][0]) return false;
		State* p=new State(s->x + s->y,0);
		p->parent=s;
		Q.push(p);
		visited[p->x][p->y]=true;
		if(finalState(p)){
			target=p;
			return true;
		}
		return false;
	}	
}
bool empty1(State* s){
	if( visited[0][s->y]) return false;
	State* p=new State(0,s->y);
	p->parent=s;
	Q.push(p);
	visited[p->x][p->y]=true;
	if(finalState(p)){
		target=p;
		return true;
	}
	return false;
}
bool empty2(State* s){
	if(visited[s->x][0]) return false;
	State* p=new State(s->x,0);
	p->parent=s;
	Q.push(p);
	visited[p->x][p->y]=true;
	if(finalState(p)){
		target=p;
		return true;
	}
	return false;
}
void process(){
	start= new State(0,0);
	Q.push(start);
	target=NULL;
	visited[0][0]=true;
	while(!Q.empty()){
		State* s=Q.pop();
		printf("pop (%d,%d)\n",s->x,s->y);
		//fill full 1
		bool ok=fill1(s);
		if(ok) break;
		ok=fill2(s);
		if(ok) break;
		ok=pour1to2(s);
		if(ok) break;
		ok=pour2to1(s);
		if(ok) break;
		ok=empty1(s);
		if(ok) break;
		ok=empty2(s);
		if(ok) break;
	}
	printf("print result\n");
	if(target==NULL){
		printf("no solution\n");
	}else{
		State* s=target;
		while(s!= start){
			printf("(%d,%d)\n",s->x,s->y);
			s=s->parent;
		}
		printf("(%d,%d)\n",s->x,s->y);
	}
	
}
void init(){
	for(int i=0;i<1000;i++){
		for(int j=0;j<1000;j++){
			visited[i][j]=false;
		}
	}
}
int main(){
	a=4;
	b=19;
	c=17;
	init();
	process();
	return 0;
} 
