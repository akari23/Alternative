#include "Minigame1.h"
#include "HomeMenu.h"
#include "Scene2a.h"

USING_NS_CC;

Scene* MiniGame1::scene()
{
	return MiniGame1::create();
}

bool MiniGame1::init()
{
	if (!Scene::init())
	{
		return false;
	}
	HomeMenu::nilai_teks = 82;
	HomeMenu::game = 5;
	//bgm->playBackgroundMusic("music/menu.mp3",true);
	background->setPosition(Vec2(0, 0));
	background->setAnchorPoint(Vec2(0, 0));
	this->addChild(background);

	//gambar soal//
	bg_gambar_soal->setPosition(Vec2(0, 768));
	bg_gambar_soal->setAnchorPoint(Vec2(0, 1));
	bg_gambar_soal->setScale(0.7);
	//this->addChild(bg_gambar_soal);
	bg_soal->setPosition(Vec2(800, 600));
	this->addChild(bg_soal);
	kalimat_soal->setPosition(Vec2(bg_soal->getContentSize().width / 2, bg_soal->getContentSize().height / 2));
	bg_soal->addChild(kalimat_soal);
	gambar_soal1->setPosition(Vec2(50, 500));
	gambar_soal1->setAnchorPoint(Vec2(0, 0));
	gambar_soal1->setScale(0);
	gambar_soal2->setPosition(Vec2(50, 500));
	gambar_soal2->setAnchorPoint(Vec2(0, 0));
	gambar_soal2->setScale(0);
	gambar_soal3->setPosition(Vec2(50, 500));
	gambar_soal3->setAnchorPoint(Vec2(0, 0));
	gambar_soal3->setScale(0);
	gambar_soal4->setPosition(Vec2(50, 500));
	gambar_soal4->setAnchorPoint(Vec2(0, 0));
	gambar_soal4->setScale(0);
	gambar_soal5->setPosition(Vec2(50, 500));
	gambar_soal5->setAnchorPoint(Vec2(0, 0));
	gambar_soal5->setScale(0);
	gambar_soal6->setPosition(Vec2(50, 500));
	gambar_soal6->setAnchorPoint(Vec2(0, 0));
	gambar_soal6->setScale(0);
	gambar_soal7->setPosition(Vec2(50, 500));
	gambar_soal7->setAnchorPoint(Vec2(0, 0));
	gambar_soal7->setScale(0);
	gambar_soal8->setPosition(Vec2(50, 500));
	gambar_soal8->setAnchorPoint(Vec2(0, 0));
	gambar_soal8->setScale(0);
	gambar_soal9->setPosition(Vec2(50, 500));
	gambar_soal9->setAnchorPoint(Vec2(0, 0));
	gambar_soal9->setScale(0);
	gambar_soal10->setPosition(Vec2(50, 500));
	gambar_soal10->setAnchorPoint(Vec2(0, 0));
	gambar_soal10->setScale(0);
	this->addChild(gambar_soal1);
	this->addChild(gambar_soal2);
	this->addChild(gambar_soal3);
	this->addChild(gambar_soal4);
	this->addChild(gambar_soal5);
	this->addChild(gambar_soal6);
	this->addChild(gambar_soal7);
	this->addChild(gambar_soal8);
	this->addChild(gambar_soal9);
	this->addChild(gambar_soal10);
	//////////////

	//letak button jawaban//
	bg_choose->setPosition(Vec2(663.5, 220));
	bg_choose->setOpacity(100);
	this->addChild(bg_choose);
	buttonA->setPosition(Vec2(420, 334));
	buttonB->setPosition(Vec2(928, 334));
	buttonC->setPosition(Vec2(420, 111));
	buttonD->setPosition(Vec2(928, 111));
	label_A->setPosition(Vec2(buttonA->getContentSize().width / 2, buttonA->getContentSize().height / 2));
	label_B->setPosition(Vec2(buttonA->getContentSize().width / 2, buttonA->getContentSize().height / 2));
	label_C->setPosition(Vec2(buttonA->getContentSize().width / 2, buttonA->getContentSize().height / 2));
	label_D->setPosition(Vec2(buttonA->getContentSize().width / 2, buttonA->getContentSize().height / 2));
	this->addChild(buttonA,1);
	this->addChild(buttonB,1);
	this->addChild(buttonC,1);
	this->addChild(buttonD,1);
	buttonA->addChild(label_A);
	buttonB->addChild(label_B);
	buttonC->addChild(label_C);
	buttonD->addChild(label_D);
	////////////////////////
	
	//hasil//
	kosong->setPosition(Vec2(0, 0));
	kosong->setAnchorPoint(Vec2(0, 0));
	this->addChild(kosong,2);
	tampil_hasil->setPosition(Vec2(1366 / 2, 768 / 2));
	kosong->addChild(tampil_hasil);
	hasil_benar->setPosition(Vec2(tampil_hasil->getContentSize().width / 2, tampil_hasil->getContentSize().height / 2 +40));
	hasil_salah->setPosition(Vec2(tampil_hasil->getContentSize().width / 2, tampil_hasil->getContentSize().height / 2));
	total_soal->setPosition(Vec2(tampil_hasil->getContentSize().width / 2, tampil_hasil->getContentSize().height / 2 + 80));
	hasil_score->setPosition(Vec2(tampil_hasil->getContentSize().width / 2, tampil_hasil->getContentSize().height / 2 - 40));
	tampil_hasil->addChild(hasil_benar);
	tampil_hasil->addChild(hasil_salah);
	tampil_hasil->addChild(total_soal);
	tampil_hasil->addChild(hasil_score);
	kosong->setScale(0);
	btn_next->setScale(0);
	btn_next->setPosition(Vec2(1366 / 2, 200));
	kosong->addChild(btn_next);
	////////

	time_text->setPosition(Vec2(1366 / 2, 750));
	this->addChild(time_text);
	
	
	buttonA->addClickEventListener(CC_CALLBACK_1(MiniGame1::answerA, this));
	buttonB->addClickEventListener(CC_CALLBACK_1(MiniGame1::answerB, this));
	buttonC->addClickEventListener(CC_CALLBACK_1(MiniGame1::answerC, this));
	buttonD->addClickEventListener(CC_CALLBACK_1(MiniGame1::answerD, this));
	btn_next->addClickEventListener(CC_CALLBACK_1(MiniGame1::next, this));

	
	bg_menu->setPosition(Vec2(1366 / 2, 768 / 2));
	label_hard->setPosition(Vec2(btn_hard->getContentSize().width / 2, btn_hard->getContentSize().height / 2));
	label_medium->setPosition(Vec2(btn_hard->getContentSize().width / 2, btn_hard->getContentSize().height / 2));
	label_easy->setPosition(Vec2(btn_hard->getContentSize().width / 2, btn_hard->getContentSize().height / 2));
	btn_hard->setPosition(Vec2(1366 / 2, 550));
	btn_medium->setPosition(Vec2(1366 / 2, 400));
	btn_easy->setPosition(Vec2(1366 / 2, 250));
	this->addChild(bg_menu,3);
	this->addChild(btn_hard, 4);
	this->addChild(btn_medium, 4);
	this->addChild(btn_easy, 4);
	btn_hard->addChild(label_hard);
	btn_medium->addChild(label_medium);
	btn_easy->addChild(label_easy);
	btn_hard->addClickEventListener(CC_CALLBACK_1(MiniGame1::hard, this));
	btn_medium->addClickEventListener(CC_CALLBACK_1(MiniGame1::medium, this));
	btn_easy->addClickEventListener(CC_CALLBACK_1(MiniGame1::easy, this));
	random_soal();
	return true;
}

