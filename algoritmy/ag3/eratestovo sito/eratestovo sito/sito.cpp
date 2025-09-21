#include <iostream>
#include <climits>

using namespace std;

void eratosthenes(int n)
{
    bool* isPrime = new bool[n + 1];
    for (int i = 0; i <= n; i++)
        isPrime[i] = true;

    isPrime[0] = false;
    isPrime[1] = false; 
    for (int p = 2; p * p <= n; p++)
    {

        if (isPrime[p])
        {
            for (int i = p * p; i <= n; i += p)
                isPrime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++)
    {
        if (isPrime[p])
            cout << p << " ";
    }
    cout << endl;

    delete[] isPrime;
}

int main()
{
    int n;
    cout << "Zadejte horni hranici pro prvocisla: ";
    cin >> n;
    eratosthenes(n);
    return 0;
}

