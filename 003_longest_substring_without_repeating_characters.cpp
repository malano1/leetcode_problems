class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char>unique;
        int max = 0;
        for(int i = 0; i < s.length(); i++){
            bool good = true;
            for(int j = 0; j < unique.size(); j++){
                if(s[i] == unique[j]){
                    i = i - unique.size() + 1;
                    good = false;
                    break;
                }       
            }
            if(good){
                unique.push_back(s[i]);
            }
            else{
                unique.clear();
                unique.push_back(s[i]);
            }
            if(unique.size() > max){
                max = unique.size();
            } 
        }
        return max;
    }
};