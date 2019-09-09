#include "Credit.h"
#include "Option.h"
#include "HomeMenu.h"

USING_NS_CC;

Scene* Credit::scene()
{
	return Credit::create();
}

bool Credit::init()
{
	if (!Scene::init())
	{
		return false;
	}


	background->setAnchorPoint(Vec2(0, 0));
	background->setPosition(Vec2(0, 0));
	this->addChild(background,0);

	close->setAnchorPoint(Vec2(1, 1));
	close->setPosition(Vec2(1360, 760));
	this->addChild(close, 1);


	close->addClickEventListener(CC_CALLBACK_1(Credit::keluar, this));

	return true;
}

void Credit::keluar(Ref* sender)
{
	HomeMenu::btn_sound();

	Director::getInstance()->popScene();
}
