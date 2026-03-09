#include <iostream>
using namespace std;

int gcd(int m, int n) {
  int r = m % n;
  if (r == 0) {
    return n;
  }
  return gcd(n, r);
}

int main() {
  int m = 51;
  int n = 15;

  int ans = gcd(m, n);
  cout << ans << endl;

  return 0;
}
