//
// Created by hk Lee on 2021/10/9.
//

#ifndef OPENGLES_MYGLRENDERCONTEXT_H
#define OPENGLES_MYGLRENDERCONTEXT_H

#include <cstdint>
#include <EGL/egl.h>
#include <GLES/gl.h>

class MyGLRenderContext {
public:
    MyGLRenderContext();

    ~MyGLRenderContext();
   static MyGLRenderContext* m_pContext;

    void SetImageData(int format, int width, int height, uint8_t *pData);

    void OnSurfaceCreated();

    void OnSurfaceChanged(int width, int height);

    void OnDrawFrame();

    MyGLRenderContext *GetInstance();

    void DestroyInstance();
};


#endif //OPENGLES_MYGLRENDERCONTEXT_H
