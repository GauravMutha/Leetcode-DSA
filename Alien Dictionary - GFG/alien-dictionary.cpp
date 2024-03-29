//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    
    vector<int>doTopoSort(vector<int>graph[],int k) {
        
        vector<int>topo;
        queue<int>q;
        vector<int>indeg(k,0);

        
        for(int i=0;i<k;i++){
            for(int j=0;j<graph[i].size();j++){
                indeg[graph[i][j]]++;
            }
        }
        
        for(int i=0;i<k;i++) if(indeg[i]==0) q.push(i);
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            topo.push_back(curr);         
            for(auto &adjNode:graph[curr]){
                indeg[adjNode]--;
                if(indeg[adjNode]==0) q.push(adjNode);
            }
        }
        return topo;
    }
    
    public:
    string findOrder(string dict[], int n, int k) {
        vector<int>graph[k];
        string ans="";
        for(int i=0;i<(n-1);i++){
            int len=min(dict[i].size(),dict[i+1].size());
            for(int ptr=0;ptr<len;ptr++){
                if(dict[i][ptr]==dict[i+1][ptr]) continue;
                graph[dict[i][ptr]-'a'].push_back(dict[i+1][ptr]-'a');
                break;
            }
        }
        
        vector<int>topo=doTopoSort(graph,k);
        for(int i=0;i<topo.size();i++){
            ans+=char(topo[i]+'a');
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends