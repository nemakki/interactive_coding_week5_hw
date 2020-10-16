#pragma once


#include "ofMain.h"
#include "hanabi.h"

class ofApp : public ofBaseApp
{

public:
	void setup() override;
	void update() override;
	void draw() override;

	ofImage figure;

	//ofPoint points[4];
	//int cornerIndex = 0;

	ofImage hanabi;
	ofImage beach;
	ofImage shade;


	float xPosition[300];
	float yPosition[300];
	int flakeSize[300];
	int direction[300];
	int minFlakeSize = 1;
	int maxFlakeSize = 5;

	float a = 0;
	float b = 0;

	void makeParticle(float x, float y);
	std::vector<Hanabi> spark;
};
