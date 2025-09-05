#include <iostream>
#include <string>
using namespace std;

class ResearchPaper {
public:
    string* authorList;
    int numAuthors;
    ResearchPaper(int totalAuthors) {
        numAuthors = totalAuthors;
        authorList = new string[numAuthors];
        for (int i = 0; i < numAuthors; ++i) {
            cout << "Author's Name " << (i + 1) << ": ";
            getline(cin >> ws, authorList[i]);
        }
    }

    ~ResearchPaper() {
        delete[] authorList;
    }

    ResearchPaper(const ResearchPaper& other) {
        numAuthors = other.numAuthors;
        authorList = new string[numAuthors];
        for (int i = 0; i < numAuthors; ++i) {
            authorList[i] = other.authorList[i];
        }
    }

    ResearchPaper& operator=(const ResearchPaper& other) {
        if (this != &other) {
            delete[] authorList;
            numAuthors = other.numAuthors;
            authorList = new string[numAuthors];
            for (int i = 0; i < numAuthors; ++i) {
                authorList[i] = other.authorList[i];
            }
        }
        return *this;
    }

    void displayAuthors() const {
        cout << "Authors: ";
        for (int i = 0; i < numAuthors; ++i) {
            cout << authorList[i];
            if (i < numAuthors - 1) cout << ", ";
        }
        cout << endl;
    }
};

int main() {
    ResearchPaper paperA(2);
    ResearchPaper paperB = paperA;

    cout << "\nInitial author lists:\n";
    cout << "Paper A - "; paperA.displayAuthors();
    cout << "Paper B - "; paperB.displayAuthors();

    paperB.authorList[0] = "newName";
    paperB.authorList[1] = "newName2";

    cout << "\nAfter modifying Paper B:\n";
    cout << "Paper A - "; paperA.displayAuthors();
    cout << "Paper B - "; paperB.displayAuthors();

    return 0;
}