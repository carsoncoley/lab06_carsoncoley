//CustomItem.h
#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H
#include "IceCreamItem.h"
#include <map>
class CustomItem : public IceCreamItem{
	public:
		CustomItem(std::string size);
		virtual ~CustomItem();
		void addTopping(std::string topping);
		virtual std::string composeItem();
		virtual double getPrice();

	protected:
		std::map<std::string, int> Toppings;
		
};
#endif
