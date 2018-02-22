/*読み込んだ整数の個数だけ＊を連続表示*/
#include<stdio.h>

int main(void){
	int no;

	printf("正の整数を入力してください:");
	scanf("%d",&no);

	if(no>=1){
		while(no-->0)
			putchar('*');
		putchar('\n');
		
	}

	return 0;
}

