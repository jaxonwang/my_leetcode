#include <iostream>

using namespace std;

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    auto s1_len = s1.size();
    auto s2_len = s2.size();
    if(s1_len+s2_len != s3.size())
        return false;
    bool a[s1_len + 1][s2_len + 1];
    a[0][0] = true;
    for (int i = 0; i < s2_len; i++) {
      a[0][i + 1] = a[0][i] && s3[i] == s2[i];
    }
    for (int i = 0; i < s1_len; i++) {
      a[i + 1][0] = a[i][0] && s3[i] == s1[i];
    }
    for (int i = 0; i < s1_len; i++) {
      for (int j = 0; j < s2_len; j++) {
        a[i + 1][j + 1] =
            (a[i + 1][j] && s2[j] == s3[i+j+1]) || (a[i][j + 1] && s1[i] == s3[i+j+1]);
      }
    }
    return a[s1_len][s2_len];
  }
};

int main(int argc, const char *argv[]) {
  string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
  cout << Solution().isInterleave(s1, s2, s3) << endl;
  return 0;
}
