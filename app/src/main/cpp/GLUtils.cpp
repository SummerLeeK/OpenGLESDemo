//
// Created by hk Lee on 2021/10/11.
//

#include "header/GLUtils.h"
#include <android/log.h>

GLuint GLUtils::createProgram(char *vShaderStr, char *fShaderStr, GLuint vertexShader,
                              GLuint fragmentShader) {
    int success;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vShaderStr, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if (!success) {
        __android_log_print(ANDROID_LOG_ERROR, "createProgram", "vertex create shader failed");
    }

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fShaderStr, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if (!success) {
        __android_log_print(ANDROID_LOG_ERROR, "createProgram", "fragment create shader failed");
    }

    GLuint program = glCreateProgram();

    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &success);

    if (!success) {
        __android_log_print(ANDROID_LOG_ERROR, "createProgram", "link program failed");
    }
// 删除着色器，它们已经链接到我们的程序中了，已经不再需要了
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return program;
}