//No Sorting or Priority Queue
//TC-->O(N)
//TC-->O(1)
class Solution {
public:
    string reorganizeString(string s) {
        vector<int>hash(26,0);
        int maxFreq=0,maxLetter=0 , ind=0,sz=s.size();
        string res(sz,' ');
        
        for(auto &c : s) hash[c-'a']++;
        for(int i=0;i<hash.size();i++){
            if(hash[i]>maxFreq) maxFreq=hash[i] , maxLetter=i; 
        }
        
        if(maxFreq>(sz+1)/2) return "";
        
        while(hash[maxLetter]>0){
            res[ind]=char(maxLetter+'a');
            ind+=2;
            hash[maxLetter]--;
        }
        
        for(int i=0;i<hash.size();i++){
            while(hash[i]>0){
                if(ind>=sz) ind=1;
                res[ind]=char(i+'a');
                ind+=2;
                hash[i]--;
            }
        }
        
        return res;
    }
};