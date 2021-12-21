// 游戏的整个算法实现
//测试扫雷游戏

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

void menu()
{
    printf("**************************\n");
    printf("***  1. play  0. exit  ***\n");
    printf("**************************\n");
}

void game()
{
    //雷的信息储存
    //1. 布置好的雷的储存
    char mine[ROWS][COLS]={0};
    //2. 排查出的雷的储存
    char show[ROWS][COLS]={0};
    //初始化
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');
    DisplayBoard(mine, ROW, COL);
    DisplayBoard(show, ROW, COL);
    //布置雷
    SetMine(mine,ROW,COL);
    //DisplayBoard(mine, ROW, COL);
    FindMine(mine,show,ROW,COL);
}
void test()
{
    int input=0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("请选择：");
        scanf("%d",&input);
        switch (input) {
            case 1:
                game();
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("选择错误，请重新选择！\n");
                break;
        }
    } while(input);
}

int main()
{
    test();
    return 0;
}
