class Solution {
public:
    int numDifferentIntegers(string w) {
        unordered_set<string>s;
        int countz=0,i=0;
        string res="";
        while(i<w.size()){
            if(isalpha(w[i])) i++;
            else if(w[i]=='0'){
                while(w[i]=='0') i++;
                if(isalpha(w[i]) || i>=w.size()) countz=1;
            }
            else if(isdigit(w[i])){
                while(isdigit(w[i]))
                    res.push_back(w[i++]);
                s.insert(res);
                res="";
            }
        }
        return s.size()+countz;
    }
};