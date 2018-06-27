#include <stdio.h>                                                                                                                              
struct person{
    char name[40];
    char phone[15];
    char mail[40];
}

main(void){
    FILE *fp;
    struct person std[256];
    char a,i,u,e,o,k,s,t,str,Search,fg=0;
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
                for(i=0;i<p;i++){
                    printf("%s %s %s\n",std[i].name,std[i].phone,std[i].mail);
                }
                break;
            case 2:
                printf("How many people doyou input?:");scanf("%d",&p);
                for(o=0;o<p;o++){
                    scanf("%s %s %s",std[o].name,std[o].phone,std[o].mail);
                }
                fp=fopen("rw.txt","w");
                for(u=0;u<p;u++){
                    fprintf(fp,"%s %s %s\n",std[u].name,std[u].phone,std[u].mail);
                }
                fclose(fp);
                break;
            case 3:
                fp=fopen("rw.txt","r");
                if(fp==NULL){
                    puts("File does not exist");
                    //return -1;
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
                e=0;
                while(fscanf(fp,"%s %s %s",std[e].name,std[e].phone,std[e].mail)!=EOF){
                    e++;}
                p=e+1;
                fclose(fp);
                printf("Search method selection(n/p/m/s):");
                scanf(" %c",&Search);
                if(Search=='n'){
                    printf("Name you want to search:");
                    scanf(" %s",Search_n);
                    for(e=0;e<p;e++){
                        if(strcmp(Search_n,std[e].name)==0){
                            printf("Found in the %d element\n%s %s %s\n",e,std[e].name,std[e].phone,std[e].mail);
                            break; 
                        }
                        else if(e==p-1&&(strcmp(Search_n,std[e].name)!=0)){
                            puts("Not found");
                        }
                    }
                }
                else if(Search=='p'){
                    printf("Phone you want to search:");
                    scanf(" %s",Search_p);
                    for(k=0;k<p;k++){
                        if(strcmp(Search_p,std[s].phone)==0){
                            printf("Found in the %d element\n%s %s %s\n",s,std[s].name,std[s].phone,std[s].mail);
                            break;
                        }
                        else if(s==p-1&&(strcmp(Search_p,std[s].phone)!=0)){
                            puts("Not found");
                        }
                    }
                }
                else if(Search=='m'){
                    printf("Mail adress you want to search:");
                    scanf(" %s",Search_m);
                    for(s=0;s<p;s++){
                        if(strcmp(Search_m,std[s].mail)==0){
                            printf("Found in the %d element\n%s %s %s\n",s,std[s].name,std[s].phone,std[s].mail);
                            break;
                        }
                        else if(s==p-1&&(strcmp(Search_m,std[s].mail)!=0)){
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
            default:
                puts("Select from (n/p/m)");
        }
    }
}
                      