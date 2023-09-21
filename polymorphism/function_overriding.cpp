#include <iostream>

class Shape
{
public:
    virtual void draw() = 0;
};

class Circle : public Shape
{
public:
    void draw(int a)
    {
        std::cout << a << "Drawing a circle\n";
    }
};

class Square : public Shape
{
public:
    void draw(int a)
    {
        std::cout << a << "Drawing a square" << std::endl;
    }
};
int main(int argc, char const *argv[])
{
    Shape *shapes[] = {new Circle(), new Square()};

    for (Shape *shape : shapes)
    {
        shape->draw();
    }
    return 0;
}
