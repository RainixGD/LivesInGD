#pragma once
#include "./includes.h"

class ToggleSprite : public CCNode {
	CCSprite* enabledSprite;
	CCSprite* disabledSprite;
	virtual bool init(const char* enabledTexture, const char* disabledTexture);

public:
	void setActive(bool enabled);
	static ToggleSprite* createWithSpriteFrameName(const char* enabledTexture, const char* disabledTexture);
};