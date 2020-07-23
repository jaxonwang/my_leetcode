#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        unordered_map<int, int> m; // rightmost 

        for (auto & i: nums){
            if(m.count(i) >0)
                continue;
            if(m.count(i-1)>0 && m.count(i+1)>0){
                int left = m[i-1];
                int right = m[i+1];
                m[m[i-1]] = right;
                m[m[i+1]] = left;
                m[i] = i;
            }else if(m.count(i-1)>0){
                m[i] = m[i-1];
                m[m[i-1]] = i;
            }else if(m.count(i+1)>0){
                m[i] = m[i+1];
                m[m[i+1]] = i;
            }else{
                m[i] = i;
            }
        }

        int max_len = 0;
        for (auto &kv: m) {
            int abs = kv.first > kv.second? kv.first - kv.second: kv.second -kv.first;
            max_len = max(abs, max_len);
        }

        for (int i = 0; i < nums.size(); i++) {
            cout << m[nums[i]] << " ";
        }
        cout << endl;
        return max_len + 1;
    }
};


int main(int argc, const char *argv[])
{ 
    vector<int> nums = {9,1,4,7,3,-1,0,5,8,-1,6};
    cout << Solution().longestConsecutive(nums) << endl;

    return 0;
}
