//
// Created by blueblood on 14.05.2022.
//

#ifndef RUBIKCUBE_SOLVER_H
#define RUBIKCUBE_SOLVER_H


class Solver {
private:
    Cube cubeToSolve;
    //someSteps
    std::string stepOne();
    std::string stepTwo();
    std::string stepThree();
    std::string stepFour();
public:
    explicit Solver(const Cube &cubeToSolve);

    virtual ~Solver();

    std::string solve();


};


#endif //RUBIKCUBE_SOLVER_H
