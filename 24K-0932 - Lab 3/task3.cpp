#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int id;
    string name;
    double price;
    Node *prev;
    Node *next;
    Node(int i, string n, double p) : id(i), name(n), price(p), prev(nullptr), next(nullptr) {}
};

class Cart
{
    Node *head;
    Node *tail;

public:
    Cart() : head(nullptr), tail(nullptr) {}

    void insertEnd(int id, string name, double price)
    {
        Node *n = new Node(id, name, price);
        if (!head)
            head = tail = n;
        else
        {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    void insertFront(int id, string name, double price)
    {
        Node *n = new Node(id, name, price);
        if (!head)
            head = tail = n;
        else
        {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }

    void removeFront()
    {
        if (!head)
            return;
        Node *temp = head;
        if (head == tail)
            head = tail = nullptr;
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void removeEnd()
    {
        if (!tail)
            return;
        Node *temp = tail;
        if (head == tail)
            head = tail = nullptr;
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void searchByID(int id)
    {
        Node *curr = head;
        while (curr)
        {
            if (curr->id == id)
            {
                cout << curr->id << " " << curr->name << " " << curr->price << endl;
                return;
            }
            curr = curr->next;
        }
        cout << "Not found\n";
    }

    void updatePriceByID(int id, double price)
    {
        Node *curr = head;
        while (curr)
        {
            if (curr->id == id)
            {
                curr->price = price;
                return;
            }
            curr = curr->next;
        }
    }

    void displayFrontToEnd()
    {
        Node *curr = head;
        if (!curr) {
            cout << "Cart is empty.\n";
            return;
        }
        cout << "ID\tName\tPrice\n";
        cout << "-------------------------\n";
        while (curr)
        {
            cout << curr->id << "\t" << curr->name << "\t" << curr->price << endl;
            curr = curr->next;
        }
    }

    void displayEndToFront()
    {
        Node *curr = tail;
        if (!curr) {
            cout << "Cart is empty.\n";
            return;
        }
        cout << "ID\tName\tPrice\n";
        cout << "-------------------------\n";
        while (curr)
        {
            cout << curr->id << "\t" << curr->name << "\t" << curr->price << endl;
            curr = curr->prev;
        }
    }

    int countItems()
    {
        int cnt = 0;
        Node *curr = head;
        while (curr)
        {
            cnt++;
            curr = curr->next;
        }
        return cnt;
    }

    void findMostExpensive()
    {
        if (!head)
        {
            cout << "Cart empty\n";
            return;
        }
        Node *curr = head;
        Node *maxNode = head;
        while (curr)
        {
            if (curr->price > maxNode->price)
                maxNode = curr;
            curr = curr->next;
        }
        cout << maxNode->id << " " << maxNode->name << " " << maxNode->price << endl;
    }
};

int main()
{
    Cart cart;
    int choice;
    cout << "1: Insert at End\n2: Insert at Front\n3: Remove First\n4: Remove Last\n5: Search by ID\n6: Update Price by ID\n7: Display Front to End\n8: Display End to Front\n9: Count Items\n10: Most Expensive\n0: Exit\n";
    while (true)
    {
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1)
        {
            int id;
            string name;
            double price;
            cout << "Enter ID Name Price: ";
            cin >> id >> name >> price;
            cart.insertEnd(id, name, price);
        }
        else if (choice == 2)
        {
            int id;
            string name;
            double price;
            cout << "Enter ID Name Price: ";
            cin >> id >> name >> price;
            cart.insertFront(id, name, price);
        }
        else if (choice == 3)
        {
            cart.removeFront();
            cout << "First item removed.\n";
        }
        else if (choice == 4)
        {
            cart.removeEnd();
            cout << "Last item removed.\n";
        }
        else if (choice == 5)
        {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            cart.searchByID(id);
        }
        else if (choice == 6)
        {
            int id;
            double price;
            cout << "Enter ID and new Price: ";
            cin >> id >> price;
            cart.updatePriceByID(id, price);
        }
        else if (choice == 7)
        {
            cout << "Cart (Front to End):\n";
            cart.displayFrontToEnd();
        }
        else if (choice == 8)
        {
            cout << "Cart (End to Front):\n";
            cart.displayEndToFront();
        }
        else if (choice == 9)
        {
            cout << "Total items: " << cart.countItems() << endl;
        }
        else if (choice == 10)
        {
            cout << "Most expensive item:\n";
            cart.findMostExpensive();
        }
        else if (choice == 0)
        {
            cout << "Exiting...\n";
            break;
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    }
}