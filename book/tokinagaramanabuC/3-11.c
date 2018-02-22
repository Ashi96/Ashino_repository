/*読み込んだ３つの整数値を等値関係を表示*/
#include<stdio.h>

int main(void){
	int a,b,c;

	puts("３つの整数を入力してください");
	printf("整数A:");	scanf("%d",&a);
	printf("整数B:");	scanf("%d",&b);
	printf("整数C:");	scanf("%d",&c);

	if(a==b && b==c)
		puts("３つの値は等しいです");
	else if(a==b||b==c||c==a)
		puts("２つの値は等しいです");
	else
		puts("３つの値は異なります");

	return 0;
}

