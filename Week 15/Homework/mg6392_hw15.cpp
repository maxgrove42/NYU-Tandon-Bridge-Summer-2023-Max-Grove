//
//  main.cpp
//  mg6392_hw15_2
//
//
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

void openInput(ifstream& inFile);

/*--------------------------------------------------------------------------
 * Name Class Declaration
 *------------------------------------------------------------------------*/
class Name {
private:
    string firstName, middleName, lastName;
public:
    friend ostream& operator<<(ostream& outs, const Name& name);
    friend istream& operator>>(istream& ins, Name& name);
    string getFullName() const;
    void setName(string firstName, string middleName, string lastName);
    void setName(string firstName, string lastName);
    
    Name();
    Name(string firstName, string middleName, string lastName);
    Name(string firstName, string lastName);
};

/*--------------------------------------------------------------------------
 * Person Class Declaration and Functions Definition
 *------------------------------------------------------------------------*/
class Person {
private:
    Name name;
    double amountPaid;
    double amountToPay; //negative number implies amount to recieve
public:
    Person(Name name = Name(), double amountPaid = 0) : name(name), amountPaid(amountPaid), amountToPay(0) {};
    Name getName() {return name;};
    double getAmountPaid() {return amountPaid;};
    double getAmountToPay() {return amountToPay;};
    void setAmountToPay(double newAmountToPay) {amountToPay = newAmountToPay;};
    void setAmountPaid(double newAmountPaid) {amountPaid = newAmountPaid;};
    friend istream& operator>>(istream& ins, Person& person);
};

/*--------------------------------------------------------------------------
 Doubly Linked List implementation.
 Includes Head and Tail accessor nodes.
 -- Head and Tail are always empty sentinel nodes to indicate front or end of the List.
 Empty List looks like:
    head -> <- tail
 List with items looks like:
    head -> <- node1 -> <- node2 -> <- tail
 (Arrows indicate doubly linked list)
 
 Includes private nested Node Class, consisting of:
    Person data, next node pointer, previous node pointer
    Node constructor : Node(person, nextNode, previousNode)
 
 List constructor creates empty list with a sentinel head and tail node.
 Destructor pops front until empty, then deletes head and tail sentinel nodes.
 
 *------------------------------------------------------------------------*/
class List {
private:
    struct Node {
        Person person;
        Node* prev;
        Node* next;
        Node(const Person &newPerson = Person(), Node* newNext = nullptr, Node* newPrev = nullptr) : person(newPerson), next(newNext), prev(newPrev) {};
    };
    Node* head;
    Node* tail;
    int size;
    void initialize();
    void clear();
    
public:
    void updateAmountToPay(double costPerPerson);
    void determinePaymentAmounts();
    
    void pushFront(Person &person);
    void pushBack(Person &person);
    void popFront();
    void popBack();
    bool isEmpty();
    int getSize();
    
    List();
    List(const List& original);
    ~List();
    List& operator =(const List& original);
};

/*--------------------------------------------------------------------------
 * Friend Group Declaration (essentially a Linked List of friends with
 * some helper / driver functions).
 *------------------------------------------------------------------------*/
class FriendGroup {
private:
    List friends;
    double totalBill;
    double costPerPerson;
public:
    FriendGroup();
    void addFriend(Person& person);
    void printDetails();
    double getTotalBill();
    double getCostPerPerson();
    void runPayments();
    friend istream& operator>>(istream& inStream, FriendGroup &friendGroup);
};


/*--------------------------------------------------------------------------
 * Main
 *------------------------------------------------------------------------*/
int main() {
    ifstream inStream;
    openInput(inStream);
    
    /* data.txt contents:
     76.80 Max Grove
     100.00 Brenda Maytorena Lara
     11 Mia
     14.20 Will M. Grove
     */
    
    FriendGroup myGroup;
    inStream >> myGroup;
    
    myGroup.runPayments();
    
    cout << endl;
    
    /* Expected output:
     Your total bill was $202.00.
     After the below payments are completed, you will each have spent about $50.50.
     Mia, you will pay Max Grove $26.30.
     Mia, you will pay Brenda Maytorena Lara $13.20.
     Will M. Grove, you will pay Brenda Maytorena Lara $36.30.
     */
    
    return 0;
}

