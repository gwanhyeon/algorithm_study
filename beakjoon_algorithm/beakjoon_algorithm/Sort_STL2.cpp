//
//  Sort_STL2.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 04/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int score;
    Student(string name, int score) {
        this->name = name;
        this->score = score;
    }
    // 정렬 기준은 '점수가 작은 순서'
    bool operator <(Student &student) {
        return this->score < student.score;
    }
};

bool compare(int a, int b) {
    return a > b;
}

int main(void) {
    Student students[] = {
        Student("1", 0),
        Student("2", 3),
        Student("4", 7),
        Student("3", 7),
        Student("5", 2)
    };
    sort(students, students + 5);
    for(int i = 0; i < 5; i++) {
        cout << students[i].name << ' ';
    }
}
