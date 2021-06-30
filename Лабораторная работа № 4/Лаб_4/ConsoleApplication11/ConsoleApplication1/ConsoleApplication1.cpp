// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{	
	setlocale(LC_ALL,"rus");
	clock_t t1 = 0, t2 = 0, t3,t4;
	Auxil *Rand = new Auxil();
	unsigned int lenS1=100, lenS2=50;
	float k[7] = { 0.04F, 0.05F, 0.067F, 0.1F, 0.2F, 0.5F, 1.0F };
	char *S1 = new char[lenS1],
		 *S2 = new char[lenS2];
	for(unsigned int i=0; i<(lenS1>lenS2?lenS1:lenS2); i++)
	{	if(i<lenS1)
			S1[i]=(int)Rand->get_int('a','z');
		if(i<lenS2)
			S2[i]=(int)Rand->get_int('a','z');
	}
	std::cout<<S1<<std::endl<<S2<<std::endl;
	//std::cout<<std::endl<< "-- расстояние Левенштейна -----"<< std::endl;
	std::cout<<std::endl<< "--длина --- рекурсия -- дин.програм. ---"<<std::endl;
	for (int i = 0; i <  sizeof(k)/sizeof(float); i++)
	{	t1 = clock();
		levenshtein_r((int)(k[i]*lenS1),S1,(int)(k[i]*lenS2 + 1),S2);
		t2 = clock();
		t3 = clock();
		levenshtein((int)(k[i]*lenS1),S1,(int)(k[i]*lenS2 + 1),S2); 
		t4 = clock();
		std::cout<<std::right<<std::setw(2)<<(int)(k[i]*lenS2)<<"/"<<std::setw(2)<<(int)(k[i]*lenS1 + 1)
			<< "        "<<std::left<<std::setw(10)<<(t2-t1)
			<<"   "<<std::setw(10)<<(t4-t3)<<std::endl;  
	}
	return 0;
}

