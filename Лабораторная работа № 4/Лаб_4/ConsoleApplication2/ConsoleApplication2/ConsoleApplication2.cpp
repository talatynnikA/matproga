// ConsoleApplication2.cpp: ���������� ����� ����� ��� ����������� ����������.
// --- main  
//    ����������� ������  
#include "stdafx.h"
#include <cmath>
#include <memory.h>
#include <iostream>
#include "MultyMatrix.h "   // ��������� ������ 

#define N 6
int main()
{

	int Mc[N + 1] = { 9, 12, 20, 23, 30, 40, 51 }, /*����������� ������*/Ms[N][N], r = 0, rd = 0;

	memset(Ms, 0, sizeof(int)*N*N);
	r = OptimalM(1, N, N, Mc, OPTIMALM_PARM(Ms));
	setlocale(LC_ALL, "rus");
	std::cout << std::endl;
	std::cout << std::endl << "-- ����������� ������ (����������� �������) "
		<< std::endl;
	std::cout << std::endl << "����������� ������: ";
	for (int i = 1; i <= N; i++) std::cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";
	std::cout << std::endl << "����������� ���������� �������� ���������: " << r;
	std::cout << std::endl << std::endl << "������� S" << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < N; j++)  std::cout << Ms[i][j] << "  ";
	}
	std::cout << std::endl;

	memset(Ms, 0, sizeof(int)*N*N);
	rd = OptimalMD(N, Mc, OPTIMALM_PARM(Ms));
	std::cout << std::endl
		<< "-- ����������� ������ (���������� ����������������) " << std::endl;
	std::cout << std::endl << "����������� ������: ";
	for (int i = 1; i <= N; i++)
		std::cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";
	std::cout << std::endl << "����������� ���������� �������� ���������: "
		<< rd;
	std::cout << std::endl << std::endl << "������� S" << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < N; j++)  std::cout << Ms[i][j] << "  ";
	}
	std::cout << std::endl << std::endl;
	system("pause");

	return 0;
}
