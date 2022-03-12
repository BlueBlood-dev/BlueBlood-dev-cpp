#include <utility>
#include <vector>
#include <iostream>
#include <valarray>


class Point {
private:
    float coordX_;
    float coordY_;
public:
    Point(float coordX, float coordY) : coordX_(coordX), coordY_(coordY) {
        std::cout << "point cstr();" << std::endl;
    }

    Point(const Point &dot) : coordX_(dot.coordX_), coordY_(dot.coordY_) {
        std::cout << "point copy cstr();" << std::endl;
    }

    virtual ~Point() {
        std::cout << "point ~cstr();" << std::endl;
    }

    float getCoordX() const {
        return coordX_;
    }

    float getCoordY() const {
        return coordY_;
    }

    void setCoordX(float coordX) {
        coordX_ = coordX;
    }

    void setCoordY(float coordY) {
        coordY_ = coordY;
    }

    Point &operator=(const Point &point) {
        coordX_ = point.coordX_;
        coordY_ = point.coordY_;
        return *this;
    }
};


class PolyLine {
private:
    std::vector<Point> polyLine_;

    float countLength() {
        double length = 0;
        for (int i = 0; i < polyLine_.size() - 1; ++i) {
            length += pow(polyLine_[i].getCoordX() - polyLine_[i + 1].getCoordX(), 2) +
                      pow(polyLine_[i].getCoordY() - polyLine_[i + 1].getCoordY(), 2);
        }
        return sqrt(length);
    }

public:
    explicit PolyLine(std::vector<Point> polyLine) : polyLine_(std::move(polyLine)) {
        std::cout << "PolyLine cstr();" << std::endl;
    }

    PolyLine(const PolyLine &line) : polyLine_(line.polyLine_) {
        std::cout << "PolyLine copy cstr()" << std::endl;
    }

    virtual ~PolyLine() {
        std::cout << "Polyline ~cstr()" << std::endl;
    }

    const std::vector<Point> &getPolyLine() const {
        return polyLine_;
    }

    void setPolyLine(const std::vector<Point> &vector) {
        PolyLine::polyLine_ = vector;
    }

    double getLength() {
        return countLength();
    }

    PolyLine &operator=(const PolyLine &polyline) {
        polyLine_ = polyline.polyLine_;
        return *this;
    }
};


class ClosedPolyLine {
private:
    std::vector<Point> closedPolyLine_;

    double countLength() {
        double length = 0;
        for (int i = 0; i < closedPolyLine_.size() - 1; ++i) {
            length += pow(closedPolyLine_[i].getCoordX() - closedPolyLine_[i + 1].getCoordX(), 2) +
                      pow(closedPolyLine_[i].getCoordY() - closedPolyLine_[i + 1].getCoordY(), 2);
        }
        length += (pow(closedPolyLine_[closedPolyLine_.size() - 1].getCoordX() - closedPolyLine_[0].getCoordX(), 2) +
                   pow(closedPolyLine_[closedPolyLine_.size() - 1].getCoordY() - closedPolyLine_[0].getCoordY(), 2));
        return sqrt(length);
    }

public:
    explicit ClosedPolyLine(std::vector<Point> closedPolyLine) : closedPolyLine_(std::move(closedPolyLine)) {
        std::cout << "ClosedPolyLine cstr();" << std::endl;
    }

    ClosedPolyLine(const ClosedPolyLine &line) : closedPolyLine_(line.closedPolyLine_) {
        std::cout << "ClosedPolyLine copy cstr();" << std::endl;
    }

    const std::vector<Point> &getClosedPolyLine() const {
        return closedPolyLine_;
    }

    void setClosedPolyLine(const std::vector<Point> &closedPolyLine) {
        closedPolyLine_ = closedPolyLine;
    }

    double getLength() {
        return countLength();
    }

    ClosedPolyLine &operator=(const ClosedPolyLine &closedPolyLine) {
        closedPolyLine_ = closedPolyLine.closedPolyLine_;
        return *this;
    }
};

class Polygon {
protected:
    std::vector<Point> polygon_;

    double countSquare() {
        double square = 0;
        for (int i = 0; i < polygon_.size() - 1; ++i) {
            square += polygon_[i].getCoordX() * polygon_[i + 1].getCoordY() -
                      polygon_[i].getCoordY() * polygon_[i + 1].getCoordX();
        }
        square += polygon_[polygon_.size() - 1].getCoordX() * polygon_[0].getCoordY() -
                  polygon_[polygon_.size() - 1].getCoordY() * polygon_[0].getCoordX();
        return std::abs(square) * 0.5;
    }

