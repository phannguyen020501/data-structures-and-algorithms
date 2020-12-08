#include <stdio.h>
#include <stdlib.h>
void insertionSort(int a[],int N){
	//index tu 0-> N-1
	for(int k=1;k<N;k++){
		int last=a[k];
		int j=k;
		while(j>0 && a[j-1]>last){
			a[j]=a[j-1];
			j--;
		}
		a[j]=last;
	}
}
void selectionSort(int a[],int N){
	//index tu 0->N-1
	for(int k=0;k < N;k++){
		int min=k;
		for(int i=k+1;i<N;i++){
			if(a[min]>a[i]){
				min=i;
			}
		}
		int tmp=a[min];
		a[min]=a[k];
		a[k]=tmp;
	}
		
}
void bubbleSort(int a[],int N){
	int swapped;
	do{
		swapped=0;
		for(int i=0;i<N-1;i++){
			if(a[i]>a[i+1]){
				int tmp=a[i+1];
				a[i+1]=a[i];
				a[i]=tmp;
				swapped=1;
			}
		}
	}while(swapped==1);
}

void mergeSort(int a[],int L,int R){
	
}

int main(){
	int a[]={5,7,3,8,1,2,9,4,6};
	//insertionSort(a,9);
	//selectionSort(a,9);
	bubbleSort(a,9);
	for(int i=0;i<9;i++){
		printf("%d ",a[i]);
	}
}
