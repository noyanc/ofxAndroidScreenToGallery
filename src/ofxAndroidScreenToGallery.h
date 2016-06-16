/*
 * ofxAndroidScreenToGallery.h
 *
 *  Created on: Jun 16, 2016
 *      Author: noyan
 */

#ifndef OFXANDROIDSCREENTOGALLERY_H_
#define OFXANDROIDSCREENTOGALLERY_H_

#include "ofMain.h"
#include "ofxAndroid.h"


class ofxAndroidScreenToGallery {
public:
	ofxAndroidScreenToGallery();
	~ofxAndroidScreenToGallery();

	void takeScreenshot();

private:
	std::string javaClassName;
	jclass jclass_This;
	jobject jinstance_This;
	jmethodID jconstructor_This;

	std::string getPictureDirectoryPath();
};



#endif /* OFXANDROIDSCREENTOGALLERY_H_ */
