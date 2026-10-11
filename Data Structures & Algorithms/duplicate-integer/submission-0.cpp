class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        return unordered_set <int> (nums.begin(),nums.end()).size() < nums.size(); //since the set automatically excludes duplicates so if there are duplicate the size would be less hence it would return true
    }
};