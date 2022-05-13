#ifndef RUBIKCUBE_CUBE_H
#define RUBIKCUBE_CUBE_H


#include <vector>
#include <string>

class Cube {
private :
    std::vector<std::vector<char>> CubeEntity;
public:
    void setFromInput(const std::string &);

    void saveToOutput(const std::string &);

    Cube();

    explicit Cube(std::vector<std::vector<char>> cubeEntity);

    virtual ~Cube();

    void printCube();

    void right();

    void rightReversed();

    void left();

    void leftReversed();

    void front();

    void frontReversed();

    void back();

    void backReversed();

    void up();

    void upReversed();

    void down();

    void downReversed();

//    bool checkInput(const std::vector<std::vector<char>>&);

};


#endif //RUBIKCUBE_CUBE_H
