class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        (*digits.rbegin())++;
        for(reverse_iterator rit=digits.rbegin()+1;rit!=digits.rend();rit++){
            *rit=*rit+(*(rit-1))/10;
            *(rit-1)=(*(rit-1))%10;
        }
        if(*digits.begin()>9){
            *digits.begin()%=10;
            digits.insert(digits.begin(),1);
        }
        
        return digits;
    }
};
