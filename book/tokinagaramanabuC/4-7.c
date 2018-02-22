/*読み込んだ整数値以下の２のべき乗を昇順に表示*/
#include<stdio.h>

int main(void){
	int no;

	printf("正の整数を入力してください:");
	scanf("%d",&no);

	if(no>=1){
		int i = 2;
		while(no>=i){
			printf("%d ",i);
			i*=2;
		}
	printf("\n");
	}

	return 0;
}

