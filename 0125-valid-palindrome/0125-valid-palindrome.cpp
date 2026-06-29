class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        string result = "";
        for(char c : s){
            if(isalnum(c)){
                result += tolower(c);
            }
        }
        int i=0,j=result.size()-1;
        while(i<=j){
            if(result[i]!=result[j]){
                return false;
                break;
            }else{
                i++;
                j--;
            }
        }
        return true;
    }
};