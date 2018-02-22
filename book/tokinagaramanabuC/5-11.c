/*６人の学生の２課目のテストの点数を読み込んで集計*/
#include<stdio.h>
#define NINZU 6	//人数

int main(void){
	int i,j;
	int tensu[NINZU][2];	//点数
	int student[NINZU]={0};	//各学生の点数の合計
	int subject[2]={0};	//各科目の点数の合計

	printf("%d人の点数を入力。\n",NINZU);

	for(i=0;i<NINZU;i++){
		printf("%2d番・・・国語:",i+1);
		scanf("%d",&tensu[i][0]);
		printf("	  数学:");
		scanf("%d",&tensu[i][1]);

		student[i] = tensu[i][0] + tensu[i][1];
		subject[0] += tensu[i][0];	//国語の点数
		subject[1] += tensu[i][1];	//数学の点数
	}

	printf("----------------------------\n");
	printf("番号  国語  数学  合計  平均\n");
	printf("----------------------------\n");
	for(i=0;i<NINZU;i++)
		printf("%3d%6d%6d%6d%7.1f\n",i+1,tensu[i][0],tensu[i][1],student[i],(double)student[i]/2);
	printf("----------------------------\n");
	printf("合計%5d%6d%6d\n",subject[0],subject[1],subject[0]+subject[1]);
	printf("平均 %6.1f%6.1f%6.1f\n",(double)subject[0]/NINZU,(double)subject[1]/NINZU,(double)(subject[0]+subject[1])/NINZU);
	printf("----------------------------\n");

	return 0;
}

