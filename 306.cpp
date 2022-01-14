#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define VALTYPE unsigned long long
#define NUMOF(chr) (chr - '0')

class Solution {
   private:
    class StateMachine {
        string mStr;
        int curr = 0, len = 0;

       public:
        StateMachine(string st) {
            mStr = st;
            len = mStr.length();
            curr = 0;
        }

        char poll(int digit, VALTYPE& res) {
            if (curr + digit > len) {
                return 1;  // Overflow.
            }
            if (mStr[curr] == '0' && digit > 1) {
                return 2;  // cannot fetch 0x.
            }
            VALTYPE ret = 0;
            for (int i = 0; i < digit; i++) {
                ret *= 10;
                ret += NUMOF(mStr[curr]);
                curr++;
            }
            res = ret;
            return 0;
        }

        void rewind(int digit) { 
            curr -= digit;
            if (curr < 0) curr = 0; 
        }

        int remainDigits() { return len - curr; }

        int available(int digit) { return curr + digit <= len; }
    };

   public:
    bool isAdditiveNumber(string num) {
        StateMachine machine(num);
        vector<VALTYPE> i;
        cout<<"START!!" <<endl;
        return helper(i, machine) == 0;
    }
    /**
     * @return
     * 0 - Globally solved; 1 - Locally solved; -1 - Not correct.
     */
    int helper(vector<VALTYPE>& choseNums, StateMachine& machine) {
        VALTYPE poll = 0;
        int ret = -1;
        for (int n = 1; machine.available(n) && ret != 0; n++) {
            char result = machine.poll(n, poll);
            if (result == 0) {
                // deal with this number;

                if (choseNums.size() >= 2) {
                    int p = choseNums.size() - 1, diff = result - choseNums[p] - choseNums[p-1];
                    if (diff == 0) {
                        ret = machine.remainDigits() == 0? 0: 1;
                        if (ret == 1) { // we're not done here.
                            choseNums.push_back(result); // push in.
                            ret = helper(choseNums, machine);
                        }
                    } else if (diff > 0) {
                        // Here we do not search forward.
                        machine.rewind(n);
                        choseNums.pop_back();
                        ret = -1;
                        break;
                    } else {
                        machine.rewind(n);

                        ret = -1;
                        continue;
                    }
                } else {
                    choseNums.push_back(result); // push in.
                    ret = helper(choseNums, machine);
                }
                machine.rewind(n);
            } else { // failed to fetch number.
                ret = -1;
                break;
            }
        }
        return ret;
    }
};

int main() {
    Solution sln;
    // false
    cout<<(sln.isAdditiveNumber("0235813")? "true": "false")<<endl;
    // true
    cout<<(sln.isAdditiveNumber("199100199")? "true": "false")<<endl;
    // false
    cout<<(sln.isAdditiveNumber("11235813213455890144")? "true": "false")<<endl;
    // true
    cout<<(sln.isAdditiveNumber("11111111111011111111111")? "true": "false")<<endl;


    return 0;
    // return sln.testMachine("101000000",3);
}