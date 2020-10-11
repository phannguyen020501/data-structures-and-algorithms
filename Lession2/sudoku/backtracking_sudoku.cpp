#include <stdio.h>
int found=0;
bool m1[10][10];//m1[r][v] v da xuat hien tren hang r
bool m2[10][10];//m2[c][v] v da xuat hien tren cot v
bool m3[3][3][10]; //m3[i][j][v] v da xuat hien tren khoi [i][i]
int x[10][10];
bool check(int v,int r,int c){
	if(m1[r][v]) return false;
	if(m2[c][v]) return false;
	if(m3[(r-1)/3][(c-1)/3][v]) return false;
	return true;
}
void solution(){
	found++;
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			printf("%d ",x[i][j]);
		}
		printf("\n");
	}
	printf("-------------------\n");
}
void TRY(int r,int c){
	if(found == 3) return;
	for(int v=1;v<=9;v++){
		if(check(v,r,c)){
			x[r][c]=v;
			m1[r][v]=true;// v xuat hien tren hang r
			m2[c][v]=true;// v xuat hien tren cot c
			m3[(r-1)/3][(c-1)/3][v]=true;// v xuat hien tren khoi
			
			if(r==9 && c==9) solution();
			else{
				if(c<9){
					TRY(r,c+1);
				}else{
					TRY(r+1,1);
				}
			}
			m1[r][v]=false;// recover
			m2[c][v]=false;// recover
			m3[(r-1)/3][(c-1)/3][v]=false;// recover
			
		}
	}
}

int main(){
	for(int v=1;v<=9;v++){
		for(int r=1;r<=9;r++){
			m1[r][v]=false;
		}
		for(int c=1;c<=9;c++){
			m2[c][v]=false;
		}
		for(int x=0;x<3;x++){
			for(int y=0;y<3;y++){
				m3[x][y][v]=false;
			}
		}
	}
	TRY(1,1);
	return 0;
}
