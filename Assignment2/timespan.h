//
// Created by Yusuf Pisan on 4/2/18.
//
// Adjusted by Braden Wolf on 4/22/21
//
// Header file for TimeSpan class

#ifndef ASS2_TIMESPAN_H
#define ASS2_TIMESPAN_H

#include <iostream>


using namespace std;

// TimeSpan class which represents a duration in hours,
// minutes, and seconds
class TimeSpan {
  // insert, generate format: 0:00:00
  friend ostream &operator<<(ostream &out, const TimeSpan &ts);

public:
  // explicit constructor
  explicit TimeSpan(double hour = 0, double minute = 0, double second = 0);

  // copy constructor
  TimeSpan(const TimeSpan &copy) = default;

  // copy assignment operator
  TimeSpan &operator=(const TimeSpan &copy) = default;

  // move constructor
  TimeSpan(TimeSpan &&move) noexcept;

  // move assignment operator
  TimeSpan &operator=(TimeSpan &&move) noexcept;

  // add
  TimeSpan &operator+(const TimeSpan &ts);

  // subtract
  TimeSpan &operator-(const TimeSpan &ts);

  // add given TimeSpan to this TimeSpan
  TimeSpan &operator+=(const TimeSpan &ts);

  // subtract given TimeSpan from this TimeSpan
  TimeSpan &operator-=(const TimeSpan &ts);

  // multiply timespan by an unsigned number
  TimeSpan &operator*(unsigned int number);

  // check equality
  bool operator==(const TimeSpan &ts) const;

  // check if not equal
  bool operator!=(const TimeSpan &ts) const;

  // less than
  bool operator<(const TimeSpan &ts) const;

  // greater than
  bool operator>(const TimeSpan &ts) const;

  // less than or equal to
  bool operator<=(const TimeSpan &ts);

  // greater than or equal to
  bool operator>=(const TimeSpan &ts);

  // hour component of timespan
  double getHour() const;

  // minute component of timespan
  double getMinute() const;

  // second component of timespan
  double getSecond() const;

  // true if timespan is 0 or larger
  bool isPositive() const;

  // destructor
  ~TimeSpan();

private:

  // Simplify
  void simplify();

  // converts total seconds to hours, mnutes, and seconds
  void convertTotalSeconds();

  // flips sign of each time category
  void flipSign();

  double hour = 0;
  double minute = 0;
  double second = 0;
  int totalSeconds = 0;
  bool isNegative = false;
  TimeSpan *tsSum = nullptr;
  TimeSpan *tsSub = nullptr;
  TimeSpan *tsProduct = nullptr;
  bool less = false;
  bool greater = false;

};

#endif // ASS2_TIMESPAN_H
