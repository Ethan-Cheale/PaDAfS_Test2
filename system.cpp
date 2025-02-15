#include <fstream>
#include "system.h"
#include "disk.h"

System::System(int N, double displacement, double radius, double boxSize_X, double boxSize_Y, int seed) {

        this->boxSize_X= boxSize_X;
        this->boxSize_Y= boxSize_Y;
        this->dist = std::uniform_real_distribution<double>(0, 1);
        this->displacement=displacement;
        gen = std::mt19937(seed);
        
        int nSide = static_cast<int>(boxSize_Y/ (2*radius));

        for (int i = 0; i < nSide && disks.size() < N; ++i) {
            for (int j = 0; j < nSide && disks.size() < N; ++j) {
                disks.push_back(Disk(i * 2*radius, j * 2*radius, radius));
            }
        }
    }   

bool System::overlap(int i){
    for (int j = 0; j < disks.size(); ++j) {
        if (i!=j && disks[i].distance(disks[j]) < (disks[i].get_radius() + disks[j].get_radius()) ) {
            return true;
        }
    }
    return false;
}

void System::step() {
    for (size_t i = 0; i<disks.size(); ++i) 
    {
        int selected_disk = std::rand() % disks.size();
        double oldx = disks[selected_disk].get_X();
        double oldy = disks[selected_disk].get_Y();
        double dx = uniform(-displacement, displacement);
        double dy = uniform(-displacement, displacement);
        this->disks[selected_disk].move(dx, dy);
        
        enforceBoundaries(disks[selected_disk]);

        if (overlap(selected_disk)){
            disks[selected_disk].set_X(oldx);
            disks[selected_disk].set_Y(oldy);
        }
       
    }
}

void System::enforceBoundaries(Disk & disk) {
        if (disk.get_X() < 0) disk.set_X(0);
        if (disk.get_X() > boxSize_X) disk.set_X(boxSize_X);
        if (disk.get_Y() < 0) disk.set_Y(0);
        if (disk.get_Y() > boxSize_Y) disk.set_Y(boxSize_Y);
}

double System::uniform(double min, double max){
    return ((max-min)*this->dist(this->gen) + min);

}

void System::save(const std::string &filename){
    // save state of disks to file
    std::ofstream outFile(filename);
    outFile<<disks.size()<<std::endl;
    outFile<<"Comment"<<std::endl;
    for (Disk& disk : disks) {
      outFile<<"A "<<disk.get_X()<<" "<<disk.get_Y()<<" "<<disk.get_radius()<<std::endl;

    }
    outFile.close();
    
}