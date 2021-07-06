#include <iostream>

using namespace std;

template <typename T>
class queue
{
private:
    T datas[10000];
    int front, end;

public:
    queue()
    {
        front = 0;
        end = 0;
    }
    void Enqueue(T data)
    {
        if (end > 10000)
        {
            fprintf(stderr, "Data size out of size.\n");
            exit(1); // exit(1)이 맞는지 모르겠다.
        }
        datas[end] = data;
        end++;
    }
    T Dequeue()
    {
        if (front > 10000)
        {
            fprintf(stderr, "Data size out of size.\n");
            exit(1); // exit(1)이 맞는지 모르겠다.
        }
        T result = datas[front];
        front++;
        return result;
    }
    T Front()
    {
        if (front > 10000 || front == end)
        {
            fprintf(stderr, "front is over the size.\n");
            exit(1); // exit(1)이 맞는지 모르겠다.
        }
        return datas[front];
    }
    T rear()
    {
        if (end < 1 || front == end)
        {
            fprintf(stderr, "end is over the size.\n");
            exit(1); // exit(1)이 맞는지 모르겠다.
        }
        return datas[end - 1];
    }
    bool isEmpty() // empty
    {
        if (front == end)
            return 1;
        else
            return 0;
    }
};

int main()
{
    queue<int> q;

    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);

    while (!q.isEmpty())
    {
        cout << q.Dequeue() << " ";
    }
    cout << endl;

    return 0;
}