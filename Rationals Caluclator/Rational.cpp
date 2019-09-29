#include <cstdlib>
#include "Rational.h"

// Get greatest common denominator through recursion
int gcd(int n, int d) {
  n = abs(n);
  d = abs(d);

  if (d == 0) {
  	return n;
  } else {
  	return gcd(d, n % d);
  }
}

namespace rational374 {

// Construct Rational 0
Rational::Rational() {
	numer_ = 0;
	denom_ = 1;
}

// Construct Rational n/1
Rational::Rational(int n) {
	numer_ = n;
	denom_ = 1;
}

// Construct Rational n/d
Rational::Rational(int n, int d) {
	if (d == 0) {
		return;
	} else if (n == 0) {
		numer_ = n;
		denom_ = 1;
	} else if (d < 0) {
		int x = gcd(n, d);
		numer_ = -n / x;
		denom_ = -d / x;
	} else {
		int x = gcd(n, d);
		numer_ = n / x;
		denom_ = d / x;
	}
}

// Access numer_ publicly
int Rational::n() const {
	return numer_;
}

// Access denom_ publicly
int Rational::d() const {
	return denom_;
}

// Add two rational numbers (make common denominator)
Rational Rational::plus(Rational other) const {
	return Rational((n() * other.d()) + (d() * other.n()),
                    d() * other.d());
}

// Subtract two rational numbers (add one to negative the other)
Rational Rational::minus(Rational other) const {
   Rational ans = plus(Rational(-other.n(), other.d()));
   return Rational(ans.n(), ans.d());
}

// Multiply two rational numbers (multiply numerators and denominators)
Rational Rational::times(Rational other) const {
	return Rational(n() * other.n(), d() * other.d());
}

// Subtract two rational numbers (multiple one vs the other flipped)
Rational Rational::div(Rational other) const {
   Rational ans = times(Rational(other.d(), other.n()));
   return Rational(ans.n(), ans.d());
}
}