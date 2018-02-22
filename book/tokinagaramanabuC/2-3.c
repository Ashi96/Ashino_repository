/*読み込んだ２つの整数値の比率を百分率で表示*/
#include<stdio.h>

int main(void){
	int x,y;

	puts("２つの整数を入力してください");
	printf("整数x:");	scanf("%d",&x);
	printf("整数y:");	scanf("%d",&y);

	printf("xの値はyの%d%%です。\n",100*x/y);

	return 0;
}

