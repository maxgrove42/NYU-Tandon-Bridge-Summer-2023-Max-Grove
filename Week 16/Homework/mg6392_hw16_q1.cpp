//hw16 q1
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void openInput(ifstream& inFile);

class Stack {
    private:
        struct Node {
          char data;
          Node* link;
        };
        Node* top;
    public:
        Stack();
        Stack(const Stack& original);
        ~Stack();
        
        void push(char symbol);
        char pop();
        bool empty() const;
};

class PascalCode {
  private:
    Stack stack;
    bool balance;
    char reverseSymbol(char symbol);
public:
    PascalCode() : balance(true) {};
    bool isBalanced() const {return balance;};
    void recieveSymbol(char symbol);
    void recieveSymbol(string text);
    friend ifstream& operator >>(ifstream& ins, PascalCode& pascal);
};

int main()
{
    ifstream inFile;
    openInput(inFile);
    PascalCode pascal;
    inFile >> pascal;
    if (pascal.isBalanced())
        cout << "Symbols are balanced." << endl;
    else
        cout << "Symbols are not balanced." << endl;
    return 0;
}

Stack::Stack() : top(nullptr) {}
Stack::Stack(const Stack& original) {
    if (original.top == nullptr)
        top = nullptr;
    else {
        Node* temp = original.top;
        Node* end = new Node;
        end->data = temp->data;
        top = end;
        temp = temp->link;
        while (temp != nullptr) {
            end->link = new Node;
            end = end->link;
            end->data = temp->data;
            temp = temp->link;
        }
        end->link = nullptr;
    }
}
Stack::~Stack() {
    char next;
    while (!empty())
        next = pop();
}
void Stack::push(char symbol) {
    Node* newTop = new Node;
    newTop->data = symbol;
    newTop->link = top;
    top = newTop;
}
char Stack::pop() {
    if (empty()) {
        cout << "Error: Trying to pop an empty stack." << endl;
        exit(1);
    }
    char result = top->data;
    Node* temp = new Node;
    temp = top;
    top = top->link;
    delete temp;
    return result;
}
bool Stack::empty() const {
    return (top == nullptr);
}

void PascalCode::recieveSymbol(char symbol) {
    if (symbol == '{' || symbol == '[' || symbol == '(')
        stack.push(symbol);
    else if (symbol == '}' || symbol == ']' || symbol == ')') {
        if (stack.empty())
            balance = false;
        else {
            char popped = stack.pop();
            balance = (reverseSymbol(symbol) == popped);
        }
    }
}

char PascalCode::reverseSymbol(char symbol) {
    switch (symbol) {
        case '}':
            return '{';
            break;
        case ']':
            return '[';
            break;
        case ')':
            return '(';
            break;
        default:
            return symbol;
    }
}

ifstream& operator >>(ifstream& ins, PascalCode& pascal) {
    string temp;
    char tempChar;
    bool hasBegun = false;

    //check for begin in the file. using ins >> char in case there are no spaces
    //  between the end and a symbol.
    while (!hasBegun && (ins >> tempChar)) {
        if (tempChar == 'b' && (ins >> tempChar))
            if (tempChar == 'e' && (ins >> tempChar))
                if (tempChar == 'g' && (ins >> tempChar))
                    if (tempChar == 'i' && (ins >> tempChar))
                        if (tempChar == 'n')
                            hasBegun = true;
    }
    //if we did not encounter begin, there's no file to balance
    if (!hasBegun) {
        cout << "no begin in file." << endl;
        pascal.balance = false;
        return ins;
    }
    while (ins >> tempChar && pascal.balance) {
        //check for end in the file. using ins >> char in case there are no spaces
        //  between the end and a symbol.
        if (tempChar == 'e' && (ins >> tempChar)) {
            if (tempChar == 'n' && (ins >> tempChar)) {
                if (tempChar == 'd' && pascal.stack.empty())
                    return ins;
                else if (tempChar == 'd' && !pascal.stack.empty()) {
                    pascal.balance = false;
                    return ins;
                }
            }
        }
        else
            pascal.recieveSymbol(tempChar);
    }
    return ins;
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
            cout << "Given no typo, error occured in file opening." << endl;
            exit(1);
        }
        else {
            cout << "Please enter the file name: ";
            cin >> fileName;
            inFile.open(fileName);
        }
    }
}
