#include "./includes.h"
#include "./LivesManager.h"
#include <Geode/modify/PlayLayer.hpp>

class $modify(PlayLayer) {
	void destroyPlayer(PlayerObject* player, GameObject* obj) {
		if (obj == m_anticheatSpike)
			return PlayLayer::destroyPlayer(player, obj);
		LivesManager::getInstance()->onPlayLayer_destroyPlayer(this, player, obj);
	}

	void postUpdate(float dt) {
		PlayLayer::postUpdate(dt);
		LivesManager::getInstance()->onPlayLayer_postUpdate(this, dt);
	}

	void resetLevel() {
		PlayLayer::resetLevel();
		LivesManager::getInstance()->onPlayLayer_reset();
	}

	bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
		if (!PlayLayer::init(level, useReplay, dontCreateObjects)) return false;
		LivesManager::getInstance()->onPlayLayer_init(this);
		return true;
	}

	void onQuit() {
		PlayLayer::onQuit();
		LivesManager::getInstance()->onPlayLayer_onQuit();
	}
};

$execute{
	LivesManager::getInstance()->maxFramesPerLife = Mod::get()->getSettingValue<int64_t>("frames-per-life");
	LivesManager::getInstance()->startNumberOfLives = Mod::get()->getSettingValue<int64_t>("lives-count");
	LivesManager::getInstance()->soundEffectVolume = Mod::get()->getSettingValue<double>("sound-effect-volume");
	LivesManager::getInstance()->bgPulseOpacity = Mod::get()->getSettingValue<double>("bg-pulse-opacity");
	LivesManager::getInstance()->shake = Mod::get()->getSettingValue<bool>("shake");

	listenForSettingChanges("frames-per-life", [](int64_t value) {
		LivesManager::getInstance()->maxFramesPerLife = value;
	});

	listenForSettingChanges("lives-count", [](int64_t value) {
		LivesManager::getInstance()->startNumberOfLives = value;
	});

	listenForSettingChanges("sound-effect-volume", [](double value) {
		LivesManager::getInstance()->soundEffectVolume = value;
	});

	listenForSettingChanges("bg-pulse-opacity", [](double value) {
		LivesManager::getInstance()->bgPulseOpacity = value;
	});
	
	listenForSettingChanges("shake", [](bool value) {
		LivesManager::getInstance()->shake = value;
	});
}