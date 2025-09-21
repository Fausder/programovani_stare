#include <iostream>
using namespace std;


int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1;
}

void printUniqueElements(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        bool isUnique = true;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j]) 
            {
                isUnique = false;
                break;
            }
        }
        if (isUnique) 
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}


int main() {


    int arr[] = { 10, 20, 30, 40, 50, 20, 30 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unikátní prvky: ";
    printUniqueElements(arr, size);

    return 0;
}
