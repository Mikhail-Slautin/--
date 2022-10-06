// Method Vrazchenii.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<fstream>
#include<cmath>
using namespace std;
void Proizv(int n, double** a, double** b, double** c);
void Vraz(int n, double** arr, double eps);
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
void Proizv(int n, double** a, double** b, double** c)
{
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            c[i][j] = 0;
            for (int k = 0;k < n;k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void Vraz(int n, double** arr, double eps)
{
    double** a = new double* [n];
    
    double** h1 = new double* [n];
    for (int i = 0;i < n;i++)
    {
        a[i] = new double[n];
        h1[i] = new double[n];
        for (int j = 0;j < n;j++)
        {
            a[i][j] = arr[i][j];
            if (i == j)
            {
                h1[i][j] = 1;
            }
            else
            {
                h1[i][j] = 0;
            }
        }
    }
    double max = 1 ;
    int k = 0;
    while ((max > eps) || (k<2))
    {
        max = 0;
        int i_max = 0;
        int j_max = 0;
        double p;
        for (int i = 0;i < n;i++)
        {
            for (int j = i+1;j<n;j++)
            {
                
                    if (abs(a[i][j]) > max)
                    {
                        max = abs(a[i][j]);
                        i_max = i;
                        j_max = j;

                    }
                
            }
        }
        p = 2 * max / (a[i_max][i_max] - a[j_max][j_max]);
        double sinphi, cosphi;
        int sign;
        if (p > 0)
        {
            sign = 1;
        }
        else if (p < 0)
        {
            sign = -1;
        }
        else
        {
            sign = 0;
        }
        sinphi = sign * sqrt(0.5 * (1 - 1 / sqrt(1 + p*p)));
        cosphi = sqrt(0.5 * (1 + 1 / sqrt(1 + p*p)));
        double** h = new double* [n];
       
        for (int i = 0;i < n;i++)
        {
            h[i] = new double[n];
            for (int j = 0;j < n;j++)
            {
                 if (i == j )
                {
                    
                   h[i][j] = 1;
                }
               
                else
                {
                    h[i][j] = 0;
                }
                
            }
        }
        h[i_max][i_max] = cosphi;
        h[i_max][j_max] = -sinphi;
        h[j_max][j_max] = cosphi;
        h[j_max][i_max] = sinphi;
        h1 = Proizv1(n, h1, h);
        double** ht = new double* [n];
        for (int i = 0;i < n;i++)
        {
            ht[i] = new double[n];
            for(int j=0;j<n;j++)
            {
                ht[i][j] = h[j][i];
            }
        }
        double** a1 = new double* [n];
        for (int i = 0;i < n;i++)
        {
            a1[i] = new double[n];
            for (int j = 0;j < n;j++)
            {
                a1[i][j] = 0;
            }
        }
        Proizv(n, ht, a, a1);
        Proizv(n, a1, h, a);
        k++;
    }
    
    double ro = a[0][0];
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            if (i == j)
            {
                if (a[i][j] > ro) ro = a[i][j];
                
            }
            
        }
        
    }
    cout << ro;
   
    /*for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            cout << h1[i][j] << " ";
        }
        cout << endl;
    };*/
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
    double eps;
    file >> eps;
    Vraz(n, arr, eps);
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
