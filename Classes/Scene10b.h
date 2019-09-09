#ifndef __SCENE_10_b_H__
#define __SCENE_10_b_H__

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

using namespace cocos2d::ui;
using namespace cocos2d;
using namespace CocosDenshion;

class Scene10b :public Scene
{
private:

public:

	SimpleAudioEngine* bgm = SimpleAudioEngine::getInstance();


	//fungsi lain//
	void quit_game(Ref* sender);
	void quit_yes(Ref* sender);
	void quit_no(Ref* sender);
	void startGame(Ref* sender);
	void pil_menu(Ref* sender);
	void close_menu(Ref* sender);
	void back_title(Ref* sender);
	void config(Ref* sender);
	void save_game(Ref* sender);
	void load_game(Ref* sender);
	void isi_teks();
	/////////

	//fungsi nama//
	void rei();
	void anna();
	void nana();
	void nama_kosong();
	void nama_titik();
	void wali();
	//////////////

	//bagian quit ke title//
	Label* label_quit = Label::createWithTTF("QUIT", "fonts/arial.ttf", 20);
	Label* label_quit_yes = Label::createWithTTF("YES", "fonts/arial.ttf", 20);
	Label* label_quit_no = Label::createWithTTF("NO", "fonts/arial.ttf", 20);
	Sprite* bg_exit = Sprite::create("bg_exit.png");
	Button* btn_exit_no = Button::create("btn_exit_awal.png", "btn_exit_tekan.png", "btn_exit_awal.png");
	Button* btn_exit_yes = Button::create("btn_exit_awal.png", "btn_exit_tekan.png", "btn_exit_awal.png");
	Button* kosong = Button::create("kosong.png", "kosong.png", "kosong.png");
	////////////////////////

	//fungsi teks//
	void teks_satu();
	/////////////

	//gambar karakter//
	Sprite* anna_sprite = Sprite::create("character/anna/A1.png");
	Sprite* nana_sprite = Sprite::create("character/nana/1.png");
	///////////////////

	//gambar karakter hiden//
	void hiden_character();
	////////////////////////

	//background latar//
	Sprite* background = Sprite::create("bg/kamar_nana.jpg");
	///////////////////


	static Scene* scene();
	virtual bool init();
	CREATE_FUNC(Scene10b);

	void teksJalan(float dt);
	void delay_game(float dt);
	void delay(float dt);
	int i = 0;
	int detik = 0;
	
	Label* teks_1 = Label::createWithTTF("", "fonts/arial.ttf", 30);	
	Label* nama = Label::createWithTTF("", "fonts/arial.ttf", 30);

	//bagian button buat menu//
	Button* btn_menu = Button::create("btn_menu_awal.png", "btn_menu_tekan.png", "btn_menu_awal.png");
	Button* btn_tittle = Button::create("ButtonMenu/btn_title_awal.png", "ButtonMenu/btn_title_tekan.png", "ButtonMenu/btn_title_awal.png");
	Button* btn_load = Button::create("ButtonMenu/btn_load_awal.png", "ButtonMenu/btn_load_tekan.png", "ButtonMenu/btn_load_awal.png");
	Button* btn_save = Button::create("ButtonMenu/btn_save_awal.png", "ButtonMenu/btn_save_tekan.png", "ButtonMenu/btn_save_awal.png");
	Button* btn_config = Button::create("ButtonMenu/btn_config_awal.png", "ButtonMenu/btn_config_tekan.png", "ButtonMenu/btn_config_awal.png");
	Button* btn_close = Button::create("ButtonMenu/btn_close_awal.png", "ButtonMenu/btn_close_tekan.png", "ButtonMenu/btn_close_awal.png");
	Sprite* bg_menu_btn = Sprite::create("ButtonMenu/bg_menu.png");
	///////////////////////////

	//bagian milih jawaban//
	Sprite* bg_choose = Sprite::create("bg_choose.png");
	Button* bg_kosong = Button::create("kosong.png", "kosong.png", "kosong.png");
	Button* btn_choose_left = Button::create("btn_choose.png","btn_choose_tekan.png","btn_choose.png");
	Button* btn_choose_right = Button::create("btn_choose.png", "btn_choose_tekan.png", "btn_choose.png");
	void choose_left(Ref* sender);
	void choose_right(Ref* sender);
	Label* label_choose_left = Label::createWithTTF("Mengajak Nana berkeliling","fonts/arial.ttf", 20);
	Label* label_choose_right= Label::createWithTTF("Pulang", "fonts/arial.ttf", 20);
	///////////////////////

	Button* buttonStart = Button::create("background_teks.png", "background_teks.png", "background_teks.png");

	
	const char* teks;
};

#endif