class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        //sorting for increasing start times
        sort(intervals.begin(),intervals.end());
        
        
        for(int i=0;i<intervals.size();){
            int start=intervals[i][0],end=intervals[i][1],j;
            for(j=i+1;j<intervals.size();j++){
                if(intervals[j][0]>end) break;
                end=max(intervals[j][1],end);
            }
            i=j;
            res.push_back({start,end});
        }
        
        return res;
    }
};