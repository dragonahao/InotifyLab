#include <string.h>
#include <jni.h>
#include "JniUtil.h"

char* JniUtil::jstringToString(JNIEnv* env, jstring jstr) {
    char* rtn = NULL;
    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("utf-8");
    jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray) env->CallObjectMethod(jstr, mid, strencode);
    jsize array_lenth = env->GetArrayLength(barr);
    jbyte* ba = env->GetByteArrayElements(barr, JNI_FALSE);
    if (array_lenth > 0) {
        rtn = (char*) malloc(array_lenth + 1);

        memcpy(rtn, ba, array_lenth);
        rtn[array_lenth] = 0;
    }
    env->ReleaseByteArrayElements(barr, ba, 0);
    return rtn;
}
