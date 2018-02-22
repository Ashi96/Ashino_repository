#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define hasei_kosu 100

int random_number_f(int m);
int main(void){
	FILE *fp,*fp2;
	int random_number,i,j,total_character_number;
	char sentence,hassei_mozi;

	puts("------------------------------------------------------------------------");	
	fp = fopen("task6_read.txt","r");
	if(fp == NULL){
		puts("		task6_read.txt -> File is not Found !!");
		return -1;
	}else
		puts("		task6_read.txt -> File is Opened !!");

	puts("------------------------------------------------------------------------");	
	puts("		task6_read.txt -> File can Scaned !!");	
	puts("-----------------------task6_read.txt : contents------------------------");	
	for(i = 0;(sentence = fgetc(fp)) != EOF;i++){
		putchar(sentence);
	}
	fclose(fp);
	puts("------------------------------------------------------------------------");	
	total_character_number = i;
	printf("		Total Characters : %d\n",total_character_number);
	puts("------------------------------------------------------------------------");	
	srand((unsigned) time(NULL));
	fp2 = fopen("task6_result.txt","w");
	if(fp2 == NULL){
		puts("		task6_result.txt File is not Found !!");
		return -1;
	}else
		puts("		task6_result.txt File is Opened !!");
	for(i = 1;i <= hasei_kosu;i++){
		fp = fopen("task6_read.txt","r");
		random_number = random_number_f(total_character_number);
		for(j = 1;j <= random_number;j++){
			sentence = fgetc(fp);
		}
		hassei_mozi = sentence;
		fclose(fp);
		if(hassei_mozi != '\n')
			fputc(hassei_mozi,fp2);
	}
	fclose(fp2);
	puts("------------------------------------------------------------------------");	
	puts("		task6_result.txt -> File can Write !!");	
	puts("------------------------------------------------------------------------");	
	return 0;
}

int random_number_f(int m){
	int num;
	num = rand() % m + 1;
	return num;
}
