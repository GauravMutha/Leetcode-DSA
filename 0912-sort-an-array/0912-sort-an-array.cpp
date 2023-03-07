//MERGE SORT
//Recursive
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
    void mergeSort(vector<int>&arr,int low,int high){
        if(low>=high) return;
        
        int mid=low+(high-low)/2;
        
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
    vector<int> sortArray(vector<int>& arr) {
        int low=0,high=arr.size()-1;
        mergeSort(arr,low,high);
        return arr;
    }
};