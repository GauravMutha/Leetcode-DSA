//Bucket sort using vector of Linked Lists
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
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        int minVal=*min_element(begin(nums),end(nums));
        int maxVal=*max_element(begin(nums),end(nums));
        vector<Node*>bucket(maxVal-minVal+1,0);
        
        for(auto &num : nums){
            auto newNode=new Node(num-minVal);
            if(bucket[num-minVal]==nullptr)
                bucket[num-minVal]=newNode;
            else{
                auto tNode=bucket[num-minVal]->tail;
                tNode->next=newNode;
                bucket[num-minVal]->tail=newNode;
            }
        }
        int i=0;
        for(auto &ptr : bucket){
            if(ptr==nullptr) continue;
            auto curr=ptr;
            while(curr!=nullptr){
                nums[i++]=curr->val+minVal;
                curr=curr->next;
            }
        }
        return nums;
    }
};