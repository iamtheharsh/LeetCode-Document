/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> mpp;
    Node* dfs(Node* root){
        if(mpp.find(root)!=mpp.end()) return mpp[root];
        Node* temp = new Node(root->val);
        mpp[root] = temp;
        for(auto bt:root->neighbors){
            temp->neighbors.push_back(dfs(bt));
        }
        return temp;
    }
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        return dfs(node);
    }
};