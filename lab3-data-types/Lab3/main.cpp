// =======================================================
// Лабораторная работа № 3
// Вариант 13
// h = (sin^3(x) + e^(-sin y)) / (0,6 * x^2 * y^2)
// =======================================================
#include <iostream>
#include <iomanip>
#include <cmath>
#include <clocale>
#include <windows.h>

using namespace std;

// Неявное преобразование double -> int в операторе k = z; сопровождается
// предупреждением компилятора C4244. Оно ожидаемо: преобразование с
// усечением выполняется осознанно, поэтому предупреждение отключено.
#pragma warning(disable : 4244)

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");

    double x, y, z;
    int k, l, m, n;

    cout << "Вариант 13: h = (sin^3(x) + e^(-sin y)) / (0,6 * x^2 * y^2)"
         << endl << endl;

    cout << "Введите x = ";
    cin >> x;
    cout << "Введите y = ";
    cin >> y;

    // Числитель и знаменатель вынесены в отдельные переменные,
    // чтобы подчеркнуть структуру выражения.
    double numerator = pow(sin(x), 3) + exp(-sin(y));
    double denominator = 0.6 * pow(x, 2) * pow(y, 2);
    z = numerator / denominator;

    k = z;          // неявное преобразование double -> int (усечение)
    l = int(z);     // явное преобразование double -> int (усечение)
    m = ceil(z);    // округление в большую сторону
    n = floor(z);   // округление в меньшую сторону

    cout << fixed << setprecision(6);
    cout << endl;
    cout << "Числитель      = " << numerator << endl;
    cout << "Знаменатель    = " << denominator << endl;
    cout << "Вещественное z = " << z << endl;
    cout << "Усечение (неявное) k = " << k << endl;
    cout << "Усечение (явное)   l = " << l << endl;
    cout << "Округление вверх   m = " << m << endl;
    cout << "Округление вниз    n = " << n << endl;

    cout << endl;
    cout << "Значение префиксного инкремента  ++k = " << ++k << endl;
    cout << "Значение постфиксного инкремента l++ = " << l++ << endl;
    cout << "Значение k после приращения = " << k << endl;
    cout << "Значение l после приращения = " << l << endl;
    cout << endl;

    system("PAUSE");
    return 0;
}
