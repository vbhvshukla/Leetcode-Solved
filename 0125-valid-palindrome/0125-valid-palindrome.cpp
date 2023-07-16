class Solution {
public:
    bool isPalindrome(string s) {
        string x = "";
        for(int i = 0;i<s.size();i++){
            if(isalnum(s[i])){
                x+=s[i];
            }
        }
        int start = 0;
        int end = x.size()-1;
        while(start<=end){
            if(tolower(x[start])!=tolower(x[end])){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};