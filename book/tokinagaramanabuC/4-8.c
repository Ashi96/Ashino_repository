/*読み込んだ正の整数値までカウントアップ*/
#include<stdio.h>

int main(void){
	int no;

	printf("正の整数を入力してください:");
	scanf("%d",&no);

	if(no>=1){
		int i = 1;
		printf("{");
		while(no>i)
			printf("%d,",i++);
		printf("%d}\n",no);
		
	}

	return 0;
}

