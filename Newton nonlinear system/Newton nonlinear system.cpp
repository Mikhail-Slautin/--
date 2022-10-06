// Newton nonlinear system.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
using namespace std;



double F1(double x1, double x2, double a);
double F2(double x1, double x2, double a);
double DFX1(double x1, double x2, double a, double (*F)(double, double, double));
double DFX2(double x1, double x2, double a, double (*F)(double, double, double));
double* gauss(double** a, double* y, int n);

double F1(double x1, double x2, double a)
{
    return(sin(1.-x1));
}
double F2(double x1, double x2, double a)
{
    return(cos(x2-x1*x1));
}

double DFX1(double x1, double x2, double a, double (*F)(double, double, double))
{
    double h = 1e-4;
    return((F(x1 + h, x2, a) - F(x1, x2, a)) / h);
}

double DFX2(double x1, double x2, double a, double (*F)(double, double, double))
{
    double h = 1e-4;
    return((F(x1 , x2+h, a) - F(x1, x2, a)) / h);
}

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


int main()
{
    double eps = 1e-4;
    int n = 3;
    double x1, x2,a;
    cin >> x1;
    cin >> x2;
    cin >> a;
    double xmax ;
    double** arr = new double*[n];
    for (int i = 0;i < n;i++)
    {
        arr[i] = new double[n];
        for (int j = 0;j < n;j++)
        {
            arr[i][j] = 0;
        }
    }
    double* y = new double[n];
     do
    {
                xmax = -1e6;
                arr[0][0] = DFX1(x1, x2,a, F1);
                arr[0][1] = DFX2(x1, x2, a, F1);
                arr[1][0] = DFX1(x1, x2, a, F2);
                arr[1][1] = DFX2(x1, x2, a, F2);
   
       
            y[0] = -F1(x1,x2,a);
            y[1] = -F2(x1, x2, a);
        
        double* deltax = gauss(arr, y, n);


        if (deltax[0] > xmax)xmax = deltax[0];

        if (deltax[1] > xmax)xmax = deltax[1];

        x1 = x1 + deltax[0];
        x2 = x2 + deltax[1];
        
        
      

    } while ( abs(xmax)>eps );


    cout<<"x1 =  "<<x1<<" x2 = "<<x2;
    

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
