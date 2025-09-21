#include <iostream>
#include <climits>

using namespace std;

struct Queue
{
    int capacity;
    int* data;
    int rear = -1;
    int front = 0;
    int size = 0;

    Queue(int capacity)
    {
        this->capacity = capacity;
        this->data = new int[this->capacity];
    }
    ~Queue()
    {
        delete[] this->data;
    }

    void enqueue(int value)
    {
        if (this->size < this->capacity)
        {
            this->rear = (this->rear + 1) % this->capacity;
            this->data[this->rear] = value;
            this->size++;
        }
        else
        {
            cout << "Queue is full" << endl;
        }
    }
    int dequeue()
    {
        if (this->size > 0)
        {
            int value = this->data[this->front];
            this->front = (this->front + 1) % this->capacity;
            this->size--;
            return value;
        }
        else
        {
            cout << "Queue is empty" << endl;
            return INT_MAX;
        }
    }
};

int main()
{
    Queue queue(4);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;
    return 0;
}
