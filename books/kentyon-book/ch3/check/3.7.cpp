#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int many_formulas(string s) {
    int n = s.size();
    long long ans = 0;

    for (int bit = 0; bit < (1 << (n - 1)); bit++) {
      long long current = 0;

      for (int i = 0; i < n; i++) {
        int digit = s[i];
        current = current * 10 + (digit - '0');

        if (i == (n - 1) || bit & (1 << i)) {
          ans += current;
          current = 0;
        }
      }
    }

    return ans;
  }
};

struct TestCase {
  string s;
  long long expected;
};

void run_tests() {
  vector<TestCase> test_cases = {{"125", 176}, {"9999999999", 12656242944}};
}

int main() {
  run_tests();
  cout << "All complete" << endl;
}
