class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr=root;
        while(1){
            if(curr->val>max(p->val,q->val))
                curr=curr->left;
            
            else if(curr->val<min(p->val,q->val))
                curr=curr->right;
            
            else break;
        }
        return curr;
    }
};