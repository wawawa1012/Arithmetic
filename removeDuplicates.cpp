//
// Created by A on 2026/4/6.
//
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> st;
        for (char c:s)
        {
            if (!st.empty()&&st.top()==c)
            {
                st.pop();
                continue;
            }
            st.push(c);
        }
        string res = ""; // 这个就是你的手提袋
        while (!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

int main()
{
    Solution sol;
    cout << "测试 1 (预期 ca): " << sol.removeDuplicates("abbaca") << endl;
    cout << "测试 2 (预期 a): " << sol.removeDuplicates("azxxzy") << endl;
    return 0;
}
