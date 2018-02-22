/*読み込んだ２つの整数値の比率を百分率（実数）で表示*/
#include<stdio.h>

int main(void){
	int a,b;

	puts("２つの整数を入力してください。");
	printf("整数a:");	scanf("%d",&a);
	printf("整数b:");	scanf("%d",&b);

	printf("aの値はbの%f%%です。\n",(double)a/b*100.0);

	return 0;
}

