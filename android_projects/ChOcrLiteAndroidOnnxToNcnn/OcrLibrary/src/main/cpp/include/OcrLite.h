#ifndef __OCR_LITE_H__
#define __OCR_LITE_H__

#include "opencv2/core.hpp"
#include "ncnn/net.h"
#include "OcrStruct.h"
#include "DbNet.h"
#include "AngleNet.h"
#include "CrnnNet.h"

using namespace cv;
using namespace std;

class OcrLite {
public:
    OcrLite(JNIEnv *jniEnv, jobject assetManager, int numOfThread);

    void initLogger(bool isDebug);

    void Logger(const char *format, ...);

    OcrResult detect(cv::Mat &src, cv::Rect &originRect, ScaleParam &scale,
                     float boxScoreThresh, float boxThresh, float minArea,
                     float unClipRatio, bool doAngle, bool mostAngle);

private:
    bool isLOG = true;
    DbNet dbNet;
    AngleNet angleNet;
    CrnnNet crnnNet;

    void drawTextBoxes(cv::Mat &boxImg, std::vector<TextBox> &textBoxes, int thickness);

    std::vector<cv::Mat> getPartImages(cv::Mat &src, std::vector<TextBox> &textBoxes);


};


#endif