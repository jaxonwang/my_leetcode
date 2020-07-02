#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
  bool isScramble(string s1, string s2) {
    if (s1.size() != s2.size())
      return false;
    if (s1.size() == 0)
      return true;
    return _isscramble(s1.c_str(), s2.c_str(), s1.size());
  }
  bool _isscramble(const char *s1, const char *s2, size_t n) {
    bool a[n + 1][n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[1][i][j] = s1[i] == s2[j] ? true : false;
      }
    }

    for (int len = 2; len <= n; len++) {
      for (int i = 0; i + len <= n; i++) {
        for (int j = 0; j + len <= n; j++) {
          a[len][i][j] = false;
          for (int tmplen = 1; tmplen < len; tmplen++) {
            if ((a[tmplen][i][j] && a[len - tmplen][i + tmplen][j + tmplen]) ||
                (a[tmplen][i + len - tmplen][j] && a[len-tmplen][i][j + tmplen])) {
              a[len][i][j] = true;
              break;
            }
          }
          cout << len<<" "<<i<<" "<<j<<" "<<a[len][i][j] << endl;
        }
      }
    }
    return a[n][0][0];
  }
};
int main(int argc, const char *argv[]) {
  cout << Solution().isScramble("hobobyrqd", "hbyorqdbo") << endl;
  return 0;
}
