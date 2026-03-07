#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int sum_of_three_integers(int K, int N) {
    int z_count = 0;
    for (int x = 0; x <= K; x++) {
      for (int y = 0; y <= K; y++) {
        int complement = N - x - y;
        if (complement >= 0 && complement <= K) {
          z_count += 1;
        }
      }
    }

    return z_count;
  }
};

struct TestCase {
  int K;
  int N;
  int expected;
};

void run_test() {
  vector<TestCase> test_cases = {{2, 2, 6},    {1, 0, 1}, {1, 3, 1}, {1, 4, 0},
                                 {2, 3, 7},    {2, 6, 1}, {3, 8, 3}, {5, 15, 1},
                                 {10, 20, 66}, {5, 15, 1}};

  Solution solution;
  for (const auto &test_case : test_cases) {
    assert(solution.sum_of_three_integers(test_case.K, test_case.N) ==
           test_case.expected);
  }
}

int main() {
  run_test();
  cout << "test cases ready" << endl;
}
