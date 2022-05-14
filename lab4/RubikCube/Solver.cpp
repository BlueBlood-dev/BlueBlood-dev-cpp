//
// Created by blueblood on 14.05.2022.
//

#include "Solver.h"

Solver::Solver(const Cube &cubeToSolve) : cubeToSolve(cubeToSolve) {}

std::string Solver::solve() {
    std::string solution;
    solution += stepOne();
    solution += stepTwo();
    solution += stepThree();
    solution += stepFour();
    solution += stepFive();
    solution += stepSix();
   // solution += stepSeven();
    cubeToSolve.printCube();
    return solution;// + stepN();
}

std::string Solver::stepOne() {
    std::string logToAdd;
    int counter = 0;
    while (true) {
        std::vector<std::vector<char>> reviewedEntity = cubeToSolve.getCubeEntity();
        if (reviewedEntity[0][1] == 'b' && reviewedEntity[4][7] == 'w') { // state 2``(1)
            logToAdd += "F``";
            cubeToSolve.front();
            cubeToSolve.front();
            counter = 0;
        } else if (reviewedEntity[1][1] == 'p' && reviewedEntity[4][5] == 'w') { //state 3``(2)
            logToAdd += "R``";
            cubeToSolve.right();
            cubeToSolve.right();
            counter = 0;
        } else if (reviewedEntity[3][1] == 'r' && reviewedEntity[4][3] == 'w') {//state 5``(3)
            logToAdd += "L``";
            cubeToSolve.left();
            cubeToSolve.left();
            counter = 0;
        } else if (reviewedEntity[2][1] == 'g' && reviewedEntity[4][1] == 'w') {//state 4`` (4)
            logToAdd += "B``";
            cubeToSolve.back();
            cubeToSolve.back();
            counter = 0;
        } else if (reviewedEntity[0][1] == 'w' && reviewedEntity[4][7] == 'b') {//state 6`3`23(5)
            logToAdd += "U`R`FR";
            cubeToSolve.upReversed();
            cubeToSolve.rightReversed();
            cubeToSolve.front();
            cubeToSolve.right();
            counter = 0;
        } else if (reviewedEntity[4][5] == 'p' && reviewedEntity[1][1] == 'w') {//state 6`4`34 (6)
            logToAdd += "U`B`RB";
            cubeToSolve.upReversed();
            cubeToSolve.backReversed();
            cubeToSolve.right();
            cubeToSolve.back();
            counter = 0;
        } else if (reviewedEntity[3][1] == 'w' && reviewedEntity[4][3] == 'r') {//state 6`2`52 (7)
            logToAdd += "U`F`LF";
            cubeToSolve.upReversed();
            cubeToSolve.frontReversed();
            cubeToSolve.left();
            cubeToSolve.front();
            counter = 0;
        } else if (reviewedEntity[2][1] == 'w' && reviewedEntity[4][7] == 'g') {//state 6`5`45 (8)
            logToAdd += "U`L`BL";
            cubeToSolve.upReversed();
            cubeToSolve.leftReversed();
            cubeToSolve.back();
            cubeToSolve.left();
            counter = 0;
        } else if (reviewedEntity[0][5] == 'w') { // state 2`6`2 (9)
            logToAdd += "F`U`F";
            cubeToSolve.frontReversed();
            cubeToSolve.upReversed();
            cubeToSolve.front();
            counter = 0;
        } else if (reviewedEntity[1][5] == 'w') { //// state 3`6`3(10)
            logToAdd += "R`U`R";
            cubeToSolve.rightReversed();
            cubeToSolve.upReversed();
            cubeToSolve.right();
            counter = 0;
        } else if (reviewedEntity[3][5] == 'w') { //state 5`6`5 (11)
            logToAdd += "L`U`L";
            cubeToSolve.leftReversed();
            cubeToSolve.upReversed();
            cubeToSolve.left();
            counter = 0;
        } else if (reviewedEntity[2][5] == 'w') {// state 4`6`4 (12)
            logToAdd += "B`U`B";
            cubeToSolve.backReversed();
            cubeToSolve.upReversed();
            cubeToSolve.back();
            counter = 0;
        } else if (reviewedEntity[0][3] == 'w') { // state 26`2` (13)
            logToAdd += "FU`F`";
            cubeToSolve.front();
            cubeToSolve.upReversed();
            cubeToSolve.frontReversed();
            counter = 0;
        } else if (reviewedEntity[1][3] == 'w') {//state 36`3` (14)
            logToAdd += "RU`R`";
            cubeToSolve.right();
            cubeToSolve.upReversed();
            cubeToSolve.rightReversed();
            counter = 0;
        } else if (reviewedEntity[3][3] == 'w') { //state 56`5` (15)
            logToAdd += "LU`L`";
            cubeToSolve.left();
            cubeToSolve.upReversed();
            cubeToSolve.leftReversed();
            counter = 0;
        } else if (reviewedEntity[2][3] == 'w') {//state 46`4` (16)
            logToAdd += "BU`B`";
            cubeToSolve.back();
            cubeToSolve.upReversed();
            cubeToSolve.backReversed();
            counter = 0;
        } else if ((reviewedEntity[5][1] == 'w' && reviewedEntity[0][7] != 'b') ||
                   reviewedEntity[0][7] == 'w') {//state 2``6`2`` (21)
            logToAdd += "FFU`FF";
            cubeToSolve.front();
            cubeToSolve.front();
            cubeToSolve.upReversed();
            cubeToSolve.front();
            cubeToSolve.front();
            counter = 0;
        } else if ((reviewedEntity[5][5] == 'w' && reviewedEntity[1][7] != 'p') ||
                   reviewedEntity[1][7] == 'w') { //state 3``6`3`` (22)
            logToAdd += "RRU`RR";
            cubeToSolve.right();
            cubeToSolve.right();
            cubeToSolve.upReversed();
            cubeToSolve.right();
            cubeToSolve.right();
            counter = 0;
        } else if ((reviewedEntity[5][3] == 'w' && reviewedEntity[3][7] != 'r') ||
                   reviewedEntity[3][7] == 'w') {//state 5``6`5``
            logToAdd += "LLU`LL";
            cubeToSolve.left();
            cubeToSolve.left();
            cubeToSolve.upReversed();
            cubeToSolve.left();
            cubeToSolve.left();
            counter = 0;
        } else if ((reviewedEntity[5][7] == 'w' && reviewedEntity[2][7] != 'g') ||
                   reviewedEntity[2][7] == 'w') {//state 4``6`4``
            logToAdd += "BBU`BB";
            cubeToSolve.back();
            cubeToSolve.back();
            cubeToSolve.upReversed();
            cubeToSolve.back();
            cubeToSolve.back();
            counter = 0;
        } else {
            cubeToSolve.up();
            logToAdd += "U";
            counter++;
            if (counter == 4)
                break;
        }
    }
    return logToAdd;
}

