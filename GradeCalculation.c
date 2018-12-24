#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{
    int student_num;
    char name[20];
    int middle_exam1;
    int middle_exam2;
    int final_exam1;
    int final_exam2;
    int sum;
}student;

int main(){
    student stud[1000];
    int i=0,j;
    int middle1_sum=0;
    int middle2_sum=0;
    int final1_sum=0;
    int final2_sum=0;
    student tmp;
    printf("학번 이름 중간1 중간2 기말1 기말2\n");
    fflush(stdin);
    while(scanf("%d",&stud[i].student_num)!=EOF){
        scanf("%s ",&stud[i].name);
        scanf("%d %d %d %d",&stud[i].middle_exam1,&stud[i].middle_exam2,&stud[i].final_exam1,&stud[i].final_exam2);
        stud[i].sum=stud[i].middle_exam1+stud[i].middle_exam2+stud[i].final_exam1+stud[i].final_exam2;
        stud[i].sum/=4;
        i++;
    }
    for(j=0;j<i;++j){
        middle1_sum+=stud[j].middle_exam1;
        middle2_sum+=stud[j].middle_exam2;
        final1_sum+=stud[j].final_exam1;
        final2_sum+=stud[j].final_exam2;
    }
    printf("중간고사 1 평균 : %d\n",middle1_sum/i);
    printf("중간고사 2 평균 : %d\n",middle2_sum/i);
    printf("기말고사 1 평균 : %d\n",final1_sum/i);
    printf("기말고사 2 평균 : %d\n",final2_sum/i);

    for(j=0;j<i;++j){
        for(int l=j+1;l<i;l++){
            if(stud[j].sum<stud[l].sum){
                tmp=stud[j];
                stud[j]=stud[l];
                stud[l]=tmp;
            }
        }
    }
    for(j=0;j<i;++j){
        printf("%d : %s : ",j+1,stud[j].name);
        if(stud[j].sum>90)
            printf("A\n");
        else if(stud[j].sum>=80)
            printf("B\n");
        else if(stud[j].sum>=70)
            printf("C\n");
        else
            printf("F\n");
    }
}
