
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int s_size = s.size();
    if (s_size == 0)
        return "";
    bool tb[s_size+1][s_size];
    for (int i = 0; i < s_size; i++) {
      tb[0][i] = true;
      tb[1][i] = true;
    }
    
    int max_j = 1;
    int max_i = 0;

    for (int j = 2; j <= s_size; j++) {
      for (int i = 0; i + j - 1 < s_size; i++) {
        tb[j][i] = tb[j - 2][i + 1] && s[i] == s[i + j - 1] ? true : false;
        if(j > max_j && tb[j][i]){
            max_j = j;
            max_i = i;
        }
      }
    }
    string ret{s, (size_t)max_i, (size_t)max_j};
    return ret;
  }
};

int main(int argc, const char *argv[]) {
  string tmp = "a";
  cout << Solution().longestPalindrome(tmp) << endl;

  return 0;
}
