class Solution {
public:
    int maxRepOpt1(string text) {
        int res=0;
        vector<vector<int>>indhash(26);
        for(int i=0;i<text.size();i++) indhash[text[i]-'a'].push_back(i);
        
        for(int n=0;n<indhash.size();n++){
            int curr=1,prev=0,maxlen=0;
            for(int i=1;i<indhash[n].size();i++){
                if(indhash[n][i]==indhash[n][i-1]+1) curr++;
                else{
                    prev=(indhash[n][i]==indhash[n][i-1]+2) ? curr:0;
                    curr=1;
                }
                maxlen=max(maxlen,curr+prev);
            }
            if(indhash[n].size()>maxlen) maxlen+=1;
            res=max(res,maxlen);
        }
        return res;
    }
};

//group by method