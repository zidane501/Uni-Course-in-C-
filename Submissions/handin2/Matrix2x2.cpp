#include "Matrix2x2.hpp"

Matrix2x2::Matrix2x2(){
    val00 = 0; val01 = 0;
    val10 = 0; val11 = 0;
};
Matrix2x2::Matrix2x2(const Matrix2x2& other){
    val00 = other.Getval00();
    val01 = other.Getval01();
    val10 = other.Getval10();
    val11 = other.Getval11();

};

Matrix2x2::Matrix2x2(double a, double b, double c, double d){
    val00 = a; val01 = b;
    val10 = c; val11 = d;
};

double Matrix2x2::CalcDeterminant() const{
    return val00*val11-val01*val10;
};

Matrix2x2  Matrix2x2::CalcInverse() const{
    Matrix2x2 inverse(val00, val01, val10, val11);
    
    double determinant = this->CalcDeterminant();
    
    if (determinant != 0){
        inverse.val00 =  val11/determinant;
        inverse.val01 = -val01/determinant;
        inverse.val10 = -val10/determinant;
        inverse.val11 =  val00/determinant;
        
        return inverse;    
    }else
    {
        std::cout << "Matrix not invertible" << std::endl;
        return inverse;
    }
};

Matrix2x2& Matrix2x2:: operator=(const Matrix2x2& z){
    
    val00 = z.val00;
    val01 = z.val01;
    val10 = z.val10;    
    val11 = z.val11;

    return * this;
};

Matrix2x2 Matrix2x2:: operator-() const{
    Matrix2x2 m;
    m.val00 = -val00;
    m.val01 = -val01;
    m.val10 = -val10;
    m.val11 = -val11;

    return m;

};
Matrix2x2 Matrix2x2:: operator+(const Matrix2x2& z) const{
    Matrix2x2 m;
    m.val00 = val00 + z.val00;
    m.val01 = val01 + z.val01;
    m.val10 = val10 + z.val10;
    m.val11 = val11 + z.val11;

    return m;

};
Matrix2x2 Matrix2x2:: operator-(const Matrix2x2& z) const{
    Matrix2x2 m;
    m.val00 = val00 - z.val00;
    m.val01 = val01 - z.val01;
    m.val10 = val10 - z.val10;
    m.val11 = val11 - z.val11;

    return m;
};
void Matrix2x2:: MultScalar(double scalar){
    
    this->val00 = scalar*val00;
    this->val01 = scalar*val01;
    this->val10 = scalar*val10;
    this->val11 = scalar*val11;


};
/*
double Matrix2x2::Getval00() const {return val00;}
double Matrix2x2::Getval01() const {return val01;}
double Matrix2x2::Getval10() const {return val10;}
double Matrix2x2::Getval11() const {return val11;}
*/

void Matrix2x2::Print() const {
    std::cout << this->Getval00() << " " << this->Getval01() << std::endl;
    std::cout << this->Getval10() << " " << this->Getval11() << std::endl;
}