std::string Solver::stepTwo() {
    std::string logToAdd;
    int counter = 0;
    while (true) {
        std::vector<std::vector<char>> reviewedEntity = cubeToSolve.getCubeEntity();
        if (reviewedEntity[0][7] == 'b' && reviewedEntity[0][2] == 'w' && reviewedEntity[1][0] == 'p' &&
            reviewedEntity[1][7] == 'p' && reviewedEntity[4][8] == 'b') {//1
            logToAdd += "F`U`F";
            cubeToSolve.frontReversed();
            cubeToSolve.upReversed();
            cubeToSolve.front();
            counter = 0;
        } else if (reviewedEntity[0][0] == 'b' && reviewedEntity[0][7] == 'b' && reviewedEntity[4][6] == 'r' &&
                   reviewedEntity[3][7] == 'r' && reviewedEntity[3][2] == 'w') {//2
            logToAdd += "L`U`L";
            cubeToSolve.leftReversed();
            cubeToSolve.upReversed();
            cubeToSolve.left();
            counter = 0;
        } else if (reviewedEntity[2][0] == 'g' && reviewedEntity[2][7] == 'g' && reviewedEntity[4][2] == 'p' &&
                   reviewedEntity[1][2] == 'w' && reviewedEntity[1][7] == 'p') {
            logToAdd += "R`U`R";
            cubeToSolve.rightReversed();
            cubeToSolve.upReversed();
            cubeToSolve.right();
            counter = 0;
        } else if (reviewedEntity[2][7] == 'g' && reviewedEntity[2][2] == 'w' && reviewedEntity[4][0] == 'g' &&
                   reviewedEntity[3][7] == 'r' && reviewedEntity[3][0] == 'r') {
            logToAdd += "B`U`B";
            cubeToSolve.backReversed();
            cubeToSolve.upReversed();
            cubeToSolve.back();
            counter = 0;
        } else if (reviewedEntity[0][2] == 'b' && reviewedEntity[0][7] == 'b' && reviewedEntity[4][8] == 'p' &&
                   reviewedEntity[1][0] == 'w' && reviewedEntity[1][7] == 'p') {
            logToAdd += "RUR`";
            cubeToSolve.right();
            cubeToSolve.up();
            cubeToSolve.rightReversed();
            counter = 0;
        } else if (reviewedEntity[0][0] == 'w' && reviewedEntity[0][7] == 'b' && reviewedEntity[3][2] == 'r' &&
                   reviewedEntity[3][7] == 'r' && reviewedEntity[4][6] == 'b') {
            logToAdd += "FUF`";
            cubeToSolve.front();
            cubeToSolve.up();
            cubeToSolve.frontReversed();
            counter = 0;
        } else if (reviewedEntity[2][0] == 'w' && reviewedEntity[2][7] == 'g' && reviewedEntity[1][2] == 'p' &&
                   reviewedEntity[3][7] == 'p' && reviewedEntity[4][2] == 'g') {
            logToAdd += "BUB`";
            cubeToSolve.back();
            cubeToSolve.up();
            cubeToSolve.backReversed();
            counter = 0;
        } else if (reviewedEntity[2][2] == 'g' && reviewedEntity[2][7] == 'g' && reviewedEntity[3][0] == 'w' &&
                   reviewedEntity[3][7] == 'r' && reviewedEntity[4][0] == 'r') {
            logToAdd += "LUL`";
            cubeToSolve.left();
            cubeToSolve.up();
            cubeToSolve.leftReversed();
            counter = 0;
        } else if (reviewedEntity[0][2] == 'p' && reviewedEntity[0][7] == 'b' && reviewedEntity[4][8] == 'w' &&
                   reviewedEntity[1][0] == 'b' && reviewedEntity[1][7] == 'p') {
            logToAdd += "RU`R`UURUR`";
            cubeToSolve.right();
            cubeToSolve.upReversed();
            cubeToSolve.rightReversed();
            cubeToSolve.up();
            cubeToSolve.up();
            cubeToSolve.right();
            cubeToSolve.up();
            cubeToSolve.rightReversed();
            counter = 0;
        } else if (reviewedEntity[0][0] == 'r' && reviewedEntity[0][7] == 'b' && reviewedEntity[3][2] == 'b' &&
                   reviewedEntity[3][7] == 'r' && reviewedEntity[4][6] == 'w') {
            logToAdd += "FU`F`UUFUF`";
            cubeToSolve.front();
            cubeToSolve.upReversed();
            cubeToSolve.frontReversed();
            cubeToSolve.up();
            cubeToSolve.up();
            cubeToSolve.front();
            cubeToSolve.up();
            cubeToSolve.frontReversed();
            counter = 0;
        } else if (reviewedEntity[2][0] == 'p' && reviewedEntity[2][7] == 'g' && reviewedEntity[4][2] == 'w' &&
                   reviewedEntity[1][2] == 'g' && reviewedEntity[1][7] == 'p') {
            logToAdd += "BU`B`UUBUB`";
            cubeToSolve.back();
            cubeToSolve.upReversed();
            cubeToSolve.backReversed();
            cubeToSolve.up();
            cubeToSolve.up();
            cubeToSolve.back();
            cubeToSolve.up();
            cubeToSolve.backReversed();
            counter = 0;
        } else if (reviewedEntity[2][2] == 'r' && reviewedEntity[2][7] == 'g' && reviewedEntity[4][0] == 'w' &&
                   reviewedEntity[3][0] == 'g' && reviewedEntity[3][7] == 'r') {
            logToAdd += "LU`L`UULUL`";
            cubeToSolve.left();
            cubeToSolve.upReversed();
            cubeToSolve.leftReversed();
            cubeToSolve.up();
            cubeToSolve.up();
            cubeToSolve.left();
            cubeToSolve.up();
            cubeToSolve.leftReversed();
            counter = 0;
        } else if ((reviewedEntity[0][7] == 'b' && reviewedEntity[0][8] == 'w' && reviewedEntity[1][7] == 'p') ||
                   (reviewedEntity[0][7] == 'b' && reviewedEntity[1][6] == 'w' && reviewedEntity[1][7] == 'p')) {
            logToAdd += "F`U`F";
            cubeToSolve.frontReversed();
            cubeToSolve.upReversed();
            cubeToSolve.front();
            counter = 0;
        } else if ((reviewedEntity[0][7] == 'b' && reviewedEntity[3][7] == 'r' && reviewedEntity[3][8] == 'w') ||
                   (reviewedEntity[0][6] == 'w' && reviewedEntity[0][7] == 'b' && reviewedEntity[3][7] == 'r')) {
            logToAdd += "L`U`L";
            cubeToSolve.leftReversed();
            cubeToSolve.upReversed();
            cubeToSolve.left();
            counter = 0;
        } else if ((reviewedEntity[2][7] == 'g' && reviewedEntity[1][8] == 'w' && reviewedEntity[1][7] == 'p') ||
                   (reviewedEntity[2][6] == 'w' && reviewedEntity[2][7] == 'g' && reviewedEntity[1][7] == 'p')) {
            logToAdd += "R`U`R";
            cubeToSolve.rightReversed();
            cubeToSolve.upReversed();
            cubeToSolve.right();
            counter = 0;
        } else if ((reviewedEntity[2][7] == 'g' && reviewedEntity[2][8] == 'w' && reviewedEntity[3][7] == 'r') ||
                   (reviewedEntity[2][7] == 'g' && reviewedEntity[3][6] == 'w' && reviewedEntity[3][7] == 'r')) {
            logToAdd += "B`U`B";
            cubeToSolve.backReversed();
            cubeToSolve.upReversed();
            cubeToSolve.back();
        } else if (reviewedEntity[5][0] == 'w' && reviewedEntity[5][1] == 'w' && reviewedEntity[5][3] == 'w' &&
                   reviewedEntity[5][4] == 'w' && reviewedEntity[5][5] == 'w' && reviewedEntity[5][7] == 'w' &&
                   reviewedEntity[3][7] == 'r' && (reviewedEntity[3][8] != 'r' || reviewedEntity[0][6] != 'b')) {
            logToAdd += "FU`F`";
            cubeToSolve.front();
            cubeToSolve.upReversed();
            cubeToSolve.frontReversed();
            counter = 0;
        } else if (reviewedEntity[5][1] == 'w' && reviewedEntity[5][2] == 'w' && reviewedEntity[5][3] == 'w' &&
                   reviewedEntity[5][4] == 'w' && reviewedEntity[5][5] == 'w' && reviewedEntity[5][7] == 'w' &&
                   reviewedEntity[0][7] == 'b' && reviewedEntity[1][7] == 'p' &&
                   (reviewedEntity[0][8] != 'b' || reviewedEntity[1][6] != 'p')) {
            logToAdd += "RU`R`";
            cubeToSolve.right();
            cubeToSolve.upReversed();
            cubeToSolve.rightReversed();
            counter = 0;
        } else if (reviewedEntity[5][1] == 'w' && reviewedEntity[5][3] == 'w' && reviewedEntity[5][4] == 'w' &&
                   reviewedEntity[5][5] == 'w' && reviewedEntity[5][7] == 'w' && reviewedEntity[5][8] == 'w' &&
                   reviewedEntity[2][7] == 'g' && reviewedEntity[1][7] == 'p' &&
                   (reviewedEntity[1][8] != 'p' || reviewedEntity[2][6] != 'g')) {
            logToAdd += "BU`B`";
            cubeToSolve.back();
            cubeToSolve.upReversed();
            cubeToSolve.backReversed();
            counter = 0;
        } else if (reviewedEntity[5][1] == 'w' && reviewedEntity[5][3] == 'w' && reviewedEntity[5][4] == 'w' &&
                   reviewedEntity[5][5] == 'w' && reviewedEntity[5][6] == 'w' && reviewedEntity[5][7] == 'w' &&
                   reviewedEntity[2][7] == 'g' && reviewedEntity[3][7] == 'r' &&
                   (reviewedEntity[2][8] != 'g' || reviewedEntity[3][6] != 'r')) {
            logToAdd += "LU`L`";
            cubeToSolve.left();
            cubeToSolve.upReversed();
            cubeToSolve.leftReversed();
            counter = 0;
        } else {
            cubeToSolve.up();
            counter++;
            if (counter == 4)
                break;
        }
    }
    return logToAdd;
}

