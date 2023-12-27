#include <sstream>
class Complex {
friend std::ostream& operator<<(std::ostream& out, const Complex& num);
private:

    double re;
    double im;
public:
   Complex(std::string& num){
        std::stringstream ss(num);
        char c;
        ss >> re >> std::ws >> c >> std::ws >> im;
        if (c == '-'){
        im = -im;
        }
    }

    Complex operator+(const Complex& other){
        std::string result = std::to_string(re + other.re) + "+" + std::to_string(im + other.im);
        Complex complex(result);
        return complex;
    }
    Complex operator-(const Complex& other){
        std::string result = std::to_string(re - other.re) + "+" + std::to_string(im - other.im);
        Complex complex(result);
        return complex;
    }
    Complex operator*(const Complex& other){
        std::string result = std::to_string(re * other.re - im * other.im) + "+" + std::to_string(re * other.im + im * other.re);
        Complex complex(result);
        return complex;
    }
    Complex operator/(const Complex& other){
        double comp_conj = (other.re * other.re + other.im * other.im);
        std::string result = std::to_string((re * other.re + im * other.im) / comp_conj) + "+" + std::to_string((im * other.re - re * other.im) / comp_conj);
        Complex complex(result);
        return complex;
    }
};

std::ostream& operator<<(std::ostream& out, const Complex& num){
    out << (num.re == 0.0 ? 0.0 : num.re)
        << (num.im < 0 ? "":"+")
        << (num.im == 0.0 ? 0.0 : num.im) << 'j';
    return out;
}