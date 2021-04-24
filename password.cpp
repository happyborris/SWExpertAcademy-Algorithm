#include <iostream>
#include <set>

using namespace std;

int N;

string rotate(string n) {
    char tmp = n[N-1];
    for(int i = N-1; i >= 0; i--) {
        n[i+1] = n[i];
    }
    n[0] = tmp;
    return n;
}

int main() {
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        int K, len;
        cin >> N >> K;
        len = N / 4;
        string n;
        cin >> n;
        set<int> s;
        set<int>::iterator iter;
        int i = 0;
        do{
            for(int j = 0; j < N; j+=len) {                        
                s.insert((int)strtol(n.substr(j, len).c_str(), NULL, 16));
            }
            n = rotate(n);
            i++;
        }while(i < len);

        iter = s.end();
        for(int i = 0; i < K; i++) {
            iter--;
        }
        cout << "#" << tc << " " << *iter << endl;
    }
}