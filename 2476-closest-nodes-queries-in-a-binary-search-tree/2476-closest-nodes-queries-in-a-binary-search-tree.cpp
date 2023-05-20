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
/*Previous submission gives TLE , because queries size is big,
its better that we first create an sorted array of nodes and
binary search there, , rather than searching tree every time*/

//Implementing lower bound without STL
class Solution {
public:
    int lowerBound(vector<int>& test,int target){
        int start = 0, end = test.size() - 1, mid = 0;
        bool found = false; // found is made true if the target itself gets found in the test array
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (test[mid] == target)
            {
                found = true;
                break;
            }
            else if (test[mid] > target)
                end = mid - 1;
            else if (test[mid] < target)
                start = mid + 1;
        }
        int result;
        if (found)
            result = mid;
        else if(start>=test.size())
            result = -1;
        else result=start;

        return result;
    }
    void inorder(TreeNode *curr, vector<int>& res) {
        if(curr==NULL) return;
        inorder(curr->left,res);
        res.push_back(curr->val);
        inorder(curr->right,res);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int>nodesArr;
        vector<vector<int>>res;
        inorder(root,nodesArr);
        for(auto q:queries){
            
            int cInd=lowerBound(nodesArr,q);
            int cVal=(cInd==-1)?-1 : nodesArr[cInd];
            
            int fVal=-1;
            if(cVal==q) fVal=cVal;
            else if(cVal==-1) fVal=nodesArr.back();
            else if(cInd>0) fVal=nodesArr[cInd-1]; 
            
            res.push_back({fVal,cVal});
        }
        return res;
    }
};