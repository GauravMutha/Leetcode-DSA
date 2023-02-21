// We can reduce time complexity by using two pointers and sorting
//O(MlogM) mi sisze of banned array
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(begin(banned),end(banned));
        int j=0,sum=0,count=0;
        
        for(int i=1;i<=n && sum+i<=maxSum;i++){
            if(j>=banned.size() || i!=banned[j]) 
                sum+=i , count++;
            else 
                while(j<banned.size() && i==banned[j]) j++;
        }
        
        return count;
    }
};