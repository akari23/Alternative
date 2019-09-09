#ifndef __MINIGAME_3_H__
#define __MINIGAME_3_H__
#include "cocos2d.h"
#include "ui\CocosGUI.h"
USING_NS_CC;

using namespace cocos2d::ui;
using namespace cocos2d;

class MiniGame3 : public cocos2d::Scene
{
public:
	static Scene* createScene();

	virtual bool init();
	void random_soal();
	void Selesai();
	void submit_function(Ref* sender);
	// a selector callback


	// implement the "static create()" method manually
	CREATE_FUNC(MiniGame3);


	TextField* teksfield = TextField::create("Input here", "fonts/arial.ttf", 30);
	Sprite* background = Sprite::create("MiniGame3/background.jpg");
	Sprite* background_jawaban = Sprite::create("MiniGame3/btn_tekan.png");
	Button* submit = Button::create("MiniGame3/btn.png", "MiniGame3/btn_tekan.png", "MiniGame3/btn.png");

	Label* soal = Label::createWithTTF("SOAL", "fonts/arial.ttf", 35);
	Label* string_jawaban = Label::createWithTTF("JAWABAN", "fonts/arial.ttf", 35);
	int nilai;
	bool bool_soal1 = true;
	bool bool_soal2 = true;
	bool bool_soal3 = true;
	bool bool_soal4 = true;
	bool bool_soal5 = true;
	bool bool_soal6 = true;
	bool bool_soal7 = true;
	bool bool_soal8 = true;
	bool bool_soal9 = true;
	bool bool_soal10 = true;
	bool bool_soal11 = true;
	bool bool_soal12 = true;
	bool bool_soal13 = true;
	bool bool_soal14 = true;
	bool bool_soal15 = true;
	bool bool_soal16 = true;
	bool bool_soal18 = true;
	bool bool_soal17 = true;
	bool bool_soal19 = true;
	bool bool_soal20 = true;
	bool bool_soal29 = true;
	bool bool_soal28 = true;
	bool bool_soal27 = true;
	bool bool_soal26 = true;
	bool bool_soal25 = true;
	bool bool_soal24 = true;
	bool bool_soal23 = true;
	bool bool_soal22 = true;
	bool bool_soal21 = true;
	bool bool_soal30 = true;

	int total_soal_angka = 1;
	float benar = 0;
	float salah = 0;
	float score;

	Button* kosong = Button::create("MiniGame1/kosong.jpg");
	Sprite* tampil_hasil = Sprite::create("MiniGame1/choose.png");
	Label* total_soal = Label::createWithTTF("Total soal = 10", "fonts/arial.ttf", 30);
	Label* hasil_benar = Label::createWithTTF("", "fonts/arial.ttf", 30);
	Label* hasil_salah = Label::createWithTTF("", "fonts/arial.ttf", 30);
	Label* hasil_score = Label::createWithTTF("", "fonts/arial.ttf", 30);
	Button* btn_next = Button::create("MiniGame1/a.png", "MiniGame1/b.png", "MiniGame1/a.png");
	void next(Ref* sender);
	void done(float dt);
	int waktu_next = 3;

	//waktu//
	void durasi(float dt);
	float waktu;
	Label* time_text = Label::createWithTTF("", "fonts/arial.ttf", 35);
	//////////

	// pilih menu
	Button* bg_menu = Button::create("langit.jpg", "langit.jpg", "langit.jpg");
	Button* btn_hard = Button::create("btn_exit_awal.png", "btn_exit_tekan.png", "btn_exit_awal.png");
	Button* btn_medium = Button::create("btn_exit_awal.png", "btn_exit_tekan.png", "btn_exit_awal.png");
	Button* btn_easy = Button::create("btn_exit_awal.png", "btn_exit_tekan.png", "btn_exit_awal.png");
	Label* label_hard = Label::createWithTTF("HARD", "fonts/arial.ttf", 30);
	Label* label_medium = Label::createWithTTF("MEDIUM", "fonts/arial.ttf", 30);
	Label* label_easy = Label::createWithTTF("EASY", "fonts/arial.ttf", 30);
	void hard(Ref* sender);
	void medium(Ref* sender);
	void easy(Ref* sender);
	int pil_menu;
	//
};

#endif // __MiniGame3_SCENE_H__
