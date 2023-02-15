//binary search + maxheap (concept of top k smallest)
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int,int>>maxh;
        vector<pair<int,int>>vec;
        int m=matrix.size() , n,ones=0;
        
        for(int r=0;r<matrix.size();r++){
            n=matrix[r].size();
            ones=upper_bound(rbegin(matrix[r]),rend(matrix[r]),0)-matrix[r].rbegin();
            vec.push_back({n-ones,r});
        }
        
        for(auto &p : vec){
            maxh.push(p);
            if(maxh.size()>k) maxh.pop();
        }
        
        vector<int>res(maxh.size());
        int i=maxh.size()-1;
        while(!maxh.empty())
            res[i--]=maxh.top().second , maxh.pop();
        
        return res;
    }
};