std::string Solver::stepThree() {
    std::string logToAdd;
    while (true) {
        int counter = 0;
        while (true) {
            std::vector<std::vector<char>> reviewedEntity = cubeToSolve.getCubeEntity();
            if (reviewedEntity[0][1] == 'b' && reviewedEntity[0][6] == 'b' && reviewedEntity[0][7] == 'b' &&
                reviewedEntity[0][8] == 'b' && reviewedEntity[4][7] == 'r' && reviewedEntity[3][6] == 'r' &&
                reviewedEntity[3][7] == 'r' && reviewedEntity[3][8] == 'r') {
                logToAdd += "U`L`ULUFU`F`";
                cubeToSolve.upReversed();
                cubeToSolve.leftReversed();
                cubeToSolve.up();
                cubeToSolve.left();
                cubeToSolve.up();
                cubeToSolve.front();
                cubeToSolve.upReversed();
                cubeToSolve.frontReversed();
                counter = 0;
            } else if (reviewedEntity[0][6] == 'b' && reviewedEntity[0][7] == 'b' && reviewedEntity[0][8] == 'b' &&
                       reviewedEntity[1][1] == 'p' && reviewedEntity[1][6] == 'p' && reviewedEntity[1][7] == 'p' &&
                       reviewedEntity[1][8] == 'p' && reviewedEntity[4][5] == 'b') {
                logToAdd += "U`F`UFURU`R`";
                cubeToSolve.upReversed();
                cubeToSolve.frontReversed();
                cubeToSolve.up();
                cubeToSolve.front();
                cubeToSolve.up();
                cubeToSolve.right();
                cubeToSolve.upReversed();
                cubeToSolve.rightReversed();
                counter = 0;
            } else if (reviewedEntity[2][1] == 'g' && reviewedEntity[2][6] == 'g' && reviewedEntity[2][7] == 'g' &&
                       reviewedEntity[2][8] == 'g' && reviewedEntity[4][1] == 'p' && reviewedEntity[1][6] == 'p' &&
                       reviewedEntity[1][7] == 'p' && reviewedEntity[1][8] == 'p') {
                logToAdd += "U`R`URUBU`B`";
                cubeToSolve.upReversed();
                cubeToSolve.rightReversed();
                cubeToSolve.up();
                cubeToSolve.right();
                cubeToSolve.up();
                cubeToSolve.back();
                cubeToSolve.upReversed();
                cubeToSolve.backReversed();
                counter = 0;
            } else if (reviewedEntity[2][6] == 'g' && reviewedEntity[2][7] == 'g' && reviewedEntity[2][8] == 'g' &&
                       reviewedEntity[3][1] == 'r' && reviewedEntity[3][6] == 'r' && reviewedEntity[3][7] == 'r' &&
                       reviewedEntity[3][8] == 'r' && reviewedEntity[4][3] == 'g') {
                logToAdd += "U`B`UBULU`L`";
                cubeToSolve.upReversed();
                cubeToSolve.backReversed();
                cubeToSolve.up();
                cubeToSolve.back();
                cubeToSolve.up();
                cubeToSolve.left();
                cubeToSolve.upReversed();
                cubeToSolve.leftReversed();
                counter = 0;
            } else if (reviewedEntity[0][1] == 'b' && reviewedEntity[0][6] == 'b' && reviewedEntity[0][7] == 'b' &&
                       reviewedEntity[0][8] == 'b' && reviewedEntity[4][7] == 'p' && reviewedEntity[1][6] == 'p' &&
                       reviewedEntity[1][7] == 'p' && reviewedEntity[1][8] == 'p') {
                logToAdd += "URU`R`U`F`UF";
                cubeToSolve.up();
                cubeToSolve.right();
                cubeToSolve.upReversed();
                cubeToSolve.rightReversed();
                cubeToSolve.upReversed();
                cubeToSolve.frontReversed();
                cubeToSolve.up();
                cubeToSolve.front();
                counter = 0;
            } else if (reviewedEntity[0][6] == 'b' && reviewedEntity[0][7] == 'b' && reviewedEntity[0][8] == 'b' &&
                       reviewedEntity[4][3] == 'b' && reviewedEntity[3][1] == 'r' && reviewedEntity[3][6] == 'r' &&
                       reviewedEntity[3][7] == 'r' && reviewedEntity[3][8] == 'r') {
                logToAdd += "UFU`F`U`L`UL";
                cubeToSolve.up();
                cubeToSolve.front();
                cubeToSolve.upReversed();
                cubeToSolve.frontReversed();
                cubeToSolve.upReversed();
                cubeToSolve.leftReversed();
                cubeToSolve.up();
                cubeToSolve.left();
                counter = 0;
            } else if (reviewedEntity[2][1] == 'g' && reviewedEntity[2][6] == 'g' && reviewedEntity[2][7] == 'g' &&
                       reviewedEntity[2][8] == 'g' && reviewedEntity[3][6] == 'r' && reviewedEntity[3][7] == 'r' &&
                       reviewedEntity[3][8] == 'r' && reviewedEntity[4][1] == 'r') {
                logToAdd += "ULU`L`U`B`UB";
                cubeToSolve.up();
                cubeToSolve.left();
                cubeToSolve.upReversed();
                cubeToSolve.leftReversed();
                cubeToSolve.upReversed();
                cubeToSolve.backReversed();
                cubeToSolve.up();
                cubeToSolve.back();
                counter = 0;
            } else if (reviewedEntity[2][7] == 'g' && reviewedEntity[2][6] == 'g' && reviewedEntity[2][8] == 'g' &&
                       reviewedEntity[4][5] == 'g' && reviewedEntity[1][1] == 'p' && reviewedEntity[1][6] == 'p' &&
                       reviewedEntity[1][7] == 'p' && reviewedEntity[1][8] == 'p') {
                logToAdd += "UBU`B`U`R`UR";
                cubeToSolve.up();
                cubeToSolve.back();
                cubeToSolve.upReversed();
                cubeToSolve.backReversed();
                cubeToSolve.upReversed();
                cubeToSolve.rightReversed();
                cubeToSolve.up();
                cubeToSolve.right();
                counter = 0;
            } else {
                cubeToSolve.up();
                logToAdd += "U";
                counter++;
                if (counter == 4)
                    break;
            }
        }
        std::vector<std::vector<char>> reviewedEntity = cubeToSolve.getCubeEntity();
        if (reviewedEntity[0][6] == 'b' && reviewedEntity[0][7] == 'b' && reviewedEntity[0][8] == 'b' &&
            reviewedEntity[1][6] == 'p' && reviewedEntity[1][7] == 'p' && reviewedEntity[1][8] == 'p' &&
            (reviewedEntity[0][5] != 'b' || reviewedEntity[1][3] != 'p')) {
            logToAdd += "URU`R`U`F`UF";
            cubeToSolve.up();
            cubeToSolve.right();
            cubeToSolve.upReversed();
            cubeToSolve.rightReversed();
            cubeToSolve.upReversed();
            cubeToSolve.frontReversed();
            cubeToSolve.up();
            cubeToSolve.front();
        } else if (reviewedEntity[0][6] == 'b' && reviewedEntity[0][7] == 'b' && reviewedEntity[0][8] == 'b' &&
                   reviewedEntity[3][6] == 'r' && reviewedEntity[3][7] == 'r' && reviewedEntity[3][8] == 'r' &&
                   (reviewedEntity[0][3] != 'b' || reviewedEntity[3][5] != 'r')) {
            logToAdd += "UFU`F`U`L`UL";
            cubeToSolve.up();
            cubeToSolve.front();
            cubeToSolve.upReversed();
            cubeToSolve.frontReversed();
            cubeToSolve.upReversed();
            cubeToSolve.leftReversed();
            cubeToSolve.up();
            cubeToSolve.left();
        } else if (reviewedEntity[2][6] == 'g' && reviewedEntity[2][7] == 'g' && reviewedEntity[2][8] == 'g' &&
                   reviewedEntity[3][6] == 'r' && reviewedEntity[3][7] == 'r' & reviewedEntity[3][8] == 'r' &&
                   (reviewedEntity[3][3] != 'r' || reviewedEntity[2][5] != 'g')) {
            logToAdd += "ULU`L`U`B`UB";
            cubeToSolve.up();
            cubeToSolve.left();
            cubeToSolve.upReversed();
            cubeToSolve.leftReversed();
            cubeToSolve.upReversed();
            cubeToSolve.backReversed();
            cubeToSolve.up();
            cubeToSolve.back();
        } else if (reviewedEntity[2][6] == 'g' && reviewedEntity[2][7] == 'g' && reviewedEntity[2][8] == 'g' &&
                   reviewedEntity[1][6] == 'p' && reviewedEntity[1][7] == 'p' && reviewedEntity[1][8] == 'p' &&
                   (reviewedEntity[2][3] != 'g' || reviewedEntity[1][5] != 'p')) {
            logToAdd += "UBU`B`U`R`UR";
            cubeToSolve.up();
            cubeToSolve.back();
            cubeToSolve.upReversed();
            cubeToSolve.backReversed();
            cubeToSolve.upReversed();
            cubeToSolve.rightReversed();
            cubeToSolve.up();
            cubeToSolve.right();
        } else {
            break;
        }
    }
    return logToAdd;
}

