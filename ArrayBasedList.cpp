#include <iostream>

using namespace std;
//int length = 10;
class arrayListType
{
    int *arr;
    int maxSize;
    int length=0;
    int loc ;
public:
    arrayListType(int size){
        if(size <= 0)
        {
            cout << " Wrong Size " << endl;
            maxSize = 10;
        }
        else
            maxSize = size;

         loc = 0;
        arr = new int [maxSize];
    }


    bool isEmpty();
    bool isFull();
    int listSize();
    int maxListSize();
    void print();
    bool isItemAtEqual(int index, int item);
    void insert(int item);
    void insertAt(int index, int item);
    void removeAt(int index);
    void retrieveAt(int index);
    void replaceAt(int index, int item);
    void clearList();
};



bool arrayListType::isEmpty()
{
    return (length == 0);
}

bool arrayListType::isFull()
{
    return (length == maxSize);
}

int arrayListType::listSize()
{
    return length;
}

int arrayListType::maxListSize()
{
    return maxSize;
}

void arrayListType::print()
{
    for(int i = 0; i < length; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

bool arrayListType::isItemAtEqual(int index, int item)
{
    if(index < 0 || index >= length)
        return false;
    else
        return (arr[index] == item);
}

void arrayListType::insert(int item)
{
    if(isFull())
        cout<<" The List is Full " << endl;
    else
        for (int i =length ; i > loc ;i-- ) {
            arr[i] = arr[i - 1];
        }
    arr[loc] = item;
    length++;
}

void arrayListType::insertAt(int index, int item)
{
    if(isFull())
        cout<<" The List is Full " << endl;
    else if(index < 0 || index > length)
        cout << "Out of Range " << endl;
    else
    {
        for(int i = length; i > index ; i--)
            arr[i] = arr[i - 1];

        arr[index] = item;
        length++;
    }
  //  cout<<length<<endl;
}

void arrayListType::retrieveAt(int index)
{
    if(index < 0 || index >= length)
        cout << "Out of Range " << endl;
    else
        cout << arr[index];
}

void arrayListType::replaceAt(int index, int item)
{
    if(index < 0 || index >= length)
        cout << "Out of Range " << endl;
    else
        arr[index] = item;
}

void arrayListType::clearList()
{
    length = 0;
}

void arrayListType::removeAt(int index)
{
    if(index < 0 || index >= length)
        cout<<"The location of the item to be removed is out of range."<<endl;
    else
    {
        for(int i = index; i < length - 1; i++)
            arr[i] = arr[i+1];

        length--;
    }
}

int main()
{
    arrayListType lst = arrayListType(100);

    lst.insertAt(0,5);
    lst.insertAt(1,6);
    /*lst.insert(5);
    lst.insert(6);*/
    lst.print();
    cout << lst.listSize();


    return 0;
}
