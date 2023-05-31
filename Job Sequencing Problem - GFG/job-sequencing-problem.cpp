//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
bool cmp(const Job& a, const Job& b) {
    return a.profit > b.profit;
}
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    //considering 1 unit=1 day for this question
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,cmp);
        int jobCount=0,profitSum=0,maxDeadline=-1;
        
        for(int i=0;i<n;i++){
            maxDeadline=max(maxDeadline,arr[i].dead);
        }
        vector<bool>freeDays(maxDeadline+1,false);
        for(int i=0;i<n;i++){
            int jobDeadline=arr[i].dead;
            for(int j=jobDeadline;j>0;j--){
                if(freeDays[j]==false){
                    freeDays[j]=true;
                    jobCount++;
                    profitSum+=arr[i].profit;
                    break;
                }
            }
        }
        return {jobCount,profitSum};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends