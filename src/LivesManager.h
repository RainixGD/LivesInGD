#pragma once
#include "./includes.h"

class PulsingBG;
class HeartsContainer;

class LivesManager {
	HeartsContainer* heartsNode;
	PulsingBG* pulseBG;
	bool isDead = false;
	int countOfFramesPlayerWasDead = 0;

	int livesLeft = 3;

	static LivesManager* instance;

public:
	int startNumberOfLives = 5;
	int maxFramesPerLife = 250;
	float soundEffectVolume = 100;
	float bgPulseOpacity = 150;
	bool shake = true;

	void updateUI();

	void onPlayLayer_destroyPlayer(PlayLayer* pl, PlayerObject* player, GameObject* obj);
	void onPlayLayer_postUpdate(PlayLayer* pl, float dt);
	void onPlayLayer_reset();
	void onPlayLayer_init(PlayLayer* pl);
	void onPlayLayer_onQuit();

	static LivesManager* getInstance();
};