#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int rows = board.size(), cols = board[0].size();

        // 1. 边境点名：遍历左右两列的边缘
        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);               // 左边缘
            if (board[i][cols - 1] == 'O') dfs(board, i, cols - 1); // 右边缘
        }

        // 2. 边境点名：遍历上下两行的边缘
        for (int j = 0; j < cols; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j);               // 上边缘
            if (board[rows - 1][j] == 'O') dfs(board, rows - 1, j); // 下边缘
        }

        // 3. 全图大清洗
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X'; // 没被 DFS 摸到的 O，死刑！
                } else if (board[i][j] == 'T') {
                    board[i][j] = 'O'; // 拿到免死金牌的 T，恢复平民身份！
                }
            }
        }
    }

private:
    // 特种部队：深度优先搜索 (顺藤摸瓜)
    void dfs(vector<vector<char>>& board, int r, int c) {
        int rows = board.size(), cols = board[0].size();
        
        // 越界了，或者遇到了 X，或者遇到了已经标记过的 T，直接回头！
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != 'O') {
            return;
        }

        // 发现活着的平民 O，立刻发免死金牌 T！
        board[r][c] = 'T';

        // 既然这个人安全，那他上下左右连着的兄弟也安全！派人继续往深处搜！
        dfs(board, r + 1, c); // 下
        dfs(board, r - 1, c); // 上
        dfs(board, r, c + 1); // 右
        dfs(board, r, c - 1); // 左
    }
};