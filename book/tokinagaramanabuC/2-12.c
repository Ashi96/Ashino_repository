/*読み込んだ身長に対する標準体重を求めて表示*/
#include<stdio.h>

int main(void){
	int height;

	printf("身長を入力してください：");
	scanf("%d",&height);

	printf("標準体重は%.1fです。\n",(height-100)*0.9);

	return 0;
}

