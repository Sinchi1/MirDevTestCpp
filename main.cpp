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