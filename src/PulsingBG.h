#pragma once
#include "./includes.h"

class PulsingBG : public CCLayerColor {
	float maxOpacity;
	virtual bool init(const ccColor4B& color, float maxOpacity);
public:
	void pulse();
	void updateMaxOpacity(float maxOpacity);
	static PulsingBG* create(const ccColor4B& color, float maxOpacity);
};