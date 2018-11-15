#ifndef WORKWITHARR_H_
#define WORKWITHARR_H_

#include"WriteAndRead.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void CheckPos(int size, int * pos);
void CheckPosNotNegative(int * pos);
void Insert(int pos, char * nameFile1, char * nameFile2);
void DeleteCharFromText(int pos2, char * nameFile);
void Encryption(int countShift, char * nameFile);
void Decryption(int countShift, char * nameFile);

#endif WORKWITHARR_H_