#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    // 字典树
    typedef struct tr {
        struct tr* children[26];
        bool isEnd;
        tr() : children{nullptr}, isEnd(false) {}
    } Trie;

    int insertWord(Trie* root, const string& word) {
        const int len = word.length();
        int count = 0;
        if (len == 0) return 0;
        for (int i = 0; i < len; i++) {
            const int index = word[i] - 'a';
            if (!root->children[index]) {
                Trie* node = new Trie();
                root->children[index] = node;
            }
            root = root->children[index];
        }
        root->isEnd = true;
        return count;
    }

    bool contains(Trie* root, const char* word) {
        if (!root) return false;
        if (strlen(word) == 0) {
            return false;
        }
        for (int i = 0; i < strlen(word); i++) {
            const int index = word[i] - 'a';
            if (!root->children[index]) return false;
            root = root->children[index];
        }
        return true;
    }

    static bool compare(string& s1, string& s2) { return s1.length() < s2.length(); }

    bool search(Trie* root, const char* str) {
        const int len = strlen(str);
        Trie* node = root;
        if (len == 0) return true;

        for (int i = 0; i < len; i++) {
            const int index = str[i] - 'a';
            node = node->children[index];
            if (!node)
                return false;
            else if (node->isEnd) {
                if (search(root, str + i + 1)) return true;
            }
        }
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), Solution::compare);
        vector<string> answer;
        Trie tr;
        for (string& word : words) {
            if (word.length() == 0) continue;
            if (!search(&tr, word.c_str())) {
                cout << "Adding word: " << word << endl;
                insertWord(&tr, word);
            } else {
                cout << "Answer pushed: " << word << endl;
                answer.push_back(word);
            }
        }
        return answer;
    }
};

int main() {
    Solution sln;
    vector<string> strs = {"cat",        "cats",           "catsdogcats", "dog",
                           "dogcatsdog", "hippopotamuses", "rat",         "ratcatdogcat"};
    vector<string> ans = sln.findAllConcatenatedWordsInADict(strs);
    return 0;
}