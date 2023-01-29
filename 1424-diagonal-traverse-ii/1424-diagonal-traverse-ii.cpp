//Priority Queue + comparator
typedef pair<int,int>p;
class compare{
public:
    bool operator()(const p &a ,const p &b){
        return (a.first>b.first) || ( (a.first==b.first) && (a.second<b.second));
    }
};
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int>res;
        priority_queue<p,vector<p>,compare> pq;
        for(int r=0;r<nums.size();r++){
            for(int c=0;c<nums[r].size();c++)
                pq.push({r+c,r});
        }
        while(!pq.empty()){
            int i=pq.top().second , j=pq.top().first-i;
            res.push_back(nums[i][j]);
            pq.pop();
        }
        
        return res;
    }
};