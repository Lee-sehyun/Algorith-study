#include <iostream>
#include <string>
#include <vector>

using namespace std;

string Answer;

int main(int argc, char** argv)
{
    setbuf(stdout, NULL);
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = "";
		int n, t;
		string B;
		
		cin >> n >> t;
		cin >> B;
		
		vector<int> dp(n);
		
		for(int i = 0 ; i < n ; i++){
		    Answer.push_back('0');
		}
	    
	    for(int i = 0 ; i < n ; i++){
	        if(B[i] == '1' && dp[i] == 0){
	            dp[i] = 1;
	            if(i+2*t >= n || B[i+2*t] == '1'){
	                if(i+t < n){
	                    Answer[i+t] = '1';
	                }
	                else {
	                    Answer[i-t] = '1';
	                }
	                if(i+2*t < n){
	                   dp[i+2*t] = 1; 
	                }
	            }
	            else{
	                Answer[i-t] = '1';
	            }
	        }
	    }
	    
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}