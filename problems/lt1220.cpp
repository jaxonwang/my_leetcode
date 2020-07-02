#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  constexpr static int size = 5;
  const int mod = 1e9 + 7;
  void assgin(int *c, const int *a) { memcpy(c, a, size * size * sizeof(int)); }
  void multi(int *c, const int *a, const int *b) {
    int tmp[size * size];
    int *c_ = (c == a || c == b) ? tmp : c;

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        unsigned long long v = 0;
        for (int k = 0; k < size; k++) {
          v += static_cast<unsigned long long>(a[i * size + k]) *
               static_cast<unsigned long long>(b[k * size + j]) ;
        }
        c_[i * size + j] = static_cast<int>(v % mod);
      }
    }
    if (c_ != c)
      assgin(c, c_);
  }
  void square(int *c, const int *a) { multi(c, a, a); }
  void power(int *c, const int *a, int exp) {
    if (exp == 1) {
      assgin(c, a);
      return;
    }
    power(c, a, exp / 2);
    square(c, c);
    if (exp % 2 != 0) {
      multi(c, c, a);
    }
  }
  int countVowelPermutation(int n) {
    if (n == 0)
      return 0;
    if (n == 1)
      return 5;
    const int m[size * size] = {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0,
                                1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0};
    int c[size * size] = {0};
    power(c, m, n - 1);
    int sum = 0;
    for (int i = 0; i < size * size; i++) {
      sum += c[i];
      sum %= mod;
    }
    return sum;
  }
};

int main() {
  int a = Solution().countVowelPermutation(20000);
  cout << a << endl;
}
