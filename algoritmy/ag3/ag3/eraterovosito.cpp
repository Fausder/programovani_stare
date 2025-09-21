#include <iostream>
#include <climits>

using namespace std;

void eratosthenesSieve(int n)
{
    // Vytvoøení dynamického pole boolù a inicializace na true
    bool* isPrime = new bool[n + 1];
    for (int i = 0; i <= n; i++)
        isPrime[i] = true;

    isPrime[0] = isPrime[1] = false; // 0 a 1 nejsou prvoèísla

    // Hlavní smyèka Eratosthenova síta
    for (int p = 2; p * p <= n; p++)
    {
        // Pokud je isPrime[p] stále true, pak je p prvoèíslo
        if (isPrime[p])
        {
            // Aktualizace všech násobkù p jako ne-prvoèísla
            for (int i = p * p; i <= n; i += p)
                isPrime[i] = false;
        }
    }

    // Výpis všech prvoèísel menších nebo rovných n
    for (int p = 2; p <= n; p++)
    {
        if (isPrime[p])
            cout << p << " ";
    }
    cout << endl;

    // Uvolnìní dynamicky alokované pamìti
    delete[] isPrime;
}

int main()
{
    int n;
    cout << "Zadejte horní hranici pro prvoèísla: ";
    cin >> n;
    eratosthenesSieve(n);
    return 0;
}