void MiniGame1::hard(Ref* sender)
{
	HomeMenu::btn_sound();
	pil_menu = 1;
	btn_hard->setScale(0);
	btn_medium->setScale(0);
	btn_easy->setScale(0);
	bg_menu->setScale(0);
	waktu = 10;
	this->schedule(schedule_selector(MiniGame1::durasi),1.f);
	log("Menu pilihan = %d", pil_menu);
}
void MiniGame1::medium(Ref* sender)
{
	HomeMenu::btn_sound();
	pil_menu = 2;
	btn_hard->setScale(0);
	btn_medium->setScale(0);
	btn_easy->setScale(0);
	bg_menu->setScale(0);
	waktu = 30;
	this->schedule(schedule_selector(MiniGame1::durasi), 1.f);
	log("Menu pilihan = %d", pil_menu);
}
void MiniGame1::easy(Ref* sender)
{
	HomeMenu::btn_sound();
	pil_menu = 3;
	btn_hard->setScale(0);
	btn_medium->setScale(0);
	btn_easy->setScale(0);
	bg_menu->setScale(0);
	waktu = 60;
	this->schedule(schedule_selector(MiniGame1::durasi), 1.f);
	log("Menu pilihan = %d", pil_menu);
}
void MiniGame1::random_soal()
{
	int nilai_random = random(0, 10);
	if (nilai_random == 1 && soal_1 == false)
	{
		soal1();
		
	}
	else if (nilai_random == 2 && soal_2 == false)
	{
		soal2(); 
	}
	else if (nilai_random == 3 && soal_3 == false)
	{
		soal3();
	}
	else if (nilai_random == 4 && soal_4 == false)
	{
		soal4();
	}
	else if (nilai_random == 5 && soal_5 == false)
	{
		soal5();
	}
	else if (nilai_random == 6 && soal_6 == false)
	{
		soal6(); 
	}
	else if (nilai_random == 7 && soal_7 == false)
	{
		soal7(); 
	}
	else if (nilai_random == 8 && soal_8 == false)
	{
		soal8();
	}
	else if (nilai_random == 9 && soal_9 == false)
	{
		soal9(); 
	}
	else if (nilai_random == 10 && soal_10 == false)
	{
		soal10(); 
	}
	else random_soal();
}


