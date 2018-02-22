/*半径を読み込んで円の面積を求めて表示*/
#include<stdio.h>

int main(void){
	double r;	//半径

	printf("半径は：");
	scanf("%lf",&r);

	printf("円の面積は%fです。\n",3.14*r*r);	//面積の計算

	return 0;
}

