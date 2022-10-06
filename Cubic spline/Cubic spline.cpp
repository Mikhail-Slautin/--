// Cubic spline.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<cmath>
using namespace std;


double* gauss(double** a, double* y, int n);
double* gauss(double** a, double* y, int n)
{
    double* x, max;
    int k, index;
    const double eps = 0.000001;  
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
int main()
{
    setlocale(LC_ALL, "rus");
    int n=5;
    double xpoint = 0.8;
    double h = 0.4;
    double x[] = {0.1,0.5,0.9,1.3,1.7};
   
    double f[] = {10,2,1.1111,0.76923,0.58824};
   
    cout << "Введите коэффициенты переменных:" << endl;
    double** arr = new double* [n];
    double* y = new double[n];
    
    for (int i = 0; i < n; i++)
    {
        arr[i] = new double[n];
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j] ;
        }
    }
    cout << "Введите коэффициенты переменных:" << endl;
    for (int i = 0;i < n;i++)
    {
        y[0] = 0;
        y[1] = 6* (f[2] - 2 * f[1] + f[0])/0.4;
        y[2] = 6 * (f[3] - 2 * f[2] + f[1])/0.4;
        y[3] = 6 * (f[4] - 2 * f[3] + f[2])/0.4;
        y[4] = 0;
    }

    double* c = gauss(arr, y, n);
    
    
    double* a = new double[n];
    for (int i = 0;i < (n-1);i++)
    {
        a[i] = f[i];
        cout << "a" << i << "=" << a[i] << " ";

    }
    cout << endl;
    double* b = new double[n];
    for (int i = 0;i < (n-1);i++)
    {
        b[i] = (f[i + 1] - f[i])/0.4 - 0.2 * c[i] - 0.4*((c[i + 1] - c[i]) / 6);
        cout << "b" << i << "=" << b[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < (n-1); i++)
    {
        cout << "c" << i << "=" << c[i]<<" " ;
    }
    cout << endl;
    double* d = new double[n];
    for (int i = 0;i < (n-1);i++)
    {
        d[i] = (c[i + 1] - c[i]) / 2.4;
        cout << "d" << i << "=" << d[i] << " ";
    }
    cout << endl;
    cout << "Значение функций в точке:" << endl;
    double* func = new double[n - 1];
    for (int i = 0;i < (n - 1);i++)
    {
        func[i] = a[i] + b[i] * (xpoint - x[i]) + c[i] * pow(xpoint - x[i], 2) + d[i] * pow(xpoint - x[i], 3);
        cout <<func[i] << endl;;
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
