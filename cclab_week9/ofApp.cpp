#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255,255,255);
    
    // set initial circle radius
    mCircleRadius = 20;
    
    nCircleRadius = 20;
    
    // set initial position
    mPos = ofVec2f(ofGetWindowWidth() * 0.5,
        ofGetWindowHeight() * 0.5);
    
    //set friction
    mFriction = 0.993;
    
    //no velocity at the beginning
    mVelocity = ofVec2f(0);
    
    //no force at beginning
    mAcceleration = ofVec2f(0);
    
    nPos = ofVec2f(ofRandomWidth(),ofRandomHeight());
    
}

//--------------------------------------------------------------
void ofApp::update(){
   
    
    // reduce velocity according to friction
    if(mVelocity.length()>0){
        mVelocity *= ofVec2f(mFriction);
        
        //When velocity is too small,  we don't want to update our velocity
        if (mVelocity.length()<MIN_VELOCITY){
            mVelocity = ofVec2f(0);
        }
    }
    
    // update position of ball according to velocity
    if (mVelocity.length()>0){
        mPos += mVelocity;
        

    
        }
    

    
    if(nPos.x>mPos.x-mCircleRadius && nPos.x<mPos.x+mCircleRadius && nPos.y>mPos.y-mCircleRadius && nPos.y<mPos.y+mCircleRadius && !random_update){
        nPos = ofVec2f(ofRandomWidth(),ofRandomHeight());
        random_update = 1;
        mCircleRadius = mCircleRadius+5;
    }
    
    else {
        random_update = 0;
    }
    
  
    if(mPos.x-mCircleRadius<0 || mPos.x+mCircleRadius>ofGetWindowWidth() || mPos.y-mCircleRadius<0 || mPos.y+mCircleRadius>ofGetWindowHeight()){
        
        ggRadius = 500;
        color =255;
        op = 255;
    }else{
        ggRadius = 0;
        op = 0;
    }

    


}

//--------------------------------------------------------------
void ofApp::draw(){

    
    
    ofSetColor(255, 204, 41);
    ofSetCircleResolution(50);
    ofDrawCircle(nPos, nCircleRadius);
    
    
    
    ofSetColor(68,68,68);
    ofDrawBitmapString("Score:" + ofToString((mCircleRadius-20)*2) ,ofVec2f(900,30));
    cout << nPos << endl;
    
    ofSetColor(255, 66, 8);
    ofSetCircleResolution(50);
    ofDrawCircle(mPos, mCircleRadius);
    


    ofSetColor(0,0,0);
    ofSetCircleResolution(50);
    ofDrawCircle(ofGetWindowWidth()*0.5,ofGetWindowHeight()*0.5, ggRadius, ggRadius);
    ofSetColor(color,color,color,op);
    ofDrawBitmapString("GAME OVER",ofVec2f(ofGetWindowWidth()*0.5-30,ofGetWindowHeight()*0.5-30));

    
    ofSetColor(color,color,color,op);
    ofDrawBitmapString("SCORE:"+ofToString((mCircleRadius-20)*2),ofVec2f(ofGetWindowWidth()*0.5-30,ofGetWindowHeight()*0.5-10));

    
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x,int y,int button){
    // put mouse position into a vector, local variable
    ofVec2f mousePos = ofVec2f(x,y);
    
    //calculate acceleration
    mAcceleration = mPos - mousePos;

    //normalize acceleration
    mAcceleration = mAcceleration.getNormalized();
    
    // apply acceleration (direction) to velocity
    mVelocity += mAcceleration;
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
