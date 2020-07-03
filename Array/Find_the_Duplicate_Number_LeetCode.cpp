class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int arr[100000], ans;
        for(int i=0;i<1000;i++) arr[i]=0;
        
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]++;
            if(arr[nums[i]]==2){
                ans=nums[i];
                break;
            }
        }
        
        return ans;
    }
};
