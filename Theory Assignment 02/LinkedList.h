#pragma Once
#include "Polynomial.h"

class LinkedList {
private:
    Polynomial* head;
    string ID;
public:
    
    LinkedList() {
        head = nullptr;
    }

    void setListID(string ID){
        this->ID = ID;
    }

    string getListID(){
        return this->ID;
    }

    void InsertTerm(int c, int e) {
        Polynomial* newNode = new Polynomial(c, e);

        if (!head || head->getExponent() < e) {
            newNode->setNext(head);
            head = newNode;
        } else {
            Polynomial* temp = head;
            while (temp->getNext() && temp->getNext()->getExponent() > e) {
                temp = temp->getNext();
            }

            if (temp->getExponent() == e) {
                temp->setCoefficient(temp->getCoefficient() + c);
            } else {
                newNode->setNext(temp->getNext());
                temp->setNext(newNode);
            }
        }
    }

    void Display() {
        Polynomial* temp = head;
        while (temp) {
            cout << temp->getCoefficient() << "x ^ " << temp->getExponent();

            if (temp->getNext() && temp->getNext()->getCoefficient() > 0){
                cout << " + ";
            } 

            temp = temp->getNext();
        }
        cout << endl;
    }

    LinkedList operator+(const LinkedList& other) {
        LinkedList result;
        Polynomial* p1 = this->head;
        Polynomial* p2 = other.head;

        while (p1 || p2) {
            if (p1 && (!p2 || p1->getExponent() > p2->getExponent())) {
                result.InsertTerm(p1->getCoefficient(), p1->getExponent());
                p1 = p1->getNext();
            } else if (p2 && (!p1 || p2->getExponent() > p1->getExponent())) {
                result.InsertTerm(p2->getCoefficient(), p2->getExponent());
                p2 = p2->getNext();
            } else {
                int sumCoeff = p1->getCoefficient() + p2->getCoefficient();
                if (sumCoeff != 0) {
                    result.InsertTerm(sumCoeff, p1->getExponent());
                }
                p1 = p1->getNext();
                p2 = p2->getNext();
            }
        }

        return result;
    }

    LinkedList operator-(const LinkedList& other) const {
        LinkedList result;
        Polynomial* p1 = this->head;
        Polynomial* p2 = other.head;

        while (p1 || p2) {
            if (p1 && (!p2 || p1->getExponent() > p2->getExponent())) {
                result.InsertTerm(p1->getCoefficient(), p1->getExponent());
                p1 = p1->getNext();
            } else if (p2 && (!p1 || p2->getExponent() > p1->getExponent())) {
                result.InsertTerm(-p2->getCoefficient(), p2->getExponent());
                p2 = p2->getNext();
            } else {
                int diffCoeff = p1->getCoefficient() - p2->getCoefficient();
                if (diffCoeff != 0) {
                    result.InsertTerm(diffCoeff, p1->getExponent());
                }
                p1 = p1->getNext();
                p2 = p2->getNext();
            }
        }
        return result;
    }

    LinkedList operator*(const LinkedList& other) const {
        LinkedList result;
        for (Polynomial* p1 = head; p1 != nullptr; p1 = p1->getNext()) {
            for (Polynomial* p2 = other.head; p2 != nullptr; p2 = p2->getNext()) {
                int newCoeff = p1->getCoefficient() * p2->getCoefficient();
                int newExp = p1->getExponent() + p2->getExponent();
                result.InsertTerm(newCoeff, newExp);
            }
        }
        return result;
    }

    double evaluate(double x) const {
        double result = 0.0;
        Polynomial* temp = head;
        while (temp) {
            result += temp->getCoefficient() * pow(x, temp->getExponent());
            temp = temp->getNext();
        }
        return result;
    }
};