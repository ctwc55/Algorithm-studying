class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt=0, idx=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) cnt++;
        }
        
        if(cnt==nums.size()||cnt==0) return;
        
        while(cnt--){
            while(nums[idx]!=0) idx++;
            nums.erase(nums.begin()+idx);
            nums.push_back(0);
        }
        
        return;
    }
};
