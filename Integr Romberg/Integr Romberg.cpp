// Integr Romberg.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<cmath>
using namespace std;
double f(double x)
{
	return(x*x*x*sqrt(4+x*x));
}
void S_pr(double(*f)(double), double a, double b, double h)
{
	int n = (b - a) / h;
	double sum = 0;
	for (double i = a; i < b; i += h)
	{
		sum += f((2 * i + h) / 2) * h;
	}
	cout << sum;
}
void S_trap(double(*f)(double), double a, double b, double h)
{
	int n = (b - a) / h;
	double sum = 0;
	for (double i = a + h; i < b; i += h)
	{
		sum += (f(i - h) + f(i)) / 2 * h;
	}
	cout<< sum;
}
void S_Simpson(double(*f)(double), double a, double b, double h)
{
	int n = (b - a) / h;
	double sum = 0;
	for (double i = a + h; i < b; i += h)
	{
		sum += (f(i - h) + 4 * f(((i - h) + i) / 2) + f(i)) / 6 * h;
	}
	cout<<sum;
}
double R(int n, int m, double(*f)(double), double a, double b)
{
	double sum = 0;
	double h=1;
	if (n == 0 && m == 0)
	{
		return (b - a) / 2;
	}
	else if (m == 0 && n != 0)
	{
		h = (b - a) / pow(2, n);
		for (int i = 1; i < pow(2, n - 1); i++)
		{
			sum += f(a + (2 * i - 1) * h);
		}
		return R(n - 1, 0, f, a, b) / 2 + sum * h;
	}
	else
	{
		return 1 / (pow(4, m) - 1) * (pow(4, m) * R(n, m - 1, f, a, b) - R(n - 1, m - 1, f, a, b));
	}
}
void Romberg(double(*f)(double), double a, double b)
{
	double eps = 0.001;
	double d, res1;
	double res = R(0, 0, f, a, b);
	int i = 1;
	do {
		res1 = res;
		res = R(i, 0, f, a, b);
		d = res - res1;
		i++;
	} while (abs(d) > eps);
	cout << res;
}

int main()
{
	double a = 1;
	double b= 5;
	double h = 1;
	S_pr(f, a, b, h);
	cout << endl;
	S_trap(f, a, b, h);
	cout << endl;
	S_Simpson(f, a, b, h);
	cout << endl;
	Romberg(f, a, b);
    return 0;
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
