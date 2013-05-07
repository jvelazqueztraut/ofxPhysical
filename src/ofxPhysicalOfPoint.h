//
//  ofxPhysicalOfPoint.h
//  ofxPhysical
//
//  Created by jvelazqueztraut on 06/05/13.
//
//  masOTROS SRL

#pragma once

#include "ofxPhysical.h"
#include "ofMain.h"


class ofxPhysicalOfPoint : public ofxPhysical{
	
	public:

		ofxPhysicalOfPoint();
		~ofxPhysicalOfPoint(){};
		
		void update(float dt);	
		void draw();			//draws the current pos point in space
	

		// apply for immediate effect ////////////////////////////////////////////////////////////////////
	
		void setPosition( ofPoint );
		void setPositionX(float);
		void setPositionY(float);
		void setPositionZ(float);
		void reset();		
	
		// animated over time ///////////////////////////////////////////////////////////////////////////

		///starts new animation to "where" regardless, using the current pos as the inital value
		void animateTo( ofPoint where );
		void animateToAfterDelay( ofPoint where, float delay );

		void animateToIfFinished( ofPoint where );
		
		//gets
		ofPoint getCurrentPosition();
		ofPoint getTargetPosition(){ return targetPoint_;}
		ofPoint getOriginalPosition(){ return originalPoint_;}
	

	private:

		void startAfterWait();

		ofPoint 		originalPoint_;
		ofPoint 		targetPoint_;
		ofPoint 		targetTempPoint_;


};