std::string Solver::stepFour() {
    std::string logToAdd;
    std::vector<std::vector<char>> reviewedEntity = cubeToSolve.getCubeEntity();
    if (reviewedEntity[0][1] == 'o' && reviewedEntity[1][1] == 'o' && reviewedEntity[4][1] == 'o' &&
        reviewedEntity[4][3] == 'o') {
        logToAdd += "FURU`R`F`";
        cubeToSolve.front();
        cubeToSolve.up();
        cubeToSolve.right();
        cubeToSolve.upReversed();
        cubeToSolve.rightReversed();
        cubeToSolve.frontReversed();
    } else if (reviewedEntity[0][1] == 'o' && reviewedEntity[4][1] == 'o' && reviewedEntity[3][1] == 'o' &&
               reviewedEntity[4][5] == 'o') {
        logToAdd += "LUFU`F`L`";
        cubeToSolve.left();
        cubeToSolve.up();
        cubeToSolve.front();
        cubeToSolve.upReversed();
        cubeToSolve.frontReversed();
        cubeToSolve.leftReversed();
    } else if (reviewedEntity[2][1] == 'o' && reviewedEntity[1][1] == 'o' && reviewedEntity[4][7] == 'o' &&
               reviewedEntity[4][3] == 'o') {
        logToAdd += "RUBU`B`R`";
        cubeToSolve.right();
        cubeToSolve.up();
        cubeToSolve.back();
        cubeToSolve.upReversed();
        cubeToSolve.backReversed();
        cubeToSolve.rightReversed();
    } else if (reviewedEntity[2][1] == 'o' && reviewedEntity[4][7] == 'o' && reviewedEntity[4][5] == 'o' &&
               reviewedEntity[3][1] == 'o') {
        logToAdd += "BULU`L`B`";
        cubeToSolve.back();
        cubeToSolve.up();
        cubeToSolve.left();
        cubeToSolve.upReversed();
        cubeToSolve.leftReversed();
        cubeToSolve.backReversed();
    } else if (reviewedEntity[0][1] == 'o' && reviewedEntity[4][3] == 'o' && reviewedEntity[4][5] == 'o' &&
               reviewedEntity[2][1] == 'o') {
        logToAdd += "FRUR`U`F`";
        cubeToSolve.front();
        cubeToSolve.right();
        cubeToSolve.up();
        cubeToSolve.rightReversed();
        cubeToSolve.upReversed();
        cubeToSolve.frontReversed();
    } else if (reviewedEntity[4][1] == 'o' && reviewedEntity[4][7] == 'o' && reviewedEntity[1][1] == 'o' &&
               reviewedEntity[3][1] == 'o') {
        logToAdd += "RBUB`U`R`";
        cubeToSolve.right();
        cubeToSolve.back();
        cubeToSolve.up();
        cubeToSolve.backReversed();
        cubeToSolve.upReversed();
        cubeToSolve.rightReversed();
    } else if (reviewedEntity[0][1] == 'o' && reviewedEntity[1][1] == 'o' && reviewedEntity[3][1] == 'o' &&
               reviewedEntity[2][1] == 'o') {
        logToAdd += "FURU`R`F`RBUB`U`R`";
        cubeToSolve.front();
        cubeToSolve.up();
        cubeToSolve.right();
        cubeToSolve.upReversed();
        cubeToSolve.rightReversed();
        cubeToSolve.frontReversed();
        cubeToSolve.right();
        cubeToSolve.back();
        cubeToSolve.up();
        cubeToSolve.backReversed();
        cubeToSolve.upReversed();
        cubeToSolve.rightReversed();
    }
    return logToAdd;
}

