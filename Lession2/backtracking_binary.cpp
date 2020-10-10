#include <stdio.h>
int x[100];
int n;
void printSolution(){
	for(int i=0;i<n;i++){
		printf("%d",x[i]);
	}
	printf("\n");
}
void TRY(int k){
	for(int v=0;v<=1;v++){
		x[k]=v;
		if(k==n-1) printSolution();
		else{
			TRY(k+1);
		}
	}
}
int main(){
	printf("n=");
	scanf("%d",&n);
	TRY(0);
	
}
