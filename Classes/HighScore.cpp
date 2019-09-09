#include "HighScore.h"
#include "Option.h"
#include "HomeMenu.h"

USING_NS_CC;

Scene* HighScore::scene()
{
	return HighScore::create();
}

bool HighScore::init()
{
	if (!Scene::init())
	{
		return false;
	}
	UserDefault::getInstance()->getFloatForKey("ScoreMiniGame1Hard");
	UserDefault::getInstance()->getFloatForKey("ScoreMiniGame1Medium");
	UserDefault::getInstance()->getFloatForKey("ScoreMiniGame1Easy");
	UserDefault::getInstance()->getFloatForKey("ScoreMiniGame2Hard");
	UserDefault::getInstance()->getFloatForKey("ScoreMiniGame2Medium");
	UserDefault::getInstance()->getFloatForKey("ScoreMiniGame2Easy");
	UserDefault::getInstance()->getFloatForKey("ScoreMiniGame3Hard");
	UserDefault::getInstance()->getFloatForKey("ScoreMiniGame3Medium");
	UserDefault::getInstance()->getFloatForKey("ScoreMiniGame3Easy");
	log("Nilai score hard = %.2f", UserDefault::getInstance()->getFloatForKey("ScoreMiniGame1Hard"));
	log("Nilai score medium = %.2f", UserDefault::getInstance()->getFloatForKey("ScoreMiniGame1Medium"));
	log("Nilai score easy = %.2f", UserDefault::getInstance()->getFloatForKey("ScoreMiniGame1Easy"));

	background->setAnchorPoint(Vec2(0, 0));
	background->setPosition(Vec2(0, 0));
	this->addChild(background,0);

	close->setAnchorPoint(Vec2(1, 1));
	close->setScale(0.8);
	close->setPosition(Vec2(1360, 760));
	this->addChild(close, 1);

	auto label_highscore = Label::createWithTTF("HIGH SCORE", "fonts/arial.ttf", 50);
	auto label_hard = Label::createWithTTF("HARD", "fonts/arial.ttf", 40);
	auto label_medium = Label::createWithTTF("MEDIUM", "fonts/arial.ttf", 40);
	auto label_easy = Label::createWithTTF("EASY", "fonts/arial.ttf", 40);
	label_highscore->setPosition(Vec2(200, 700));
	label_hard->setPosition(Vec2(1366 / 2 - 300, 520));
	label_medium->setPosition(Vec2(1366 / 2+70 , 520));
	label_easy->setPosition(Vec2(1366 / 2 + 420, 520));
	label_miniGame1->setPosition(Vec2(150, 400));
	label_miniGame2->setPosition(Vec2(150, 250));
	label_miniGame3->setPosition(Vec2(150, 100));
	labelScoreMiniGame1Hard->setPosition(Vec2(1366 / 2 - 300, 400));
	labelScoreMiniGame1Medium->setPosition(Vec2(1366 / 2 + 70, 400));
	labelScoreMiniGame1Easy->setPosition(Vec2(1366 / 2 + 420, 400));
	labelScoreMiniGame2Hard->setPosition(Vec2(1366 / 2 - 300, 250));
	labelScoreMiniGame2Medium->setPosition(Vec2(1366 / 2 + 70, 250));
	labelScoreMiniGame2Easy->setPosition(Vec2(1366 / 2 + 420, 250));
	labelScoreMiniGame3Hard->setPosition(Vec2(1366 / 2 - 300, 100));
	labelScoreMiniGame3Medium->setPosition(Vec2(1366 / 2 + 70, 100));
	labelScoreMiniGame3Easy->setPosition(Vec2(1366 / 2 + 420, 100));
	this->addChild(label_highscore);
	this->addChild(label_miniGame1);
	this->addChild(label_miniGame2);
	this->addChild(label_miniGame3);
	this->addChild(label_hard);
	this->addChild(label_medium);
	this->addChild(label_easy);
	this->addChild(labelScoreMiniGame1Hard);
	this->addChild(labelScoreMiniGame1Medium);
	this->addChild(labelScoreMiniGame1Easy);
	this->addChild(labelScoreMiniGame2Hard);
	this->addChild(labelScoreMiniGame2Medium);
	this->addChild(labelScoreMiniGame2Easy);
	this->addChild(labelScoreMiniGame3Hard);
	this->addChild(labelScoreMiniGame3Medium);
	this->addChild(labelScoreMiniGame3Easy);

	labelScoreMiniGame1Easy->setString(__String::createWithFormat("%.2f",UserDefault::getInstance()->getFloatForKey("ScoreMiniGame1Easy"))->getCString());
	labelScoreMiniGame1Medium->setString(__String::createWithFormat("%.2f", UserDefault::getInstance()->getFloatForKey("ScoreMiniGame1Medium"))->getCString());
	labelScoreMiniGame1Hard->setString(__String::createWithFormat("%.2f", UserDefault::getInstance()->getFloatForKey("ScoreMiniGame1Hard"))->getCString());
	labelScoreMiniGame2Easy->setString(__String::createWithFormat("%.2f", UserDefault::getInstance()->getFloatForKey("ScoreMiniGame3Easy"))->getCString());
	labelScoreMiniGame2Medium->setString(__String::createWithFormat("%.2f", UserDefault::getInstance()->getFloatForKey("ScoreMiniGame3Medium"))->getCString());
	labelScoreMiniGame2Hard->setString(__String::createWithFormat("%.2f", UserDefault::getInstance()->getFloatForKey("ScoreMiniGame3Hard"))->getCString());
	labelScoreMiniGame3Easy->setString(__String::createWithFormat("%.2f", UserDefault::getInstance()->getFloatForKey("ScoreMiniGame2Easy"))->getCString());
	labelScoreMiniGame3Medium->setString(__String::createWithFormat("%.2f", UserDefault::getInstance()->getFloatForKey("ScoreMiniGame2Medium"))->getCString());
	labelScoreMiniGame3Hard->setString(__String::createWithFormat("%.2f", UserDefault::getInstance()->getFloatForKey("ScoreMiniGame2Hard"))->getCString());
	close->addClickEventListener(CC_CALLBACK_1(HighScore::keluar, this));

	return true;
}

void HighScore::keluar(Ref* sender)
{
	HomeMenu::btn_sound();

	Director::getInstance()->popScene();
}
