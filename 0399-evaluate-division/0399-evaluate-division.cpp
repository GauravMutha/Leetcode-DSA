//BFS
class Solution {
private:
    
    unordered_map<string,vector<pair<string,double>>>graph;
    vector<double>res;
    double ans;

public:
    
    void bfs(string src,string dest){
        unordered_map<string,bool>visited;
        queue<pair<string,double>>q;
        q.push({src,1.0});
        
        while(!q.empty()){
            string curr=q.front().first;
            double calc=q.front().second;
            q.pop();
            if(curr==dest){
                ans=calc;
                return;
            }
            for(auto &[adjNode,val]:graph[curr]){
                if(!visited[adjNode])
                    q.push({adjNode,calc*val}) , visited[adjNode]=true;
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        for(int i=0;i<equations.size();i++){
            string u=equations[i][0] , v=equations[i][1];
            double val=values[i];
            
            graph[u].push_back({v,val});
            graph[v].push_back({u,1/val});
        }
        
        for(int i=0;i<queries.size();i++){
            string src=queries[i][0] , dest=queries[i][1];
            ans=-1;
            if(graph.find(src)!=graph.end() && graph.find(dest)!=graph.end() ){
                bfs(src,dest);
            }
            res.push_back(ans);
        }
        return res;
    }
};