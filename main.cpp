#include <iostream>

using namespace std;

template<int m, int kg, int s, int A, int K, int mol, int cd>
class DimQ{
public:
    double value;

    DimQ(double _value){
        value = _value;
    }

    DimQ<m, kg, s, A, K, mol, cd> operator-() const{
        return DimQ<m, kg, s, A, K, mol, cd>(-value);
    }

    DimQ<m, kg, s, A, K, mol, cd> operator+(const DimQ<m, kg, s, A, K, mol, cd> &other) const{
        return DimQ<m, kg, s, A, K, mol, cd>(value + other.value);
    }

    DimQ<m, kg, s, A, K, mol, cd> operator-(const DimQ<m, kg, s, A, K, mol, cd> &other) const{
        return DimQ<m, kg, s, A, K, mol, cd>(value - other.value);
    }
};

template<int m, int kg, int s, int A, int K, int mol, int cd>
ostream &operator<<(ostream& out, const DimQ<m, kg, s, A, K, mol, cd> &output){

};

template<int m1, int kg1, int s1, int A1, int K1, int mol1, int cd1, int m2, int kg2, int s2, int A2, int K2, int mol2, int cd2>
DimQ<m1+m2, kg1+kg2, s1+s2, A1+A2, K1+K2, mol1+mol2, cd1+cd2> operator*(DimQ<m1, kg1, s1, A1, K1, mol1, cd1> &a, DimQ<m2, kg2, s2, A2, K2, mol2, cd2> &b){
    return DimQ<m1+m2, kg1+kg2, s1+s2, A1+A2, K1+K2, mol1+mol2, cd1+cd2>(a.value*b.value);
}

template<int m1, int kg1, int s1, int A1, int K1, int mol1, int cd1, int m2, int kg2, int s2, int A2, int K2, int mol2, int cd2>
DimQ<m1-m2, kg1-kg2, s1-s2, A1-A2, K1-K2, mol1-mol2, cd1-cd2> operator/(DimQ<m1, kg1, s1, A1, K1, mol1, cd1> &a, DimQ<m2, kg2, s2, A2, K2, mol2, cd2> &b){
    return DimQ<m1-m2, kg1-kg2, s1-s2, A1-A2, K1-K2, mol1-mol2, cd1-cd2>(a.value/b.value);
}

template

typedef DimQ<0,0,0,0,0,0,0> NoMeasure;

typedef DimQ<1,0,0,0,0,0,0> Length;
typedef DimQ<0,1,0,0,0,0,0> Mass;
typedef DimQ<0,0,1,0,0,0,0> Time;
typedef DimQ<0,0,0,1,0,0,0> ElectricCurrent;
typedef DimQ<0,0,0,0,1,0,0> Temperuture;
typedef DimQ<0,0,0,0,0,1,0> SubstanceAmount;
typedef DimQ<0,0,0,0,0,0,1> LightIntensity;

typedef DimQ<1,0,-1,0,0,0,0> Velocity;
typedef DimQ<1,0,-2,0,0,0,0> Acceleration;


int main() {
    Length len(1);
    Time time(2);
    Velocity vel = len/time;
    Acceleration acc = vel/time;
    cout << "Hello, World!" << endl;
    return 0;
}