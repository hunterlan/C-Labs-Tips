#ifndef OPSWITHARRAY_H
#define OPSWITHARRAY_H
#include<stdlib.h>
#include<time.h>
#include<stdio.h>

/**
* @file OpsWithArray.h
* Описування прототипів функції для роботи з массивом
* @author Шарикін Костянтин
* @version 0.0.1
* @date 2018.10.01
*/

void makingDoubleArr(int ** array, int col);
void FillArrRandNum(int ** array, int col, int row);
void FillArrRandNum(int * array, int col);
void SortFromSmallToBig(int * array, int size);
void ClearArr(int ** array, int col);
void ShowSingleArr(int * array, int size);
void ShowDoubleArr(int ** array, int col, int row);

#endif