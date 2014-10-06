LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_LDLIBS    := -llog
LOCAL_MODULE    := Inotify
LOCAL_SRC_FILES := Inotify.cpp
LOCAL_SRC_FILES += JniUtil.cpp

include $(BUILD_SHARED_LIBRARY)
