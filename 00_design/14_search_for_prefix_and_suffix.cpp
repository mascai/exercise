/*
https://leetcode.com/explore/featured/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3728/

Design a special dictionary which has some words and allows you to search the words in it by a prefix and a suffix.

Implement the WordFilter class:

WordFilter(string[] words) Initializes the object with the words in the dictionary.
f(string prefix, string suffix) Returns the index of the word in the dictionary which has the prefix prefix and the suffix suffix. If there is more than one valid index, return the largest of them. If there is no such word in the dictionary, return -1.
 

Example 1:

Input
["WordFilter", "f"]
[[["apple"]], ["a", "e"]]
Output
[null, 0]

Explanation
WordFilter wordFilter = new WordFilter(["apple"]);
wordFilter.f("a", "e"); // return 0, because the word at index 0 has prefix = "a" and suffix = 'e".
 

Constraints:

1 <= words.length <= 15000
1 <= words[i].length <= 10
1 <= prefix.length, suffix.length <= 10
words[i], prefix and suffix consist of lower-case English letters only.
At most 15000 calls will be made to the function f.

*/


struct Node {
    Node() {
        children_.resize(26);
    }
    
    void add(const string& word, size_t begin, int index) {
        wordIndexes_.push_back(index);
        if (begin < word.length()) {
            if (not children_[word[begin] - 'a']) {
                children_[word[begin] - 'a'] = make_unique<Node>();
            }
            children_[word[begin] - 'a']->add(word, begin + 1, index);
        }
    }
    
    vector<int> find(const string& prefix, size_t begin) {
        if (begin == prefix.size()) {
            return wordIndexes_;
        } else {
            if (not children_[prefix[begin] -'a']) {
                return {};
            } else {
                return children_[prefix[begin] -'a']->find(prefix, begin + 1);
            }
        }
    }
    
private:
    vector<int> wordIndexes_;
    vector<unique_ptr<Node>> children_;
};

class WordFilter {
public:
    WordFilter(vector<string>& words) {
        forwardTrie_ = make_unique<Node>();
        backwardTrie_ = make_unique<Node>();
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            forwardTrie_->add(word, 0, i);
            
            reverse(word.begin(), word.end());
            backwardTrie_->add(word, 0, i);
        }
    }
    
    int f(string prefix, string suffix) {
        const auto& forwardMatch = forwardTrie_->find(prefix, 0);
        reverse(suffix.begin(), suffix.end());
        const auto& backwardMatch = backwardTrie_->find(suffix, 0);

        auto fIter = forwardMatch.rbegin(), bIter = backwardMatch.rbegin();
        while (fIter != forwardMatch.rend() && bIter != backwardMatch.rend()) {
            if (*fIter == *bIter) {
                return *fIter;
            } else if (*fIter > *bIter) {
                fIter++;
            } else {
                bIter++;
            }
        }
        return -1;
    }
private:
    unique_ptr<Node> forwardTrie_;
    unique_ptr<Node> backwardTrie_;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
