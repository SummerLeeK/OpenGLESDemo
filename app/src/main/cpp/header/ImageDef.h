//
// Created by hk Lee on 2021/10/9.
//

#ifndef OPENGLES_IMAGEDEF_H
#define OPENGLES_IMAGEDEF_H
#include <cstdint>

const int IMAGE_FORMAT_RGBA = 0x01;

const int IMAGE_FORMAT_NV21 = 0x02;

const int IMAGE_FORMAT_NV12 = 0x03;

const int IMAGE_FORMAT_I420 = 0x04;

struct NativeImage {
    int width;
    int height;
    int format;
    uint8_t *ppPlane[3];

    NativeImage() {
        width = 0;
        height = 0;
        format = 0;
        ppPlane[0] = nullptr;
        ppPlane[1] = nullptr;
        ppPlane[2] = nullptr;
    }
};


#endif //OPENGLES_IMAGEDEF_H
