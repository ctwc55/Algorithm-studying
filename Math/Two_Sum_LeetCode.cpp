class Solution {
public:
    typedef struct{
        int value, idx;
    }INFO;
    
    INFO data[100000];
    
    static bool cmp(INFO a, INFO b){
        return a.value<b.value;
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int idx_s=0, idx_e=nums.size()-1, sum=0;
        
        for(int i=0;i<nums.size();i++){
            data[i].value=nums[i];
            data[i].idx=i;
        }
        
        sort(data,data+nums.size(),cmp);
        
        sum=data[idx_s].value+data[idx_e].value;
        while(sum!=target){
            if(sum<target){
                sum-=data[idx_s].value;
                sum+=data[++idx_s].value;
            } 
            else{
                sum-=data[idx_e].value;
                sum+=data[--idx_e].value;
            }  
        }
        
        ans.push_back(data[idx_s].idx);
        ans.push_back(data[idx_e].idx);
        
        return ans;
    }
};
