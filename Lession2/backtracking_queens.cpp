#include <stdio.h>
// xep n quan hau tren ban co vua sao cho k co 2 con hau nao an nhau
int n;
int x[100];
void printSolution(){
	for(int i=1;i<=n;i++){
		printf("%d ",x[i]);
	}
	printf("\n");
}
int check(int v,int k){
	//kiem tra v gan dc cho x[k] hay k
	for(int i=1;i<=k-1;i++){
		if(x[i]==v) return 0;
		if(x[i]+i==v+k) return 0;
		if(x[i]-i==v-k) return 0;
	}
	return 1;

}
void TRY(int k){
	for(int v=1;v<=n;v++){
		if(check(v,k)){
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
	TRY(1);
	return 0;
}
