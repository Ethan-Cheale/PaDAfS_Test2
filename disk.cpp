#include "disk.h"
#include <cmath>

Disk::Disk(double x, double y, double r){
    this->x = x;
    this->y = y;
    this->radius = r;
}

void Disk::move(double dx, double dy){
    this->x += dx;
    this->y += dy;
}

double Disk::distance(Disk& other){
    double squared_dist = std::pow((this->x - other.x),2) + std::pow((this->y - other.y),2);
    return (std::sqrt(squared_dist));
}

double Disk::get_X(){
    return this->x;
}

double Disk::get_Y(){
    return this->y;
}

double Disk::get_radius(){
    return this->radius;
}

void Disk::set_X(double x){
    this->x = x;
}

void Disk::set_Y(double y){
    this->y = y;
}

void Disk::set_radius(double radius){
    this->radius = radius;
}
