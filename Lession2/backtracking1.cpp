#include <stdio.h>
int n;
int x[100];
bool m[100];
void printSolution(){
	for(int i=1;i<=n;i++){
		printf("%d ",x[i]);
	}
	printf("\n");
}
void TRY(int i){
	for(int v=1;v<=n;v++){
		if(!m[v]){
			x[i]=v;
			m[v]=true;
			if(i==n){
				printSolution();
			}else{
				TRY(i+1);
			}
			m[v]=false;
		}
	}
}

int main(){
	printf("n=");
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		m[i]=false;
	}
	TRY(1);
	return 0;
}
