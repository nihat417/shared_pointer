#include <iostream>
using namespace std;

#include "shared.h"

class Exam
{
public:
    int x, y, z;
    Exam() : x(), y(), z() {}

};

int main()
{
    Shared<Exam> exams;
    cout << exams.getCount() << endl;

    Shared<Exam> exams_1(new Exam());
    cout << exams_1.getCount() << endl;

    Shared<Exam> exams_2(exams_1);
    cout << exams_1.getCount() << endl;
    cout << exams_2.getCount() << endl;
}