#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    if (matrix.size() == 0)
      return 0;

    int column_num = matrix[0].size();
    vector<int>height(column_num);

    int *l = new int[column_num];
    int *r = new int[column_num];

    int max_area=0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < column_num; j++) {
            height[j] = matrix[i][j] == '0' ? 0 : height[j]+1;
        }
        int left, right;
        for (int j = 0; j < column_num; j++) {
            for (left = j - 1; left >=0 && height[left] >= height[j]; left = l[left] -1){
            }
            l[j]  = left + 1;
        }
        for (int j = column_num -1; j >= 0; j--) {
            for (right = j + 1; right < column_num && height[right] >= height[j]; right=r[right]+1){
            }
            r[j] = right -1;
        }
        for (int j = 0; j < column_num; j++) {
            max_area = max(max_area, (r[j]-l[j]+1) * height[j]);
        }
    }
    delete [] l;
    delete [] r;

    return max_area;
  }
};

int main(int argc, const char *argv[]) {
  vector<vector<char>> test {{'1', '0', '1', '0', '0'},
                               {'1', '0', '1', '1', '1'},
                               {'1', '1', '1', '1', '1'},
                               {'1', '0', '0', '1', '0'}};
  cout << Solution().maximalRectangle(test) << endl;;

  return 0;
}
