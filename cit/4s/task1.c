#include<stdio.h>
#include<stdlib.h>
int main(void){
	FILE *fp,*fp2;
	char sentence;
	int mozi[55] = {};
	char ch1,ch2;
	int i = 0;
	int j = 0;
	int count = 0;

	puts("------------------------------------------------------------------------");	
	fp = fopen("task1.txt","r");
	if(fp == NULL){
		puts("			task1.txt -> File is not Found !!");
		return -1;
	}else
		puts("			task1.txt -> File is Opened !!");

	puts("------------------------------------------------------------------------");	
	puts("--------------------------task1.txt : contents--------------------------");
	while((sentence = fgetc(fp)) != EOF){
		putchar(sentence);
		switch(sentence){
			case 'A':	mozi[0]++;	break;
			case 'B':	mozi[1]++;	break;
			case 'C':	mozi[2]++;	break;
			case 'D':	mozi[3]++;	break;
			case 'E':	mozi[4]++;	break;
			case 'F':	mozi[5]++;	break;
			case 'G':	mozi[6]++;	break;
			case 'H':	mozi[7]++;	break;
			case 'I':	mozi[8]++;	break;
			case 'J':	mozi[9]++;	break;
			case 'K':	mozi[10]++;	break;
			case 'L':	mozi[11]++;	break;
			case 'M':	mozi[12]++;	break;
			case 'N':	mozi[13]++;	break;
			case 'O':	mozi[14]++;	break;
			case 'P':	mozi[15]++;	break;
			case 'Q':	mozi[16]++;	break;
			case 'R':	mozi[17]++;	break;
			case 'S':	mozi[18]++;	break;
			case 'T':	mozi[19]++;	break;
			case 'U':	mozi[20]++;	break;
			case 'V':	mozi[21]++;	break;
			case 'W':	mozi[22]++;	break;
			case 'X':	mozi[23]++;	break;
			case 'Y':	mozi[24]++;	break;
			case 'Z':	mozi[25]++;	break;
			case 'a':	mozi[26]++;	break;
			case 'b':	mozi[27]++;	break;
			case 'c':	mozi[28]++;	break;
			case 'd':	mozi[29]++;	break;
			case 'e':	mozi[30]++;	break;
			case 'f':	mozi[31]++;	break;
			case 'g':	mozi[32]++;	break;
			case 'h':	mozi[33]++;	break;
			case 'i':	mozi[34]++;	break;
			case 'j':	mozi[35]++;	break;
			case 'k':	mozi[36]++;	break;
			case 'l':	mozi[37]++;	break;
			case 'm':	mozi[38]++;	break;
			case 'n':	mozi[39]++;	break;
			case 'o':	mozi[40]++;	break;
			case 'p':	mozi[41]++;	break;
			case 'q':	mozi[42]++;	break;
			case 'r':	mozi[43]++;	break;
			case 's':	mozi[44]++;	break;
			case 't':	mozi[45]++;	break;
			case 'u':	mozi[46]++;	break;
			case 'v':	mozi[47]++;	break;
			case 'w':	mozi[48]++;	break;
			case 'x':	mozi[49]++;	break;
			case 'y':	mozi[50]++;	break;
			case 'z':	mozi[51]++;	break;
			default:	mozi[52]++;
			}
		count++;
	}
	puts("------------------------------------------------------------------------");	
	puts("---------------------------------divide---------------------------------");
	for(ch1 = 'A',ch2 = 'a',i = 0,j = 26;(ch1 <= 'Z') && (ch2 <= 'z');ch1++,ch2++,i++,j++)
		printf("%c : %5d : %15.6lf	|	%c : %5d : %15.6lf\n",ch1,mozi[i],(mozi[i] / (double)count) * 100,ch2,mozi[j],(mozi[j] / (double)count) * 100);
	printf("else : %5d : %15.6lf\n",mozi[52],(mozi[52] / (double)count) * 100);
	puts("------------------------------------------------------------------------");	
	printf("			Total Characters : %d\n",count);

	fclose(fp);

	puts("------------------------------------------------------------------------");	
	fp2 = fopen("task1_result.txt","w");
	if(fp2 == NULL){
		puts("		task1_result.txt -> File is not Found !!");
		return -1;
	}else
		puts("		task1_result.txt -> File can Write !!");
	for(ch1 = 'A',i = 0;ch1 <= 'Z';ch1++,i++){
		fputc(ch1,fp2);
		fputs("    : ",fp2);
		fprintf(fp2,"%15.6lf\n",(mozi[i] / (double)count) * 100);
	}
	for(ch2 = 'a',j = 26;ch2 <= 'z';ch2++,j++){
		fputc(ch2,fp2);
		fputs("    : ",fp2);
		fprintf(fp2,"%15.6lf\n",(mozi[j] / (double)count) * 100);
	}
	fputs("else : ",fp2);
	fprintf(fp2,"%15.6lf\n",(mozi[52] / (double)count) * 100);
	fclose(fp2);
	puts("------------------------------------------------------------------------");	
		
	return 0;
}
