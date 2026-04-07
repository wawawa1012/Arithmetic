//
// Created by A on 2026/4/7.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (int asteroid:asteroids)
        {
            bool alive=true;//判断当前行星是否存活，后面就不用加繁琐的判断了
            while (alive&&!res.empty()&&asteroid<0&&res.back()>0)//发生碰撞的条件
            {
                int curr=abs(asteroid);
                int prev=res.back();
                if (curr==prev)
                {
                    res.pop_back();
                    alive=false;
                }
                if (curr<prev)
                {
                    alive=false;
                } //什么都不做
                if (curr>prev)
                {
                    res.pop_back();
                }
            }
            if (alive) res.push_back(asteroid);
        }


        return res;
    }
};

int main() {
    Solution sol;

    vector<int> a1 = {5, 10, -5};
    vector<int> r1 = sol.asteroidCollision(a1);
    cout << "测试 1 (预期 5 10): ";
    for (int x : r1) cout << x << " "; cout << endl;

    vector<int> a2 = {10, 2, -5};
    vector<int> r2 = sol.asteroidCollision(a2);
    cout << "测试 2 (预期 10): ";
    for (int x : r2) cout << x << " "; cout << endl;

    vector<int> a3 = {-2, -1, 1, 2};
    vector<int> r3 = sol.asteroidCollision(a3);
    cout << "测试 3 (预期 -2 -1 1 2): ";
    for (int x : r3) cout << x << " "; cout << endl;

    return 0;
}