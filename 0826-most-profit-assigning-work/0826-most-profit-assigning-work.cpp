//map+binary search(lower_bound)
class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& profit, vector<int>& worker) {
        map<int,int>m;
        int totalProfit=0, maxProfit=-1;
        
        //sorts job difficulties with their profit
        for(int i=0;i<diff.size();i++)
            m[diff[i]]=max(m[diff[i]],profit[i]);
        //within map itself , we make values as prefix array of maxProfit
        for(auto it=m.begin();it!=m.end();it++){
            maxProfit=max(maxProfit,it->second);
            it->second=maxProfit;
        }
        
        for(int i=0;i<worker.size();i++){
            auto it=m.upper_bound(worker[i]);
            it--;
            totalProfit+=it->second;
        }
        
        return totalProfit;
    }
};