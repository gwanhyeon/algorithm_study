//정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
//
//명령은 총 다섯 가지이다.
//
//push X: 정수 X를 스택에 넣는 연산이다.
//pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
//size: 스택에 들어있는 정수의 개수를 출력한다.
//empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
//top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
//입력

// 풀이 과정에서 문제가 생겼던 부분은 1월달일 경우 31을 더해주면 안되는 경우였는데, 내가 그것까지 생각을 해버렸다
// 예를 들어 1 1 1월 1일을 입력하였을 경우 31일이 추가되면안되고,day 수만큼만 증가되어야했었다.


#include <stdio.h>
#include <iostream>
using namespace std;

int main(void){
    
    int stack[10];
    int input = 0;
    int size = 0;
    int select = 0;
    
    
    
    // 1 init
    for(int i=0; i<sizeof(stack); i++){
        stack[i] = 1;
    }
    while(true){
        cin >> select;
        
        switch (select) {
            case 1:
                // push()
                cout << "push function()"<<endl;
                cout << "Your enter the number" <<endl;
                cin >> input;
                stack[size] = input;
                cout << stack[size] << endl;
                size = size + 1;
                
                break;
            case 2:
                // pop()
                cout << "pop function()" << endl;
                if(size == 0){
                    cout << "-1 정수가 없습니다."<<endl;
                }else{
                    stack[size] = 1;
                    size = size - 1;
                    cout << "pop : "<< stack[size] << endl;
                }

                break;
            case 3:
                
                // size
                cout << "size function()" << endl;
                cout << "size : " << size << endl;

                break;
            case 4:
                // empty
                cout << "Empty Check" << endl;
                
                if(size == 0){
                    cout << "stack is empty : 1" << endl;
                }else{
                    cout << "stack is not empty : 0" <<endl;
                }
                break;
            case 5:
                // top
                cout <<"Top Check" << endl;
                if(size == 0 ){
                    cout << "stack is empty : -1" << endl;
                }else{
                    cout << stack[size-1] << endl;
                }
                break;
            default:
                break;
        }
        
        
        
    }

 
}
