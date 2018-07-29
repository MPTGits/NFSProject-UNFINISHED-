#pragma once
class Car
{
private:
	double forceOfCar;
	int nitroCarBonus;
	int priceOfCar;
	char carType[100];
public:
	Car(double forceOfCar =0, int nitroCarBonus = 0,const char* carType="unknown");
	void print() const;
	int get_PriceOfCar()const;
	void set_PriceOfCar(int priceOfCar);
	double get_forceOfCar() const;
	int get_nitroCarBonus() const;
	void set_forceOfCar(double forceOfCar);
	void set_nitroCarBonus(int nitroCarBonus);
	void set_CarType(const char*);
};

