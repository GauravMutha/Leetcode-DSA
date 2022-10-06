class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int minsum=INT_MAX;
        unordered_map<string,int>m;
        vector<string>res;
        
        for(int i=0;i<list1.size();i++)
            m[list1[i]]=i+1;
        for(int i=0;i<list2.size();i++){
            if(m.find(list2[i])!=m.end()){
                m[list2[i]]+=i+1;
                minsum=min(m[list2[i]],minsum);
            }
        }
        
        for(int i=0;i<list1.size();i++)
            if(m[list1[i]]>i+1 && m[list1[i]]==minsum) res.push_back(list1[i]);
        
        return res;
    }
};

//This solution removes the clearing and filling of vector again and again
//without introducing another map