/*
 * ofxAndroidScreenToGallery.cpp
 *
 *  Created on: Jun 16, 2016
 *      Author: noyan
 */


#include "ofxAndroidScreenToGallery.h"

#ifndef NULL
#define NULL   ((void *) 0)
#endif


ofxAndroidScreenToGallery::ofxAndroidScreenToGallery() {
	javaClassName = "cc/openframeworks/ofxaddons/ofxandroidscreentogallery/OFXAndroidScreenToGallery";

	char *javaclassname = new char[javaClassName.size()+1];
	strcpy(javaclassname, javaClassName.c_str());
    jclass tmp = ofGetJNIEnv()->FindClass(javaclassname);
    jclass_This = (jclass)ofGetJNIEnv()->NewGlobalRef(tmp);

    jconstructor_This = ofGetJNIEnv()->GetMethodID(jclass_This, "<init>", "()V");

	jinstance_This = ofGetJNIEnv()->NewGlobalRef(ofGetJNIEnv()->NewObject(jclass_This, jconstructor_This));
}


ofxAndroidScreenToGallery::~ofxAndroidScreenToGallery() {
	ofGetJNIEnv()->DeleteGlobalRef(jclass_This);
	ofGetJNIEnv()->DeleteGlobalRef(jinstance_This);
}


std::string ofxAndroidScreenToGallery::getPictureDirectoryPath() {
    jstring resultJNIStr = (jstring)ofGetJNIEnv()->CallObjectMethod(jinstance_This, ofGetJNIEnv()->GetMethodID(jclass_This, "getPictureDirectoryPath", "()Ljava/lang/String;"));

	jboolean *iscopy = NULL;
    const char *resultCStr = ofGetJNIEnv()->GetStringUTFChars(resultJNIStr, iscopy);
    std::string resultStr(resultCStr);
    ofGetJNIEnv()->ReleaseStringUTFChars(resultJNIStr, resultCStr);
    ofGetJNIEnv()->DeleteLocalRef(resultJNIStr);
    return resultStr;
}


void ofxAndroidScreenToGallery::takeScreenshot() {
	std::string screenshotdir = getPictureDirectoryPath() + "/Screenshots/";

	std::string yearstr = ofToString(ofGetYear());
	std::string monthstr = ofToString(ofGetMonth());
	if (monthstr.length() == 1) monthstr = "0" + monthstr;
	std::string daystr = ofToString(ofGetDay());
	if (daystr.length() == 1) daystr = "0" + daystr;
	std::string hourstr = ofToString(ofGetHours());
	if (hourstr.length() == 1) hourstr = "0" + hourstr;
	std::string minutestr = ofToString(ofGetMinutes());
	if (minutestr.length() == 1) minutestr = "0" + minutestr;
	std::string secondstr = ofToString(ofGetSeconds());
	if (secondstr.length() == 1) secondstr = "0" + secondstr;

	std::string screenshotfilename = "Screenshot_" + yearstr + "-" + monthstr + "-" + daystr + "-" + hourstr + "-" + minutestr + "-" + secondstr;
	std::string screenshotfilepath = screenshotdir + screenshotfilename + ".png";

	ofSaveScreen(screenshotfilepath);

    jstring jStringParam = ofGetJNIEnv()->NewStringUTF(screenshotfilepath.c_str());
	ofGetJNIEnv()->CallVoidMethod(jinstance_This, ofGetJNIEnv()->GetMethodID(jclass_This, "addScreenshotToGallery", "(Ljava/lang/String;)V"), jStringParam);
	ofGetJNIEnv()->DeleteLocalRef(jStringParam);
}



