//ONLY ONE STATEMENT IS DIFFERENT FROM PREVIOUS CODE --> return statement
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st1;
        for(int i=0,j=0;i<pushed.size();i++){
            st1.push(pushed[i]);
            while(j<popped.size() && !st1.empty() && (st1.top()==popped[j])) 
                 st1.pop(),j++;
        }
        return st1.empty();
    }
};

//TC-->O(n) (2 pass)
//SC--> O(n) BUT uses only 1 stack