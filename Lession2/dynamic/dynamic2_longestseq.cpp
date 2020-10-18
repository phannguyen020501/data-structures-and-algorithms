#include <stdio.h>
#define MAX 100000
int n;
int x[MAX];
int p[MAX];
int trace[MAX];
int rs=-10000;
int result[MAX];
void input(char* fn){
    FILE* f=fopen(fn,"r");
    fscanf(f,"%d",&n);
    for(int i=1;i<=n;i++){
        fscanf(f,"%d",&x[i]);
    }
    fclose(f);
}
void dynamic(){
	p[1]=1;
	trace[1]=0;
	for(int i=2;i<=n;i++){
		int max=0;
		for(int j=1;j<=i;j++){
			if(x[i]>x[j]){
				max=p[j];
				trace[i]=j;
			}
		}
		p[i]=max+1;
		rs=rs>p[i]?rs:p[i];
	}
	for(int i=1;i<=n;i++){
		printf("%d ",p[i]);
	}
	printf("\n");
	for(int i=1;i<=n;i++){
		printf("%d ",trace[i]);
	}
	printf("\nlongest sub sequence: %d",rs);
	
}

int main(){
	char* fn="long-9.txt";
	input(fn);
	dynamic();

}
