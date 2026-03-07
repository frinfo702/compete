#include <algorithm>
#include <cassert>
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

class Solution {
public:
  int max_complement(vector<int> &nums) {
    if (nums.size() < 1) {
      throw invalid_argument("nums must have at least 2 elements");
    }
    vector<int>::iterator max_value = max_element(nums.begin(), nums.end());
    vector<int>::iterator min_value = min_element(nums.begin(), nums.end());

    int largest_comp = *max_value - *min_value;

    return largest_comp;
  }
};

void run_test() {
  Solution solution;
  {
    vector<int> nums = {1, 2, 4, 10};
    assert(solution.max_complement(nums) == 9);
  }
  {
    vector<int> nums = {-10, -3, -1, -20};
    assert(solution.max_complement(nums) == 19);
  }
  {
    vector<int> nums = {-5, 0, 12, 9};
    assert(solution.max_complement(nums) == 17);
  }
  {
    vector<int> nums = {7, 7, 7, 7};
    assert(solution.max_complement(nums) == 0);
  }
  {
    vector<int> nums = {100, -100};
    assert(solution.max_complement(nums) == 200);
  }
  {
    vector<int> nums = {42};
    assert(solution.max_complement(nums) == 0);
  }
}

int main() {
  run_test();
  cout << "ok" << endl;
}
