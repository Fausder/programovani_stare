#include <iostream>
#include <climits>

using namespace std;

struct Stack
{
    int capacity = 3;
    int* data;
    int index = -1;

    Stack(int capacity)
    {
        this->capacity = capacity;
        this->data = new int[this->capacity];
    }
    ~Stack()
    {
        delete[] this->data;
    }

    void push(int value)
    {
        if (this->index < this->capacity)
        {
            this->index++;
            this->data[this->index] = value;
        }
        else
        {
            cout << "Nah " << endl;
        }
    }
    int pop()
    {
        if (this->index >= 0)
        {
            return (this->data[this->index--]);
        }
        else
        {
            cout << "nah" << endl;
            return INT_MAX;
        }
    }
};
bool checkParity(string str)
{
    Stack stack(str.length());

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ')')
            stack.push(str[i]);

        if (str[i] == ')')
           if (stack.pop() == INT_MAX);
               return false;
    }

    return stack.index == -1;
}


int main()
{
    string str = "((.) (.))";
    cout << checkParity(str) << endl;

    Stack stack(4);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
	return 0;
}