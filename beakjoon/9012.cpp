//
//  9012.cpp
//  Algorigm_CodingTest
//
//  Created by kgh on 2018. 4. 9..
//  Copyright © 2018년 kgh. All rights reserved.
//

//괄호 문자열(Parenthesis String, PS)은 두 개의 괄호 기호인 ‘(’ 와 ‘)’ 만으로 구성되어 있는 문자열이다. 그 중에서 괄호의 모양이 바르게 구성된 문자열을 올바른 괄호 문자열(Valid PS, VPS)이라고 부른다.
//한 쌍의 괄호 기호로 된 “( )” 문자열은 기본 VPS 이라고 부른다. 만일 x 가 VPS 라면 이것을 하나의 괄호에 넣은 새로운 문자열 “(x)”도 VPS 가 된다. 그리고 두 VPS x 와 y를 접합(concatenation)시킨 새로운 문자열 xy도 VPS 가 된다. 예를 들어 “(())()”와 “((()))” 는 VPS 이지만 “(()(”, “(())()))” , 그리고 “(()” 는 모두 VPS 가 아닌 문자열이다.
//                                                                                                                                                                                                                                                                                                                                                              여러분은 입력으로 주어진 괄호 문자열이 VPS 인지 아닌지를 판단해서 그 결과를 YES 와 NO 로 나타내어야 한다.
//
//                                                                                                                                                                                                                                                                                                                                                              입력
//                                                                                                                                                                                                                                                                                                                                                              입력 데이터는 표준 입력을 사용한다. 입력은 T개의 테스트 데이터로 주어진다. 입력의 첫 번째 줄에는 입력 데이터의 수를 나타내는 정수 T가 주어진다. 각 테스트 데이터의 첫째 줄에는 괄호 문자열이 한 줄에 주어진다. 하나의 괄호 문자열의 길이는 2 이상 50 이하이다.
//
//                                                                                                                                                                                                                                                                                                                                                              출력
//                                                                                                                                                                                                                                                                                                                                                              출력은 표준 출력을 사용한다. 만일 입력 괄호 문자열이 올바른 괄호 문자열(VPS)이면 “YES”, 아니면 “NO”를 한 줄에 하나씩 차례대로 출력해야 한다.
//
//예제 입력 1
//6
//(())())
//(((()())()
//  (()())((()))
//  ((()()(()))(((())))()
//   ()()()()(()()())()
//   (()((())()(
//              예제 출력 1
//              NO
//              NO
//              YES
//              NO
//              YES
//              NO

//#include <stdio.h>
//#include <string>
//#include <iostream>
//
//
//using namespace std;
//
//int main(void){
//
//    int n;
//    int cnt=0;
//    cin >> n;       // n개수 입력
//
//    // cnt값을 전역변수로 쓰지말자 미치놈아~
//    while(n--){
//        string str;
//        cin >>str;
//
//        // String 값은 하나씩 뺄 수 있다. 오케이 좋았어
//        // compare은 될줄알았는데 안된다. compare를 사용하자 여기서는 string stl method 에서는 == 이 불가능하다.
//
//        // 결국 str[i] == '(' 이런 형식으로 사용 가능하다
//
//        for(int i=0; i<str.size(); i++){
//            //cout << str[i];
//
//            if(str[i] == '('){
//                cnt++;
//                //cout << str[i];
//
//            }else if(str[i] == ')'){
//                cnt--;
//            }
//            if (cnt < 0) {
//                cout << "NO" <<endl;
//            }
//        }
//        if(cnt == 0){
//            cout << "YES"<<endl;
//        }else{
//            cout <<"NO"<<endl;
//        }
//
//
//    }
//
//
//}


// 함수를 사용하여 알고리즘을 작성하자 오ㅐ? 출력시 장애날수가 있다..
// 이미 메모리를 잡고 있어서, 출력에 초과 가능성이 있다.

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
string valid(string str);
int main(void){
    
    int n;
    cin >>n;
    while(n--){
        string str;
        cin >>str;
        
        cout << valid(str) << '\n';
        
    }
    return 0;
}
string valid(string str) {
    
    int cnt=0;
    
    
    for(int i=0; i<str.size(); i++){
        if(str[i]=='('){
            cnt += 1;
        }else if(str[i]==')'){
            cnt -= 1;
        }
        if (cnt < 0) {
            return "NO";
        }
    }
    if(cnt == 0){
        return "YES";
    }else{
        return "NO";
    }
    
}



