#include "Matrix2x2.hpp"

Matrix2x2::Matrix2x2(){

};
Matrix2x2::Matrix2x2(const Matrix2x2& other){
    other.Getval00 = val00;
    other.Getval01 = val01;
    other.Getval10 = val10;
    other.Getval11 = val11;
};
Matrix2x2::Matrix2x2(double a = 0, double b = 0, double c = 0, double d = 0){
    val00 = a; val01 = b;
    val10 = c; val11 = d;
};
double Matrix2x2::CalcDeterminant() const{
    return val00*val11-val01*val10;
};
Matrix2x2  Matrix2x2::CalcInverse() const{
    Matrix2x2 inverse(val00, val01, val10, val11);
    double determinant = this->CalcDeterminant;
    inverse.val00 =  val11/determinant;
    inverse.val10 = -val10/determinant;
    inverse.val01 = -val01/determinant;
    inverse.val11 =  val00/determinant;
    
    return inverse;
};
Matrix2x2& Matrix2x2:: operator=(const Matrix2x2& z){

};
Matrix2x2 Matrix2x2:: operator-() const{

};
Matrix2x2 Matrix2x2:: operator+(const Matrix2x2& z) const{

};
Matrix2x2 Matrix2x2:: operator-(const Matrix2x2& z) const{

};
void Matrix2x2:: MultScalar(double scalar){

};
double Matrix2x2::Getval00() const {return val00;}
double Matrix2x2::Getval01() const {return val01;}
double Matrix2x2::Getval10() const {return val10;}
double Matrix2x2::Getval11() const {return val11;}

void Matrix2x2::Print() const {
    std::cout << this->Getval00 << " " << this->Getval01 << std::endl;
    std::cout << this->Getval10 << " " << this->Getval11 << std::endl;
}