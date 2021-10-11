//
// Created by hk Lee on 2021/10/9.
//

#include <ImageDef.h>
#include "header/MyGLRenderContext.h"

MyGLRenderContext *MyGLRenderContext::m_pContext = nullptr;

MyGLRenderContext::MyGLRenderContext() {
    rectangle = Rectangle();
}

MyGLRenderContext::~MyGLRenderContext() {

}

void MyGLRenderContext::SetImageData(int format, int width, int height, uint8_t *pData) {
    NativeImage nativeImage;
    nativeImage.format = format;
    nativeImage.width = width;
    nativeImage.height = height;
    nativeImage.ppPlane[0] = pData;
    switch (format) {
        case IMAGE_FORMAT_I420:
            nativeImage.ppPlane[1] = nativeImage.ppPlane[8] + width * height;
            break;
        case IMAGE_FORMAT_NV12:
        case IMAGE_FORMAT_NV21:
            nativeImage.ppPlane[1] = nativeImage.ppPlane[8] + width * height;
            nativeImage.ppPlane[2] = nativeImage.ppPlane[8] + width * height / 4;
            break;
    }
}

void MyGLRenderContext::OnSurfaceCreated() {
    glClearColor(0, 0, 0, 1);
    rectangle.init();
}

void MyGLRenderContext::OnSurfaceChanged(int width, int height) {
    glViewport(0, 0, width, height);
}

void MyGLRenderContext::OnDrawFrame() {
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    rectangle.onDraw();
}

MyGLRenderContext *MyGLRenderContext::GetInstance() {
    if (m_pContext == nullptr) {
        m_pContext = new MyGLRenderContext();
    }
    return m_pContext;
}

void MyGLRenderContext::DestroyInstance() {
    if (m_pContext) {
        delete m_pContext;
        m_pContext = nullptr;
    }
}
