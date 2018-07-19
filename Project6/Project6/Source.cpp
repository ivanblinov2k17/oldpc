#include <iostream>
#include <fstream>
#include <algorithm>
#include "Header.h"
#include <ctime>
using namespace std;

int main(int argc, char* argv[])
{
	/*if (argc == 2)
	{
	char* a = argv[0];
	char* b = argv[1];


	ifstream fin(a);
	ofstream fout(b);




	}
	else
	cout << "������ �������� ������!" << endl;*/
	int size = 10000000;
	int* arr = new int[size];
	int* arr1 = new int[size];
	int* arr2 = new int[size];
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		arr[i] = ((double)rand() / RAND_MAX)*size;
	for (int i = 0; i < size; i++)
	{
		arr1[i] = arr[i];
		arr2[i] = arr[i];
	}

	double ans = 0;
	double start = clock();
	MergeSortIterative(arr, size);
	double end = clock();
	delete[] arr;
	ans = (end - start) / (double)CLOCKS_PER_SEC;
	cout << "iterative: " << ans << endl;
	double ans1 = 0;
	double start1 = clock();
	MergeSortRecursive(arr1, size);
	double end1 = clock();
	delete[] arr1;
	ans1 = (end1 - start1) / (double)CLOCKS_PER_SEC;
	cout << "recursive: " << ans1 << endl;
	double ans2 = 0;
	double start2 = clock();
	MergeSortNatural(arr2, size);
	double end2 = clock();
	delete[] arr2;

	ans2 = (end2 - start2) / (double)CLOCKS_PER_SEC;
	cout << "naturalno: " << ans2 << endl;
	system("pause");
	return 0;
}