#include<iostream>
//#include<stack>
#include<string>
using namespace std;

// Function to convert Infix expression to postfix
string InfixToPostfix(string expression);

// Function to verify whether an operator has higher precedence over other
int HasHigherPrecedence(char operator1, char operator2);

// Function to verify whether a character is operator symbol or not.
bool IsOperator(char C);

// Function to verify whether a character is alphanumeric chanaracter (letter or numeric digit) or not.
bool IsOperand(char C);

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


string InfixToPostfix(string expression)
{
    stack<char> S;
    string postfix = "";
    for (unsigned int i = 0; i < expression.length(); i++) {

        if (expression[i] == ' ' || expression[i] == ',') continue;

        else if (IsOperator(expression[i]))
        {
            while (!S.isEmpty() && S.toP() != '(' && HasHigherPrecedence(S.toP(), expression[i]))
            {
                postfix += S.toP();
                S.pop();
            }
            S.push(expression[i]);
        }

        else if (IsOperand(expression[i]))
        {
            postfix += expression[i];
        }

        else if (expression[i] == '(')
        {
            S.push(expression[i]);
        }
        else if (expression[i] == ')')
        {
            while (!S.isEmpty() && S.toP() != '(') {
                postfix += S.toP();
                S.pop();
            }
            S.pop();
        }
    }

    while (!S.isEmpty()) {
        postfix += S.toP();
        S.pop();
    }

    return postfix;
}

bool IsOperand(char C)
{
    if (C >= '0' && C <= '9') return true;
    if (C >= 'a' && C <= 'z') return true;
    if (C >= 'A' && C <= 'Z') return true;
    return false;
}

bool IsOperator(char C)
{
    if (C == '+' || C == '-' || C == '*' || C == '/' || C == '^')
        return true;
    return false;
}

int IsRightAssociative(char op)
{
    if (op == '$') return true;
    return false;
}


int GetOperatorWeight(char op)
{
    int weight = -1;
    switch (op)
    {
        case '+':
        case '-':
            weight = 1;
        case '*':
        case '/':
            weight = 2;
        case '^':
            weight = 3;
    }
    return weight;
}

int HasHigherPrecedence(char op1, char op2)
{
    int op1Weight = GetOperatorWeight(op1);
    int op2Weight = GetOperatorWeight(op2);
    if (op1Weight == op2Weight)
    {
        if (IsRightAssociative(op1)) return false;
        else return true;
    }
    return op1Weight > op2Weight ? true : false;
}


int main() {
    string expression;
    cout << "Enter Infix Expression \n";
    getline(cin, expression);
    string postfix = InfixToPostfix(expression);
    cout << "Output = " << postfix << "\n";
    return 0;
}
