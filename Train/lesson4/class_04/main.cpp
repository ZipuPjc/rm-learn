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
    Mat img = imread("../assets/lena.jpg");
    if(img.empty())
    {
        cout << "Image not found!" << endl;
        return -1;
    }
    imshow("Lena", img);
    cout << "rows=" << img.rows << endl;
    cout << "cols=" << img.cols << endl;
    cout << "channels=" << img.channels() << endl;
    cout << "step=" << img.step << endl;
    cout << "Color order: BGR" << endl;
    Rect rect(200,180,220,240);
    Mat roi = img(rect);
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

    cout<<"----------------------------------------------------------------------";
    Mat fruits_img=imread("../assets/fruits.jpg",IMREAD_COLOR);
    Mat fruits_hsv;
    Mat fruits_mask;
    cvtColor(fruits_img,fruits_hsv,COLOR_BGR2HSV);
    inRange(fruits_hsv,Scalar(35,60,40),Scalar(60,255,255),fruits_mask);
    Mat kernel=getStructuringElement(MORPH_RECT,Size(3,3));
    Mat fruits_open;
    morphologyEx(fruits_mask,fruits_open,MORPH_OPEN,kernel);
    imshow("Original", fruits_img);
    imshow("Mask", fruits_mask);
    imshow("Open", fruits_open);
    imwrite("../results/fruits_mask.png", fruits_mask);
    imwrite("../results/fruits_open.png", fruits_open);
    
    cout<<"-------------------------------------------------------------------------";
    Mat coins_tune_img = imread("../assets/coins.png", IMREAD_COLOR);
    if (coins_tune_img.empty())
    {
        cout << "Coins image not found!" << endl;
        return -1;
    }
    Mat coins_tune_gray;
    cvtColor(coins_tune_img, coins_tune_gray, COLOR_BGR2GRAY);

    namedWindow("Coins Tune Binary", WINDOW_NORMAL);
    namedWindow("Coins Tune Result", WINDOW_NORMAL);
    createTrackbar("Threshold", "Coins Tune Binary", nullptr, 255);
    setTrackbarPos("Threshold", "Coins Tune Binary", 135);

    Mat coins_tune_binary;
    Mat coins_tune_result;

    vector<vector<Point>> coins_tune_contours;
    vector<vector<Point>> coins_tune_valid_contours;
    int coins_tune_count = 0;
    while (true)
    {
        int threshold_value =
            getTrackbarPos("Threshold", "Coins Tune Binary");
        threshold(
            coins_tune_gray,
            coins_tune_binary,
            threshold_value,
            255,
            THRESH_BINARY
        );
        coins_tune_result = coins_tune_img.clone();
        coins_tune_contours.clear();
        coins_tune_valid_contours.clear();
        findContours(
            coins_tune_binary.clone(),
            coins_tune_contours,
            RETR_EXTERNAL,
            CHAIN_APPROX_SIMPLE
        );
        for (int i = 0; i < (int)coins_tune_contours.size(); i++)
        {
            double area = contourArea(coins_tune_contours[i]);

            if (area >= 250 && area <= 4000)
            {
                coins_tune_valid_contours.push_back(
                    coins_tune_contours[i]
                );
            }
        }
        for (int i = 0; i < (int)coins_tune_valid_contours.size(); i++)
        {
            Rect box = boundingRect(coins_tune_valid_contours[i]);

            rectangle(
                coins_tune_result,
                box,
                Scalar(0, 255, 0),
                2
            );
            int textY = max(15, box.y - 5);
            putText(
                coins_tune_result,
                to_string(i + 1),
                Point(box.x, textY),
                FONT_HERSHEY_SIMPLEX,
                0.5,
                Scalar(0, 0, 255),
                1
            );
        }
        coins_tune_count =
            (int)coins_tune_valid_contours.size();
        putText(
            coins_tune_result,
            "Count: " + to_string(coins_tune_count),
            Point(10, 25),
            FONT_HERSHEY_SIMPLEX,
            0.7,
            Scalar(255, 0, 0),
            2
        );
        imshow("Coins Tune Binary", coins_tune_binary);
        imshow("Coins Tune Result", coins_tune_result);
        if (waitKey(1) == 27)
        {
            break;
        }
    }
    imwrite(
        "../results/coins_tuned_binary.png",
        coins_tune_binary
    );

    imwrite(
        "../results/coins_tuned_counted.png",
        coins_tune_result
    );
    cout << "最终阈值："
        << getTrackbarPos("Threshold", "Coins Tune Binary")
        << endl;

    cout << "最终硬币数量："
        << coins_tune_count
        << endl;

    cout << "调参结果已保存。" << endl;
    waitKey(0);
    destroyWindow("Coins Tune Binary");
    destroyWindow("Coins Tune Result");

}
