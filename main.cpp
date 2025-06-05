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
        Cfraction(){numerator,denomenator = 0,1;}

        Cfraction(int64_t numerator, int64_t denomenator = 1){
            this->numerator = numerator;
            this->denomenator = denomenator;
            normalize();
        }

        Cfraction(const Cfraction& copy){
            numerator = copy.numerator;
            denomenator = copy.denomenator;
        }

        int64_t get_numartor() const {
            return numerator;
        }

        int64_t get_denomenator() const {
            return numerator;
        }
};




int main(){
    cout << "Hello, C++!" << endl;
    return 0;
}