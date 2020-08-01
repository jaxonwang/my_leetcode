#include <iostream>
#include <limits>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:

  int get_p_num(int start, int s_size, vector<vector<bool>>&tb, unordered_map<int, int> &m){
      if(start == s_size - 1)
          return 1;
      if (m.count(start)>0)
          return m[start];
      if(tb[s_size - start][start])
          return 1;

      int min_c = numeric_limits<int>::max();
        for (int j = 1; start + j < s_size; j++) {
            if(tb[j][start]){
                min_c = min(get_p_num(start + j, s_size, tb, m), min_c);
            }
        }
      min_c++;
      m[start] = min_c;
      return min_c;
  }

  int minCut(string s) {
    int s_size = s.size();
    if (s_size == 0)
        return 1;
    vector<vector<bool>> tb;
    for (int i = 0; i < s_size+1; i++) {
        vector<bool> tmp((size_t)s_size);
        tb.push_back(move(tmp));
    }

    for (int i = 0; i < s_size; i++) {
      tb[0][i] = true;
      tb[1][i] = true;
    }
    
    for (int j = 2; j <= s_size; j++) {
      for (int i = 0; i + j - 1 < s_size; i++) {
        tb[j][i] = tb[j - 2][i + 1] && s[i] == s[i + j - 1] ? true : false;
      }
    }

    unordered_map<int, int> m;
    return get_p_num(0, s_size, tb, m)-1;
  }
};

int main(int argc, const char *argv[]) {
  string tmp = "abb";
  cout << Solution().minCut(tmp) << endl;
  tmp = "bb";
  cout << Solution().minCut(tmp) << endl;
  tmp = "leet";
  cout << Solution().minCut(tmp) << endl;

  return 0;
}
