// Brute force

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        int n = haystack.size();
        for (int i = 0; i < n; ++i) {
            if (needle[0] == haystack[i]) {
                int curI = i;
                int len = 1;
                while (len < needle.size() and curI + len < n and
                       needle[len] == haystack[curI + len]) {
                    ++len;
                }
                if (len == needle.size()) {
                    return i;
                }
            }
        }
        return -1;
    }
};


// CMP solution 
// O(n)

class Solution {
public:
    
    vector<int> prefix(string s) {
        int n = s.size();
        vector<int> pi(n, 0);
        int j = 0;
        for (int i = 1; i < n; ++i) {
            j = pi[i - 1];
            while (j > 0 and s[i] != s[j]) {
                j = pi[j - 1];
            }
            if (s[i] == s[j]) {
                ++j;
            }
            pi[i] = j;
        }
        return pi;
    }
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        int n = haystack.size();
        string s = needle + "#" + haystack;
        auto pi = prefix(s);
        for (int i = needle.size() + 1; i < pi.size(); ++i) {
            if (pi[i] == needle.size()) {
                return i - 2 * needle.size();
            }
        }
        return -1;
    }
};