/*--------------------------------------------------------------------------
 * Person friend functions (>> operator)
 *------------------------------------------------------------------------*/
 istream& operator>>(istream& ins, Person& person) {
    ins >> person.amountPaid;
    ins.ignore(999, ' ');
    ins >> person.name;
    return ins;
 }
/*--------------------------------------------------------------------------
 * List Constructor, Destructor, =operator, copy constructor
 *------------------------------------------------------------------------*/
List::List() {
    initialize();
}
List::List(const List& original) {
    initialize();
    if (original.head == nullptr)
        head = nullptr;
    else {
        for (Node *temp = original.head->next; temp->next != nullptr; temp = temp->next) {
            this->pushBack(temp->person);
        }
    }
}
List::~List() {
    clear();
    delete head;
    delete tail;
    head = nullptr;
    tail = nullptr;
}

List& List::operator =(const List& original) {
    if (this == &original) return *this;
    clear();
    for (Node *temp = original.head->next; temp->next != nullptr; temp = temp->next) {
        this->pushBack(temp->person);
    }
    return *this;
}
/*--------------------------------------------------------------------------
 * List Functions
 *------------------------------------------------------------------------*/
void List::updateAmountToPay(double costPerPerson) {
    for (Node* temp = head->next; temp->next != nullptr; temp = temp->next) {
        double amountToPay = costPerPerson - temp->person.getAmountPaid();
        temp->person.setAmountToPay(amountToPay);
    }
}

void List::determinePaymentAmounts() {
    /* For each node in the list ("payer"),
        get their amount paid. If this is negative, they are owed money, so continue to the next Node.
        While the payer's amountToPay is still positive, go through each of the other Node's ("recipients").
            If the recipient is the payer, or the recipient has money to pay out, skip them and go to the
            next possible recipient.
        The payer will pay recipient the minimum of their amount to pay and the recipients amount paid.
        Payer amount to pay will decrement by payment amount and recipient amountPaid will increment by payment.
            Print the amount that payer will pay recipient.
     */
    for (Node* payer = head->next; payer->next != nullptr; payer = payer->next) {
        double payerAmountToPay = payer->person.getAmountToPay();
        
    
        if (payerAmountToPay <= 0)
            continue;
        else {
            while (payerAmountToPay > 0) {
                //if we are on the last payer and their payment amount is <= 0.05, end the allocations. There may be times when someone is paying slightly more due to rounding.
                if (payer->next->next == nullptr && payerAmountToPay <= 0.05) break;
                for (Node* recipient = head->next; recipient->next != nullptr; recipient = recipient->next) {
                    if (recipient == payer || recipient->person.getAmountToPay() >= 0)
                        continue;
                    
                    else {
                        double paymentAmount = min(payer->person.getAmountToPay(), -1 * recipient->person.getAmountToPay());
                        
                        
                        payer->person.setAmountToPay(payerAmountToPay - paymentAmount);
                        payerAmountToPay = payer->person.getAmountToPay();
                        recipient->person.setAmountToPay(recipient->person.getAmountToPay() + paymentAmount);
                        
                        if (paymentAmount > 0) {
                            //print what happened.
                            cout << payer->person.getName() << ", you will pay ";
                            cout << recipient->person.getName() << " $" << paymentAmount << "." << endl;
                        }
                    }
                }
            }
        }
    }
}

void List::initialize() {
    size = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
}

void List::clear() {
    while (!isEmpty())
        popFront();
}
void List::pushFront(Person &person) {
    Node * insert = new Node(person, head->next, head);
    head->next->prev = insert;
    head->next = insert;
    size++;
}
void List::pushBack(Person &person) {
    Node * insert = new Node(person, tail, tail->prev);
    tail->prev->next = insert;
    tail->prev = insert;
    size++;
}
void List::popFront() {
    if (isEmpty()) {
        cout << "attempting to pop an empty List";
        exit(1);
    }
    Node* p = head->next;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    size--;
}
void List::popBack() {
    if (isEmpty()) {
        cout << "attempting to pop an empty List";
        exit(1);
    }
    Node * p = tail->prev;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    size--;
}
bool List::isEmpty() {
    return (size == 0);
}
int List::getSize() {
    return size;
}

