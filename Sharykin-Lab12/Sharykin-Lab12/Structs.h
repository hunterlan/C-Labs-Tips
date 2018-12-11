#ifndef STRUCT_H_
#define STRUCT_H_

/**
* @file Structs.h
* ������������ ���� ��������
* @author ������ ���������
* @version 1.0
* @date 2018.11.25
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
*  
* ��������� ��������  
*/

struct Student
{
	char firstName[50]; ///< ��'� ��������
	char lastName[80]; ///< �� ������� ��������
	char patronyminc[60]; ///< �� ������� ��������
	char country[50]; ///< � ��� ����� ��������� �������
	char disctrict[50]; ///< � ��� ������ ��������� �������
	char city[50]; ///< � ����� ��� ��������� �������
	char phoneNumber[13]; ///< �������� ����� ��������
	int isLiveInHostel; ///< �� ���� ������� � ����������
	int isGetAScholarship; ///< �� ������ ������� �������� (�� �����.���������)
	float markZNO[3]; ///< ������ �������� �� �������� 
	void ShowData();
};

/*
*
* ��������� ��������
*/

struct Worker
{
	char firstName[50];///< ��'� ��������
	char lastName[80];///< ������� ��������
	char patronyminc[60];///< �� ������� ��������
	int birthday[3];///< ���� ���������� ��������
	char position[100];///< ��������� ��������
	int salary;///< ��������� ����� ��������
	int isWorkerTeacher;///< �� ������ ������� ��������
	void ShowData();
};

/*
*
* ��������� ��������
*/

struct Laptop
{
	float sizeOfScreen;///< ����� ������ ��������
	char nameOfCompany[50];///< ��������, ���� �������� �������
	char nameOfModel[50];///< ������ ��������
	int isHaveBluetooth;///< �� �� Bluetooth
	int countKeyOnKeyboard;///< ʳ������ ������ �� ��������
	int price;///< ֳ�� ��������
	char operationSystem[50];///< ���������� ������� ��������
};

/*
*
* ��������� ��������
*/

struct Product
{
	char nameOfProduct[100];///< ����� ��������
	int countOfProduct;///< ������� ��������
	float priceToBuyProduct;///< ֳ�� �������� ��� �������
	float priceToSaleProduct;///< ֳ�� �������� ��� �������
};

#endif STRUCT_H_