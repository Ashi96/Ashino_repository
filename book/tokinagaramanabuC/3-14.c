/*読み込んだ２つの整数値は等しいか*/
#include<stdio.h>
int main(void){
	int a,b,diff;

	puts("２つの整数を入力してください");
	printf("整数A:");	scanf("%d",&a);
	printf("整数B:");	scanf("%d",&b);

	if(a==b)
		puts("２つの値は同じです");
	else{
		int max,min;
		if(a<b){
			min=a;
			max=b;
		}else{
			min=b;
			max=a;
		}

	printf("小さい方の値は%dです\n",min);
	printf("大きい方の値は%dです\n",max);
	}

	return 0;
}

