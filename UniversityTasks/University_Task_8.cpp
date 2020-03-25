#include "University_Task_8.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
void zadanie8_1(const double PI)
{
	int switcher = 0;
	double Y = 0.0;
	long double S = 0.0;
	double a = 0.1;
	double b = 1.0;
	double h = 0.1;
	double n = 0;
	double k;
	cout << "Input k:";
	cin >> k;
	do {
		cout << "0. Exit" << endl;
		cout << "1. Y(X)" << endl;
		cout << "2. S(X)" << endl;
		cout << "3. |Y(X)-S(X)|" << endl;
		cout << "Make a choice:";
		cin >> switcher;
		switch (switcher)
		{
		case 1:
			for (double x = a; x < b; x += h)
			{
				Y = exp(x * cos(PI / 4)) * cos(x * sin(PI / 4));
				cout << std::ends << fixed << setprecision(8) << "Y(X)=" << Y << endl;
			}
			break;

		case 2:
			for (double x = a; x < b; x += h)
			{
				S = ((cos(k * PI / 4)) / (floor(Factorial(k)))) * pow(x, k);
				cout << std::ends << fixed << setprecision(8) << "S(X)=" << S << endl;
			}
			break;

		case 3:
			for (double x = a; x < b; x += h)
			{
				S = ((cos(k * PI / 4)) / (floor(Factorial(k)))) * pow(x, k);
				Y = exp(x * cos(PI / 4)) * cos(x * sin(PI / 4));
				cout <<std::ends<< fixed << setprecision(8) << "|Y(X)-S(X)| " << abs(Y - x) << endl;
			}
			break;
		case 0:
			break;
		default:
			cout << "Please correct input" << endl;
		}
	} while (switcher != 0);

}
double Factorial(double K)
{
	if (K < 0) // если пользователь ввел отрицательное число
		return 0; // возвращаем ноль
	if (K == 0) // если пользователь ввел ноль,
		return 1; // возвращаем факториал от нуля - не удивляетесь, но это 1 =)
	else // Во всех остальных случаях
		return K * Factorial(K - 1); // делаем рекурсию.
}