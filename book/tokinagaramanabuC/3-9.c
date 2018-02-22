/*読み込んだ２つの整数値の差を求めて表示*/
#include<stdio.h>

int main(void){
	int n1,n2,sa;

	puts("２つの整数を入力してください");
	printf("整数1：");	scanf("%d",&n1);
	printf("整数2：");	scanf("%d",&n2);

/*	if(n1>n2)
		sa=n1-n2;
	else
		sa=n2-n1;
*/
	sa=(n1>n2)?n1-n2:n2-n1;

	printf("それらの差は%dです。\n",sa);

	return 0;
}

