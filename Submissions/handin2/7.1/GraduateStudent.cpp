#include "GraduateStudent.hpp"

GraduateStudent::GraduateStudent(){

}

GraduateStudent::GraduateStudent(std::string name, double fines, double fees, bool fullTime){
    this->fullTime = fullTime;
}

void GraduateStudent::print(){
    std::cout << name << std::endl;
    std::cout << "fines: " << this->GetLibraryFines << std::endl;
    //std::cout << "fees: " << this->fees << std::endl;
    std::cout << "fullTime: " << this->fullTime << std::endl;
 
}
double GraduateStudent::MoneyOwed() const{
    return this->GetLibraryFines();
}