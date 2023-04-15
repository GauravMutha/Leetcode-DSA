//Genrate all gray codes first then filling 'ans' from 'start'
//Similar to 89.Gray Codes
class Solution {
public:
    vector<int> generate(int n){
        if(n==0) return {0};
        vector<int> vec=generate(n-1);
        int mask=1<<(n-1) , sz=vec.size();
        for(int i=sz-1;i>=0;i--){
            int temp=vec[i];
            temp|=mask;
            vec.push_back(temp);
        }
        return vec;
    }
    vector<int> circularPermutation(int n, int start) {
        vector<int>gCodes=generate(n);
        vector<int>ans;
        bool startFound=false;
        for(int i=0;ans.size()<gCodes.size();){
            if(gCodes[i]==start) startFound=true;
            if(startFound) ans.push_back(gCodes[i]);
            i++;
            i%=gCodes.size();
        }
        
        return ans;
    }
};