#include <stdio.h>;
int n,k;
int x[100];
void printSolution(){
	for(int i=1;i<=k;i++){
		printf("%d ",x[i]);
	}
	printf("\n");
}
void TRY(int i){
	for(int v=x[i-1]+1;v<=n;v++){
		x[i]=v;
		if(i==k){
			printSolution();
		}else{
			TRY(i+1);
		}
		
	}
}
int main(){
	printf("n=");
	scanf("%d",&n);
	printf("k=");
	scanf("%d",&k);
	x[0]=0;
	TRY(1);
	return 0;
}