void MiniGame1::next(Ref* sender)
{
	HomeMenu::btn_sound();
	kosong->setOpacity(200);
	btn_next->setScale(0); tampil_hasil->setScale(0);
	schedule(schedule_selector(MiniGame1::done),1.f);
	auto loading_label = Label::createWithTTF("LOADING", "fonts/arial.ttf", 100);
	loading_label->setPosition(Vec2(1366 / 2, 768/2));
	kosong->addChild(loading_label);
}
void MiniGame1::done(float dt)
{
	waktu_next--;
	if (waktu_next == -1)
	{
		HomeMenu::nilai_teks = 84;
		this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
		{
			//Ini adalah kode untuk berpindah scene
			Director::getInstance()->pushScene(TransitionFade::create(0.5, Scene2a::scene(), Color3B(255, 255, 255)));
		})));
	}
}
void MiniGame1::durasi(float dt)
{
	
	auto duration = __String::createWithFormat("%.f", waktu)->getCString();
	time_text->setString(duration);
	waktu--;
	if (waktu < 0)
	{
		kosong->setScale(1);
		kosong->setOpacity(100);
		auto string_benar = __String::createWithFormat("Nilai Benar = %.f", benar)->getCString();
		auto string_salah = __String::createWithFormat("Nilai Salah = %.f", salah)->getCString();
		auto string_score = __String::createWithFormat("Nilai Score = FAIL")->getCString();
		hasil_benar->setString(string_benar);
		hasil_salah->setString(string_salah);
		hasil_score->setString(string_score);
		unschedule(schedule_selector(MiniGame1::durasi));
		auto label = Label::createWithTTF("WAKTU TELAH HABIS", "fonts/arial.ttf", 60);
		label->setPosition(Vec2(1366 / 2, 700));
		label->setAnchorPoint(Vec2(0.5, 1));
		this->addChild(label,3);
		btn_next->setScale(1);
		auto next_label = Label::createWithTTF("Lanjut", "fonts/arial.ttf", 30);
		next_label->setPosition(Vec2(btn_next->getContentSize().width / 2, btn_next->getContentSize().height / 2));
		btn_next->addChild(next_label);

	}
}

