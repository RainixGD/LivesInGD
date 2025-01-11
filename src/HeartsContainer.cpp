#include "./HeartsContainer.h"
#include "./ToggleSprite.h"

bool HeartsContainer::init(int maxCountOfLives, float padding) {
	if (!CCNode::init()) return false;
	if (maxCountOfLives > 0) this->maxCountOfLives = maxCountOfLives;

	for (int i = 0; i < maxCountOfLives; i++) {
		auto heart = ToggleSprite::createWithSpriteFrameName("lifeIcon_full.png"_spr, "lifeIcon_empty.png"_spr);
		heart->setPositionX(i * padding);
		this->addChild(heart);
		heartIcons.push_back(heart);
	}
	return true;
}

void HeartsContainer::update(int activeNumber) {
	if (activeNumber > maxCountOfLives) return;
	for (int i = 0; i < heartIcons.size(); i++) {
		heartIcons[i]->setActive(i < activeNumber);
	}
}

HeartsContainer* HeartsContainer::create(int maxCountOfLives, float padding) {
	auto ret = new HeartsContainer();
	if (ret && ret->init(maxCountOfLives, padding)) {
		ret->autorelease();
		return ret;
	}
	return nullptr;
}