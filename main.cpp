#include<iostream>
using namespace std;
const int MAX_SIZE = 5;
template<class t>
class stack {
	int top;
	t item[MAX_SIZE];
public:
	stack() {
        top =- 1;
    }

	bool isEmpty()
	{
		return top < 0;
	}

	void push(t Element)
	{
		if (top >= MAX_SIZE-1)
		{
			cout << "Stack is full";
		}
		else
		{
			top++;
			item[top] = Element;
		}
	}

	void Top() {
        if (isEmpty())
            cout << "stack is empty";
        else {
            cout << "the top element is : " << item[top] << endl ;
        }
    }

    void pop()
    {
        if (isEmpty())
            cout << "stack is empty";
        else
            Top();
            top--;
    }

    int Size (){

        cout << "Stack size is : " << endl;
        return top+1;

    }

    void clear (){
        top = -1 ;
    }

	void print() {
		for (int i = top; i >= 0; i--)
		{
			cout << item[i] << " ";
		}
		cout << endl;
	}

};
int main() {
	stack<int>s;
	s.push(5);
	s.push(15);
	s.push(20);
    s.push(30);
    s.print();
    /*s.clear();
    s.print();*/
    cout << s.Size();
    /*s.Top();
    s.pop();
	s.print();*/
}