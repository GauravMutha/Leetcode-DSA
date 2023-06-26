//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int nums1[], int nums2[], int n1, int n2, int k)
    {
        int ptr1=0 , ptr2=0 ,count=0;
        
        while(ptr1<n1 && ptr2<n2 && count<k){
            count++;
            if(nums1[ptr1]<=nums2[ptr2]){
                if(count==k) return nums1[ptr1];
                ptr1++;
            }
            else {
                if(count==k) return nums2[ptr2];
                ptr2++;
            }
        }
        
        while(ptr1<n1 && count<k){
            count++;
            if(count==k) return nums1[ptr1];
            ptr1++;
        }
        while(ptr2<n2 && count<k){
            count++;
            if(count==k) return nums2[ptr2];
            ptr2++;
        }
        
        return 1;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends