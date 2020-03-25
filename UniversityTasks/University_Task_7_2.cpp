#include "University_Task_7_2.h"
#include <iostream>
#include <iomanip>

void ut7_2::showMatrix(double matrix[5], int count)
{
	for (int i = 0; i < count; i++) {
		std::cout <<std::setw(15)<< matrix[i] << '\t';
	}
	std::cout << std::endl;
}
void ut7_2::showMatrix(double matrix[][5], int count)
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			std::cout<< std::setw(15) << matrix[i][j] << '\t';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
int ut7_2::sign(double a)
{
	if (a > 0)
		return 1;
	else
		return -1;
}

double ut7_2::sum(int a, double arr1[][5], double arr2[][5])
{
	int i;
	double sum = 0;
	for (i = 0; i <= a - 2; i++) {
		sum += arr1[i][i] * (double)pow(arr2[i][a], 2);
	}
	return sum;
}

double ut7_2::sum(int a, int b, double arr1[][5], double arr2[][5])
{
	double sum = 0;
	for (int i = 0; i <= a - 2; i++) {
		sum += (double)arr1[i][i] * (double)arr2[i][a] * (double)arr2[i][b];
	}
	return sum;
}

double ut7_2::sum(int a, double arr1[][5], double arr2[], double arr3[][5])
{
	double sum = 0;
	for (int k = 0; k <= a - 2; k++) {
		sum += (double)arr1[k][k] * (double)arr2[k] * (double)arr3[k][a];
	}
	return sum;

}

double ut7_2::sum(int a, double arr1[][5], double arr2[],int n)
{
	double sum = 0;
	for (int k = a + 1; k <= n - 1; k++)
		sum += (double)arr1[a][k] * (double)arr2[k];
	return sum;

}
const int n = 5;
const double q = -3.23;
const int d = -2;
void ut7_2::start()
{
	
	double a[5][5] = { { q, 1, 0, 0, 0 }, { 1, -2, 1, 0, 0 }, { 0, 1, -2, 1, 0 }, { 0, 0, 1, -2, 1 }, { 0, 0, 0, 1, q } };
	double b[5] = { 0, d, d, d, 0 };
	double s[5][5] = { { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } };
	double s_t[5][5];
	double d[5][5] = { { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } };
	double x[5];
	double y[5];
	int i, j, k;
	d[0][0] = sign(a[0][0]);
	s[0][0] = sqrt(fabs(a[0][0]));
	for (k = 0; k < n; k++)
	{
		if (k != 0)
		{
			d[k][k] = sign(a[k][k] - sum(k, d, s));
			s[k][k] = sqrt(fabs(a[k][k] - sum(k, d, s)));
			std::cout << "s [" << k << "][" << k << "] " << s[k][k] << std::endl;
		}
		for ( j = k + 1; j < n; j++)
		{
			s[k][j] = (double)(a[k][j] - sum(k, j, d, s)) / (double)(s[k][k] * d[k][k]);
			std::cout << "s [" << k << "][" << j << "] " << s[k][j] << std::endl;
		}
	}
	std::cout << std::endl;
	showMatrix(s, n);
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < n; j++)
		{
			s_t[i][j] = s[j][i];
		}
	}
	std::cout << std::endl << std::endl;
	showMatrix(s_t, n);
	y[0] = b[0] / (s[0][0] * d[0][0]);
	for (i = 0; i < n; i++)
		y[i] = (b[i] - sum(i, d, y, s)) / (s[i][i] * d[i][i]);
	showMatrix(y, 5);
	x[n-1] = (y[n] / s[n][n]);
	std::cout << std::endl << std::endl;
	for ( i = n; i >= 0; i--)
		x[i] = (double)((y[i] - sum(i, s, x,n)) / s_t[i][i]);
	showMatrix(x, 5);
}

