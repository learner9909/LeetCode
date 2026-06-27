class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
       int count = 0;
       sort(nums.begin(),nums.end());
       int i=0,j=nums.size()-1;
       while(i<j){
        int sum = nums[i]+nums[j];
        if(sum==k){
            i++;
            j--;
            count++;
        }
        else if(sum<k) i++;
        else j--;
       }
       return count;
    }
};