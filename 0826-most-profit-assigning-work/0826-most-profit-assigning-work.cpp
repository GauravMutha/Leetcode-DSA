//vector of pairs + sorting + two pointers
//instead of map + ----------+ instead of binary search
class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& profit, vector<int>& worker) {
        
        vector<pair<int,int>>jobs;
        for(int i=0;i<diff.size();i++){
            jobs.push_back({diff[i],profit[i]});
        }
        
        sort(begin(worker),end(worker));
        sort(begin(jobs),end(jobs));
        
        int j=0,maxProfit=0,res=0,n=jobs.size(); //index for jobs
        for(auto &ability : worker){
            while(j<n && jobs[j].first<=ability){
                maxProfit=max(maxProfit,jobs[j].second);
                j++;
            }
            res+=maxProfit;
        }
        return res;
    }
};