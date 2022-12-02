class Solution {
public:
    int countStudents(vector<int>& stu, vector<int>& sand) {
        int count[2]={} , len=sand.size() ,ind=0;
        
        for(auto type : stu) count[type]++;
        
        for(auto type : sand){
            if(count[type]) count[type]-- , ind++;
            else break;
        }
        
        return len-ind;
    }
};

//Order of students does not matter
//SC-->O(1)
//TC-->O(n)