#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool check[1000000][11];

string exchange(string s, int i1, int i2) {
    char tmp = s[i1];
    s[i1] = s[i2];
    s[i2] = tmp;
    return s;
}

int main() {
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        string reward;
        int cnt, max_num = -1;
        cin >> reward >> cnt;
        stack<pair<string, int>> s;
        s.push({reward, 0});
        while(!s.empty()) {
            string cur_reward = s.top().first;
            int cur_cnt = s.top().second;
            s.pop();
            if(cur_cnt < cnt) {
                for(int i = 0; i < cur_reward.length()-1; i++) {
                    for(int j = i+1; j < cur_reward.length(); j++) {
                        string next_reward = exchange(cur_reward, i, j);
                        if(!check[stoi(next_reward)][cur_cnt]) {
                            check[stoi(next_reward)][cur_cnt] = true;
                            s.push({next_reward, cur_cnt+1});
                        }
                    }
                }
            }
            else {
                max_num = max(max_num, stoi(cur_reward));
            }
        }
        printf("#%d %d\n", tc, max_num);
    }
    return 0;
}