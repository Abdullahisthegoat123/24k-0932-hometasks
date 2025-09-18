#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string item;
    int price;
    Node *next;
    Node(string i, int p) : item(i), price(p), next(nullptr) {}
};

class ShoppingCart
{
    Node *head;

public:
    ShoppingCart() : head(nullptr) {}

    void insertAfter(string afterItem, string item, int price)
    {
        Node *curr = head;
        while (curr)
        {
            if (curr->item == afterItem)
            {
                Node *n = new Node(item, price);
                n->next = curr->next;
                curr->next = n;
                return;
            }
            curr = curr->next;
        }
        cout << afterItem << " not found!\n";
    }

    void addEnd(string item, int price)
    {
        Node *n = new Node(item, price);
        if (!head)
        {
            head = n;
            return;
        }
        Node *curr = head;
        while (curr->next)
            curr = curr->next;
        curr->next = n;
    }

    void addFront(string item, int price)
    {
        Node *n = new Node(item, price);
        n->next = head;
        head = n;
    }

    void display()
    {
        Node *curr = head;
        cout << "Shopping Cart Items:\n";
        while (curr)
        {
            cout << curr->item << " - $" << curr->price << endl;
            curr = curr->next;
        }
    }
    void search(string item)
    {
        Node *curr = head;
        while (curr)
        {
            if (curr->item == item)
            {
                cout << item << " exists in cart. Price: $" << curr->price << endl;
                return;
            }
            curr = curr->next;
        }
        cout << item << " not found in cart.\n";
    }
};

int main()
{
    ShoppingCart cart;
    cart.addEnd("Laptop", 1000);
    cart.addEnd("Phone", 700);
    cart.addEnd("Tablet", 400);
    cart.addEnd("Headphones", 150);
    cart.addFront("Smartwatch", 200);
    cart.addEnd("Keyboard", 80);
    cart.insertAfter("Phone", "Monitor", 300);
    cart.search("Tablet");

    cart.display();

    return 0;
}