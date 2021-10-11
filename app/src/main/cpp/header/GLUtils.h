//
// Created by hk Lee on 2021/10/11.
//

#ifndef OPENGLES_GLUTILS_H
#define OPENGLES_GLUTILS_H
#include <cstdint>
#include <EGL/egl.h>
#include <GLES/gl.h>
#include <GLES3/gl3.h>

class GLUtils {

    static GLuint loadShader();

public:
    static GLuint createProgram(char* vShaderStr,char* fShaderStr,GLuint vertexShader,GLuint fragmentShader);
};


#endif //OPENGLES_GLUTILS_H
