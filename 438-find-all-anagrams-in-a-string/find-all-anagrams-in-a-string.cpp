class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;

        int n = s.size(), m = p.size();
        if (m > n) return res;

        vector<int> freq(26, 0);

        // build freq for p
        for (char c : p) {
            freq[c - 'a']++;
        }

        int left = 0, right = 0;
        int count = m;

        while (right < n) {

            // include current char
            if (freq[s[right] - 'a'] > 0)
                count--;

            freq[s[right] - 'a']--;
            right++;

            // if all matched
            if (count == 0)
                res.push_back(left);

            // maintain window size
            if (right - left == m) {

                if (freq[s[left] - 'a'] >= 0)
                    count++;

                freq[s[left] - 'a']++;
                left++;
            }
        }

        return res;
    }
};