/*--------------------------------------------------------------------------
 * FriendGroup Functions
 *------------------------------------------------------------------------*/
istream& operator>>(istream& inStream, FriendGroup& friendGroup) {
    double tempPaymentAmount;
    Name tempName;
    while (inStream >> tempPaymentAmount) {
        inStream.ignore(999, ' ');
        inStream >> tempName;

        Person tempPerson(tempName, tempPaymentAmount);
        friendGroup.addFriend(tempPerson);
        
    }
    return inStream;
}
FriendGroup::FriendGroup() {
    totalBill = 0;
    costPerPerson = 0;
}
void FriendGroup::addFriend(Person& person) {
    friends.pushBack(person);
    totalBill += person.getAmountPaid();
    costPerPerson = totalBill / friends.getSize();
}
double FriendGroup::getTotalBill() {
    return totalBill;
}
double FriendGroup::getCostPerPerson() {
    return costPerPerson;
}
void FriendGroup::runPayments() {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    cout << "Your total bill was $" << totalBill << "." << endl;
    cout << "After the below payments are completed, you will each have spent about $";
    cout << costPerPerson << "." << endl;
    friends.updateAmountToPay(costPerPerson);
    friends.determinePaymentAmounts();
}

/*--------------------------------------------------------------------------
 * Name Functions
 *------------------------------------------------------------------------*/
ostream& operator<<(ostream& outs, const Name& name) {
    cout << name.getFullName();
    return outs;
}
istream& operator>>(istream& ins, Name& name) {
    string fullName;
    string tempFirst, tempMiddle, tempLast;
    getline(ins, fullName);
    int i;
    for (i = 0; i < fullName.length() && fullName[i] != ' ' && fullName[i] != '\n'; i++) {
        tempFirst.push_back(fullName[i]);
    }
    
    if (i >= fullName.length()) {
        name.firstName = tempFirst;
        name.middleName = "";
        name.lastName = "";
        return ins;
    }
    
    for (++i; i < fullName.length() && fullName[i] != ' ' && fullName[i] != '\n'; i++) {
        tempMiddle.push_back(fullName[i]);
    }
    
    if (i >= fullName.length()) {
        name.firstName = tempFirst;
        name.lastName = tempMiddle;
        name.middleName = "";
        return ins;
    }
    for (++i; i < fullName.length() && fullName[i] != ' ' && fullName[i] != '\n'; i++) {
        tempLast.push_back(fullName[i]);
    }
    name.firstName = tempFirst;
    name.middleName = tempMiddle;
    name.lastName = tempLast;
    return ins;
}
string Name::getFullName() const {
    
    if (middleName.length() > 0)
        return (firstName + " " + middleName + " " + lastName);
    else if (lastName.length() > 0)
        return (firstName + " " + lastName);
    else
        return (firstName);
}
void Name::setName(string firstName, string middleName, string lastName) {
    this->firstName = firstName;
    this->middleName = middleName;
    this->lastName = lastName;
}
void Name::setName(string firstName, string lastName) {
    this->firstName = firstName;
    this->middleName = "";
    this->lastName = lastName;
}

Name::Name() {
    firstName = "";
    middleName = "";
    lastName = "";
}
Name::Name(string firstName, string middleName, string lastName) {
    setName(firstName, middleName, lastName);
}
Name::Name(string firstName, string lastName) {
    setName(firstName, lastName);
}

void openInput(ifstream& inFile) {
    string fileName;
    cout << "Please enter the file name: ";
    cin >> fileName;
    inFile.open(fileName);
    while (inFile.fail()) {
        char temp;
        cout << "Unable to open " << fileName << "." << endl;
        cout << "Is there a typo in the file name (y/n): ";
        cin >> temp;
        cin.ignore(999,'\n');
        if (temp == 'n') {
            cout << "Given no tpyo, error occured in file opening." << endl;
            exit(1);
        }
        else {
            cout << "Please enter the file name: ";
            cin >> fileName;
            inFile.open(fileName);
        }
    }
}
