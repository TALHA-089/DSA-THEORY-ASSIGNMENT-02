#pragma Once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Polynomial {
private:
    int coefficient;
    int exponent;
    Polynomial* next;

public:
    Polynomial(int c, int e) {
        coefficient = c;
        exponent = e;
        next = nullptr;
    }

    Polynomial* getNext() {
        return next;
    }

    int getCoefficient() {
        return coefficient;
    }

    void setCoefficient(int c){
        this->coefficient = c;
    }

    int getExponent() {
        return exponent;
    }

    void setNext(Polynomial* nextNode) {
        next = nextNode;
    }
};