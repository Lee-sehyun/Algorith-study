#include <iostream>

using namespace std;

int main()
{

    //입력
    int C[8];
    int check = 0;

    for (int i = 0; i < 8; i++)
    {
        cin >> C[i];
    }

    // 시작해보자!
    // 오름차순, 내림차순으로 정렬되어있는지만 확인하면 됨.
    for (int i = 0; i < 7; i++)
    {
        if (C[i] > C[i + 1])
            break;
        if (i == 6)
        {
            cout << "ascending" << endl;
            check = 1;
        }
    }
    if (check == 0)
    {
        for (int i = 0; i < 7; i++)
        {
            if (C[i] < C[i + 1])
            {
                cout << "mixed" << endl;
                break;
            }
            if (i == 6)
            {
                cout << "descending" << endl;
                check = 1;
            }
        }
    }

    return 0;
}