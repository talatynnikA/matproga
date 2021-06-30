// Knapsack.cpp 
#include <iostream>

#include "Knapsack.h"
// Main 
#include "Combi1.h"
#include <tchar.h>
#include "Knapsack.h"
#define NN 4
#define NINF 0x80000000    // самое малое int-число  

namespace combi1
{
    struct  subset       // генератор  множества всех подмножеств    
    {
        short  n,        // количество элементов исходного множества < 64  
            sn,          // количество элементов текущего  подмножества
            * sset;             // массив индексов текущего подмножества 
        unsigned __int64 mask;  // битовая маска  
        subset(short n = 1);    // конструктор(кол-во эл-ов исх. мн-ва) 
        short getfirst();       // сформ. массив индексов по битовой маске    
        short getnext();        // ++маска и сформировать массив индексов 
        short ntx(short i);       // получить i-й элемент массива индексов 
        unsigned __int64 count(); // вычислить общее кол-во подмножеств 
        void reset();             // сбросить генератор, начать сначала 
    };
}
int main()
{
    setlocale(LC_CTYPE, "rus");
    int V = 100,   // вместимость рюкзака              
        v[NN] = { 25, 30, 60, 20 },     // размер предмета каждого типа  
        c[NN] = { 25, 10, 20, 30 };     // стоимость предмета каждого типа 
    short m[NN];   // количество предметов каждого типа  {0,1}   
    int maxcc = knapsack_s(
        V,   // [in]  вместимость рюкзака 
        NN,  // [in]  количество типов предметов 
        v,   // [in]  размер предмета каждого типа  
        c,   // [in]  стоимость предмета каждого типа     
        m    // [out] количество предметов каждого типа  
    );
    std::cout << std::endl << "-------- Задача о рюкзаке ---------";
    std::cout << std::endl << "- количество предметов : " << NN;
    std::cout << std::endl << "- вместимость рюкзака  : " << V;
    std::cout << std::endl << "- размеры предметов    : ";
    for (int i = 0; i < NN; i++) std::cout << v[i] << " ";
    std::cout << std::endl << "- стоимости предмета   : ";
    for (int i = 0; i < NN; i++) std::cout << c[i] << " ";
    std::cout << std::endl << "- стоимости предметов  : ";
    for (int i = 0; i < NN; i++) std::cout << v[i] * c[i] << " ";
    std::cout << std::endl << "- оптимальная стоимость рюкзака: " << maxcc;
    std::cout << std::endl << "- вес рюкзака: ";
    int s = 0; for (int i = 0; i < NN; i++) s += m[i] * v[i];
    std::cout << s;
    std::cout << std::endl << "- выбраны предметы: ";
    for (int i = 0; i < NN; i++) std::cout << " " << m[i];
    std::cout << std::endl << std::endl;
    system("pause");
    return 0;
}

int calcv(combi1::subset s, const int v[])  // объем в рюкзаке
{
    int rc = 0;
    for (int i = 0; i < s.sn; i++) rc += v[s.ntx(i)];
    return rc;
};
int calcc(combi1::subset s, const int v[], const int c[]) //стоимость в рюкзаке 
{
    int rc = 0;
    for (int i = 0; i < s.sn; i++) rc += (v[s.ntx(i)] * c[s.ntx(i)]);
    return rc;
};
void setm(combi1::subset s, short m[]) //отметить выбранные предметы 
{
    for (int i = 0; i < s.n; i++) m[i] = 0;
    for (int i = 0; i < s.sn; i++) m[s.ntx(i)] = 1;
};
int   knapsack_s(
    int V,         // [in] вместимость рюкзака 
    short n,       // [in] количество типов предметов 
    const int v[], // [in] размер предмета каждого типа  
    const int c[], // [in] стоимость предмета каждого типа
    short  m[]     // [out] количество предметов каждого типа {0,1} 
)
{
    combi1::subset s(n);
    int maxc = NINF, cc = 0;
    short  ns = s.getfirst();
    while (ns >= 0)
    {
        if (calcv(s, v) <= V)
            if ((cc = calcc(s, v, c)) > maxc)
            {
                maxc = cc;
                setm(s, m);
            }
        ns = s.getnext();
    };
    return maxc;
};