std::string Solver::stepFive() {
    std::string logToAdd;
    std::vector<std::vector<char>> reviewedEntity = cubeToSolve.getCubeEntity();
    if (reviewedEntity[1][1] == 'b') {
        logToAdd += "UL`UULUL`UL";
        cubeToSolve.up();
        cubeToSolve.leftReversed();
        cubeToSolve.up();
        cubeToSolve.up();
        cubeToSolve.left();
        cubeToSolve.up();
        cubeToSolve.leftReversed();
        cubeToSolve.up();
        cubeToSolve.left();
    } else if (reviewedEntity[3][1] == 'b') {
        logToAdd += "UB`UUBUB`UB"; //  logToAdd += "UR`UURUR`URUB`UUBUB`UBUR`UURUR`UR"
        cubeToSolve.up();
        cubeToSolve.backReversed();
        cubeToSolve.up();
        cubeToSolve.up();
        cubeToSolve.back();
        cubeToSolve.up();
        cubeToSolve.backReversed();
        cubeToSolve.up();
        cubeToSolve.back();
    } else if (reviewedEntity[2][1] == 'b') {
        logToAdd += "UR`UURUR`URUB`UUBUB`UBUR`UURUR`UR";
        cubeToSolve.up();
        cubeToSolve.rightReversed();
        cubeToSolve.up();
        cubeToSolve.up();
        cubeToSolve.right();
        cubeToSolve.up();
        cubeToSolve.rightReversed();
        cubeToSolve.up();
        cubeToSolve.right();
        cubeToSolve.up();
        cubeToSolve.backReversed();
        cubeToSolve.up();
        cubeToSolve.up();
        cubeToSolve.back();
        cubeToSolve.up();
        cubeToSolve.backReversed();
        cubeToSolve.up();
        cubeToSolve.back();
        cubeToSolve.up();
        cubeToSolve.rightReversed();
        cubeToSolve.up();
        cubeToSolve.up();
        cubeToSolve.right();
        cubeToSolve.up();
        cubeToSolve.rightReversed();
        cubeToSolve.up();
        cubeToSolve.right();
    }
    reviewedEntity = cubeToSolve.getCubeEntity();
    if (reviewedEntity[2][1] == 'p') {
        logToAdd += "UF`UUFUF`UF";
        cubeToSolve.up();
        cubeToSolve.frontReversed();
        cubeToSolve.up();
        cubeToSolve.up();
        cubeToSolve.front();
        cubeToSolve.up();
        cubeToSolve.frontReversed();
        cubeToSolve.up();
        cubeToSolve.front();
    } else if (reviewedEntity[3][1] == 'p') {
        logToAdd += "UB`UUBUB`UBUL`UULUL`ULUB`UUBUB`UB";
        cubeToSolve.up();
        cubeToSolve.backReversed();
        cubeToSolve.up();
        cubeToSolve.up();
        cubeToSolve.back();
        cubeToSolve.up();
        cubeToSolve.backReversed();
        cubeToSolve.up();
        cubeToSolve.back();
        cubeToSolve.up();
        cubeToSolve.leftReversed();
        cubeToSolve.up();
        cubeToSolve.up();
        cubeToSolve.left();
        cubeToSolve.up();
        cubeToSolve.leftReversed();
        cubeToSolve.up();
        cubeToSolve.left();
        cubeToSolve.up();
        cubeToSolve.backReversed();
        cubeToSolve.up();
        cubeToSolve.up();
        cubeToSolve.back();
        cubeToSolve.up();
        cubeToSolve.backReversed();
        cubeToSolve.up();
        cubeToSolve.back();
    }
    reviewedEntity = cubeToSolve.getCubeEntity();

    if (reviewedEntity[3][1] == 'g') {
        logToAdd += "UR`UURUR`UR";
        cubeToSolve.up();
        cubeToSolve.rightReversed();
        cubeToSolve.up();
        cubeToSolve.up();
        cubeToSolve.right();
        cubeToSolve.up();
        cubeToSolve.rightReversed();
        cubeToSolve.up();
        cubeToSolve.right();
    }
    return logToAdd;
}

