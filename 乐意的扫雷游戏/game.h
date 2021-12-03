#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<string.h>
#define ROW 9 
#define COL 9 
#define ROWS 11
#define COLS 11
//ɨ����Ϸ����
void game();
//��ʼ�����̵ĺ���
void InitBoard(char Board[ROWS][COLS], int rows, int cols, char set);
//��ӡ���̵ĺ���
void DisplayBoard(char Board[ROWS][COLS], int row, int col);
//�����׵ĺ���
void SetMine(char Board[ROWS][COLS],int row,int col,int nub);
//�������(һֱ�浽����������ֵΪ��Ӯ���)
char FindMine(char Board[ROWS][COLS], char show[ROWS][COLS], int row, int col,int nub);
//���ص���Χ�׵ĸ���
char CountMine(char Board[ROWS][COLS],char[ROWS][COLS] ,int row, int col);
//����չ��
void Extend(char Board[ROWS][COLS], char show[ROWS][COLS], int row, int col);
//�ж�ӮûӮ(Ӯ���� 1 ��ûӮ���� 0 )
int Is_win(char Board[ROWS][COLS],char show[ROWS][COLS], int row, int col,int nub);
//��Ϸʤ�� �� ʧ�ܺ���ʱ��ӡ���
void SleepPrint(char* p);