#pragma once
#include <cmath>
#include <math.h>

class Value {
public:
  double val;
  Value() {}
  Value(double val) : val(val) {}
  friend Value operator+(const Value self, const Value other) {
    return Value(self.val + other.val);
  }

  friend Value operator-(const Value self, const Value other) {
    return Value(self.val - other.val);
  }

  friend Value operator/(const Value self, const Value other) {
    return Value(self.val / other.val);
  }

  friend Value operator*(const Value self, const Value other) {
    return Value(self.val * other.val);
  }

  friend Value operator^(const Value self, const Value other) {
    return Value(std::pow(self.val, other.val));
  }
};
