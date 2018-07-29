#include "stdafx.h"
#include "ListOfCars.h"


ListOfCars::ListOfCars()
{
	Car BMW(40, 10,"BMW");
	BMW.set_PriceOfCar(100);
	listOfCars[0] = BMW;
	Car Ferarri(40,20,"Ferarri");
	Ferarri.set_PriceOfCar(150);
	listOfCars[1] = Ferarri;
	Car Lada(12, 0,"Lada");
	Lada.set_PriceOfCar(20);
	listOfCars[2] = Lada;
	Car Passat(250, 70,"Passat");
	Passat.set_PriceOfCar(450);
	listOfCars[3] = Passat;
	Car Golf(160, 50,"Golf");
	Golf.set_PriceOfCar(300);
	listOfCars[4] = BMW;
	Car Jigula(0, 300,"Jigula");
	Jigula.set_PriceOfCar(120);
	listOfCars[5] = Jigula;
	Car Ford(15, 40,"Ford");
	Ford.set_PriceOfCar(160);
	listOfCars[6] = Ford;
	Car Audi(50, 5,"Audi");
	Audi.set_PriceOfCar(230);
	listOfCars[7] = Audi;
	Car Lambo(320, 70,"Lambo");
	Lambo.set_PriceOfCar(700);
	listOfCars[8] = Lambo;
}

