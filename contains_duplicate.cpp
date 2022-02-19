class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(sizeof(nums) < 2) return false;
        //Sort Array to allow for a lower Big O of search
        sort(nums.begin(),nums.end());
        //Iterate through num vector
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                return true;
            }
        }
        return false;
    }
};