#include"Structs.h"
struct Student
{
	char firstName[50];
	char lastName[80];
	char patronyminc[60];
	char homeAdress[200];
	char phoneNumber[13];
	bool isLiveInHostel;
	bool isGetAScholapship;
	float markZNO[3];
};

struct Worker
{
	char firstName[50];
	char lastName[80];
	char patronyminc[60];
	int birthday[3];
	char position[100];
	int salary;
	bool isWorkerTeacher;
};

struct Laptop
{
	float sizeOfScreen;
	char nameOfCompany[50];
	char nameOfModel[50];
	bool isHaveBluetooth;
	int countKeyOnKeyboard;
	int price;
	char operationSystem[50];
};

struct Product
{
	char nameOfProduct[100];
	int countOfProduct;
	float priceToBuyProduct, priceToSaleProduct;
};