#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        
        int left[prices.size()];
        int right[prices.size()];
        int min_p=prices[0];
        left[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
           left[i] = max(left[i-1], prices[i] - min_p);
           min_p = min(min_p, prices[i]);
        }
        int max_p=prices[prices.size()-1];
        right[prices.size()-1] = 0;

        for (int i = prices.size()-2; i >=0; i--) {
           right[i] = max(right[i+1], max_p - prices[i]);
           max_p = max(max_p, prices[i]);
        }
        int total = 0;
        for (int i = 0; i < prices.size()-2; i++) {
            total = max(total, left[i] + right[i+1]);
        }
        total = max(total, right[0]);
        return total;
    }
};


int main(int argc, const char *argv[])
{
    vector<int> t = {3,3,5,0,0,3,1,4};
    cout << Solution().maxProfit(t)<<endl;
    return 0;
}
