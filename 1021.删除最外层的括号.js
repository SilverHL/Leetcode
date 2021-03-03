/*
 * @lc app=leetcode.cn id=1021 lang=javascript
 *
 * [1021] 删除最外层的括号
 */

// @lc code=start
/**
 * @param {string} S
 * @return {string}
 */
var removeOuterParentheses = function(S) {
  let sArr = S.split("");
  let stack = [];
  let outerIndex = [];

  for (let i = 0; i < sArr.length; i++) {
    if (sArr[i] == '(') {
      stack.push(i); 
    } else {
      let len = stack.length;
      if (len == 1) {
        outerIndex.push(stack[0], i);
      }
      stack.pop();
    }
  }
  
  let j = 0;
  let res = "";
  for (let i = 0; i < S.length; ++i) {
    if (j < outerIndex.length && outerIndex[j] == i) {
      j++;
      continue;
    } else {
      res += S[i];
    }
  }
  return res;
};
// @lc code=end

