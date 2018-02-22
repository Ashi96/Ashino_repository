/*身長と体重からBMIを求めて表示*/
#include<stdio.h>

int main(void){
	double height,weight;

	printf("身長を入力してください：");	scanf("%lf",&height);
	printf("体重を入力してください：");	scanf("%lf",&weight);

	printf("BMIは%.2fです。\n",weight/((height/100.0)*(height/100.0)));

	return 0;
}

