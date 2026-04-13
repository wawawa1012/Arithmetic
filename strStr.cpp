//
// Created by A on 2026/4/13.
//
#include <iostream>
#include <vector>
using namespace std;
//horspool算法
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        vector<int> shift =shiftTable(needle) ;
        int m = needle.size();
        int i=m-1;
        while (i<haystack.size()) //匹配结束前
        {
            int k=0; //匹配成功的字符数
            while (k<=m-1&&needle[m-1-k]==haystack[i-k])//恰好匹配某字符
            {
                k++;
            }
            if (k==m) return i-m+1;
            i+=shift[haystack[i]-'a'];
        }
        return -1;
    }

    vector<int> shiftTable(string needle)
    {
        int n = needle.size();
        vector<int> table(26, 0);
        for (int i = 0; i < 26; i++) table[i] = n;
        for (int j = 0; j < n - 1; j++) table[needle[j] - 'a'] = n - j - 1;
        return table;
    }
};
