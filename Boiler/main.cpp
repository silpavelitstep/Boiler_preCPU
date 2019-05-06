#include "boiler.h"

#include <iostream>
//#define TEST 1
using namespace std;
int main()
{
	{//чтобы boiler успел удалиться из стека до "pause"
		BoilerList blr;
		blr.menu();
		//TEST проверка функций на существование
		 //тело show неактивно
		//тело del неактивно
		//тело menu - пользовательский ввод заменен на автоматический
		//FILL используется автозаполнение при создании бойлера
		//CONSDEST для проверки факта запуска конструктора/деструктора
		//дополнительно отключается очистка экрана
		//TEST+FILL автозапуск add + автозаполнение boiler 
	}
	
	
	system("pause");
	return 0;
}