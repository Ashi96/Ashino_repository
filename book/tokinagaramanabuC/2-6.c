/*読み込んだ実数値をそのまま表示*/
#include<stdio.h>

int main(void){
	double x;

	printf("実数を入力してください:");
	scanf("%lf",&x);

	printf("あなたは%fと入力しましたね。\n",x);

	return 0;
}

