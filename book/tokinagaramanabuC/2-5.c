/*読み込んだ２つの整数値の平均値の符号を反転した値を表示*/
#include<stdio.h>

int main(void){
	int x,y;
	int avg;

	puts("２つの整数の値を入力してください");
	printf("整数x:");	scanf("%d",&x);
	printf("整数y:");	scanf("%d",&y);

	avg=(x+y)/2;

	printf("平均値の符号を反転した値は%dです。\n",-avg);
	
	return 0;
}

