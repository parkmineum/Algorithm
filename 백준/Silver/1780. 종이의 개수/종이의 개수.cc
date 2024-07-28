#include <iostream>
#include <string.h>
 
using namespace std;
 
int N;
int map[2200][2200];
//[0]:-1종이 개수, [1]:0종이 개수, [2]:1종이 개수
int answer[3];
 
//모두 같은 숫자인지 판단
bool allSameNumber(int x, int y, int n) {
    
    int check = map[x][y];
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[x + i][y + j] != check) {
                return false;
            }
        }
    }
 
    return true;
}
 
void makePaper(int x, int y, int n) {
 
    //종이가 모두 같은 숫자일 경우 -> 해당 종이 갯수 + 1, 종료
    if (allSameNumber(x, y, n)) {
        int paperNum = map[x][y];
        answer[paperNum + 1]++;
        return;
    }
 
    int div = n / 3;
 
    //9개로 나누어서 분할 정복
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            makePaper(x + div * i, y + div * j, div);
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //초기화
    N = 0;
    memset(map, 0, sizeof(map));
    memset(answer, 0, sizeof(answer));
 
    //입력
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
 
 
    makePaper(0, 0, N);
 
    //출력
    for (int i = 0; i < 3; i++) {
        cout << answer[i] << "\n";
    }
 
 
}
