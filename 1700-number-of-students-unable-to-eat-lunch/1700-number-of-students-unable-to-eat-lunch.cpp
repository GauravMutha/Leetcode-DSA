class Solution {
public:
    int countStudents(vector<int>& stu, vector<int>& sand) {
        queue<int>q;
        for(auto elem : stu) q.push(elem);
        int k=0,count=0;
        while(k<sand.size()){
            int val=q.front();
            q.pop();
            if(sand[k]!=val) count++, q.push(val);
            else k++,count=0;
            
            if(count==q.size()) break;
        }
        return q.size();
    }
};

//Using a queue
//SC-->O(n)
//TC-->O(n)