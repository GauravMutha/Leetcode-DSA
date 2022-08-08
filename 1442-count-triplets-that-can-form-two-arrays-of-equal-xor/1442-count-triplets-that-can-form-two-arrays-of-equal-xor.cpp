class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int pair1=0,pair2=0,count=0;
        for(int i=0;i<arr.size()-1;i++){
             pair1=arr[i];  
            for(int j=i+1;j<arr.size();j++){
                pair1^=arr[j];
                pair2=arr[j];
                for(int k=j;k<arr.size();k++){
                        pair2^=arr[k];
                    if(pair1==pair2){count++;}
                }
            }
        }
        return count;
    }
};