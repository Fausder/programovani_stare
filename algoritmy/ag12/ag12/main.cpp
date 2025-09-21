#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

int partition(int* arr, int l, int r)
{
	int pivot = arr[r];
	int i = l - 1;
	for (int j = l; j < r; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[r]);
	return i + 1;
}

void quickSort(int* arr, int l, int r)
{
	if (l >= r)
		return;
	int pivotIndex = partition(arr, l, r);
	quickSort(arr, l, pivotIndex - 1);
	quickSort(arr, pivotIndex + 1, r);
}

void soucet(int* arr, int n)
{
	if (n <= 0)
	{
		cout << "Pole je prazdne." << endl;
		return;
	}
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] > 0)
			{
				sum += arr[i];

			}
		}
		cout << "Soucet kladnych cisel v poli je: " << sum << endl;

	}
}

int main()
{
	// Nastavení velikosti pole
	const int n = 300000; // Velikost pole
	int* arr = new int[n];

	// Generování náhodného pole
	srand(static_cast<unsigned>(time(0)));
	for (int i = 0; i < n; i++)
	{
		arr[i] = (rand() % 20001) - 10000; // Náhodná èísla v rozsahu -10000 až 10000
	}


	// Mìøení èasu
	auto start = chrono::high_resolution_clock::now();
	quickSort(arr, 0, n - 1);
	auto end = chrono::high_resolution_clock::now();

	// Výpoèet souètu
	soucet(arr, n);

	// Výpoèet doby trvání
	chrono::duration<double> duration = end - start;

	// Výstup
	cout << "Sorted array (first 10 elements): \n";
	for (int i = 0; i < 10; i++) // Zobrazení prvních 10 prvkù
		cout << arr[i] << " ";
	cout << "\nTime taken to sort: " << duration.count() << " seconds" << endl;

	// Uvolnìní pamìti
	delete[] arr;

	return 0;
}