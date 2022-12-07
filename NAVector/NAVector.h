#ifndef _NAVEC_
#define _NAVEC_

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template<class T>
class NAVector;

template <class T>
class NAVector {
private:
    T* arr;
    int size;
    int capacity;
    typedef T* iterator;
public:
// Constructors and Big 4
    NAVector (int n); // Initialize by specific capacity
// No content is added, size = 0
// Assign a default size value
    template<class U>
    NAVector(U *ark, int  n ); // Initialize by n items from array
    NAVector (const NAVector&); // Initialize with a copy
    ~NAVector(); // Delete allocated memory
    NAVector<T>& operator=(const NAVector& other); // Copy assignment
    NAVector<T>& operator=(const NAVector&& other); // Move assignment
 
// // Access operations
    T& operator[](int l); // Access item by reference
// // Throw an exception if out of range  
 
// // Modifying operations
    int push_back(T element); // Add item to end of vec & return # of items
//   // Increase capacity of needed
    T pop_back();   // Remove and return last element in vec
    void erase(iterator it);    // Remove item at iterator
// // Throw exception if invalid iter
    void erase(iterator t1, iterator it2);// Remove items between
// // iterator 1 <= iterator 2 otherwise do nothing
// // Throw exception if any iterator outside range
    void clear();     // Delete all vector content
    void insert(iterator it, T element);      // Insert item at iterator
//   // Throw exception if invalid
 
// // Iterators // Supports *, + and ++ operations at least
// // Can use: typedef T* iterator
// // Or u can use std::iterator so you can
// // apply STL algorithms on NAVector
iterator begin(); // Return an iterator (T*)
iterator end(); // Return an iterator (T*)
 
// // Comparison operations
// bool operator==(const NAVector<T>&) // Return true if ==  
// bool operator< (const NAVector<T>&) // Compares item by item
// // Return true if first different item in this is < in other
 
// // Capacity operations
const int sz();    // Return current size of vec
const int cap(); // Return size of current allocated array  
// int resize()         // Relocate to bigger space
// bool empty()         // Return true if size is 0
 
// // Friends
template<class U>
friend ostream& operator<< (ostream& out, const NAVector<U> &other);
};

#endif