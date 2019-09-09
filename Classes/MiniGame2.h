#ifndef __MINIgAME_2_H__
#define __MINIGAME_2_H__
#include "cocos2d.h"
#include "ui\CocosGUI.h"
USING_NS_CC;

using namespace cocos2d::ui;
using namespace cocos2d;

class MiniGame2 : public cocos2d::Scene
{
public:
    static Scene* createScene();

    virtual bool init();
	void random_soal();
	void Selesai();
    // a selector callback
  
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
	Sprite* tulisan = Sprite::create("MiniGame2/tulisan.jpg");
	Sprite* mobo_teks = Sprite::create("MiniGame2/motherboard.jpg");
	Sprite* soal_teks = Sprite::create("MiniGame2/komponen.jpg");
	Sprite* bg_soal = Sprite::create("MiniGame2/bg_mobo.jpg");
	Sprite* bg_mobo = Sprite::create("MiniGame2/bg_mobo.jpg");
    // implement the "static create()" method manually
    CREATE_FUNC(MiniGame2);
	
	//waktu//
	void durasi(float dt);
	float waktu ;
	Label* time_text = Label::createWithTTF("", "fonts/arial.ttf", 35);
	//////////
	//Hasil//
	Button* kosong = Button::create("MiniGame1/kosong.jpg");
	Sprite* tampil_hasil = Sprite::create("MiniGame1/choose.png");
	Label* hasil_score = Label::createWithTTF("asd", "fonts/arial.ttf", 30);
	Button* btn_next = Button::create("MiniGame1/a.png", "MiniGame1/b.png", "MiniGame1/a.png");
	void next(Ref* sender);
	void kosongscale();
	void done(float dt);
	int waktu_next = 5;
	float score = 0;
	////////
	Sprite* background = Sprite::create("MiniGame2/background.jpg");
	Sprite* Mobo = Sprite::create("MiniGame2/mobo.png");
	Sprite* sprite = Sprite::create("MiniGame2/mobo1.png");
	Sprite* sprite2 = Sprite::create("MiniGame2/mobo2.png");
	Sprite* sprite3 = Sprite::create("MiniGame2/mobo3.png");
	Sprite* sprite4 = Sprite::create("MiniGame2/mobo4.png");
	Sprite* sprite5 = Sprite::create("MiniGame2/mobo5.png");
	Sprite* sprite6 = Sprite::create("MiniGame2/mobo6.png");
	Sprite* sprite7 = Sprite::create("MiniGame2/mobo7.png");
	Sprite* sprite8 = Sprite::create("MiniGame2/mobo8.png");


	Sprite* soal = Sprite::create("MiniGame2/mobo1.png");
	
	int nilai;
	bool bool_soal1 = true;
	bool bool_soal2 = true;
	bool bool_soal3 = true;
	bool bool_soal4 = true;
	bool bool_soal5 = true;
	bool bool_soal6 = true;
	bool bool_soal7 = true;
	bool bool_soal8 = true;

	int total_soal = 0;
	//bool benar = false;

	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event * event);
	void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event * event);
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event * event);
};

#endif // __MiniGame2_SCENE_H__
