class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int tmp;
        
        while(nums.size()>1){
            tmp=nums.size();
            for(int i=1;i<nums.size();i++){
                if(nums[0]==nums[i]){
                    nums.erase(nums.begin());
                    nums.erase(nums.begin()+i-1);
                    break;
                }
            }
            if(tmp==nums.size()) break;
        }
        
        return nums[0];
    }
};
