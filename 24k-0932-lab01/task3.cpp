#include <iostream>
using namespace std;

class Exam
{
public:
    int *mark;

    Exam(int marks)
    {
        mark = new int(marks);
    }

    void updateMarks(int Nmarks)
    {
        *mark = Nmarks;
    }

    void printMarks()
    {
        cout << "Marks: " << *mark << endl;
    }
    ~Exam()
    {
        delete mark;
    }
};

int main()
{
    Exam exam(75);
    Exam copiedExam = exam;

    cout << "Marks before modification:" << endl;
    cout << "Original exam" << endl;
    exam.printMarks();
    cout << "Copied exam" << endl;
    copiedExam.printMarks();

    copiedExam.updateMarks(98);

    cout << "Marks after modifying the copied exam:" << endl;
    cout << "Original exam" << endl;
    exam.printMarks();
    cout << "Copied exam" << endl;
    copiedExam.printMarks();
}