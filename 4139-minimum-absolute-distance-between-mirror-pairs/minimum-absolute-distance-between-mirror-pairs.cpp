
class Solution {
public:
    int reverseNum(int x) {
        int rev = 0;

        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> pos;
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (pos.count(nums[i])) {
                ans = min(ans, i - pos[nums[i]]);
            }

            pos[reverseNum(nums[i])] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
