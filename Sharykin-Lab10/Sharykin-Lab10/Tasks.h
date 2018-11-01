#ifndef TASKS_H
#define TASKS_H
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/**
* @file Tasks.h
* Заголовчний файл Tasks
* @author Шарикін Костянтин
* @version 1.0
* @date 2018.10.29
*/

void Encryption(char * txt, int countShift);
void Decryption(char * txt, int countShift);
void CheckPos(int size, int * pos);
void CheckPosNotNegative(int * pos);
#endif