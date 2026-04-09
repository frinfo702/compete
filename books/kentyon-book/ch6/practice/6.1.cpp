#include <iostream>
#include <vector>

class Solution {
public:
  int binary_search(std::vector<int> a, int key) {
    int left = 0;
    int right = (int)a.size() - 1;
    while (right >= left) {
      int mid = left + (right - left) / 2;
      if (a[mid] == key) {
        return mid;
      } else if (a[mid] > key) {
        right = mid - 1;
      } else if (a[mid] < key) {
        left = mid + 1;
      }
    }

    return -1;
  }
};

int main() {
  Solution s;
  int N = 8;
  std::vector<int> a = {3, 5, 8, 10, 14, 17, 21, 39};

  std::cout << s.binary_search(a, 10) << std::endl;
  std::cout << s.binary_search(a, 3) << std::endl;
  std::cout << s.binary_search(a, 39) << std::endl;

  std::cout << s.binary_search(a, -100) << std::endl;
  std::cout << s.binary_search(a, 9) << std::endl;
  std::cout << s.binary_search(a, 100) << std::endl;

  return 0;
}
