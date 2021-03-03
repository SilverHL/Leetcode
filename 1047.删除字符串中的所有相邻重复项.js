/*
 * @lc app=leetcode.cn id=1047 lang=javascript
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
/**
 * @param {string} S
 * @return {string}
 */
var removeDuplicates = function(S) {
  const stack = [];
  for (const char of S) {
    let len = stack.length;
    if(len == 0) {
      stack.push(char);
    } else {
      if(char == stack[len-1]) {
        stack.pop();
      } else {
       stack.push(char)
      }
    }
  }
  return stack.join("");
}
// @lc code=end

