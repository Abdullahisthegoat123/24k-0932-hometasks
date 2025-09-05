#include <iostream>
using namespace std;

class Box {
private:
    int* boxVolume;

public:
    Box() {
        boxVolume = new int(0);
    }

    Box(int val) {
        boxVolume = new int(val);
    }

    Box(const Box& other) {
        boxVolume = new int(*other.boxVolume);
    }

    
    void changeVolume(int v) {
        *boxVolume = v;
    }
    
    void displayVolume() const {
        cout << "Current volume: " << *boxVolume << endl;
    }
    ~Box() {
        delete boxVolume;
    }
};

int main() {
    Box box(5000);
    Box copiedBox = box;

    cout << "Volumes before modification:" << endl;
    cout << "Original box" << endl;
    box.displayVolume();
    cout << "Copied box" << endl;
    copiedBox.displayVolume();

    copiedBox.changeVolume(24555);

    cout << "Volumes after modifying copiedBox:" << endl;
    cout << "Original box" << endl;
    box.displayVolume();
    cout << "Copied box " << endl;
    copiedBox.displayVolume();

    return 0;
}