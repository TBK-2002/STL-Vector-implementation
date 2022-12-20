/**
 * @file main.cpp
 * @author Nour El-din and Tolba (nour.sehs.3@gmail.com)
 * @brief the main file for the NAVector class which is a vector class that is implemented using an array.
 * @version 0.1
 * @date 2022-12-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include "NAVector.h"
#include "NAVector.cpp"

using namespace std;

/**
 * @brief the main function
 * 
 * @return int returns 0 if the program runs successfully
 */

int main(){
    int arr[] = {1, 2, 3};
    NAVector<int> obj(arr, 3);
    int arr2[]={1,1,3};
    NAVector<int> obj2(arr2,3);
    cout<< obj2 << endl;
    obj2.pop_back();
    obj2.pop_back();
    obj2.pop_back();
    cout << obj2.sz() << endl;
    cout << obj2.empty() << endl;
    cout << obj2.cap() << endl;
    obj2.resize();
    cout << obj2.sz() << endl;
    cout << obj2.cap() << endl;
    cout << obj2;
    obj2.push_back(1);
    obj2.push_back(2);
    obj2.push_back(3);
    obj2.push_back(4);
    obj2.push_back(5);
    obj2.push_back(6);
    obj2.push_back(7);
    cout << obj2 << endl;
    int* p = obj2.begin()+4;
    int* p2 = obj2.begin()+6;
    obj2.erase(p,p2);
    cout << obj2 << endl;
    // cout << obj[2] << '\n';
    // cout << obj.pop_back() << '\n';
    // obj.push_back(4);
    // cout << obj[2] << '\n';
    // cout << *obj.begin() << '\n';
    // obj.erase(obj.begin());
    // cout << obj[1] << '\n';
    // obj.insert(obj.begin()+1, 1);
    // cout << obj[2] << '\n';
    // obj.clear();
    // cout << obj.sz() << '\n';
    // cout << obj.cap() << '\n';
    // obj.push_back(1);
    // obj.push_back(2);
    // obj.push_back(3);
    // obj.push_back(4);
    // obj.push_back(5);
    // obj.push_back(6);
    // obj.push_back(7);
    // cout << obj << '\n';
    // cout << obj.sz() << '\n';
    // cout << obj.cap() << '\n';
   return 0;
}