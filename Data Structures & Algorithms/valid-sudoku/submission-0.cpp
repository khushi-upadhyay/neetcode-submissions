class Solution {
   public:
    bool validBox(vector<vector<char>>& board, int sr, int er, int sc, int ec) {
        unordered_set<char> seen;
        for (int i = sr; i < er; i++) {
            for (int j = sc; j < ec; j++) {
                if (board[i][j] == '.') continue;
                if (seen.count(board[i][j])) return false;
                seen.insert(board[i][j]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; i++) {
            unordered_set<char> seen;
            for (int j = 0; j < col; j++) {
                if (board[i][j] == '.') continue;
                if (seen.count(board[i][j])) return false;
                seen.insert(board[i][j]);
            }
        }
        for (int j = 0; j < col; j++) {
            unordered_set<char> seen;
            for (int i = 0; i < row; i++) {
                if (board[i][j] == '.') continue;
                if (seen.count(board[i][j])) return false;
                seen.insert(board[i][j]);
            }
        }
        // sr = starting row, er = ending row; sc = strating col; ec = ending col
        for (int sr = 0; sr < row; sr += 3) {
            int er = sr + 3;
            for (int sc = 0; sc < col; sc += 3) {
                int ec = sc + 3;
                if (!validBox(board, sr, er, sc, ec)) return false;
            }
        }
        return true;
    }
};
