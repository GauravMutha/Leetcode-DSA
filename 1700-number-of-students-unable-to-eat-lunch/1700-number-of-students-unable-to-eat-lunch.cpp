class Solution {
public:
    int countStudents(vector<int>& stu, vector<int>& sand) {
        int front =0, ind=0 ,end=0 ,len=sand.size(), res=len;
        while(res){
            if(stu[front]==sand[ind]){
                res--;
                stu[front]=-1;
                front=(front+1)%len;
                ind++;
            }
            else{
                end=front;
                front=(front+1)%len;
                while(stu[front]!=sand[ind] && front!=end) front=(front+1)%len;
                if(front==end) break;
            }
        }
        return res;
    }
};

//Using two pointer
//No Queue
//SC-->O(1)
//TC-->O(n)