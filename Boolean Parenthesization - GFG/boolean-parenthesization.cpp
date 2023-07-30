//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

//Memoization

class Solution{
private: 
    int mod=1003;
public:
    int helper(int i,int j,int wantTrue,string &str,vector<vector<vector<int>>> &dp){
        
        if(i>j) return 0;
        if(i==j)
            return (wantTrue) ? (str[i]=='T') : (str[i]=='F');
            
        if(dp[i][j][wantTrue]!=-1) return dp[i][j][wantTrue];
        
    }
    
    int countWays(int n, string str){
        
        vector<vector<vector<int>>>dp (n,vector<vector<int>>(n,vector<int>(2,0)));
        
        for(int i=0;i<n;i+=2){
            if(str[i]=='T') dp[i][i][1]=1;
            else dp[i][i][0]=1;
        }
        
        for(int i=n-1;i>=0;i--){
            
            for(int j=i+1;j<n;j++){
                
                
                for(int wantTrue=0;wantTrue<=1;wantTrue++){
                    
                    int ways=0;
                    
                    for(int ind=i+1;ind<j;ind+=2){
                        
                        int lt=dp[i][ind-1][1];
                        int lf=dp[i][ind-1][0];
                        int rt=dp[ind+1][j][1];
                        int rf=dp[ind+1][j][0];
                        
                        if(str[ind]=='&'){
                            if(wantTrue) ways = (ways+ (lt*rt)%mod)%mod;
                            else ways = (ways+ (lt*rf)%mod + (lf*rt)%mod + (lf*rf)%mod)%mod;
                        }
                        else if(str[ind]=='|'){
                            if(wantTrue) ways = (ways+ (lt*rt)%mod+ (lf*rt)%mod + (lt*rf)%mod)%mod;
                            else ways = (ways+ (rf*lf)%mod)%mod;
                        }
                        else if(str[ind]=='^'){
                            if(wantTrue) ways = (ways+ (lt*rf)%mod + (lf*rt)%mod)%mod;
                            else  ways = (ways+ (lf*rf)%mod + (lt*rt)%mod)%mod;
                        }
                        
                    }
                    dp[i][j][wantTrue]=ways;
                }
                
            }
        }
        
        return dp[0][n-1][1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends