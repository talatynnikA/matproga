// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
// --- main  
//    вычисление дистанции (расстояния) Левенштейна 
#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "Levenshtein.h"
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	clock_t t1 = 0, t2 = 0, t3, t4;
	char x[] = "сом", y[] = "домик";
	int  lx = sizeof(x)-1, ly = sizeof(y)-1;
	std::cout << std::endl;
	std::cout << std::endl << "-- расстояние Левенштейна -----" << std::endl;
	//std::cout << std::endl << x << "->" << y << " = " << levenshtein_r(sizeof(x)-1, x, sizeof(y)-1, y) << std::endl;
	std::cout << std::endl << "--длина --- рекурсия -- дин.програм. ---"
		<< std::endl;

	for (int i = 8; i < std::min(lx, ly); i++)
	{

		t1 = clock(); levenshtein_r(i, x, i - 2, y); t2 = clock();
		t3 = clock(); levenshtein(i, x, i - 2, y); t4 = clock();
		std::cout << std::right << std::setw(2) << i - 2 << "/" << std::setw(2) << i
			<< "        " << std::left << std::setw(10) << (t2 - t1)
			<< "   " << std::setw(10) << (t4 - t3) << std::endl;
	}
	system("pause");
	return 0;
}
