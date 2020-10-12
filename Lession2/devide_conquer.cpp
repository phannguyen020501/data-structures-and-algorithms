#include <stdio.h>
int x[]={1,2,3,4,5,6,7};
int bsearch(int x[],int start,int finish,int y){
	if(start==finish){
		if(x[start]==y){
			return start;
		}else{
			return -1;
		}
	}else{
		int m=(start+finish)/2;
		if(x[m]==y) return m;
		if(x[m]<y){
			return bsearch(x,m+1,finish,y);
		}else{
			return bsearch(x,start,m-1,y);
		}
	}
}

int main(){
	int result=bsearch(x,0,6,3);
	printf("%d ",result);	
}
