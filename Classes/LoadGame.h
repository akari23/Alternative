#ifndef __LOAD_GAME_H__
#define __LOAD_GAME_H__

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

using namespace cocos2d::ui;
using namespace cocos2d;
using namespace CocosDenshion;

class LoadGame :public Scene
{
private:

public:
	static Scene* scene();
	virtual bool init();
	CREATE_FUNC(LoadGame);

	//fungsi//
	void keluar(Ref* sender);
	void save_game_1(Ref* sender);
	void save_game_2(Ref* sender);
	void save_game_3(Ref* sender);
	void save_game_4(Ref* sender);
	void save_game_5(Ref* sender);
	void save_game_6(Ref* sender);
	void nilai_save_game_1();
	void nilai_save_game_2();
	void nilai_save_game_3();
	void nilai_save_game_4();
	void nilai_save_game_5();
	void nilai_save_game_6();
	void teks_save(int teks_ke);
	void Mulai_load();
	/////////



	Sprite* background = Sprite::create("langit.jpg");

	Button* close = Button::create("setting_close.png", "setting_close_tekan.png", "setting_close.png");
	Button* btn_save_1 = Button::create("save_button.png", "save_button_tekan.png", "save_button.png");
	Button* btn_save_2 = Button::create("save_button.png", "save_button_tekan.png", "save_button.png");
	Button* btn_save_3 = Button::create("save_button.png", "save_button_tekan.png", "save_button.png");
	Button* btn_save_4 = Button::create("save_button.png", "save_button_tekan.png", "save_button.png");
	Button* btn_save_5 = Button::create("save_button.png", "save_button_tekan.png", "save_button.png");
	Button* btn_save_6 = Button::create("save_button.png", "save_button_tekan.png", "save_button.png");


	//label save game//
	Label* label_save1 = Label::createWithTTF("", "fonts/arial.ttf", 30);
	Label*label_save2 = Label::createWithTTF("", "fonts/arial.ttf", 30);
	Label* label_save3 = Label::createWithTTF("", "fonts/arial.ttf", 30);
	Label* label_save4 = Label::createWithTTF("", "fonts/arial.ttf", 30);
	Label* label_save5 = Label::createWithTTF("", "fonts/arial.ttf", 30);
	Label* label_save6 = Label::createWithTTF("", "fonts/arial.ttf", 30);
	//////////////////

	int i = 0;
	const char* teks;
};

#endif