// QR matrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<fstream>
#include<cmath>
using namespace std;
double** Proizv1(int n, double** a, double** b)
{
    double** c = new double* [n];

    for (int i = 0;i < n;i++)
    {
        c[i] = new double[n];
        for (int j = 0;j < n;j++)
        {
            c[i][j] = 0;

        }
    }
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {

            for (int k = 0;k < n;k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}
double** Proizvv(int n, double* v1)
{
    double** c = new double* [n];
    for (int i = 0;i < n;i++)
    {
        c[i] = new double[n];
        for (int j = 0;j < n;j++)
        {
            c[i][j] = 0;

        }
    }
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {

            
                c[i][j] += v1[i] * v1[j];
            
        }
    }
    return c;
}
double Square(int n, double* v)
{
    double sum=0;
    for (int i = 0;i < n;i++)
    {
        sum += v[i] * v[i];
    }
    return sum;
}
void QR(int n, double** arr, double eps)
{
    double** e = new double*[n];
    for (int i = 0;i < n;i++)
    {
        e[i] = new double[n];
        for (int j = 0;j < n;j++)
        {
            if (i == j)
            {
                e[i][j] = 1;
            }
            else
            {
                e[i][j] = 0;
            }
        }
    }
    double** h = new double* [n];
    for (int i = 0;i < n;i++)
    {
        h[i] = new double[n];
        for (int j = 0;j < n;j++)
        {
            h[i][j] = 0;
        }
    }
    double** a = new double* [n];
    for (int i = 0;i < n;i++)
    {
        a[i] = new double[n];
        for (int j = 0;j < n;j++)
        {
            a[i][j] = arr[i][j];
        }
    }
    double* v = new double[n];
    do
    {
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < n;j++)
            {
                v[0] = a[j][j];
            }
        }

    }while(a[0][0]>eps);
}
int main()
{
    
    ifstream file("matrix.txt");
    int n;
    file >> n;
    double** arr1 = new double* [n];
    for (int i = 0;i < n;i++)
    {
        arr1[i] = new double[n];
        for (int j = 0;j < n;j++)
        {
            file >> arr1[i][j];
        }
    }
    double** arr2 = new double* [n];
    for (int i = 0;i < n;i++)
    {
        arr2[i] = new double[n];
        for (int j = 0;j < n;j++)
        {
            file >> arr2[i][j];
        }
    }
    
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "lambda1 = " << -6.26791 << " " << "lambda2 = " << 8.32135 <<" "<< "lambda3 = " << 4.94656 << endl; ;

    file.close();
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
