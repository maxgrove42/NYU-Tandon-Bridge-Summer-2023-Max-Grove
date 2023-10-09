//Created by Max Grove, mg6392
//

#include <string>
#include <iostream>
using namespace std;

class Check;
class Money;

int convertInt(char ch);
Check* getCheckInputs(int numChecks);
int getNumChecks();
void displayCashedValues(Money &sumCashedChecks, Money &sumUnCashedChecks, const Check *checks, int numChecks);
void getDeposits(Money &deposits);
void getBalances(Money &priorBalance, Money &userNewBalance);
void displayBankBalance(const Money &priorBalance, const Money &deposits, const Money &sumCashedChecks, Money &bankBalance);
void displayDifference(const Money &userBalance, const Money &bankBalance);
Check* sortChecks(Check *checks, int numChecks);
int indexOfSmallestCheck(Check *checks, int startIndex, int numChecks);
void swapChecks(Check &check1, Check &check2);
void displayChecks(Check *yourChecks, int numChecks);

void runBank();

class Money
{
public:
    Money(long dollars, int cents);
    Money(long dollars); //Initializes the object so its value represents $dollars.00.
    Money(); //Initializes the object so its value represents $0.00.
    
    double getValue();
    
    friend Money operator +(const Money &amount1, const Money &amount2);
    friend Money operator -(const Money &amount1, const Money &amount2);
    friend Money operator -(const Money &amount);
    friend bool operator ==(const Money &amount1, const Money &amount2);
    friend bool operator !=(const Money &amount1, const Money &amount2);
    friend bool operator <(const Money &amount1, const Money &amount2);
    friend bool operator >(const Money &amount1, const Money &amount2);
    friend bool operator <=(const Money &amount1, const Money &amount2);
    friend bool operator >=(const Money &amount1, const Money &amount2);
    friend istream& operator >>(istream &ins, Money &amount);
    friend ostream& operator <<(ostream &outs, const Money &amount);

private:
    long allCents;
};

class Check {
public:
    Check(int newCheckNumber, const Money &newCheckAmount, bool newCashed);
    Check();
    
    int getCheckNumber() const;
    Money getCheckAmount() const;
    bool getCashed() const;
    void setCheckNumber(int newCheckNumber);
    void setCheckAmount(Money newCheckAmount);
    void setCashed(bool newCashed);
    
    friend istream& operator >>(istream &ins, Check &check);
    friend ostream& operator <<(ostream &outs, const Check &check);
    
private:
    int checkNumber;
    Money checkAmount;
    bool cashed;
};

/*--------------------------------------------------------------------------
 * Main
 *------------------------------------------------------------------------*/
int main() {
    char goAgain = 'Y';
    while (goAgain == 'Y' || goAgain == 'y') {
        runBank();
        cout << "Want to balance another checkbook? Y for Yes, N for no" << endl;
        cin >> goAgain;
        cout << endl;
    }
    cout << "Thank you for balancing your checkbook with Max's Checkbook Balancer. Goodbye." << endl << endl;
    return 0;
}

/*--------------------------------------------------------------------------
 * Check Functions
 *------------------------------------------------------------------------*/
int Check::getCheckNumber() const {
    return checkNumber;
}
Money Check::getCheckAmount() const {
    return checkAmount;
}
bool Check::getCashed() const {
    return cashed;
}
void Check::setCheckNumber(int newCheckNumber) {
    checkNumber = newCheckNumber;
}
void Check::setCheckAmount(Money newCheckAmount) {
    checkAmount = newCheckAmount;
}
void Check::setCashed(bool newCashed) {
    cashed = newCashed;
}
Check::Check(int newCheckNumber, const Money &newCheckAmount, bool newCashed) {
    checkNumber = newCheckNumber;
    checkAmount = newCheckAmount;
    cashed = newCashed;
}
Check::Check() {
    Money temp;
    checkNumber = -1;
    checkAmount = temp;
    cashed = false;
}

/*--------------------------------------------------------------------------
 * Overloaded Operators for Check Class
 *------------------------------------------------------------------------*/
