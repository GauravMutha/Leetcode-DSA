//Backtracking
//Single recursive call in a for loop
//Using integer bits as hash instead of bool arrays
//Slightly optimised than before using preprocessing
class Solution {
private:
    int maxSz=0;
public:
    void helper(int pos,int currSz,int hash,vector<string>&arr,vector<int>& hashArr){
        
        maxSz=max(currSz,maxSz);
        
        for(int i=pos;i<arr.size();i++){
            if(hashArr[i]&(1<<26)) continue;
            if((hash & hashArr[i]) != 0) continue;
            currSz+=arr[i].size();
            helper(i+1,currSz,hash|hashArr[i],arr,hashArr);
            currSz-=arr[i].size();
        }
    }
    int maxLength(vector<string>& arr) {
        int hash=0;
        vector<int>hashArr(arr.size(),0);
        for(int i=0;i<arr.size();i++){
            for(auto ch :arr[i]){
                if(hashArr[i]&(1<<(ch-'a'))){
                    hashArr[i]|=(1<<26);
                    break;
                }
                hashArr[i]|=(1<<(ch-'a'));
            }
        }  
        
        helper(0,0,hash,arr,hashArr);
        
        return maxSz;
    }
};