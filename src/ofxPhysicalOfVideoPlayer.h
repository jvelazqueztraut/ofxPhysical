//
//  ofxPhysicalOfVideoPlayer.h
//  ofxPhysical
//
//  Created by jvelazqueztraut on 06/05/13.
//
//  masOTROS SRL

#pragma once

#include "ofxPhysicalObject.h"

class ofxPhysicalOfVideoPlayer : public ofxPhysicalObject {
    
public:
    ~ofxPhysicalOfVideoPlayer(){};
    
    void loadMovie(string name){
        movie.loadMovie(name);
    }
    
    void setLoopState(ofLoopType l){
        movie.setLoopState(l);
    }
    
    void update(float dt){
        ofxPhysicalObject::update(dt);
        movie.update();
    }
    
    void draw(){
        ofxPhysicalObject::beginDraw();
        movie.draw(0,0);
        ofxPhysicalObject::endDraw();
    }
    
    void setAnchorPercent(float xPct,float yPct){
        movie.setAnchorPercent(xPct,yPct);
    }
    
    ofVideoPlayer     movie;
};
