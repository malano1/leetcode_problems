#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //Variables
        vector<int>::iterator ptr;
        vector<int> checked;
        int unique_count = 0;
        
        //Iterate through num vector
        for(ptr = nums.begin(); ptr < nums.end(); ptr++){
            //Using std::find() to find if *ptr value is in checked
            //If not in checked
            if(find(checked.begin(),checked.end(),*ptr)==checked.end()){
                //Push_back onto vector checked & increase count
                checked.push_back(*ptr);
                unique_count++;            }
            //If already in checked
            else{
                //Remove from nums vector
                nums.erase(ptr);
                //Erasing from vector causes ptr iteration to jump forward one, thus
                //Go back to check missed element
                ptr--;
            }
            
        }
        //Return amount of unique elements/values
        return unique_count;
    }
};