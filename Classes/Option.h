#ifndef __OPTION_H__
#define __OPTION_H__


#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;


using namespace cocos2d::ui;
using namespace cocos2d;
using namespace CocosDenshion;

class Option :public Scene
{
private:
	
public:

	static float volume_suara;
	static float volume_sfx;
	static float speed_teks;
	static float speed_teks_nilai;
	static bool screen;

	void keluar(Ref* sender);
	void bgm_down(Ref* sender);
	void bgm_up(Ref* sender);
	void sfx_down(Ref* sender);
	void sfx_up(Ref* sender);
	void speed_down(Ref* sender);
	void speed_up(Ref* sender);
	void fullscreen(Ref* sender);

	Label* label_volume = Label::createWithTTF("", "fonts/arial.ttf", 50);
	Label* label_sfx = Label::createWithTTF("", "fonts/arial.ttf", 50);
	Label* label_speed= Label::createWithTTF("", "fonts/arial.ttf", 50);

	Sprite* background = Sprite::create("langit.jpg");
	Sprite* background_tengah = Sprite::create("background_setting_1.png");

	Button* close = Button::create("setting_close.png", "setting_close_tekan.png", "setting_close.png");

	Button* volume_bgm_pluss = Button::create("pluss_awal.png", "pluss_tekan.png", "pluss_awal.png");
	Button* volume_bgm_minus = Button::create("minus_awal.png", "minus_tekan.png", "minus_awal.png");
	Button* volume_sfx_pluss = Button::create("pluss_awal.png", "pluss_tekan.png", "pluss_awal.png");
	Button* volume_sfx_minus = Button::create("minus_awal.png", "minus_tekan.png", "minus_awal.png");
	Button* speed_pluss = Button::create("pluss_awal.png", "pluss_tekan.png", "pluss_awal.png");
	Button* speed_minus = Button::create("minus_awal.png", "minus_tekan.png", "minus_awal.png");
	Button* btn_screen = Button::create("uncheck.png", "uncheck.png", "uncheck.png");
	static Scene* scene();
	virtual bool init();
	CREATE_FUNC(Option);
};

#endif