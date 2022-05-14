//

#include "Cube.h"
#include <iostream>
#include <fstream>
#include "Solver.cpp"

Cube::Cube(std::vector<std::vector<char>> cubeEntity) : CubeEntity(std::move(cubeEntity)) {
    if(!checkInput(cubeEntity))
        throw std::invalid_argument("Wrong input");

}

Cube::Cube() = default;

Cube::~Cube() = default;

std::string Cube::getSolution() const {
    return Solver(Cube(CubeEntity)).solve();
}

void Cube::printCube() {
    std::string order = "FRBLUD";
    int orderCounter = 0;
    for (auto const &element: CubeEntity) {
        std::cout << order[orderCounter++] << std::endl;
        for (int i = 0; i < 9; ++i) {
            if (i != 0 && i % 3 == 0)
                std::cout << "\n";
            std::cout << element[i] << " ";
        }
        std::cout << "\n";
    }
}


void Cube::saveToOutput(const std::string &filename) {
    std::ofstream out("output.out");
    if (!out)
        throw std::invalid_argument("FILE wasn't opened");
    else {
        for (auto const &element: CubeEntity) {
            for (int i = 0; i < 9; ++i) {
                if (i != 0 && i % 3 == 0)
                    out << "\n";
                out << element[i] << " ";
            }
            out << "\n\n";
        }
    }
}

void Cube::setFromInput(const std::string &filename) {
    std::ifstream in(filename);
    if (!in)
        throw std::invalid_argument("FILE wasn't opened");
    else {
        std::vector<std::vector<char>> entity;
        std::vector<char> facet(9, 0);
        char value;
        for (int i = 0; i < 6; ++i) {
            entity.push_back(facet);
        }
        int facetCounter = 0;
        int cubeCounter = 0;
        int checkCounter = 0;
        while (in >> value) {
            entity[facetCounter][cubeCounter++] = value;
            if (cubeCounter == 9) {
                facetCounter++;
                cubeCounter = 0;
            }
            checkCounter++;
        }
        in.close();
        if (checkCounter != 54)
            throw std::invalid_argument("wrong input format");
        else
            CubeEntity = entity;
    }
} 

//FRBLUD
void Cube::right() {
    std::vector<std::vector<char>> tempEntity = CubeEntity;
    //FRONT CHANGES from old down
    CubeEntity[0][2] = tempEntity[5][2];
    CubeEntity[0][5] = tempEntity[5][5];
    CubeEntity[0][8] = tempEntity[5][8];
    //UP CHANGES from old front
    CubeEntity[4][2] = tempEntity[0][2];
    CubeEntity[4][5] = tempEntity[0][5];
    CubeEntity[4][8] = tempEntity[0][8];
    //BACK CHANGES from old up
    CubeEntity[2][0] = tempEntity[4][8];
    CubeEntity[2][3] = tempEntity[4][5];
    CubeEntity[2][6] = tempEntity[4][2];
    //DOWN CHANGES from old back
    CubeEntity[5][2] = tempEntity[2][6];
    CubeEntity[5][5] = tempEntity[2][3];
    CubeEntity[5][8] = tempEntity[2][0];
    //SIDE CHANGES
    CubeEntity[1][0] = tempEntity[1][6];
    CubeEntity[1][1] = tempEntity[1][3];
    CubeEntity[1][2] = tempEntity[1][0];
    CubeEntity[1][3] = tempEntity[1][7];
    CubeEntity[1][5] = tempEntity[1][1];
    CubeEntity[1][6] = tempEntity[1][8];
    CubeEntity[1][7] = tempEntity[1][5];
    CubeEntity[1][8] = tempEntity[1][2];
}

