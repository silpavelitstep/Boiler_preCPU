#include "boiler.h"
#pragma warning(disable : 4996)
#include <iostream>
#define TEST "ON" //автоматический вызов меню
#define FILL "ON" //автоматическое заполнение полей объекта
#define CONSDEST "ON"//контроль запуска конструктора/деструктора
using namespace std;
int BoilerList::menu()
{
	char select = ' ';
	int test_pos = 0;//for test
	while (true)
	{
		
#ifdef TEST
		//автоматический выбор пунктов меню и выход
		cout << "menu exist: Pass\n";
		char sel[5] = { 'a','s','d','c','q' };
		
		select = sel[test_pos++];
#else
	#ifdef CONSDEST
	#else
		system("CLS");
	#endif CONSDEST


		
		cout << "Menu:\n"
			<< "Select and put symbol:\n"
			<< "'a': add a boiler,\n"
			<< "'s': show all boilers\n"
			<< "'d': delete any boiler\n"
			<< "'c': delete all boilers\n"
			<< "'q' for exit.\n> ";
		cin >> select;
#endif TEST
		switch (select)
		{
		case 'a':  add(); break;
		case 's': show(); break;
		case 'd':  del(); break;
		case 'c':clear(); break;
		case 'q':return 1;//to close menu
		
		}
	}
	return 1;
}
int BoilerList::add()
{
#ifdef TEST
	cout << "add exist: Pass" << endl;
#endif TEST
	if (countBoilers == 19)
		cout << "Can't add. List is full!\n";
	else
	{
		pBoiler[countBoilers++] = new Boiler();
	}

	return 1;
}
int BoilerList::show()
{
#ifdef TEST
	cout << "show() exist: Pass" << endl;
#else
	cout << "Boiler list:\n";
	if (!countBoilers)
		cout << "List is empty!\n";
	for (int i = 0; i < countBoilers; i++)
	{
		cout << i << ": ";
		pBoiler[i]->show();
	}
	system("pause");
#endif TEST
	return 1;
}
int BoilerList::del()
{
#ifdef TEST
	cout << "del() exist: Pass" << endl;
#else
	int index;
	cout << "Set index: ";
	cin >> index;
	//index from 0 to countBoilers-1
	if (index<0 || countBoilers == 0 || index>countBoilers - 1)
		return 1;
	delete pBoiler[index];
	//if index==countBoiler то сдвиг массива не нужен
	for (int i=index;i<countBoilers-1;i++)
	{
		pBoiler[i] = pBoiler[i + 1];
	}
	countBoilers--;
#endif TEST
	return 1;
}
int BoilerList::clear()
{
#ifdef TEST
	cout << "clear() exist: Pass" << endl;
#else
	for (int i = 0; i < countBoilers; i++)
	{
		delete pBoiler[i];
	}
	countBoilers = 0;
#endif TEST
	return 1;
}
BoilerList::BoilerList()
{
#ifdef CONSDEST
	cout << "exe BoilerList()\n";
#endif CONSDEST
}
BoilerList::~BoilerList()
{
#ifdef CONSDEST
	cout << "delete BoilerList()\n";
#endif CONSDEST
	clear();

}
Boiler::Boiler()
{
#ifdef CONSDEST
	cout << "new/stack Boiler()\n";
#endif CONSDEST
#ifdef FILL
	strcpy(vender,"vender");
	litresInSec = 5;
	power = 50;
#else
	cin.getline(vender, 1);//free buffer
	cout << "New boiler:\n";
	cout << "set a vender: ";
	cin.getline(vender,20);
	cout << "set litres in second: ";
	cin >> litresInSec;
	cout << "set power in watt: ";
	cin >> power;
#endif FILL
}
Boiler::~Boiler()
{
#ifdef CONSDEST
	cout << "delete Boiler()\n";
#endif CONSDEST
	
}
inline void Boiler::show()
{
	cout << vender << '\t' << litresInSec << '\t' << power << endl;
}

