#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 100000000;

class Solution {
public:
  int shift_only(vector<int> &nums) {
    int min_divisor_count = INF;

    for (int value : nums) {
      int divisor_count = 0;
      while (value % 2 == 0) {
        divisor_count += 1;
        value /= 2;
      }

      if (divisor_count < min_divisor_count) {
        min_divisor_count = divisor_count;
      }
    }

    return min_divisor_count;
  }
};

void run_test() {
  Solution solution;
  {
    vector<int> nums = {2, 4, 8};
    assert(solution.shift_only(nums) == 1);
  }
  {
    vector<int> nums = {1, 4, 8};
    assert(solution.shift_only(nums) == 0);
  }
  {
    vector<int> nums = {8, 12, 40};
    assert(solution.shift_only(nums) == 2);
  }
  {
    vector<int> nums = {5, 6, 8, 10};
    assert(solution.shift_only(nums) == 0);
  }
  {
    vector<int> nums = {382253568, 723152896, 37802240,
                        379425024, 404894720, 471526144};
    assert(solution.shift_only(nums) == 8);
  }
}
int main() {
  run_test();
  cout << "ok" << endl;
}
