#include <iostream>
#include <string>
using namespace std;

struct Ticket {
    int id;
    string name;
    string ride;
    Ticket* next;
    Ticket(int i, string n, string r) : id(i), name(n), ride(r), next(nullptr) {}
};

class TicketList {
    Ticket* last;
public:
    TicketList() : last(nullptr) {}

    void issueEnd(int id, string name, string ride) {
        Ticket* t = new Ticket(id, name, ride);
        if (!last) {
            last = t;
            t->next = t;
        } else {
            t->next = last->next;
            last->next = t;
            last = t;
        }
    }

    void issueFront(int id, string name, string ride) {
        Ticket* t = new Ticket(id, name, ride);
        if (!last) {
            last = t;
            t->next = t;
        } else {
            t->next = last->next;
            last->next = t;
        }
    }

    void cancelById(int id) {
        if (!last) return;
        Ticket* curr = last->next, *prev = last;
        do {
            if (curr->id == id) {
                if (curr == last && curr == last->next) {
                    delete curr;
                    last = nullptr;
                } else {
                    prev->next = curr->next;
                    if (curr == last) last = prev;
                    delete curr;
                }
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != last->next);
    }

    void cancelFirst() {
        if (!last) return;
        Ticket* first = last->next;
        if (first == last) {
            delete first;
            last = nullptr;
        } else {
            last->next = first->next;
            delete first;
        }
    }

    void searchById(int id) {
        if (!last) return;
        Ticket* curr = last->next;
        do {
            if (curr->id == id) {
                cout << curr->id << " " << curr->name << " " << curr->ride << endl;
                return;
            }
            curr = curr->next;
        } while (curr != last->next);
        cout << "Not found\n";
    }

    void displayCircular() {
        if (!last) return;
        Ticket* curr = last->next;
        do {
            cout << curr->id << " " << curr->name << " " << curr->ride << endl;
            curr = curr->next;
        } while (curr != last->next);
    }

    int countTickets() {
        if (!last) return 0;
        int cnt = 0;
        Ticket* curr = last->next;
        do {
            cnt++;
            curr = curr->next;
        } while (curr != last->next);
        return cnt;
    }

    void nextTicket(int id) {
        if (!last) return;
        Ticket* curr = last->next;
        do {
            if (curr->id == id) {
                Ticket* nxt = curr->next;
                cout << nxt->id << " " << nxt->name << " " << nxt->ride << endl;
                return;
            }
            curr = curr->next;
        } while (curr != last->next);
        cout << "Not found\n";
    }
};

int main() {
    TicketList t;
    cout << "Issuing tickets...\n";
    t.issueEnd(1, "Ali", "RollerCoaster");
    t.issueEnd(2, "Sara", "FerrisWheel");
    t.issueFront(0, "VIP", "RollerCoaster");

    cout << "\nAll tickets (circular order):\n";
    t.displayCircular();

    cout << "\nCancelling ticket with ID 2...\n";
    t.cancelById(2);

    cout << "Cancelling first ticket...\n";
    t.cancelFirst();

    cout << "\nTickets after cancellations:\n";
    t.displayCircular();

    cout << "\nSearching for ticket with ID 1:\n";
    t.searchById(1);

    cout << "\nTotal tickets: " << t.countTickets() << endl;

    cout << "\nNext ticket after ID 1:\n";
    t.nextTicket(1);

    return 0;
}