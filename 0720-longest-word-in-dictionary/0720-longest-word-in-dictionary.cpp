#include <bits/stdc++.h>
using namespace std;

class Trie {
    struct Node {
        Node* child[26];
        int endCount;
        int prefixCount;

        Node() {
            for (int i = 0; i < 26; i++) child[i] = nullptr;
            endCount = 0;
            prefixCount = 0;
        }
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(const string& word) {
        Node* node = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (node->child[idx] == nullptr) {
                node->child[idx] = new Node();
            }

            node = node->child[idx];
            node->prefixCount++;
        }

        node->endCount++;
    }

    bool search(const string& word) {
        Node* node = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (node->child[idx] == nullptr) {
                return false;
            }

            node = node->child[idx];
        }

        return node->endCount > 0;
    }

    bool startsWith(const string& prefix) {
        Node* node = root;

        for (char ch : prefix) {
            int idx = ch - 'a';

            if (node->child[idx] == nullptr) {
                return false;
            }

            node = node->child[idx];
        }

        return true;
    }

    int countWordsEqualTo(const string& word) {
        Node* node = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (node->child[idx] == nullptr) {
                return 0;
            }

            node = node->child[idx];
        }

        return node->endCount;
    }

    int countWordsStartingWith(const string& prefix) {
        Node* node = root;

        for (char ch : prefix) {
            int idx = ch - 'a';

            if (node->child[idx] == nullptr) {
                return 0;
            }

            node = node->child[idx];
        }

        return node->prefixCount;
    }

    void erase(const string& word) {
        if (!search(word)) return;

        Node* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            node = node->child[idx];
            node->prefixCount--;
        }

        node->endCount--;
    }
};
class Solution {
public:
    bool static comp(const string& a,const string& b){
        if(a.size()==b.size()) return b>a;
        return b.size()>a.size();
    }
    string longestWord(vector<string>& words) {
        Trie tr;
        for(auto& w:words){
            tr.insert(w);
        }
        sort(words.begin(),words.end(),comp);
        int n = words.size();
        unordered_map<string,bool> mpp;
        for(auto& w:words){
            if(w.size()==1) mpp[w] = true;
            else mpp[w] = false;
        }
        if(words[0].size()!=1) return "";
        string ans = words[0];
        for(int i=0;i<n;i++){
            if(!mpp[words[i]]) continue;
            for(int j=0;j<26;j++){
                char c = 'a' + j;
                string temp = words[i];
                temp += c;
                if(mpp.find(temp)!=mpp.end()){
                    mpp[temp] = true;
                    if(temp.size()>ans.size()){
                        ans = temp;
                    }
                }
            }
        }
        return ans;
    }
};