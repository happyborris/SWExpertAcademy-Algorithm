#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int T_num;
        cin >> T_num;

        int score[1000];
        int cnt[101] = {0, };
        //int choi = 0, ans = 0;
        pair<int, int> p;

        for(int j = 0; j < 1000; j++) {
            cin >> score[j];
        }
        for(int j = 0; j < 1000; j++) {
            cnt[score[j]]++;
        }

        for(int j = 100; j >= 0; j--) {
            if(p.first < cnt[j]) {
                p.first = cnt[j];
                // cout << "choi : " << choi << ", cnt[j] : " << cnt[j] << ", j : " << j << endl;
                p.second = j;
            }
        }

        cout << "#" << T_num << " " << p.second << endl;
    }
}