#pragma once
#include <algorithm>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
//������� �������� A � B � ������ C
void Merge(int const *const A, int const nA, int const *const B, int const nB, int *const C);
//���������� ����������� ���������� ��������
void MergeSortRecursive(int * A, int  n);
//���������� ����������� ���������� ��������
void MergeSortIterative(int *&A, int  n);
//���������� ������������ ���������� ��������
void MergeSortNatural(int *&A, int  n);
//������ ��� ������� �� �������
double test(void(*sort)(int*&, int const), int*& A, int const n);

