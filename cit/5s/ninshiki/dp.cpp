#include"stdio.h"
#include"stdlib.h"
#include"math.h"

#define NAME_A "city011"
//#define NAME_A "city012"
//#define NAME_A "city021"
//#define NAME_A "city022"

//#define NAME_B "city011"
#define NAME_B "city012"
//#define NAME_B "city021"
//#define NAME_B "city022"

struct HD{
	char header1[200];
	char header2[200];
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

int main()
{
	
	HD a_hd[100];
	HD b_hd[100];
	
	int i,j,k;
	int x,y;
	
	////////////////////////////////////////////////////////////////////
	for( i=1; i<=100; i++){
	FILE *fp1;
	FILE *fp2;
	
	char filename1[100];
	char filename2[100];
	
	sprintf(filename1,"city_mcepdata\\%s/%s_%03d.txt",NAME_A,NAME_A,i);
	fp1=fopen(filename1,"r");
	
	sprintf(filename2,"city_mcepdata\\%s/%s_%03d.txt",NAME_B,NAME_B,i);
	fp2=fopen(filename2,"r");
	
	fscanf(fp1,"%s %s %d ",a_hd[i-1].header1,a_hd[i-1].header2,&a_hd[i-1].header3);
	fscanf(fp2,"%s %s %d ",b_hd[i-1].header1,b_hd[i-1].header2,&b_hd[i-1].header3);
	
	
	for( j=0; j<a_hd[i-1].header3; j++){
		for( k=0; k<15; k++){
			fscanf(fp1,"%f ", &a_data[i-1][j][k]);
		}
	}
	
	for( j=0; j<b_hd[i-1].header3; j++){
		for( k=0; k<15; k++){
			fscanf(fp2,"%f ", &b_data[i-1][j][k]);
		}
	}
	
	fclose(fp1);
	fclose(fp2);
	}
	
	/////////////////////////////////////////////////////////////////////////////////////
	
	for(int y=0; y<100; y++){
		for(int x=0; x<100; x++){
			
			//////////////////////////////////////////////////////////////
			for( i=0; i<a_hd[y].header3; i++){
				for( j=0; j<b_hd[x].header3; j++){
					for( k=0; k<15; k++){
					d[x][i][j]+=(a_data[y][i][k]-b_data[x][j][k])*(a_data[y][i][k]-b_data[x][j][k]);
					}
					d[x][i][j]=sqrt(d[x][i][j]);
				}
			}
			/////////////////////////////////////////////////////////////////////////////
			
			
			//////////////////////////////////////////////////////////////
			g[x][0][0]=d[x][0][0];
			
			for( i=1; i<a_hd[y].header3; i++){
				g[x][i][0]=g[x][i-1][0]+d[x][i][0];
			}
			for( j=1; j<b_hd[x].header3; j++){
				g[x][0][j]=g[x][0][j-1]+d[x][0][j];
			}
			
			
			for( i=1; i<a_hd[y].header3; i++){
				for( j=1; j<b_hd[x].header3; j++){
				g[x][i][j]=min(g[x][i][j-1]+d[x][i][j],g[x][i-1][j]+d[x][i][j],g[x][i-1][j-1]+2*d[x][i][j]);
				}
			}
			
			g[x][a_hd[y].header3-1][b_hd[x].header3-1]=g[x][a_hd[y].header3-1][b_hd[x].header3-1]/(a_hd[y].header3+b_hd[x].header3);
			/////////////////////////////////////////////////////////////////////////////
			
			if(x==0)min_number[0]=g[x][a_hd[y].header3-1][b_hd[x].header3-1] , min_number[1]=x;
			if(min_number[0]>g[x][a_hd[y].header3-1][b_hd[x].header3-1])min_number[0]=g[x][a_hd[y].header3-1][b_hd[x].header3-1], min_number[1]=x;
					
		}
			for( i=0; i<100; i++)
				for( j=0; j<200; j++)
					for( k=0; k<200; k++)
						g[i][j][k]=0,d[i][j][k]=0;
		printf("(%03d,%03d)=%f",y+1,(int)min_number[1]+1,min_number[0]);
		if(y==min_number[1])printf("\n"),count++;
		else printf("~\n");
	}
	printf("%3d(%s,%s)\n",count,NAME_A,NAME_B);
}
