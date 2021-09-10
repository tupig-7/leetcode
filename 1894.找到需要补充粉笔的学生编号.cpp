/*
 * @lc app=leetcode.cn id=1894 lang=cpp
 *
 * [1894] 找到需要补充粉笔的学生编号
 */

// @lc code=start
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        vector<long long> ans(n + 1, 0);
        for(int i = 1; i <= n; ++i) {
            ans[i] = ans[i - 1] + chalk[i - 1]; // 求前缀和
        }

        k %= ans[n];
        if(k == 0) {
            return 0;
        }
        return upper_bound(ans.begin(), ans.end(), k) - ans.begin() - 1;
    }
};
// @lc code=end

