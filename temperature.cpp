//
// Created by A on 2026/3/11.
//
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st; // 悬案室，只存日子（索引）

        for (int i = 0; i < n; i++) {
            // 今天的温度，来悬案室踢门了！
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int d = st.top(); // 抓出一个苦主
                st.pop();         // 案件了结，请他出悬案室
                answer[d] = i - d; // 精准填入属于他的那一格：等待天数 = 今天(i) - 苦主的日期(d)
            }
            // 踢门结束（或者根本没踢开），自己乖乖进去当悬案
            st.push(i);
        }
        return answer;
    }
};
//以下是brute force
/*class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int days=0;
        bool is_higher=false;
        vector<int> answer;
        for (int i=0;i<temperatures.size();i++)
        {
            is_higher=false;
            for (int j=i+1;j<temperatures.size();j++)
            {
                if (temperatures[i]<temperatures[j])
                {
                    days=j-i;
                    is_higher=true;
                    break;
                }
            }
            answer.push_back(is_higher?days:0);
        }
        return answer;
    }
};*/