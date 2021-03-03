#include <iostream>
#include <vector>
#include <functional>
#include <vector>

class fig {
public:
    const double pi = 3.1415926;

    virtual double square() const{
        return 0;
    }

    double perimeter() const{
        auto p = 0.;
        for(auto i:sides)
            p += i;
        return p;
    }

    virtual int countAngles() const{
        return 0;
    };
protected:
    std::vector <double> sides;
};

class triangleF : public fig {
public:
    triangleF(double a, double b,  double c){
        sides.push_back(a);
        sides.push_back(b);
        sides.push_back(c);
    }
    double square() const{
        double p = (sides[0] + sides[1] + sides[2]) / 2;
        return sqrt(p * (p - sides[0]) * (p - sides[1]) * (p - sides[2]));
    }
    int countAngles() const{
        return 3;
    }
};

class rectangleF : public fig {
public:
    rectangleF(double a, double b){
        sides.push_back(a);
        sides.push_back(b);
        sides.push_back(a);
        sides.push_back(b);
    }
    rectangleF(double a){
        sides.push_back(a);
        sides.push_back(a);
        sides.push_back(a);
        sides.push_back(a);
    }
    double square() const {
        return sides[0] * sides[1];
    }
    int countAngles() const{
        return 4;
    }
};

class squareF : public fig {
public:
    squareF(double a){
        sides.push_back(a);
        sides.push_back(a);
        sides.push_back(a);
        sides.push_back(a);
    }
    double square() const{
        return sides[0] * sides[0];
    }
    int countAngles() const{
        return 4;
    }
};

class circleF : public fig {
public:
    circleF(double r){
        sides.push_back(r);
    }
    double square() const{
        return pi * sides[0] * sides[0];
    }
    double perimeter() const{
        return 2 * pi * sides[0];
    }
};

class ellipseF : fig {
public:
    ellipseF(double a, double b){
        sides.push_back(a);
        sides.push_back(b);
    }
    ellipseF(double a){
        sides.push_back(a);
        sides.push_back(a);
    }
    double square() const{
        return pi * sides[0] * sides[1];
    }
    double perimeter() const{
        std::cout << "Count it yourself =)" << '\n';
        return 0;
    }
};

double square(fig* f){
    return f -> square();
}

double perimeter(fig* f){
    return f -> perimeter();
}

double angles_amount(fig* f){
    return f -> countAngles();
}

std::vector <std::function<double(fig*)>> func;

int main() {
    func.push_back(square);
    func.push_back(perimeter);
    func.push_back(angles_amount);
    rectangleF r(12, 10);
    double pp = func[1](&r);
    std::cout << "Square: " << func[0](&r) << '\n';
    std::cout << "Perimeter: " << func[1](&r) << '\n';
    std::cout << "Angles amount: " << func[2](&r) << '\n';
    return 0;
}
