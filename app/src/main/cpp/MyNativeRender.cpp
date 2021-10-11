//
// Created by hk Lee on 2021/10/9.
//

#include <android/log.h>
#include "header/com_jinqikeji_opengles_MyNaticeRender.h"
#include "MyGLRenderContext.h"

extern "C"
JNIEXPORT void JNICALL
Java_com_jinqikeji_opengles_MyNaticeRender_natice_1OnInit(JNIEnv *env, jobject thiz) {
    __android_log_print(ANDROID_LOG_INFO,"MyNaticeRender","natice_1OnInit");
    MyGLRenderContext::GetInstance();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_jinqikeji_opengles_MyNaticeRender_natice_1OnUnInit(JNIEnv *env, jobject thiz) {
    MyGLRenderContext::DestroyInstance();

}

extern "C"
JNIEXPORT void JNICALL
Java_com_jinqikeji_opengles_MyNaticeRender_native_1OnSurfaceChanged(JNIEnv *env, jobject thiz,

                                                                    jint width, jint height) {
    __android_log_print(ANDROID_LOG_INFO,"MyNaticeRender","native_1OnSurfaceChanged");

    MyGLRenderContext::GetInstance()->OnSurfaceChanged(width, height);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_jinqikeji_opengles_MyNaticeRender_native_1OnSurfaceCreated(JNIEnv *env, jobject thiz) {
    __android_log_print(ANDROID_LOG_INFO,"MyNaticeRender","native_1OnSurfaceCreated");

    MyGLRenderContext::GetInstance()->OnSurfaceCreated();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_jinqikeji_opengles_MyNaticeRender_native_1SetImageData(JNIEnv *env, jobject thiz,
                                                                jint format, jint width,
                                                                jint height, jbyteArray bytes) {
//    MyGLRenderContext::GetInstance()->SetImageData(format, width, height, bytes);

}
extern "C"
JNIEXPORT void JNICALL
Java_com_jinqikeji_opengles_MyNaticeRender_native_1OnDrawFrame(JNIEnv *env, jobject thiz) {

    MyGLRenderContext::GetInstance()->OnDrawFrame();

}