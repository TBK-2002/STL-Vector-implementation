#include <iostream>
#include "NAVector.h"
#include "NAVector.cpp"

using namespace std;

int main(){
    int arr[] = {1, 2, 3};
    NAVector<int> obj(arr, 3);
    cout << obj[2] << '\n';
    cout << obj.pop_back() << '\n';
    obj.push_back(4);
    cout << obj[2] << '\n';
    cout << *obj.begin() << '\n';
    obj.erase(obj.begin());
    cout << obj[1] << '\n';
    obj.insert(obj.begin()+1, 1);
    cout << obj[2] << '\n';
    obj.clear();
    cout << obj.sz() << '\n';
    cout << obj.cap() << '\n';
    obj.push_back(1);
    obj.push_back(2);
    obj.push_back(3);
    obj.push_back(4);
    obj.push_back(5);
    obj.push_back(6);
    obj.push_back(7);
    cout << obj << '\n';
    cout << obj.sz() << '\n';
    cout << obj.cap() << '\n';
    return 0;
}