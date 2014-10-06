#include <jni.h>
#include <string.h>
#include <android/log.h>
#include "JniUtil.h"

#define TAG "ANDROID_LAB" // 这个是自定义的LOG的标识
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型


#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_lab_sodino_inotifylab_MainActivity_watch
	(JNIEnv * env, jobject thiz, jstring pathWatch) {
	char *char_pathWatch = NULL;
	char_pathWatch = JniUtil::jstringToString(env, pathWatch);
 	LOGD("watch path=%s", char_pathWatch);
}


JavaVM *cached_jvm;
jweak Class_C;
jmethodID MID_C_g;
JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM* jvm, void* reserved) {
	LOGD("jni_onLoad");

	//check JNI version
	jint result = JNI_ERR;
	JNIEnv* env = NULL;
	if (jvm->GetEnv((void**) &env, JNI_VERSION_1_6) == JNI_OK) {
		result = JNI_VERSION_1_6;
	} else if (jvm->GetEnv((void**) &env, JNI_VERSION_1_4) == JNI_OK) {
		result = JNI_VERSION_1_4;
	} else if (jvm->GetEnv((void**) &env, JNI_VERSION_1_2) == JNI_OK) {
		result = JNI_VERSION_1_2;
	} else if (jvm->GetEnv((void**) &env, JNI_VERSION_1_1) == JNI_OK) {
		result = JNI_VERSION_1_1;
	}

	if (result != JNI_ERR) {
		LOGD("JNI VERSION=%d",result);
	} else {
		LOGD("cannot get the jni version");
	}

	return result;
}

JNIEXPORT void JNICALL
JNI_OnUnload(JavaVM *jvm, void *reserved) {
	LOGD("jni_onLoad");
//	JNIEnv *env;
//	if (jvm->GetEnv((void **) &env, JNI_VERSION_1_2)) {
//		return;
//	}
//	env->DeleteWeakGlobalRef(Class_C);
	return;
}

#ifdef __cplusplus
}
#endif
