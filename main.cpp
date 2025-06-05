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

        int64_t get_numartor() const {
            return numerator;
        }

        int64_t get_denomenator() const {
            return denomenator;
        }
};




int main(){
    cout << "Hello, C++!" << endl;
    return 0;
}