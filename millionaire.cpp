#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {
        int N;
        long long sum = 0;
        cin >> N;
        vector<int> v;
        for(int j = 0; j < N; j++) {
            int k;
            cin >> k;
            v.push_back(k);
        }
        vector<int>::iterator i = v.begin();
        while(i < v.end()) {
            int cnt = 0;
            int max = *max_element(i, v.end());
            vector<int>::iterator max_index = find(i, v.end(), max);
            for(i; *i < max; i++) {
                sum -= *i;
                cnt++;
            }
            sum += cnt * max;
            i++;
        }

        cout << "#" << t+1 << " " << sum << endl;
    }

    return 0;
}