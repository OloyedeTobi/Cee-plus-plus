#include "prototype.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void FillShoppingInfo(Person* person) {
	cout << "Enter the following details" << endl;
	cout << "Customer Name: ";
	cin.getline(person->customer.CustomerName,30);
	cout << "\nCustomer Phone Number:";
	cin.getline(person->customer.PhoneNumber, 15);
	cout << "\nShop Name:";
	cin.getline(person->shop.ShopName, 30);
	cout << "\nAddress:";
	cin.getline(person->shop.Address, 20);
	cout << "\nProduct Name:";
	cin >> person->product.ProductName;
	cin.ignore();
	cout << "\nProduct Quantity:";
	cin >> person->product.Quantity;
	cout << "\nUnit Price:";
	cin >> person->product.UnitPrice;

	person->product.TotalPrice = person->product.Quantity * person->product.UnitPrice;

}


void WriteReceipt(Person person) {
	ofstream file;
	file.open("new.txt");
	if (file.is_open()) {
		file << "******************************************************" << endl;

		file << setw(34) << person.shop.ShopName << endl;
		file << setw(37) << person.shop.Address << endl;
		file << "\n\nCustomer" << setw(25) << person.customer.CustomerName << endl;
		file << "Phone Number" << setw(21) << person.customer.PhoneNumber << endl;

		file << "\n\nYour Order" << endl;

		file << "Product Name" << setw(25) << "Unit Price" << setw(25) << "Quantity Ordered" << endl;
		file << person.product.ProductName << setw(25) << person.product.UnitPrice << setw(20) << person.product.Quantity
			<< endl;
		
		file << setw(40) << "*****" << endl;
		file << setw(37) << "Total Price" << setw(15) << person.product.TotalPrice << endl;
		file << setw(40) << "*****" << endl;
		file << setw(20) << "Thanks for your patronage" << endl;


		file << "******************************************************";

	}

	file.close();



}