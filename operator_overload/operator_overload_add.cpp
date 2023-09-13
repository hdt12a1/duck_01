#include <iostream>

class Complex {
public:
    Complex(double real = 0.0, double imaginary = 0.0) : real(real), imaginary(imaginary) {}

    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imaginary + other.imaginary);
    }
    // Overloading the << operator for output
    friend std::ostream& operator<<(std::ostream& os, const Complex& complex) {
        os << complex.real << " + " << complex.imaginary << "i";
        return os;
    }
private:
    double real;
    double imaginary;
};

int main() {
    Complex a(3.0, 4.0);
    Complex b(1.0, 2.0);
    
    Complex c = a + b; // Calls the overloaded + operator

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;

    return 0;
}
