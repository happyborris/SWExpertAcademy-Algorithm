#include <iostream>
#include <vector>

using namespace std;

void landscape() {

}

int main() {
    for(int i = 0; i < 10; i++) {
        int T, cnt = 0;
        cin >> T;
        vector<bool> land[T];
        pair<vector<bool>, int> p[T];

        for(int j = 0; j < T; j++) {
            int height;
            cin >> height;
            for(int k = 0; k < 255; k++) {
                if(k < height)
                    land[j].push_back(true);
                else
                    land[j].push_back(false);
            }
            p[j].first = land[j];
            p[j].second = height;
        }

        for(int j = 2; j < T-2; j++) {
            for(int k = 0; k < p[j].second; k++) {
                if(!p[j-2].first[k] && !p[j-1].first[k] && !p[j+1].first[k] && !p[j+2].first[k]) cnt++;
            }
        }

        cout << "#" << i+1 << " " << cnt << endl;
    }
    return 0;
}