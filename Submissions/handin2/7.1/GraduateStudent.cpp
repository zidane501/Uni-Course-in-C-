#include "GraduateStudent.hpp"

GraduateStudent::GraduateStudent(){

}

GraduateStudent::GraduateStudent(std::string name, double fines, double fees, bool fullTime){
    this->name          = name;
    this->fines         = fines;
    this->tuition_fees  = fees;
    this->fullTime      = fullTime;
}

