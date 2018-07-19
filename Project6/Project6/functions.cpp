#include <iostream>
#include <fstream>
#include <algorithm>
#include "Header.h"
#include <ctime>
using namespace std;
void Merge(int* A, int nA, int* B, int nB, int * C)
{
	int a = 0;
	int b = 0;
	while (a + b < nA + nB)
	{
		if ((b >= nB) || ((a<nA) && (A[a] <= B[b])))
		{
			C[a + b] = A[a];
			a++;
		}
		else
		{
			C[a + b] = B[b];
			b++;
		}
	}
}

void MergeSortRecursive(int * A, int n)
{
	if (n < 2) return;
	if (n == 2)
	{
		if (A[0] > A[1]) { int t = A[0]; A[0] = A[1]; A[1] = t; }
		return;
	}
	MergeSortRecursive(A, n / 2);
	MergeSortRecursive(A + n / 2, n - n / 2);
	int* B(new int[n]);
	Merge(A, n / 2, A + n / 2, n - n / 2, B);
	for (int i(0); i<n; ++i) A[i] = B[i];
	delete[n] B;
}

void MergeSortIterative(int *&A, int n)
{
	int *B(new int[n]);
	for (int size(1); size<n; size *= 2)
	{
		int start = 0;
		for (start; (start + size)<n; start += size * 2)
		{
			Merge(A + start, size, A + start + size, min(size, n - start - size), B + start);
		}
		for (start; start<n; ++start) B[start] = A[start];

		int *temp = B;
		B = A; A = temp;
	}
	delete[n] B;
}

void MergeSortNatural(int *&A, int n)
{
	int *B = new int[n];
	while (true)
	{
		int start1;
		int end1;
		int start2 = -1;
		int	end2 = -1;
		while (true)
		{
			start1 = end2 + 1; end1 = start1;
			while ((end1<n - 1) && (A[end1] <= A[end1 + 1]))
				end1++;
			if (end1 == n - 1)
				break;
			start2 = end1 + 1;
			end2 = start2;
			while ((end2<n - 1) && (A[end2] <= A[end2 + 1]))
				end2++;
			Merge(A + start1, end1 - start1 + 1, A + start2, end2 - start2 + 1, B + start1);

			if (end2 == n - 1)
				break;
		}
		if ((start1 == 0) && (end1 == n - 1))
			break;
		if (end1 == n - 1)
		{
			for (start1; start1<n; start1++)
				B[start1] = A[start1];
		}

		int *temp(B); B = A; A = temp;
	}
	delete[n] B;
}

double test(void(*sort)(int*, int const), int* A, int const n)
{
	double ans = 0;
	double start = clock();
	sort(A, n);
	double end = clock();
	ans = (start - end) / (double)CLOCKS_PER_SEC;
	return ans;
}

double test(void(*sort)(int*&, int const), int*& A, int const n)
{
	double ans = 0;
	double start = clock();
	sort(A, n);
	double end = clock();
	ans = (start - end) / (double)CLOCKS_PER_SEC;
	return ans;
}