class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;

        vector<int> f1(26, 0), f2(26, 0);

        // frequency of s1
        for (char c : s1) {
            f1[c - 'a']++;
        }

        // first window
        for (int i = 0; i < n; i++) {
            f2[s2[i] - 'a']++;
        }

        // check first window
        if (f1 == f2) return true;

        // sliding window
        for (int i = n; i < m; i++) {
            // add new character
            f2[s2[i] - 'a']++;

            // remove old character
            f2[s2[i - n] - 'a']--;

            // compare
            if (f1 == f2) return true;
        }

        return false;
    }
};