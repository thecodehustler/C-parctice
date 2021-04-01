#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  static bool find132pattern(vector<int>& nums) {
    vector<int> st;  // 今天又是单调栈的一天，但是今天呢是单调递增栈。
    for (int& x : nums) {
      while (!st.empty() && x < st.back()) {
        if (st.size() >= 2) {
          if (st.front() >= x) {
            break;
          } else {
            return true;
          }
        }
        st.pop_back();
      }
      st.push_back(x);
    }
    return false;
  }
};

int main() {
  vector<pair<vector<int>, bool>> vec = {
      make_pair<vector<int>, bool>({1, 0, 1, -4, -3}, false),
      make_pair<vector<int>, bool>({3, 5, 0, 3, 4}, true)};
  for (pair<vector<int>, bool>& x : vec) {
    cout << Solution::find132pattern(x.first) << ' ' << x.second << endl;
  }
  return 0;
}
