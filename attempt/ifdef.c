#include<stdio.h>
#define A

#ifdef SMOKE
	int a = 5;
#endif
#ifdef MUTE
	int a = 10;
#else
	int a = -1;
#endif

int main(void){
	printf("%d\n",a + 10);
	return 0;
}
