/*
 * TimeCounter.h
 *
 *  Created on: 02.01.2017
 *      Author: mickpr
 */

#ifndef TIMECOUNTER_H_
#define TIMECOUNTER_H_

//#include <cstdio>
#include <ctime>

class TimeCounter {
private:
	clock_t startTime, stopTime;
public:
	void start();
	void stop();
	double getTime();
	void wait(double Miliseconds);
};

#endif /* TIMECOUNTER_H_ */
