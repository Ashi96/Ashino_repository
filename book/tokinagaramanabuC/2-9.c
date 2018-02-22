/*読み込んだ２つの実数値の比率を百分率(実数）で表示*/
#include<stdio.h>

int main(void){
	double a,b;

	puts("２つの実数を入力してください");
	printf("実数a:");	scanf("%lf",&a);
	printf("実数b:");	scanf("%lf",&b);

	printf("aの値はbの%f%%です。\n",a/b*100);

	return 0;
}

