//
//  카카오셔틀버스.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 07/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
string solution(int n, int t, int m, vector<string> timetable);
int StringToMintime(string time);
int main(void)
{
    string cTestTime[] = {"08:00", "08:01", "08:02", "08:03"};
    string cTestTime2[] = {"09:10", "09:09", "08:00"};
    string cTestTime3[] = {"09:00", "09:00", "09:00", "09:00"};
    string cTestTime4[] = {"00:01", "00:01", "00:01", "00:01", "00:01"};
    string cTestTime5[] = {"23:59"};
    string cTestTime6[] = {"23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"};
    vector<string> testTimeTable(cTestTime, cTestTime + (sizeof(cTestTime) / sizeof(cTestTime[0])));
    vector<string> testTimeTable2(cTestTime2, cTestTime2 + (sizeof(cTestTime2) / sizeof(cTestTime2[0])));
    vector<string> testTimeTable3(cTestTime3, cTestTime3 + (sizeof(cTestTime3) / sizeof(cTestTime3[0])));
    vector<string> testTimeTable4(cTestTime4, cTestTime4 + (sizeof(cTestTime4) / sizeof(cTestTime4[0])));
    vector<string> testTimeTable5(cTestTime5, cTestTime5 + (sizeof(cTestTime5) / sizeof(cTestTime5[0])));
    vector<string> testTimeTable6(cTestTime6, cTestTime6 + (sizeof(cTestTime6) / sizeof(cTestTime6[0])));
    
//    cout << "con time : " << solution(1, 1, 5, testTimeTable) << endl;
//    cout << "con time : " << solution(2, 10, 2, testTimeTable2) << endl;
//    cout << "con time : " << solution(2, 1, 2, testTimeTable3) << endl;
//    cout << "con time : " << solution(1, 1, 5, testTimeTable4) << endl;
    cout << "con time : " << solution(1, 1, 1, testTimeTable5) << endl;
    cout << "con time : " << solution(10, 60, 45, testTimeTable6) << endl;
    
    return 0;
}

// string으로 받은 시각을 int형식의 분 time으로 변경(계산하기 쉽게)
int StringToMintime(string time)
{
    int minTime = 0;
    int hour = ((time[0] - '0') * 10 + (time[1] - '0')) * 60;
    int min = (time[3] - '0') * 10 + (time[4] - '0');
    
    minTime = hour + min;
    return minTime;
}

const char timeComvertor[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
string solution(int n, int t, int m, vector<string> timetable)
{
    string answer = "";
    int shuttleFrequency = n;    // 셔틀 운행 횟수
    int shuttleTime = t;        // 셔틀 운행 간격
    int crewNumber = 0;            // 셔틀타려는 크루 수
    int conTime = 0;            // 콘 시간
    int *convertTimeTable;        // string timetable -> int timetalbe
    
    convertTimeTable = new int[timetable.size() + 1];
    crewNumber = timetable.size();
    
    // 1. 분값(int)으로 string값 컨버팅
    for(int i = 0; i < crewNumber; i ++) convertTimeTable[i] = StringToMintime(timetable[i]);
    
    // 2. 시간 순으로 정렬(버블소트)
    for(int i = 0; i < crewNumber; i ++) {
        int tempTime;
        for(int j = i; j < crewNumber - 1; j ++) {
            if(convertTimeTable[i] > convertTimeTable[j + 1]) {
                tempTime = convertTimeTable[i];
                convertTimeTable[i] = convertTimeTable[j + 1];
                convertTimeTable[j + 1] = tempTime;
            }
        }
    }
    
    int checkCrew = 0;     // 버스에 탈 크루 체크(timetable 순서)
    int driveTime = 540; // 9 * 60 = 540분(첫차가 09시)
    for(int i = 0; i < shuttleFrequency; i ++) {
        int shuttleSeat = m; // 운행시간마다 셔틀에 탈 수 있는 최대 인원(크루) 수
        
        // 3. 운행시각마다 셔틀타는 크루수 체크
        for(int j = checkCrew; j < crewNumber; j ++) {
            if(convertTimeTable[j] <= driveTime) {
                shuttleSeat -= 1; // 인원수 빼기
                checkCrew += 1;
                if(shuttleSeat == 0) break; // 자리 다차면 끝
            }
        }
        
        // 4. 다음 운행이 없을 경우 콘 시간 정하기
        if(i == shuttleFrequency - 1) {
            if(shuttleSeat == 0) conTime = convertTimeTable[checkCrew - 1] - 1; // 자리가 없을떄
            else conTime = driveTime; // 자리가 있을떄
        }
        
        driveTime += shuttleTime;
        if(driveTime >= (60 * 24)) break;
    }
    
    // int값을 string값으로 만들어주는 코드
    int temp;
    temp = conTime / 60;
    answer += timeComvertor[temp / 10];
    answer += timeComvertor[temp % 10];
    answer += ":";
    temp = conTime % 60;
    answer += timeComvertor[temp / 10];
    answer += timeComvertor[temp % 10];
    
    delete convertTimeTable;
    
    return answer;
}
