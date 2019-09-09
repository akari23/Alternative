#ifndef __MINIGAME_H
#define __MINIGAME_H

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

using namespace cocos2d::ui;
using namespace cocos2d;
using namespace CocosDenshion;

class MiniGame :public Scene
{
private:

public:
	static Scene* scene();
	virtual bool init();
	CREATE_FUNC(MiniGame);

	//fungsi//
	void keluar(Ref* sender);
	/////////
	Sprite* background = Sprite::create("langit.jpg");
	Button* close = Button::create("setting_close.png", "setting_close_tekan.png", "setting_close.png");

	// pilih menu
	Button* minigame1 = Button::create("btn_choose.png", "btn_choose_tekan.png", "btn_choose.png");
	Button* minigame2 = Button::create("btn_choose.png", "btn_choose_tekan.png", "btn_choose.png");
	Button* minigame3 = Button::create("btn_choose.png", "btn_choose_tekan.png", "btn_choose.png");
	Label* label_minigame1 = Label::createWithTTF("TEBAK GAMBAR", "fonts/arial.ttf", 30);
	Label* label_minigame2 = Label::createWithTTF("MENJAWAB", "fonts/arial.ttf", 30);
	Label* label_minigame3 = Label::createWithTTF("PUZZLE", "fonts/arial.ttf", 30);
	void miniGame1(Ref* sender);
	void miniGame2(Ref* sender);
	void miniGame3(Ref* sender);
	int pil_menu;
	//
};

#endif