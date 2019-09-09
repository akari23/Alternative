#ifndef __HIGHSCORE_H
#define __HIGHSCORE_H

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

using namespace cocos2d::ui;
using namespace cocos2d;
using namespace CocosDenshion;

class HighScore :public Scene
{
private:

public:
	static Scene* scene();
	virtual bool init();
	CREATE_FUNC(HighScore);

	//fungsi//
	void keluar(Ref* sender);
	/////////
	Sprite* background = Sprite::create("langit.jpg");
	Button* close = Button::create("setting_close.png", "setting_close_tekan.png", "setting_close.png");

	Label* label_miniGame1 = Label::createWithTTF("Mini Game 1 =", "fonts/arial.ttf", 40);
	Label* label_miniGame2 = Label::createWithTTF("Mini Game 2 =", "fonts/arial.ttf", 40);
	Label* label_miniGame3 = Label::createWithTTF("Mini Game 3 =", "fonts/arial.ttf", 40);

	Label* labelScoreMiniGame1Hard = Label::createWithTTF("Mini Game 1 =", "fonts/arial.ttf", 40);
	Label* labelScoreMiniGame1Medium= Label::createWithTTF("Mini Game 1 =", "fonts/arial.ttf", 40);
	Label* labelScoreMiniGame1Easy = Label::createWithTTF("Mini Game 1 =", "fonts/arial.ttf", 40);

	Label* labelScoreMiniGame2Hard = Label::createWithTTF("Mini Game 2 =", "fonts/arial.ttf", 40);
	Label* labelScoreMiniGame2Medium = Label::createWithTTF("Mini Game 2 =", "fonts/arial.ttf", 40);
	Label* labelScoreMiniGame2Easy = Label::createWithTTF("Mini Game 2 =", "fonts/arial.ttf", 40);

	Label* labelScoreMiniGame3Hard = Label::createWithTTF("Mini Game 1 =", "fonts/arial.ttf", 40);
	Label* labelScoreMiniGame3Medium = Label::createWithTTF("Mini Game 1 =", "fonts/arial.ttf", 40);
	Label* labelScoreMiniGame3Easy = Label::createWithTTF("Mini Game 1 =", "fonts/arial.ttf", 40);
};

#endif