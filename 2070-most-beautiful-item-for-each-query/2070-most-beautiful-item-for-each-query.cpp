//sorting  + pair vector+ two pointer
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int>res(queries.size());
        
        vector<pair<int,int>>queriesPairs;
        for(int i=0;i< queries.size();i++)
            queriesPairs.push_back({queries[i],i});
        
        sort(begin(queriesPairs),end(queriesPairs));
        sort(begin(items),end(items));
        int maxBeauty=0,j=0;
        
        for(int i=0;i<queriesPairs.size();i++){
            while(j<items.size() && items[j][0]<=(queriesPairs[i].first)){
                maxBeauty=max(maxBeauty,items[j][1]);
                j++;
            }
            res[queriesPairs[i].second]=maxBeauty;
        }
        
        return res;
    }
};