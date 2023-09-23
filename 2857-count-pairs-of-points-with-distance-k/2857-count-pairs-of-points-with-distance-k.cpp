class Solution {
public:
    int countPairs(vector<vector<int>>& points, int k) {
        
        map<pair<int,int>,int>m;
        int res=0;
        
        for(int i=0;i<points.size();i++){
            
            int x2=points[i][0], y2=points[i][1];
            
            for(int a=0;a<=k;a++){
                
                int b=k-a; //basically a+b=k
                
                res+=m[{a^x2,b^y2}];
                
            }
            m[{x2,y2}]++;
        }
        
        return res;
    }
};