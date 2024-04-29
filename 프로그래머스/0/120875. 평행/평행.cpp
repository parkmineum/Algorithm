#include <string>
#include <vector>
 
using namespace std;
 

bool slope(pair<vector<int>, vector<int>> a, pair<vector<int>, vector<int>> b){
    float x1 = a.first[0] - a.second[0];
    float y1 = a.first[1] - a.second[1];
    
    float x2 = b.first[0] - b.second[0];
    float y2 = b.first[1] - b.second[1];
    
    if (y1/x1 == y2/x2)   return 1;
    
    
    return 0;
}
 
 
int solution(vector<vector<int>> dots) {
    // 점은 항상 4개가 주어진다. 
    vector<int> a = dots[0];   // [1,4]
    vector<int> b = dots[1];   // [9,2]
    vector<int> c = dots[2];   // [3,8]
    vector<int> d = dots[3];   // [11,6]
    
    // [a-b, c-d], [a-c, b-d], [a-d, b-c] 중 평행일 경우
    // make_pair를 통해 벡터로 묶기 
    if (slope(make_pair(a, b), make_pair(c, d)) || slope(make_pair(a, c), make_pair(b, d)) || slope(make_pair(a, d), make_pair(b, c))){
            return 1;
    }
    
    return 0;
}