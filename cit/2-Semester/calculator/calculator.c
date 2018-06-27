#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926

float Standard(float);
float Function(float);  
float Fun_add(float);
float Fun_sub(float);
float Fun_mul(float);
float Fun_div(float);

int main(){
	float Number_1=0;
	int mode;
	char Sign;
	while(1){
		printf("Mode select:(0:Standard mode 1:Function mode)\n"); //0:Standard mode, 1:Function mode;
		scanf("%d",&mode);
		if(mode==0){
			if(Number_1==0){
				printf("Number_input:\n");
				scanf("%f",&Number_1);
				Number_1=Standard(Number_1);
			}
			else{
				Number_1=Standard(Number_1);
			}
		}
		if(mode==1){
			if(Number_1==0){
				printf("Number_input:\n");
				scanf("%f",&Number_1);
				Number_1=Function(Number_1);
			}
			else{
				Number_1=Function(Number_1);
			}
		}
		else{
			puts("Select 0 or 1 ");
		}
	}
}

float Standard(float Number_1){
	float Number_2;
	int Fa,Fb;
	char Sign;
	while(1){
		printf("Sign_input:(h:help)\n");
		scanf(" %c",&Sign);					//Not %s.result Number_1 is removed.Space one character.
		switch(Sign){
			case '+':						//If not'',get an error.
				printf("Number_input:\n");
				scanf("%f",&Number_2);
				printf("%g(%g+%g=%g)\n",Number_1+Number_2,Number_1,Number_2,Number_1+Number_2);
				Number_1+=Number_2;
				break;
			case '-':
				printf("Number_input:\n");
				scanf("%f",&Number_2);
				printf("%g(%g-%g=%g)\n",Number_1-Number_2,Number_1,Number_2,Number_1-Number_2);
				Number_1-=Number_2;
				break;
			case '*':
				printf("Number_input:\n");
				scanf("%f",&Number_2);
				printf("%g(%g*%g=%g)\n",Number_1*Number_2,Number_1,Number_2,Number_1*Number_2);
				Number_1*=Number_2;
				break;
			case '/':
				printf("Number_input:\n");
				scanf("%f",&Number_2);
				printf("%g(%g/%g=%g)\n",Number_1/Number_2,Number_1,Number_2,Number_1/Number_2);
				Number_1/=Number_2;
				break;
			case '!':					    //factorial
				Fa=Number_1;
				Fb=1;
				while(Fa>1){
					Fb=Fb*Fa;
					Fa-=1;
				}
				printf("%d\n",Fb);
				Number_1=Fb;
				break;
			case '%':
				printf("Number_input:\n");
				scanf("%f",&Number_2);
				printf("%g%%(%g is %g%% of the %g)\n",(Number_1/Number_2)*100,Number_1,(Number_1/Number_2)*100,Number_2);
				Number_1/=Number_2;
				break;
			case 'c':						
				printf("Reset a Number\n");
				Number_1=0;
				break;
			case 'C':
				printf("Reset\n");          
				Number_1=0;
				return Number_1;
			case 'm':
				return Number_1;			// Back "mode select"
			case 'F':
				printf("forced termination\n");
				exit(0);
			case 'h':
				puts("+:addition\n-:subtraction\n*:multiplication\n/:division\n!:factorial\n%:percent\nc:All clear (back to Sign Input)\nC:All clear (back to Mode select)\nm:mode select\nF:Forced termination");
				break;
			default:
				printf("error:It is not a target sign\n");
		}
	}
}

float Function(float Number_1){
	char Sign;
	while(1){
		printf("Sign_input:(h:help)\n");
		scanf(" %c",&Sign);					
		switch(Sign){
			case '+':						
				Number_1=Fun_add(Number_1);
				break;
			case '-':
				Number_1=Fun_sub(Number_1);
				break;
			case '*':
				Number_1=Fun_mul(Number_1);
				break;
			case '/':
				Number_1=Fun_div(Number_1);
				break;
			case 'c':
				printf("Reset a Number\n");
				Number_1=0;
				break;
			case 'C':
				printf("Reset\n");
				Number_1=0;
				return Number_1;
			case 'm':
				return Number_1;	
			case 'F':
				printf("forced termination\n");
				exit(0);
				return;
			case 'h':
				puts("+:addition\n-:subtraction\n*:multiplication\n/:division\nC:All clear (back to Sign Input)\nC:All clear (back to Mode select)\nm:mode select\nF:Forced termination");
				break;
			default:
				printf("error:It is not a target sign\n");
		}
	}
}

