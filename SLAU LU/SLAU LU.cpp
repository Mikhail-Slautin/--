// SLAU LU.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<cmath>
#include <fstream>
using namespace std;


double helpfunk(double** arr, int n, int a)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i][a] == 0);
        else
        {
            return i;
            break;
        }
    }
}
void obr(double** mat, int n)
{
    double** arr = new double* [n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new double[2 * n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = mat[i][j];
        }
        for (int j = n; j < 2 * n; j++)
        {
            if (i == j - n)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = 0;
            }
        }
    }
    for (int a = 0; a < n; a++)
    {
        {
            if (arr[a][a] == 0)
            {
                int i = helpfunk(arr, n, a);
                for (int j = 0; j < n; j++)
                {
                    arr[a][j] = arr[a][j] + arr[i][j];
                }
            }
            double c = arr[a][a];
            for (int j = 0; j < 2 * n; j++)
            {
                arr[a][j] = (double)arr[a][j] / c;
            }
            for (int i = 0; i < n; i++)
            {
                double d = arr[i][a];
                if (i == a);
                else
                {
                    if (arr[i][a] == 0);
                    if (arr[i][a] != 0)
                    {
                        for (int j = 0; j < 2 * n; j++)
                        {
                            arr[i][j] = (double)arr[i][j] - d * arr[a][j];
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j < 2 * n; j++)
        {
            mat[i][j - n] = arr[i][j];
        }
    }
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
bool LU(double** mat, int n, int m, double** L, double** U)
{
    double eps = 0.00001;
    double** tmp = new double* [n];
    for (int i = 0; i < n; i++)
    {
        tmp[i] = new double[2 * m];
        for (int j = 0; j < m; j++)
        {
            tmp[i][j] = mat[i][j];
        }
        for (int j = m; j < 2 * m; j++)
        {
            if (i == j - m)
            {
                tmp[i][j] = 1;
            }
            else
            {
                tmp[i][j] = 0;
            }
        }
    }
    double tmp_;
    for (int k = 0; k < n - 1; k++)
    {
        epsilon(tmp, n, 2 * n, eps);
        if (abs(tmp[k][k]) < eps)
        {
            return false;
        }
        else
        {
            for (int i = k + 1; i < n; i++)
            {
                tmp_ = tmp[i][k] / tmp[k][k];
                for (int j = 0; j < 2 * m; j++)
                {
                    tmp[i][j] -= tmp_ * tmp[k][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            U[i][j] = tmp[i][j];
        }
        for (int j = m; j < 2 * m; j++)
        {
            L[i][j - m] = tmp[i][j];
        }
    }
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            cout << L[i][j] << " ";
        }
        cout<< endl;
    }
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            cout << U[i][j] << " ";
        }
        cout << endl;
    }
    obr(L, n);
    return true;
}
bool LU_clay(double** mat, double* b, double* res, int n)
{
    double** L = new double* [n];
    double** U = new double* [n];
    double* tmp = new double[n];
    double tmp_ = 0;
    for (int i = 0; i < n; i++)
    {
        L[i] = new double[n];
        U[i] = new double[n];
    }
    if (LU(mat, n, n, L, U))
    {
        for (int i = 0; i < n; i++)
        {
            tmp_ = 0;
            for (int j = 0; j < i; j++)
            {
                tmp_ += tmp[j] * L[i][j];
            }
            tmp[i] = (b[i] - tmp_) / L[i][i];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            tmp_ = 0;
            for (int j = i + 1; j < n; j++)
            {
                tmp_ += res[j] * U[i][j];
            }
            res[i] = (tmp[i] - tmp_) / U[i][i];
        }
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    setlocale(LC_ALL, "rus");
    ifstream fin("matrix.txt");
    
   
    int n;
    fin >> n;
    
    double** arr = new double* [n];
    for (int i = 0;i < n;i++)
    {
        arr[i] = new double[n];
        for (int j = 0;j < n;j++)
        {
            fin >> arr[i][j];
        }
    }
  
    double* b = new double[n];
    for (int i = 0;i < n;i++)
    {
        fin >> b[i];
    }
    double* res = new double[n];
    cout << LU_clay(arr, b, res, n) << endl;
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << "  ";
    }
    cout << endl;

    fin.close();
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
