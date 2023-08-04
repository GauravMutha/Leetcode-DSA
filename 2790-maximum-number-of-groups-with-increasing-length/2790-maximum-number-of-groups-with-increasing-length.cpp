//Without bonary search
//Only greedy
//O(n)
class Solution {
public:
    int maxIncreasingGroups(vector<int>& limits) {
        
        sort(limits.begin(),limits.end());
        
        long long count=0,sum=0;
        
        for(int i=0;i<limits.size();i++){
            long long group=count+1; //it is the group we are checking about
            sum+=(long long)limits[i];
            if(sum>=(long long)(group*(group+1)/2)) count++;
        }
        
        return (long long)count;
    }
};