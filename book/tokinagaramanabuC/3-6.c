/*等価演算子や関係演算子が生成する値を表示*/
#include<stdio.h>

int main(void){
	int a,b;

	puts("２つの整数を入力してください");
	printf("変数a:");	scanf("%d",&a);
	printf("変数b:");	scanf("%d",&b);

	puts("等価式の値");
	printf("a==bの値：%d\n",a==b);
	printf("a!=bの値：%d\n",a!=b);

	puts("等価式の値");
	printf("a<bの値：%d\n",a<b);
	printf("a<=bの値：%d\n",a<=b);
	printf("a>bの値：%d\n",a>b);
	printf("a>=bの値：%d\n",a>=b);

	return 0;
}

