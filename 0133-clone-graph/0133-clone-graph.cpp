/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
//BFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        unordered_map<Node*,Node*>m;
        auto clonedRoot=new Node(node->val);
        m[node]=clonedRoot;
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            for(auto adjNode: curr->neighbors){
                if(m.find(adjNode)==m.end()){
                    auto NewNode=new Node(adjNode->val);
                    m[adjNode]=NewNode;
                    q.push(adjNode);
                }
                m[curr]->neighbors.push_back(m[adjNode]);
            }
        }
        return m[node];
    }
};