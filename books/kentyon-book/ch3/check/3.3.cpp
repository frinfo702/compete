#include <cassert>
#ifdef LOCAL_TEST
#include <iostream>
#endif
#include <vector>

using namespace std;

const int INF = 1000000000;

class Solution {
public:
  int secondSmallest(vector<int> &nums) {
    int smallest = INF;
    int second_smallest = INF;

    for (int value : nums) {
      if (value < smallest) {
        second_smallest = smallest;
        smallest = value;
        continue;
      }
      if (value < second_smallest) {
        second_smallest = value;
      }
    }

    return second_smallest;
  }
};

void run_tests() {
  Solution solution;

  {
    vector<int> nums = {1, 2};
    assert(solution.secondSmallest(nums) == 2);
  }
  {
    vector<int> nums = {2, 1};
    assert(solution.secondSmallest(nums) == 2);
  }
  {
    vector<int> nums = {5, 3, 4};
    assert(solution.secondSmallest(nums) == 4);
  }
  {
    vector<int> nums = {10, -3, 7, 2};
    assert(solution.secondSmallest(nums) == 2);
  }
  {
    vector<int> nums = {9, 8, 7, 6, 5};
    assert(solution.secondSmallest(nums) == 6);
  }
}

#ifdef LOCAL_TEST
int main() {
  run_tests();
  cout << "OK" << endl;
}
#endif
