
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {

        // vector<pair<int, int>> s;
        // vector<int> candies(ratings.size(), 0);
        // s.push_back(pair<int,int>{-1, -1});
        //
        // int sum_c=0;
        // int last_value=0;
        // for (int i = 0; i < ratings.size(); i++) {
        //    if(s.back().first < ratings[i]){
        //        sum_c += ++last_value;
        //        candies[i] = last_value;
        //        s.push_back(pair<int,int>{ratings[i], i});
        //    }else if(s.back().first == ratings[i]){
        //        sum_c += last_value;
        //    }else{
        //        int before_rating = s.back().second;
        //        while(s.back().first >= ratings[i]){
        //            s.pop_back();
        //        }
        //        last_value = 1;
        //        if (before_rating == 1)
        //
        //        sum_c += ++last_value;
        //        if(last_value )
        //        sum_c += i - s.back().second - 1;
        //        candies[i] = last_value;
        //    }
        // }

        int sum_c=0;

        int des_start_pos = 0;
        int previous_candy = 1;
        sum_c += 1;
        for (int i = 1; i < ratings.size(); i++) {
            if(ratings[i] > ratings[i-1]){
                des_start_pos = i;
                sum_c += ++previous_candy;
            }else if(ratings[i] == ratings[i-1]){
                des_start_pos = i;
                previous_candy = 1;
                sum_c += previous_candy;
            }else{
                if(previous_candy == 1)
                    sum_c += i - des_start_pos;
                previous_candy = 1;
                sum_c += previous_candy;
            }
            cout << sum_c << endl;
        }

        return sum_c;
        
    }
};

int main(int argc, const char *argv[])
{
    vector<int >  tmp = {1,2,3,1,0};
    cout << Solution().candy(tmp) << endl;
    return 0;
}
