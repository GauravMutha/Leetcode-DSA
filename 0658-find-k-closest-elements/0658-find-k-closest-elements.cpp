// priority queue maxheap O(nlog(k))
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>res;
        priority_queue<pair<int,int>>maxh;
        
        for(int i=0;i<arr.size();i++){
            maxh.push({abs(arr[i]-x),i});
            if(maxh.size()>k) maxh.pop();
        }
        
        while(!maxh.empty()){
            res.push_back(arr[maxh.top().second]);
            maxh.pop();
        }
        sort(res.begin(),res.end());
        return res;
    }
};