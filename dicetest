// dicetest
#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
                               //전체적으로 너무 힘든길로 만든것 같습니다 
int main()
{
    int sel;
    int random,user;
    char ch;
    int guo;
    int money = 1000;
    int bet = 0;
    int next = 0;
    int win = 0;
    int draw =0;
    int lose =0;
    int sum;
 
    while (1) {
        printf("====================================\n");
        printf("= = =         DICE GAME      = = =\n\n");
        printf("Money  = 1000에서 시작 합니다 \n\n");
        printf("1. Game Start\n");
        printf("2. Game Score\n");
        printf("3. End Game\n");
        printf("====================================\n");
        printf(">");
        scanf("%d",&sel); 
        srand(time(NULL));
        rand();rand();rand();rand();                       //난수
        srand(rand());
        random=(rand()%6+1)+(rand()%6+1)+(rand()%6+1);
        user=(rand()%6+1)+(rand()%6+1)+(rand()%6+1);
 
        switch(sel) {
            case 1:                                    // case1이 사실상 이 코딩의 전부인데 뭔가 이상하다
                money -= 10;                                //판돈은 10원
                printf("== DICE GAME START! ==\n");
                printf("나의 주사위의 합 : %d\n", user);
 
                printf("배팅하시겠습니까 <y/n>?");
                fflush(stdin);
 
                scanf("%c", &ch);
 
                if (ch == 'Y' || ch == 'y'){             //Y 혹은 y이면
                    printf("배팅금액을 입력해 주세요<1 ~ 990> :\n");
                    scanf("%d", &guo);
 
                    if (money < guo)   printf("금액 부족\n");
                    else{money-= guo;}
                }
                else if (ch == 'N'|| ch == 'n') {     //N 혹은 n이면
                    printf("게임 종료");
                    bet =0;
                    break;
                }
                else {
                    printf("잘못입력했습니다.\n");
                    break;
                }
 
                sum = 10 + (2 * guo);
                printf("random의 주사위 합은%d : ", random);
 
                if (user > random){                        // 밑 이랑 비교
                    money = money + sum + next;
                    next = 0;
                    printf("win\n");
                    printf("남은 금액 : %d\n", money);
                    win++;
                }
                else if (user < random){                      //위 랑 비교
                    printf("Lose!!!!\n");
                    printf("현재 남은 금액은 %d입니다.", money);
                    lose++;
 
                    if (money < 10){
                        printf("10원 갖고, 돈 갖고 오세요^^!!\n");
                        break;
                    }
                }
                else{
                    next=10+2*guo;
                       printf("draw\n");
                    draw++;
                }
                break;
            case 2:
                printf("===========\n");
                printf("Win:%d\n",win);
                printf("Lose:%d\n",lose);
                printf("Draw:%d\n",draw);
                printf("===========\n");
                break;
            case 3:
                printf("Exit Game\n");
                return 0;
            default: printf("10원 갖고, 돈 갖고 오세요^^!!\n");          //10원 미만이면 나간다
        }
    }
 
    return 0;
}