    double countLength() {
        double length = 0;
        for (int i = 0; i < polygon_.size() - 1; ++i) {
            length += pow(polygon_[i].getCoordX() - polygon_[i + 1].getCoordX(), 2) +
                      pow(polygon_[i].getCoordY() - polygon_[i + 1].getCoordY(), 2);
        }
        length += (pow(polygon_[polygon_.size() - 1].getCoordX() - polygon_[0].getCoordX(), 2) +
                   pow(polygon_[polygon_.size() - 1].getCoordY() - polygon_[0].getCoordY(), 2));
        return sqrt(length);
    }

private:
    bool checkConvexity() {
        double checkValue;
        for (int i = 1; i < polygon_.size() - 1; ++i) {
            checkValue = (polygon_[i].getCoordX() - polygon_[i - 1].getCoordX()) *
                         (polygon_[i + 1].getCoordY() - polygon_[i].getCoordY()) -
                         (polygon_[i].getCoordY() - polygon_[i - 1].getCoordY()) *
                         (polygon_[i + 1].getCoordX() - polygon_[i].getCoordX());
            if (checkValue > 0)
                return false;
        }
        return true;
    }

public:
    explicit Polygon(std::vector<Point> polygon) : polygon_(std::move(polygon)) {
        if (polygon.size() <= 2 || !checkConvexity())
            throw (std::invalid_argument("Polygon is not convex"));
        std::cout << "Polygon cstr();" << std::endl;
    }

    Polygon(const Polygon &polygon) : polygon_(polygon.polygon_) {
        std::cout << "Polygon cstr();" << std::endl;
    }

    virtual ~Polygon() {
        std::cout << "Polygon ~cstr();" << std::endl;
    }

    const std::vector<Point> &getPolygon() const {
        return polygon_;
    }

    void setPolygon(const std::vector<Point> &polygon) {
        polygon_ = polygon;
    }


    double getSquare() {
        return countSquare();
    }

    double getLength() {
        return countLength();
    }

    Polygon &operator=(const Polygon &polygon) {
        polygon_ = polygon.polygon_;
        return *this;
    }
};


class Triangle : public Polygon {
private:
    bool checkTriangleRule(std::vector<Point> triangle) {
        double firstSide = sqrt(pow(triangle[0].getCoordX() - triangle[1].getCoordX(), 2) +
                                pow(triangle[0].getCoordY() - triangle[1].getCoordY(), 2));
        double secondSide = sqrt(pow(triangle[1].getCoordX() - triangle[2].getCoordX(), 2) +
                                 pow(triangle[1].getCoordY() - triangle[2].getCoordY(), 2));
        double thirdSide = sqrt(pow(triangle[2].getCoordX() - triangle[0].getCoordX(), 2) +
                                pow(triangle[2].getCoordY() - triangle[0].getCoordY(), 2));
        if (!(firstSide + secondSide > thirdSide || thirdSide + firstSide > secondSide ||
              secondSide + thirdSide > firstSide))
            return false;
        return true;
    }

public:
    Triangle(const std::vector<Point> &polygon) : Polygon(polygon) {
        if (polygon.size() != 3 || !checkTriangleRule(polygon))
            throw (std::invalid_argument("Triangle must contain only 3 points or sides don't match the triangle rule"));
        std::cout << "Triangle cstr();" << std::endl;
    }

    Triangle(const Triangle &polygon) : Polygon(polygon) {
        std::cout << "Triangle copy cstr();" << std::endl;
    }

    virtual ~Triangle() {
        std::cout << "Triangle ~cstr();" << std::endl;
    }
};

