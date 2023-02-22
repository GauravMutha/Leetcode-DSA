//map+binary seacrh (using lower bound stl)
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int,int>m;
        vector<int>res(intervals.size());
        for(int i=0;i<intervals.size();i++){
            m[intervals[i][0]]=i;
        }
        for(int i=0;i<intervals.size();i++){
            auto it=m.lower_bound(intervals[i][1]);
            if(it==m.end()) res[i]=-1;
            else res[i]=it->second;
        }
        return res;
    }
};