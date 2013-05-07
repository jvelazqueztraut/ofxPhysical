//
//  ofxPhysicalOfFbo.h
//  ofxPhysical
//
//  Created by jvelazqueztraut on 06/05/13.
//
//  masOTROS SRL

#pragma once

#include "ofxPhysicalObject.h"

class ofxPhysicalOfFbo : public ofxPhysicalObject {
public:
    ~ofxPhysicalOfFbo(){};
    
    void setup(int w, int h){
        fbo.allocate(w,h);
        fbo.begin();
        ofClear(0,0);
        fbo.end();
    }
    
    void begin(){
        fbo.begin();
    }
    
    void end(){
        fbo.end();
    }
    
    void draw(){
        ofxPhysicalObject::beginDraw();
        fbo.draw(0,0);
        ofxPhysicalObject::endDraw();
    }
    
    void setAnchorPercent(float xPct,float yPct){
        fbo.setAnchorPercent(xPct,yPct);
    }
    
    ofFbo       fbo;
};
