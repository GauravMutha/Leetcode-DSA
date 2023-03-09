//Radix Sort using vectors of linked lists
 // Definition for singly-linked list.
struct Node {
    int val;
    Node *next;
    Node *tail;
    Node() : val(0), next(nullptr), tail(this) {}
    Node(int x) : val(x), next(nullptr), tail(this) {}
};
class Solution {
public:
    void radixSort(vector<int>&nums,int factor){
        vector<Node*>bucket(10,nullptr);
        for(auto &num : nums){
            auto newNode=new Node(num);
            if(bucket[(num/factor)%10]==nullptr)
                bucket[(num/factor)%10]=newNode;
            else{
                auto tNode=bucket[(num/factor)%10]->tail;
                tNode->next=newNode;
                bucket[(num/factor)%10]->tail=newNode;
            }
        }
        
        int i=0;
        for(auto &ptr : bucket){
            if(ptr==nullptr) continue;
            auto curr=ptr;
            while(curr!=nullptr){
                nums[i++]=curr->val;
                curr=curr->next;
            }
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size(),factor=1;
        int maxVal=INT_MIN,minVal=*min_element(begin(nums),end(nums));
        
        for(auto &num : nums) num-=minVal , maxVal=max(num,maxVal);
        
        while(maxVal/factor){
            radixSort(nums,factor);
            factor*=10;
        }
        for(auto &num : nums) num+=minVal;
        return nums;
    }
};