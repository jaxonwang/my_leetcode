#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;


class Solution {

public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {

        vector<int> p_sum(nums);
        for (int i = 1; i < p_sum.size(); i++) {
           p_sum[i] += p_sum[i-1];
        }

        map<int,int> m;

        m[p_sum[0]] = 1;

        for (int i = 0; i < i_v.size(); i++) {
            
        }

    }
};

int main(int argc, const char *argv[])
{
    
    return 0;
}



