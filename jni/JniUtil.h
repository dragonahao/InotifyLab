/*
 * JniUtil.h
 *
 *  Created on: Oct 6, 2014
 *      Author: sodino
 */

#ifndef JNIUTIL_H_
#define JNIUTIL_H_

#include <jni.h>
#include <string.h>
class JniUtil {
public :
	static char* jstringToString(JNIEnv* , jstring );
};

#endif /* JNIUTIL_H_ */
