#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    if (height.size() == 0)
          return 0;
    int *maxbefore_pos = new int[height.size()];
    int max = 0;
    int max_pos = 0;
    for (int i = 0; i < height.size(); i++) {
      if (height[i] >= max) {
        max = height[i];
        max_pos = i;
      }
      maxbefore_pos[i] = max_pos;
    }
    int *water = new int[height.size()]{};
    water[0] = height[0];
    int *maxbefore_pos_1 = new int[height.size()]{};

    for (int i = 1; i < height.size(); i++) {
      int max_b_pos = maxbefore_pos[i - 1];
      int max_b = height[max_b_pos];
      if (height[i] > max_b) {
        water[i] =
            water[max_b_pos] + (i - max_b_pos) * max_b + height[i] - max_b;
        maxbefore_pos_1[i] = i;
      } else {
        maxbefore_pos_1[i] = i - 1;
        int p;
        for (p = maxbefore_pos_1[i - 1]; height[p] < height[i];
            p = maxbefore_pos_1[p]) {
        }
        maxbefore_pos_1[i] = p;
        water[i] = water[maxbefore_pos_1[i]] + (i - maxbefore_pos_1[i]) * height[i];
      }
    }

    int trapped = water[height.size() - 1];
    for (int i = 0; i < height.size(); i++) {
      trapped -= height[i];
    }

    delete[] water;
    delete[] maxbefore_pos_1;
    delete[] maxbefore_pos;
    return trapped;
  }
};
int main(int argc, const char *argv[]) {
  vector<int> v = {2,0,2};
  cout << Solution().trap(v) << endl;
  return 0;
}
