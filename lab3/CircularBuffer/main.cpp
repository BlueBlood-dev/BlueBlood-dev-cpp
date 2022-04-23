#include <iostream>
#include <algorithm>
#include <cassert>
#include "CircleBuff.h"
#include "algorithms.h"

void testIterator(){
    CircleBuff<int> tempBuffer(20);
    for (int i = 17; i >= 0; --i)
        tempBuffer.pushBack(i);
    tempBuffer.pushFront(123);
    //tempBuffer.pushFront(123);
    for(int i =0; i < 20; ++i)
        std::cout << tempBuffer[i] << " ";
    std::cout<<std::endl;

    auto start = tempBuffer.begin();
    auto end = tempBuffer.end();
    std::sort(start,end);
    while(start!=end){
        std::cout << *start << " ";
        start++;
    }
    std::cout << "\nEND OF ITERATOR TESTING\n -----------------------\n";

}


void testPrints(){
    CircleBuff<int> tempBuffer = CircleBuff<int>(10);
    for (int i = 0; i < 7; ++i)
        tempBuffer.pushBack(i);
    tempBuffer.pushBack(7);
    tempBuffer.testPrint();
    tempBuffer.pushFront(-1);
    tempBuffer.testPrint();
    tempBuffer.pushFront(-2);
    tempBuffer.testPrint();
    tempBuffer.pushBack(8);
    tempBuffer.testPrint();
    tempBuffer.pushFront(-3);
    tempBuffer.testPrint();
    tempBuffer.pushFront(-4);
    tempBuffer.testPrint();
    tempBuffer.pushBack(9);
    tempBuffer.testPrint();
    tempBuffer.pushBack(10);
    tempBuffer.testPrint();
    tempBuffer.popBack();
    tempBuffer.pushBack(11);
    tempBuffer.testPrint();
    auto begin = tempBuffer.begin();
    auto end = tempBuffer.end();
    std::cout<< "Output using iterator\n";
    while(begin!=end){
        std::cout << *begin << " ";
        begin++;
    }
    std::cout << std::endl;
}

bool even(int element){
    return element % 2 == 0;
}

void testAlgorithms(){
    std::vector<int> myTestVar = {1,2,3,4,5,6};
    assert(Algs::is_sorted(myTestVar.begin(),myTestVar.end()));
    myTestVar = {2,4,8,10};
    assert(Algs::is_partitioned(myTestVar.begin(),myTestVar.end(),even));
    assert(*Algs::find_not(myTestVar.begin(),myTestVar.end(),2) == 4);
    assert(Algs::is_palindrome(myTestVar.begin(),myTestVar.end(),even));
    myTestVar = {1,2,3,4,5,6};
    assert(Algs::any_of(myTestVar.begin(),myTestVar.end(),even));
    myTestVar = {1,3,5};
    assert(Algs::none_of(myTestVar.begin(),myTestVar.end(),even));
    myTestVar = {1,3,2,5};
    assert(Algs::one_of(myTestVar.begin(),myTestVar.end(),even));
    myTestVar = {2,4,8,10};
    assert(Algs::all_of(myTestVar.begin(),myTestVar.end(),even));
    myTestVar = {1,2,4,8,2,10};
    assert(*Algs::find_backwards(myTestVar.begin(),myTestVar.end(),8) == 8);
}

int main() {
    testIterator();
    testAlgorithms();
    testPrints();
}
