// lab4_2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "StringGenerator.h"
#include <ctime>
#include <iostream>
#include "Distance.h"
#include "MultiMatrix.h"
#define N 6
using namespace lab4;
namespace lab4
{
	void DistanceClac()
	{
		setlocale(LC_CTYPE,"Rus");
		int nums = 7;
		double divider = 1;
		int stringLenght = 300;
		int strLen1, strLen2 = 0;
		srand(time(nullptr));
		StringGenerator *sGen = new StringGenerator();
		char *s1 = sGen->GetString(stringLenght);
		char *s2 = sGen->GetString(stringLenght - 50);
		//
		Distance *distance = new Distance();
		for (int i = nums; i != -1; i--)
		{
			strLen1 = (stringLenght - 10)*(divider / (i + 1));
			strLen2 = (stringLenght - 10)*(divider / (i + 1));
			std::cout << "№" << nums - i << std::endl;
			std::cout << "Длины строк: " << strLen1 << " и  " << strLen2 << std::endl;
			std::cout << "Кол-во тактов (динамичиск. прог.):" << distance->DynamicMethod(sGen->GetPrefix(s1,strLen1), sGen->GetPrefix(s2, strLen2));
			//std::cout << "Кол-во тактов(рекурсия):" << distance->RecursiveMethod(sGen->GetPrefix(s1, strLen1), sGen->GetPrefix(s2, strLen2));
			std::cout << std::endl;
		}
	}
	void Brackets()
	{
	setlocale(LC_ALL, "rus");
			int Mc[N+1] = { 100, 15, 20, 43, 70, 40, 71 }, Ms[N][N], r = 0, rd = 0;
			clock_t start, stop;
			/*memset(Ms, 0, sizeof(int)*N*N);
			start = clock();
			r = OptimalM(1, N, N, Mc, OPTIMALM_PARM(Ms));
			stop = clock();
			
			std::cout << std::endl;
			std::cout << std::endl << "-- расстановка скобок (рекурсивное решение). Time: " << stop - start
				<< std::endl;
			std::cout << std::endl << "размерности матриц: ";
			for (int i = 1; i <= N; i++) std::cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";
			std::cout << std::endl << "минимальное количество операций умножения: " << r;
			std::cout << std::endl << std::endl << "матрица S" << std::endl;
			for (int i = 0; i < N; i++)
			{
				std::cout << std::endl;
				for (int j = 0; j < N; j++)  std::cout << Ms[i][j] << "  ";
			}
			std::cout << std::endl;
			*/
			memset(Ms, 0, sizeof(int)*N*N);
			start = clock();
			rd = OptimalMD(N, Mc, OPTIMALM_PARM(Ms));
			stop = clock();
			std::cout << std::endl
				<< "-- расстановка скобок (динамичеое программирование). Time: " << stop - start << std::endl;
			std::cout << std::endl << "размерности матриц: ";
			for (int i = 1; i <= N; i++)
				std::cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";
			std::cout << std::endl << "минимальное количество операций умножения: "
				<< rd;
			std::cout << std::endl << std::endl << "матрица S" << std::endl;
			for (int i = 0; i < N; i++)
			{
				std::cout << std::endl;
				for (int j = 0; j < N; j++)  std::cout << Ms[i][j] << "  ";
			}
			std::cout << std::endl << std::endl;
			system("pause");
		
	}
}
int main()
{
	srand(time(nullptr));
	//DistanceClac();
	Brackets();
	return 0;
}

