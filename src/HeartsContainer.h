#pragma once
#include "./includes.h"

class ToggleSprite;

class HeartsContainer : public CCNode {
	int maxCountOfLives = 3;
	std::vector<ToggleSprite*> heartIcons;
	virtual bool init(int maxCountOfLives, float padding);
public:
	void update(int activeNumber);
	static HeartsContainer* create(int maxCountOfLives, float padding);
};