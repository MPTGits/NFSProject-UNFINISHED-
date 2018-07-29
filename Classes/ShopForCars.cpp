#include "stdafx.h"
#include "ShopForCars.h"
#include <iostream>


void ShopForCars::printShopCars() const
{
	for (int i = 0; i < 9; ++i) {
		std::cout << "Car at slot(" << i << ")" << std::endl;
		listOfCars[i].print();
		std::cout << std::endl;
	}
}


ShopForCars::ShopForCars()
{
}


