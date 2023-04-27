#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000  ///default capacity of a queue

template<typename T>
class Queue
{
    T *arr;
    int capacity;
    int Front;
    int End;
    int counter;

public:
    Queue(){
        arr = new int [SIZE];
        capacity = SIZE;
        Front = 0;
        End = -1;
        counter = 0;
    }
    Queue(int size = SIZE)
    {
        arr = new int[size];
        capacity = size;
        Front = 0;
        End = -1;
        counter = 0;
    }

    ~Queue()
    {
        delete[] arr;
    }

    void enqueue(T item)
    {
        if (isFull())
        {
            cout << "Overflow\nthe queue is full\n";
            exit(EXIT_FAILURE);
        }

        cout << "Inserting " << item << endl;

        End = (End + 1) % capacity;
        arr[End] = item;
        counter++;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Error!!The queue is empty\n";
            exit(EXIT_FAILURE);
        }

        int x = arr[Front];
        cout << "Removing " << x << endl;

        Front = (Front + 1) % capacity;
        counter--;

        return x;
    }

    int front()
    {
        if (isEmpty())
        {
            cout << "Error!!The queue is empty\n";
            exit(EXIT_FAILURE);
        }
        return arr[Front];
    }

    int queueSize()
    {
        return counter;
    }

    bool isEmpty()
    {
        return (queueSize() == 0);
    }

    bool isFull()
    {
        return (queueSize() == capacity);
    }

    void print(){
        for(int i =0;i < counter;i++){
            cout<<"Element [ "<<i+1<<" ] -> "<<arr[i]<<endl;
        }
    }
};


int main()
{
    Queue<int> q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.print();

    cout << "The Front element is " << q.front() << endl;
    q.dequeue();

    q.enqueue(4);

    cout << "The queue size is " << q.queueSize() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();

    if (q.isEmpty())
    {
        cout << "The queue is empty\n";
    }
    else
    {
        cout << "The queue is not empty\n";
    }
    return 0;
}
