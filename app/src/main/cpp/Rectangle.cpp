//
// Created by hk Lee on 2021/10/11.
//
#include "Rectangle.h"


Rectangle::Rectangle() {

}

Rectangle::~Rectangle() {

}

void Rectangle::init() {
    char vShaderStr[] =
            "#version 300 es                          \n"
            "layout(location = 0) in vec3 vPosition;  \n"
            "out vec3 ourColor;                       \n"
            "void main()                              \n"
            "{                                        \n"
            "   gl_Position = vec4(vPosition,1.0f);              \n"
            "}                                        \n";

    char fShaderStr[] =
            "#version 300 es                              \n"
            "precision mediump float;                     \n"
            "out vec4 fragColor;                          \n"
            "void main()                                  \n"
            "{                                            \n"
            "   fragColor =vec4(1.0f,0.5f,0.5f,1.0f);           \n"
            "}                                            \n";

    program = GLUtils::createProgram(vShaderStr, fShaderStr, vertexShader, fragmentShader);

    GLfloat vVertices[] = {
            0.5f,  0.5f, 0.0f,  // top right
            0.5f, -0.5f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f,  // bottom left
            -0.5f,  0.5f, 0.0f
    };


    const int indices[] = {0, 1, 3,//第一个三角形
                           1, 2, 3//第二个三角形
    };
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vVertices), vVertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float) ,(void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);

}

void Rectangle::onDraw() {

    glUseProgram(program);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}