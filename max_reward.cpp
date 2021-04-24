#include <iostream>
#include <string>
#include <queue>

using namespace std;

bool check[1000000][11];

string exchange(string reward, int index1, int index2) {
    char temp = reward[index1];
    reward[index1] = reward[index2];
    reward[index2] = temp;
    return reward;
}

int main() {
    int T;
    cin >> T;

    for(int i = 0; i < T; i++) {
        string reward;
        int cnt;
        int max_num = -1;
        cin >> reward >> cnt;
        queue<pair<string, int>> q;
        q.push({reward, 0});
        while (!q.empty()) {
            string cur_reward = q.front().first;
            int cur_cnt = q.front().second;
            q.pop();
            if(cur_cnt < cnt) {
                for(int j = 0; j < cur_reward.length()-1; j++) {
                        for(int k = j+1; k < cur_reward.length(); k++){
                        string next_reward = exchange(cur_reward, j, k);
                        int next_cnt = cur_cnt + 1;
                        if(!check[stoi(next_reward)][cur_cnt]) {
                            check[stoi(next_reward)][cur_cnt] = true;
                            q.push({next_reward, next_cnt});
                        }
                    }
                }
            }
            else {
                max_num = max(max_num, stoi(cur_reward));
            }
        }
        printf("#%d %d\n", i+1, max_num);
    }

    return 0;
}