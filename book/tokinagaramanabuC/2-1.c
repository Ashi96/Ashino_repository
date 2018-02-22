/*読み込んだ整数値と１０を加算乗除した値を表示*/
#include<stdio.h>

int main(void){
	int n;

	printf("整数を入力してください");
	scanf("%d",&n);

	printf("１０を加えると%dです。\n",n+10);	//加算
	printf("１０を減じると%dです。\n",n-10);	//減算
	printf("１０を乗じると%dです。\n",n*10);	//乗算
	printf("１０を除した商は%dです。\n",n/10);	//除算(商)
	printf("１０を除した余は%dです。\n",n%10);	//除算(余)

	return 0;
}

