//PreMadeItem.cpp
#include "IceCreamItem.h"
#include "IceCreamOrder.h"
#include "PreMadeItem.h"
#include <sstream>
#include <iomanip>

using namespace std;

PreMadeItem::PreMadeItem(std::string name, std::string size) : IceCreamItem(size){
	this->name = name;
}

PreMadeItem::~PreMadeItem(){

}

std::string PreMadeItem::composeItem(){
	std::string result;
	result = "Pre-made Size: " + this->size + "\n" + "Pre-made Item: " + this->name + "\n";
	stringstream stream;
	stream << fixed << setprecision(2) << this->getPrice();
	result += "Price: $" + stream.str() +"\n";
	return result;
}

double PreMadeItem::getPrice(){
	if(this->size == "large"){
		this->price = 7.5;
	}
	else if(this->size == "medium"){
		this->price = 6.0;
	}else{
		this->price = 4.0;
	}
	return this->price;
}
