class TrieNode{
public:
    TrieNode **children;
    string seq;
    TrieNode(){
        children = new TrieNode*[26]();
        seq = "";
    }
};
class Solution {
public:
    TrieNode *buildTrie(vector<string> words){
        TrieNode *root = new TrieNode();
        for(auto &word: words){
            TrieNode *curr = root;
            for(auto &c: word){
                if(curr->children[c - 'a'] == NULL) curr->children[c - 'a'] = new TrieNode();
                curr = curr->children[c - 'a'];
            }
            curr->seq = word;
        }
        return root;
    }
    void dfs(vector<string> &res, vector<vector<char>> &board, int i, int j, TrieNode *node){
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return;
        char c = board[i][j];
        if(c == '#' || node->children[c - 'a'] == NULL) return;
        node = node->children[c - 'a'];
        string seq = node->seq;
        if(seq != ""){
            res.push_back(seq);
            node->seq = "";
        }
        board[i][j] = '#';
        dfs(res, board, i - 1, j, node);
        dfs(res, board, i, j - 1, node);
        dfs(res, board, i + 1, j, node);
        dfs(res, board, i, j + 1, node);
        board[i][j] = c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrie(words);
        vector<string> res;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                dfs(res, board, i, j, root);
            }
        }
        return res;
    }
};