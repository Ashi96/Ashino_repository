/*読み込んだ３つの整数値の最小値を求めて表示*/
#include<stdio.h>

int main(void){
	int n1,n2,n3;

	puts("３つの整数を入力してください");
	printf("整数1:");	scanf("%d",&n1);
	printf("整数2:");	scanf("%d",&n2);
	printf("整数3:");	scanf("%d",&n3);

	printf("最小値は%dです。\n",(n1<n2)?((n1<n3)?n1:n3):((n2<n3)?n2:n3));

	return 0;
}

