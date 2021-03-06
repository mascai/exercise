/*
A valid encoding of an array of words is any reference string s and array of indices indices such that:

words.length == indices.length
The reference string s ends with the '#' character.
For each index indices[i], the substring of s starting from indices[i] and up to (but not including) the next '#' character is equal to words[i].
Given an array of words, return the length of the shortest reference string s possible of any valid encoding of words.

 

Example 1:

Input: words = ["time", "me", "bell"]
Output: 10
Explanation: A valid encoding would be s = "time#bell#" and indices = [0, 2, 5].
words[0] = "time", the substring of s starting from indices[0] = 0 to the next '#' is underlined in "time#bell#"
words[1] = "me", the substring of s starting from indices[1] = 2 to the next '#' is underlined in "time#bell#"
words[2] = "bell", the substring of s starting from indices[2] = 5 to the next '#' is underlined in "time#bell#"
Example 2:

Input: words = ["t"]
Output: 2
Explanation: A valid encoding would be s = "t#" and indices = [0].

 

Constraints:

1 <= words.length <= 2000
1 <= words[i].length <= 7
words[i] consists of only lowercase letters.
*/


// Soluton 1
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> s(begin(words), end(words));
        for (auto word : words) {
            for (int i = 1; i < word.size(); ++i) {
                if (s.find(word.substr(i)) != s.end()) {
                    s.erase(word.substr(i));
                }
            }
        }
        int res = 0;
        for (auto word : s) {
            res += word.size() + 1;
        }
        return res;
    }
};

// Solution 2
class Solution {
public:
    struct Node {
       map <char, Node*> m;
    };
    
    int insertNode(Node* head, const string& s) {
        Node* curr = head;
        bool flag = false;
        for (int i = s.size() - 1; i >= 0; i--) {
            char x = s[i];
            if (not curr->m[x]) {
                curr->m[x] = new Node();
                flag = true;
            }
            curr = curr->m[x];
        }
        if (flag) {
            return s.size();
        }
        return 0;
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        sort(begin(words), end(words), [](string l, string r) {return l.size() > r.size();});
       
        int res = 0;
        Node* head = new Node();
        for (int i = 0; i < words.size(); ++i) {
            int temp = insertNode(head, words[i]);
            if (temp) {
                res += temp + 1;
            }
        }
        return res;
    }
};
