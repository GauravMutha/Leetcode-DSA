//Simple concepts of subset I
//Preprocessing to store all the given length subsets/combinations
//using classic two recursion call method
class CombinationIterator {
private:
    int itr=0;
    vector<string>allCombinations;
    void helper(int i,string &ds,string characters,int sz){
        if(i>=characters.size()){
            if(ds.size()==sz) 
                allCombinations.push_back(ds);
            return;
        }
        ds.push_back(characters[i]);
        helper(i+1,ds,characters,sz);
        ds.pop_back();
        helper(i+1,ds,characters,sz);
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