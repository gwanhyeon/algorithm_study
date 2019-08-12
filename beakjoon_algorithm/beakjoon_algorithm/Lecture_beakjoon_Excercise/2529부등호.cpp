


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int n;
char a[20];
vector<string> ans;
bool check[10];
bool good(char x, char y, char op) {
    if (op == '<') {
        if (x > y) return false;
    }
    if (op == '>') {
        if (x < y) return false;
    }
    return true;
}
void go(int index, string num) {
    // 정답의 후보를 코드에 넣어준다.
    if (index == n+1) {
        ans.push_back(num);
        return;
    }
    
    // 0~9 까지값
    for (int i=0; i<=9; i++) {
        // 체크된 놈이면 계쏙 진행한다.
        if (check[i]) continue;
        // 부등호값에 대한 조건 만족 처리
        if (index == 0 || good(num[index-1], i+'0', a[index-1])) {
            // 안으로 들어간다 check 변수 조건 처리
            check[i] = true;
            cout << "go(" << index+1<< "," << num+to_string(i) << ")"<< '\n';
            cout << "i : " << i << '\n';
            // index+1만큼 증가시켜주고, 더해나간다.
            go(index+1, num+to_string(i));
            // 다돌고나서 check[i] =false를 만들어서 다시 뒤로 돌아간다.
            check[i] = false;
        }
    }
}
int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    go(0, "");
    
    // 정답의 후보중에서 최대값 최소값을 찾아준다. minmax_element();
    auto p = minmax_element(ans.begin(), ans.end());
    cout << *p.second << '\n';
    cout << *p.first << '\n';
    return 0;
}
