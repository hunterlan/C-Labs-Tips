#ifndef STRUCT_H_
#define STRUCT_H_

/**
* @file Structs.h
* Заголовочний файл структур
* @author Шарикін Костянтин
* @version 1.0
* @date 2018.11.25
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
*  
* Структура «Студент»  
*/

struct Student
{
	char firstName[50]; ///< Ім'я студента
	char lastName[80]; ///< По батькові студента
	char patronyminc[60]; ///< По батькові студента
	char country[50]; ///< У якій країні народився студент
	char disctrict[50]; ///< У якій області народився студент
	char city[50]; ///< У якому місті народився студент
	char phoneNumber[13]; ///< Мобільний номер студента
	int isLiveInHostel; ///< Чи живе студент у гуртожитку
	int isGetAScholarship; ///< Чи отримує студент стипендію (за індив.завданням)
	float markZNO[3]; ///< Оцінки студента за екзамени 
	void ShowData();
};

/*
*
* Структура «Робітник»
*/

struct Worker
{
	char firstName[50];///< Ім'я робітника
	char lastName[80];///< Призвіще робітника
	char patronyminc[60];///< По батькові робітника
	int birthday[3];///< День народження робітника
	char position[100];///< Должність робітника
	int salary;///< Зароботна плата робітника
	int isWorkerTeacher;///< Чи работає робітник вчителем
	void ShowData();
};

/*
*
* Структура «Ноутбук»
*/

struct Laptop
{
	float sizeOfScreen;///< Розмір екрана ноутбука
	char nameOfCompany[50];///< Компанія, якак створила ноутбук
	char nameOfModel[50];///< Модель ноутбука
	int isHaveBluetooth;///< Чи має Bluetooth
	int countKeyOnKeyboard;///< Кількість кнопок на клавіатурі
	int price;///< Ціна ноутбука
	char operationSystem[50];///< Операціїна система ноутбука
};

/*
*
* Структура «Продукт»
*/

struct Product
{
	char nameOfProduct[100];///< Назва продукта
	int countOfProduct;///< кількість продуктів
	float priceToBuyProduct;///< Ціна продукту для покупки
	float priceToSaleProduct;///< Ціна продукту для продажу
};

#endif STRUCT_H_