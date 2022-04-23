#include <iostream>
#include <algorithm>
#include "CircleBuff.h"
#include "algorithms.h"

void testIterator(){
    CircleBuff<int> tempBuffer(20);
    for (int i = 0; i < 18; ++i)
        tempBuffer.pushBack(rand() % 1000);
    tempBuffer.pushFront(123);
    tempBuffer.pushFront(123);
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
}

bool even(int element){
    return element % 2 == 0;
}

void testAlgorithms(){
    std::vector<int> myTestVar = {1,2,3,4,5,6};
    if(Algs::is_sorted(myTestVar.begin(),myTestVar.end()))
        std::cout << "SORTED\n";
    myTestVar = {2,4,8,10};
   if(Algs::is_partitioned(myTestVar.begin(),myTestVar.end(),even))
        std::cout<< "PARTITIONED\n";

   auto element = *Algs::find_not(myTestVar.begin(),myTestVar.end(),2);
        std::cout << "the element due to FIND_NOT is "  << element << std::endl;
    //etc... 
}



int main() {
    testIterator();
    //testPrints();
    testAlgorithms();
}