void MiniGame1::ganti()
{
	soal_ke++;
	if (soal_ke <= 10)
		random_soal();
	else
	{
		kosong->setScale(1);
		kosong->setOpacity(100);
		auto score1 = UserDefault::getInstance()->getFloatForKey("ScoreMiniGame1Hard");
		auto score2 = UserDefault::getInstance()->getFloatForKey("ScoreMiniGame1Medium");
		auto score3 = UserDefault::getInstance()->getFloatForKey("ScoreMiniGame1Easy");
		auto label_highScore = Label::create("NEW HIGH SCORE!!", "fonts/arial.ttf", 80);
		label_highScore->setColor(Color3B::BLACK);
		label_highScore ->setPosition(Vec2(1366/2,700));
		
		switch (pil_menu)
		{
		case 1:
			score = benar * waktu;
			if (score > score1)
			{
				UserDefault::getInstance()->setFloatForKey("ScoreMiniGame1Hard", score);
				this->addChild(label_highScore,4);
			}
			break;
		case 2:
			score = benar * waktu / 3;
			if (score > score2)
			{
				UserDefault::getInstance()->setFloatForKey("ScoreMiniGame1Medium", score);
				this->addChild(label_highScore,4);
			}
			break;
		case 3:
			score = benar * waktu / 6;
			if (score > score3)
			{
				UserDefault::getInstance()->setFloatForKey("ScoreMiniGame1Easy", score);
				this->addChild(label_highScore,4);
			}
			break;
		default:
			break;
		}
		auto string_benar = __String::createWithFormat("Nilai Benar = %.f", benar)->getCString();
		auto string_salah = __String::createWithFormat("Nilai Salah = %.f", salah)->getCString();
		auto string_score = __String::createWithFormat("Nilai Score = %.2f", score)->getCString();
		

		log("%f", waktu);
		log("Nilai score hard = %.2f", UserDefault::getInstance()->getFloatForKey("ScoreMiniGame1Hard"));
		log("Nilai score medium = %.2f", UserDefault::getInstance()->getFloatForKey("ScoreMiniGame1Medium"));
		log("Nilai score easy = %.2f", UserDefault::getInstance()->getFloatForKey("ScoreMiniGame1Easy"));
		hasil_benar->setString(string_benar);
		hasil_salah->setString(string_salah);
		hasil_score->setString(string_score);
		unschedule(schedule_selector(MiniGame1::durasi));
		soal_scale();
		//bg_gambar_soal->setScale(0);
		bg_soal->setScale(0);
		buttonA->setScale(0);
		buttonB->setScale(0);
		buttonC->setScale(0);
		buttonD->setScale(0);
		bg_choose->setScale(0);
		btn_next->setScale(1);
		auto next_label = Label::createWithTTF("Lanjut", "fonts/arial.ttf", 30);
		next_label->setPosition(Vec2(btn_next->getContentSize().width / 2, btn_next->getContentSize().height / 2));
		btn_next->addChild(next_label);
	}

}

void MiniGame1::answerA(Ref* sender)
{
	
	HomeMenu::btn_sound();
	auto pilih = 1;
	if (pilih == jawaban)
		benar++;
	else salah++;
	log("Nilai Benar = %.f", benar);
	log("Nilai Salah =  %.f", salah);
	ganti();
}
void MiniGame1::answerB(Ref* sender)
{
	
	HomeMenu::btn_sound();
	auto pilih = 2;
	if (pilih == jawaban)
		benar++;
	else salah++;
	log("Nilai Benar =  %.f", benar);
	log("Nilai Salah = %.f", salah);
	ganti();
}
void MiniGame1::answerC(Ref* sender)
{
	
	HomeMenu::btn_sound();
	auto pilih = 3;
	if (pilih == jawaban)
		benar++;
	else salah++;
	log("Nilai Benar =  %.f", benar);
	log("Nilai Salah =  %.f", salah);
	ganti();
}
void MiniGame1::answerD(Ref* sender)
{
	
	HomeMenu::btn_sound();
	auto pilih = 4;
	if (pilih == jawaban)
		benar++;
	else salah++;
	log("Nilai Benar =  %.f", benar);
	log("Nilai Salah = %.f", salah);
	ganti();
}


