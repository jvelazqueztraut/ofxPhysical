//
//  ofxPhysical.h
//  ofxPhysical
//
//  Created by jvelazqueztraut on 06/05/13.
//
//  masOTROS SRL


#define DEFAULT_ANIMATION_DURATION	1.0f


#include <iostream>
#include <Math.h>
using namespace std;

#pragma once

#define OF_AVAILABLE true

#if (OF_AVAILABLE)
#include "ofMain.h"
#endif



enum AnimRepeat{
	PLAY_ONCE = 0,
	LOOP, 
	LOOP_BACK_AND_FORTH, 
	LOOP_BACK_AND_FORTH_ONCE,
};

enum AnimCurve{
	EASE_IN_EASE_OUT = 0,
	EASE_IN, 
	EASE_OUT, 
	LINEAR,	
	LATE_LINEAR, 
	VERY_LATE_LINEAR, 
	BOUNCY,	//this needs work TODO
	OBJECT_DROP,
	TANH, 
	SINH, 	
	EARLY_SQUARE, 
	SQUARE,
	LATE_SQUARE,
	BLINK_5,
	BLINK_3,
	BLINK_2,
	BLINK_AND_FADE_1,
	BLINK_AND_FADE_2,
	BLINK_AND_FADE_3,
	LATE_EASE_IN_EASE_OUT,
	VERY_LATE_EASE_IN_EASE_OUT,
	QUADRATIC_EASE_IN,
	QUADRATIC_EASE_OUT,
	QUADRATIC_BEZIER_PARAM, //http://www.flong.com/texts/code/shapers_exp/
	EXPONENTIAL_SIGMOID_PARAM,
	NUM_ANIM_CURVES //leave that on the last to see how many we have
};


class ofxPhysical{
	
	public:

		void setup();
		void update(float dt);

		void pause();					//really needed?
		void resume();					//

		void setCurve( AnimCurve curveStyle_ );
		void setRepeatType( AnimRepeat repeat );
		void setDuration( float seconds );

		void setDoubleExpSigmoidParam(float param){doubleExpSigmoidParam = param;} //only for QUADRATIC_BEZIER_PARAM curve
		void setQuadraticBezierParams(float a, float b){quadraticBezierParamA = a; quadraticBezierParamB = b; } //only for EXPONENTIAL_SIGMOID_PARAM curve
		void setDropObjectParams(float bounceHeightPercent){bounceAmp = bounceHeightPercent;} //only for DROP_OBJECT curve

		float getDuration(){ return 1.0f/transitionSpeed_; }

		float getPercentDone();			///get how much of the animation has been "walked"
		void setPercentDone(float p);			//Will allow to skip to any point of animation. use carefully
		bool isAnimating();				///is the animation still going on?
		bool hasFinishedAnimating();	///has the animation finished?
		bool isWaitingForAnimationToStart();	///an animation has been scheduled with "animateToAfterDelay"
		bool isOrWillBeAnimating();		/// object is either animating now or it's waiting to be launch animation after a delay
		float getCurrentSpeed(); ///as a percentage of linear speed
		float timeLeftForAnimationToStart(){ return delay_; }
		float waitTimeLeftPercent(){ return 1.0f - delay_ / waitTime_; }
	
		static string getCurveName(AnimCurve c);
		static float calcCurveAt(float percent, AnimCurve type, float param1 = 0.5, float param2 = 0.5, float param3 = 0.5); //exposing this to get direct access to simple curve values
		void drawCurve(int x, int y, int size);

		virtual ~ofxPhysical(void) {}
		ofxPhysical() {}


	protected:

		bool		animating_;
		bool		paused_;
	
		int 		playcount_;
	
		float		transitionSpeed_;	///this is 1/N (N == # of updates) it will take for the transition to end
		float		percentDone_;		/// [0..1]
			
	
		float		delay_;		//countdown timer that stores delay when startAnimationAfterDelay() is used
		float		waitTime_;	//original wait delay_
		AnimRepeat 	repeat_;
		AnimCurve	curveStyle_;
	
		int			direction_;  // 1 : forward,   -1 : backward
	
		float calcCurveAt( float percent );

		void startAnimation();			///Used by subclasses to indicate we are starting an anim
		void startAnimationAfterDelay(float delay);
		void reset();					///Used by subclasses to indicate a reset of an animation
		void fillInParams(float&p1, float &p2, float &p3);

	private:
	
		virtual void startAfterWait() = 0;
		float currentSpeed_;
		float prevSpeed_;
		float lastDT_;

		//for some of the curves
		float doubleExpSigmoidParam;
		float quadraticBezierParamA, quadraticBezierParamB;
		float bounceAmp;
};

	