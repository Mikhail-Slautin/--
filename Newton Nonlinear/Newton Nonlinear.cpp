﻿// Newton Nonlinear.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
using namespace std;

typedef double(*func)(double x);

double func1(double x);
double dfunc(double x, func f);

double func1(double x)
{
    return (pow(4, x) - 5 * x - 2);
}

double dfunc(double x, func func1)
{
    double h = 1e-4;
    return((func1(x+h)-func1(x))/h);
}

int main()
{
    double eps = 1e-4;
    double x0;
    double x1;
    cin>> x0;
    x1 = x0 - func1(x0) / dfunc(x0,&func1);
    while(abs(x1-x0)>eps)
    {
        x0 = x1;
        x1 = x0 - func1(x0) / dfunc(x0,&func1);
        
    }
    cout << x1;  
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
