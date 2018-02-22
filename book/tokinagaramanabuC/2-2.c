/*読み込んだ整数値を５で割った商と剰余を表示*/
#include<stdio.h>

int main(void){
	int n;

	printf("nの値を入力してください：");
	scanf("%d",&n);

	printf("n/5は%dです。\n",n/5);	//商
	printf("n%%5は%dです。\n",n%5);	//剰余

	return 0;
}

