//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       long long prod=1;
       int cnt=0,zInd=0; //cnt holds the zero count
       vector<long long>res(n,0);
       
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                cnt++;
                zInd=i;
            }
            else prod*=nums[i];  
        }
        
        if(cnt>1) return res;
        else if(cnt==1){
            res[zInd]=prod;
            return res;
        }
        
        for(int i=0;i<n;i++){
            res[i]=(long long)(prod/nums[i]);
        }
        
        return res;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends