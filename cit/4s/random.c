#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
	int num;
	srand(time(NULL));
	for(int i = 0;i <= 10;i++){
		num = rand() % 10 + 1;	//10で割った余りの数値は0~9。それに１をたせば１〜１０の乱数が作れる
		printf("%d\n",num);
	}
	return 0;
}
