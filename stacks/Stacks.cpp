#include <iostream>
using namespace std;

class Stack
{
    int top;
    int size;
    int *s;

public:
    Stack(int size);
    void push(int x);
    int pop();
    int peek(int index);
    int isFull();
    int isEmpty();
    void display();
    ~Stack();
};

Stack::Stack(int length)
{
    size = length;
    top = -1;
    s = new int[size];
}

Stack::~Stack()
{
    delete[] s;
    cout << "Stack Deleted";
}

void Stack::push(int x)
{
    if (isFull())
    {
        cout << "Stack Full";
    }
    else
    {
        s[++top] = x;
    }
}

int Stack::pop()
{
    int x = s[top--];
    return x;
}

int Stack::peek(int index)
{
    if (top - index + 1 > 0 || top - index + 1 == size)
    {
        cout << "Undefined";
    }
    return s[top - index + 1];
}

int Stack::isFull()
{
    if (top == size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Stack::isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

void Stack::display()
{
    while (top >= 0)
    {
        cout << s[top--] << " ";
    }
}

int main()
{
    int A[] = {1, 3, 5, 7, 9};
    Stack st(5);

    for (int i = 0; i < 5; i++)
    {
        st.push(A[i]);
    }
    st.pop();
    st.display();
}