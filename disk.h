
#ifndef DISK_H
#define DISK_H

class Disk{
    private:
        double x;
        double y; 
        double radius;

    public:
        Disk(double x, double y, double r);

        void move(double dx, double dy);
        double distance(Disk& d);

        double get_X();
        double get_Y();
        double get_radius();

        void set_X(double x);
        void set_Y(double y);
        void set_radius(double radius);
};

#endif