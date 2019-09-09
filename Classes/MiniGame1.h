#ifndef __MiniGame1_H__
#define __MiniGame1_H__


#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;


using namespace cocos2d::ui;
using namespace cocos2d;
using namespace CocosDenshion;

class MiniGame1 :public Scene
{
private:

public:

	Sprite* background = Sprite::create("MiniGame1/kelas.jpg");
	SimpleAudioEngine* bgm = SimpleAudioEngine::getInstance();
	
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

	//waktu//
	void durasi(float dt);
	float waktu ;
	Label* time_text = Label::createWithTTF("", "fonts/arial.ttf", 35);
	//////////

	//gambar soal//
	void soal_scale();
	Sprite* bg_gambar_soal = Sprite::create("MiniGame1/bg_gambar.jpg");
	Sprite* bg_soal = Sprite::create("MiniGame1/bg_standar.png");
	Label* kalimat_soal = Label::createWithTTF("Apakah nama alat dari gambar di samping ?","fonts/arial.ttf",20);
	Sprite* gambar_soal1 = Sprite::create("MiniGame1/switch.png");
	Sprite* gambar_soal2 = Sprite::create("MiniGame1/router.png");
	Sprite* gambar_soal3 = Sprite::create("MiniGame1/utp.png");
	Sprite* gambar_soal4 = Sprite::create("MiniGame1/hub.png");
	Sprite* gambar_soal5 = Sprite::create("MiniGame1/repeater.png");
	Sprite* gambar_soal6 = Sprite::create("MiniGame1/ethernet.png");
	Sprite* gambar_soal7 = Sprite::create("MiniGame1/server.png");
	Sprite* gambar_soal8 = Sprite::create("MiniGame1/computer.png");
	Sprite* gambar_soal9 = Sprite::create("MiniGame1/keyboard.png");
	Sprite* gambar_soal10 = Sprite::create("MiniGame1/mouse.png");
	//////////////

	//fungsi soal//
	int jawaban = 0;
	int soal_ke = 1;
	void ganti();
	void soal1();
	void soal2();
	void soal3();
	void soal4();
	void soal5();
	void soal6();
	void soal7();
	void soal8();
	void soal9();
	void soal10();
	///////////////

	//fugnsi soal random//
	bool soal_1 = false;
	bool soal_2 = false;
	bool soal_3 = false;
	bool soal_4 = false;
	bool soal_5 = false;
	bool soal_6 = false;
	bool soal_7 = false;
	bool soal_8 = false;
	bool soal_9 = false;
	bool soal_10 = false;
	void random_soal();
	/////////////////////
	//button jawab//
	Sprite* bg_choose = Sprite::create("MiniGame1/bg_choose.jpg");
	Button* buttonA = Button::create("MiniGame1/choose.png", "MiniGame1/choose_pressed.png", "MiniGame1/choose.png");
	Button* buttonB = Button::create("MiniGame1/choose.png", "MiniGame1/choose_pressed.png", "MiniGame1/choose.png");
	Button* buttonC = Button::create("MiniGame1/choose.png", "MiniGame1/choose_pressed.png", "MiniGame1/choose.png");
	Button* buttonD = Button::create("MiniGame1/choose.png", "MiniGame1/choose_pressed.png", "MiniGame1/choose.png");
	Label* label_A = Label::createWithTTF("A", "fonts/arial.ttf", 30);
	Label* label_B = Label::createWithTTF("B", "fonts/arial.ttf", 30);
	Label* label_C = Label::createWithTTF("C", "fonts/arial.ttf", 30);
	Label* label_D = Label::createWithTTF("D", "fonts/arial.ttf", 30);
	void answerA(Ref* sender);
	void answerB(Ref* sender);
	void answerC(Ref* sender);
	void answerD(Ref* sender);
	////////////////

	//Hasil//
	Button* kosong = Button::create("MiniGame1/kosong.jpg");
	Sprite* tampil_hasil = Sprite::create("MiniGame1/choose.png");
	Label* total_soal = Label::createWithTTF("Total soal = 10", "fonts/arial.ttf", 30);
	Label* hasil_benar = Label::createWithTTF("asd", "fonts/arial.ttf", 30);
	Label* hasil_score= Label::createWithTTF("asd", "fonts/arial.ttf", 30);
	Label* hasil_salah = Label::createWithTTF("asd", "fonts/arial.ttf", 30);
	Button* btn_next = Button::create("MiniGame1/a.png", "MiniGame1/b.png", "MiniGame1/a.png");
	void next(Ref* sender);
	void done(float dt);
	int waktu_next = 5;
	////////

	//nilai//
	float benar = 0;
	float salah = 0;
	float score = 0;
	////////

	static Scene* scene();
	virtual bool init();
	CREATE_FUNC(MiniGame1);
};

#endif