#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            int curr = nums[i];

            // When multiplied by a negative number, max becomes min and min becomes max
            if (curr < 0) {
                swap(max_so_far, min_so_far);
            }

            max_so_far = max(curr, max_so_far * curr);
            min_so_far = min(curr, min_so_far * curr);

            result = max(result, max_so_far);
        }

        return result;
    }
};