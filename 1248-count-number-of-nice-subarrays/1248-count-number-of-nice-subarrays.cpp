class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l=0,r=0,odd=0,res=0,count=0;
        for(r=0;r<nums.size();r++){
            if(nums[r]%2){
                odd++;
                if(odd>=k){
                    count=1;
                    while((nums[l++]%2)==0) count++;
                    res+=count;
                }
            }
            else if(odd>=k) res+=count;
        }
        return res;
    }
};

//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int j = 0, odd = 0, count = 0, total = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] & 1) {
//                 odd++;
//                 if (odd >= k) {
//                     count = 1;
//                     while (!(nums[j++] & 1)) count++;
//                     total += count;
//                 }
//             } else if (odd >= k) total += count;
//         }
//         return total;
//     }
// };