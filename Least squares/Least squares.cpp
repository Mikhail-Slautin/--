// Least squares.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
using namespace std;

double* gauss(double** a, double* y, int n);
double func1(double* x, int n,int m);
double func3(double* x, double* y, int n, int m);


double* gauss(double** a, double* y, int n)
{
    double* x, max;
    int k, index;
    const double eps = 0.000001;  // точность
    x = new double[n];
    k = 0;
    while (k < n)
    {
        // Поиск строки с максимальным a[i][k]
        max = abs(a[k][k]);
        index = k;
        for (int i = k + 1; i < n; i++)
        {
            if (abs(a[i][k]) > max)
            {
                max = abs(a[i][k]);
                index = i;
            }
        }
        // Перестановка строк
        if (max < eps)
        {
            // нет ненулевых диагональных элементов
            cout << "Решение получить невозможно из-за нулевого столбца ";
            cout << index << " матрицы A" << endl;
            return 0;
        }
        for (int j = 0; j < n; j++)
        {
            double temp = a[k][j];
            a[k][j] = a[index][j];
            a[index][j] = temp;
        }
        double temp = y[k];
        y[k] = y[index];
        y[index] = temp;
        // Нормализация уравнений
        for (int i = k; i < n; i++)
        {
            double temp = a[i][k];
            if (abs(temp) < eps) continue; // для нулевого коэффициента пропустить
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] / temp;
            y[i] = y[i] / temp;
            if (i == k)  continue; // уравнение не вычитать само из себя
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] - a[k][j];
            y[i] = y[i] - y[k];
        }
        k++;
    }
    // обратная подстановка
    for (k = n - 1; k >= 0; k--)
    {
        x[k] = y[k];
        for (int i = 0; i < k; i++)
            y[i] = y[i] - a[i][k] * x[k];
    }
    return x;
}
double func1(double* x,  int n,int m)
{
    double sum = 0;
    for (int i = 0;i < n;i++)
    {
        sum += pow(x[i], m);
    }
    return sum;
}


double func3(double* x, double* y, int n, int m)
{
    double sum = 0;
    for (int i = 0;i < n;i++)
    {
        sum += y[i] * pow(x[i], m);
    }
    return sum;
}

int main() 
{
    setlocale(LC_ALL, "rus");
    int n = 6;
    int m = 3;
    double* x = new double[n];
    double* y = new double[n];
    for (int i = 0;i < n;i++)
    {
        x[0] = -3;
        y[0] = -2.9502;
        x[1] = -2;
        y[1] = -1.8647;
        x[2] = -1;
        y[2] = -0.63212;
        x[3] = 0;
        y[3] = 1;
        x[4] = 1;
        y[4] = 3.7183;
        x[5] = 2;
        y[5] = 9.3891;
    }
   
    double** arr = new double* [m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = new double[m];
        for (int j = 0; j < m; j++)
        {
            
                arr[i][j] = func1(x,n,i+j);
                arr[0][0] = n ;
                
            
        }
    }

    
    double* f = new double[m];
    for (int i = 0;i < m;i++)
    {
        
            f[i] = func3(x,y,n,i);
        
    }

    
   

    double* a = gauss(arr, f, m);
   
    for (int i = 0;i < m;i++)
    {
        cout << a[i] << " + ";
    }
    cout << endl;
    
    cout << 2.19091 + 2.22533 * (-0.5) << endl;
    
    cout << 0.88421 + 2.84135 * (-0.5) + 0.578682 * (-0.5) * -0.5;
    


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
