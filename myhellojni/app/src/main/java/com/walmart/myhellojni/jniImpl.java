package com.walmart.myhellojni;

import android.util.Log;

public class jniImpl {

    private static final String TAG = "jniImpl";

    private long counter;

    public jniImpl(int start) {
        counter = create(start);
    }

//    public jniImpl(String start) {
//        counter = create_from_string(start);
//    }

    protected void finalize() {
        destroy(counter);
    }

    public void add(int val) {
        add(counter, val);
    }

    public void subtract(int val) {
        subtract(counter, val);
    }

    public void increment() {
        increment(counter);
    }

    public void decrement() {
        decrement(counter);
    }

    public int getVal() {
        return getval(counter);
    }

    public String toString() {
        return tooString(counter);
    }

    static {
        Log.d(TAG,"Loads lib started..");
        System.loadLibrary("hello-jni");
        Log.d(TAG,"Load libs finished");
    }

    public native String getStringFromJNI();

    public native String getJniString();

    public native int getIntSqure(int value);

    public native int getProduct(int value1, int value2);

    public native int getSum(int value1, int value2);

    public native int getRemainder(int value1, int value2);

    public native boolean getBooleanMethod(boolean unsignedChar);

    private  native long create(int start);

    //private  native long create_from_string(String start);

    private  native void destroy(long ptr);

    private  native void add(long ptr, int val);

    private  native void subtract(long ptr, int val);

    private  native void increment(long ptr);

    private  native void decrement(long ptr);

    private  native int getval(long ptr);

    private  native String tooString(long ptr);
}
