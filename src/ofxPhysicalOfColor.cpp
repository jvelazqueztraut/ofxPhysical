//
//  ofxPhysicalOfColor.cpp
//  ofxPhysical
//
//  Created by jvelazqueztraut on 06/05/13.
//
//  masOTROS SRL

#include "ofxPhysicalOfColor.h"


ofxPhysicalOfColor::ofxPhysicalOfColor(){

	setup();	
	originalColor_ = ofColor::black;
	targetColor_ = ofColor::white;
}


void ofxPhysicalOfColor::update(float dt){
	ofxPhysical::update( dt );
}


void ofxPhysicalOfColor::applyCurrentColor(){
	ofSetColor( getCurrentColor() );
}


void ofxPhysicalOfColor::setColor(ofColor newColor){
	ofxPhysical::reset();
	originalColor_ = newColor;
	targetColor_ = newColor;
}


void ofxPhysicalOfColor::revertToBaseColor(){
	ofxPhysical::reset();
}
	

void ofxPhysicalOfColor::setAlphaOnly( float a ){

	originalColor_ = getCurrentColor();
	originalColor_.a = a;
	targetColor_ = originalColor_;
	ofxPhysical::reset();
}


void ofxPhysicalOfColor::animateTo( ofColor col ){

	originalColor_ = getCurrentColor();
	targetColor_ = col;
	ofxPhysical::startAnimation();
}


void ofxPhysicalOfColor::animateToAfterDelay( ofColor newColor, float delay ){
	
	//originalTempColor_ = getCurrentColor();
	targetTempColor_ = newColor;
	ofxPhysical::startAnimationAfterDelay(delay);
}


void ofxPhysicalOfColor::animateToIfFinished( ofColor col ){
	if (animating_ == false){
		animateTo( col );
	}
}


void ofxPhysicalOfColor::fadeIn(){

	ofColor targetC = getCurrentColor();
	
	if ( sizeof(targetC.r) == sizeof(float) )
		targetC.a = (float)1.0f;
	else if ( sizeof(targetC.r) == sizeof(unsigned char) )
		targetC.a = (unsigned char) numeric_limits<unsigned char>::max();
	else if ( sizeof(targetC.r) == sizeof(unsigned short) )
		targetC.a = (unsigned char) numeric_limits<unsigned short>::max();

	animateTo( targetC );	
}


void ofxPhysicalOfColor::fadeOut(){

	ofColor targetC = getCurrentColor();
	targetC.a = 0.0f;
	animateTo( targetC );
}


void ofxPhysicalOfColor::animateToAlpha( float a ){

	originalColor_ = getCurrentColor();
	targetColor_ = originalColor_;
	targetColor_.a = a;
	ofxPhysical::startAnimation();	
}


void ofxPhysicalOfColor::startBlinking( float blinkDuration){

	setRepeatType(LOOP_BACK_AND_FORTH);
	setCurve(EASE_IN_EASE_OUT);
	setAlphaOnly(0.0f);
	setDuration( blinkDuration );
	ofColor c = getCurrentColor();
	c.a = 255;
	animateTo( c );
}


ofColor ofxPhysicalOfColor::getCurrentColor(){

	float mappedDistribution = calcCurveAt(percentDone_);	///percentDone_ is [0..1] & tells me where we are between orig and target
	float newC[4];
	ofColor r;
	for (int i = 0; i < 4; i++){
		newC[i] = ( (int)targetColor_[i] - (int)originalColor_[i]) * mappedDistribution;
		r[i] = originalColor_[i] + newC[i];
	}
	return r;
}

void ofxPhysicalOfColor::startAfterWait(){
	animateTo(targetTempColor_);
}


