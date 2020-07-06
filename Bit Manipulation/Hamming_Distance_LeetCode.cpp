class Solution {
public:
    int hammingDistance(int x, int y) {
        int com=x^y, ans=0;
        while(com>0){
            if(com&1) ans++;
            com>>=1;
        }
        
        return ans;
    }
};
