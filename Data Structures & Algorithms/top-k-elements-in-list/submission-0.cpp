class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(int num : nums){
            count[num]++;
        }
        vector<vector<int>> freq(nums.size()+1);
        for(const auto& entry : count){
            freq[entry.second].push_back(entry.first);
        }
        vector<int> res;
        for(int i=freq.size()-1; i>0;--i){   //pushing the numbers from top
            for(int n: freq[i]){
                res.push_back(n);
                if(res.size()==k)
                return res;
            }
        }
    }
};
