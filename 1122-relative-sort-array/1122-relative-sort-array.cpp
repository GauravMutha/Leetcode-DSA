class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>count(1001,0);
        int k=0;
        for(int i=0;i<arr1.size();i++)
            count[arr1[i]]++;
        for(int i=0;i<arr2.size();i++){
            while(count[arr2[i]]) arr1[k++]=arr2[i] , count[arr2[i]]--;
        }
        for(int i=0;i<1001;i++){
            while(count[i]) arr1[k++]=i , count[i]--;
        }
        
        return arr1;
    }
};