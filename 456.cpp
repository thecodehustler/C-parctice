#include <iostream>
#include <vector>

using namespace std;

// 231Pattern

/* bool find132pattern(vector<int> &nums)
{
  vector<int> stk;
  int n = nums.size();
  int l = -1e9;
  for (int i = n - 1; i >= 0; i--)
  {
    if (nums[i] < l)
      return true;
    while (stk.size() && stk.back() < nums[i])
    {
      l = stk.back();
      stk.pop_back();
    }
    stk.push_back(nums[i]);
  }
  return false;
} */

bool find132pattern(vector<int>& nums) {
  vector<int> st;
  for (int i = 0; i < nums.size(); i++) {
    for (int j = nums.size() - 1; j > i; j--) {
      if (st.empty() && nums[j] <= nums[i]) {
        continue;
      } else {
        if (!st.empty() && st.front() < nums[j]) {
          return true;
        } else {
          while (!st.empty() && st.back() <= nums[j]) {
            st.pop_back();
          }
        }
        st.push_back(nums[j]);
      }
    }
    st.clear();
  }
  return false;
}

int main() {
  // some code here.
  vector<pair<vector<int>, bool>> tests = {
      // make_pair<vector<int>, bool>({3,1,4,2}, true),
      // make_pair<vector<int>, bool>({-2,1,-2}, false),
      // make_pair<vector<int>, bool>({-2,1,1,-2,1,1}, false),
      // make_pair<vector<int>, bool>({1,0,1,-4,-3}, false),
      make_pair<vector<int>, bool>({1, 3, 2, 4, 5, 6, 7, 8, 9, 10}, true),

  };

  for (auto& x : tests) {
    cout << find132pattern(x.first) << ' ' << x.second << endl;
  }
  return 0;
}