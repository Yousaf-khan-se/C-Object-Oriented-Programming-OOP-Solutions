// Muhammad Yousaf_I228797_SE-F
#include <iostream>

using namespace std;

class Pizza
{
private:
	char *name;
	char *topping;
	char *size;
	bool is_ready;
	double price;

public:
	//_________________________________________________________________constructors
	Pizza()
	{
		name = "";
		topping = "";
		size = "";
		is_ready = 0;
		price = 0.0;
	}
/*	~Pizza()
	{
		delete name;
		name = nullptr;
		delete topping;
		topping = nullptr;
		delete size;
		size = nullptr;
	}*/
	Pizza(char *toppingVal, double priceVal)
	{
		topping = toppingVal;
		topping = toppingVal;
		price = priceVal;
		name = "";
		size = "";
		is_ready = 0;
	}
	Pizza(char *toppingVal, double priceVal, char *nameVal, char *sizeVal, bool ready_status)
	{
		topping = toppingVal;
		price = priceVal;
		name = nameVal;
		size = sizeVal;
		is_ready = ready_status;
	}
	Pizza(const Pizza &pizza)
	{
		this->topping = pizza.topping;
		this->price = pizza.price;
		this->name = pizza.name;
		this->size = pizza.size;
		this->is_ready = pizza.is_ready;
	}
	//_______________________________________________________________________getter & setter functions
	void setTopping(char *toppingVal) // – setter for topping
	{
		topping = toppingVal;
	}
	void setPrice(double priceVal) // – setter for price
	{
		price = priceVal;
	}
	void setName(char *nameVal) // – setter for name
	{
		name = nameVal;
	}
	void setSize(char *sizeVal) // –setter for size
	{
		size = sizeVal;
	}
	char *getTopping() // – getter for topping
	{
		return topping;
	}
	double getPrice() //- getter for price
	{
		return price;
	}
	char *getName() // – getter for name
	{
		return name;
	}
	char *getSize() // – getter for size
	{
		return size;
	}
	//__________________________________________________other function
	void makePizza() // – function to make pizza (check if topping is not NULL then set value of is_ready to true)
	{
		if (topping != NULL)
			is_ready = true;
	}
	bool check_status() // function to check if pizza is ready or not
	{
		return is_ready;
	}
};

int main()
{
	
}
