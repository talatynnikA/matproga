#include "stdafx.h"
#include "StringGenerator.h"
#include <cstdlib>
#include <cstring>

lab4::StringGenerator::StringGenerator()
{
	
}
lab4::StringGenerator::StringGenerator(int num)
{
	String = GetString(num);
}
char* lab4::StringGenerator::GetString(int num)
{
	int i = 0;
	char *tmp = new char[num+1]();
	for (i = 0; i < num; i++)
	{
		tmp[i] = 97 + rand() % 25;
	}
	tmp[num] = 0;
	return tmp;
}

char* lab4::StringGenerator::GetPrefix(char* string, int num)
{
	int i = 0;
	char *result = new char[num]();
	while(i < num)
	{
		result[i] = string[i];
		i++;
	}
	result[num] = 0;
	return result;
}