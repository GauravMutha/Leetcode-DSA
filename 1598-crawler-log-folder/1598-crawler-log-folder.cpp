class Solution {
public:
    int minOperations(vector<string>& logs) {
        int steps=0;
        for(auto oper : logs){
            if(oper=="../")
                steps=max(0,steps-1);
            else if(oper!="./") steps++;
        }
        return steps;
    }
};