/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_jinqikeji_opengles_MyNaticeRender */

#ifndef _Included_com_jinqikeji_opengles_MyNaticeRender
#define _Included_com_jinqikeji_opengles_MyNaticeRender
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_jinqikeji_opengles_MyNaticeRender
 * Method:    natice_OnInit
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_jinqikeji_opengles_MyNaticeRender_natice_1OnInit
  (JNIEnv *, jobject);

/*
 * Class:     com_jinqikeji_opengles_MyNaticeRender
 * Method:    natice_OnUnInit
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_jinqikeji_opengles_MyNaticeRender_natice_1OnUnInit
  (JNIEnv *, jobject);

/*
 * Class:     com_jinqikeji_opengles_MyNaticeRender
 * Method:    native_SetImageData
 * Signature: (III[B)V
 */
JNIEXPORT void JNICALL Java_com_jinqikeji_opengles_MyNaticeRender_native_1SetImageData
  (JNIEnv *, jobject, jint, jint, jint, jbyteArray);

/*
 * Class:     com_jinqikeji_opengles_MyNaticeRender
 * Method:    native_OnSurfaceCreated
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_jinqikeji_opengles_MyNaticeRender_native_1OnSurfaceCreated
  (JNIEnv *, jobject);

/*
 * Class:     com_jinqikeji_opengles_MyNaticeRender
 * Method:    native_OnSurfaceChanged
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_com_jinqikeji_opengles_MyNaticeRender_native_1OnSurfaceChanged
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     com_jinqikeji_opengles_MyNaticeRender
 * Method:    native_OnDrawFrame
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_jinqikeji_opengles_MyNaticeRender_native_1OnDrawFrame
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
