class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n=ratings.size();
        vector<int>vec(n,1);
        
        for(int i=1;i<n;i++)
            if(ratings[i]>ratings[i-1] && vec[i]<=vec[i-1])
                vec[i]=(vec[i-1]+1);
        for(int i=n-2;i>=0;i--)
            if(ratings[i]>ratings[i+1] && vec[i]<=vec[i+1])
                vec[i]=(vec[i+1]+1);
        
        int res=accumulate(vec.begin(),vec.end(),0);
        
        return res;
    }
};