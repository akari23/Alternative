#ifndef __HOME_MENU_H__
#define __HOME_MENU_H__

#include "Scene1.h"
#include "Option.h"

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;


using namespace cocos2d::ui;
using namespace cocos2d;
using namespace CocosDenshion;

class HomeMenu :public Scene
{
private:

public:

SimpleAudioEngine* bgm = SimpleAudioEngine::getInstance();
SimpleAudioEngine* sfx = SimpleAudioEngine::getInstance();
	//fungsi//
	void startGame(Ref* sender);
	void loadGame(Ref* sender);
	void optionGame(Ref* sender);
	void creditGame(Ref* sender);
	void rateGame(Ref* sender);
	void quitGame(Ref* sender);
	void quit_yes(Ref* sender);
	void quit_no(Ref* sender);
	void miniGame(Ref* sender);
	void highScore(Ref* sender);

	static void btn_sound();
	static void bgm_home_volume();
	//////////

	static Scene* scene();
	virtual bool init();
	CREATE_FUNC(HomeMenu);

	Sprite* logo = Sprite::create("polines.png");
	Sprite* judul = Sprite::create("judul5.png");
	Sprite* background = Sprite::create("background2.jpg");
	Sprite* bg_exit = Sprite::create("bg_exit.png");
	Button* btn_exit_no= Button::create("btn_exit_awal.png", "btn_exit_tekan.png","btn_exit_awal.png");
	Button* btn_exit_yes = Button::create("btn_exit_awal.png", "btn_exit_tekan.png", "btn_exit_awal.png");
	Button* kosong = Button::create("kosong.png","kosong.png","kosong.png");

	Button* buttonStart = Button::create("button_awal.png", "button_akhir.png", "button_awal.png");
	Button* buttonStart1 = Button::create("button_awal.png", "button_akhir.png", "button_awal.png");
	Button* buttonStart2 = Button::create("button_awal.png", "button_akhir.png", "button_awal.png");
	Button* buttonStart3 = Button::create("button_awal.png", "button_akhir.png", "button_awal.png");
	Button* buttonStart4 = Button::create("button_awal.png", "button_akhir.png", "button_awal.png");
	Button* buttonStart5 = Button::create("button_awal.png", "button_akhir.png", "button_awal.png");
	Button* buttonHighScore = Button::create("button_awal.png", "button_akhir.png", "button_awal.png");
	Button* buttonMiniGame = Button::create("button_awal.png", "button_akhir.png", "button_awal.png");


	Label* label_start = Label::createWithTTF("START", "fonts/arial.ttf", 20);
	Label* label_load = Label::createWithTTF("LOAD", "fonts/arial.ttf", 20);
	Label* label_setting = Label::createWithTTF("SETTING", "fonts/arial.ttf", 20);
	Label* label_credit = Label::createWithTTF("CREDIT", "fonts/arial.ttf", 20);
	Label* label_rate = Label::createWithTTF("RATE", "fonts/arial.ttf", 20);
	Label* label_quit = Label::createWithTTF("QUIT", "fonts/arial.ttf", 20);
	Label* label_quit_yes = Label::createWithTTF("YES", "fonts/arial.ttf", 20);
	Label* label_quit_no= Label::createWithTTF("NO", "fonts/arial.ttf", 20);
	Label* label_highScore = Label::createWithTTF("High Score", "fonts/arial.ttf", 20);
	Label* label_miniGame = Label::createWithTTF("Mini Game", "fonts/arial.ttf", 20);

	void jadwalLogo(float dt);
	void judulTampil(float dt);
	int waktu = 5;
	int nilaiJudul = 0;
	static bool nilai_logo;

	static int game;
	static int nilai_teks;
	static bool load_game;
};


#endif