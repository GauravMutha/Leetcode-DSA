class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int minsum=0;
        unordered_map<string,int>m;
        map<int,vector<string>>res;
        
        for(int i=0;i<list1.size();i++)
            m[list1[i]]=i;
        for(int i=0;i<list2.size();i++)
            if(m.find(list2[i])!=m.end()) res[i+m[list2[i]]].push_back(list2[i]);
        
        return res.begin()->second;
    }
};

//Another verson of hash set.
