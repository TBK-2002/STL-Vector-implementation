#include "NAVector.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template <class T>
NAVector<T>::NAVector(int n)
{
    capacity = n;
    size = 0;
    arr = new T(capacity);
}

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

template <class T>
NAVector<T>::NAVector(const NAVector &other){
    this->size = other.size;
    this->capacity=other.capacity;
    this->arr = new T[capacity];
    for(int i = 0; i < size; i++){
        this->arr[i] = other.arr[i];
    }
};

template<class T>
NAVector<T>::~NAVector(){
    if(arr != nullptr){
        delete[] arr;
    }
}

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

template<class T>
NAVector<T>& NAVector<T>::operator=(const NAVector&& other){
    this->size = other.size;
    this->capacity=other.capacity;
    delete[] this-> arr;
    this->arr = other.arr;
    other.arr = nullptr;
}

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

template<class T>
T NAVector<T>::pop_back(){
    size--;
    return arr[size-1];
}

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

template<class T>
void NAVector<T>::erase(iterator it1, iterator it2){
    // Implement de ya tolba hat8ayr 7aga wa7da bas fel loop el fatet
    // w bos 3ala el comments el makotba 3an el function de fe header file
}


template<class T>
void NAVector<T>::clear(){
    size = 0;;
}

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


template<class T>
T* NAVector<T>::begin(){
    return arr;
}

template<class T>
T* NAVector<T>::end(){
    return arr+size;
}

// Comparison operations




template <class T>
const int NAVector<T>::sz()
{
    return size;
}

template <class T>
const int NAVector<T>::cap()
{
    return capacity;
}

template<class T>
std::ostream& operator<<(ostream& out, const NAVector<T>& other){
    for(int i = 0; i < other.size; i++){
        out << other.arr[i] << " ";
    }
    return out;
}
