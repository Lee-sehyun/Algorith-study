#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

void BFS(int i, int j, vector<vector<int> > &origin, vector<vector<int> > &change, vector<vector<int> > &dp){
    dp[i][j] = 1;
    if(i > 0 && dp[i-1][j] == 0 && origin[i-1][j] == origin[i][j] && change[i-1][j] == change[i][j]){
        BFS(i-1, j, origin, change, dp);
    }
    if(j > 0 && dp[i][j-1] == 0 && origin[i][j-1] == origin[i][j] && change[i][j-1] == change[i][j]){
        BFS(i, j-1, origin, change, dp);
    }
    if(i < N-1 && dp[i+1][j] == 0 && origin[i+1][j] == origin[i][j] && change[i+1][j] == change[i][j]){
        BFS(i+1, j, origin, change, dp);
    }
    if(j < M-1 && dp[i][j+1] == 0 && origin[i][j+1] == origin[i][j] && change[i][j+1] == change[i][j]){
        BFS(i, j+1, origin, change, dp);
    }
}

int main()
{
    int answer = 0;
    cin >> N >> M;

	vector<vector<int> > origin(N, vector<int>(M));
    vector<vector<int> > change(N, vector<int>(M));
    vector<vector<int> > dp(N, vector<int>(M, 0));

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> origin[i][j];
        }
    }
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> change[i][j];
        }
    }

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(dp[i][j] == 0){
                if(origin[i][j] == change[i][j]){
                    dp[i][j] = 1;
                }
                else {
                    answer++;
                    if(answer > 1 || (i > 0 && origin[i-1][j] == origin[i][j]) || (j > 0 && origin[i][j-1] == origin[i][j])){
                        cout << "NO\n";
                        goto out;
                    }
                    else {
                        BFS(i, j, origin, change, dp);
                    }
                }
            }
        }
    }

    cout << "YES\n";

    out:

	return 0;//Your program should return 0 on normal termination.
}