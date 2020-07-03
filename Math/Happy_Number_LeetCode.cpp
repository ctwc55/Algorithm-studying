class Solution {
public:
    bool isHappy(int n) {
        int tmp, sum, chk[1000];
        for(int i=0;i<1000;i++) chk[i]=0;
        
        tmp=n;
        while(sum!=1){
            sum=0;
            while(tmp>0){
                sum+=(tmp%10)*(tmp%10);
                tmp/=10;
            }
            if(chk[sum]) return false;
            chk[sum]=1;
            tmp=sum;
        }
        
        return true;
    }
};
