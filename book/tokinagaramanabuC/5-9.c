/*学生の点数を読み込んで分布を表示*/
#include<stdio.h>

#define NUMBER 80

int main(void){
	int i,j;
	int num;
	int tensu[NUMBER];
	int bunpu[11] = {0};
	int bunpu_max = 0;

	printf("人数を入力してください:");
	do{
		scanf("%d",&num);
		if(num<1||num>NUMBER)
			printf("1~%dで入力してください:",NUMBER);
	}while(num<1||num>NUMBER);
	printf("%d人の点数を入力してください\n",num);
	for(i=0;i<num;i++){
		printf("%2d番:",i+1);
		do{
			scanf("%d",&tensu[i]);
			if(tensu[i]<0||tensu[i]>100)
				printf("0~100で入力してください:");
		}while(tensu[i]<0||tensu[i]>100);
		bunpu[tensu[i]/10]++;
	}

	puts("\n---分布グラフ---");
	for(i=0;i<=10;i++)
		if(bunpu[i]>bunpu_max)
			bunpu_max=bunpu[i];
	for(i=bunpu_max;i>=1;i--){
		for(j=0;j<=10;j++){
		if(bunpu[j]>=i)
			printf(" * ");
		else
			printf("   ");
		}
		putchar('\n');
	}
	for(i=0;i<34;i++)
		putchar('-');
	putchar('\n');
	for(i=0;i<=10;i++)
		printf("%2d ",i*10);
	putchar('\n');

	return 0;
}

