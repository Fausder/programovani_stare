#include <iostream>
#include <vector>
#include <climits>
using namespace std;

enum
{
	LEFT = 1,
	RIGHT = -1
};
class ArrowedInt
{
public:
	int value;
	int direction = LEFT;
	ArrowedInt(int value) { this->value = value; }
};

void printInts(vector<ArrowedInt*>aInts)
{;
	for (auto aInt : aInts)
	{
		cout << aInt->value << "\t";
	}
	cout << endl;
}

void swapArrowedInts(ArrowedInt*& first, ArrowedInt*& second)
{
	ArrowedInt* temp = first;
	first = second;
	second = temp;
}

void changeDirections(vector<ArrowedInt*>& aInts, ArrowedInt* mobileInt)
{
	for (auto aInt : aInts)
	{
		if (aInt->value > mobileInt->value)
		{
			aInt->direction *= -1;
		}
	}
}

bool isMobile(vector<ArrowedInt*> aInts, int index)
{
	if (index == 0 && aInts[index]->direction == LEFT)
	{
		return false;
	}
	if (index == aInts.size() - 1 && aInts[index]->direction == RIGHT)
	{
		return false;
	}
	int direction = aInts[index]->direction;
	if (aInts[index]->value > aInts[index + direction]->value)
	{
		return true;
	}
	return false;
}

int getLargestMobileIndex(vector<ArrowedInt*>& aInts)
{
	int maxValue = INT_MIN;
	int maxIndex = -1;
	for (int i = 0;i < aInts.size(); i++)
	{
		if (isMobile(aInts, i) && aInts[i]->value > maxValue)
		{
			maxValue = aInts[i]->value;
			maxIndex = i;
		}
	}
	return maxIndex;
}

bool bninarySearch(int* arr, int N, int value)
{
	int left = 0;
	int right = N - 1;
	int M = (left + right) / 2;
	while (left <= right)
	{
		M = (left + right) / 2;
		if (arr[M] == value)
		{
			return true;
		}
		else if (arr[M] < value)
		{
			left = M + 1;
		}
		else
		{
			right = M - 1;
		}
	}
	return false;
}

bool binaryRecursiveSearch(int* arr, int left, int right, int value)
{
	if (left > right)
	{
		return false;
	}
	int M = (left + right) / 2;
	if (arr[M] == value)
	{
		return true;
	}
	else if (arr[M] < value)
	{
		return binaryRecursiveSearch(arr, M + 1, right, value);
	}
	else
	{
		return binaryRecursiveSearch(arr, left, M - 1, value);
	}
}

void johnsonTrotter(int N)
{
	vector<ArrowedInt*> aInts;
	for (int i = 0; i < N; i++)
	{
		aInts.push_back(new ArrowedInt(i));
	}
	printInts(aInts);
	int index = getLargestMobileIndex(aInts);

	while (index>=0)
	{
		int direction = aInts[index]->direction;
		swapArrowedInts(aInts[index],aInts[index + direction]);
		printInts(aInts);
		changeDirections(aInts, aInts[index + direction]);
		index = getLargestMobileIndex(aInts);
	}
}

void printArray(int* arr, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void kusKodu(int* arr, int N, int l, int r)
{
	if (l == r)
	{
		printArray(arr, N);
		return;
	}
	for (int i = l; i <= r; i++)
	{
		swap(arr[l], arr[i]);
		kusKodu(arr, N, l + 1, r);
		swap(arr[l], arr[i]);
	}
}

int main()
{
	//int N = 4;
	//johnsonTrotter(N);

	int arr[] = { 1, 2, 3, 4, 5 };
	int M = sizeof(arr) / sizeof(arr[0]);
	kusKodu(arr, M, 0, M - 1);
	/*int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = i+1;
	}
	int value = 5;
	cout << "Value: " << value << (bninarySearch(arr,N,value)?"":" Not") << " found!"<< endl;

	cout << "Value: " << value << (binaryRecursiveSearch(arr, 0, N - 1, value) ? "" : " Not") << " found!" << endl;
	*/
	return 0;
}