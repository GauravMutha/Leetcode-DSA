class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>>graph;
        vector<string>ans;
        stack<string>st;
        int n=tickets.size();
        
        for(int i=0;i<n;i++)
            graph[tickets[i][0]].insert(tickets[i][1]);
        
        st.push("JFK");
        
        while(st.size()){
            string src=st.top();
            
            if(graph[src].size()==0){
                ans.push_back(src);
                st.pop();
            }
            else{
                auto dest=graph[src].begin();
                st.push(*dest);
                graph[src].erase(dest);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};