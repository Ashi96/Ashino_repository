/*読み込んだ整数値が１０の倍数であるか*/
#include<stdio.h>

int main(void){
	int no;

	printf("整数を入力してください：");
	scanf("%d",&no);

	if(no%10)
		puts("その数は１０の倍数ではありません");

	return 0;
}

