//
// Created by zhouke on 2017/7/22.
//

#ifndef TESTNDK_LOG_H
#define TESTNDK_LOG_H
#include <android/log.h>
#define LOG_TAG "System.out.c"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#endif //TESTNDK_LOG_H
