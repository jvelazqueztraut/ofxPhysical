//
//  ofxPhysicalOfPoint.cpp
//  ofxPhysical
//
//  Created by jvelazqueztraut on 06/05/13.
//
//  masOTROS SRL

#include "ofxPhysicalOfPoint.h"


ofxPhysicalOfPoint::ofxPhysicalOfPoint(){

	ofxPhysical::setup();	//defaults to (0,0,0) >> (0,0,0)
}


void ofxPhysicalOfPoint::update(float dt){

	ofxPhysical::update( dt );
}


void ofxPhysicalOfPoint::draw(){
	
	ofPushMatrix();
		ofPoint p = getCurrentPosition();
		ofTranslate(p.x, p.y, p.z);
		float s = 10.0f;
		ofRect( -s * 0.5f, -s * 0.5f, s, s );
	ofPopMatrix();
	
}


void ofxPhysicalOfPoint::setPosition( ofPoint newPos ){
	
	ofxPhysical::reset();
	originalPoint_ = newPos;
	targetPoint_ = newPos;
}


void ofxPhysicalOfPoint::setPositionX( float newX ){
	
	originalPoint_ = getCurrentPosition();
	originalPoint_.x = newX;
	targetPoint_ = originalPoint_;
	ofxPhysical::reset();
}


void ofxPhysicalOfPoint::setPositionY( float newY ){
	
	originalPoint_ = getCurrentPosition();
	originalPoint_.y = newY;
	targetPoint_ = originalPoint_;
	ofxPhysical::reset();
}


void ofxPhysicalOfPoint::setPositionZ( float newZ ){
	
	originalPoint_ = getCurrentPosition();
	originalPoint_.z = newZ;
	targetPoint_ = originalPoint_;
	ofxPhysical::reset();
}


void ofxPhysicalOfPoint::reset(){

	ofxPhysical::reset();
	targetPoint_ = originalPoint_;
}


void ofxPhysicalOfPoint::animateTo( ofPoint where ){

	originalPoint_ = getCurrentPosition();
	targetPoint_ = where;
	ofxPhysical::startAnimation();
}

void ofxPhysicalOfPoint::animateToAfterDelay( ofPoint where, float delay ){
	
	if (delay <= 0.0f){
		animateTo(where);
	}else{
		//originalTempPoint_ = getCurrentPosition();
		targetTempPoint_ = where;
		ofxPhysical::startAnimationAfterDelay(delay);
	}
}


void ofxPhysicalOfPoint::animateToIfFinished( ofPoint where ){

	if (animating_ == false){
		animateTo(where);
	}
}


ofPoint ofxPhysicalOfPoint::getCurrentPosition(){
	float mappedDistribution = calcCurveAt(percentDone_);	///percentDone_ is [0..1] & tells me where we are between orig and target
	return originalPoint_ + ( targetPoint_ - originalPoint_) * mappedDistribution ;
}


void ofxPhysicalOfPoint::startAfterWait(){
	animateTo(targetTempPoint_);
}