void Cube::rightReversed() {
    std::vector<std::vector<char>> tempEntity = CubeEntity;
    //DOWN CHANGES from old front
    CubeEntity[5][2] = tempEntity[0][2];
    CubeEntity[5][5] = tempEntity[0][5];
    CubeEntity[5][8] = tempEntity[0][8];
    //FRONT CHANGES from old up
    CubeEntity[0][2] = tempEntity[4][2];
    CubeEntity[0][5] = tempEntity[4][5];
    CubeEntity[0][8] = tempEntity[4][8];
    //UP CHANGES from old back
    CubeEntity[4][8] = tempEntity[2][0];
    CubeEntity[4][5] = tempEntity[2][3];
    CubeEntity[4][2] = tempEntity[2][6];
    //BACK CHANGES from old down
    CubeEntity[2][6] = tempEntity[5][8];
    CubeEntity[2][3] = tempEntity[5][5];
    CubeEntity[2][0] = tempEntity[5][2];
    //SIDE CHANGES
    CubeEntity[1][6] = tempEntity[1][0];
    CubeEntity[1][3] = tempEntity[1][1];
    CubeEntity[1][0] = tempEntity[1][2];
    CubeEntity[1][7] = tempEntity[1][3];
    CubeEntity[1][1] = tempEntity[1][5];
    CubeEntity[1][8] = tempEntity[1][6];
    CubeEntity[1][5] = tempEntity[1][7];
    CubeEntity[1][2] = tempEntity[1][8];

}

void Cube::left() {
    std::vector<std::vector<char>> tempEntity = CubeEntity;
    //DOWN changes from old front
    CubeEntity[5][0] = tempEntity[0][0];
    CubeEntity[5][3] = tempEntity[0][3];
    CubeEntity[5][6] = tempEntity[0][6];
    //FRONT CHANGES from old up
    CubeEntity[0][0] = tempEntity[4][0];
    CubeEntity[0][3] = tempEntity[4][3];
    CubeEntity[0][6] = tempEntity[4][6];
    //UP CHANGES from old back
    CubeEntity[4][6] = tempEntity[2][2];
    CubeEntity[4][3] = tempEntity[2][5];
    CubeEntity[4][0] = tempEntity[2][8];
    //BACK CHANGES from old down
    CubeEntity[2][8] = tempEntity[5][0];
    CubeEntity[2][5] = tempEntity[5][3];
    CubeEntity[2][2] = tempEntity[5][6];
    //SIDE CHANGES
    CubeEntity[3][0] = tempEntity[3][6];
    CubeEntity[3][1] = tempEntity[3][3];
    CubeEntity[3][2] = tempEntity[3][0];
    CubeEntity[3][3] = tempEntity[3][7];
    CubeEntity[3][5] = tempEntity[3][1];
    CubeEntity[3][6] = tempEntity[3][8];
    CubeEntity[3][7] = tempEntity[3][5];
    CubeEntity[3][8] = tempEntity[3][2];


}

void Cube::leftReversed() {
    std::vector<std::vector<char>> tempEntity = CubeEntity;
    //DOWN changes from old front
    CubeEntity[0][0] = tempEntity[5][0];
    CubeEntity[0][3] = tempEntity[5][3];
    CubeEntity[0][6] = tempEntity[5][6];
    //FRONT CHANGES from old up
    CubeEntity[4][0] = tempEntity[0][0];
    CubeEntity[4][3] = tempEntity[0][3];
    CubeEntity[4][6] = tempEntity[0][6];
    //UP CHANGES from old back
    CubeEntity[2][8] = tempEntity[4][0];
    CubeEntity[2][5] = tempEntity[4][3];
    CubeEntity[2][2] = tempEntity[4][6];
    //BACK CHANGES from old down
    CubeEntity[5][0] = tempEntity[2][8];
    CubeEntity[5][3] = tempEntity[2][5];
    CubeEntity[5][6] = tempEntity[2][2];
    //SIDE CHANGES
    CubeEntity[3][6] = tempEntity[3][0];
    CubeEntity[3][3] = tempEntity[3][1];
    CubeEntity[3][0] = tempEntity[3][2];
    CubeEntity[3][7] = tempEntity[3][3];
    CubeEntity[3][1] = tempEntity[3][5];
    CubeEntity[3][8] = tempEntity[3][6];
    CubeEntity[3][5] = tempEntity[3][7];
    CubeEntity[3][2] = tempEntity[3][8];
}

