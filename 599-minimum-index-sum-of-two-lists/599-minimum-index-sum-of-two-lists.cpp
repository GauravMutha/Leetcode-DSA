class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int minsum=INT_MAX;
        vector<string>res;
        for(int i=0;i<list1.size();i++){
            for(int j=0;j<list2.size();j++){
                if(list1[i]==list2[j] && i+j<minsum){
                    res.clear();
                    res.push_back(list1[i]);
                    minsum=i+j;
                }
                else if(list1[i]==list2[j] && i+j==minsum){
                    res.push_back(list1[i]);
                }
            }
        }
        return res;
    }
};

//brute force