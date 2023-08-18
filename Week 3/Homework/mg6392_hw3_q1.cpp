//
//  main.cpp
//  hw3q1
//
//  Created by Max Grove on 7/22/23.
//
/*
 This program computes how much a customer has to pay after
 purchasing two items. The price is calculated as following:
 - Buy one, get one 50% off promotion (50% off on cheaper item)
 - If customer is club card member, addt'l 10% off
 - Tax is added (based on user entering tax rate.
 
 Inputs:
 - Two items' prices (type doubles)
 - Club Card membership (char input 'y' or 'n' or 'Y' or 'N')
 - Tax rate (8.25 = 8.25%)
 
 Outputs:
 - Base price, Price after discounts, Total Price (with tax added)
 */

#include <iostream>
using namespace std;

const double BOGO_DISCOUNT = 0.5; //discount rate on lower priced item
const double CLUB_DISCOUNT = 0.1;

int main() {
    double item1, item2, taxRate;
    char clubCard;
    double basePrice, priceDiscounted, totalPrice;
    
    //obtain user inputs
    cout << "Enter price of first item: ";
    cin >> item1;
    cout << "Enter price of second item: ";
    cin >> item2;
    cout << "Does customer have a club card? (Y/N): ";
    cin >> clubCard;
    cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin >> taxRate;
    
    //calculate base price.
    basePrice = item1 + item2;
    
    //calculate price after discounts. Lower Priced item discounted based on BOGO_DISCOUNT rate.
    if (item1 < item2) {
        priceDiscounted = item2 + BOGO_DISCOUNT * item1;
    }
    else {
        priceDiscounted = item1 + BOGO_DISCOUNT * item2;
    }
    
    // discount if customer is club card member. Rate stored in CLUB_DISCOUNT
    if (clubCard == 'Y' || clubCard == 'y') {
        priceDiscounted *= (1-CLUB_DISCOUNT);
    }
    
    //add tax
    totalPrice = priceDiscounted * (1 + taxRate / 100);
    
    //output to user
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2); //set 2 decimal places - dealing with money. HW question shows show 1 dec place but assuming 2 was meant.
    cout << "Base price: " << basePrice << endl;
    cout << "Price after discounts: " << priceDiscounted << endl;
    
    cout.precision(5); //set 5 decimal places (based on homework question)
    cout << "Total Price: " << totalPrice << endl;
    
    return 0;
}
