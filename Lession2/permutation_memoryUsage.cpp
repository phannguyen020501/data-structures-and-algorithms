#include<stdio.h>
const int max=100;
int m[max][max];
int C(int k,int n){
	if(k==0 || k==n){
		m[k][n]=1;
	}
	if(m[k][n] <0){
		m[k][n]=C(k-1,n-1)+C(k,n-1);
		
	}
	return m[k][n];
}
int main(){
	for(int i=0;i<max;i++){
		for(int j=0;j<max;j++){
			m[i][j]=-1;
		}
	}
	printf("%d ",C(3,6));
	return 0;
}
