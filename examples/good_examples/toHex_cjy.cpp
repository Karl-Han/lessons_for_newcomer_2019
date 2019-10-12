#include <iostream>
using namespace std;

class Solution {
   public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        string res = "";
        string rule[16] = {"0", "1", "2", "3", "4", "5", "6", "7",
                           "8", "9", "a", "b", "c", "d", "e", "f"};
        unsigned m = num;
        while (m) {
            res = rule[num = (m % 16)] + res;
            m /= 16;
        }
        return res;
    }
};

int main() {
    int num = 0;
    cin >> num;
    Solution solve;
    cout << solve.toHex(num);
}
