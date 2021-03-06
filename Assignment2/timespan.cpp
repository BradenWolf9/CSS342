//
// Created by Yusuf Pisan on 4/2/18.
//
// Adjusted by Braden Wolf 4/22/21
//
// Implementation file for TimeSpan class

#include "timespan.h"



/*************************************************************************
                              Insert
**************************************************************************/

// insert, generate format: 0:00:00
ostream &operator<<(ostream &out, const TimeSpan &ts) {
  if(ts.isNegative) {
    out << "-";
  }
  out << ts.hour << ":";
  if(ts.minute < 10) {
    out << "0";
  }

  out << ts.minute << ":";
  if(ts.second < 10) {
    out << "0";
  }
  out << ts.second;
  return out;
}



/*************************************************************************
                              Constructor
**************************************************************************/

// explicit constructor
TimeSpan::TimeSpan(double hour, double minute, double second) :
  hour{hour},
  minute{minute},
  second{second} {
    this->totalSeconds = 0;
    this->isNegative = false;
    this->tsSum = nullptr;
    this->tsSub = nullptr;
    this->tsProduct = nullptr;
    this->less = false;
    this->greater = false;
    this->simplify();
  }



/*************************************************************************
                              Math Operations
**************************************************************************/

// add
TimeSpan &TimeSpan::operator+(const TimeSpan &ts) {
  delete this->tsSum;
  this->tsSum = new TimeSpan;

  if(this->isNegative) {
    flipSign();
  }
  if(ts.isNegative) {
    flipSign();
  }

  tsSum->second = this->second + ts.second;
  tsSum->minute = this->minute + ts.minute;
  tsSum->hour = this->hour + ts.hour;

  tsSum->simplify();

  return *tsSum;
}

// subtract
TimeSpan &TimeSpan::operator-(const TimeSpan &ts) {
  delete this->tsSub;
  this->tsSub = new TimeSpan;

  if(this->isNegative) {
    flipSign();
  }
  if(ts.isNegative) {
    flipSign();
  }

  tsSub->second = this->second - ts.second;
  tsSub->minute = this->minute - ts.minute;
  tsSub->hour = this->hour - ts.hour;

  tsSub->simplify();

  return *tsSub;
}

// add given TimeSpan to this TimeSpan
TimeSpan &TimeSpan::operator+=(const TimeSpan &ts) {
  if(this->isNegative) {
    flipSign();
  }
  if(ts.isNegative) {
    flipSign();
  }

  this->totalSeconds += ts.totalSeconds;
  convertTotalSeconds();
  this->simplify();

  return *this;
}

// subtract given TimeSpan from this TimeSpan
TimeSpan &TimeSpan::operator-=(const TimeSpan &ts) {
  if(this->isNegative) {
    flipSign();
  }
  if(ts.isNegative) {
    flipSign();
  }

  this->totalSeconds -= ts.totalSeconds;
  convertTotalSeconds();
  this->simplify();

  return *this;
}

// multiply with an integer
TimeSpan &TimeSpan::operator*(unsigned int number) {
  delete this->tsProduct;
  this->tsProduct = new TimeSpan;

  tsProduct->second = this->second * number;
  tsProduct->minute = this->minute * number;
  tsProduct->hour = this->hour * number;

  tsProduct->simplify();

  return *tsProduct;
}



/*************************************************************************
                              Comparisons
**************************************************************************/

// equality ==
bool TimeSpan::operator==(const TimeSpan &ts) const {
  return (this->hour   == ts.hour   &&
          this->minute == ts.minute &&
          this->second == ts.second);
}

// inequality !=
bool TimeSpan::operator!=(const TimeSpan &ts) const {
  return (!operator==(ts));
}

// less than
bool TimeSpan::operator<(const TimeSpan &ts) const {
  return (this->totalSeconds < ts.totalSeconds);
}

// greater than
bool TimeSpan::operator>(const TimeSpan &ts) const {
  return (this->totalSeconds > ts.totalSeconds);
}

// less than or equal to
bool TimeSpan::operator<=(const TimeSpan &ts) {
  return *this < ts || *this == ts;
}

// greater than or equal to
bool TimeSpan::operator>=(const TimeSpan &ts) {
  return *this > ts || *this == ts;
}



/*************************************************************************
                              Accessors
**************************************************************************/

// hour component
double TimeSpan::getHour() const { return this->hour; }

// minute component
double TimeSpan::getMinute() const { return this->minute; }

// second component
double TimeSpan::getSecond() const { return this->second; }

// true if timespan is 0 or larger
bool TimeSpan::isPositive() const {
  return (this->totalSeconds >= 0);
}



/*************************************************************************
                              Destructor
**************************************************************************/

// destructor
TimeSpan::~TimeSpan() {
  delete this->tsSum;
  delete this->tsSub;
  delete this->tsProduct;
}



/*************************************************************************
                              Simplify
**************************************************************************/

// simplify
void TimeSpan::simplify() {
  this->totalSeconds = this->second + (this->minute * 60) + (this->hour * 60 * 60);

  convertTotalSeconds();

  if(!isPositive()) {
    this->isNegative = true;
    flipSign();
  }
  else {
    this->isNegative = false;
  }

  if(this->hour == 0) {
    this->hour = 0;
  }
  if(this->minute == 0) {
    this->minute = 0;
  }
  if(this->second == 0) {
    this->second = 0;
  }
}

// converts total seconds to hours, mnutes, and seconds
void TimeSpan::convertTotalSeconds() {
  int hours = this->totalSeconds / (60 * 60);
  int leftOverHourSeconds = this->totalSeconds % (60 * 60);
  int minutes = leftOverHourSeconds / 60;
  int seconds = leftOverHourSeconds % 60;

  this->hour = hours;
  this->minute = minutes;
  this->second = seconds;
}

// flips sign of each time category
void TimeSpan::flipSign() {
  this->hour = this->hour * -1;
  this->minute = this->minute * -1;
  this->second = this->second * -1;
}
