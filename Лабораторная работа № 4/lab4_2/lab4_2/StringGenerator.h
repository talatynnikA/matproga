#include "stdafx.h"
namespace lab4
{
	class StringGenerator
	{
		char *String;
	public:
		StringGenerator();
		StringGenerator(int num);
		char* GetString(int num);
		char* GetPrefix(char* string, int num);
	};
}