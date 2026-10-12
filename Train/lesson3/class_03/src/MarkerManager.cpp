#include "MarkerManager.hpp"
#include <iostream>
#include <algorithm>

bool MarkerManager::add(const Marker& marker)
{
    if (marker.id <= 0 ||
        marker.priority < 0 ||
        marker.priority > 100 ||
        contains(marker.id))
    {
        return false;
    }

    markers.push_back(marker);
    return true;
}

bool MarkerManager::contains(int id) const
{
    for (const Marker& m : markers)
    {
        if (m.id == id)
        {
            return true;
        }
    }

    return false;
}

void MarkerManager::display() const
{
    for (const Marker& m : markers)
    {
        std::cout << "编号 " << m.id
                  << "：位置 (" << m.x_mm
                  << ", " << m.y_mm
                  << ")，优先级 "
                  << m.priority << std::endl;
    }
}

int MarkerManager::countpriority(int threshold) const
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

bool MarkerManager::updatePriority(int id, int newPriority)
{
    // 检查新优先级是否合法
    if (newPriority < 0 || newPriority > 100)
    {
        return false;
    }

    // 根据编号查找并修改
    for (Marker& m : markers)
    {
        if (m.id == id)
        {
            m.priority = newPriority;
            return true;
        }
    }

    // 编号不存在
    return false;
}

void MarkerManager::sortByPriority()
{
    std::sort(
        markers.begin(),
        markers.end(),
        [](const Marker& a, const Marker& b)
        {
            // 优先级高的排在前面
            if (a.priority != b.priority)
            {
                return a.priority > b.priority;
            }

            // 优先级相同，编号小的排在前面
            return a.id < b.id;
        }
    );
}