#include "ofApp.h"


int main()
{
	ofSetupOpenGL(960, 640, OF_WINDOW);
	return ofRunApp(std::make_shared<ofApp>());
}
