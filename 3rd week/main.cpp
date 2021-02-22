#include <iostream>
#include <vector>

class fig {
public:
    const double pi = 3.1415926;
    virtual double square(){
        return 0;
    }
    double perimeter(){
        double p = 0;
        for(auto i:sides)
            p += i;
        return p;
    }
    virtual int countAngles(){
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
    double square() override{
        double p = (sides[0] + sides[1] + sides[2]) / 2;
        return sqrt(p * (p - sides[0]) * (p - sides[1]) * (p - sides[2]));
    }
    int countAngles() override{
        return 3;
    }
};

class rectangleF : public fig {
public:
    rectangleF(double a, double b){
        sides.push_back(a);
        sides.push_back(b);
    }
    rectangleF(double a){
        sides.push_back(a);
        sides.push_back(a);
    }
    double square() override{
        return sides[0] * sides[1];
    }
    int countAngles() override{
        return 4;
    }
};

class squareF : public fig {
public:
    squareF(double a){
        sides.push_back(a);
    }
    double square() override{
        return sides[0] * sides[0];
    }
    int countAngles() override{
        return 4;
    }
};

class circleF : public fig {
public:
    circleF(double r){
        sides.push_back(r);
    }
    double square() override{
        return pi * sides[0] * sides[0];
    }
    double perimeter(){
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
    double square() override{
        return pi * sides[0] * sides[1];
    }
    double perimeter(){
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

int angles_amount(fig* f){
    return f -> countAngles();
}

int main() {
    return 0;
}
