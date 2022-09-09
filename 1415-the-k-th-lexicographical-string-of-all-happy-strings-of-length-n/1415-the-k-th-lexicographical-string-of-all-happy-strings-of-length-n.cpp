class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string>res;
        string temp="";
        generate(res,temp,n,k);
        
        return (res.size()==k)?res.back():"";
    }
    
    void generate(vector<string>& res,string& curr,int n,int k){
        static vector<char>vect={'a','b','c'};
        if(res.size()==k)return;
        if(curr.size()==n){
            res.push_back(curr);
            return;
        }
        for(int i=0;i<vect.size();i++){
            if(curr.size() && (curr.back()==vect[i]))continue;
            curr+=vect[i];
            generate(res,curr,n,k);
            curr.pop_back();
        }
    }
};