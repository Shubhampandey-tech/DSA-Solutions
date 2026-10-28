class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> freq;
        int n = arr.size();

        for (int x : arr) {
            freq[x]++;
            if (freq[x] * 4 > n) {
                return x;
            }
        }

        return -1;
    }
};