void Cube::front() {
    std::vector<std::vector<char>> tempEntity = CubeEntity;
    //RIGHT from up
    CubeEntity[1][0] = tempEntity[4][6];
    CubeEntity[1][3] = tempEntity[4][7];
    CubeEntity[1][6] = tempEntity[4][8];
    //DOWN from right
    CubeEntity[5][0] = tempEntity[1][6];
    CubeEntity[5][1] = tempEntity[1][3];
    CubeEntity[5][2] = tempEntity[1][0];
    //LEFT from down
    CubeEntity[3][2] = tempEntity[5][0];
    CubeEntity[3][5] = tempEntity[5][1];
    CubeEntity[3][8] = tempEntity[5][2];
    //UP from left
    CubeEntity[4][6] = tempEntity[3][8];
    CubeEntity[4][7] = tempEntity[3][5];
    CubeEntity[4][8] = tempEntity[3][2];
    //SIDES changes
    CubeEntity[0][0] = tempEntity[0][6];
    CubeEntity[0][1] = tempEntity[0][3];
    CubeEntity[0][2] = tempEntity[0][0];
    CubeEntity[0][3] = tempEntity[0][7];
    CubeEntity[0][5] = tempEntity[0][1];
    CubeEntity[0][6] = tempEntity[0][8];
    CubeEntity[0][7] = tempEntity[0][5];
    CubeEntity[0][8] = tempEntity[0][2];

}

void Cube::frontReversed() {
    std::vector<std::vector<char>> tempEntity = CubeEntity;
    //RIGHT from up
    CubeEntity[4][6] = tempEntity[1][0];
    CubeEntity[4][7] = tempEntity[1][3];
    CubeEntity[4][8] = tempEntity[1][6];
    //DOWN from right
    CubeEntity[1][6] = tempEntity[5][0];
    CubeEntity[1][3] = tempEntity[5][1];
    CubeEntity[1][0] = tempEntity[5][2];
    //LEFT from down
    CubeEntity[5][0] = tempEntity[3][2];
    CubeEntity[5][1] = tempEntity[3][5];
    CubeEntity[5][2] = tempEntity[3][8];
    //UP from left
    CubeEntity[3][8] = tempEntity[4][6];
    CubeEntity[3][5] = tempEntity[4][7];
    CubeEntity[3][2] = tempEntity[4][8];
    //SIDES changes
    CubeEntity[0][6] = tempEntity[0][0];
    CubeEntity[0][3] = tempEntity[0][1];
    CubeEntity[0][0] = tempEntity[0][2];
    CubeEntity[0][7] = tempEntity[0][3];
    CubeEntity[0][1] = tempEntity[0][5];
    CubeEntity[0][8] = tempEntity[0][6];
    CubeEntity[0][5] = tempEntity[0][7];
    CubeEntity[0][2] = tempEntity[0][8];
}

void Cube::back() {
    std::vector<std::vector<char>> tempEntity = CubeEntity;
    //RIGHT from down
    CubeEntity[1][2] = tempEntity[5][8];
    CubeEntity[1][5] = tempEntity[5][7];
    CubeEntity[1][8] = tempEntity[5][6];
    //DOWN from left
    CubeEntity[5][6] = tempEntity[3][0];
    CubeEntity[5][7] = tempEntity[3][3];
    CubeEntity[5][8] = tempEntity[3][6];
    //UP from right
    CubeEntity[4][0] = tempEntity[1][2];
    CubeEntity[4][1] = tempEntity[1][5];
    CubeEntity[4][2] = tempEntity[1][8];
    //LEFT from up
    CubeEntity[3][0] = tempEntity[4][2];
    CubeEntity[3][3] = tempEntity[4][1];
    CubeEntity[3][6] = tempEntity[4][0];
    //SIDES changes
    CubeEntity[2][0] = tempEntity[2][6];
    CubeEntity[2][1] = tempEntity[2][3];
    CubeEntity[2][2] = tempEntity[2][0];
    CubeEntity[2][3] = tempEntity[2][7];
    CubeEntity[2][5] = tempEntity[2][1];
    CubeEntity[2][6] = tempEntity[2][8];
    CubeEntity[2][7] = tempEntity[2][5];
    CubeEntity[2][8] = tempEntity[2][2];

}

