//
//  main.c
//  tuixiangzi
//
//  Created by GWL on 2016/12/2.
//  Copyright © 2016年 GWL. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 11

/** 二维数组 */
char map[ROWS][COLS] = {
    "##########",
    "#  ####  #",
    "# X####  #",
    "# O      #",
    "######   #",
    "#  ####  #",
    "#        #",
    "#   ######",
    "#         ",
    "##########"
};

/** 保存小人当前的行坐标 */
int currentPersonRow = 3;
/** 保存小人当前的列坐标 */
int currentPersonCol = 2;

/** 显示游戏地图 */
void showMap();

/** 让用户输入小人的前进方向,将用户输入的字符返回 */
char enterDirection();

/** 将小人向上移动 */
void moveToUp();
/** 将小人向下移动 */
void moveDown();
/** 将小人向左移动 */
void moveToLeft();
/** 将小人向右移动 */
void moveToRight();

int main(int argc, const char * argv[]) {
    
    int flag = 1;
    
    while (flag)
    {
        // 调用一个函数，就可以将控制台上的内容清空
        //#include <stdlib.h>
        // 清空控制台上所有内容
        //清除操作xcode下面的输出区域太不支持
        //需要在终端运行才可以清空
        system("clear");
        
        showMap();
        // 判断游戏是否胜利
        if (map[8][9] == 'X')
        {
            printf("恭喜你取得游戏的胜利\n");
            break;
        }
        
        char dir = enterDirection();
        
        switch (dir) {
            case 'a':
            case 'A':
                //将小人向左移动
                moveToLeft();
                break;
            case 'w':
            case 'W':
                //将小人向上移动
                moveToUp();
                break;
            case 's':
            case 'S':
                //将小人向下移动
                moveDown();
                break;
            case 'd':
            case 'D':
                //将小人向右移动
                moveToRight();
                break;
            case 'q':
            case 'Q':
                //退出
                printf("你的智商真底\n");
                flag = 0;
                break;
            default:
                break;
        }
    }
    
    return 0;
}

