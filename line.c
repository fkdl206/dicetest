#include<stdio.h>
#include<string.h>
#define max_size 1000


int main(int argc,char* argv[]){
    int i=0;
    char line[max_size][max_size];
    char ops[max_size];
    char* tmp;
    int start,end;
    if(argc!=2){
        printf("error");
        return 0;
    }
    FILE * fp=fopen(argv[1],"r");
    while(fgets(line[i],max_size,fp)!=NULL)i++;
    for(int j=0;j<i;j++){
        printf("%d : %s",j,line[j]);
    }
    printf("\n");
    while(printf("input :")&&scanf("%s",&ops)!=EOF){
        if(!strncmp(ops,"*",1)){
            for(int j=0;j<i;j++){
                printf("%d : %s",j,line[j]);
            }
            continue;
        }
        if(strchr(ops,'-')!=NULL){
            tmp=strtok(ops,"-");
            start=atoi(tmp);
            tmp=strtok(NULL,"-");
            end=atoi(tmp);
            for(int j=start;j<end+1;j++){
                printf("%d : %s",j,line[j]);
            }
            printf("\n");
            continue;
        }
        if(strchr(ops,',')!=NULL){
            tmp=strtok(ops," ,");
            while(tmp!=NULL){
                printf("%d : %s",atoi(tmp),line[atoi(tmp)]);
                tmp=strtok(NULL," ,\n");
            }
            printf("\n");
            continue;
        }
        printf("%d : %s\n",atoi(ops),line[atoi(ops)]);
        fflush(stdin);
    }

}
