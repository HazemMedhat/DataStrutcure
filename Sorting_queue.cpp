#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define cap 1000  ///default capacity of a queue

template<typename T>
class Queue
{
    T *arr;
    int capacity;
    int Front;
    int End;
    int counter;

public:
    Queue()
    {
        arr = new int [cap];
        capacity = cap;
        Front = 0;
        End = -1;
        counter = 0;
    }
    Queue(int siZe = cap)
    {
        arr = new int[siZe];
        capacity = siZe;
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

    void print()
    {
        for(int i =0; i < counter; i++)
        {
            cout<<"Element [ "<<i+1<<" ] -> "<<arr[i]<<endl;
        }
    }
    int minIndex(Queue<int> &q, int sortedIndex)
    {
        int min_index = -1;
        int min_val = INT_MAX;
        int n = q.queueSize();
        for (int i=0; i<n; i++)
        {
            int curr = q.front();
            q.dequeue();

            if (curr <= min_val && i <= sortedIndex)
            {
                min_index = i;
                min_val = curr;
            }
            q.enqueue(curr);
        }
        return min_index;
    }

    void insertMinToRear(Queue<int> &q, int min_index)
    {
        int min_val;
        int n = q.queueSize();
        for (int i = 0; i < n; i++)
        {
            int curr = q.front();
            q.dequeue();
            if (i != min_index)
                q.enqueue(curr);
            else
                min_val = curr;
        }
        q.enqueue(min_val);
    }

    void sortQueue(Queue<int> &q)
    {
        for (int i = 1; i <= q.queueSize(); i++)
        {
            int min_index = minIndex(q, q.queueSize() - i);
            insertMinToRear(q, min_index);
        }
    }
};


int main()
{
    Queue<int> Newqueue(5);

    Newqueue.enqueue(10);
    Newqueue.enqueue(70);
    Newqueue.enqueue(0);
    Newqueue.enqueue(20);
    Newqueue.enqueue(40);
    Newqueue.sortQueue(Newqueue);
    Newqueue.print();
    return 0;
}
