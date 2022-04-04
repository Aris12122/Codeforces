#include<bits/stdc++.h>
#define len(s) (int)s.size()
using namespace std;
set<vector<vector<int>>>used;
int Min, inf = 1e9 + 7;
 
void print(vector<vector<int>>matrix){
    int n = len(matrix);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout << matrix[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}
 
vector<vector<int>> left_shift(vector<vector<int>>matrix){
    int n = len(matrix);
    for(int i = 0; i < n; i++){
 
        int t = matrix[i][0];
        for(int j = 1; j < n; j++){
            matrix[i][j - 1] = matrix[i][j];
        }
        matrix[i][n - 1] = t;
    }
    return matrix;
}
 
vector<vector<int>> right_shift(vector<vector<int>>matrix){
    int n = len(matrix);
    for(int i = 0; i < n; i++){
 
        int t = matrix[i][n - 1];
        for(int j = n - 2; j >= 0; j--){
            matrix[i][j + 1] = matrix[i][j];
        }
        matrix[i][0] = t;
    }
    return matrix;
}
 
vector<vector<int>> up_shift(vector<vector<int>>matrix){
    int n = len(matrix);
    for(int j = 0; j < n; j++){
 
        int t = matrix[0][j];
        for(int i = 1; i < n; i++){
            matrix[i - 1][j] = matrix[i][j];
        }
        matrix[n - 1][j] = t;
    }
    return matrix;
}
 
vector<vector<int>> down_shift(vector<vector<int>>matrix){
    int n = len(matrix);
    for(int j = 0; j < n; j++){
        int t = matrix[n - 1][j];
        for(int i = n - 2; i >= 0; i--){
            matrix[i + 1][j] = matrix[i][j];
        }
        matrix[0][j] = t;
    }
    return matrix;
}
 
int check(vector<vector<int>>&matrix){
    int n = len(matrix);
    int dig_cnt = 0, oth_cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 1){
                if(i == j) dig_cnt++;
                else oth_cnt++;
            }
        }
    }
    return (n - dig_cnt) + oth_cnt;
}
 
void f(vector<vector<int>>matrix){
    if(used.count(matrix)) return;
    used.insert(matrix);
    //print(matrix);
    Min = min(Min, check(matrix));
    f(left_shift(matrix));
    f(right_shift(matrix));
    f(up_shift(matrix));
    f(down_shift(matrix));
}
 
void solve(){
    int n;
    cin >> n;
    vector<vector<int>>matrix(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++) {
            matrix[i][j] = (s[j] - '0');
        }
    }
    f(matrix);
 
}
 
int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--){
        used.clear();
        Min = inf;
        solve();
        cout << Min << '\n';
    }
}
