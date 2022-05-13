////
//// Created by blueblood on 07.05.2022.
////
//
//#include "App.h"
//#include <iostream>
//#include <fstream>
//#include "Cube.cpp"
//
//void App::startApp() {
//    std::cout
//            << "Hi, this is a RubikCube solver!\n----------------------------\n";
//    std::string command;
//    Cube cube = Cube();
//    while(true){ // check if input from cstr is required
//        std::cin >> command;
//        if(command == "--setFromInput")
//            if(cube.getCorners().empty()){
//                std::ifstream in("input.in");
//                // parse required
//            }
//        if(command == "--exit")
//            break;
//    }
//
//}
//
//
//void App::help() {
//    std::cout << "\nList of provided commands is:\n1)--setFromInput\n2)--help\n3)--solve4)--printCurrent\n5)--saveToFile\n";
//}