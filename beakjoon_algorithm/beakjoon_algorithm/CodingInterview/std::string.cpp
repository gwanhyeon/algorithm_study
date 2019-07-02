//
//  std::string.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 03/07/2019.
//  Copyright © 2019 kgh. All rights reserved.
//
#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str = "Hello World";     // string str("HelloWorld");   같은 형식
    string str_copy = "Coding";
    str.push_back('!');
    cout << str << '\n';
    str.pop_back();
    str += str_copy;
    cout << str << '\n';
    cout << str.size() << '\n';
    cout << str.length() << '\n';
    cout << str.capacity() << '\n';
    str.resize(4);
    cout << str << '\n';
    cout << str.size() << '\n';
    cout << str.length() << '\n';
    cout << str.capacity() << '\n';
    str.shrink_to_fit();
    cout << str << endl;
    cout << str.size() << '\n';
    cout << str.length() << '\n';
    cout << str.capacity() << '\n';
    cout << str.substr(3) << '\n';
    cout << str.substr(3,1) << '\n';
    cout << str.replace(3, 2, str_copy) << '\n';
    cout << str.find("Hello") << '\n';
    cout << str.find("Hello", 4) << '\n';
    cout << str[str.size() - 1] << '\n';
    cout << str.at(0) << '\n';
    cout << str[0] << '\n';
    cout << str.at(0) << '\n';
    cout << str.front() << '\n';
    cout << str.back() << '\n';
    string::iterator iter = str.begin();
    for (; iter != str.end(); ++iter)
    {
        cout << *iter << " ";
    }
    char arr[10];
    int arr_size = str.copy(arr, 3, 5);
    arr[arr_size] = '\0';
    cout << arr << '\n';
    cout << str.compare(str_copy) << '\n';
    str.clear();
    return 0;
}
