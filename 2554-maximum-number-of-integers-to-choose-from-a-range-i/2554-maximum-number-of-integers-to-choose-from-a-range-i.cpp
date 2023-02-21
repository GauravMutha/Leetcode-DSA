//Linear search
//TC-->O(max(N,M)) SC-->O(M) where M is number of unique elements in banned
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int>s;
        for(int i=0;i<banned.size();i++){
            if(banned[i]<=n) s.insert(banned[i]); 
        }
        int sum=0,count=0;
        for(int i=1;i<=n;i++){
            if(s.find(i)==s.end() && sum+i<=maxSum) sum+=i ,count++;
        }
        
        return count;
    }
};