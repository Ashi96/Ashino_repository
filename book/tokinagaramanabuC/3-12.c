/*読み込んだ２つの整数値の差が１０以下かどうか表示*/
#include<stdio.h>
int main(void){
	int a,b,diff;

	puts("２つの整数を入力してください");
	printf("整数a:");	scanf("%d",&a);
	printf("整数b:");	scanf("%d",&b);

	diff=a-b;

	if(diff>10||diff<-10)
		puts("それらの差は１１以上です");
	else
		puts("それらの差は１０以下です");

	return 0;
}

