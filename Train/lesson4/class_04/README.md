## personality
1.  已完成基础和附加题
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
### 附加题
1.  morphologyEx() 通用形式 morphologyEx(mask,dst,op,kernel);
闭操作 MORPH_CLOSE 膨胀 → 腐蚀 → 填小黑洞
2.  Mat kernel = getStructuringElement(shape,ksiz，anchor);
MORPH_RECT矩形
MORPH_ELLIPSE椭圆
MORPH_CROSS十字
### 附加题2
1.  createTrackbar()
getTrackbarPos() 读取滑动条的值
setTrackbarPos() 设置初始值
