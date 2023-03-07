//MERGE SORT
//Iterative
//Extra Space
class Solution {
public:
    void merge(vector<int>&arr,int low,int mid,int high){
        vector<int>temp;
        int i=low , j=mid+1;
        while(i<=mid && j<=high){
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else {
                temp.push_back(arr[j]);
                j++;
            }
        }
        while(i<=mid) temp.push_back(arr[i]) , i++;
        while(j<=high) temp.push_back(arr[j]) , j++;
        
        for(int i=low;i<=high;i++) arr[i]=temp[i-low];
    }
    vector<int> sortArray(vector<int>& arr) {
        int currSize,n=arr.size(),pass=0;
        for(currSize=1;currSize<n;currSize*=2){
            for(int left=0; left<n-1; left+=2*currSize){
                
                int mid=min(left+currSize-1,n-1);
                int right=min(left+2*currSize-1,n-1);
                
                merge(arr,left,mid,right);
            }
        }
        return arr;
    }
};