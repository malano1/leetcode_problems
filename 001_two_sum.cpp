class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                //If target sum found at indicies i & j
                if(nums[i] + nums[j] == target){
                    output = {i,j};
                    break;
               } 
            }
        }
        //If no sum could be found to match target
        if(output.size() == 0){
            output = {0,0};
        }
        return output;
    }
};