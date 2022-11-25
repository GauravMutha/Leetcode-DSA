class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int>res;
        for(auto a : ast){
            bool flag=false;
            while(res.size() && res.back()>0 && a<0 && !flag){
                if(res.back()>=-a) flag=true;
                if(res.back()<=-a) res.pop_back();
            }
            if(!flag) res.push_back(a);
        }
        return res;
    }
};