// IntegGauss.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
double Gauss_2(double(*f)(double, double), double beta, int N, int M, double a, double b, double c, double d)
{
	double sum = 0;
	double h_x = (b - a) / N;
	double h_y = (d - c) / M;
	double x, y;
	double B = beta;
	for (int i = 0; i < N; i++)
	{
		x = a + (i + 0.5) * h_x;
		for (int j = 0; j < M; j++)
		{
			y = c + (j + 0.5) * h_y;
			sum += f(x - 0.5 * B * h_x, y + 0.5 * B * h_y) + f(x + 0.5 * B * h_x, y + 0.5 * B * h_y) + f(x + 0.5 * B * h_x, y - 0.5 * B * h_y) + f(x - 0.5 * B * h_x, y - 0.5 * B * h_y);
		}
	}
	return 0.25 * h_x * h_y * sum;
}
double Gauss(double(*f)(double), double* W, double* z, int N, int M, double a, double b)
{
	double h = (b - a) / N;
	double sum = 0;
	double x;
	for (int i = 0; i < N; i++)
	{
		x = a + (i + 0.5) * h;
		for (int j = 0; j < M; j++)
		{
			sum += W[j] * f(x + 0.5 * h * z[j]);
		}
	}
	return 0.5 * h * sum;
}
double f1(double x)
{
	return x * log(1 + x);
}
double f12(double x, double y)
{
	return 1. / (1 + x * y);
}
int main()
{
	setlocale(LC_ALL, "Russian");
	
	/*int M =3;
	double* W = new double[M];
	double* z = new double[M];
	z[0] = -sqrt(0.6);
	z[1] = 0;
	z[2] = sqrt(0.6);
	W[0] = 5. / 9;
	W[1] = 8. / 9;
	W[2] = 5. / 9;
	int N = 1;
	double a = 0;
	double b = 1;
	cout << Gauss(f1, W, z, N, M, a, b) << endl;*/
	double h_x = 0.01;
	double h_y = 0.01;
	double alpha = 1. / 2;
	double a, b, c, d;
	a = 0;
	c = 0;
	b = 1;
	d = 1;
	int N, M;
	double pi = 3.1415926535;
	double Real = pi * pi / 12.;
	double I;
	double beta = sqrt(1 / 3.);
	cout<< "k"<< " "<< "I" <<" "<< "e"<< " "<< "Относительная погрешность:"<< endl;
	for (int i = 0; i < 3; i++)
	{
		h_x = pow(alpha, i);
		h_y = pow(alpha, i);
		M = (d - c) / h_y;
		N = (b - a) / h_x;
		I = Gauss_2(f12, beta, N, M, a, b, c, d);
		cout << i<< " " << I<< " " << Real - I << " " << fabs((Real - I) / Real) << endl;
		
	}
	

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
