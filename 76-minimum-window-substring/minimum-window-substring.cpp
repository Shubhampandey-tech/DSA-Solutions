class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need, window;

        // store frequency of t
        for(char c : t) need[c]++;

        int have = 0;
        int needCount = need.size();

        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        for(int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;

            if(need.count(c) && window[c] == need[c]) {
                have++;
            }

            // shrink window
            while(have == needCount) {
                // update result
                if((right - left + 1) < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // remove left char
                window[s[left]]--;
                if(need.count(s[left]) && window[s[left]] < need[s[left]]) {
                    have--;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};