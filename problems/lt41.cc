#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    int count = nums.size();

    for (int i = 0; i < count; i++) {
      for (int k = nums[i]; k <= count && k > 0 && nums[k - 1] != k;) {
        int k1 = nums[k - 1];
        nums[k - 1] = k;
        k = k1;
      }
    }
    for (int i = 0; i < count; i++) {
      if (nums[i] != i + 1)
        return i + 1;
    }
    return count + 1;
  }
};

int main(int argc, const char *argv[]) {
  vector<int> v = {1, 2, 0};
  cout << Solution().firstMissingPositive(v) << endl;
  return 0;
}
