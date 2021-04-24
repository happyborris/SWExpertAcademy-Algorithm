#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T, sum = 0;
    cin >> T;
    vector<int> v[T];

    for(int i = 0; i < T; i++) {
        for(int j = 0; j < 10; j++) {
            int k;
            cin >> k;
            v[i].push_back(k);
        }
    }

    for(int i = 0; i < T; i++) {
        cout << "#" << i+1 << " ";
        for(int j = 0; j < 10; j++) {
            if(v[i][j] % 2) sum += v[i][j];
        }
        cout << sum << endl;
        sum = 0;
    }
}