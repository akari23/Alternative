#include "MiniGame.h"
#include "HomeMenu.h"
#include "MiniGame1.h"
#include "MiniGame2.h"
#include "MiniGame3.h"

USING_NS_CC;

Scene* MiniGame::scene()
{
	return MiniGame::create();
}

bool MiniGame::init()
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


	close->addClickEventListener(CC_CALLBACK_1(MiniGame::keluar, this));
	label_minigame1->setPosition(Vec2(minigame1->getContentSize().width / 2, minigame1->getContentSize().height / 2));
	label_minigame2->setPosition(Vec2(minigame2->getContentSize().width / 2, minigame1->getContentSize().height / 2));
	label_minigame3->setPosition(Vec2(minigame3->getContentSize().width / 2, minigame1->getContentSize().height / 2));
	minigame1->setPosition(Vec2(1366 / 2, 550));
	minigame2->setPosition(Vec2(1366 / 2, 400));
	minigame3->setPosition(Vec2(1366 / 2, 250));
	this->addChild(minigame1, 1);
	this->addChild(minigame2, 1);
	this->addChild(minigame3, 1);
	minigame1->addChild(label_minigame1);
	minigame2->addChild(label_minigame2);
	minigame3->addChild(label_minigame3);
	minigame1->addClickEventListener(CC_CALLBACK_1(MiniGame::miniGame1, this));
	minigame2->addClickEventListener(CC_CALLBACK_1(MiniGame::miniGame2, this));
	minigame3->addClickEventListener(CC_CALLBACK_1(MiniGame::miniGame3, this));
	return true;
}

void MiniGame::keluar(Ref* sender)
{
	HomeMenu::btn_sound();

	Director::getInstance()->popScene();
}
void MiniGame::miniGame1(Ref* sender)
{
	HomeMenu::btn_sound();

	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		Director::getInstance()->replaceScene(TransitionFade::create(1, MiniGame1::scene(), Color3B(255, 255, 255)));
	})));
}
void MiniGame::miniGame2(Ref* sender)
{
	HomeMenu::btn_sound();

	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		Director::getInstance()->replaceScene(TransitionFade::create(1, MiniGame3::createScene(), Color3B(255, 255, 255)));
	})));
}
void MiniGame::miniGame3(Ref* sender)
{
	HomeMenu::btn_sound();

	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		Director::getInstance()->replaceScene(TransitionFade::create(1, MiniGame2::createScene(), Color3B(255, 255, 255)));
	})));
}
