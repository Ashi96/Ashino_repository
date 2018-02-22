//ガウス・サイデル法
#include<stdio.h>
#define NUMBER 10

int main(void){
	double matrix[NUMBER][NUMBER]={0};
	double answer[NUMBER][1]={0};
	int row,column;
	int i,j;

	puts("---------------------行数・列数入力--------------------");
	do{
		printf("行数を入れてください:");
		scanf("%d",&row);
		if(row<=0||row>=NUMBER)
			printf("1以上%d以下の行数のみ有効です\n",NUMBER);
	}while(row<=0||row>=NUMBER);

	do{
		printf("列数を入れてください:");
		scanf("%d",&column);
		if(column<=0||column>=NUMBER)
			printf("1以上%d以下の列数のみ有効です\n",NUMBER);
	}while(column<=0||column>=NUMBER);

	puts("-----------------各要素(方程式の左辺)------------------");
	for(i=0;i<=(row-1);i++){
		for(j=0;j<=(column-1);j++){
			printf("行数:%d,列数:%d:",i+1,j+1);
			scanf("%lf",&matrix[i][j]);
		}
	}

	puts("---------------------方程式の右辺---------------------");
	for(i=0;i<=(row-1);i++){
		printf("%d行目:",i+1);
		scanf("%lf",&answer[i][0]);
	}

	return 0;
}
