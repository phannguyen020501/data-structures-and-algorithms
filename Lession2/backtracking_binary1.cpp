#include<stdio.h>
 int n;
int x[100];
void printSolution(){
	for(int i=1;i<=n;i++){
		printf("%d",x[i]);
	}
	printf("\n");
}
void TRY(int k){
	for(int v=0;v<=1;v++){
		if((v+x[k-1])<2){
			x[k]=v;
			if(k==n){
				printSolution();
			}else{
				TRY(k+1);
			}
		}
	}
}
int main(){
	printf("n=");
	scanf("%d",&n);
	x[0]=0;
	TRY(1);
	return 0;
}
