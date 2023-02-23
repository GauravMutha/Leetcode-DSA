//sorting + binary search(using lower bound)
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int>res(queries.size());
        sort(begin(items),end(items));
        int maxBeauty=-1;
        for(auto &p:items){
            maxBeauty=max(maxBeauty,p[1]);
            p.push_back(maxBeauty);
        }
        
        //comparator function for upper_bound on vector of vectors
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };
        
        for(int i=0;i<queries.size();i++){
            //making a temp vector to pass as val in upper_bound
            vector<int>temp={queries[i],-1,-1};
            auto it=upper_bound(begin(items),end(items),temp,cmp);
            if(it==items.begin()) res[i]=0;
            else res[i] = (*(--it))[2];
        }
        
        return res;
    }
};