/*読み込んだ整数に12を加えた値を表示*/
#include<stdio.h>

int main(void){
	int no;
	printf("整数を入力してください:");
	scanf("%d",&no);

	printf("%dに12を加えると",no);
	printf("%dです。\n",no+12);

	return 0;
}

