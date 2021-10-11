//
// Created by hk Lee on 2021/10/11.
//

#ifndef OPENGLES_RECTANGLE_H
#define OPENGLES_RECTANGLE_H

#include <cstdint>
#include <EGL/egl.h>
#include <GLES/gl.h>
#include <GLES3/gl3.h>
#include "GLUtils.h"
#include <cstdlib>
#include <android/log.h>

class Rectangle {
    GLuint program;
    GLuint vertexShader;
    GLuint fragmentShader;
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
public:
    void init();

    void onDraw();

    Rectangle();

    ~Rectangle();
};


#endif //OPENGLES_RECTANGLE_H
