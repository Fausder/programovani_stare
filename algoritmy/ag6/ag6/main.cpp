#include <iostream>
#include <stack>

using namespace std;

void printTowers(stack<int> A, stack<int> B, stack<int> C, int N)
{
    stack<int> tempA = A;
    stack<int> tempB = B;
    stack<int> tempC = C;
    for (int i = N; i > 0; i--)
    {
        if (tempA.size() >= i)
        {
            cout << tempA.top() << "\t";
            tempA.pop();
        }
        else
        {
            cout << "|\t";
        }
        if (tempB.size() >= i)
        {
            cout << tempB.top() << "\t";
            tempB.pop();
        }
        else
        {
            cout << "|\t";
        }
        if (tempC.size() >= i)
        {
            cout << tempC.top() << "\t" << endl;
            tempC.pop();
        }
        else
        {
            cout << "|\t" << endl;
        }
    }
    cout << endl;
}

bool isMoveValid(const stack<int>& src, const stack<int>& dest)
{
    return (!src.empty() && (dest.empty() || src.top() < dest.top()));
}

void moveDisk(stack<int>& src, stack<int>& dest)
{
    if (isMoveValid(src, dest))
    {
        dest.push(src.top());
        src.pop();
    }
}

void towersOfHanoi(stack<int>& src, stack<int>& aux, stack<int>& dest, int N)
{
    if (N == 1)
    {
        moveDisk(src, dest);
        //printTowers(src, aux, dest, 4);
        return;
    }

    towersOfHanoi(src, dest, aux, N - 1);
    moveDisk(src, dest);
    //printTowers(src, aux, dest, 4);
    towersOfHanoi(aux, src, dest, N - 1);
}

int main()
{
    int N = 25;
    stack<int> A;
    stack<int> B;
    stack<int> C;

    for (int i = N; i > 0; i--)
    {
        A.push(i);
    }
    printTowers(A, B, C, N);
    time_t startTime = time(nullptr);
    towersOfHanoi(A, B, C, N);
	time_t endTime = time(nullptr);
	cout << "Time taken: " << endTime - startTime << " seconds" << endl;
    printTowers(A, B, C, N);

    return 0;
}

