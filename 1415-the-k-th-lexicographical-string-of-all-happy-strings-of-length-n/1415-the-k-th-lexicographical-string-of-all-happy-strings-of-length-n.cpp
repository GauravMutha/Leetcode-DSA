class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string>res;
        string temp="";
        generate(res,temp,n);
        if(res.size()<k)return "";
        return res[k-1];
    }
    
    void generate(vector<string>& res,string& curr,int n){
        static vector<char>vect={'a','b','c'};
        if(curr.size()==n){
           res.push_back(curr);
            return;
        }
        for(int i=0;i<vect.size();i++){
            if(curr.size() && (curr.back()==vect[i]))continue;
            curr+=vect[i];
            generate(res,curr,n);
            curr.pop_back();
        }
    }
};