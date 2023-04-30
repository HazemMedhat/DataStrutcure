#include<iostream>
//#include<stack>
#include<string>
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
    int toP() {
        if (!isEmpty()){
            return item[top] ;


        }

    }
    void pop()
    {
        if (isEmpty())
            cout << "stack is empty";
        else
            //  Top();
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

 int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int ans=0;
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i]=='('){
                st.push(i);
            }else{
                st.pop();
                if(st.isEmpty()){
                    st.push(i);
                }
                int sz=i-st.toP();
                ans=max(ans,sz);
            }
        }
        return ans;
 }

int main()
{

	string expression;
	cout << "Enter an expression:";
	cin >> expression;
		cout<<longestValidParentheses(expression);


	return 0;}
