//Backtracking
//Single recursive call in a for loop
//Using integer bits as hash instead of bool arrays
class Solution {
private:
    int maxSz=0;
public:
    bool check(string& str,int& hash2){
        int tempHash=hash2;
        for(auto& ch :str){
            if(tempHash&(1<<(ch-'a'))) return false;
            tempHash|=(1<<(ch-'a'));
        }
        hash2=tempHash;
        return true;
    }
    void helper(int pos,int currSz,int& hash,vector<string> &arr){
        
        maxSz=max(currSz,maxSz);
        
        for(int i=pos;i<arr.size();i++){
            int hash2=hash;
            if(!check(arr[i],hash2)) continue;
            currSz+=arr[i].size();
            helper(i+1,currSz,hash2,arr);
            currSz-=arr[i].size();
        }
    }
    int maxLength(vector<string>& arr) {
        int hash=0;
        helper(0,0,hash,arr);
        
        return maxSz;
    }
};