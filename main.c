// 游戏的整个算法实现
//测试三子棋游戏

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
    char ret=0;
    char board[ROW][COL]={0};
    InitBoard(board,ROW,COL);
    DisplayBoard(board, ROW, COL);
    //下棋
    while (1) {
        PlayerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        //判断输赢
        ret=IsWin(board,ROW,COL);
        if (ret!='c') {
            break;
        }
        ComputerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        if (ret!='c') {
            break;
        }
    }
    if (ret=='*') {
        printf("玩家赢\n");
    }
    else if (ret=='#')
    {
        printf("电脑赢\n");
    }
    else
    {
        printf("平局\n");
    }
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