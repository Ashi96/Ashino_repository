#include<stdio.h>

void add(int *pa,int *pb){
	printf("%d + %d = %d",*pa,*pb,*pa + *pb);
	}

int main(void){
	int a = 100;
	int b = 55;
	add(&a,&b);
	return 0;
}
