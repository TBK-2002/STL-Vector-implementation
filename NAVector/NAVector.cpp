/**
 * @file NAVector.cpp
 * @author Nour El-din and Tolba (nour.sehs.3@gmail.com)
 * @brief this is the implementation file for the NAVector class which is a vector class that is implemented using an array.
 * @version 0.1
 * @date 2022-12-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "NAVector.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Construct a new NAVector object
 * 
 * @tparam T the type of the vector
 * @param n the size of the vector
 */

template <class T>
NAVector<T>::NAVector(int n)
{
    capacity = n;
    size = 0;
    arr = new T(capacity);
}

/**
 * @brief Construct a new NAVector object
 * 
 * @tparam T the type of the vector
 * @tparam U the type of the array which is supposed to be from the same type
 * @param ark the array
 * @param n the size of the array
 */

template <class T>
template <class U>
NAVector<T>::NAVector(U *ark, int n)
{
    size = n;
    capacity = n;
    arr = new T[capacity];
    for (int i = 0; i < n; i++)
    {
        arr[i] = ark[i];
    }
}

/**
 * @brief Construct a new NAVector object
 * 
 * @tparam T the type of the vector
 * @param other the vector which is supposed to be copied
 */

template <class T>
NAVector<T>::NAVector(const NAVector &other){
    this->size = other.size;
    this->capacity=other.capacity;
    this->arr = new T[capacity];
    for(int i = 0; i < size; i++){
        this->arr[i] = other.arr[i];
    }
};

/**
 * @brief Destroy the NAVector object
 * 
 * @tparam T the type of the vector
 */

template<class T>
NAVector<T>::~NAVector(){
    if(arr != nullptr){
        delete[] arr;
    }
}

/**
 * @brief Copy assignment
 * 
 * @tparam T the type of the vector
 * @param other the vector which is supposed to be copied
 * @return NAVector<T>& the vector which is copied
 */

template<class T>
NAVector<T>& NAVector<T>::operator=(const NAVector& other){
    this->size = other.size;
    this->capacity=other.capacity;
    delete[] this-> arr;
    this->arr = new T[capacity];
    for(int i = 0; i < size; i++){
        this->arr[i] = other.arr[i];
    }
}

/**
 * @brief Move assignment
 * 
 * @tparam T the type of the vector
 * @param other the vector which is supposed to be moved
 * @return NAVector<T>& the vector which is moved
 */

template<class T>
NAVector<T>& NAVector<T>::operator=(const NAVector&& other){
    this->size = other.size;
    this->capacity=other.capacity;
    delete[] this-> arr;
    this->arr = other.arr;
    other.arr = nullptr;
}

/**
 * @brief Acess the element of the vector
 * 
 * @tparam T the type of the vector
 * @param l the index of the element
 * @return int& the element
 */

template<class T>
T& NAVector<T>::operator[](int l){
    try{
        if(l >= size){
            throw out_of_range("Out of range");
        }
        return arr[l];
    }
    catch(exception& ex){
        cout << "Out of range\n";
    }
}

/**
 * @brief add an element to the end of the vector
 * 
 * @tparam T type of the vector
 * @param element element to be added
 * @return int the size of the vector
 */

template<class T>
int NAVector<T>::push_back(T element){
    if(size < capacity){
        size++;
        arr[size-1] = element;
        return size;
    }
    else{
        T* tmp = new T[capacity*2];
        for(int i = 0; i < capacity; i++){
            tmp[i] = arr[i];
        }
        delete[] arr;
        arr = tmp;
        tmp = nullptr;
        capacity*=2;
        size++;
        arr[size-1] = element;
        return size;
    }
}

/**
 * @brief remove the last element of the vector
 * 
 * @tparam T type of the vector
 * @return T the last element of the vector
 */

template<class T>
T NAVector<T>::pop_back(){
    size--;
    return arr[size-1];
}

/**
 * @brief erase an element from the vector
 * 
 * @tparam T type of the vector
 * @param it iterator of the element to be erased
 */

template<class T>
void NAVector<T>::erase(iterator it){
    try{
        if(it < begin() || it > end()){
            throw out_of_range("Out of range");
        }
        for(iterator i = it; i < end(); i++){
            *i = *(i+1);
        }
        size--;
    }
    catch(exception& ex){
        cout << "Out of range\n";
    }
}

/**
 * @brief erase a range of elements from the vector
 * 
 * @tparam T type of the vector
 * @param it1 iterator of the first element to be erased
 * @param it2 iterator of the last element to be erased
 */

