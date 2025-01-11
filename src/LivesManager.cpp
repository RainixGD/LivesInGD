#include "./LivesManager.h"
#include "./HeartsContainer.h"
#include "./PulsingBG.h"

void LivesManager::updateUI() {
	if (heartsNode) {
		heartsNode->update(livesLeft);
	}
}

void LivesManager::onPlayLayer_destroyPlayer(PlayLayer* pl, PlayerObject* player, GameObject* obj) {
	isDead = true;

	if (livesLeft <= 0)
		pl->destroyPlayer(player, obj);
}

void LivesManager::onPlayLayer_postUpdate(PlayLayer* pl, float dt) {
	
	if (isDead) {
		if (countOfFramesPlayerWasDead == 0) {
			livesLeft--;
			updateUI();
			if (pulseBG)
				pulseBG->pulse();
			if (shake)
				pl->shakeCamera(0.15, 5, 0.01);
			FMODAudioEngine::sharedEngine()->playEffect("sound.mp3"_spr, 1.f, 1.f, soundEffectVolume / 100.f);
		}
		countOfFramesPlayerWasDead++;
		if (countOfFramesPlayerWasDead > maxFramesPerLife) {
			countOfFramesPlayerWasDead = 0;
		}
	}
	else {
		countOfFramesPlayerWasDead = 0;
	}

	if (livesLeft <= 0)
		pl->destroyPlayer(pl->m_player1, nullptr);

	isDead = false;
}

void LivesManager::onPlayLayer_reset() {
	livesLeft = startNumberOfLives;
	countOfFramesPlayerWasDead = 0;
	updateUI();
}

void LivesManager::onPlayLayer_init(PlayLayer* pl) {
	auto size = CCDirector::sharedDirector()->getWinSize();

	heartsNode = HeartsContainer::create(startNumberOfLives, 30.f);
	heartsNode->setZOrder(150);
	heartsNode->setPosition(25, size.height - 25);
	pl->addChild(heartsNode);

	pulseBG = PulsingBG::create(ccc4(255, 0, 0, 255), bgPulseOpacity);
	pulseBG->setZOrder(151);
	pl->addChild(pulseBG);

	updateUI();
}

void LivesManager::onPlayLayer_onQuit() {
	heartsNode = nullptr;
	pulseBG = nullptr;
}

LivesManager* LivesManager::getInstance() {
	if (!instance) {
		instance = new LivesManager();
	}
	return instance;
}

LivesManager* LivesManager::instance = nullptr;