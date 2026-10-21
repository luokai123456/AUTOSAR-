/*****************************************************************************
******************************************************************************
*
*               C Runtime Library for Simulink Desktop Real-Time
*
*               Copyright 1994-2021 The MathWorks, Inc.
*
******************************************************************************
*****************************************************************************/

#ifndef MATH_H__
#define MATH_H__

#include <_sldrtcrt.h>


#define CRTLIBMATHFAMILY(fn) \
  CRTKERNELEXTERNC double fn (double x);  \
  CRTKERNELEXTERNC float fn##f (float x); \
  CRTKERNELEXTERNC long double fn##l (long double x);

#define CRTLIBMATHFAMILY2(fn) \
  CRTKERNELEXTERNC double fn (double x, double y); \
  CRTKERNELEXTERNC float fn##f (float x, float y); \
  CRTKERNELEXTERNC long double fn##l (long double x, long double y);

#define CRTKERNELMATHFAMILY(fn) \
  CRTKERNELIMPORT( double fn (double x) );  \
  CRTKERNELIMPORT( float fn##f (float x) ); \
  CRTKERNELIMPORT( long double fn##l (long double x) );

#define CRTKERNELMATHFAMILY2(fn) \
  CRTKERNELIMPORT( double fn (double x, double y) ); \
  CRTKERNELIMPORT( float fn##f (float x, float y) ); \
  CRTKERNELIMPORT( long double fn##l (long double x, long double y) );

#define CRTINLINEMATHFAMILY(fn, impl) \
  inline fn(float x) { return(impl); } \
  inline fn(double x) { return(impl); } \
  inline fn(long double x) { return(impl); }

#define CRTINLINEMATHFAMILY2(fn, impl) \
  inline fn(float x, float y) { return(impl); } \
  inline fn(double x, double y) { return(impl); } \
  inline fn(long double x, long double y) { return(impl); }

#define CRTUNSUPPORTEDMATHFAMILY(fn) \
  fn(float x); \
  fn(double x); \
  fn(long double x);


/* Paragraph numbers are taken from the C standard ISO/IEC 9899:2011 draft
   available at http://www.open-std.org/jtc1/sc22/WG14/www/docs/n1570.pdf */


typedef float float_t;
typedef double double_t;

#define _INFINITY (1e300 * 1e300)
#define INFINITY ((float) _INFINITY)


/* 7.12.3 Classification macros */

#ifndef __cplusplus

#define isinf(x) ((x) == _INFINITY || (x) == -_INFINITY)
#define isnan(x) ((x) != (x))
#define isfinite(x) (!isnan(x) && !isinf(x))

#else

CRTUNSUPPORTEDMATHFAMILY(int fpclassify)
CRTINLINEMATHFAMILY(int isinf, x == _INFINITY || x == -_INFINITY)
CRTINLINEMATHFAMILY(int isnan, x != x)
CRTINLINEMATHFAMILY(int isfinite, !isnan(x) && !isinf(x))
CRTUNSUPPORTEDMATHFAMILY(int isnormal)
CRTUNSUPPORTEDMATHFAMILY(int signbit)

#endif

/* 7.12.4 Trigonometric functions */

CRTKERNELMATHFAMILY(acos)
CRTKERNELMATHFAMILY(asin)
CRTKERNELMATHFAMILY(atan)
CRTKERNELMATHFAMILY2(atan2)
CRTKERNELMATHFAMILY(cos)
CRTKERNELMATHFAMILY(sin)
CRTKERNELMATHFAMILY(tan)

/* 7.12.5 Hyperbolic functions */

CRTLIBMATHFAMILY(acosh)
CRTLIBMATHFAMILY(asinh)
CRTLIBMATHFAMILY(atanh)
CRTKERNELMATHFAMILY(cosh)
CRTKERNELMATHFAMILY(sinh)

CRTKERNELIMPORT( double tanh (double x) );
inline float tanhf(float x) { return((float) tanh(x)); }
inline long double tanhl(long double x) { return(tanh((double) x)); }

/* 7.12.6 Exponential and logarithmic functions */

CRTKERNELMATHFAMILY(exp)
CRTKERNELMATHFAMILY(exp2)

CRTKERNELUNSUPPORTED( double expm1(double x) );
CRTKERNELUNSUPPORTED( float expm1f(float x) );
CRTKERNELUNSUPPORTED( long double expm1l(long double x) );

CRTKERNELIMPORT( double frexp(double value, int *exp) );
inline float frexpf(float value, int *exp) { return((float) frexp(value, exp)); }
inline long double frexpl(long double value, int *exp) { return(frexp((double) value, exp)); }

CRTKERNELUNSUPPORTED( int ilogb(double x) );
CRTKERNELUNSUPPORTED( int ilogbf(float x) );
CRTKERNELUNSUPPORTED( int ilogbl(long double x) );

CRTKERNELIMPORT( double ldexp(double x, int exp) );
inline float ldexpf(float x, int exp) { return((float) ldexp(x, exp)); }
inline long double ldexpl(long double x, int exp) { return(ldexp((double) x, exp)); }

CRTKERNELMATHFAMILY(log)
CRTKERNELMATHFAMILY(log10)

CRTKERNELUNSUPPORTED( double log1p(double x) );
CRTKERNELUNSUPPORTED( float log1pf(float x) );
CRTKERNELUNSUPPORTED( long double log1pl(long double x) );

CRTKERNELUNSUPPORTED( double log2(double x) );
CRTKERNELUNSUPPORTED( float log2f(float x) );
CRTKERNELUNSUPPORTED( long double log2l(long double x) );

CRTKERNELUNSUPPORTED( double logb(double x) );
CRTKERNELUNSUPPORTED( float logbf(float x) );
CRTKERNELUNSUPPORTED( long double logbl(long double x) );

CRTKERNELIMPORT( double modf(double value, double *iptr) );
CRTKERNELIMPORT( float modff(float value, float *iptr) );
CRTKERNELEXTERNC long double modfl(long double value, long double *iptr);

CRTKERNELUNSUPPORTED( double scalbn(double x, int n) );
CRTKERNELUNSUPPORTED( float scalbnf(float x, int n) );
CRTKERNELUNSUPPORTED( long double scalbnl(long double x, int n) );
CRTKERNELUNSUPPORTED( double scalbln(double x, long int n) );
CRTKERNELUNSUPPORTED( float scalblnf(float x, long int n) );
CRTKERNELUNSUPPORTED( long double scalblnl(long double x, long int n) );

/* 7.12.7 Power and absolute-value functions */

CRTKERNELUNSUPPORTED( double cbrt(double x) );
CRTKERNELUNSUPPORTED( float cbrtf(float x) );
CRTKERNELUNSUPPORTED( long double cbrtl(long double x) );

CRTLIBMATHFAMILY(fabs)

CRTKERNELIMPORT( double hypot (double x, double y) ); \
inline float hypotf(float x, float y) { return((float) hypot(x, y)); }
inline long double hypotl(long double x, long double y) { return(hypot((double) x, (double) y)); }

CRTKERNELMATHFAMILY2(pow)
CRTKERNELMATHFAMILY(sqrt)

/* 7.12.8 Error and gamma functions */

CRTKERNELUNSUPPORTED( double erf(double x) );
CRTKERNELUNSUPPORTED( float erff(float x) );
CRTKERNELUNSUPPORTED( long double erfl(long double x) );

CRTKERNELUNSUPPORTED( double erfc(double x) );
CRTKERNELUNSUPPORTED( float erfcf(float x) );
CRTKERNELUNSUPPORTED( long double erfcl(long double x) );

CRTKERNELUNSUPPORTED( double lgamma(double x) );
CRTKERNELUNSUPPORTED( float lgammaf(float x) );
CRTKERNELUNSUPPORTED( long double lgammal(long double x) );

CRTKERNELUNSUPPORTED( double tgamma(double x) );
CRTKERNELUNSUPPORTED( float tgammaf(float x) );
CRTKERNELUNSUPPORTED( long double tgammal(long double x) );

/* 7.12.9 Nearest integer functions */

CRTLIBMATHFAMILY(ceil)
CRTLIBMATHFAMILY(floor)

CRTKERNELUNSUPPORTED( double nearbyint(double x) );
CRTKERNELUNSUPPORTED( float nearbyintf(float x) );
CRTKERNELUNSUPPORTED( long double nearbyintl(long double x) );

CRTKERNELUNSUPPORTED( double rint(double x) );
CRTKERNELUNSUPPORTED( float rintf(float x) );
CRTKERNELUNSUPPORTED( long double rintl(long double x) );

CRTKERNELUNSUPPORTED( long int lrint(double x) );
CRTKERNELUNSUPPORTED( long int lrintf(float x) );
CRTKERNELUNSUPPORTED( long int lrintl(long double x) );
CRTKERNELUNSUPPORTED( long long int llrint(double x) );
CRTKERNELUNSUPPORTED( long long int llrintf(float x) );
CRTKERNELUNSUPPORTED( long long int llrintl(long double x) );

CRTLIBMATHFAMILY(round)

CRTKERNELUNSUPPORTED( long int lround(double x) );
CRTKERNELUNSUPPORTED( long int lroundf(float x) );
CRTKERNELUNSUPPORTED( long int lroundl(long double x) );
CRTKERNELUNSUPPORTED( long long int llround(double x) );
CRTKERNELUNSUPPORTED( long long int llroundf(float x) );
CRTKERNELUNSUPPORTED( long long int llroundl(long double x) );

CRTLIBMATHFAMILY(trunc)

/* 7.12.10 Remainder functions */

CRTKERNELMATHFAMILY2(fmod)

CRTKERNELUNSUPPORTED( double remainder(double x, double y) );
CRTKERNELUNSUPPORTED( float remainderf(float x, float y) );
CRTKERNELUNSUPPORTED( long double remainderl(long double x, long double y) );

CRTKERNELUNSUPPORTED( double remquo(double x, double y, int *quo) );
CRTKERNELUNSUPPORTED( float remquof(float x, float y, int *quo) );
CRTKERNELUNSUPPORTED( long double remquol(long double x, long double y, int *quo) );

/* 7.12.11 Manipulation functions */

CRTKERNELUNSUPPORTED( double copysign(double x, double y) );
CRTKERNELUNSUPPORTED( float copysignf(float x, float y) );
CRTKERNELUNSUPPORTED( long double copysignl(long double x, long double y) );

CRTKERNELEXTERNC double nan(const char* tagp);
CRTKERNELEXTERNC float nanf(const char* tagp);
CRTKERNELEXTERNC long double nanl(const char* tagp);

CRTKERNELUNSUPPORTED( double nextafter(double x, double y) );
CRTKERNELUNSUPPORTED( float nextafterf(float x, float y) );
CRTKERNELUNSUPPORTED( long double nextafterl(long double x, long double y) );

CRTKERNELUNSUPPORTED( double nexttoward(double x, long double y) );
CRTKERNELUNSUPPORTED( float nexttowardf(float x, long double y) );
CRTKERNELUNSUPPORTED( long double nexttowardl(long double x, long double y) );

/* 7.12.12 Maximum, minimum, and positive difference functions */

CRTKERNELUNSUPPORTED( double fdim(double x, double y) );
CRTKERNELUNSUPPORTED( float fdimf(float x, float y) );
CRTKERNELUNSUPPORTED( long double fdiml(long double x, long double y) );

CRTLIBMATHFAMILY2(fmax);
CRTLIBMATHFAMILY2(fmin);

/* 7.12.13 Floating multiply-add */

CRTKERNELUNSUPPORTED( double fma(double x, double y, double z) );
CRTKERNELUNSUPPORTED( float fmaf(float x, float y, float z) );
CRTKERNELUNSUPPORTED( long double fmal(long double x, long double y, long double z) );

/* 7.12.14 Comparison macros */

#ifndef __cplusplus

#define isgreater(x, y) ((x) > (y))
#define isgreaterequal(x, y) ((x) >= (y))
#define isless(x, y) ((x) < (y))
#define islessequal(x, y) ((x) <= (y))
#define islessgreater(x, y) ((x) < (y) || (x) > (y))
#define isunordered(x, y) (isnan(x) || isnan(y))

#else

CRTINLINEMATHFAMILY2(int isgreater, x > y)
CRTINLINEMATHFAMILY2(int isgreaterequal, x >= y)
CRTINLINEMATHFAMILY2(int isless, x < y)
CRTINLINEMATHFAMILY2(int islessequal, x <= y)
CRTINLINEMATHFAMILY2(int islessgreater, x < y || x > y)
CRTINLINEMATHFAMILY2(int isunordered, isnan(x) || isnan(y))

#endif

//EVPT ADD
#define M_E        2.71828182845904523536   // e
#define M_LOG2E    1.44269504088896340736   // log2(e)
#define M_LOG10E   0.434294481903251827651  // log10(e)
#define M_LN2      0.693147180559945309417  // ln(2)
#define M_LN10     2.30258509299404568402   // ln(10)
#define M_PI       3.14159265358979323846   // pi
#define M_PI_2     1.57079632679489661923   // pi/2
#define M_PI_4     0.785398163397448309616  // pi/4
#define M_1_PI     0.318309886183790671538  // 1/pi
#define M_2_PI     0.636619772367581343076  // 2/pi
#define M_2_SQRTPI 1.12837916709551257390   // 2/sqrt(pi)
#define M_SQRT2    1.41421356237309504880   // sqrt(2)
#define M_SQRT1_2  0.707106781186547524401  // 1/sqrt(2)



#undef CRTKERNELMATHFAMILY2
#undef CRTKERNELMATHFAMILY

#endif /* MATH_H__ */
