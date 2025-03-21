#define EXPORT_API extern "C" __declspec(dllexport)
#define GU_PC PD_group_unitStruct PD_Calculator

#include "../include/panelData_calculator.h"
using namespace std;

// Define extern function
EXPORT_API double panelData_calculate(double *numbers, size_t size) {
  std::vector<double> vec(numbers, numbers + size);
  PD_Calculator obj;
  return obj.panelData_calculate(vec);
}

bool PD_Calculator::PD_legitimacyCheck(double a, double b) {
  return (abs(a - b) / (a + b) * 2.0) > 0.1 ? false : true;
}

GU_PC::_find_group(int aL, int aR, int bL, int bR) {
  PD_group_unitStruct callback;
  if (aR < bL) {
    callback.left = -1, callback.right = -1;
  } else {
    callback.left = max(aL, bL);
    callback.right = min(aR, bR);
  }
  return callback;
}

GU_PC::find_group(PD_unitStruct a, PD_unitStruct b) {
  return _find_group(a.left, a.right, b.left, b.right);
}

GU_PC::find_group(PD_group_unitStruct a, PD_group_unitStruct b) {
  return _find_group(a.left, a.right, b.left, b.right);
}

double PD_Calculator::panelData_calculate(std::vector<double> _numbers) {
  map<double, PD_unitStruct> countMap;
  vector<double> numbers = _numbers;
  // prepare data
  for (int i = 0; i < numbers.size(); i++) {
    countMap[numbers[i]].count++;
    countMap[numbers[i]].timeS += i;
  }
  // sort keys
  int i = 0;
  for (auto &_countMap : countMap) {
    numbers[i] = _countMap.first;
    _countMap.second.timeS /= _countMap.second.count;
    i++;
  }
  // find parallel
  int num_size = countMap.size();
  for (i = 0; i < num_size; i++) {
    int left_p = i - 1, right_p = i + 1;
    while (left_p >= 0) {
      if (PD_legitimacyCheck(numbers[left_p], numbers[i])) {
        countMap[numbers[left_p]].in_use = true;
        left_p--;
      } else {
        countMap[numbers[i]].left = left_p + 1;
        break;
      }
    }
    while (right_p < num_size) {
      if (PD_legitimacyCheck(numbers[right_p], numbers[i])) {
        countMap[numbers[right_p]].in_use = true;
        right_p++;
      } else {
        countMap[numbers[i]].right = right_p - 1;
        break;
      }
    }
    if (left_p == -1) countMap[numbers[i]].left = 0;
    if (right_p == num_size) countMap[numbers[i]].right = num_size - 1;
  }
  // find group
  vector<PD_group_unitStruct> groups;
  for (i = 0; i < num_size - 1; i++) {
    PD_group_unitStruct temp =
        find_group(countMap.at(numbers[i]), countMap.at(numbers[i + 1]));
    if (temp.left != -1) {
      if (!groups.empty()) {
        if (groups.back().left != temp.left ||
            groups.back().right != temp.right) {
          groups.push_back(temp);
        }
      } else {
        groups.push_back(temp);
      }
    }
  }
  // special situation(return -1 or num)
  if (groups.size() == 0) {
    int real_disfind_check = 0;
    double num = 0.0;
    int count = 1, time = 0;
    for (auto pair : numbers) {
      if (countMap[pair].count > count) {
        num = pair;
        count = countMap[pair].count;
        time = countMap[pair].timeS;
        real_disfind_check = 1;
      } else if ((count != 1) && (num != pair) &&
                 (countMap[pair].count == count)) {
        if (countMap[pair].timeS > time) {
          num = pair;
          count = countMap[pair].count;
          time = countMap[pair].timeS;
          real_disfind_check = 1;
        } else if (countMap[pair].timeS == time) {
          real_disfind_check = 2;
        }
      }
    }
    if (real_disfind_check == 0) return -1;
    if (real_disfind_check == 1) return num;
    if (real_disfind_check == 2) return -2;
  }
  // deduplicate && deoverlap
  bool overlap_check = false;
  while (!overlap_check) {
    vector<PD_group_unitStruct> temp_groups;
    overlap_check = true;
    int num_size = groups.size();
    for (int j = 0; j < num_size - 1; j++) {
      PD_group_unitStruct temp = find_group(groups[j], groups[j + 1]);
      if (temp.left != -1) {
        overlap_check = false;
        temp_groups.push_back(temp);
      } else {
        temp_groups.push_back(groups[j + 1]);
      }
    }
    if (!overlap_check) {
      groups.assign(temp_groups.begin(), temp_groups.end());
    }
  }
  // calculate
  map<double, double> resMap;
  for (auto &pair : groups) {
    double sum = 0.0, timeS = 0.0;
    int counter = 0;
    for (i = pair.left; i <= pair.right; i++) {
      sum += numbers[i] * countMap[numbers[i]].count;
      timeS += countMap[numbers[i]].timeS;
      counter += countMap[numbers[i]].count;
    }
    sum /= counter;
    timeS /= counter;
    resMap[timeS] = sum;
  }
  // return
  return resMap.rbegin()->second;
}
