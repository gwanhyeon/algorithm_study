#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
// 10진법 수를 B진법수로 변환하는 문제


int main(void){
    int n,b;
    string str;
    // n = 숫자 , b = 진법변환하는것
    cin >> n >> b;
    
    
    // 진법변환은 어떻게 하는거냐 ? 현재 숫자 % 진법 => 의 나머지가 진법변환하는수이므로, 이것은 역순으로 이루어져있기때문에 마지막에 리버스해줘야함.
    // 결국 n 이 0이 되지 않을경우 까지 생각해서 출력해주면 된다.
    
    while(n>0){
        int r = n % b;
        if(r >= 10){
            // 기본의 값에서 -10을 빼주면 int형의 숫자가 0부터 시작하므로 여기서 값을 + "A"를 더해주면 값이 변환 된다.
            str += (char)(r - 10 + 'A');
        
        }else {
            // 진짜 단순히 문자열만 변환시키기 위함.
            str += (char)(r + '0');
        }
        n /= b;
    }
    reverse(str.begin(),str.end());
    cout << str;
    
    
    return 0;
}
