# personal
## 作业看法
    1.代码手写 涉及基础c++知识，没有特别需要注意的
    2.需要注意：CMake需要重新编译，工程向路径改变（利用chatgpt修改CMakeLists.txt）
    3.附加体简单看了下，1.使用sort+cmp或者lambada排序 2.while+switch（此处代码均由gpt完成）
## 课程
    1.含糊不清，课程深浅度不够
    2.课程源码未开源，仅发布当前课程相关，自学平台资源差
    2.讲课建议参考北理工追梦实验室课程 https://b23.tv/C8AuEDU
    3.资料建议参考北航战队github开源学习 https://github.com/LemperorD/learningRM_alg

# AI制作
## MarkerManager
## 一、项目简介
本项目使用 C++ 实现标记管理功能，包含标记添加、编号查询、
优先级统计、优先级修改和排序，并通过终端菜单进行交互。
## 二、文件职责
- `include/MarkerManager.hpp`：定义 Marker 结构体和 MarkerManager 类。
- `src/MarkerManager.cpp`：实现 MarkerManager 的成员函数。
- `main.cpp`：实现终端菜单、用户输入和功能调用。
- `CMakeLists.txt`：配置项目构建。
- `.gitignore`：忽略编译生成的文件。
## 三、构建方法
在项目根目录执行：
```bash
cmake -S . -B build
cmake --build build
```

## 四、运行方法
```bash
./build/class_03
```
## 五、自测数据
依次选择菜单中的添加功能，输入：
```text
1 100 200 80
2 200 -50 95
3 0 0 60
```
检查以下情况：
1. 添加合法标记。
2. 添加重复编号，预期失败。
3. 添加优先级为 101 的标记，预期失败。
4. 输入阈值 80，预期统计数量为 2。
5. 输入阈值 90，预期统计数量为 1。
6. 在空管理器中查看标记，程序应正常运行。
7. 修改编号 1 的优先级为 95，然后排序。
8. 尝试将编号 1 的优先级修改为 101，预期失败且原记录不变。
