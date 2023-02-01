typedef pair<int,int> p;
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int>res;
        priority_queue<p,vector<p>,greater<p>> minh;
        long time=0,i=0,n=tasks.size();
        
        for(int i=0;i<tasks.size();i++)
            tasks[i].push_back(i);
        
        sort(tasks.begin(),tasks.end());
        
        while(i<n || minh.size()){
            if(minh.empty()) time=max(time,(long)tasks[i][0]);
            while(i<n && time>=tasks[i][0]){
                minh.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            auto [process,index] = minh.top();
            minh.pop();
            time+=process;
            res.push_back(index);
        }
        return res;
    }
};