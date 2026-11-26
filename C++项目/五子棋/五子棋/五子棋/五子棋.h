#include <stdio.h>
#include <stdlib.h>
#define MAX_ROW 15
#define MAX_COL 15
#define WHITE -1
#define BLACK 1
#define BLANK 0

void draw_chessboard(int row, int col, int chessboard[][MAX_COL]);//画棋盘
void draw_chessman(int type, char* tableline);//画棋子
int random_create_point(void);//人机
void draw_menu(void);//菜单
void person_person(void);//人对人
void person_computer_random(void);//人机
int is_full(int chessboard[][MAX_COL], int row, int col);//满了
int is_win(int chessboard[][MAX_COL], int row, int col);//胜利

