//第一次写的cpp
/*
#include <iostream>
#include<vector>

using namespace cv;
using namespace std;

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
        vector<Marker> markers;
protected:
public:
        bool add(const Marker& marker)
        {
            if(marker.id<=0||marker.priority<0||marker.priority>100||contains(marker.id))
            {
                return false;
            }
            markers.push_back(marker);
            return true;

        }

        bool contains(int id) const
        {
            for(const Marker& m:markers)
            {
                if(m.id==id)
                {
                    return true;
                }
            }
            return false;
        }

        void display() const
        {
        for (const Marker& m : markers)
            {
            cout << "编号 " << m.id
                 << "：位置 (" << m.x_mm << ", "
                 << m.y_mm << ")，优先级 "
                 << m.priority << endl;
            }
        }

        int countpriority(int threshold) const
        {
            int count = 0;
            for (const Marker& m : markers)
            {
                if (m.priority >= threshold)
                {
                    count++;
                }
            }
            return count;
        }  
};

int countpriority(const vector<Marker>& markers)
{
    int count = 0;
    for(Marker m: markers)
    {
        if(m.priority >= 80)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    vector<Marker> markers ={
        {1,100,200,80},
        {2,200,-50,95},
        {3,0,0,60}};

    for(Marker m: markers)
    {
         cout << "编号 " << m.id
             << "：位置 (" << m.x_mm << ", "
             << m.y_mm << ")，优先级 "
             << m.priority << endl;
    }
    cout << "优先级大于80的标记数量: " << countpriority(markers) << endl;

    Marker* ptr = &markers[0];
    cout << "指针读取：" << ptr->id << endl;
    Marker& ref = markers[0];
    cout << "引用读取：" << ref.id << endl;

    MarkerManager markers2;
    for(const Marker&m : markers)
    {
        if(markers2.add(m))
        {
        cout << "add id " << m.id << ":"
             << "true"<< endl;
        }
    }
    Marker test1={2,300,400,90};
    Marker test2={4,500,600,101};
    cout<<(markers2.add(test1)?"true":"false")<<endl;
    cout<<(markers2.add(test2)?"true":"false")<<endl;

    return 0;
}
*/