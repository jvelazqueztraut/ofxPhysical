//
//  ofxPhysicalOfImage.h
//  ofxPhysical
//
//  Created by jvelazqueztraut on 06/05/13.
//
//  masOTROS SRL

#pragma once

#include "ofxPhysicalObject.h"

class ofxPhysicalOfImage : public ofxPhysicalObject {
    
public:
    ~ofxPhysicalImage(){};
    
    void loadImage(string file){
        image.loadImage(file);
    }
    
    void draw(){
        ofxPhysicalObject::beginDraw();
        image.draw(0,0);
        ofxPhysicalObject::endDraw();
    }
    
    void setAnchorPercent(float xPct,float yPct){
        image.setAnchorPercent(xPct,yPct);
    }

    ofImage     image;
};
