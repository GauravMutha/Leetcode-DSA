//Binary search
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int>candleIndx,res;
        for(int i=0;i<s.size();i++)
            if(s[i]=='|') candleIndx.push_back(i);
        for(auto q:queries){
            int lMost=lower_bound(begin(candleIndx),end(candleIndx),q[0])-begin(candleIndx);
            int rMost=upper_bound(begin(candleIndx),end(candleIndx),q[1])-begin(candleIndx)-1;
            
            int count=0;
            if(lMost>=rMost) count=0;
            else count=(candleIndx[rMost]-candleIndx[lMost]+1)-(rMost-lMost+1);
            
            res.push_back(count);
        }
        
        return res;
    }
};