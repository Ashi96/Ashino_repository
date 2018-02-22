#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include <assert.h>

int main(void){
	FILE *fp,*fp2;
	char sentence;

	fp = fopen("task4_read.txt","r");
	assert(NULL != fp);
	puts("task4_read.txt -> File is Opend !!");

	fp2 = fopen("task4_result.txt","w");
	puts("task4_result.txt -> File is Opend !!");
	
	while((sentence = fgetc(fp)) != EOF){
		putchar(sentence);
		if((isalpha(sentence)) || (sentence == ' ') || (sentence == '\n'))
			fputc
		else
	}
	fclose(fp);

	return 0;
}
