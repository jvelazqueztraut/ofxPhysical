//
//  ofxPhysicalOfObject.cpp
//  ofxPhysical
//
//  Created by jvelazqueztraut on 06/05/13.
//
//  masOTROS SRL

#include "ofxPhysicalObject.h"

ofxPhysicalObject::ofxPhysicalObject(){
    size.reset(1.);
    color.setColor(ofColor(255));
    position.setPosition(ofPoint(0.,0.,0.));
    rotation.setPosition(ofPoint(0.,0.,0.));
}

void ofxPhysicalObject::update(float dt){
    size.update(dt);
    color.update(dt);
    position.update(dt);
    rotation.update(dt);
}

void ofxPhysicalObject::beginDraw(){
    ofPushMatrix();
    ofPushStyle();
    ofTranslate(position.getCurrentPosition());
    ofRotateX(rotation.getCurrentPosition().x);
    ofRotateY(rotation.getCurrentPosition().y);
    ofRotateZ(rotation.getCurrentPosition().z);
    if(size.val()<0) ofScale(0.,0.,0.);
    else ofScale(size.val(),size.val(),size.val());
    ofSetColor(color.getCurrentColor());
}

void ofxPhysicalObject::endDraw(){
    ofPopStyle();
    ofPopMatrix();
}

void ofxPhysicalObject::setPosition(ofPoint p){
    position.setPosition(p);
}
void ofxPhysicalObject::setPosition(float x, float y,float z){
    setPosition(ofPoint(x,y,z));
}
void ofxPhysicalObject::setSize(float s){
    size.reset(s);
}

void ofxPhysicalObject::setColor(ofColor c){
    color.setColor(c);
}
void ofxPhysicalObject::setColor(int r, int g, int b, int a){
    setColor(ofColor(r,g,b,a));
}
void ofxPhysicalObject::setColor(int b, int a){
    setColor(ofColor(b,a));
}
void ofxPhysicalObject::setColor(int b){
    setColor(ofColor(b));
}
void ofxPhysicalObject::setRotation(ofPoint r){
    rotation.setPosition(r);
}
void ofxPhysicalObject::setRotation(float x, float y, float z){
    setRotation(ofPoint(x,y,z));
}

bool ofxPhysicalObject::isOrWillBeAnimating(){
    return (position.isOrWillBeAnimating() || size.isOrWillBeAnimating() || color.isOrWillBeAnimating() || rotation.isOrWillBeAnimating());
}