void Cube::backReversed() {
    std::vector<std::vector<char>> tempEntity = CubeEntity;
    //RIGHT from down
    CubeEntity[5][8] = tempEntity[1][2];
    CubeEntity[5][7] = tempEntity[1][5];
    CubeEntity[5][6] = tempEntity[1][8];
    //DOWN from left
    CubeEntity[3][0] = tempEntity[5][6];
    CubeEntity[3][3] = tempEntity[5][7];
    CubeEntity[3][6] = tempEntity[5][8];
    //UP from right
    CubeEntity[1][2] = tempEntity[4][0];
    CubeEntity[1][5] = tempEntity[4][1];
    CubeEntity[1][8] = tempEntity[4][2];
    //LEFT from up
    CubeEntity[4][2] = tempEntity[3][0];
    CubeEntity[4][1] = tempEntity[3][3];
    CubeEntity[4][0] = tempEntity[3][6];
    //SIDES changes
    CubeEntity[2][6] = tempEntity[2][0];
    CubeEntity[2][3] = tempEntity[2][1];
    CubeEntity[2][0] = tempEntity[2][2];
    CubeEntity[2][7] = tempEntity[2][3];
    CubeEntity[2][1] = tempEntity[2][5];
    CubeEntity[2][8] = tempEntity[2][6];
    CubeEntity[2][5] = tempEntity[2][7];
    CubeEntity[2][2] = tempEntity[2][8];
}

void Cube::up() {
    std::vector<std::vector<char>> tempEntity = CubeEntity;
    //FRONT from right
    CubeEntity[0][0] = tempEntity[1][0];
    CubeEntity[0][1] = tempEntity[1][1];
    CubeEntity[0][2] = tempEntity[1][2];
    //RIGHT from back
    CubeEntity[1][0] = tempEntity[2][0];
    CubeEntity[1][1] = tempEntity[2][1];
    CubeEntity[1][2] = tempEntity[2][2];
    //BACK from left
    CubeEntity[2][0] = tempEntity[3][0];
    CubeEntity[2][1] = tempEntity[3][1];
    CubeEntity[2][2] = tempEntity[3][2];
    //LEFT ftom front
    CubeEntity[3][0] = tempEntity[0][0];
    CubeEntity[3][1] = tempEntity[0][1];
    CubeEntity[3][2] = tempEntity[0][2];
    //SIDES changes
    CubeEntity[4][0] = tempEntity[4][6];
    CubeEntity[4][1] = tempEntity[4][3];
    CubeEntity[4][2] = tempEntity[4][0];
    CubeEntity[4][3] = tempEntity[4][7];
    CubeEntity[4][5] = tempEntity[4][1];
    CubeEntity[4][6] = tempEntity[4][8];
    CubeEntity[4][7] = tempEntity[4][5];
    CubeEntity[4][8] = tempEntity[4][2];

}

void Cube::upReversed() {
    std::vector<std::vector<char>> tempEntity = CubeEntity;
    //FRONT from right
    CubeEntity[1][0] = tempEntity[0][0];
    CubeEntity[1][1] = tempEntity[0][1];
    CubeEntity[1][2] = tempEntity[0][2];
    //RIGHT from back
    CubeEntity[2][0] = tempEntity[1][0];
    CubeEntity[2][1] = tempEntity[1][1];
    CubeEntity[2][2] = tempEntity[1][2];
    //BACK from left
    CubeEntity[3][0] = tempEntity[2][0];
    CubeEntity[3][1] = tempEntity[2][1];
    CubeEntity[3][2] = tempEntity[2][2];
    //LEFT ftom front
    CubeEntity[0][0] = tempEntity[3][0];
    CubeEntity[0][1] = tempEntity[3][1];
    CubeEntity[0][2] = tempEntity[3][2];
    //SIDES changes
    CubeEntity[4][6] = tempEntity[4][0];
    CubeEntity[4][3] = tempEntity[4][1];
    CubeEntity[4][0] = tempEntity[4][2];
    CubeEntity[4][7] = tempEntity[4][3];
    CubeEntity[4][1] = tempEntity[4][5];
    CubeEntity[4][8] = tempEntity[4][6];
    CubeEntity[4][5] = tempEntity[4][7];
    CubeEntity[4][2] = tempEntity[4][8];
}

