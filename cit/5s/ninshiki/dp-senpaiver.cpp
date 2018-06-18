#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#define NAME_A "city011"
#define NAME_B "city021"

struct HD{
	char header1[100];
	char header2[100];
	int header3;
};

float a_data[100][200][15];
float b_data[100][200][15];

float d[100][200][200];
float g[100][200][200];

int count=0;

float min_number[2];
	
float min(float x, float y, float z){
	float k=x;
	
	if(k>y)k=y;
	if(k>z)k=z;
	
	return k;
}

int main(){
	
	HD a_hd[100];
	HD b_hd[100];
	
//ファイルデータの読み込み
//////////////////////////////////////////////////////////////////////////////////////////////
	for(int i=1; i<=100; i++){
	FILE *fp;
	FILE *fp2;
	
	char filename[100];
	char filename2[100];
	
	if(i<10)sprintf(filename,"%s/%s_00%d.txt",NAME_A,NAME_A,i);
	else if(i<100)sprintf(filename,"%s/%s_0%d.txt",NAME_A,NAME_A,i);
	else sprintf(filename,"%s/%s_%d.txt",NAME_A,NAME_A,i);
	fp=fopen(filename,"r");
	
	if(i<10)sprintf(filename2,"%s/%s_00%d.txt",NAME_B,NAME_B,i);
	else if(i<100)sprintf(filename2,"%s/%s_0%d.txt",NAME_B,NAME_B,i);
	else sprintf(filename2,"%s/%s_%d.txt",NAME_B,NAME_B,i);
	fp2=fopen(filename2,"r");
	
	fscanf(fp,"%s %s %d ",a_hd[i-1].header1,a_hd[i-1].header2,&a_hd[i-1].header3);
	fscanf(fp2,"%s %s %d ",b_hd[i-1].header1,b_hd[i-1].header2,&b_hd[i-1].header3);
	
	
	for(int j=0; j<a_hd[i-1].header3; j++){
		for(int k=0; k<15; k++){
			fscanf(fp,"%f ", &a_data[i-1][j][k]);
		}
	}
	
	for(int j=0; j<b_hd[i-1].header3; j++){
		for(int k=0; k<15; k++){
			fscanf(fp2,"%f ", &b_data[i-1][j][k]);
		}
	}
	
	fclose(fp);
	fclose(fp2);
	}
/////////////////////////////////////////////////////////////////////////////////////////
	
for(int y=0; y<100; y++){
	for(int x=0; x<100; x++){
				
		//局所距離計算
		////////////////////////////////////////////////////////////////////////
		for(int i=0; i<a_hd[y].header3; i++){
			for(int j=0; j<b_hd[x].header3; j++){
				for(int k=0; k<15; k++){
				d[x][i][j]+=(a_data[y][i][k]-b_data[x][j][k])*(a_data[y][i][k]-b_data[x][j][k]);
				}
				d[x][i][j]=sqrt(d[x][i][j]);
			}
		}
		////////////////////////////////////////////////////////////////////////
		
		//単語間距離計算
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		g[x][0][0]=d[x][0][0];
		
		for(int i=1; i<a_hd[y].header3; i++){
			g[x][i][0]=g[x][i-1][0]+d[x][i][0];
		}
		for(int j=1; j<b_hd[x].header3; j++){
			g[x][0][j]=g[x][0][j-1]+d[x][0][j];
		}
		
		
		for(int i=1; i<a_hd[y].header3; i++){
			for(int j=1; j<b_hd[x].header3; j++){
			g[x][i][j]=min(g[x][i][j-1]+d[x][i][j],g[x][i-1][j]+d[x][i][j],g[x][i-1][j-1]+2*d[x][i][j]);
			}
		}
		
		g[x][a_hd[y].header3-1][b_hd[x].header3-1]=g[x][a_hd[y].header3-1][b_hd[x].header3-1]/(a_hd[y].header3+b_hd[x].header3);
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		if(x==0)min_number[0]=g[x][a_hd[y].header3-1][b_hd[x].header3-1] , min_number[1]=x;
		if(min_number[0]>g[x][a_hd[y].header3-1][b_hd[x].header3-1])min_number[0]=g[x][a_hd[y].header3-1][b_hd[x].header3-1], min_number[1]=x;
				
	}
		//dとgの初期化
		for(int i=0; i<100; i++)
			for(int j=0; j<200; j++)
				for(int k=0; k<200; k++)
					g[i][j][k]=0,d[i][j][k]=0;

	if(y==min_number[1])printf("(%d,%d)=%f ○\n",y,(int)min_number[1],min_number[0]),count++;
	else printf("(%d,%d)=%f ×\n",y,(int)min_number[1],min_number[0]);
}
	printf("%d",count);
}