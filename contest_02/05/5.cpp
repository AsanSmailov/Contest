#include <sstream>
#include <string>

Complex make_complex(std::string str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
        str.erase(i, 1);
        i--; 
    }
    }
    std::stringstream ss(str);
    double re, im;
    char j;
    ss >> re >> im >> j;
    return {re, im};
} 

Complex sum(const Complex& c1, const Complex& c2) {
    return {c1.re + c2.re, c1.im + c2.im};
}

Complex sub(const Complex& c1, const Complex& c2) {
    return {c1.re - c2.re, c1.im - c2.im};
}

Complex mul(const Complex& c1, const Complex& c2) {
    return {c1.re * c2.re - c1.im * c2.im, c1.re * c2.im + c1.im * c2.re};
}

Complex div(const Complex& c1, const Complex& c2) {
    double denominator = c2.re * c2.re + c2.im * c2.im;
    return {(c1.re * c2.re + c1.im * c2.im) / denominator,
            (c1.im * c2.re - c1.re * c2.im) / denominator};
}

void print(const Complex& c) {
    std::cout << c.re;
    if (c.im >= 0) {
        std::cout << "+";
    }if(c.im==-0){
        std::cout << 0 << "j" << std::endl;
    }else std::cout << c.im << "j" << std::endl;
}
