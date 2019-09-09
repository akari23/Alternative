#ifndef __CREDIT_H_
#define __CREDIT_H_

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

using namespace cocos2d::ui;
using namespace cocos2d;
using namespace CocosDenshion;

class Credit :public Scene
{
private:

public:
	static Scene* scene();
	virtual bool init();
	CREATE_FUNC(Credit);

	//fungsi//
	void keluar(Ref* sender);
	/////////
	Sprite* background = Sprite::create("credit.png");
	Button* close = Button::create("setting_close.png", "setting_close_tekan.png", "setting_close.png");
};

#endif