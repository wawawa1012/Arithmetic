//
// Created by A on 2026/3/21.
//
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses); //图，记录前驱后继关系
        vector<int> in_degree(numCourses, 0);//入度数组

        for (const auto pre:prerequisites)
        {
            int course=pre[0]; //后继
            int prerequisite=pre[1]; //前驱

            graph[prerequisite].push_back(course);
            in_degree[course]++; //入度+1
        }

        queue<int> q;//队列，入度为零进入，若队列清空而入度数组仍不全为零则无法拓扑排序
        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }
        int learnt=0;
        while (!q.empty())
        {
            int curr=q.front();//记录要被弹出的课程，准备操作与其相关的一系列课程
            q.pop();
            learnt++;
            for (const auto nextCourse:graph[curr])
            {
                in_degree[nextCourse]--;
                if (in_degree[nextCourse] == 0) q.push(nextCourse);
            }
        }
        return learnt == numCourses;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> prerequisites = {{1, 0}}; // 学1必须先学0
    bool result = sol.canFinish(2, prerequisites);
    cout<<result;
    return 0; // 在这里打个断点，就能 DEBUG 了！
}