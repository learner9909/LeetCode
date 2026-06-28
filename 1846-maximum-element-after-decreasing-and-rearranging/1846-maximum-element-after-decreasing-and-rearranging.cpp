class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(nums[0]!=1) nums[0]=1;
        for(int i=1;i<n;i++){
            if(abs(nums[i]-nums[i-1])>1){
                nums[i]=nums[i-1]+1;
            }
        }
        int max_ele = INT_MIN;
        for(int i=0;i<n;i++){
            max_ele = max(max_ele,nums[i]);
        }
        return max_ele;
    }
};