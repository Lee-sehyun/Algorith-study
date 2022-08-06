/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		
		int N;
		
		cin >> N;
		
		vector<int> num(N);
		vector<int> dp(N);
		
		for(int i = 0 ; i < N ; i++){
		    cin >> num[i];
		}
		
		queue<int> q;
		
		for(int i = 0 ; i < N ; i++){
		    if(dp[i] == 0){
		        q.push(i);
		        dp[i] = 1;
		    }
		    while(!q.empty()){
		        int next = q.front();
		        q.pop();
		        if(next + num[next] >= N){
		            Answer++;
		        }
		        else if(dp[next + num[next]] == 0){
		            dp[next + num[next]] = 1;
		            q.push(next + num[next]);
		        }
		    }
		}
		
		
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}