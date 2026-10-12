#ifndef MARKER_MANAGER_HPP
#define MARKER_MANAGER_HPP

#include <vector>

struct Marker
{
    int id;
    double x_mm;
    double y_mm;
    int priority;
};

class MarkerManager
{
private:
    std::vector<Marker> markers;

public:
    bool add(const Marker& marker);

    bool contains(int id) const;

    void display() const;

    int countpriority(int threshold) const;

    bool updatePriority(int id, int newPriority);

    void sortByPriority();
};

#endif