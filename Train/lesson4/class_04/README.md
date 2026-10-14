## personality
1.  目前只完成基础题三道，这几天太忙，接下来两天补完
2.  OpenCV学习量还是挺大的，每段代码至少敲过两边，后面需要加强下函数
2.  5天前进的rm,前三课相关习题已补上
3.  借助chatgpt与xmind自学，文件基于Ubuntu 26.04.1下VScode编译

## homework
### Practice 1
1.  imread()读取lena图片--检验 .empty()
2.  输出图片信息-- Mat属性 .rows .cols .channels .step.....
3.  roi创建--采用Rect rect()--Mat roi=img(rect)--后面有用到rect
4.  rectangle-画矩形
5.  深拷贝与浅拷贝

### Practice 2
1.  imread()->cvtColor()->threshold()->findContour()->contourArea()->rectangle()-> putText()
2.  原图->灰度图->二值图->算轮廓->算轮廓面积(for筛选+新vector存)-> 画矩形+编号
3.  反思:记清函数使用即可

### Practice 3
1.  vector<Point2f> srcPoints
2.  getPerspectiveTransform()+warpPerspective() 
3.  透视找点解决
