#ifndef TASKS_H
#define TASKS_H
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void Encryption(char * txt, int countShift);
void Decryption(char * txt, int countShift);
int IdentifySize(char * txt);
void CheckPos(int size, int * pos);
void CheckPosNotNegative(int * pos);
#endif