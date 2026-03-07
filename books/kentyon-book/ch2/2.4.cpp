#include <cmath>
#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

double calc_dist(double x1, double y1, double x2, double y2) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
  int N;
  cin >> N;
  vector<double> x(N), y(N);
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i];
  }

  double min_dict = 1000000000.0;

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      double dict = calc_dist(x[i], y[i], x[j], y[j]);

      if (dict < min_dict) {
        min_dict = dict;
      }
    }
  }

  cout << min_dict << endl;
}
