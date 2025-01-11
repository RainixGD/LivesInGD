#include "./PulsingBG.h"

bool PulsingBG::init(const ccColor4B& color, float maxOpacity) {
	if (!CCLayerColor::initWithColor(color)) return false;
	this->setOpacity(0);
	this->maxOpacity = maxOpacity;
	return true;
}

void PulsingBG::pulse() {
	auto first = CCFadeTo::create(0.15f, static_cast<GLubyte>(maxOpacity));
	auto second = CCFadeTo::create(0.15f, 0);

	auto pulseAction = CCSequence::createWithTwoActions(first, second);

	this->runAction(pulseAction);
}

void PulsingBG::updateMaxOpacity(float maxOpacity) {
	this->maxOpacity = maxOpacity;
}

PulsingBG* PulsingBG::create(const ccColor4B& color, float maxOpacity) {
	auto ret = new PulsingBG();
	if (ret && ret->init(color, maxOpacity)) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}