std::string Solver::stepSix() {
    std::string logToAdd;
    std::vector<std::vector<char>> reviewedEntity = cubeToSolve.getCubeEntity();

    if ((reviewedEntity[3][2] == 'b' && reviewedEntity[0][0] == 'p' && reviewedEntity[4][6] == 'o') ||
        (reviewedEntity[3][2] == 'b' && reviewedEntity[0][0] == 'o' && reviewedEntity[4][6] == 'p') ||
        (reviewedEntity[3][2] == 'p' && reviewedEntity[0][0] == 'b' && reviewedEntity[4][6] == 'o') ||
        (reviewedEntity[3][2] == 'p' && reviewedEntity[0][0] == 'o' && reviewedEntity[4][6] == 'b') ||
        (reviewedEntity[3][2] == 'o' && reviewedEntity[0][0] == 'b' && reviewedEntity[4][6] == 'p') ||
        (reviewedEntity[3][2] == 'o' && reviewedEntity[0][0] == 'p' && reviewedEntity[4][6] == 'b')) {
        logToAdd += "F`L`FR`F`LFR";
        cubeToSolve.frontReversed();
        cubeToSolve.leftReversed();
        cubeToSolve.front();
        cubeToSolve.rightReversed();
        cubeToSolve.frontReversed();
        cubeToSolve.left();
        cubeToSolve.front();
        cubeToSolve.right();
    } else if ((reviewedEntity[1][2] == 'b' && reviewedEntity[2][0] == 'p' && reviewedEntity[4][2] == 'o') ||
               (reviewedEntity[1][2] == 'b' && reviewedEntity[2][0] == 'o' && reviewedEntity[4][2] == 'p') ||
               (reviewedEntity[1][2] == 'p' && reviewedEntity[2][0] == 'o' && reviewedEntity[4][2] == 'b') ||
               (reviewedEntity[1][2] == 'p' && reviewedEntity[2][0] == 'b' && reviewedEntity[4][2] == 'o') ||
               (reviewedEntity[1][2] == 'o' && reviewedEntity[2][0] == 'b' && reviewedEntity[4][2] == 'p') ||
               (reviewedEntity[1][2] == 'o' && reviewedEntity[2][0] == 'p' && reviewedEntity[4][2] == 'b')) {
        logToAdd += "R`F`L`FRF`LF";
        cubeToSolve.rightReversed();
        cubeToSolve.frontReversed();
        cubeToSolve.leftReversed();
        cubeToSolve.front();
        cubeToSolve.right();
        cubeToSolve.frontReversed();
        cubeToSolve.left();
        cubeToSolve.front();
    } else if ((reviewedEntity[2][2] == 'b' && reviewedEntity[3][0] == 'o' && reviewedEntity[4][0] == 'p') ||
               (reviewedEntity[2][2] == 'b' && reviewedEntity[3][0] == 'p' && reviewedEntity[4][0] == 'o') ||
               (reviewedEntity[2][2] == 'p' && reviewedEntity[3][0] == 'o' && reviewedEntity[4][0] == 'b') ||
               (reviewedEntity[2][2] == 'p' && reviewedEntity[3][0] == 'b' && reviewedEntity[4][0] == 'o') ||
               (reviewedEntity[2][2] == 'o' && reviewedEntity[3][0] == 'p' && reviewedEntity[4][0] == 'b') ||
               (reviewedEntity[2][2] == 'o' && reviewedEntity[3][0] == 'b' && reviewedEntity[4][0] == 'p')) {
        logToAdd += "F`L`B`LFL`BL";
        cubeToSolve.frontReversed();
        cubeToSolve.leftReversed();
        cubeToSolve.backReversed();
        cubeToSolve.left();
        cubeToSolve.front();
        cubeToSolve.leftReversed();
        cubeToSolve.back();
        cubeToSolve.left();
    }

    reviewedEntity = cubeToSolve.getCubeEntity();
    if ((reviewedEntity[0][0] == 'p' && reviewedEntity[3][2] == 'g' && reviewedEntity[4][6] == 'o') ||
        (reviewedEntity[0][0] == 'p' && reviewedEntity[3][2] == 'o' && reviewedEntity[4][6] == 'g') ||
        (reviewedEntity[0][0] == 'g' && reviewedEntity[3][2] == 'o' && reviewedEntity[4][6] == 'p') ||
        (reviewedEntity[0][0] == 'g' && reviewedEntity[3][2] == 'p' && reviewedEntity[4][6] == 'o') ||
        (reviewedEntity[0][0] == 'o' && reviewedEntity[3][2] == 'g' && reviewedEntity[4][6] == 'p') ||
        (reviewedEntity[0][0] == 'o' && reviewedEntity[3][2] == 'p' && reviewedEntity[4][6] == 'g')) {
        logToAdd += "B`R`BL`B`RBL";
        cubeToSolve.backReversed();
        cubeToSolve.rightReversed();
        cubeToSolve.back();
        cubeToSolve.leftReversed();
        cubeToSolve.backReversed();
        cubeToSolve.right();
        cubeToSolve.back();
        cubeToSolve.left();
    } else if((reviewedEntity[2][2] == 'g' && reviewedEntity[3][0] == 'o' && reviewedEntity[4][0] == 'p') ||
            (reviewedEntity[2][2] == 'g' && reviewedEntity[3][0] == 'p' && reviewedEntity[4][0] == 'o') ||
            (reviewedEntity[2][2] == 'p' && reviewedEntity[3][0] == 'g' && reviewedEntity[4][0] == 'o') ||
            (reviewedEntity[2][2] == 'p' && reviewedEntity[3][0] == 'o' && reviewedEntity[4][0] == 'g') ||
            (reviewedEntity[2][2] == 'o' && reviewedEntity[3][0] == 'g' && reviewedEntity[4][0] == 'p') ||
            (reviewedEntity[2][2] == 'o' && reviewedEntity[3][0] == 'p' && reviewedEntity[4][0] == 'g')){
        logToAdd += "L`B`R`BLB`RB";
        cubeToSolve.leftReversed();
        cubeToSolve.backReversed();
        cubeToSolve.rightReversed();
        cubeToSolve.back();
        cubeToSolve.left();
        cubeToSolve.backReversed();
        cubeToSolve.right();
        cubeToSolve.back();
    }
    return  logToAdd;
}

