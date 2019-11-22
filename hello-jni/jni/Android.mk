LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE    := hello-jni

LOCAL_C_INCLUDES := $(LOCAL_PATH)/

LOCAL_SRC_FILES := hello-jni.c \
                    counter.c
include $(BUILD_SHARED_LIBRARY)
