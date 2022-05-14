#include "Cube.cpp"
#include <fstream>


int main() {
    // FACETS INPUT ORDER  FRBLUD
    try {
        Cube tempCube = Cube();
        tempCube.setFromInput("input.in");
        tempCube.saveToOutput("output.out");
        tempCube.right();
        tempCube.rightReversed();
        tempCube.left();
        tempCube.leftReversed();
        tempCube.up();
        tempCube.upReversed();
        tempCube.down();
        tempCube.downReversed();
        tempCube.front();
        tempCube.frontReversed();
        tempCube.back();
        tempCube.backReversed();
        tempCube.up();
        tempCube.leftReversed();
        tempCube.front();
        tempCube.upReversed();
        tempCube.frontReversed();
        //tempCube.generateRandom();
        tempCube.printCube();
        std::string solution = tempCube.getSolution();
        std::cout << solution;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}