void Cube::down() {
    std::vector<std::vector<char>> tempEntity = CubeEntity;
    //FRONT from left
    CubeEntity[0][6] = tempEntity[3][6];
    CubeEntity[0][7] = tempEntity[3][7];
    CubeEntity[0][8] = tempEntity[3][8];
    //LEFT from BACK
    CubeEntity[3][6] = tempEntity[2][6];
    CubeEntity[3][7] = tempEntity[2][7];
    CubeEntity[3][8] = tempEntity[2][8];
    //BACK from right
    CubeEntity[2][6] = tempEntity[1][6];
    CubeEntity[2][7] = tempEntity[1][7];
    CubeEntity[2][8] = tempEntity[1][8];
    //RIGHT from front
    CubeEntity[1][6] = tempEntity[0][6];
    CubeEntity[1][7] = tempEntity[0][7];
    CubeEntity[1][8] = tempEntity[0][8];
    //SIDES changes
    CubeEntity[5][0] = tempEntity[5][6];
    CubeEntity[5][1] = tempEntity[5][3];
    CubeEntity[5][2] = tempEntity[5][0];
    CubeEntity[5][3] = tempEntity[5][7];
    CubeEntity[5][5] = tempEntity[5][1];
    CubeEntity[5][6] = tempEntity[5][8];
    CubeEntity[5][7] = tempEntity[5][5];
    CubeEntity[5][8] = tempEntity[5][2];
}

void Cube::downReversed() {
    std::vector<std::vector<char>> tempEntity = CubeEntity;
    //FRONT from left
    CubeEntity[3][6] = tempEntity[0][6];
    CubeEntity[3][7] = tempEntity[0][7];
    CubeEntity[3][8] = tempEntity[0][8];
    //LEFT from BACK
    CubeEntity[2][6] = tempEntity[3][6];
    CubeEntity[2][7] = tempEntity[3][7];
    CubeEntity[2][8] = tempEntity[3][8];
    //BACK from right
    CubeEntity[1][6] = tempEntity[2][6];
    CubeEntity[1][7] = tempEntity[2][7];
    CubeEntity[1][8] = tempEntity[2][8];
    //RIGHT from front
    CubeEntity[0][6] = tempEntity[1][6];
    CubeEntity[0][7] = tempEntity[1][7];
    CubeEntity[0][8] = tempEntity[1][8];
    //SIDES changes
    CubeEntity[5][6] = tempEntity[5][0];
    CubeEntity[5][3] = tempEntity[5][1];
    CubeEntity[5][0] = tempEntity[5][2];
    CubeEntity[5][7] = tempEntity[5][3];
    CubeEntity[5][1] = tempEntity[5][5];
    CubeEntity[5][8] = tempEntity[5][6];
    CubeEntity[5][5] = tempEntity[5][7];
    CubeEntity[5][2] = tempEntity[5][8];
}

const std::vector<std::vector<char>> &Cube::getCubeEntity() const {
    return CubeEntity;
}

void Cube::setCubeEntity(const std::vector<std::vector<char>> &cubeEntity) {
    CubeEntity = cubeEntity;
}

bool Cube::isSolved() const {
    for (int i = 0; i < CubeEntity.size(); ++i) {
        for (int j = 0; j < CubeEntity[i].size(); ++j)
            if (CubeEntity[i][j] != CubeEntity[i][4])
                return false;
    }
    return true;
}

bool Cube::checkInput(const std::vector<std::vector<char>> &cubeEntity) const {
    std::string order = "bpgrow";
    int orderChecker = 0;
    if (cubeEntity.size() != 6) // check that only provided colors are present
        return false;
    for(int i = 0; i < cubeEntity.size(); ++i){
        for (int j = 0; j < CubeEntity[i].size(); ++j) {
            if(CubeEntity[i].size() != 9)
                return false;
    }
        if(cubeEntity[0][4] !='b' || cubeEntity[1][4] !='p' || cubeEntity[2][4] != 'g' || cubeEntity[3][4] !='r' || cubeEntity[4][4] != 'o' || cubeEntity[5][4] != 'w')
            return false;
    return true;
}







