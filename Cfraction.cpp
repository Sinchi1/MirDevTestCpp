#include <iostream>
using namespace std;

class Cfraction{
    private:
        int64_t numerator;
        int64_t denomenator;

        void normalize(){
            if (denomenator < 0){
                numerator = -numerator;
                denomenator = -denomenator;
            }
        }

    public:
        Cfraction(){numerator = 0; denomenator = 1;}

        Cfraction(int64_t numerator, int64_t denomenator = 1){
            this->numerator = numerator;
            this->denomenator = denomenator;
            normalize();
        }

        Cfraction& operator=(const Cfraction& second) {
        if (this != &second) {
            numerator = second.numerator;
            denomenator = second.denomenator;
        }
            return *this;
        }

        Cfraction(const Cfraction& copy){
            numerator = copy.numerator;
            denomenator = copy.denomenator;
        }

        Cfraction operator+(const Cfraction& second) const{
            return Cfraction{numerator * second.denomenator + second.numerator * denomenator,
            denomenator * second.denomenator };
        }
        
        Cfraction operator-(const Cfraction& second) const{
            return Cfraction{numerator * second.denomenator - second.numerator * denomenator,
            denomenator * second.denomenator };
        }

        Cfraction operator/(const Cfraction& second) const{
            return Cfraction{numerator * second.denomenator, denomenator * second.numerator};
        }

        Cfraction operator*(const Cfraction& second) const{
            return Cfraction{numerator * second.numerator, denomenator * second.denomenator};
        }

        Cfraction& operator+=(const Cfraction& second){
            *this = *this + second;
            return *this;
        }

        Cfraction& operator-=(const Cfraction& second){
            *this = *this - second;
            return *this;
        }

        Cfraction& operator/=(const Cfraction& second){
            *this = *this / second;
            return *this;
        }

        Cfraction& operator*=(const Cfraction& second){
            *this = *this * second;
            return *this;
        }

        Cfraction& operator++(){
            numerator += denomenator;
            return *this;
        }

        Cfraction operator++(int){
            Cfraction temp(*this);
            ++(*this);
            return temp;
        }

        Cfraction& operator--(){
            numerator -= denomenator;
            return *this;
        }

        Cfraction operator--(int){
            Cfraction temp(*this);
            --(*this);
            return temp;
        }

        operator double() const {
            return static_cast<double>(numerator) / denomenator;
        }

        Cfraction& operator()(int numerator, int denomenator){
            this->numerator = numerator;
            this->denomenator = denomenator;
            normalize();
            return *this;
        }

        Cfraction& operator()(int numerator){
            this->numerator = numerator;
            this->denomenator = 1;
            return *this;
        }

        bool operator==(const Cfraction& second) const {
            return this->numerator == second.numerator && this->denomenator == second.denomenator;
        }

        bool operator!=(const Cfraction& second) const {
            return !(*this == second);
        }

        bool operator<(const Cfraction& second) const {
            return static_cast<double>(*this) < static_cast<double>(second);
        }

        bool operator<=(const Cfraction& second) const {
            return !(*this > second);
        }

        bool operator>(const Cfraction& second) const {
            return static_cast<double>(*this) > static_cast<double>(second);
        }

        bool operator>=(const Cfraction& second) const {
            return !(*this < second);
        }

        int64_t get_numerator() const {
            return numerator;
        }

        int64_t get_denomenator() const {
            return denomenator;
        }
};

extern "C" {

    struct Fraction {
        int64_t num;
        int64_t den;
    };

    static Cfraction wrap(Fraction f) {
        return Cfraction(f.num, f.den);
    }

    Fraction frac_create(int64_t num, int64_t den) {
        Cfraction f(num, den);
        return { f.get_numerator(), f.get_denomenator() };
    }

    Fraction frac_add(Fraction a, Fraction b) {
        Cfraction fa = wrap(a);
        Cfraction fb = wrap(b);
        Cfraction result = fa + fb;
        return { result.get_numerator(), result.get_denomenator() };
    }

    Fraction frac_sub(Fraction a, Fraction b) {
        Cfraction fa = wrap(a);
        Cfraction fb = wrap(b);
        Cfraction result = fa - fb;
        return { result.get_numerator(), result.get_denomenator() };
    }

    Fraction frac_mul(Fraction a, Fraction b) {
        Cfraction fa = wrap(a);
        Cfraction fb = wrap(b);
        Cfraction result = fa * fb;
        return { result.get_numerator(), result.get_denomenator() };
    }

    Fraction frac_div(Fraction a, Fraction b) {
        Cfraction fa = wrap(a);
        Cfraction fb = wrap(b);
        Cfraction result = fa / fb;
        return { result.get_numerator(), result.get_denomenator() };
    }

    double to_double(Fraction a) {
        return static_cast<double>(wrap(a));
    }
}


