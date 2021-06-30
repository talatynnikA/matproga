#include "stdafx.h"
#pragma once
namespace lab4
{
	class Distance
	{
		int levenshtein(int lx, char* x, int ly, char* y);
		int levenshtein_r(int lx, char* x, int ly, char* y);
		int min3(int x1,int x2,int x3) const;
	public:
		Distance();
		int DynamicMethod(char* firstWord, char* secondWord);
		int RecursiveMethod(char* firstWord, char* secondWord);
	};
}