#pragma once
#ifndef BOILER_H
#define BOILER_H
struct Boiler
{
	char vender[20];//
	int litresInSec;
	int power;//watt
	Boiler();
	~Boiler();
	inline void show();
};
struct BoilerList
{
	Boiler *pBoiler[20] = {};//max count boiler is 20;
	int countBoilers=0;
	int menu();
	int add();
	int show();
	int del();
	int clear();
	~BoilerList();
	BoilerList();
};



#endif BOILER_H