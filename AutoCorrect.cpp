class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }
    
    TrieNode* search(TrieNode* root,string pattern){
        if(pattern.size()==0){
            return root;
        }
        int index = pattern[0]-'a';
       	TrieNode* child = root->children[index];
        if(child !=NULL){
            TrieNode* ans = search(child, pattern.substr(1));
            return ans;
        }
        else{
            return NULL;
        }
    }
    
    
    TrieNode * search(string pattern){
        return search(root, pattern);
    }
    
    void printallwords(TrieNode* ans, string pattern){
        if(ans->isTerminal == true){
            cout << pattern << endl;
        }
        for(int i=0;i<26;i++){
            if(ans->children[i]!=NULL){
                printallwords(ans->children[i], pattern+ans->children[i]->data);
            }
        }
    }

    void autoComplete(vector<string> input, string pattern) {
        // Write your code here
        for(int i=0;i<input.size();i++){
            insertWord(input[i]);
        }
        TrieNode* ans = search(pattern);
        if(ans !=NULL){
            printallwords(ans,pattern);
        }
        else{
            return;
        }
        
    }
};
