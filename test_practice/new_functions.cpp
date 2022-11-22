#include <iostream>
#include "prototype.h"
using namespace std;
#include <iomanip>


int main() {
	Person person;
	FillShoppingInfo(&person);
	WriteReceipt(person);
	
	system("pause");
	return 0;
}