/*
 * TimeCounter.cpp
 *
 *  Created on: 02.01.2017
 *      Author: mickpr
 */

#include "TimeCounter.h"

void TimeCounter::start() {
	startTime = clock();
}

void TimeCounter::stop() {
	stopTime = clock();
}

double TimeCounter::getTime() {
	return  (double)(stopTime - startTime)/CLOCKS_PER_SEC;

}

void TimeCounter::wait(double Miliseconds) {
	 clock_t koniec = clock() + Miliseconds * CLOCKS_PER_SEC / 1000.0;
	 while( clock() < koniec ) continue;
}