template<class T>
void NAVector<T>::erase(iterator it1, iterator it2){
    if(it1 > it2){
        return;
    }
    try{
        if(it1 < begin() || it1 > end() || it2 < begin() || it2 > end()){
            throw out_of_range("Out of range");
        }
        int diff = it2-it1;
        for(iterator i = it1; i < it2; i++){
            *i = *(i+diff);
        }
        size-= diff;
    }
    catch(exception& ex){
        cout << "Out of range\n";
    }
}

/**
 * @brief clear the vector
 * 
 * @tparam T type of the vector
 */

template<class T>
void NAVector<T>::clear(){
    size = 0;;
}

/**
 * @brief insert an element to the vector
 * 
 * @tparam T type of the vector
 * @param it iterator of the element to be inserted
 * @param element element to be inserted
 */

template<class T>
void NAVector<T>::insert(iterator it, T element){
    try{
        if(it < begin() || it > end()){
            throw out_of_range("Out of range");
        }
        if(size < capacity){
            size++;
            for(iterator i = end(); i > it; i--){
                *i = *(i-1);
            }
            *it = element;
        }
        else{
            T* tmp = new T[capacity*2];
            for(int i = 0; i < capacity; i++){
                tmp[i] = arr[i];
            }
            delete[] arr;
            arr = tmp;
            tmp = nullptr;
            capacity*=2;
            size++;
            for(iterator i = end(); i > it; i--){
                *i = *(i-1);
            }
            *it = element;
        }
    }
    catch(exception& ex){
        cout << "Out of range\n";
    }
}

/**
 * @brief return iterator to the first element of the vector
 * 
 * @tparam T the type of the vector
 * @return T* the iterator
 */


template<class T>
T* NAVector<T>::begin(){
    return arr;
}

/**
 * @brief return iterator to the last element of the vector
 * 
 * @tparam T the type of the vector
 * @return T* the iterator
 */

template<class T>
T* NAVector<T>::end(){
    return arr+size;
}

// Comparison operations


/**
 * @brief return the size of the vector
 * 
 * @tparam T the type of the vector
 * @return const int  the size of the vector
 */

template <class T>
const int NAVector<T>::sz()
{
    return size;
}

/**
 * @brief return the capacity of the vector
 * 
 * @tparam T the type of the vector
 * @return const int  the capacity of the vector
 */

template <class T>
const int NAVector<T>::cap()
{
    return capacity;
}

/**
 * @brief overload the operator << to print the vector
 * 
 * @tparam T the type of the vector
 * @param out the output stream
 * @param other the vector to be printed
 * @return std::ostream& the output stream
 */

template<class T>
std::ostream& operator<<(ostream& out, const NAVector<T>& other){
    for(int i = 0; i < other.size; i++){
        out << other.arr[i] << " ";
    }
    return out;
}

/**
 * @brief overload the operator == to compare two vectors
 * 
 * @tparam T the type of the vector
 * @param other the vector to be compared
 * @return true if the vectors are equal
 * @return false if the vectors are not equal
 */

template<class T>
bool NAVector<T>::operator==(const NAVector<T>& other){
    if(this->size==other.size){
        for(int i=0;i<size;i++){
            if(arr[i]==other.arr[i]){
                continue;
            }
            else return false;
        }
        return true;
    }
    else return false;
}

/**
 * @brief overlao the operator < to compare two vectors
 * 
 * @tparam T the type of the vector
 * @param other the vector to be compared
 * @return true return true if the vector is smaller than the other vector
 * @return false return false if the vector is not smaller than the other vector
 */

template<class T>
bool NAVector<T>::operator< (const NAVector<T>& other){
    if(other.size>size){
        return true;
    }else if(size==other.size) {
        for(int j=0;j<size;j++){
            if(arr[j]<other.arr[j]){
                return true;
            }
             if(arr[j]>other.arr[j]) {
                return false;
            }
             else continue;
        }
    }
}

/**
 * @brief resize the vector
 * 
 * @tparam T the type of the vector
 * @return int the new capacity of the vector
 */

template<class T>
int NAVector<T>::resize() {
    T* tmp = new T[capacity*2];
    for(int i = 0; i < capacity; i++){
        tmp[i] = arr[i];
    }
    delete[] arr;
    arr = tmp;
    tmp = nullptr;
    capacity*=2;
    return capacity;
}

/**
 * @brief check if the vector is empty
 * 
 * @tparam T the type of the vector
 * @return true if the vector is empty
 * @return false if the vector is not empty
 */

template<class T>
bool NAVector<T>::empty(){
    return size==0;
}