istream& operator >>(istream &ins, Check &check) {
    int newCheckNumber;
    Money newCheckAmount;
    bool newCashed;
    
    ins >> newCheckNumber >> newCheckAmount >> newCashed;
    
    check.checkNumber = newCheckNumber;
    check.checkAmount = newCheckAmount;
    check.cashed = newCashed;
    
    return ins;
}
ostream& operator <<(ostream &outs, const Check &check) {
    cout << "Check number: " << check.checkNumber << endl;
    cout << "   Check Amount: " << check.checkAmount << endl;
    if (check.cashed)
        cout << "   Check cashed: Yes" << endl;
    else
        cout << "   Check cashed: No" << endl;
    return outs;
}

/*--------------------------------------------------------------------------
 * Money functions
 *------------------------------------------------------------------------*/
Money::Money(long dollars, int cents) {
    if (dollars * cents < 0) { //If one is negative and one is positive
        cout << "Illegal values for dollars and cents. Both must be positive or negative." << endl;
        exit(1);
    }
    allCents = dollars * 100 + cents;
}
Money::Money(long dollars) {
    allCents = dollars * 100;
}
Money::Money() {
    allCents = 0;
}
double Money::getValue() {
    return allCents * 0.01;
}

/*--------------------------------------------------------------------------
 * Overloaded Operators for Money Class
 *------------------------------------------------------------------------*/
Money operator +(const Money & amount1, const Money & amount2) {
    Money temp;
    temp.allCents = amount1.allCents + amount2.allCents;
    return temp;
}
Money operator -(const Money &amount1, const Money &amount2) {
    Money temp;
    temp.allCents = amount1.allCents - amount2.allCents;
    return temp;
}
Money operator -(const Money &amount) {
    Money temp;
    temp.allCents = -amount.allCents;
    return temp;
}
bool operator ==(const Money &amount1, const Money &amount2) {
    return (amount1.allCents == amount2.allCents);
}
bool operator !=(const Money &amount1, const Money &amount2) {
    return (amount1.allCents != amount2.allCents);
}
bool operator <(const Money &amount1, const Money &amount2) {
    return (amount1.allCents < amount2.allCents);
}
bool operator >(const Money &amount1, const Money &amount2) {
    return (amount1.allCents > amount2.allCents);
}
bool operator <=(const Money &amount1, const Money &amount2) {
    return (amount1.allCents <= amount2.allCents);
}
bool operator >=(const Money &amount1, const Money &amount2) {
    return (amount1.allCents >= amount2.allCents);
}
istream& operator >>(istream &ins, Money & amount) {
    char oneChar, decimalPoint, digit1, digit2;
    long dollars;
    int cents;
    bool negative = false;
    
    ins >> oneChar;
    if (oneChar == '-') {
        negative = true;
        ins >> oneChar;
    }
    //oneChar should be '$' at this point
    
    ins >> dollars >> decimalPoint >> digit1 >> digit2;
    
    if (oneChar != '$' || decimalPoint != '.' || digit1 < '0' || digit1 > '9' || digit2 < '0' || digit2 > '9') {
        cout << "Error on money input. Illegal entry.";
        exit(1);
    }
    cents = convertInt(digit1) * 10 + convertInt(digit2);
    amount.allCents = dollars * 100 + cents;
    if (negative)
        amount.allCents = -amount.allCents;
    
    return ins;
}
ostream& operator <<(ostream &outs, const Money &amount) {
    long dollars, cents;
    if (amount.allCents < 0) {
        cents = -amount.allCents % 100;
    }
    else {
        cents = amount.allCents % 100;
    }
    dollars = amount.allCents / 100;
    
    if (amount.allCents < 0) {
        dollars = dollars * -1;
        outs << "-$" << dollars << ".";
    }
    else
        outs << "$" << dollars << ".";
    
    if (cents < 10)
        outs << "0";
    outs << cents;
    
    return outs;
}

/*--------------------------------------------------------------------------
 * Additional functions
 *------------------------------------------------------------------------*/
void runBank() {
    int numChecks;
    Check* yourChecks;
    Money sumCashedChecks, sumUnCashedChecks, deposits, priorBalance, userNewBalance, bankNewBalance;
    
    numChecks = getNumChecks();
    yourChecks = getCheckInputs(numChecks);
    displayCashedValues(sumCashedChecks, sumUnCashedChecks, yourChecks, numChecks);
    getDeposits(deposits);
    getBalances(priorBalance, userNewBalance);
    displayBankBalance(priorBalance, deposits, sumCashedChecks, bankNewBalance);
    displayDifference(userNewBalance, bankNewBalance);
    displayChecks(yourChecks, numChecks);
    
    delete [] yourChecks;
    yourChecks = nullptr;
}

