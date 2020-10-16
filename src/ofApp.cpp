#include "ofApp.h"


void ofApp::setup()
{
	//ofLoadImage(figure, "figure.png");

	//points[0].x = 0;
	//points[0].y = 0;
	//points[1].x = 240;
	//points[1].y = 0;
	//points[2].x = 240;
	//points[2].y = 160;
	//points[3].x = 0;
	//points[3].y = 160;
	figure.load("4xfigure.png");
	hanabi.load("4xhanabi.png");
	beach.load("4xbeach.png");
	shade.load("shade.png");

	ofSetFrameRate(30);

	for (int i = 0; i < 300; i++) {
		flakeSize[i] = round(ofRandom(minFlakeSize, maxFlakeSize));
		xPosition[i] = ofRandom(0, ofGetWidth());
		yPosition[i] = ofRandom(0, ofGetHeight());
		direction[i] = round(ofRandom(0, 1));
	}

}


void ofApp::update()
{
	for (auto& particle : spark)
	{
		particle.acceleration = { 0, .08 };
		particle.update();
	}


	auto iter = spark.begin();
	while (iter != spark.end())
	{
		if (iter->isDead())
		{
			// erase a particle
			iter = spark.erase(iter);
		}
		else
		{
			iter++;
		}
	}


		makeParticle(540, 300);
	


}


void ofApp::draw()
{
	ofBackground(38);
	
		
		beach.draw(0, 0);
		figure.draw(0, 0);
		hanabi.draw(0, 0);
		
		//wave		
		
		for (int j = 0; j < ofGetWidth(); j+=2) {

			ofSetColor(207, 241, 255);
			float n = ofNoise(j / 600.0, b / 150.0);
			n = ofMap(n, 0, 1, ofGetHeight() * 2 / 3.0, ofGetHeight());
			ofDrawLine(j, ofGetHeight(), j, n - 1);

		}

		b += 0.5;

		for (int j = 0; j < ofGetWidth(); j++) {

			ofSetColor(120, 139, 245);
			float n = ofNoise(j / 800.0, a / 150.0);
			n = ofMap(n, 0, 1, ofGetHeight() * 2 / 3.0, ofGetHeight());
			ofDrawLine(j, ofGetHeight(), j, n - 1);

		}

		a += 0.5;



		ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
		shade.draw(0, 0);
		ofEnableBlendMode(OF_BLENDMODE_ALPHA);

		ofEnableBlendMode(OF_BLENDMODE_ADD);
		for (auto& particle : spark)
		{
			particle.draw();
		}
		ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	
	//snow

	for (int i = 0; i < 300; i++) {
		
		ofSetColor(ofColor::white);
		ofDrawEllipse(xPosition[i], yPosition[i], flakeSize[i], flakeSize[i]);

		if (direction[i] == 0) {
			xPosition[i] += ofMap(flakeSize[i], minFlakeSize, maxFlakeSize, .1, .5);
		}
		else {
			xPosition[i] -= ofMap(flakeSize[i], minFlakeSize, maxFlakeSize, .1, .5);
		}

		yPosition[i] += flakeSize[i] + direction[i];

		if (xPosition[i] > ofGetWidth() + flakeSize[i] || xPosition[i] < -flakeSize[i] || yPosition[i] > ofGetHeight() + flakeSize[i]) {
			xPosition[i] = ofRandom(0, ofGetWidth());
			yPosition[i] = -flakeSize[i];
		}

	}






}

void ofApp::makeParticle(float x, float y)
{
	Hanabi p;
	p.position = { x, y };
	p.velocity = { ofRandom(-2, 2), ofRandom(-2, 2) };

	spark.push_back(p);
}
