#include <iostream>

using namespace std;

#define ARRAY_LENGTH 3

class Fraction {
    protected:
        // Calculates the greates common divisor with 
        // Euclid's algorithm
        // both arguments have to be positive
        int gcd(int a, int b) {
            while (a != b) {
                if (a > b) {
                    a -= b;
                } else {
                    b -= a;
                }
            }
            return a;
        }

    public:
        int numerator, denominator;

        Fraction() {
            numerator = 0;
            denominator = 1;
        }

        Fraction(int n, int d) {
            if (d==0) {
                cerr << "Denominator may not be 0." << endl;
                exit(0);
            } else if (n == 0) {
                numerator = 0;
                denominator = 1;
            } else {
                int sign = 1;
                if (n < 0) {
                    sign *= -1;
                    n *= -1;
                }
                if (d < 0) {
                    sign *= -1;
                    d *= -1;
                }

                int tmp = gcd(n, d);
                numerator = n/tmp*sign;
                denominator = d/tmp;
            }
        }

        operator int() {return (numerator)/denominator;}
        operator float() {return ((float)numerator)/denominator;}
        operator double() {return ((double)numerator)/denominator;}
};

Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.denominator
                +rhs.numerator*lhs.denominator,
                lhs.denominator*rhs.denominator);
    return tmp;
}

Fraction operator+=(Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.denominator
                +rhs.numerator*lhs.denominator,
                lhs.denominator*rhs.denominator);
    lhs = tmp;
    return lhs;
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.denominator
                -rhs.numerator*lhs.denominator,
                lhs.denominator*rhs.denominator);
    return tmp;
}

Fraction operator-=(Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.denominator
                -rhs.numerator*lhs.denominator,
                lhs.denominator*rhs.denominator);
    lhs = tmp;
    return lhs;
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.numerator,
               lhs.denominator*rhs.denominator);
    return tmp;
}

Fraction operator*=(Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.numerator,
               lhs.denominator*rhs.denominator);
    lhs = tmp;
    return lhs;
}

Fraction operator*(int lhs, const Fraction& rhs) {
    Fraction tmp(lhs*rhs.numerator,rhs.denominator);
    return tmp;
}

Fraction operator*(const Fraction& rhs, int lhs) {
    Fraction tmp(lhs*rhs.numerator,rhs.denominator);
    return tmp;
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
    Fraction tmp(lhs.numerator*rhs.denominator,
                 lhs.denominator*rhs.numerator);
    return tmp;
}

std::ostream& operator<<(std::ostream &strm, const Fraction &a) {
    if (a.denominator == 1) {
        strm << a.numerator;
    } else {
        strm << a.numerator << "/" << a.denominator;
    }
    return strm;
}

//5/3 == 1 using integer division. To get the remainder, 5 - 1*3 = 2.
class MixedFraction: public Fraction
{

public:
    void initValues(int n, int d) {
        if (d==0) {
            cerr << "Denominator may not be 0." << endl;
            exit(0);
        } else if (n == 0) {
            numerator = 0;
            denominator = 1;
        } else {
            int sign = 1;
            if (n < 0) {
                sign *= -1;
                n *= -1;
            }
            if (d < 0) {
                sign *= -1;
                d *= -1;
            }

            int tmp = gcd(n, d);

            numerator = n/tmp*sign;
            denominator = d/tmp;
            wholePart = numerator/denominator;
            numerator = numerator - wholePart*denominator;
            if (numerator < 0 && wholePart != 0)
            {
                numerator *= -1;
            }
        }
    }

public:
    int n, d, wholePart;

    MixedFraction()
    {
        numerator = 0;
        denominator = 1;
    }

    MixedFraction(int n, int d) {
        initValues(n, d);
    }
};

// bool MixedFraction operator<(const MixedFraction& lhs, const MixedFraction& rhs)
// {
//     if (lhs.wholePart < rhs.wholePart)
//     {
//         return true;
//     } else if (lhs.wholePart == rhs.wholePart) {
//         int num1 = lhs.numerator * rhs.denominator;
//         int num2 = rhs.numerator * lhs.denominator;
//         return num1 < num2;
//     } else {
//         return false;
//     }
// }

bool operator>(const MixedFraction& lhs, const MixedFraction& rhs)
{
    if (lhs.wholePart > rhs.wholePart)
    {
        return true;
    } else if (lhs.wholePart == rhs.wholePart) {
        int num1 = lhs.numerator * rhs.denominator;
        int num2 = rhs.numerator * lhs.denominator;
        return num1 > num2;
    } else {
        return false;
    }
}

std::ostream& operator<<(std::ostream &strm, const MixedFraction &a) {
    if (a.wholePart != 0)
    {
        if (a.numerator == 0)
        {
            strm << a.wholePart;
        } else {
            strm << a.wholePart << " (" << a.numerator << "/" << a.denominator << ")";
        }
    } else if (a.denominator == 1) {
        strm << a.numerator;
    } else {
        strm << a.numerator << "/" << a.denominator;
    }
    return strm;
}

std::istream& operator>>(std::istream &strm, MixedFraction &a)
{
    int n, d;
    strm >> n >> d;
    a.initValues(n, d);
    return strm;
}

void max(MixedFraction *fractions)
{
    MixedFraction maxVal = fractions[0];

    for (int i = 1; i < ARRAY_LENGTH; i++)
    {
        if(fractions[i] > maxVal)
        {
            maxVal = fractions[i];
        }
    }

    cout << "Max fraction is: " << maxVal << endl;
}

int main() {
    MixedFraction fractions[ARRAY_LENGTH];

    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        std::cout << " Enter fraction " << i << ": " << std::endl;
        MixedFraction a;
        cin >> a;
        cout << a << endl;
        fractions[i] = a;
    }

    max(fractions);

    return 0;
}
