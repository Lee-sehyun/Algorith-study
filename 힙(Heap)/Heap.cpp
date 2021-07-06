#include <iostream>

using namespace std;

template <typename T>
class Heap
{
private:
    T datas[10001];
    int size;

    /*
    밑에서부터 위로 heapify를 진행
    */
    void upHeapfy(int home)
    {
        for (int i = home / 2; i > 0; i /= 2)
        {
            heapify(i);
        }
    }
    /*
    자신의 자식에 자신보다 더 큰 값이 존재하면 자신과 바꿔줌.
    따라서 가장 큰 값이 자신이 됨.
    */
    void heapify(int home)
    {
        int left = home * 2;
        int right = home * 2 + 1;
        int minidx = home;
        if (left <= size && datas[minidx] < datas[left])
        {
            minidx = left;
        }
        if (right <= size && datas[minidx] < datas[right])
        {
            minidx = right;
        }
        if (minidx != home)
        {
            swap(home, minidx);
            heapify(minidx);
        }
    }

    void swap(int i, int j)
    {
        T temp = datas[i];
        datas[i] = datas[j];
        datas[j] = temp;
    }

public:
    Heap()
    {
        size = 0;
    }
    /*
    push
    datas의 마지막에 data를 넣어주고 heap을 정렬해줌.
    */
    void push(T data) // push
    {
        if (size > 10000)
        {
            fprintf(stderr, "Data size out of size.\n");
            exit(1); // exit(1)이 맞는지 모르겠다.
        }
        datas[size + 1] = data;
        size++;
        upHeapfy(size);
    }
    /*
    가장 첫 값(가장 큰 값)을 리턴
    */
    T pop() // pop
    {
        if (size > 0)
        {
            T result = datas[1];
            swap(1, size);
            size--;
            heapify(1);
            return result;
        }
        else
        {
            fprintf(stderr, "The data is not available.\n");
            exit(1);
        }
    }
    /*
    비었는지 확인.
    비었으면 true 리턴, 비지 않았으면 false 리턴
    */
    bool empty() // empty
    {
        if (size == 0)
            return true;
        else
            return false;
    }
};

int main()
{
    Heap<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while (!s.empty())
    {
        cout << s.pop() << " ";
    }
    cout << endl;

    return 0;
}