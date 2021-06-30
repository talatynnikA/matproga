#include "stdafx.h"
#include "Combi.h"
namespace combi
{
	accomodation::accomodation(short n, short m) // конструктор
	{
		this->n = n; //разменость исходного множества
		this->m = m; //размерность генерируемых размещений
		this->cgen = new xcombination(n, m);
		this->pgen = new permutation(m);
		this->sset = new short[m]; //указатель на массив индексов
		this->reset();
	}

	void  accomodation::reset() //сброс текущего состояния, для начало работы сначало
	{
		this->na = 0; //номер текущего размещения
		this->cgen->reset();
		this->pgen->reset();
		this->cgen->getfirst();
	};

	short accomodation::getfirst() //формирует первое размещение
	{
		short rc = (this->n >= this->m) ? this->m : -1;
		if (rc > 0)
		{
			for (int i = 0; i <= this->m; i++)
				this->sset[i] = this->cgen->sset[this->pgen->ntx(i)];
		};
		return rc;
	};

	short accomodation::getnext() //формирует массив следующего размещения
	{
		short rc;
		this->na++;
		if ((this->pgen->getnext())> 0) rc = this->getfirst();
		else  if ((rc = this->cgen->getnext())> 0)
		{
			this->pgen->reset();  rc = this->getfirst();
		};
		return rc;
	};

	short accomodation::ntx(short i) // возвращает значение элемента массива индексов
	{
		return this->sset[i];
	};

	unsigned __int64 fact(unsigned __int64 x){ return (x == 0) ? 1 : (x*fact(x - 1)); };

	unsigned __int64  accomodation::count() const //вычисление общего количества размещений
	{
				return (this->n >= this->m) ?
			fact(this->n) / fact(this->n - this->m) : 0;
	};
}

