#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void){
    string str;
    int cnt=0;
    cin >> str;
    
    
    stack<int> s;
    for(int i=0; i<str.size(); i++){
        if(str[i] == '('){
            
            s.push(i);  // '('가 나왔을 경우 (이 나온 인덱스의 값을 push 해준다.
            // Why? 인덱스값으로, 레이저인지 쇠막대기인지 구분 해주기 위해서
        }else{
            // 이제 스택에 있는 인덱스 값을 비교 해볼것이다.
            // () 레이저 인것을 확인 하기 위해서.
            if(s.top()+1 == i){
                s.pop();        // pop을 해주는이유는 레이저 인것이 확인 되었기 때문에 stack에서 빼준다.
                // 여기서 왜 size를 해주는거에대한 궁금증이 생겼는데, 그 이유는 레이저가 쇠막대기를 잘라버릴때,
                // 결국 stack에 있는 "("의 개수만큼이 쇠막대기의 개수가 되어서
                cnt += s.size();
                // 레이저가 아니고 ")" 가 나왔을 경우에 레이저 처리가 된것이므로
                // stack에 있던값을 다 빼주고, 이제 ")" 개수만큼이 또 잘려진 쇠막대기의 개수가 되기 때문에
                // cnt +=1 만큼을 해준다.
            }else{
                s.pop();
                cnt += 1;
            }
            
        }
    }
    cout << cnt;
    
}
