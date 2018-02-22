/*読み込んだ２つの整数値の積(乗算結果)を変数に格納して表示*/
#include<stdio.h>

int main(void){
	int n1,n2;
	int seki;	//積

	puts("２つの整数を入力してください");
	printf("整数１：");	scanf("%d",&n1);
	printf("整数２：");	scanf("%d",&n2);

	seki=n1*n2;

	printf("それらの積は%dです。\n",seki);

	return 0;
}

