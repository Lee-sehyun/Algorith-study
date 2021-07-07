#include <bits/stdc++.h>

using namespace std;

int main()
{

    //입력
    int C, N;

    cin >> C;

    cout << fixed;
    cout.precision(3);

    // 시작해보자!
    for (int c = 0; c < C; c++)
    {
        cin >> N;
        float sum = 0, avg;
        vector<int> score(N);
        for (int i = 0; i < N; i++)
        {
            cin >> score[i];
            sum += score[i];
        }
        avg = sum / N;
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            if (score[i] > avg)
                cnt++;
        }
        cout << (float)cnt / N * 100 << "%" << endl;
    }

    return 0;
}