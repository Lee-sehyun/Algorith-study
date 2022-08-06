#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	setbuf(stdout, NULL);
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		
		int n, m, size;
		int even = 0, odd = 0;
// 		vector<pair<int, int> > max(3);
		
		cin >> n >> m;
		
// 		vector<vector<int> > w;
		
		for(int i = 0 ; i < n ; i++){
		    cin >> size;
		    vector<int> temp(size);
		    for(int j = 0 ; j < size ; j++){
		        cin >> temp[j];
		    }
		    
		    sort(temp.begin(), temp.end());
		    
		    if(odd%2 == 0){
		        if(size%2 == 0){
    		      //  even++;
    		        
    		        for(int j = 0 ; j < 4 ; j++){
    		            Answer += temp[j];
    		        }
    		        
    		      //  if(temp[2] + temp[3] > max[0].first){
    		      //      max[0].first = temp[2] + temp[3];
    		      //      max[0].second = 2;
    		      //  }
    		      //  sort(max.begin(), max.end());
    				// w.push_back(temp);
    		    }
    		    else {
    		        odd++;
    		        
    		        Answer += temp[0];
    		        for(int j = 0 ; j < 4 ; j++){
    		            Answer += temp[j];
    		        }
    		        
    		      //  if(temp[2] + temp[3] > max[0].first){
    		      //      max[0].first = temp[2] + temp[3];
    		      //      max[0].second = 1;
    		      //  }
    		      //  sort(max.begin(), max.end());
    		    }
		    }
		    else {
		        if(size%2 == 0){
    		      //  even++;
    		        
    		        Answer += temp[0];
    		        Answer += temp[1];
    		        for(int j = 0 ; j < 4 ; j++){
    		            Answer += temp[j];
    		        }
    		        
    		  //      if(temp[2] + temp[3] > max[0].first){
    		  //          max[0].first = temp[2] + temp[3];
    		  //          max[0].second = 2;
    		  //      }
    		  //      sort(max.begin(), max.end());
    				// w.push_back(temp);
    		    }
    		    else {
    		        odd++;
    		        
    		        Answer += temp[0];
    		        for(int j = 0 ; j < 4 ; j++){
    		            Answer += temp[j];
    		        }
    		        
    		      //  if(temp[2] + temp[3] > max[0].first){
    		      //      max[0].first = temp[2] + temp[3];
    		      //      max[0].second = 1;
    		      //  }
    		      //  sort(max.begin(), max.end());
    		    }
		    }
		    
		    if(i == 0 || i == n-1){
	            Answer -= temp[2];
	            Answer -= temp[3];
	        }
		    
		}
	
		
// 		if(max[2].second == 1 && max[1].second == 1 && odd == 2){
// 			Answer -= max[2].first;
// 			int sum = Answer - max[1].first;
// 			Answer -= max[0].first;
// 			for(int i = 0 ; i < n-2 ; i++){
// 				sum += w[i][0] + w[i][1];
// 			}
// 			if(sum < Answer){
// 				Answer = sum;
// 			}
// 		}
// 		else{
		  //  Answer -= max[2].first;
		  //  Answer -= max[1].first;
// 		}
		
		
		
		
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}