#include "IceCreamOrder.h"
#include "IceCreamItem.h"
#include "CustomItem.h"
#include <sstream>
#include <iomanip>

using namespace std;

CustomItem::CustomItem(std::string size) : IceCreamItem(size){
	if(size == "small"){
		price = 3.0;
	}
	else if(size == "medium"){
		price = 5.0;
	}
	else if(size == "large"){
		price = 6.5;
	}
}

CustomItem::~CustomItem(){

}

void CustomItem::addTopping(std::string topping){
	std::map<string,int>::iterator it = Toppings.find(topping);
	if(it != Toppings.end()){
		Toppings[topping] += 1;
	}
	else{
		Toppings.insert(std::pair<string,int>(topping, 1));
	}
}

double CustomItem::getPrice(){
	double tPrice = 0.0;
	//double temp = 0.0;
	for(std::map<string,int>::iterator i = Toppings.begin(); i != Toppings.end(); i++){
		tPrice += (0.4) * static_cast<double>(i->second);
		//this->price += tPrice;
		//temp += 1;
	}
	return tPrice + this->price;

	//stringstream stream;
	//stream << fixed << setprecision(2) << price;
	//price = price - (temp * (0.2));
	//return price;
}

std::string CustomItem::composeItem(){
	std::string result;
	result = "Custom Size: " + this->size + "\nToppings:\n";
	for(std::map<string, int>::iterator i = Toppings.begin(); i != Toppings.end(); i++){
		result += i->first + ": " + to_string(i->second) + " oz\n";
	}
	stringstream stream;
	stream << fixed << setprecision(2) << this->getPrice();
	result += "Price: $" + stream.str() + "\n";
	return result;
}
