#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class figure {
public:
    virtual double GetArea() {
        return 0;
    };
    virtual void Print() {};
};

class triangle : public figure {
private:
    double base;
    double height;
public:
    triangle(int b, int h) : base(b), height(h) {}
    void Print() {
        printf("%s %f %f\t%f\n", "triangle", base, height, GetArea());
    }
    double GetArea() {
        return 0.5 * base * height;
    }
};

class rectangle : public figure {
private:
    double side1;
    double side2;
public:
    rectangle(int s1, int s2) : side1(s1), side2(s2) {}
    void Print() {
        printf("%s %f %f\t%f\n", "rectangle", side1, side2, GetArea());
    }
    double GetArea() {
        return side1 * side2;
    }
};

class circle : public figure {
private:
    double radius;
public:
    circle(int r) : radius(r) {}
    void Print() {
        printf("%s %f\t\t\t\t%f\n", "circle", radius, GetArea());
    }
    double GetArea() {
        return 3.14 * radius * radius;
    }
};

int main() {
    ifstream infile;
    infile.open("Lab2.txt");
    if (infile.fail()) {
        cerr << "error" << endl;
        return -1;
    }
    int num;
    infile >> num;
    vector<figure*> figures;
    figures.reserve(100);

    for (int i = 0; i < num; i++) {
        char buffer[10];
        infile >> buffer;
        if (buffer[0] == 't') {
            int b, h;
            infile >> b >> h;
            triangle *pt = new triangle(b, h);
            figures.push_back(pt);
        }
        else if (buffer[0] == 'r') {
            int s1, s2;
            infile >> s1 >> s2;
            rectangle *pr = new rectangle(s1, s2);
            figures.push_back(pr);
        }
        else {
            int r;
            infile >> r;
            circle *pc = new circle(r);
            figures.push_back(pc);
        }

    }

    for (figure * pf : figures) {
        pf->Print();
    }

    for (figure * pf : figures) {
        delete pf;
    }
}