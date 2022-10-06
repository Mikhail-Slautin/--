// SLAU progonka.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<fstream>
using namespace std;

double* Func(double** arr, double* y, int n)
{
	double* x = new double[n];
	double* P = new double[n];
	double* Q = new double[n];
	P[0] = -arr[0][1]/arr[0][0];
	Q[0] = y[0] / arr[0][0];
	for (int i = 1;i < n - 1;i++)
	{
		P[i] = -arr[i][i + 1] / (arr[i][i] + arr[i ][i-1] * P[i - 1]);
		Q[i] = (-arr[i ][i-1] * Q[i - 1] +y[i]) / (arr[i][i] + arr[i + 1][i] * P[i - 1]);
	}
	x[n-1] = (-arr[n -1][n-2] * Q[n - 2] + y[n-1]) / (arr[n-1][n-1] +arr[n-1][n-2] * P[n - 2]);
	for (int k = n - 2;k >= 0;k--)
	{
		x[k] = P[k] * x[k + 1] + Q[k];
	}
	return x;

}
double* progonka(double** mat, int n)//где размер матрицы n на n+1
{
	double* a = new double[n];
	double* b = new double[n];
	double* res = new double[n];
	double F, A, B, C;
	A = 0;
	a[0] = 0;
	b[0] = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (i != 0)
		{
			A = mat[i][i - 1];
		}
		B = mat[i][i];
		C = mat[i][i + 1];
		F = mat[i][n];
		a[i + 1] = -C / (A * a[i] + B);
		b[i + 1] = (F - A * b[i]) / (A * a[i] + B);
	}
	res[n - 1] = (mat[n - 1][n] - mat[n - 1][n - 2] * b[n - 1]) / (mat[n - 1][n - 1] + mat[n - 1][n - 2] * a[n - 1]);
	for (int i = n - 2; i >= 0; i--)
	{
		res[i] = a[i + 1] * res[i + 1] + b[i + 1];
	}
	delete[]a;
	delete[]b;
	return res;
}
int main()
{
	
	int n = 5;
	double** mat = new double* [n];
	double* res = new double[n];
	for (int i = 0; i < n; i++)
	{
		mat[i] = new double[n + 1];
		for (int j = 0; j < n; j++)
		{
			mat[i][j] = 0;
		}
	}
	mat[0][0] = 16;
	mat[0][1] = -9;
	mat[1][0] = 8;
	mat[1][1] = -13;
	mat[1][2] = -5;
	mat[2][1] = -3;
	mat[2][2] = -21;
	mat[2][3] = 9;
	mat[3][2] = -9;
	mat[3][3] = 16;
	mat[3][4] = -5;
	mat[4][3] = 1;
	mat[4][4] = -9;
	mat[0][n] = -27;
	mat[1][n] = -84;
	mat[2][n] =-225;
	mat[3][n] = -89;
	mat[4][n] = 69;
	res = progonka(mat, n);
	for (int i = 0; i < n; i++)
	{
		cout << res[i] << " ";
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
