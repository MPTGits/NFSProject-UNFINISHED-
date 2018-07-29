#ifndef HUMANRACER_H
#define HUMANRACER_H
#include "Car.h"
#include"ListOfCars.h"
#include "ShopForCars.h"
#include "AllTypeRacer.h"

class HumanRacer:public AllTypeRacer,public ShopForCars
{
private:
	int currentCars;
	int carSlotSize;
	int money;
	void copy(const HumanRacer& other);
public:
	void customerToBuy();
	HumanRacer(const char* name="unknown");
	HumanRacer(const HumanRacer& other);
	HumanRacer& operator=(const HumanRacer& other);
	virtual bool isHuman() const;
	virtual int get_Money() const;
	virtual void set_Money(int money);
	 virtual void addANewCar(const Car& newCar);
	//Input int i =>and index that we want the car to be moved to the last index and 
	//all of its parameters made as 0
	virtual void removingACar(int i);
	virtual void printCars() const;
	virtual void nullCar(Car& nullThisCar);
	virtual void print() const;
	virtual void pickACar();
	
	virtual ~HumanRacer();
};

#endif