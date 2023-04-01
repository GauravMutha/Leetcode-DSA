//BFS Kahn's
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string>ans;
        set<string>recipeSet,suppSet;
        unordered_map<string,vector<string>>graph;
        unordered_map<string,int>indeg;
        queue<string>q;
        
        //storing what is in supplies,and setting indeg of recipes to 0
        for(auto s : supplies) 
            suppSet.insert(s);
        for(auto r : recipes) 
            indeg[r]=0;
        
        //making graph
        for(int i=0;i<ingredients.size();i++){
            for(int j=0;j<ingredients[i].size();j++){
                if(suppSet.find(ingredients[i][j])==suppSet.end()){
                    graph[ingredients[i][j]].push_back(recipes[i]);
                    indeg[recipes[i]]++;
                }
            }
        }
        
        //initialising queue
        for(auto [r,val] : indeg){
            if(val==0)
                q.push({r});
        }
        
        while(!q.empty()){
            string ready=q.front(); //recipe has been made
            q.pop();
            ans.push_back(ready);
            for(auto adj : graph[ready]){
                indeg[adj]--;
                if(indeg[adj]==0){
                    q.push(adj);
                }
            }
        
        }
        return ans;
    }
};