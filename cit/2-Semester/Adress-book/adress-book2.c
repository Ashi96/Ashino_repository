#include <stdio.h>                                                                                                                              
struct person{
    char name[40];
    char phone[15];
    char mail[40];
}

main(void){
    FILE *fp;
    struct person std[256];
    char a,str,Search,fg=0;
    char Search_n[40],Search_m[40],Search_p[15];
    int mode,p,Number;
    while(fg==0){
        printf("mode_select(0/1/2/3/4/100/200):");
        scanf("%d",&mode);
        switch(mode){
            case 0:
                printf("How many people do you input?:");scanf("%d",&p);
                for(a=0;a<p;a++){
                    scanf("%s %s %s",std[a].name,std[a].phone,std[a].mail);
                }
                break;
            case 1:
                for(a=0;a<p;a++){
                    printf("%s %s %s\n",std[a].name,std[a].phone,std[a].mail);
                }
                break;
            case 2:
                printf("How many people do you input?:");scanf("%d",&p);
                for(a=0;a<p;a++){
                    scanf("%s %s %s",std[a].name,std[a].phone,std[a].mail);
                }
                fp=fopen("rw.txt","w");
                for(a=0;a<p;a++){
                    fprintf(fp,"%s %s %s\n",std[a].name,std[a].phone,std[a].mail);
                }
                fclose(fp);
                break;
            case 3:
                fp=fopen("rw.txt","r");
                if(fp==NULL){
                    puts("File does not exist");
                }
                while((str=fgetc(fp))!=EOF){
                    printf("%c",str);
                }
                fclose(fp);
                break;
            case 4:
                fp=fopen("rw.txt","r");
                if(fp==NULL){
                    puts("File does not exist");
                }
                a=0;
                while(fscanf(fp,"%s %s %s",std[a].name,std[a].phone,std[a].mail)!=EOF){
                    a++;}
                p=a+1;
                fclose(fp);
                printf("Search method selection(n/p/m/s):");
                scanf(" %c",&Search);
                if(Search=='n'){
                    printf("Name you want to search:");
                    scanf(" %s",Search_n);
                    for(a=0;a<p;a++){
                        if(strcmp(Search_n,std[a].name)==0){
                            printf("Found in the %d element\n%s %s %s\n",a,std[a].name,std[a].phone,std[a].mail);
                            break;
                        }                                 
                        else if(a==p-1&&(strcmp(Search_n,std[a].name)!=0)){
                            puts("Not found");
                        }
                    }
                }
                else if(Search=='p'){
                    printf("Phone Number you want to search:");
                    scanf(" %s",Search_p);
                    for(a=0;a<p;a++){
                        if(strcmp(Search_p,std[a].phone)==0){
                            printf("Found in the %d element\n%s %s %s\n",a,std[a].name,std[a].phone,std[a].mail);
                            break;
                        }
                        else if(a==p-1&&(strcmp(Search_p,std[a].phone)!=0)){
                            puts("Not found");
                        }
                    }
                }
                else if(Search=='m'){
                    printf("Mail adress you want to search:");
                    scanf(" %s",Search_m);
                    for(a=0;a<p;a++){
                        if(strcmp(Search_m,std[a].mail)==0){
                            printf("Found in the %d element\n%s %s %s\n",a,std[a].name,std[a].phone,std[a].mail);
                            break;
                        }
                        else if(a==p-1&&(strcmp(Search_m,std[a].mail)!=0)){
                            puts("Not found");
                        }
                    }
                }
               else if(Search=='s'){
                    puts("n:Name search\np:Phone Number search\nm:Mail Adress search\ns:Support");
                }
                break;
            case 100:
                fg=1;
                break;
            case 200:
                puts("  0:Input to the structure\n  1:Display contents of structure\n  2:Write to file\n  3:Read file\n  4:Search function\n100:End\n200:Support");
                break;
            default:
                puts("Select from (n/p/m)");
        }
    }
}
