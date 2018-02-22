/*読み込んだ整数値を1までカウントダウン*/
#include<stdio.h>

int main(void){
	int i,no;

	printf("正の整数を入力してください:");
	scanf("%d",&no);

	if(no>=1){
		i = 1;
		while(no>=i){
			printf("%d ",i++);
		}
	printf("\n");
	}

	return 0;
}

