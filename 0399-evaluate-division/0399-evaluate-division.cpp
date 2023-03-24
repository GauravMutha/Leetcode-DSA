//DFS
class Solution {
private:
    
    unordered_map<string,vector<pair<string,double>>>graph;
    vector<double>res;
    double ans=0;

public:
    
    void dfs(string curr,string dest,double calc,unordered_map<string,bool>& visited){
        visited[curr]=true;
        if(curr==dest){
            ans=calc;
            return;
        }
        for(auto &[adjNode,val]: graph[curr]){
            if(!visited[adjNode]){
                dfs(adjNode,dest,calc*val,visited);
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
            unordered_map<string,bool>visited;
            if(graph.find(src)!=graph.end()){
                dfs(src,dest,1.0,visited);
            }
            res.push_back(ans);
        }
        return res;
    }
};