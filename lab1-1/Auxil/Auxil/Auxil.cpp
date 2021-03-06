// Auxil.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Auxil.h"
#include "Knapsack.h"
#define  CYCLE  100000 

namespace auxil {
	void start()                          // старт  генератора сл. чисел
	{
		srand((unsigned)time(NULL));
	}

	double dget(double rmin, double rmax) // получить случайное число
	{
		return ((double)rand() / (double)RAND_MAX) * (rmax - rmin) + rmin;
	}

	int iget(int rmin, int rmax)         // получить случайное число

	{
		return (int)dget((double)rmin, (double)rmax);
	}


}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Hello World!\n";
    std::cout << "Hello World!\n";
    std::cout << "старт  генератора сл. чисел(start)\n";
    start();
    std::cout << "получить случайное число(dget)\n";
    std::cout << dget(-123, 256) << "\n";

    std::cout << "получить случайное число(iget)\n";
    std::cout << iget(0, 999) << "\n";
    std::cout << "Hello World!\n";


	std::cout << "ПРИМЕР 2\n";

	double  av1 = 0, av2 = 0;
	clock_t  t1 = 0, t2 = 0;

	setlocale(LC_ALL, "rus");

	auxil::start();                          // старт генерации 
	t1 = clock();                            // фиксация времени 
	for (int i = 0; i < CYCLE; i++)
	{
		av1 += (double)auxil::iget(-100, 100); // сумма случайных чисел 
		av2 += auxil::dget(-100, 100);         // сумма случайных чисел 
	}
	t2 = clock();                            // фиксация времени 


	std::cout << std::endl << "количество циклов:         " << CYCLE;
	std::cout << std::endl << "среднее значение (int):    " << av1 / CYCLE;
	std::cout << std::endl << "среднее значение (double): " << av2 / CYCLE;
	std::cout << std::endl << "продолжительность (у.е):   " << (t2 - t1);
	std::cout << std::endl << "                  (сек):   "
		<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
	std::cout << std::endl;
	system("pause");

	system("pause");


    return 0;
}

void start()                          // старт  генератора сл. чисел
{
    srand((unsigned)time(NULL));
}

double dget(double rmin, double rmax) // получить случайное число
{
    return ((double)rand() / (double)RAND_MAX) * (rmax - rmin) + rmin;
}

int iget(int rmin, int rmax)         // получить случайное число

{
    return (int)dget((double)rmin, (double)rmax);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
