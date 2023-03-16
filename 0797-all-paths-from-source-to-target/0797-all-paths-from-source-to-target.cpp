//BFS traversal
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        queue<vector<int>>q;
        q.push({0});
        while(!q.empty()){
            auto path=move(q.front()); 
            q.pop();
            if(path.back()==graph.size()-1){
                //the vector we just popped out has reached the target
                ans.push_back(path);
            }
            else{
                //new vectors are inserted here based on previous vector's neighbours
                for(auto node : graph[path.back()]){
                    path.push_back(node);
                    q.push(path);
                    path.pop_back();
                }
            }
        }
        
        return ans;
    }
};