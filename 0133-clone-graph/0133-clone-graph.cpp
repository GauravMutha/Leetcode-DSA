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
//DFS
class Solution {
private:
    unordered_map<Node*,Node*>m;
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        if(m.find(node)!=m.end()) return m[node];
        auto NewNode=new Node(node->val);
        m[node]=NewNode;
        
        for(auto adjNode:node->neighbors){
            m[node]->neighbors.push_back(cloneGraph(adjNode));
        }
        return m[node];
    }
};