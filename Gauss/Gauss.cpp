// Gauss.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int search_max(double** arr, int n, int j)
{
	double max = arr[0][j];
	int i_max = 0;
	for (int i = 0; i < n; i++)
	{
		if (max < abs(arr[i][j]))
		{
			max = arr[i][j];
			i_max = i;
		}
	}
	return i_max;
}
void swap_row(double** arr, int i, int j, int n)
{
	double* a = new double[n];
	for (int k = 0; k < n; k++)
	{
		a[k] = arr[i][k];
		arr[i][k] = arr[j][k];
		arr[j][k] = a[k];
	}
	delete[]a;
}
void epsilon(double** arr, int n, int m, double eps)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (abs(arr[i][j]) < eps)
			{
				arr[i][j] = 0;
			}
		}
	}
}
void gayss(double** arr, int n, int m)
{
	int a = 0;
	int i;
	double eps = 0.00001;
	do {
		epsilon(arr, n, m, eps);
		i = search_max(arr, n, a);
		if (i == a);
		else
		{
			swap_row(arr, a, i, m);
		}
		double c = arr[a][a];//константа 1
		for (int j = 0; j < m; j++)
		{
			arr[a][j] = (double)arr[a][j] / c;
		}
		for (int i = 0; i < n; i++)
		{
			double c1 = arr[i][a];//констата 2
			if (i == a);
			else
			{
				if (abs(arr[i][a]) < eps);
				if (abs(arr[i][a]) > eps)
				{
					for (int j = 0; j < m; j++)
					{
						arr[i][j] = (double)arr[i][j] - c1 * arr[a][j];
					}
				}
			}
		}
		a++;
	} while (a < n);
}
int main()
{
    int n = 4;
    double** mat1 = new double* [n];
    for (int i = 0; i < n; i++)
    {
        mat1[i] = new double[n + 1];
    }
    mat1[0][0] = 8;
    mat1[0][1] = 8;
    mat1[0][2] = -5;
    mat1[0][3] = -8;
    mat1[0][4] = 13;
    mat1[1][0] = 8;
    mat1[1][1] = -5;
    mat1[1][2] = 9;
    mat1[1][3] = -8;
    mat1[1][4] = 38;
    mat1[2][0] = 5;
    mat1[2][1] = -4;
    mat1[2][2] = -6;
    mat1[2][3] = -2;
    mat1[2][4] = 14;
    mat1[3][0] = 8;
    mat1[3][1] = 3;
    mat1[3][2] = 6;
    mat1[3][3] = 6;
    mat1[3][4] = -95;
    gayss(mat1, n, n + 1);
    for (int i = 0; i < n; i++)
    {
        cout << mat1[i][n] << "  ";
    }
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
