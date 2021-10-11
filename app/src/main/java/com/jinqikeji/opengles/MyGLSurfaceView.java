package com.jinqikeji.opengles;

import android.content.Context;
import android.opengl.GLSurfaceView;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class MyGLSurfaceView extends GLSurfaceView {

    public MyNaticeRender myNaticeRender;
    public MyGLSurfaceView.MyGLRender glRender;

    public MyGLSurfaceView(Context context) {
        super(context);
        this.setEGLContextClientVersion(3);

        myNaticeRender = new MyNaticeRender();
        glRender = new MyGLSurfaceView.MyGLRender(myNaticeRender);
        setRenderer(glRender);
        setRenderMode(RENDERMODE_CONTINUOUSLY);

    }

    public static class MyGLRender implements Renderer {

        public MyNaticeRender myNaticeRender;

        public MyGLRender(MyNaticeRender myNaticeRender) {
            this.myNaticeRender = myNaticeRender;
            myNaticeRender.natice_OnInit();
        }

        @Override
        public void onSurfaceCreated(GL10 gl, EGLConfig config) {
            myNaticeRender.native_OnSurfaceCreated();
        }

        @Override
        public void onSurfaceChanged(GL10 gl, int width, int height) {
            myNaticeRender.native_OnSurfaceChanged(width, height);

        }

        @Override
        public void onDrawFrame(GL10 gl) {
            myNaticeRender.native_OnDrawFrame();
        }
    }
}
