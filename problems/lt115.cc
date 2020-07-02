#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {

        int s_len = s.size();
        int t_len = t.size();
        if(s_len == 0)
            return false;
        if(s_len < t_len)
            return false;

        long long num[s_len+1][t_len+1];

        num[0][0] = s[0] == t[0]?1:0;
        for (int i = 1; i < s_len; i++) {
            if(s[i] == t[0])
                num[i][0] = num[i-1][0] + 1;
            else
                num[i][0] = num[i-1][0];
        }
        for (int i = 1; i < t_len; i++) {
            num[0][i] = 0;
        }
        for (int i = 1; i < s_len; i++) {
            for (int j=1;j< t_len;j++){
                if(j>i){
                    num[i][j] = 0;
                    continue;
                }
                num[i][j] = num[i-1][j];
                if (s[i] == t[j])
                    num[i][j] += num[i-1][j-1];
            }
        }
        return num[s_len-1][t_len-1];
    }

    int numDistinct1(string s, string t) {
        int m = t.length(), n = s.length();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for (int j = 0; j <= n; j++) dp[0][j] = 1;
        for (int j = 1; j <= n; j++){
            for (int i = 1; i <= m; i++){
                dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
                cout << dp[i][j]<<" ";
            }
            cout << endl;
        }
        return dp[m][n];
    }
};

int main(int argc, const char *argv[])
{
    // cout << Solution().numDistinct("rabbbit", "rabbit") << endl;;
    string a="xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo";
    string b="rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys";
     cout << Solution().numDistinct(a, b) << endl;;
    return 0;
}
