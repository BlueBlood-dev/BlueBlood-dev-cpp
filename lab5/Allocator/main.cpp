#include <iostream>
#include <map>
#include <vector>
#include <chrono>
#include "MyAllocator.h"
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

int main() {
    try {
        std::map<unsigned int,unsigned int> chunksInput;
        chunksInput.insert(std::make_pair(40,3));
        chunksInput.insert(std::make_pair(70,5));
        chunksInput.insert(std::make_pair(256,30));
        chunksInput.insert(std::make_pair(256,5));
        chunksInput.insert(std::make_pair(256,5));
        auto begin = chunksInput.begin();
        auto end = chunksInput.end();
        MyAllocator al = MyAllocator<int>(begin,end);
        std::vector<int,MyAllocator<int>> v1(al);
        std::vector<int> opponent;
        auto time1 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i <32; ++i) {
            v1.push_back(1);
        }
        auto time2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double,std::milli> timeTotal = time2 - time1;
        std::cout << v1.size() << std::endl;
        std::cout << "Custom time is " << timeTotal.count() << std::endl;
        time1 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 32; ++i) {
            opponent.push_back(1);
        }
        time2 = std::chrono::high_resolution_clock::now();
        timeTotal = time2 - time1;
        std::cout << "Default time is " << timeTotal.count() << std::endl;
    } catch(std::exception &e){
        std::cout << e.what();
    }
}