void MiniGame1::soal1() //switch
{
	soal_1 = true;
	soal_scale();
	gambar_soal1->setScale(0.3);
	auto teksA = __String::createWithFormat("Switch")->getCString();
	auto teksB = __String::createWithFormat("Hub")->getCString();
	auto teksC = __String::createWithFormat("Kabel UTP")->getCString();
	auto teksD = __String::createWithFormat("Router")->getCString();
	label_A->setString(teksA);
	label_B->setString(teksB);
	label_C->setString(teksC);
	label_D->setString(teksD);
	jawaban = 1;
}
void MiniGame1::soal2() // router
{
	soal_2 = true;
	soal_scale();
	gambar_soal2->setScale(0.3);
	auto teksA = __String::createWithFormat("Switch")->getCString();
	auto teksB = __String::createWithFormat("Hub")->getCString();
	auto teksC = __String::createWithFormat("Router")->getCString();
	auto teksD = __String::createWithFormat("Repeater")->getCString();
	label_A->setString(teksA);
	label_B->setString(teksB);
	label_C->setString(teksC);
	label_D->setString(teksD);
	jawaban = 3;
}
void MiniGame1::soal3() //utp
{
	soal_3 = true;
	soal_scale();
	gambar_soal3->setScale(0.3);
	auto teksA = __String::createWithFormat("Repeater")->getCString();
	auto teksB = __String::createWithFormat("Keyboard")->getCString();
	auto teksC = __String::createWithFormat("Mouse")->getCString();
	auto teksD = __String::createWithFormat("Kabel UTP")->getCString();
	label_A->setString(teksA);
	label_B->setString(teksB);
	label_C->setString(teksC);
	label_D->setString(teksD);
	jawaban = 4;
}
void MiniGame1::soal4() // hub
{
	soal_4 = true;
	soal_scale();
	gambar_soal4->setScale(0.3);
	auto teksA = __String::createWithFormat("Switch")->getCString();
	auto teksB = __String::createWithFormat("Router")->getCString();
	auto teksC = __String::createWithFormat("Hub")->getCString();
	auto teksD = __String::createWithFormat("Kabel UTP")->getCString();
	label_A->setString(teksA);
	label_B->setString(teksB);
	label_C->setString(teksC);
	label_D->setString(teksD);
	jawaban = 3;
}
void MiniGame1::soal5() // repeater
{
	soal_5 = true;
	soal_scale();
	gambar_soal5->setScale(0.3);
	auto teksA = __String::createWithFormat("Hub")->getCString();
	auto teksB = __String::createWithFormat("Repeater")->getCString();
	auto teksC = __String::createWithFormat("Switch")->getCString();
	auto teksD = __String::createWithFormat("Router")->getCString();
	label_A->setString(teksA);
	label_B->setString(teksB);
	label_C->setString(teksC);
	label_D->setString(teksD);
	jawaban = 2;
}
void MiniGame1::soal6() // ethernet
{
	soal_6 = true;
	soal_scale();
	gambar_soal6->setScale(0.2);
	auto teksA = __String::createWithFormat("Kabel UTP")->getCString();
	auto teksB = __String::createWithFormat("Jack audio")->getCString();
	auto teksC = __String::createWithFormat("Komputer")->getCString();
	auto teksD = __String::createWithFormat("Ethernet")->getCString();
	label_A->setString(teksA);
	label_B->setString(teksB);
	label_C->setString(teksC);
	label_D->setString(teksD);
	jawaban = 4;
}
void MiniGame1::soal7() // server
{
	soal_7 = true;
	soal_scale();
	gambar_soal7->setScale(0.2);
	auto teksA = __String::createWithFormat("Komputer server")->getCString();
	auto teksB = __String::createWithFormat("Hub")->getCString();
	auto teksC = __String::createWithFormat("Komputer")->getCString();
	auto teksD = __String::createWithFormat("Kabel UTP")->getCString();
	label_A->setString(teksA);
	label_B->setString(teksB);
	label_C->setString(teksC);
	label_D->setString(teksD);
	jawaban = 1;
}
void MiniGame1::soal8() // komputer
{
	soal_8 = true;
	soal_scale();
	gambar_soal8->setScale(0.2);
	auto teksA = __String::createWithFormat("Mouse")->getCString();
	auto teksB = __String::createWithFormat("Komputer")->getCString();
	auto teksC = __String::createWithFormat("Komputer server")->getCString();
	auto teksD = __String::createWithFormat("Keyboard")->getCString();
	label_A->setString(teksA);
	label_B->setString(teksB);
	label_C->setString(teksC);
	label_D->setString(teksD);
	jawaban = 2;
}
void MiniGame1::soal9() // keyboard 
{
	soal_9 = true;
	soal_scale();
	gambar_soal9->setScale(0.1);
	auto teksA = __String::createWithFormat("Hub")->getCString();
	auto teksB = __String::createWithFormat("Kabel UTP")->getCString();
	auto teksC = __String::createWithFormat("Mouse")->getCString();
	auto teksD = __String::createWithFormat("Keyboard")->getCString();
	label_A->setString(teksA);
	label_B->setString(teksB);
	label_C->setString(teksC);
	label_D->setString(teksD);
	jawaban = 4;
}
void MiniGame1::soal10() // mouse
{
	soal_10 = true;
	soal_scale();
	gambar_soal10->setScale(0.3);
	auto teksA = __String::createWithFormat("Keyboard")->getCString();
	auto teksB = __String::createWithFormat("Mouse")->getCString();
	auto teksC = __String::createWithFormat("Komputer")->getCString();
	auto teksD = __String::createWithFormat("Kabel UTP")->getCString();
	label_A->setString(teksA);
	label_B->setString(teksB);
	label_C->setString(teksC);
	label_D->setString(teksD);
	jawaban = 3;
}

void MiniGame1::soal_scale()
{
	gambar_soal1->setScale(0);
	gambar_soal2->setScale(0);
	gambar_soal3->setScale(0);
	gambar_soal4->setScale(0);
	gambar_soal5->setScale(0);
	gambar_soal6->setScale(0);
	gambar_soal7->setScale(0);
	gambar_soal8->setScale(0);
	gambar_soal9->setScale(0);
	gambar_soal10->setScale(0);
}
