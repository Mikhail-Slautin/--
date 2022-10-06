// Newton.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
using namespace std;

double Newton(double* y, double* x, double xpoint, int n);
double Func(double x);

double Func(double x)
{
    return (exp(x) - x);
}

double Newton(double* y, double* x, double xpoint, int n)
{
    double sum = y[0];
    for (int i = 0;i <n;i++)
    {
        double P = 0;
        for (int j=0;j<n;j++)
        {
            double F = 1;
            for (int k = 0;k <n;k++)
            {
                if (k != j)
                {
                    F *= (x[j] - x[k]);
                }
            }
            P += y[j] / F;

        }
      
        sum+= P*(xpoint - x[i]);
         
    }
    return sum/2;

}

int main()
{
    setlocale(LC_ALL, "Russian");

    double xpoint = -0.5;
    int n = 4;
    double* x = new double[n];
    for (int i = 0;i < n;i++)
    {
        cin >> x[i];
    }
    double* y = new double[n];
    for (int i = 0;i < n;i++)
    {
        y[i] = Func(x[i]);
    }



    cout << "Значение полинома Ньютона: " << Newton(y, x, xpoint, n) << endl;
    cout << "Значение истинной функции: " << Func(xpoint) << endl;
    cout << "Погрешность: " << abs(Newton(y, x, xpoint, n) - Func(xpoint)) << endl;
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