std::string Solver::stepSeven() {
    std::string logToAdd;
    std::vector<std::vector<char>> reviewedEntity = cubeToSolve.getCubeEntity();
    if(reviewedEntity[1][0] == 'o'){
        logToAdd += "F`RFR`F`RFR`";
        cubeToSolve.frontReversed();
        cubeToSolve.right();
        cubeToSolve.front();
        cubeToSolve.rightReversed();
        cubeToSolve.frontReversed();
        cubeToSolve.right();
        cubeToSolve.front();
        cubeToSolve.rightReversed();
    }else if(reviewedEntity[0][2] == 'o'){
        logToAdd += "RF`R`FRF`R`F";
        cubeToSolve.right();
        cubeToSolve.frontReversed();
        cubeToSolve.rightReversed();
        cubeToSolve.front();
        cubeToSolve.right();
        cubeToSolve.frontReversed();
        cubeToSolve.rightReversed();
        cubeToSolve.front();
    } else {
        cubeToSolve.up();
        logToAdd += "U";
    }
    for (int i = 0; i < 4; ++i) {
        reviewedEntity = cubeToSolve.getCubeEntity();
        if(reviewedEntity[1][0] == 'o'){
            logToAdd += "F`RFR`F`RFR`";
            cubeToSolve.frontReversed();
            cubeToSolve.right();
            cubeToSolve.front();
            cubeToSolve.rightReversed();
            cubeToSolve.frontReversed();
            cubeToSolve.right();
            cubeToSolve.front();
            cubeToSolve.rightReversed();
        }else if(reviewedEntity[0][2] == 'o'){
            logToAdd += "RF`R`FRF`R`F";
            cubeToSolve.right();
            cubeToSolve.frontReversed();
            cubeToSolve.rightReversed();
            cubeToSolve.front();
            cubeToSolve.right();
            cubeToSolve.frontReversed();
            cubeToSolve.rightReversed();
            cubeToSolve.front();
        }
        cubeToSolve.up();
        logToAdd += "U";
    }
    int counter = 0;
    while(!cubeToSolve.isSolved()){
        cubeToSolve.up();
        logToAdd+="U";
        counter++;
        if(counter == 4)
            throw std::invalid_argument("Rubik invariant, change input");
    }
    return  logToAdd;

}


Solver::~Solver() = default;
