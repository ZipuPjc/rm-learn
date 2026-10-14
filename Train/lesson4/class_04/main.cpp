#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

void printPixel(string name, Vec3b pixel)
{
    cout << name 
         << " BGR=("
         << (int)pixel[0] << ", "
         << (int)pixel[1] << ", "
         << (int)pixel[2] << ")"
         << endl;
}

int main()
{
    // 1. 读取 Lena
    Mat img = imread("../assets/lena.jpg");

    if(img.empty())
    {
        cout << "Image not found!" << endl;
        return -1;
    }
    imshow("Lena", img);
    // 2. 输出图像信息
    cout << "rows=" << img.rows << endl;
    cout << "cols=" << img.cols << endl;
    cout << "channels=" << img.channels() << endl;
    cout << "step=" << img.step << endl;
    cout << "Color order: BGR" << endl;
    // 3. ROI
    Rect rect(200,180,220,240);
    Mat roi = img(rect);
    // 原图副本
    Mat marked = img.clone();
    rectangle(marked,rect,Scalar(0,255,0),2);
    imshow("Marked", marked);
    imshow("ROI", roi);
    imwrite(
        "../results/lena_marked.png",
        marked
    );
    imwrite(
        "../results/lena_roi.png",
        roi
    );

    //共享数据的ROI
    Mat shared_img = img.clone();
    Mat shared_roi = shared_img(rect);
    Vec3b before_shared =shared_roi.at<Vec3b>(0,0);
    printPixel("Before",before_shared);
    // 修改ROI左上角
    shared_roi.at<Vec3b>(0,0)=Vec3b(0,0,255);
    Vec3b after_shared =shared_roi.at<Vec3b>(0,0);
    printPixel("After",after_shared);
    // 查看原副本对应位置
    printPixel(
        "Image(180,200)",
        shared_img.at<Vec3b>(180,200)
    );

    // clone后的ROI
    Mat clone_img = img.clone();
    Mat clone_roi =clone_img(rect).clone();
    Vec3b before_clone =clone_roi.at<Vec3b>(0,0);
    printPixel("Before",before_clone);
    clone_roi.at<Vec3b>(0,0)= Vec3b(0,0,255);
    Vec3b after_clone =clone_roi.at<Vec3b>(0,0);
    printPixel("After",after_clone);
    printPixel("Image(180,200)",clone_img.at<Vec3b>(180,200));


    cout<<"----------------------------------------------------------------------------------"<<endl;
    
    Mat coins_img=imread("../assets/coins.png",IMREAD_COLOR);
    if(coins_img.empty())
    {
        cout<<"Coins_img not found!"<<endl;
    }
    //转灰度
    Mat coins_gray;
    cvtColor(coins_img,coins_gray,COLOR_BGR2GRAY);
    //二值化
    Mat coins_binary;
    threshold(coins_gray,coins_binary,135,255,THRESH_BINARY);

    imwrite("../results/coins_binary.png",coins_binary);

    //外轮廓
    vector<vector<Point>> coins_Contours;
    findContours(coins_binary,coins_Contours,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
    //求面积--筛选
    vector<vector<Point>> coins_validContours;
    for(int i=0;i<coins_Contours.size();i++)
    {
        double area=contourArea(coins_Contours[i]);
        if(area>=250 && area<=4000)
        {
            coins_validContours.push_back(coins_Contours[i]);
        }
    }
    //绘制矩形框和编号
    for(int i=0;i<coins_validContours.size();i++)
    {
        Rect box=boundingRect(coins_validContours[i]);
        rectangle(coins_img,box,Scalar(0,255,0),2);


        putText(coins_img,to_string(i+1),Point(box.x,box.y),FONT_HERSHEY_SIMPLEX, 0.5,
        Scalar(0, 0, 255), 1);
    }
    int coins_count = (int)coins_validContours.size();
    imwrite("../results/coins_counted.png",coins_img);

    imshow("1",coins_binary);
    imshow("2",coins_img);

    cout<<"-------------------------------------------------------------";
    Mat sudoku_img = imread("../assets/sudoku.png");

    if (sudoku_img.empty())
    {
        cout << "Sudoku image not found!" << endl;
        return -1;
    }

    Mat sudoku_points = sudoku_img.clone();
    Mat sudoku_corrected;

    vector<Point2f> srcPoints = {
        Point2f(74, 85),
        Point2f(490, 70),
        Point2f(520, 520),
        Point2f(36, 516)
    };

    vector<Point2f> dstPoints = {
        Point2f(0, 0),
        Point2f(449, 0),
        Point2f(449, 449),
        Point2f(0, 449)
    };

    for (int i = 0; i < (int)srcPoints.size(); i++)
    {
        circle(
            sudoku_points,
            srcPoints[i],
            5,
            Scalar(0, 0, 255),
            FILLED
        );

    putText(
        sudoku_points,
        to_string(i + 1),
        Point(
            (int)srcPoints[i].x + 5,
            (int)srcPoints[i].y - 5
        ),
        FONT_HERSHEY_SIMPLEX,
        0.7,
        Scalar(0, 0, 255),
        2
        );
    }

    Mat perspectiveMatrix = getPerspectiveTransform(
        srcPoints,
        dstPoints
    );

    warpPerspective(
        sudoku_img,
        sudoku_corrected,
        perspectiveMatrix,
        Size(450, 450)
    );

    imwrite("../results/sudoku_points.png", sudoku_points);
    imwrite("../results/sudoku_corrected.png", sudoku_corrected);

    cout << "Corrected width: " << sudoku_corrected.cols << endl;
    cout << "Corrected height: " << sudoku_corrected.rows << endl;

    imshow("Sudoku Points", sudoku_points);
    imshow("Sudoku Corrected", sudoku_corrected);

    waitKey(0);
}