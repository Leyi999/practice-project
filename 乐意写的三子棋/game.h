#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#define ROW 3
#define COL 3
//��ʼ�����̵ĺ���
void InitBoard(char Board[ROW][COL], int row, int col);
//��ӡ���̵ĺ���
void DisplayBoard(char Board[ROW][COL], int row, int col);
//�����- ʵ�ָ�ֵ�ĺ���
void Player_Move(char Board[ROW][COL], int row ,int col);
//������- ������� ��ֵ�ĺ���
void Computer_Move(char Board[ROW][COL], int row, int col);
//�ж��Ƿ���Ҫ������Ϸ
char Is_win(char Board[ROW][COL], int row, int col);
//�ж������Ƿ����˵ĺ���
int Is_full(char Board[ROW][COL], int row, int col);