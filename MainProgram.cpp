#include <iostream>
#include <string>
 
class Vehicle {
protected:
    std::string	_make;
	int			_year;
	double		_fuellevel;
 
public:
 
	Vehicle(std::string make, int year, double fuellevel)
		: _make(make), _year(year), _fuellevel(fuellevel) { }
 
	std::string getMake() const { return _make; }
 
	int getYear() const { return _year; }
 
	double getFuelLevel() const { return _fuellevel; }
 
	void refuel(double amount)
	{
		if (_fuellevel > 100.0 || amount < 0)
			return ;
		if (_fuellevel + amount >= 100)
			_fuellevel = 100;
		else
			_fuellevel += amount;
	}
 
	virtual	std::string describe() const
	{
		return "Car: " + _make + " (" + std::to_string(_year) + "), "
			+ "fuel: " + std::to_string(_fuellevel) + "%";
	}
 
	virtual	~Vehicle() = default;
};
 
class Car : public Vehicle {
private:
	int	_numDoors;
 
public:
 
	Car(std::string make, int year, double fuelLevel, int numDoors)
		: Vehicle(make, year, fuelLevel), _numDoors(numDoors) { }
 
	int getNumDoors() const { return _numDoors; }
 
	std::string describe() const override
	{
		return "Car: " + _make + " (" + std::to_string(_year) + "), "
			+ std::to_string(_numDoors) + " doors, fuel: "
			+ std::to_string(_fuellevel) + "%";
	}
};
 
class Truck : public Vehicle {
private:
    double _payloadTons;
 
public:
 
    Truck(std::string make, int year, double fuelLevel, double payloadTons)
        : Vehicle(make, year, fuelLevel), _payloadTons(payloadTons) { }
 
    double getPayloadTons() const { return _payloadTons; }
 
    std::string describe() const override
    {
        return "Truck: " + _make + " (" + std::to_string(_year) + "), "
            + std::to_string(_payloadTons) + " tons payload, fuel: "
            + std::to_string(_fuellevel) + "%";
    }
};
 
int main() {
    // --- Basic usage demo ---
    Car   c("Toyota", 2020, 75.5, 4);
    Truck t("Ford",   2018, 60.0, 5.5);
 
    std::cout << c.describe() << "\n";
    std::cout << t.describe() << "\n";
 
    // Polymorphism via base pointer
    Vehicle* v1 = &c;
    Vehicle* v2 = &t;
    std::cout << v1->describe() << "\n";
    std::cout << v2->describe() << "\n";
 
    // Refuel demo
    c.refuel(20.0);
    std::cout << "After refuel: " << c.getFuelLevel() << "%\n";
 
    return 0;
}
