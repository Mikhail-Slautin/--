// SLAU Jacobi.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<cmath>
#include<fstream>
#include<omp.h>
using namespace std;
bool Accuracy(int n, double* x, double* x_1, double eps);
void Jacobi(int n, double** arr, double* b, double* x);

bool Accuracy(int n,double* x, double* x_1,double eps)
{
	double norm;
	norm = fabs(x[0] - x_1[0]);
#pragma omp parallel for
	for (int i = 0;i < n;i++)
	{
		if (fabs(x[i] - x_1[i]) > norm)
			norm = fabs(x[i] - x_1[i]);
		
		x[i] = x_1[i];
	}
	return(norm < eps);
	
	
}
void Jacobi(int n, double** arr, double* b, double* x)
{
	double* TempX = new double[n]; 
	double eps = 1e-4;
	int k = 0;
	do {
#pragma omp parallel for 
	
			for (int i = 0; i < n; i++)
			{
				TempX[i] = b[i];

#pragma omp parallel for 
				for (int j = 0; j < n; j++)
				{
					if (i != j)
						TempX[i] -= arr[i][j] * x[j];
				}
				TempX[i] /= arr[i][i];
			}
	
			k++;
	} while (!Accuracy(n,x,TempX,eps));
	
	delete[] TempX;
}
int main()
{
	ifstream file("matrix.txt");
	int n;
	file >> n;
	double** arr = new double* [n];
	for (int i = 0;i < n;i++)
	{
		arr[i] = new double[n];
		for (int j = 0;j < n;j++)
		{
			file >> arr[i][j];
		}
	}
	double* b = new double[n];
	for (int i = 0;i < n;i++)
	{
		file >> b[i];
	}
	double* x = new double[n];
	for (int i = 0;i < n;i++)
	{
		file >> x[i];
	}
	
	double start, stop;
	start = omp_get_wtime();
	Jacobi(n, arr, b, x);
	stop = omp_get_wtime();
	for (int i = 0;i < n;i++)
	{
		cout << x[i] << " ";
	}
	cout << endl;
	cout << stop - start;
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