char enterDirection()
{
    //输入小人的前进方向
    printf("请输入小人的前进方向 w.上 s.下 a.左 d.右 q.退出游戏\n");
    //接收输入小人的方向
    char dir = 'a';
    
    //将scanf缓冲区中的数据清空,避免输入的时候会出现一些问题
    rewind(stdin);
    scanf("%c",&dir);
    
    //将用户输入的前进方向返回
    return dir;
}
/** 显示游戏地图 */
void showMap()
{
    // 打印map数组中的元素
    for (int i = 0; i < ROWS; i ++)
    {
        printf("%s\n",map[i]);
    }
}
/** 将小人向上移动 */
void moveToUp()
{
    // 下一个行坐标
    int nextPersonRow = currentPersonRow - 1;
    // 下一个列坐标
    int nextPersonCol = currentPersonCol;
    //判断下一个坐标在地图上的格子是个什么类型
    if (map[nextPersonRow][nextPersonCol] == ' ')
    {
        // 路，移动小人
        map[nextPersonRow][nextPersonCol] = 'O';
        map[currentPersonRow][currentPersonCol] = ' ';
        
        // 从新设置小人当前坐标
        currentPersonRow = nextPersonRow;
        currentPersonCol = nextPersonCol;
        
    } else if (map[nextPersonRow][nextPersonCol] == 'X')
    {
        int nextBoxRow = nextPersonRow - 1;
        int nextBoxCol = nextPersonCol;
        
        if (map[nextBoxRow][nextBoxCol] == ' ')
        {
            // 路，移动小人
            map[nextBoxRow][nextBoxCol] = 'X';
            map[nextPersonRow][nextPersonCol] = 'O';
            map[currentPersonRow][currentPersonCol] = ' ';
            
            // 从新设置小人当前坐标
            currentPersonRow = nextPersonRow;
            currentPersonCol = nextPersonCol;
        }
    }
}
/** 将小人向下移动 */
void moveDown()
{
    // 下一个行坐标
    int nextPersonRow = currentPersonRow + 1;
    // 下一个列坐标
    int nextPersonCol = currentPersonCol;
    
    //判断下一个坐标在地图上的格子是个什么类型
    if (map[nextPersonRow][nextPersonCol] == ' ')
    {
        // 路，移动小人
        map[nextPersonRow][nextPersonCol] = 'O';
        map[currentPersonRow][currentPersonCol] = ' ';
        
        // 从新设置小人当前坐标
        currentPersonRow = nextPersonRow;
        currentPersonCol = nextPersonCol;
        
    } else if (map[nextPersonRow][nextPersonCol] == 'X')
    {
        int nextBoxRow = nextPersonRow + 1;
        int nextBoxCol = nextPersonCol;
        
        if (map[nextBoxRow][nextBoxCol] == ' ')
        {
            // 路，移动小人
            map[nextBoxRow][nextBoxCol] = 'X';
            map[nextPersonRow][nextPersonCol] = 'O';
            map[currentPersonRow][currentPersonCol] = ' ';
            
            // 从新设置小人当前坐标
            currentPersonRow = nextPersonRow;
            currentPersonCol = nextPersonCol;
        }
    }
}
/** 将小人向左移动 */
void moveToLeft()
{
    // 下一个行坐标
    int nextPersonRow = currentPersonRow;
    // 下一个列坐标
    int nextPersonCol = currentPersonCol - 1;
    
    //判断下一个坐标在地图上的格子是个什么类型
    if (map[nextPersonRow][nextPersonCol] == ' ')
    {
        // 路，移动小人
        map[nextPersonRow][nextPersonCol] = 'O';
        map[currentPersonRow][currentPersonCol] = ' ';
        
        // 从新设置小人当前坐标
        currentPersonRow = nextPersonRow;
        currentPersonCol = nextPersonCol;
        
    } else if (map[nextPersonRow][nextPersonCol] == 'X')
    {
        int nextBoxRow = nextPersonRow;
        int nextBoxCol = nextPersonCol - 1;
        
        if (map[nextBoxRow][nextBoxCol] == ' ')
        {
            // 路，移动小人
            map[nextBoxRow][nextBoxCol] = 'X';
            map[nextPersonRow][nextPersonCol] = 'O';
            map[currentPersonRow][currentPersonCol] = ' ';
            
            // 从新设置小人当前坐标
            currentPersonRow = nextPersonRow;
            currentPersonCol = nextPersonCol;
        }
    }
}
/** 将小人向右移动 */
void moveToRight()
{
    // 下一个行坐标
    int nextPersonRow = currentPersonRow;
    // 下一个列坐标
    int nextPersonCol = currentPersonCol + 1;
    
    //判断下一个坐标在地图上的格子是个什么类型
    if (map[nextPersonRow][nextPersonCol] == ' ')
    {
        // 路，移动小人
        map[nextPersonRow][nextPersonCol] = 'O';
        map[currentPersonRow][currentPersonCol] = ' ';
        
        // 从新设置小人当前坐标
        currentPersonRow = nextPersonRow;
        currentPersonCol = nextPersonCol;
        
    } else if (map[nextPersonRow][nextPersonCol] == 'X')
    {
        int nextBoxRow = nextPersonRow;
        int nextBoxCol = nextPersonCol + 1;
        
        if (map[nextBoxRow][nextBoxCol] == ' ')
        {
            // 路，移动小人
            map[nextBoxRow][nextBoxCol] = 'X';
            map[nextPersonRow][nextPersonCol] = 'O';
            map[currentPersonRow][currentPersonCol] = ' ';
            
            // 从新设置小人当前坐标
            currentPersonRow = nextPersonRow;
            currentPersonCol = nextPersonCol;
        }
    }
}
