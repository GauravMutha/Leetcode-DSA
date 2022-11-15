class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0;
        for(int j=0,k=0;j<pushed.size();j++,i++){
            pushed[i]=pushed[j];
            while(i>=0 && j<pushed.size() && pushed[i]==popped[k]) i--, k++;
        }
        i--;
        return (i<0);
    }
};

//TC-->O(n) (1 pass)
//SC--> O(1) USES NO EXTRA SPACE