class WordDictionary {
    struct Node{
        Node* child[26];
        int pc;
        int ec;

        Node(){
            for(int i=0;i<26;i++) child[i] = nullptr;
            ec = 0;
        }
    };
    Node* root;
public:
    WordDictionary() {
        root = new Node;
    }
    
    void addWord(string word) {
        Node* node = root;
        for(auto w:word){
            int i = w-'a';
            if(node->child[i]==nullptr){
                node->child[i] = new Node();
            }
            node = node->child[i];
            node->pc++;
        }
        node->ec++;
    }
    
    bool solve(int idx,string& word,Node* node){
        if(idx>=word.size()) return node->ec>0;

        bool ans = false;
        if(word[idx]=='.'){
            for(int i=0;i<26;i++){
                if(node->child[i]!=nullptr){
                    ans = ans | solve(idx+1,word,node->child[i]);
                }
            }
        }
        else{
            int i = word[idx]-'a';
            if(node->child[i]==nullptr) return false;
            return solve(idx+1,word,node->child[i]);
        }
        return ans;
    }

    bool search(string word) {
        Node* node = root;
        return solve(0,word,node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */