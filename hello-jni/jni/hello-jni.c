#include <string.h>
#include <jni.h>
#include <stdio.h>
#include <stdlib.h>

#include "counter.h"

JNIEXPORT jstring JNICALL 
Java_com_walmart_myhellojni_jniImpl_getStringFromJNI(JNIEnv *env, jobject thisObj) {
   return (*env)->NewStringUTF(env, "Hello from native code!");
}

jstring
Java_com_walmart_myhellojni_jniImpl_getJniString(JNIEnv* env, jobject thiz){
    return (*env)->NewStringUTF(env, "Hello from JNI! Dhanesh");
}

JNIEXPORT jint JNICALL 
Java_com_walmart_myhellojni_jniImpl_getIntSqure(JNIEnv* env, jobject obj,jint value) {
    return value * value;
}

JNIEXPORT jint JNICALL
Java_com_walmart_myhellojni_jniImpl_getSum(JNIEnv* env, jobject obj,jint value1, jint value2) {
    return value1 + value2;
}

JNIEXPORT jint JNICALL
Java_com_walmart_myhellojni_jniImpl_getProduct(JNIEnv* env, jobject obj,jint value1, jint value2) {
    return value1 * value2;
}

JNIEXPORT jint JNICALL
Java_com_walmart_myhellojni_jniImpl_getRemainder(JNIEnv* env, jobject obj,jint value1, jint value2) {
    return value1 % value2;
}

JNIEXPORT jboolean JNICALL 
Java_com_walmart_myhellojni_jniImpl_getBooleanMethod(JNIEnv* env,jobject obj, jboolean unsignedChar) {
    return !unsignedChar;
}

JNIEXPORT jlong JNICALL
Java_com_walmart_myhellojni_jniImpl_create(JNIEnv *env, jobject obj, jint start)
{
	counter_t *c;

	(void)env;
	(void)obj;

	c = counter_create((int)start);
	return (jlong)c;
}

JNIEXPORT jlong JNICALL
Java_com_walmart_myhellojni_jniImpl_create_from_string(JNIEnv *env, jobject obj, jstring start)
{
	const char *str;
	int         sval;

	str  = (*env)->GetStringUTFChars(env, start, 0);
	sval = atoi(str);
	(*env)->ReleaseStringUTFChars(env, start, str);

	return Java_com_walmart_myhellojni_jniImpl_create(env, obj, sval);
}

JNIEXPORT void JNICALL
Java_com_walmart_myhellojni_jniImpl_destroy(JNIEnv *env, jobject obj, jlong ptr)
{
	(void)env;
	(void)obj;
	counter_destroy((counter_t *)ptr);
}

JNIEXPORT void JNICALL
Java_com_walmart_myhellojni_jniImpl_add(JNIEnv *env, jobject obj, jlong ptr, jint val)
{
	(void)env;
	(void)obj;
	counter_add((counter_t *)ptr, (int)val);
}

JNIEXPORT void JNICALL
Java_com_walmart_myhellojni_jniImpl_subtract(JNIEnv *env, jobject obj, jlong ptr, jint val)
{
	(void)env;
	(void)obj;
	counter_subtract((counter_t *)ptr, (int)val);
}

JNIEXPORT void JNICALL
Java_com_walmart_myhellojni_jniImpl_increment(JNIEnv *env, jobject obj, jlong ptr)
{
	(void)env;
	(void)obj;
	counter_increment((counter_t *)ptr);
}

JNIEXPORT void JNICALL
Java_com_walmart_myhellojni_jniImpl_decrement(JNIEnv *env, jobject obj, jlong ptr)
{
	(void)env;
	(void)obj;
	counter_decrement((counter_t *)ptr);
}

JNIEXPORT jint JNICALL
Java_com_walmart_myhellojni_jniImpl_getval(JNIEnv *env, jobject obj, jlong ptr)
{
	(void)env;
	(void)obj;
	return counter_getval((counter_t *)ptr);
}

JNIEXPORT jstring JNICALL
Java_com_walmart_myhellojni_jniImpl_tooString(JNIEnv *env, jobject obj, jlong ptr)
{
	int     val;
	char    sval[16];
	jstring jval;

	(void)obj;

	val = counter_getval((counter_t *)ptr);
	snprintf(sval, sizeof(sval), "%d", val);

	return (*env)->NewStringUTF(env, sval);
}