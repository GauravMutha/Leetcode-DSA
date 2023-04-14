//Simple concepts of subset I
//Preprocessing to store all the given length subsets/combinations
//Using single recursion call in for loop
class CombinationIterator {
private:
    int itr=0;
    vector<string>allCombinations;
    void helper(int pos,string &ds,string & str,int sz){
        if(ds.size()>=sz){
            if(ds.size()==sz) 
                allCombinations.push_back(ds);
            return;
        }
        for(int i=pos;i<str.size();i++){
            if(ds.back()==str[i]) continue;
            ds.push_back(str[i]);
            helper(i+1,ds,str,sz);
            ds.pop_back();
        }
    }
public:
    CombinationIterator(string characters, int combinationLength) {
        string ds;
        helper(0,ds,characters,combinationLength);
    }
    
    string next() {
         return allCombinations[itr++];
    }
    
    bool hasNext() {
        return itr<allCombinations.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */