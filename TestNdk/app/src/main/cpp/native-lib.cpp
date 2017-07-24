#include <string>
#include <threadpool.h>
#include "../include/com_example_test_MainActivity.h"


JNIEXPORT jstring JNICALL
Java_com_example_test_MainActivity_sayHello(JNIEnv *env, jobject instance) {

    // TODO

    std::string hello = "Hello from C++1";

    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT jstring JNICALL
Java_com_example_test_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++2";
    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT jint JNICALL
Java_com_example_test_MainActivity_createThradPool(JNIEnv *env, jobject instance) {
    threadpool_t *thp = threadpool_create(3,100,12);    /*线程池里最小3个线程，最大100个，队列最大值12*/
    // TODO
    return (jint) thp;
}
void *process(void *arg)
{
    LOGI("thread 0x%x working on task %d\n ",(unsigned int)pthread_self(),*(int *)arg);
    sleep(1);
    LOGI("task %d is end\n",*(int *)arg);
    return NULL;
}
JNIEXPORT void JNICALL Java_com_example_test_MainActivity_threadAdd
        (JNIEnv * env, jobject jobject1, jint threadhandler, jintArray array){
    /* 第三个参数用来表明返回的数组指针是指向数据的真正存区（值为1时），
       还是指向拷贝了数组元素值的另一存区（值为0)*/
    //jint * addrAenv  = (*env)->GetIntArrayElements(env,array,1);
    jboolean  bo = true;
    jint  *add = env->GetIntArrayElements(array,&bo);
    int length = env->GetArrayLength(array);
    threadpool_t * thp = (threadpool_t *) threadhandler;
    for(int i=0;i<length;i++){

        int * add_int = &add[i];
        LOGI("add[%d] = %d 入队列 %d",i,add[i],&add[i]);
        threadpool_add(thp,process,(void*)&add[i]);
    }
    LOGI("hello world");
}

JNIEXPORT void JNICALL Java_com_example_test_MainActivity_thradDestory
        (JNIEnv * env, jobject obj, jint handler) {
    threadpool_t * thp = (threadpool_t *) handler;
    threadpool_destroy(thp);
}

