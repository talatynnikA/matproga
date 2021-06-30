#include "stdafx.h"
#include "Combi.h"
#include <algorithm>
namespace combi
{
	xcombination::xcombination(short n, short m) /*конструктор с параметрами(первый определяет кол-фо элементов в исходном множестве, 
												 а второй -кол-во элементов в генерируемом сочитании)*/
	{
		this->n = n; //мощность исходного множества
		this->m = m; //	кол-во элем. в генерируемых сочетаний
		this->sset = new short[m + 2]; // адрес нулевого элем. массива индексов
		this->reset();
	}

	void  xcombination::reset()     // сбросить генератор, начать сначала 
	{
		this->nc = 0; // номер текущего сочетания
		for (int i = 0; i < this->m; i++) this->sset[i] = i;
		this->sset[m] = this->n;
		this->sset[m + 1] = 0;
	};

	short xcombination::getfirst() //проверяет корректность параметров
	{
		return (this->n >= this->m) ? this->m : -1;
	};

	short xcombination::getnext()    // сформировать следующий массив индексов  
	{
		short rc = getfirst();
		if (rc > 0)
		{
			short j;
			for (j = 0; this->sset[j] + 1 == this->sset[j + 1]; ++j)
				this->sset[j] = j;
			if (j >= this->m) rc = -1;
			else {
				this->sset[j]++;
				this->nc++;
			};
		}
		return rc; //возвращает отриц значение, если j-индекс >= m
	};

	short xcombination::ntx(short i) //возвращает значение элемента массива индексов
	{
		return this->sset[i];
	};

	unsigned __int64 fact(unsigned __int64 x){ return(x == 0) ? 1 : (x*fact(x - 1)); }; //вычислительная функция 

	unsigned __int64 xcombination::count() const // вычисляет и возвращает общее кол-во сочетаний из n по m 
	{
		return (this->n >= this->m) ?
			fact(this->n) / (fact(this->n - this->m)*fact(this->m)) : 0;
	};
};
