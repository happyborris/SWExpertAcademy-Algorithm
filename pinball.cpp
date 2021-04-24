#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int T, N, W, H, min_num = 99999;
int map[15][12];

void boom(int cur_map[15][12], int i, int j) {
    if(i >= 0 && i < H && j >= 0 && j < W) {
        int range = cur_map[i][j]; // 폭발 범위
        cur_map[i][j] = 0;
        for(int a = 1; a < range; a++) {
            boom(cur_map, i-a, j); // 위쪽 범위 폭발
            boom(cur_map, i, j-a); // 왼쪽 범위 폭발
            boom(cur_map, i+a, j); // 아래쪽 범위 폭발
            boom(cur_map, i, j+a); // 오른쪽 범위 폭발
        }
    }
}

void reset(int cur_map[15][12]) {
    for (int i = 0; i < W; i++)
	{
		int index = H-1;
		for (int j = H-1; j >= 0; j--)
		{
			if (cur_map[j][i] != 0) {
				cur_map[index][i] = cur_map[j][i];
				index--;
			}	
		}
		for (int j = index; j >= 0; j--) {
			cur_map[j][i] = 0;
		}
	}
}

void dfs(int cnt, int before[15][12], int target) {
    if(cnt == 0) {
        int result = 0;
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                if(before[i][j]) result++;
            }
        }
        min_num = min(min_num, result);
        return;
    }

    int cur_map[15][12];
    for(int i = 0; i < H; i ++) {
        for(int j = 0; j < W; j++) {
            cur_map[i][j] = before[i][j];
        }
    }

    for(int i = 0; i < H; i++) {
        if(cur_map[i][target]) {
            boom(cur_map, i, target);
            break;
        }
    }
    reset(cur_map);

    for(int i = 0; i < W; i++) {
        dfs(cnt-1, cur_map, i);
    }
}

int main() {
    cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        cin >> N >> W >> H;
        min_num = 99999;
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                int k;
                cin >> k;
                map[i][j] = k;
            }
        }
        for(int i = 0; i < W; i++) {
            dfs(N, map, i);
        }
        cout << "#" << tc << " " << min_num << endl;
    }
}