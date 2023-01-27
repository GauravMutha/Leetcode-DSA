typedef pair<int,int> p;
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string>res(score.size(),"");
        string top[3]={"Gold Medal","Silver Medal","Bronze Medal"} , temp="";
        
        priority_queue<p> maxh;
        for(int i=0;i<score.size();i++){
            maxh.push({score[i],i});
        }
        
        for(int i=0;i<score.size();i++){
            int index = maxh.top().second;
            maxh.pop();
            if(i<3) res[index] = top[i];
            else res[index]= to_string(i+1);
        }
        
        return res;
    }
};