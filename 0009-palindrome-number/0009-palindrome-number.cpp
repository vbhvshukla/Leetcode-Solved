class Solution {
public:
    bool isPalindrome(int x) {
        long long temp = x;
        if(x<0){
            return false;
        }
        abs(x);
        long long revnum = 0;
        while(x){
            revnum = revnum * 10 + x%10;
            x/=10;
        }
        if(revnum == temp){
            return true;
        }
        else {
            return false;
        }
    }
};