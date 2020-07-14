#include <complex>
using namespace std;

// -------------------------------------------------------

using FloatType = double;
using P = complex<FloatType>;

#define EPS (1e-10)
#define EQ(a, b) (abs((a) - (b)) < EPS)
#define EQV(a, b) (EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()))

FloatType dot(P a, P b) { return a.real() * b.real() + a.imag() * b.imag(); }

FloatType cross(P a, P b) { return a.real() * b.imag() - a.imag() * b.real(); }

// 2直線の直行判定
bool is_orthogonal(P a1, P a2, P b1, P b2) {
  return EQ(dot(a1 - a2, b1 - b2), 0.0);
}

// 2直線の平行判定
bool is_parallel(P a1, P a2, P b1, P b2) {
  return EQ(cross(a1 - a2, b1 - b2), 0.0);
}

// 点cが直線a-b上にあるか
bool is_point_on_line(P a, P b, P c) { return EQ(cross(b - a, c - a), 0.0); }

// 点cが線分a-b上にあるか
bool is_point_on_line_segment(P a, P b, P c) {
  return (abs(c - a) + abs(c - b) < abs(b - a) + EPS);
}

// 点a,bを通る直線と点cとの距離
FloatType distance_l_p(P a, P b, P c) {
  return abs(cross(b - a, c - a)) / abs(b - a);
}

// 点a,bを通る線分と点cとの距離
FloatType distance_ls_p(P a, P b, P c) {
  if (dot(b - a, c - a) < EPS) return abs(c - a);
  if (dot(a - b, c - b) < EPS) return abs(c - b);
  return distance_l_p(a, b, c);
}

// a1,a2を端点とする線分とb1,b2を端点とする線分の交差判定
FloatType is_intersected_ls(P a1, P a2, P b1, P b2) {
  return (cross(a2 - a1, b1 - a1) * cross(a2 - a1, b2 - a1) < EPS) &&
         (cross(b2 - b1, a1 - b1) * cross(b2 - b1, a2 - b1) < EPS);
}

// a1,a2を端点とする線分とb1,b2を端点とする線分の交点計算
P intersection_ls(P a1, P a2, P b1, P b2) {
  P b = b2 - b1;
  FloatType d1 = abs(cross(b, a1 - b1));
  FloatType d2 = abs(cross(b, a2 - b1));
  FloatType t = d1 / (d1 + d2);

  return a1 + (a2 - a1) * t;
}

// a1,a2を通る直線とb1,b2を通る直線の交差判定
bool is_intersected_l(P a1, P a2, P b1, P b2) {
  return !EQ(cross(a1 - a2, b1 - b2), 0.0);
}

// a1,a2を通る直線とb1,b2を通る直線の交点計算
P intersection_l(P a1, P a2, P b1, P b2) {
  P a = a2 - a1;
  P b = b2 - b1;
  return a1 + a * cross(b, b1 - a1) / cross(b, a);
}
