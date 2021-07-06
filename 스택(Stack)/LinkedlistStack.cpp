#include <iostream>
#include <string>

using namespace std;

template <typename T>
class node
{
private:
    node *pre;
    T data;
    node *next;

public:
    node(T d)
    {
    }
};

template <typename T>
class stack
{
private:
    node<T> *head;

public:
    stack()
    {
        head = new node<T>;
    }
    void push(T data) // push
    {
        node *temp = new node<T>;
    }
    void pop() // pop
    {
        if (size > 0)
        {
            size--;
        }
        else
        {
            fprintf(stderr, "The data is not available.\n");
            exit(1);
        }
    }
    T top() // top
    {
        if (size == 0)
        {
            fprintf(stderr, "The data is not available.\n");
            exit(1);
        }
        return datas[size - 1];
    }
    T bottom() // bottom
    {
        if (size == 0)
        {
            fprintf(stderr, "The data is not available.\n");
            exit(1);
        }
        return datas[0];
    }
    bool empty() // empty
    {
        if (size == 0)
            return 1;
        else
            return 0;
    }
};

int main()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}