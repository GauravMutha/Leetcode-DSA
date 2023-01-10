/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//BFS
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        TreeNode *L,*R;
        
        while(!q.empty()){
            L=q.front()->left ; R=q.front()->right ; q.pop();
            if(L && R) q.push(L) ,q.push(R);
            else if(!L && !R) break;
            else if(!L) return false;
            else {
                q.push(L);
                break;
            }
        }
        
        while(!q.empty()){
            if(q.front()->left || q.front()->right) return false;
            q.pop();
        }
        
        return true;
    }
};