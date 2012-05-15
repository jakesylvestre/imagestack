#ifndef IMAGESTACK_FILTER_H
#define IMAGESTACK_FILTER_H
#include "header.h"

class GaussianBlur : public Operation {
public:
    void help();
    void parse(vector<string> args);
    static Image apply(Image im, float filterWidth, float filterHeight, float filterFrames);
};

class FastBlur : public Operation {
public:
    void help();
    void parse(vector<string> args);
    static void apply(Image im, float filterWidth, float filterHeight, float filterFrames, bool addMargin = true);
private:
    // IIR filters
    static void blurX(Image im, float filterWidth, int tapSpacing = 1);
    static void blurY(Image im, float filterHeight, int tapSpacing = 1);
    static void blurT(Image im, float filterFrames, int tapSpacing = 1);

    // helper function for IIR filtering
    static void calculateCoefficients(float sigma, float *c0, float *c1, float *c2, float *c3);
};

class RectFilter : public Operation {
public:
    void help();
    void parse(vector<string> args);
    static void apply(Image im, int filterWidth, int filterHeight, int filterFrames, int iterations = 1);

private:
    static void blurX(Image im, int filterSize, int iterations = 1);
    static void blurY(Image im, int filterSize, int iterations = 1);
    static void blurT(Image im, int filterSize, int iterations = 1);
    static void blurXCompletely(Image im);
};


class LanczosBlur : public Operation {
public:
    void help();
    void parse(vector<string> args);
    static Image apply(Image im, float filterWidth, float filterHeight, float filterFrames);
};

class MedianFilter : public Operation {
public:
    void help();
    void parse(vector<string> args);
    static Image apply(Image im, int radius);
};

class MinFilter : public Operation {
  public:
    void help();
    void parse(vector<string> args);
    static void apply(Image im, int radius);
};

class MaxFilter : public Operation {
  public:
    void help();
    void parse(vector<string> args);
    static void apply(Image im, int radius);
};

class PercentileFilter : public Operation {
public:
    void help();
    void parse(vector<string> args);
    static Image apply(Image im, int radius, float percentile);
};

class CircularFilter : public Operation {
public:
    void help();
    void parse(vector<string> args);
    static Image apply(Image im, int radius);
};


class Envelope : public Operation {
public:
    void help();
    void parse(vector<string> args);
    enum Mode {Lower = 0, Upper};
    static void apply(Image im, Mode m, int radius);
};

class HotPixelSuppression : public Operation {
public:
    void help();
    void parse(vector<string> args);
    static Image apply(Image im);
};

#include "footer.h"
#endif