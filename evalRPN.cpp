//
// Created by A on 2026/3/11.
//
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto &token:tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                int r_num=st.top();//右操作数
                st.pop();
                int l_num=st.top();//左操作数
                st.pop();
                int num;
                // 直接拿字符串的第一个字符 (char) 去匹配，十分简洁
                switch (token[0]) {
                case '+': num = l_num + r_num; break;
                case '-': num = l_num - r_num; break;
                case '*': num = l_num * r_num; break;
                case '/': num = l_num / r_num; break;
                }
                st.push(num);//（中间）结果压栈
            }
            else
            {
                st.push(stoi(token));//stoi函数转成数字再压栈
            }
        }
        return st.top();
    }
};