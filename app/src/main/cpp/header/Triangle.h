//
// Created by hk Lee on 2021/10/9.
//

#ifndef OPENGLES_TRIANGLE_H
#define OPENGLES_TRIANGLE_H
#include <cstdint>
#include <EGL/egl.h>
#include <GLES/gl.h>
#include <GLES3/gl3.h>
class Triangle {
    GLuint program;
    GLuint vertexShader;
    GLuint fragmentShader;
    unsigned int VAO;
    unsigned int VBO;

public:
    void init();

    void onDraw();

    Triangle();

    ~Triangle();
};


#endif //OPENGLES_TRIANGLE_H
