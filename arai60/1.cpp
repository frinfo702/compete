#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> value_to_indice;

    for (int index = 0; index < nums.size(); index++) {
      int complement = target - nums[index];

      if (value_to_indice.find(complement) != value_to_indice.end()) {
        return {value_to_indice[complement], index};
      }
      value_to_indice[nums[index]] = index;
    }

    return {};
  }
};
