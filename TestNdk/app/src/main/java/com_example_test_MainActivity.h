/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_example_test_MainActivity */

#ifndef _Included_com_example_test_MainActivity
#define _Included_com_example_test_MainActivity
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_example_test_MainActivity
 * Method:    stringFromJNI
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_test_MainActivity_stringFromJNI
  (JNIEnv *, jobject);

/*
 * Class:     com_example_test_MainActivity
 * Method:    sayHello
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_test_MainActivity_sayHello
  (JNIEnv *, jobject);

/*
 * Class:     com_example_test_MainActivity
 * Method:    createThradPool
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_example_test_MainActivity_createThradPool
  (JNIEnv *, jobject);

/*
 * Class:     com_example_test_MainActivity
 * Method:    threadAdd
 * Signature: (I[I)V
 */
JNIEXPORT void JNICALL Java_com_example_test_MainActivity_threadAdd
  (JNIEnv *, jobject, jint, jintArray);

/*
 * Class:     com_example_test_MainActivity
 * Method:    thradDestory
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_example_test_MainActivity_thradDestory
  (JNIEnv *, jobject, jint);

#ifdef __cplusplus
}
#endif
#endif