int convertInt(char ch) {
    if (ch >= '0' && ch <= '9')
        return (int)(ch - '0');
    else {
        cout << "Illegal entry used for convertInt function.";
        exit(1);
    }
}
int getNumChecks() {
    int numChecks;
    cout << "Please enter the number of checks you have: ";
    cin >> numChecks;
    return numChecks;
}
Check* getCheckInputs(int numChecks) {
    string temp;

    Check *yourChecks = new Check[numChecks];
    
    cout << "Please enter the check number, the amount of the check, and whether or not the check has been cashed by typing 1 for yes and 0 for no." << endl;
    cout << "Example: 9 (check number) $40.89 (amount) 1 (cashed indicator)" << endl << "Example: 9 $40.89 1" << endl;
    
    for (int i = 0; i < numChecks; i++) {
        cin >> yourChecks[i];
    }
    
    return yourChecks;
}

void displayCashedValues(Money &sumCashedChecks, Money &sumUnCashedChecks, const Check *checks, int numChecks) {
    for (int i = 0; i < numChecks; i++) {
        if (checks[i].getCashed())
            sumCashedChecks = sumCashedChecks + checks[i].getCheckAmount();
        else
            sumUnCashedChecks = sumUnCashedChecks + checks[i].getCheckAmount();
    }
    cout << "Cashed checks value is: " << sumCashedChecks << endl;
    cout << "Uncashed checks value is: " << sumUnCashedChecks << endl;
    cout << endl;
}

void getDeposits(Money &deposits) {
    Money temp;
    cout << "Please enter the deposits ($x.xx)" << endl;
    cout << "End your deposits by entering $0.00" << endl;
    cin >> temp;
    while (temp != 0) {
        deposits = deposits + temp;
        cin >> temp;
    }
    cout << "The total deposit value is: " << deposits << endl;
    cout << endl;
}
void getBalances(Money &priorBalance, Money &userNewBalance) {
    cout << "Please enter the prior balance amount ($x.xx): ";
    cin >> priorBalance;
    cout << "Please enter the new balance amount per your records: ";
    cin >> userNewBalance;
    cout << endl;
}
void displayBankBalance(const Money &priorBalance, const Money &deposits, const Money &sumCashedChecks, Money &bankBalance) {
    bankBalance = priorBalance + deposits - sumCashedChecks;
    cout << "The balance according to the bank (prior balance + deposits - cashed checks): " << bankBalance << endl;
}
void displayDifference(const Money &userBalance, const Money &bankBalance) {
    cout << "The difference between user entered balance and bank balance is: " << (bankBalance - userBalance) << endl;
    cout << endl;
}

Check* sortChecks(Check *checks, int numChecks) {
    Check *sortedChecks = new Check[numChecks];
    int smallestIndex = 0;
    for (int i = 0; i < numChecks; i++) {
        smallestIndex = indexOfSmallestCheck(checks, i, numChecks);
        swapChecks(checks[i], checks[smallestIndex]);
    }
    return sortedChecks;
}

int indexOfSmallestCheck(Check *checks, int startIndex, int numChecks) {
    int minCheckNumber = checks[startIndex].getCheckNumber();
    int indexOfMin = startIndex;
    for (int i = startIndex + 1; i < numChecks; i++) {
        if (checks[i].getCheckNumber() < checks[indexOfMin].getCheckNumber()) {
            minCheckNumber = checks[i].getCheckNumber();
            indexOfMin = i;
        }
    }
    return indexOfMin;
}
void swapChecks(Check &check1, Check &check2) {
    Check temp = check1;
    check1 = check2;
    check2 = temp;
}
void displayChecks(Check *yourChecks, int numChecks) {
    sortChecks(yourChecks, numChecks);
    cout << "The cashed checks are: " << endl;
    for (int i = 0; i < numChecks; i++) {
        if (yourChecks[i].getCashed()) {
            cout << yourChecks[i];
        }
    }
    cout << endl;
    cout << "The uncashed checks are: " << endl;
    for (int i = 0; i < numChecks; i++) {
        if (!yourChecks[i].getCashed()) {
            cout << yourChecks[i];
        }
    }
    cout << endl;
}
