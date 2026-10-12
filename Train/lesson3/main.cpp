#include "MarkerManager.hpp"
#include <iostream>

using namespace std;

int main()
{
    MarkerManager manager;

    while (true)
    {
        cout << "\n===== Marker 管理系统 =====\n";
        cout << "1. 查看全部标记\n";
        cout << "2. 添加标记\n";
        cout << "3. 按编号查询\n";
        cout << "4. 按阈值统计\n";
        cout << "5. 修改优先级\n";
        cout << "6. 按优先级排序并展示\n";
        cout << "0. 退出\n";
        cout << "请选择操作：";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            manager.display();
            break;
        }

        case 2:
        {
            Marker m;

            cout << "请输入编号、x坐标、y坐标、优先级：";
            cin >> m.id >> m.x_mm >> m.y_mm >> m.priority;

            if (manager.add(m))
            {
                cout << "添加成功\n";
            }
            else
            {
                cout << "添加失败：编号重复或输入不合法\n";
            }

            break;
        }

        case 3:
        {
            int id;

            cout << "请输入要查询的编号：";
            cin >> id;

            if (manager.contains(id))
            {
                cout << "编号存在\n";
            }
            else
            {
                cout << "编号不存在\n";
            }

            break;
        }

        case 4:
        {
            int threshold;

            cout << "请输入优先级阈值：";
            cin >> threshold;

            cout << "符合条件的标记数量："
                 << manager.countpriority(threshold)
                 << endl;

            break;
        }

        case 5:
        {
            int id;
            int newPriority;

            cout << "请输入编号和新的优先级：";
            cin >> id >> newPriority;

            if (manager.updatePriority(id, newPriority))
            {
                cout << "修改成功\n";
            }
            else
            {
                cout << "修改失败：编号不存在或优先级无效\n";
            }

            break;
        }

        case 6:
        {
            manager.sortByPriority();

            cout << "排序结果：\n";
            manager.display();

            break;
        }

        case 0:
        {
            cout << "程序退出\n";
            return 0;
        }

        default:
        {
            cout << "无效选项，请重新选择\n";
            break;
        }
        }
    }

    return 0;
}