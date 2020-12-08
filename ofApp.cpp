#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);

	ofTrueTypeFontSettings font_settings("fonts/msgothic.ttc", 22);
	font_settings.antialiased = true;	font_settings.addRanges(ofAlphabet::Japanese);
	this->font.load(font_settings);

	this->words = {

		u8"óÎ", u8"àÎ", u8"ìÛ", u8"éQ", u8"„Ê",
		u8"„Ê", u8"éΩ", u8"éJ", u8"ãË", u8"èE", 
	};
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);

	if (ofGetFrameNum() % 120 < 75) {

		this->noise_param += ofMap(ofGetFrameNum() % 60, 0, 75, 0.04, 0);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {


	for(int x = 100; x <= ofGetWidth() - 100; x += 30){

		for(int y = 100; y <= ofGetHeight() - 100; y += 30){

			auto location = glm::vec2(x, y);
			int noise_value = ofMap(ofNoise(location.x * 0.003, location.y * 0.003, this->noise_param), 0, 1, 0, this->words.size());

			this->font.drawString(this->words[noise_value], x - 11, y + 11);

		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}