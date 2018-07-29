#pragma once
#include "Car.h"
#include "AllTypeRacer.h"
#include <cstring>

class AIRacer:public AllTypeRacer 
{
private:
	void copy(const AIRacer& other);
	virtual void addANewCar(const Car& newCar);
	//Input int i =>and index that we want the car to be moved to the last index and 
	//all of its parameters made as 0
	virtual void removingACar(int i);
	virtual void printCars() const;
	virtual void nullCar(Car& nullThisCar);
	virtual void pickACar();
	virtual int get_Money() const;
	virtual void set_Money(int money);
	virtual void customerToBuy();
	
public:
	AIRacer();
	AIRacer(const AIRacer& ohter);
	AIRacer& operator=(const AIRacer& other);
	virtual void print() const;
	virtual bool isHuman() const;
	virtual ~AIRacer();
};

