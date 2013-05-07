//
//  ofxPhysicalOfFloat.h
//  ofxPhysical
//
//  Created by jvelazqueztraut on 06/05/13.
//
//  masOTROS SRL

#pragma once

#include "ofxPhysical.h"

class ofxPhysicalFloat : public ofxPhysical{
	    	
	public:

		ofxPhysicalFloat();
		~ofxPhysicalFloat(){};

		void update( float dt );
	
		void animateTo( float newVal );
		void animateToAfterDelay( float newVal, float delay );
		void animateToIfFinished( float newVal );	///starts new animation to newVal only if there isnt an anim going on
		void animateFromTo( float originalValue, float destinationValue );


		//gets
		float val();								///gives you the current value.
		float getCurrentValue(){ return val(); }
		float getTargetValue(){ return targetVal_;}
		float getOriginalValue(){ return originalVal_;}

		void reset(float newVal);					///sets an original value, and stops animation
		void reset();								///goes back to the original value


	
		///trying to make everyone life's easier with operators, I want an ofxPhysicalFloat to behave 
		///like a float here, but doesn't quite work all the time
		///so you'd better use the .val() method to get the current value

		operator float(){ return val(); }			///return current value when asking for float
		operator double(){ return val(); }			///return current value when asking for double
	
	private:

		// ## MUST IMPLEMENT ##
		void		startAfterWait();
		float		originalVal_;
		float		targetVal_;
		float		targetTempVal_;

};

