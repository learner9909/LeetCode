class Solution {
public:
    long long sumAndMultiply(int n) {
        string s;
        int sum = 0;
        while(n>0){
            int ld = n%10;
            if(ld!=0){
                s += to_string(ld);
                sum += ld;
            }
            n /= 10;
        }
        reverse(s.begin(),s.end());
        int x = s.empty() ? 0: stoi(s);
        return 1LL*x*sum;
    }
};