//
// Created by A on 2026/3/12.
//
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    string decodeString(string s)
    {
        //在遇到[时跨入新世界，要存档（将原来的数字及字符串压栈）
        stack<int> stINT;     // 记忆卡：存倍数
        stack<string> stSTR;  // 记忆卡：存旧世界的字符串

        int currNum = 0;      // 数字背包
        string currSTR = "";  // 字符串背包
        for (int i=0;i<s.size();i++)
        {
            char c=s[i];
            if (isdigit(c)) {
                // 1. 黄金数字累加公式
                currNum = currNum * 10 + (c - '0');
            }
            else if (c == '[') {
                // 2. 【遇到传送门】：立刻存档！
                stINT.push(currNum);
                stSTR.push(currSTR);
                // 存完档，清空背包，轻装进入副本！
                currNum = 0;
                currSTR = "";
            }
            else if (c == ']') {
                // 3. 【打穿副本】：读档清算！
                int repeatTimes = stINT.top(); // 拿出倍数
                stINT.pop();

                string pastSTR = stSTR.top();  // 拿出旧世界的进度
                stSTR.pop();

                // 把当前副本里打到的怪 (currSTR)，复制 repeatTimes 遍
                string temp = "";
                for (int k = 0; k < repeatTimes; k++) {
                    temp += currSTR;
                }

                // 终极拼接：旧世界的进度 + 刚刚复制完的副本产出，塞回背包！
                currSTR = pastSTR + temp;
            }
            else {
                // 4. 普通字母：直接塞进背包
                currSTR += c;
            }
        }
        return currSTR;
    }
};
