class Solution {
public:
    bool isAnagram(string s1,string s2){
        if(s1.length()!=s2.length()) return false;
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        return s1==s2;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            vector<string> anagram;
            anagram.push_back(strs[i]);
            visited[i]=true;
            for(int j=i+1;j<n;j++){
                if(!visited[j] && isAnagram(strs[i],strs[j])){
                    anagram.push_back(strs[j]);
                    visited[j] = true;
                }
            }
            ans.push_back(anagram);
        }
        return ans;
    }
};