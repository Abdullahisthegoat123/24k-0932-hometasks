#include <iostream>
#include <string>
using namespace std;

struct Node {
    string itemName;
    double price;
    Node* next;
    Node(string name, double p) : itemName(name), price(p), next(nullptr) {}
};

class ShoppingCart {
private:
    Node* head;
public:
    ShoppingCart() : head(nullptr) {}

    void addItemToTail(string name, double price) {
        Node* newNode = new Node(name, price);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void deleteItemFromFront() {
        if (!head) {
            cout << "Cart is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Removed: " << temp->itemName << endl;
        delete temp;
    }

    void searchByItemName(string name) {
        Node* temp = head;
        while (temp) {
            if (temp->itemName == name) {
                cout << "Found: " << temp->itemName << " - Price: " << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item not found.\n";
    }

    void searchByPosition(int pos) {
        Node* temp = head;
        int idx = 0;
        while (temp) {
            if (idx == pos) {
                cout << "Position " << pos << ": " << temp->itemName << " - Price: " << temp->price << endl;
                return;
            }
            temp = temp->next;
            idx++;
        }
        cout << "Invalid position.\n";
    }

    void displayCart() {
        Node* temp = head;
        if (!temp) {
            cout << "Cart is empty.\n";
            return;
        }
        cout << "Shopping Cart:\n";
        while (temp) {
            cout << temp->itemName << " - Price: " << temp->price << endl;
            temp = temp->next;
        }
    }

    ~ShoppingCart() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    ShoppingCart cart;
    int choice;
    string name;
    double price;
    int pos;

    do {
        cout << "\n1. Add Item to Tail\n2. Delete Item from Front\n3. Search by Item Name\n4. Search by Position\n5. Display Entire Cart\n0. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter item name: ";
                cin >> name;
                cout << "Enter price: ";
                cin >> price;
                cart.addItemToTail(name, price);
                break;
            case 2:
                cart.deleteItemFromFront();
                break;
            case 3:
                cout << "Enter item name to search: ";
                cin >> name;
                cart.searchByItemName(name);
                break;
            case 4:
                cout << "Enter position to search: ";
                cin >> pos;
                cart.searchByPosition(pos);
                break;
            case 5:
                cart.displayCart();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}