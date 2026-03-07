// 核心思路：回溯法 (Backtracking)
// 1. 第一行随便放
// 2. 第二行、第三行依次判断条件
// 3. 如果某行无法满足，回溯到上一行重新放

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

constexpr int MAX_SIZE = 8; // 8皇后

// 记录皇后的坐标
struct queen {
    int row, column;
};

class Solution {
private:
    vector<queen> queens;  // 记录当前棋盘上已经放置的皇后
    int solutionCount = 0; // 解法计数器

    // 判断当前坐标 (r, c) 是否安全（是否满足条件）
    bool is_safe(int r, int c) {
        for (int i = 0; i < queens.size(); i++) {
            // 判断同列是否有冲突 (同行不需要判断，因为我们是一行行向下推的)
            if (queens[i].column == c) return false;

            // 判断斜线是否有冲突 (横向距离 == 纵向距离)
            int distX = abs(c - queens[i].column);
            int distY = abs(r - queens[i].row);
            if (distX == distY) return false;
        }
        return true;
    }

    // 执行回溯的核心递归函数
    void trace_back(int r) {
        // 终结条件：如果已经成功推进到了第 8 行，说明找到了一种解
        if (r == MAX_SIZE) {
            solutionCount++;
            return;
        }

        // 遍历当前行的每一列
        for (int c = 0; c < MAX_SIZE; c++) {
            if (is_safe(r, c)) {
                // 推进：满足条件，放置皇后
                queens.push_back({r, c});

                // 递归：进入下一行继续判断
                trace_back(r + 1);

                // 回溯：从下一行退回来后，无论成功与否，都要把刚才放的皇后拿掉，尝试本行的下一个位置
                queens.pop_back();
            }
        }
    }

public:
    void solve() {
        trace_back(0); // 从第 0 行开始运行
        cout << "Total solutions for " << MAX_SIZE << "-Queens: " << solutionCount << endl;
    }
};

int main() {
    Solution s;
    s.solve();
    return 0;
}