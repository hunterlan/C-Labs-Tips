#ifndef WRITEANDREAD_H_
#define WRITEANDREAD_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void ReadFromFile(char *nameFile, char * txt);
void WriteToFile(char * nameFile, char * txt);
long GetLengthSymbInFile(char * nameFile);

#endif WRITEANDREAD_H_
