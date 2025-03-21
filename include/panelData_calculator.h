#ifndef PANELDATA_CALCULATOR_H
#define PANELDATA_CALCULATOR_H

#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

// define basic data unit
struct PD_unitStruct {
  int count = 0;
  int timeS = 0;
  int left, right;
  bool in_use = false;
};

// define group data unit
struct PD_group_unitStruct {
  int left, right;
};

class PD_Calculator {
 public:
  // Check data legitimacy
  bool PD_legitimacyCheck(double a, double b);

  // Calculator model function
  PD_group_unitStruct _find_group(int aL, int aR, int bL, int bR);
  PD_group_unitStruct find_group(PD_unitStruct a, PD_unitStruct b);
  PD_group_unitStruct find_group(PD_group_unitStruct a, PD_group_unitStruct b);

  // Calculator main function
  double panelData_calculate(std::vector<double> _numbers);
};

#endif