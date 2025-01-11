#include "./ToggleSprite.h"

bool ToggleSprite::init(const char* enabledTexture, const char* disabledTexture) {
	if (!CCNode::init()) return false;

	enabledSprite = CCSprite::createWithSpriteFrameName(enabledTexture);
	disabledSprite = CCSprite::createWithSpriteFrameName(disabledTexture);

	if (!enabledSprite || !disabledSprite) return false;

	enabledSprite->setVisible(0);
	disabledSprite->setVisible(0);
	this->addChild(enabledSprite);
	this->addChild(disabledSprite);

	return true;
}


void ToggleSprite::setActive(bool enabled) {
	if (enabled) {
		enabledSprite->setVisible(1);
		disabledSprite->setVisible(0);
	}
	else {
		enabledSprite->setVisible(0);
		disabledSprite->setVisible(1);
	}
}

ToggleSprite* ToggleSprite::createWithSpriteFrameName(const char* enabledTexture, const char* disabledTexture) {
	auto ret = new ToggleSprite();
	if (ret && ret->init(enabledTexture, disabledTexture)) {
		ret->autorelease();
		return ret;
	}
	return nullptr;
}