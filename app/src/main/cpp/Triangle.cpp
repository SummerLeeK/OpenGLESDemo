//
// Created by hk Lee on 2021/10/9.
//

#include "Triangle.h"
#include "GLUtils.h"
#include <time.h>
#include <cstdlib>
#include <android/log.h>

void Triangle::init() {
    char vShaderStr[] =
            "#version 300 es                          \n"
            "layout(location = 0) in vec3 vPosition;  \n"
            "layout(location = 1) in vec3 aColor;     \n"
            "out vec3 ourColor;                       \n"
            "void main()                              \n"
            "{                                        \n"
            "   gl_Position = vec4(vPosition,1.0f);              \n"
            "   ourColor = aColor;                    \n"
            "}                                        \n";

    char fShaderStr[] =
            "#version 300 es                              \n"
            "precision mediump float;                     \n"
            "out vec4 fragColor;                          \n"
            "in vec3 ourColor;                            \n"
            "void main()                                  \n"
            "{                                            \n"
            "   fragColor =vec4(ourColor,1.0f);           \n"
            "}                                            \n";

    program = GLUtils::createProgram(vShaderStr, fShaderStr, vertexShader, fragmentShader);

    GLfloat vVertices[] = {
            0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
            -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
            0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
    };


    glGenVertexArrays(1, &VAO);

    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vVertices), vVertices, GL_STATIC_DRAW);


    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                          (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);
}

void Triangle::onDraw() {



    glUseProgram(program);
    glBindVertexArray(VAO);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}

Triangle::Triangle() {

}

Triangle::~Triangle() {

    if (program != 0) {
        glDeleteProgram(program);
        program = 0;
    }
}