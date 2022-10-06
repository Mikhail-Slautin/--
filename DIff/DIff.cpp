// DIff.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

double diff_l(double* x, double* y, int i)
{
    double h = x[i] - x[i - 1];
    double dy = y[i] - y[i - 1];
    return dy / h;
}
double diff_r(double* x, double* y, int i)
{
    double h = x[i + 1] - x[i];
    double dy = y[i + 1] - y[i];
    return dy / h;
}
double diff_c(double* x, double* y, int i)
{
    double h = x[i + 1] - x[i - 1];
    double dy = y[i + 1] - y[i - 1];
    return dy / h;
}
double diff_2_l(double* x, double* y, int i)
{
    double* diff = new double[3];
    diff[0] = diff_l(x, y, 1);
    double h = x[i] - x[i - 1];
    diff[1] = diff_l(x, y, 2);
    diff[2] = diff_l(x, y, 3);
    double* x_ = new double[3];
    double dy = diff[1] - diff[0];
    return dy / h;
}
double diff_2_r(double* x, double* y, int i)
{
    double* diff = new double[3];
    diff[0] = diff_r(x, y, i - 1);
    diff[1] = diff_r(x, y, i);
    diff[2] = diff_r(x, y, i + 1);
    double h = x[i + 1] - x[i];
    double dy = diff[2] - diff[1];
    return dy / h;
}
double diff_2_c(double* x, double* y, int i)
{
    double* diff = new double[3];
    double h = x[i + 1] - x[i - 1];
    diff[0] = diff_c(x, y, 1);
    diff[1] = diff_c(x, y, 2);
    diff[2] = diff_c(x, y, 3);
    double dy = diff[2] - diff[0];
    return dy / h;
}
int main()
{
    

    int n = 5;
    double* x = new double[n];
    double* y = new double[n];
    x[0] = -0.2;
    x[1] = 0;
    x[2] = 0.2;
    x[3] = 0.4;
    x[4] = 0.6;
    y[0] = -0.40136;
    y[1] = 0;
    y[2] = 0.40136;
    y[3] = 0.81152;
    y[4] = 1.2435;
    cout << diff_l(x, y, 2) << endl;
    cout << diff_r(x, y, 2) << endl;
    cout << diff_c(x, y, 2) << endl;
    cout << diff_2_l(x, y, 2) << endl;
    cout << diff_2_r(x, y, 2) << endl;
    cout << diff_2_c(x, y, 2) << endl;
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
