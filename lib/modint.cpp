#include <iostream>
using namespace std;

template <long long ModInt_MOD>
class ModInt {
  using ValType = long long;

  ValType val;

 public:
  constexpr ModInt(ValType v = 0) noexcept : val(v % ModInt_MOD) {
    if (val < 0) val += ModInt_MOD;
  }

  constexpr ValType get_value() { return val; }
  constexpr long long get_mod() { return ModInt_MOD; }

  constexpr ModInt operator-() const noexcept {
    return val ? ModInt_MOD - val : 0;
  }
  constexpr ModInt operator+(const ModInt& rhs) const noexcept {
    return ModInt(*this) += rhs;
  }
  constexpr ModInt operator-(const ModInt& rhs) const noexcept {
    return ModInt(*this) -= rhs;
  }
  constexpr ModInt operator*(const ModInt& rhs) const noexcept {
    return ModInt(*this) *= rhs;
  }
  constexpr ModInt operator/(const ModInt& rhs) const noexcept {
    return ModInt(*this) /= rhs;
  }
  constexpr ModInt& operator+=(const ModInt& rhs) noexcept {
    val += rhs.val;
    if (val >= ModInt_MOD) val -= ModInt_MOD;
    return *this;
  }
  constexpr ModInt& operator-=(const ModInt& rhs) noexcept {
    val -= rhs.val;
    if (val < 0) val += ModInt_MOD;
    return *this;
  }
  constexpr ModInt& operator*=(const ModInt& rhs) noexcept {
    val = val * rhs.val % ModInt_MOD;
    return *this;
  }
  constexpr ModInt& operator/=(const ModInt& rhs) noexcept {
    ValType a = rhs.val, b = ModInt_MOD, u = 1, v = 0;
    while (b) {
      ValType t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    val = val * u % ModInt_MOD;
    if (val < 0) val += ModInt_MOD;
    return *this;
  }
  constexpr bool operator==(const ModInt& rhs) const noexcept {
    return this->val == rhs.val;
  }
  constexpr bool operator!=(const ModInt& rhs) const noexcept {
    return this->val != rhs.val;
  }
  friend constexpr ostream& operator<<(ostream& os,
                                       const ModInt<ModInt_MOD>& x) noexcept {
    return os << x.val;
  }
  friend constexpr ModInt<ModInt_MOD> modpow(const ModInt<ModInt_MOD>& a,
                                             long long n) noexcept {
    if (n == 0) return 1;
    auto t = modpow(a, n / 2);
    t = t * t;
    if (n & 1) t = t * a;
    return t;
  }
};
