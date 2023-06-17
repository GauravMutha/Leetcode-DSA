//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

bool cmp(const Item &a , const Item &b){
    double ratio1=a.value*1.0/a.weight*1.0;
    double ratio2=b.value*1.0/b.weight*1.0;
    return (ratio1) > (ratio2);
}
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,cmp);
        double res=0.0;
        int currWtSum=0;
        for(int i=0;i<n;i++){
            if((currWtSum+arr[i].weight)<=W)
                currWtSum+=arr[i].weight , res+=arr[i].value;
            else{
                double valuePerWt=(arr[i].value*1.0/arr[i].weight*1.0);
                res+=(W-currWtSum)*valuePerWt;
                break;
            }
        }
        return res;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends