//
// Created by Vishnenko Maxim on 06.04.2023.
//

#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <memory>

#define UNUSED(variable) (void)variable

using namespace std;

class Shape{
private:
    int x;
    int y;

public:
    Shape() : x(0), y(0) {};
    Shape(int _x, int _y) : x(_x), y(_y) {};

    int GetX() const {
        return x;
    };

    int GetY() const {
        return y;
    };

    void SetCoord(const int _x, const int _y) {
        x = _x;
        y = _y;
    };

    [[nodiscard]] virtual double GetSquare() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
private:
    int width;
    int height;

public:
    Rectangle() : Shape(), width(0), height(0){};
    Rectangle(const int _x, const int _y, const int _width, const int _height) : Shape(_x, _y), width(_width), height(_height) {};
    Rectangle(const Rectangle &_primitive) : Shape(_primitive.GetX(), _primitive.GetY()), width(_primitive.width), height(_primitive.height) {};

    [[nodiscard]] double GetSquare() const override {
        return width*height;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle() : Shape(), radius(0) {};
    Circle(const int _x, const int _y, const double _radius) : Shape(_x, _y), radius(_radius) {};
    Circle(const Circle &_primitive) : Shape(_primitive.GetX(), _primitive.GetY()), radius(_primitive.radius) {};

    [[nodiscard]] double GetSquare() const override {
        return 3.14*radius*radius;
    }
};

class Element{
private:
    int type;
    shared_ptr<void> data;

public:
    Element() = delete;

    explicit Element(const Circle &_primitive){
        type = 1;
        data.reset(static_cast<Circle *>(new Circle(_primitive)));
    };

    explicit Element(const Rectangle &_primitive){
        type = 2;
        data.reset(static_cast<Rectangle *>(new Rectangle(_primitive)));
    };

    ~Element() = default;

    [[nodiscard]] int       GetType() const {return type;};
    [[nodiscard]] double    GetSquare() const {return 0.0;};
    [[nodiscard]] int       GetX() const {return 0;};
    [[nodiscard]] int       GetY() const {return 0;};
    void    SetCoord(int _x, int _y) {UNUSED(_x); UNUSED(_y);};
};

#endif //PRIMITIVES_H
