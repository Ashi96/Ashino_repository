#include<stdio.h>
#include<stdlib.h>

int divide(char word);
int main(void){
	FILE *fp,*fp2;
	int mozi[60][60] = {};
	int mozi1,mozi2,i,j;
	int count = 0;
	char word,ch1,ch2;

	puts("------------------------------------------------------------------------");	
	fp = fopen("task4_read.txt","r");
	if(fp == NULL){
		puts("		task4_read.txt -> File is not Found !!");
		return -1;
	}else
		puts("		task4_read.txt -> File is Opened !!");

	puts("------------------------------------------------------------------------");	
	puts("		task4_read.txt -> File can Scaned !!");
	puts("------------------------------------------------------------------------");	
	puts("-----------------------task4_read.txt : contents------------------------");	
	word = fgetc(fp);
	putchar(word);
	mozi1 = divide(word);
	count++;

	while((word = fgetc(fp)) != EOF){
		putchar(word);
		mozi2 = divide(word);
		mozi[mozi1][mozi2]++;
		mozi1 = mozi2;
		count++;
	}
	fclose(fp);

	puts("------------------------------------------------------------------------");	
	printf("			Total Characters : %d\n",count);
	puts("------------------------------------------------------------------------");	

	fp2 = fopen("task4_result.txt","w");
	if(fp2 == NULL){
		puts("		task4_result.txt  -> File is not Found !!");
		return -1;
	}else
		puts("		task4_result.txt  -> File is Opend !!");
	puts("------------------------------------------------------------------------");	
	for(ch1 = 'A',i = 0;ch1 <= 'Z';ch1++,i++){
		for(ch2 = 'A',j = 0;ch2 <= 'Z';ch2++,j++){
			fputc(ch1,fp2);
			fputc(ch2,fp2);
			fputs("  : ",fp2);
			fprintf(fp2,"%15.6lf\n",(mozi[i][j] / (double)count) * 100);
		}
		for(ch2 = 'a',j = 26;ch2 <= 'z';ch2++,j++){
			fputc(ch1,fp2);
			fputc(ch2,fp2);
			fputs("  : ",fp2);
			fprintf(fp2,"%15.6lf\n",(mozi[i][j] / (double)count) * 100);
		}
		fputc(ch1,fp2);
		fputs("_  : ",fp2);
		fprintf(fp2,"%15.6lf\n",(mozi[i][52] / (double)count) * 100);
		fputc(ch1,fp2);
		fputs(",  : ",fp2);
		fprintf(fp2,"%15.6lf\n",(mozi[i][53] / (double)count) * 100);
		fputc(ch1,fp2);
		fputs(".  : ",fp2);
		fprintf(fp2,"%15.6lf\n",(mozi[i][54] / (double)count) * 100);
		fputc(ch1,fp2);
		fputs("else  : ",fp2);
		fprintf(fp2,"%15.6lf\n",(mozi[i][55] / (double)count) * 100);
	}
	for(ch1 = 'a',i = 26;ch1 <= 'z';ch1++,i++){
		for(ch2 = 'A',j = 0;ch2 <= 'Z';ch2++,j++){
			fputc(ch1,fp2);
			fputc(ch2,fp2);
			fputs("  : ",fp2);
			fprintf(fp2,"%15.6lf\n",(mozi[i][j] / (double)count) * 100);
		}
		for(ch2 = 'a',j = 26;ch2 <= 'z';ch2++,j++){
			fputc(ch1,fp2);
			fputc(ch2,fp2);
			fputs("  : ",fp2);
			fprintf(fp2,"%15.6lf\n",(mozi[i][j] / (double)count) * 100);
		}
		fputc(ch1,fp2);
		fputs("_  : ",fp2);
		fprintf(fp2,"%15.6lf\n",(mozi[i][52] / (double)count) * 100);
		fputc(ch1,fp2);
		fputs(",  : ",fp2);
		fprintf(fp2,"%15.6lf\n",(mozi[i][53] / (double)count) * 100);
		fputc(ch1,fp2);
		fputs(".  : ",fp2);
		fprintf(fp2,"%15.6lf\n",(mozi[i][54] / (double)count) * 100);
		fputc(ch1,fp2);
		fputs("else  : ",fp2);
		fprintf(fp2,"%15.6lf\n",(mozi[i][55] / (double)count) * 100);
	}
	ch1 = '_';
		for(ch2 = 'A',j = 0;ch2 <= 'Z';ch2++,j++){
			fputc(ch1,fp2);
			fputc(ch2,fp2);
			fputs("  : ",fp2);
			fprintf(fp2,"%15.6lf\n",(mozi[52][j] / (double)count) * 100);
		}
		for(ch2 = 'a',j = 26;ch2 <= 'z';ch2++,j++){
			fputc(ch1,fp2);
			fputc(ch2,fp2);
			fputs("  : ",fp2);
			fprintf(fp2,"%15.6lf\n",(mozi[52][j] / (double)count) * 100);
		}
		fputc(ch1,fp2);
		fputs("_  : ",fp2);
		fprintf(fp2,"%15.6lf\n",(mozi[52][52] / (double)count) * 100);
		fputc(ch1,fp2);
		fputs(",  : ",fp2);
		fprintf(fp2,"%15.6lf\n",(mozi[52][53] / (double)count) * 100);
		fputc(ch1,fp2);
		fputs(".  : ",fp2);
		fprintf(fp2,"%15.6lf\n",(mozi[52][54] / (double)count) * 100);
		fputc(ch1,fp2);
		fputs("else  : ",fp2);
		fprintf(fp2,"%15.6lf\n",(mozi[52][55] / (double)count) * 100);
	ch1 = ',';
		for(ch2 = 'A',j = 0;ch2 <= 'Z';ch2++,j++){
			fputc(ch1,fp2);
			fputc(ch2,fp2);
			fputs("  : ",fp2);
			fprintf(fp2,"%15.6lf\n",(mozi[53][j] / (double)count) * 100);
		}
		for(ch2 = 'a',j = 26;ch2 <= 'z';ch2++,j++){
			fputc(ch1,fp2);
			fputc(ch2,fp2);
			fputs("  : ",fp2);
			fprintf(fp2,"%15.6lf\n",(mozi[53][j] / (double)count) * 100);
		}
		fputc(ch1,fp2);
		fputs("_  : ",fp2);
		fprintf(fp2,"%15.6lf\n",(mozi[53][52] / (double)count) * 100);
		fputc(ch1,fp2);
		fputs(",  : ",fp2);
		fprintf(fp2,"%15.6lf\n",(mozi[53][53] / (double)count) * 100);
		fputc(ch1,fp2);
		fputs(".  : ",fp2);
		fprintf(fp2,"%15.6lf\n",(mozi[53][54] / (double)count) * 100);
		fputc(ch1,fp2);
		fputs("else  : ",fp2);
		fprintf(fp2,"%15.6lf\n",(mozi[53][55] / (double)count) * 100);
	ch1 = '.';
		for(ch2 = 'A',j = 0;ch2 <= 'Z';ch2++,j++){
			fputc(ch1,fp2);
			fputc(ch2,fp2);
			fputs("  : ",fp2);
			fprintf(fp2,"%15.6lf\n",(mozi[54][j] / (double)count) * 100);
		}
		for(ch2 = 'a',j = 26;ch2 <= 'z';ch2++,j++){
			fputc(ch1,fp2);
			fputc(ch2,fp2);
			fputs("  : ",fp2);
			fprintf(fp2,"%15.6lf\n",(mozi[54][j] / (double)count) * 100);
		}
		fputc(ch1,fp2);
		fputs("_  : ",fp2);
		fprintf(fp2,"%15.6lf\n",(mozi[54][52] / (double)count) * 100);
		fputc(ch1,fp2);
		fputs(",  : ",fp2);
		fprintf(fp2,"%15.6lf\n",(mozi[54][53] / (double)count) * 100);
		fputc(ch1,fp2);
		fputs(".  : ",fp2);
		fprintf(fp2,"%15.6lf\n",(mozi[54][54] / (double)count) * 100);
		fputc(ch1,fp2);
		fputs("else  : ",fp2);
		fprintf(fp2,"%15.6lf\n",(mozi[54][55] / (double)count) * 100);

		for(ch2 = 'A',j = 0;ch2 <= 'Z';ch2++,j++){
			fputs("else",fp2);
			fputc(ch2,fp2);
			fputs("  : ",fp2);
			fprintf(fp2,"%15.6lf\n",(mozi[55][j] / (double)count) * 100);
		}
		for(ch2 = 'a',j = 26;ch2 <= 'z';ch2++,j++){
			fputs("else",fp2);
			fputc(ch2,fp2);
			fputs("  : ",fp2);
			fprintf(fp2,"%15.6lf\n",(mozi[55][j] / (double)count) * 100);
		}
		fputs("else",fp2);
		fputs("_  : ",fp2);
		fprintf(fp2,"%15.6lf\n",(mozi[55][52] / (double)count) * 100);
		fputs("else",fp2);
		fputs(",  : ",fp2);
		fprintf(fp2,"%15.6lf\n",(mozi[55][53] / (double)count) * 100);
		fputs("else",fp2);
		fputs(".  : ",fp2);
		fprintf(fp2,"%15.6lf\n",(mozi[55][54] / (double)count) * 100);
		fputs("else",fp2);
		fputs("else  : ",fp2);
		fprintf(fp2,"%15.6lf\n",(mozi[55][55] / (double)count) * 100);
	fclose(fp2);
	puts("		task4_result.txt  -> File can Write !!");
	puts("------------------------------------------------------------------------");	

	return 0;
}
int divide(char word){
	char cha;
	int mozi,i;
	if((word >= 'A') && (word <= 'Z')){
		for(i = 0,cha = 'A';i <= 25;i++,cha++){
			if(word == cha){
				mozi = i;
				break;
			}
		}
	}
	else if((word >= 'a') && (word <= 'z')){
		for(i = 26,cha = 'a';i <= 51;i++,cha++){
			if(word == cha){
				mozi = i;
				break;
			}
		}
	}else if(word == ' ')
		mozi = 52;
	else if(word == ',')
		mozi = 53;
	else if(word == '.')
		mozi = 54;
	else
		mozi = 55;
	return mozi;
}
