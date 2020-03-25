#pragma once
#include <string>
namespace ut7_2
{
	void showMatrix(double matrix[5], int count);
	void showMatrix(double matrix[][5], int count);

	int sign(double a);
	double sum(int a, double arr1[][5], double arr2[][5]);
	double sum(int a, int b, double arr1[][5], double arr2[][5]);
	double sum(int a, double arr1[][5], double arr2[],double arr3[][5]);
	double sum(int a, double arr1[][5], double arr2[],int n);
	void start();
}