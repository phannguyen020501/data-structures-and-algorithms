#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000
int a[MAX];
int n;
void input(FILE* fn){
    FILE* f=fopen(fn,"r");//mở file đọc dừ liêu
    fscanf(f,"%d",&n);
    for(int i=0;i<n;i++){
        fscanf(f,"%d",&a[i]);
    }
    fclose(f);//đóng file
    //printf("%d:",n);
    //for(int i=0;i<n;i++){
       // printf("%d ",a[i]);
    //}
}
void genData(char* fn,int n){
    srand(time(NULL));

    FILE* f = fopen(fn,"w");
    fprintf(f,"%d\n",n);
    for(int  i = 1 ; i <= n; i++){
        int x = 500-rand()%1000;
        fprintf(f,"%d ",x);
    }
    fclose(f);
}
void algo1(){
    int rs = -100000000;
    for(int i = 0; i < n; i++){
        int T = 0;
        for(int j = i; j < n; j++){
            T += a[j];
            rs = T > rs ? T : rs;
        }
    }
    printf("result=%d",rs);
}
void algo2(){
    int rs=-10000000;
    int s=a[0];
    for(int i=1;i<n;i++){
        if(s>0){
            s=s+a[i];
        }
        else {
            s=a[i];
        }
        rs=s>rs?s:rs;
    }

    printf("result=%d",rs);
}
int main(){
    //char* filename="seq-8.txt";
    char* filename="seq-10000.txt";
    //genData(filename,1000);
    input(filename);
    algo1();
}
