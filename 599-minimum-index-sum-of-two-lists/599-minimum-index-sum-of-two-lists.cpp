class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string>res;
        int minsum=INT_MAX;
        unordered_map<string,int>m;
        
        for(int i=0;i<list1.size();i++)
            m[list1[i]]=i;
        
        for(int i=0;i<list2.size();i++){
            if(m.find(list2[i])==m.end()) continue;
            if(m[list2[i]]+i<minsum){
                res.clear();
                res.push_back(list2[i]);
                minsum=i+m[list2[i]];
            }
            else if(m[list2[i]]+i==minsum)
                res.push_back(list2[i]);
        }
        return res;
    }
};

//Worst case TC--> O(nlogn + m^2)
//SC--> O(n)
