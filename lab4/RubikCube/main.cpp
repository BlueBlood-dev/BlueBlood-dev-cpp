#include "Cube.cpp"
#include <fstream>





int main() {
    // FACETS INPUT ORDER  FRBLUD
    try { // without app.run()
        Cube tempCube = Cube();
        tempCube.setFromInput("input.in");
        tempCube.rightReversed();
        tempCube.right();
        tempCube.leftReversed();
        tempCube.left();
        tempCube.frontReversed();
        tempCube.front();
        tempCube.back();
        tempCube.backReversed();
        tempCube.up();
        tempCube.upReversed();
        tempCube.down();
        tempCube.downReversed();
        tempCube.printCube();
        tempCube.saveToOutput("output.out");
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}