class Trapezoid : public Polygon {
private:
    bool checkParallel(std::vector<Point> trapezoid) {
        // normalize vectors and check the rule
        double firstLength = sqrt(pow(trapezoid[0].getCoordX() - trapezoid[1].getCoordX(), 2) +
                                  pow(trapezoid[0].getCoordY() - trapezoid[1].getCoordY(), 2));
        double secondLength = sqrt(pow(trapezoid[1].getCoordX() - trapezoid[2].getCoordX(), 2) +
                                   pow(trapezoid[1].getCoordY() - trapezoid[2].getCoordY(), 2));
        double thirdLength = sqrt(pow(trapezoid[2].getCoordX() - trapezoid[3].getCoordX(), 2) +
                                  pow(trapezoid[2].getCoordY() - trapezoid[3].getCoordY(), 2));
        double fourthLength = sqrt(pow(trapezoid[0].getCoordX() - trapezoid[3].getCoordX(), 2) +
                                   pow(trapezoid[0].getCoordY() - trapezoid[3].getCoordY(), 2));

        double xFirst = std::abs(trapezoid[0].getCoordX() - trapezoid[1].getCoordX()) / firstLength;
        double yFirst = std::abs(trapezoid[0].getCoordY() - trapezoid[1].getCoordY()) / firstLength;
        double xSecond = std::abs(trapezoid[1].getCoordX() - trapezoid[2].getCoordX()) / secondLength;
        double ySecond = std::abs(trapezoid[1].getCoordY() - trapezoid[2].getCoordY()) / secondLength;
        double xThird = std::abs(trapezoid[2].getCoordX() - trapezoid[3].getCoordX()) / thirdLength;
        double yThird = std::abs(trapezoid[2].getCoordY() - trapezoid[3].getCoordY()) / thirdLength;
        double xFourth = std::abs(trapezoid[3].getCoordX() - trapezoid[0].getCoordX()) / fourthLength;
        double yFourth = std::abs(trapezoid[3].getCoordY() - trapezoid[0].getCoordY()) / fourthLength;

        if ((xFirst != xThird && yFirst != yThird) && (xSecond != xFourth && ySecond != yFourth))
            return false;
        return true;
    }

public:
    Trapezoid(const std::vector<Point> &polygon) : Polygon(polygon) {
        if (polygon.size() != 4 || !checkParallel(polygon)) {
            throw std::invalid_argument("Trapezoid must contain only 4 points or it doesn't have 2 parallel sides");
        }
    }

    Trapezoid(const Trapezoid &polygon) : Polygon(polygon) {
        std::cout << "Trapezoid copy cstr();" << std::endl;
    }

    virtual ~Trapezoid() {
        std::cout << "Trapezoid ~cstr()" << std::endl;
    }
};

class RightPolygon : public Polygon {
private:
    bool checkRightness(std::vector<Point> rightPolygon) {
        double firstValue = sqrt(pow(rightPolygon[0].getCoordX() - rightPolygon[1].getCoordX(), 2) +
                                 pow(rightPolygon[0].getCoordY() - rightPolygon[1].getCoordY(), 2));
        for (int i = 1; i < rightPolygon.size() - 1; ++i) {
            double temp = sqrt(pow(rightPolygon[i].getCoordX() - rightPolygon[i + 1].getCoordX(), 2) +
                               pow(rightPolygon[i].getCoordY() - rightPolygon[i + 1].getCoordY(), 2));
            if (firstValue != temp)
                return false;
        }
        if (firstValue != sqrt(pow(polygon_[polygon_.size() - 1].getCoordX() - polygon_[0].getCoordX(), 2) +
                               pow(polygon_[polygon_.size() - 1].getCoordY() - polygon_[0].getCoordY(), 2)))
            return false;

        return true;
    }

public:
    RightPolygon(const std::vector<Point> &polygon) : Polygon(polygon) {
        if (!checkRightness(polygon))
            throw std::invalid_argument("this polygon is not right");
        std::cout << "RightPolygon cstr();" << std::endl;
    }

    RightPolygon(const RightPolygon &polygon) : Polygon(polygon) {
        std::cout << "RightPolygon copy cstr();" << std::endl;
    }

    virtual ~RightPolygon() {
        std::cout << "RightPolygon ~cstr();" << std::endl;
    }
};

int main() {
    try {
        Polygon polygon = Polygon(
                {Point(3.0, 4.0), Point(5.0, 11.0), Point(12.0, 8.0),
                 Point(9.0, 5.0)});
        std::cout << polygon.getSquare() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Triangle triangle = Triangle({Point(1.45, 3.42), Point(2.5, 4.8), Point(1.2, 3.1)});
        std::cout << triangle.getLength() << std::endl;
        Triangle triangle1 = Triangle(triangle);
        std::cout << triangle1.getLength() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