float Fun_add(float Number_1){
	float ang,rst;
	char tri;
	printf("s/c/t(h:help):\n");													//s:sin,c:cos,t:tan;
	scanf(" %c",&tri);
	switch(tri){
		case 's':
			printf("angle:\n");
			scanf("%f",&ang);
			rst = sin(ang*PI/180.0);
			printf("%g(%g+sin%g(deg))\n",Number_1+rst,Number_1,ang);
			Number_1+=rst;
			break;
		case 'c':
			printf("angle:\n");
			scanf("%f",&ang);
			rst = cos(ang*PI/180.0);
			printf("%g(%g+cos%g(deg))\n",Number_1+rst,Number_1,ang);
			Number_1+=rst;
			break;
		case 't':
			printf("angle:\n");
			scanf("%f",&ang);
			rst = tan(ang*PI/180.0);
			printf("%g(%g+tan%g(deg))\n",Number_1+rst,Number_1,ang);
			Number_1+=rst;
			break;
		case 'h':
			puts("s:sin\nc:cos\nt:tan");
			break;
		default:
			printf("error:It is not a target sign\n");
	}
	return Number_1;
}

float Fun_sub(float Number_1){
	float ang,rst;
	char tri;
	printf("s/c/t:(h:help)\n");
	scanf(" %c",&tri);
	switch(tri){
		case 's':
			printf("angle:\n");
			scanf("%f",&ang);
			rst = sin(ang*PI/180.0);
			printf("%g(%g-sin%g(deg))\n",Number_1-rst,Number_1,ang);
			Number_1-=rst;
			break;
		case 'c':
			printf("angle:\n");
			scanf("%f",&ang);
			rst = cos(ang*PI/180.0);
			printf("%g(%g-cos%g(deg))\n",Number_1-rst,Number_1,ang);
			Number_1-=rst;
			break;
		case 't':
			printf("angle:\n");
			scanf("%f",&ang);
			rst = tan(ang*PI/180.0);
			printf("%g(%g-tan%g(deg))\n",Number_1-rst,Number_1,ang);
			Number_1-=rst;
			break;
		case 'h':
			puts("s:sin\nc:cos\nt:tan");
			break;
		default:
			printf("error:It is not a target sign\n");
	}
	return Number_1;
}


float Fun_mul(float Number_1){
	float ang,rst;
	char tri;
	printf("s/c/t:(h:help)\n");
	scanf(" %c",&tri);
	switch(tri){
		case 's':
			printf("angle:\n");
			scanf("%f",&ang);
			rst = sin(ang*PI/180.0);
			printf("%g(%g*sin%g(deg))\n",Number_1*rst,Number_1,ang);
			Number_1*=rst;
			break;
		case 'c':
			printf("angle:\n");
			scanf("%f",&ang);
			rst = cos(ang*PI/180.0);
			printf("%g(%g*cos%g(deg))\n",Number_1*rst,Number_1,ang);
			Number_1*=rst;
			break;
		case 't':
			printf("angle:\n");
			scanf("%f",&ang);
			rst = tan(ang*PI/180.0);
			printf("%g(%g*tan%g(deg))\n",Number_1*rst,Number_1,ang);
			Number_1*=rst;
			break;
		case 'h':
			puts("s:sin\nc:cos\nt:tan");
			break;
		default:
			printf("error:It is not a target sign\n");
	}
	return Number_1;
}


float Fun_div(float Number_1){
	float ang,rst;
	char tri;
	printf("s/c/t:(h:heip)\n");
	scanf(" %c",&tri);
	switch(tri){
		case 's':
			printf("angle:\n");
			scanf("%f",&ang);
			rst = sin(ang*PI/180.0);
			printf("%g(%g/sin%g(deg))\n",Number_1/rst,Number_1,ang);
			Number_1/=rst;
			break;
		case 'c':
			printf("angle:\n");
			scanf("%f",&ang);
			rst = cos(ang*PI/180.0);
			printf("%g(%g/cos%g(deg))\n",Number_1/rst,Number_1,ang);
			Number_1/=rst;
			break;
		case 't':
			printf("angle:\n");
			scanf("%f",&ang);
			rst = tan(ang*PI/180.0);
			printf("%g(%g/tan%g(deg))\n",Number_1/rst,Number_1,ang);
			Number_1/=rst;
			break;
		case 'h':
			puts("s:sin\nc:cos\nt:tan");
			break;
		default:
			printf("error:It is not a target sign\n");
	}
	return Number_1;
}
