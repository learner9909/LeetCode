class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int total = 0;
        vector<int> freq(3,-1);
        for(int i=0;i<n;i++){
            freq[(s[i] & 31)-1] = i;
            total += min({freq[0],freq[1],freq[2]})+1;
        }
       return total;
    }
};