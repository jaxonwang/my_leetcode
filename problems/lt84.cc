#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int largestRectangleArea(const vector<int> &heights) {
    int leftmost[heights.size()], rightmost[heights.size()], left, right;

    for (int i = heights.size() - 1; i >= 0; i--) {
      for (right = i + 1; right < heights.size() && heights[right] >= heights[i]; right = rightmost[right] + 1) ;
      rightmost[i] = right - 1;
    }
    int max = 0;
    for (int i = 0; i < heights.size(); i++) {
      for (left = i - 1; left >= 0 && heights[left] >= heights[i]; left = leftmost[left] - 1) ;
      leftmost[i] = left + 1;
      int size = (rightmost[i] - leftmost[i] + 1) * heights[i];
      if (size > max)
        max = size;
    }
    return max;
  }
};
int main(int argc, const char *argv[]) {

  cout << Solution().largestRectangleArea({2, 1, 5, 6, 2, 3}) << endl;
  return 0;
}
