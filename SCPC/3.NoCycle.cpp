#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string Answer;

class graph
{
private:
    vector<vector<int>> Graph;
    int size_n;

public:
    graph(int n = 0)
    {
        size_n = n + 1;
        Graph.resize(n + 1, vector<int>(0));
    }
    void add(int u, int v)
    {
        Graph[u].push_back(v);
    }
    int find(int u, int v)
    {
        for(vector<int>::iterator iter = Graph[u].begin(); iter != Graph[u].end(); iter++){
            if((*iter) == v){
                return 1;
            }
        }
        return 0;
    }
    int cycle(int u, int v)
    {
        vector<int> dp(Graph.size());
        stack<int> s;
        int temp;
        
        s.push(v);
        
        while(!s.empty()){
            temp = s.top();
            s.pop();
            
            if(dp[temp] == 0){
                dp[temp] = 1;
                for(vector<int>::iterator iter = Graph[temp].begin(); iter != Graph[temp].end(); iter++){
                    if((*iter) == u){
                        return 1;
                    }
                    s.push((*iter));
                }
            }
        }
        return 0;
    }
};

int main(int argc, char** argv)
{
	int T, test_case;
	

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = "";
		int N, M, K, a, b;
		
		cin >> N >> M >> K;
		
		graph g(N);
		
		for(int i = 0 ; i < M ; i++){
		    cin >> a >> b;
		    g.add(a, b);
		}
		
		for(int i = 0 ; i < K ; i++){
		    cin >> a >> b;
		    if(g.find(a, b) == 1){
		        Answer.push_back('0');
		    }
		    else if(g.find(b, a) == 1){
		        Answer.push_back('1');
		    }
		    else{
		        if(g.cycle(a, b) == 0){
		            Answer.push_back('0');
		            g.add(a, b);
		        }
		        else {
		            Answer.push_back('1');
		            g.add(b, a);
		        }
		    }
		}
		
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}