class Solution {
public:

    class TrieNode {
    public:

        TrieNode* children[26];
        bool isTerminal;
        string word;

        TrieNode() {
            isTerminal = false;
            word = "";

            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };


    void insert(TrieNode* root, string& word) {

        TrieNode* curr = root;

        for (char ch : word) {

            int index = ch - 'a';

            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }

        curr->isTerminal = true;
        curr->word = word;
    }


    void backtrack(
        vector<vector<char>>& board,
        int row,
        int col,
        TrieNode* node,
        vector<string>& ans
    ) {

        // Boundary check
        if (row < 0 || row >= board.size() ||
            col < 0 || col >= board[0].size()) {
            return;
        }

        // Already visited
        if (board[row][col] == '#') {
            return;
        }

        char ch = board[row][col];

        // Check whether this character exists in Trie
        TrieNode* next = node->children[ch - 'a'];

        if (next == nullptr) {
            return;
        }

        // Found a complete word
        if (next->isTerminal) {

            ans.push_back(next->word);

            // Prevent duplicate result
            next->isTerminal = false;
        }

        // Mark visited
        board[row][col] = '#';

        // Explore four directions
        backtrack(board, row - 1, col, next, ans);
        backtrack(board, row + 1, col, next, ans);
        backtrack(board, row, col - 1, next, ans);
        backtrack(board, row, col + 1, next, ans);

        // Backtrack
        board[row][col] = ch;
    }


    vector<string> findWords(
        vector<vector<char>>& board,
        vector<string>& words
    ) {

        vector<string> ans;

        if (board.empty()) {
            return ans;
        }

        // Create Trie
        TrieNode* root = new TrieNode();

        // Insert all words
        for (string& word : words) {
            insert(root, word);
        }

        // DFS from every board cell
        for (int row = 0; row < board.size(); row++) {

            for (int col = 0; col < board[0].size(); col++) {

                backtrack(
                    board,
                    row,
                    col,
                    root,
                    ans
                );
            }
        }

        return ans;
    }
};