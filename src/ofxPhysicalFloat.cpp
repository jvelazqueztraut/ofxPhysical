//
//  ofxPhysicalOfFloat.cpp
//  ofxPhysical
//
//  Created by jvelazqueztraut on 06/05/13.
//
//  masOTROS SRL

#include "ofxPhysicalFloat.h"

ofxPhysicalFloat::ofxPhysicalFloat(){

	ofxPhysical::setup();
	originalVal_ = targetVal_= 0.0f;
}


void ofxPhysicalFloat::update( float dt ){
	
	ofxPhysical::update( dt );
}


void ofxPhysicalFloat::animateTo( float newVal ){

	originalVal_ = val();
	targetVal_ = newVal;
	
	ofxPhysical::startAnimation();	
}


void ofxPhysicalFloat::animateToAfterDelay( float newVal, float delay ){
	
	if (delay <= 0.0f){
		animateTo(newVal);
	}else{
		//originalTempVal_ = val();
		targetTempVal_ = newVal;
		ofxPhysical::startAnimationAfterDelay(delay);
	}
}


void ofxPhysicalFloat::animateFromTo( float originalValue, float destinationValue ){

	ofxPhysical::startAnimation();
	
	originalVal_ = originalValue;
	targetVal_ = destinationValue;
}


void ofxPhysicalFloat::animateToIfFinished( float newVal ){
	if ( animating_ == false ){
		animateTo(newVal);
	}
}


float ofxPhysicalFloat::val(){
	
	float mappedDistribution = calcCurveAt( percentDone_ );	///percentDone_ is [0..1] & tells me where we are between orig and target
	return originalVal_ + ( targetVal_ - originalVal_ ) * mappedDistribution ;
}


void ofxPhysicalFloat::reset( float newVal ){

	ofxPhysical::reset();
	originalVal_ = targetVal_ = newVal; 
}


void ofxPhysicalFloat::reset(){

	ofxPhysical::reset();
	targetVal_ = originalVal_;
}


void ofxPhysicalFloat::startAfterWait(){
	animateTo(targetTempVal_);
}

