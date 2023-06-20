//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&cost){
	    int n =cost.size();
	    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(cost[i][j]==-1) cost[i][j]=1e9;
                if(i==j) cost[i][j]=0;
            }
	    }
	    for(int via=0;via<n;via++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                int x=cost[i][via]+cost[via][j];
	                cost[i][j]=min(cost[i][j],x);
	            }
	        }
	    }
	    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(cost[i][j] == 1e9) cost[i][j]=-1;
            }
	    }
	    return;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends