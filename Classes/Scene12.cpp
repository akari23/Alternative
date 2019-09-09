#include "Scene12.h"
#include "Scene16.h"
#include "Option.h"
#include "HomeMenu.h"
#include "SaveGame.h"
#include "LoadGame.h"

USING_NS_CC;



Scene* Scene12::scene()
{
	return Scene12::create();
}

bool Scene12::init()
{
	if (!Scene::init())
	{
		return false;
	}
	bgm->playBackgroundMusic("music/12.mp3", true);
	HomeMenu::game = 17;
	

	//background//
	background->setPosition(Vec2(0, 0));
	background->setAnchorPoint(Vec2(0, 0));
	this->addChild(background);
	/////////////

	this->schedule(schedule_selector(Scene12::delay_game), 1);

	buttonStart->setPosition(Vec2(1366 / 2, 10));
	buttonStart->setScale(0);
	buttonStart->setAnchorPoint(Vec2(0.5, 0));
	this->addChild(buttonStart, 1);

	//bagian button menu//
	btn_menu->setPosition(Vec2(1313, 714));
	btn_menu->setAnchorPoint(Vec2(0.5, 0.5));
	this->addChild(btn_menu, 1);
	bg_menu_btn->setPosition(Vec2(1600, 780)); //1255,384 (movenya)
	bg_menu_btn->setAnchorPoint(Vec2(0.5, 0.5));
	bg_menu_btn->setOpacity(150);
	this->addChild(bg_menu_btn, 2);
	bg_menu_btn->addChild(btn_tittle);
	bg_menu_btn->addChild(btn_save);
	bg_menu_btn->addChild(btn_load);
	bg_menu_btn->addChild(btn_config);
	bg_menu_btn->addChild(btn_close);
	btn_tittle->setPosition(Vec2(bg_menu_btn->getContentSize().width / 2 - 110, 330));
	btn_save->setPosition(Vec2(bg_menu_btn->getContentSize().width / 2 - 110, 260));
	btn_load->setPosition(Vec2(bg_menu_btn->getContentSize().width / 2 - 110, 190));
	btn_config->setPosition(Vec2(bg_menu_btn->getContentSize().width / 2 - 110, 120));
	btn_close->setPosition(Vec2(bg_menu_btn->getContentSize().width / 2 - 110, 50));
	btn_tittle->setAnchorPoint(Vec2(0.5, 0.5));
	btn_save->setAnchorPoint(Vec2(0.5, 0.5));
	btn_load->setAnchorPoint(Vec2(0.5, 0.5));
	btn_config->setAnchorPoint(Vec2(0.5, 0.5));
	btn_close->setAnchorPoint(Vec2(0.5, 0.5));
	btn_tittle->setScale(0.6);
	btn_save->setScale(0.6);
	btn_load->setScale(0.6);
	btn_config->setScale(0.6);
	btn_close->setScale(0.6);
	////////////////////////

	//bagian ke title//
	bg_exit->setPosition(Vec2(1366 / 2, 768 / 2));
	bg_exit->setAnchorPoint(Vec2(0.5, 0.5));
	bg_exit->setScale(0);
	btn_exit_no->setPosition(Vec2(bg_exit->getContentSize().width / 2 + 30, bg_exit->getContentSize().height / 2));
	btn_exit_no->setAnchorPoint(Vec2(0, 0.5));
	btn_exit_no->setScale(0);
	label_quit_no->setScale(0);
	label_quit_no->setPosition(Vec2(btn_exit_no->getContentSize().width / 2, btn_exit_no->getContentSize().height / 2));
	label_quit_yes->setScale(0);
	label_quit_yes->setPosition(Vec2(btn_exit_yes->getContentSize().width / 2, btn_exit_yes->getContentSize().height / 2));
	btn_exit_yes->setPosition(Vec2(bg_exit->getContentSize().width / 2 - 30, bg_exit->getContentSize().height / 2));
	btn_exit_yes->setAnchorPoint(Vec2(1, 0.5));
	btn_exit_yes->setScale(0);
	kosong->setPosition(Vec2(0, 0));
	kosong->setAnchorPoint(Vec2(0, 0));
	kosong->setScale(0);
	this->addChild(bg_exit, 3);
	this->addChild(kosong, 2);
	bg_exit->addChild(btn_exit_yes);
	bg_exit->addChild(btn_exit_no);
	btn_exit_no->addChild(label_quit_no);
	btn_exit_yes->addChild(label_quit_yes);
	//////////////////



	//bagian percakapan teks//

	teks_1->setPosition(Vec2(50, 150));

	teks_1->setAnchorPoint(Vec2(0, 1));

	teks_1->setOpacity(0);

	nama->setPosition(Vec2(50, 190));
	nama->setAnchorPoint(Vec2(0, 1));
	nama->setColor(Color3B::BLACK);

	buttonStart->addChild(teks_1);
	buttonStart->addChild(nama);


	/////////////////////////
	btn_load->addClickEventListener(CC_CALLBACK_1(Scene12::load_game, this));
	btn_save->addClickEventListener(CC_CALLBACK_1(Scene12::save_game, this));
	btn_config->addClickEventListener(CC_CALLBACK_1(Scene12::config, this));
	btn_exit_no->addClickEventListener(CC_CALLBACK_1(Scene12::quit_no, this));
	btn_exit_yes->addClickEventListener(CC_CALLBACK_1(Scene12::quit_yes, this));
	btn_tittle->addClickEventListener(CC_CALLBACK_1(Scene12::back_title, this));
	btn_close->addClickEventListener(CC_CALLBACK_1(Scene12::close_menu, this));
	buttonStart->addClickEventListener(CC_CALLBACK_1(Scene12::startGame, this));
	btn_menu->addClickEventListener(CC_CALLBACK_1(Scene12::pil_menu, this));
	///////////////////////
	//gambar karakter//
	anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	hiden_character();
	this->addChild(nana_sprite);
	this->addChild(anna_sprite);
	this->addChild(lily_sprite);
	/////////////////////////
	//background//
	if (HomeMenu::nilai_teks > 36)
		background->setTexture("bg/camp.jpg");
	/////////////
	return true;
}
void Scene12::hiden_character()
{
	anna_sprite->setScale(0);
	nana_sprite->setScale(0);
	lily_sprite->setScale(0);
}
void Scene12::delay_game(float dt)
{
	detik++;

	if (detik == 4)
	{
		isi_teks();
		this->schedule(schedule_selector(Scene12::teksJalan), Option::speed_teks);
		unschedule(schedule_selector(Scene12::delay_game));
		detik = 0;
	}
	else if (detik == 3)
		buttonStart->setScale(1);
}


void Scene12::pil_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1400, 780)));
	btn_menu->setScale(0);

}

void Scene12::close_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1600, 780)));
	btn_menu->setScale(1);
}

void Scene12::back_title(Ref* sender)
{

	HomeMenu::btn_sound();
	bg_exit->setScale(1);
	kosong->setScale(1);
	btn_exit_no->setScale(1);
	btn_exit_yes->setScale(1);
	label_quit_no->setScale(1);
	label_quit_yes->setScale(1);

}

void Scene12::config(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, Option::scene(), Color3B(255, 255, 255)));
	})));

}
void Scene12::save_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, SaveGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene12::load_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, LoadGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene12::delay(float dt)
{
	if (detik == 1)
	{
		unschedule(schedule_selector(Scene12::delay));
		buttonStart->setScale(1);
		if (HomeMenu::nilai_teks == 37)
		{
			this->schedule(schedule_selector(Scene12::teksJalan), Option::speed_teks);
		}
		detik = 0;
	}
	detik++;
}
void Scene12::startGame(Ref* sender)
{
	unschedule(schedule_selector(Scene12::teksJalan));
	HomeMenu::btn_sound();
	HomeMenu::nilai_teks++;
	isi_teks();
	teks_1->setOpacity(0);
	i = 0;
	log("Nilai teks = %d", HomeMenu::nilai_teks);
	if (HomeMenu::nilai_teks == 37)
	{
		buttonStart->setScale(0);
		if (HomeMenu::nilai_teks > 36)
			background->setTexture("bg/camp.jpg");
		this->schedule(schedule_selector(Scene12::delay), 1.f);
	}
	else if (HomeMenu::nilai_teks == 80)
	{
		HomeMenu::nilai_teks = 1;
		this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
		{
			Director::getInstance()->replaceScene(TransitionFade::create(3, Scene16::scene(), Color3B(255, 255, 255)));
		})));
	}
	else
		this->schedule(schedule_selector(Scene12::teksJalan), Option::speed_teks);

}

void Scene12::isi_teks()
{
	if (HomeMenu::nilai_teks == 1)
	{
		anna();
		teks = __String::createWithFormat("\"A-apa masih jauh?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 2)
	{
		lily();
		teks = __String::createWithFormat("\"Kurang sedikit kak Anna, bertahanlah sebentar lagi.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));

		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 3)
	{
		anna();
		teks = __String::createWithFormat("\"Kamu kuat sekali ya Lily.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));

		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 4)
	{
		lily();
		teks = __String::createWithFormat("\"Tidak kok, aku juga sudah capek.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l4.png");
		lily_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));

		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 5)
	{
		rei();
		teks = __String::createWithFormat("\"Dia ini anggota wapalhi, tentu saja dia sudah terbiasa.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));

		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 6)
	{
		hiden_character();
		anna();
		teks = __String::createWithFormat("\"Kamu sendiri, kenapa bisa sekuat itu? \nKamu bukan anggota wapalhi kan?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 7)
	{
		hiden_character();
		lily();
		teks = __String::createWithFormat("\"Kakak Rei anggota wapalhi kok.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));

	}
	else if (HomeMenu::nilai_teks == 8)
	{
		anna();
		teks = __String::createWithFormat("\"Eh? Benarkah? Aku tidak tahu.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));

		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 9)
	{
		hiden_character();
		rei();
		teks = __String::createWithFormat("\"Aku jarang sekali datang ke ormawa tapi.\"")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 10)
	{
		nama_kosong();
		teks = __String::createWithFormat("Berkat berbagai hal yang aku lakukan di beberapa minggu ini, \nstaminaku terlatih. Tapi, tetap saja aku tidak menyangka \naku benar-benar sedang mendaki gunung.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 11)
	{
		anna();
		teks = __String::createWithFormat("\"Hei Rei, pastikan Nana baik-baik saja. \nJangan sampai dia tertinggal.\"")->getCString();
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 12)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Aku melihat Nana yang tatapannya terlihat kosong \nsejak kami mulai mendaki gunung. Kasihan sekali, kalau saja aku \npunya kekuatan lebih, pasti sudah aku gendong.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 13)
	{
		hiden_character();
		rei();
		teks = __String::createWithFormat("\"Ngomong-ngomong, kamu sudah bilang kalau \nsebentar lagi sampai sebanyak lima kali.\"")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 14)
	{
		lily();
		teks = __String::createWithFormat("\"Ehehe.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/5.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 15)
	{
		hiden_character();
		anna();
		teks = __String::createWithFormat("\"Benarkah?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 16)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Anna sepertinya benar-benar kelelahan \nsampai otaknya jadi tidak beres.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 17)
	{
		rei();
		teks = __String::createWithFormat("\"Bagaimana kalau kita istirahat sebentar, \nbisakah kamu tanyakan ke ketua?\"")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 18)
	{
		lily();
		teks = __String::createWithFormat("\"Oke, tunggu sebentar.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 19)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Aku berhenti sejenak untuk meletakkan tas \ndan meminum air dari botol minumku.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 20)
	{
		anna();
		teks = __String::createWithFormat("\"Bukannya kita belum dapat izin untuk berhenti?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 21)
	{
		rei();
		teks = __String::createWithFormat("\"Tenang saja, pasti dapat kok. Kalau ada satu orang \nsaja yang kelelahan, kita pasti akan berhenti untuk beristirahat.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 22)
	{
		rei();
		teks = __String::createWithFormat("\"Lagipula ini bukan acara khusus anggota wapalhi, \njadi tidak sekeras itu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 23)
	{
		nama_kosong();
		teks = __String::createWithFormat("Anna dan Nana kemudian merobohkan diri mereka dengan segera.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2-300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2+300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 24)
	{
		hiden_character();
		lily();
		teks = __String::createWithFormat("\"Kakak! Kita boleh-\nEh?! Sudah pada beristirahat ternyata.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l3.png");
		lily_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 25)
	{
		lily();
		teks = __String::createWithFormat("\"Kakak, jangan duduk terlalu lama.\nMalahan, kalau bisa jangan duduk!\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 26)
	{
		
		anna();
		teks = __String::createWithFormat("\"Kenapa memangnya?\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 27)
	{
		hiden_character();
		rei();
		teks = __String::createWithFormat("\"Oh ya, aku lupa mengingatkan. Otot kalian sedang terkejut \ndan berusaha membiasakan diri dengan pendakian.\"")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 28)
	{
		rei();
		teks = __String::createWithFormat("\"Kalau kalian istirahat sekarang, otot kalian akan kembali menegang.\"")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 29)
	{
		anna();
		teks = __String::createWithFormat("\"Aku tidak begitu paham, tapi baiklah.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 30)
	{
		hiden_character();
		nana();
		teks = __String::createWithFormat("\"Apa aku boleh makan snack?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/3.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 31)
	{
		hiden_character();
		lily();
		teks = __String::createWithFormat("\"Boleh kak, tapi jangan banyak-banyak ya.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 32)
	{
		lily();
		teks = __String::createWithFormat("\"Lima menit lagi kemudian kita mendaki lagi ya.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 33)
	{
		hiden_character();
		anna();
		teks = __String::createWithFormat("\"Sebentar sekali waktu istirahatnya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 34)
	{
		hiden_character();
		lily();
		teks = __String::createWithFormat("\"Tenang saja, sebentar lagi sampai kok.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 35)
	{
		rei();
		teks = __String::createWithFormat("\"Itu yang keenam.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l5.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 36)
	{
		hiden_character();
		anna();
		teks = __String::createWithFormat("\"Apanya?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50)); 
	}
	else if (HomeMenu::nilai_teks == 37)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Sesampainya di area perkemahan, kami semua sibuk \nmempersiapkan berbagai hal untuk melewati malam ini.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 38)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku bersama anggota laki-laki lain membantu mendirikan tenda; \nsementara Anna, Nana, dan Lily membantu membuatkan makanan.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 39)
	{
		nama_kosong();
		teks = __String::createWithFormat("Setelah matahari terbenam sepenuhnya, kami menyalakan api unggun \nyang sudah kami persiapkan tadi dan duduk di sekitarnya.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 40)
	{
		anna();
		teks = __String::createWithFormat("\"Rasanya menyenangkan sekali berkumpul \ndi dekat api unggun seperti ini.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 41)
	{
		lily();
		teks = __String::createWithFormat("\"Iya, tapi jangan tidur terlalu larut. \nKita masih perlu menyimpan tenaga untuk pendakian ke puncak besok.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2-300, 768 / 2 + 50));

		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2+300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 42)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Aku menyeruput teh jahe dari gelasku. \nJahe memang luar biasa. Untung saja aku tidak lupa membawanya.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 43)
	{
		lily();
		teks = __String::createWithFormat("\"Bagaimana kak? \nApakah pendakian ini membuat kakak bernostalgia?\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 44)
	{
		rei();
		teks = __String::createWithFormat("\"Ya. Aku jadi ingat kalau mendaki gunung itu memang melelahkan.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 45)
	{
		nana();
		teks = __String::createWithFormat("\"Sudah berapa kali Rei mendaki gunung?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 46)
	{
		rei();
		teks = __String::createWithFormat("\"Baru dua kali termasuk ini. \nPertama kali ketika aku di tingkat satu.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 47)
	{
		lily();
		teks = __String::createWithFormat("\"Untuk yang kali ini, usahakan untuk \nmengikuti pendakian ke puncak ya.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		lily_sprite->setScale(0.6);
		lily_sprite->setScaleX(-0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 48)
	{
		hiden_character();
		anna();
		teks = __String::createWithFormat("\"Apa?! Kamu mendaki gunung tapi tidak sampai ke puncak?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
		nana_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 49)
	{
		rei();
		teks = __String::createWithFormat("\"Waktu itu aku sudah kelelahan hanya untuk mencapai area perkemahan.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/k5.png");
		anna_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 50)
	{
		rei();
		teks = __String::createWithFormat("\"Mungkin kamu tidak tahu, tapi selama beberapa hari setelah \npendakian itu, aku berjalan seperti orang tua.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/k5.png");
		anna_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 51)
	{
		rei();
		teks = __String::createWithFormat("\"Mungkin kalian akan merasakannya nanti.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
		nana_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/k7.png");
		anna_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 52)
	{
		hiden_character();
		lily();
		teks = __String::createWithFormat("\"Te-tenang saja kak, kalau tadi kakak pemanasan dengan benar, \ntidak akan sampai seperti itu kok.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setScaleX(-0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 53)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Kami kemudian terdiam sejenak menikmati hangatnya api unggun \nyang kami kelilingi.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 54)
	{
		rei();
		teks = __String::createWithFormat("\"Tidak buruk juga.\"")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 55)
	{
		rei();
		teks = __String::createWithFormat("\"Berada dalam suasana yang jarang bisa kita nikmati \ntidak buruk juga.\"")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 56)
	{
		anna();
		teks = __String::createWithFormat("\"Berterimakasihlah padaku!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 57)
	{
		rei();
		teks = __String::createWithFormat("\"Terimakasih Lily.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 58)
	{
		nama_kosong();
		teks = __String::createWithFormat("Anna meninju pundakku dengan keras. \nNana sedikit tertawa melihatnya.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2-300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2+300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 59)
	{
		rei();
		teks = __String::createWithFormat("\"Habisnya, kalau Lily tidak mengajakku, \nkita tidak akan ada di sini kan.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 60)
	{
		anna();
		teks = __String::createWithFormat("\"Ya, itu memang benar sih.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 61)
	{
		hiden_character();
		lily();
		teks = __String::createWithFormat("\"Terimakasih kembali kak karena telah meramaikan acara ini.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 62)
	{
		lily();
		teks = __String::createWithFormat("\"Mungkin sebaiknya kita segera tidur.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 63)
	{
		rei();
		teks = __String::createWithFormat("\"Aku setuju. Ayo kita kembali ke tenda.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 64)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Kami memadamkan api yang telah menghangatkan kami. \nPadamnya api membawa kegelapan dan hawa dingin yang menusuk \ntulang.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 65)
	{
		anna();
		teks = __String::createWithFormat("\"Rei, apa yang kamu lakukan?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 66)
	{
		rei();
		teks = __String::createWithFormat("\"Ha?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 67)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku melihat Lily dan Nana tertawa.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2-300, 768 / 2 + 50));

		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l5.png");
		lily_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 68)
	{
		rei();
		teks = __String::createWithFormat("\"Ke-kenapa sih? Ayo cepat masuk ke tenda, \naku bisa membeku di sini.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l5.png");
		lily_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 69)
	{
		hiden_character();
		anna();
		teks = __String::createWithFormat("\"Itu yang ingin aku lakukan, \ntapi kenapa kamu mengikuti kami sampai ke tenda kami?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 70)
	{

		nama_kosong();
		teks = __String::createWithFormat("Karena sejak tadi aku terus bersama mereka, \ntanpa sadar aku mengikuti mereka.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 71)
	{
		hiden_character();
		lily();
		teks = __String::createWithFormat("\"Aku sih tidak keberatan kak Rei tidur bersama kita, \nkalau yang lain?\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l5.png");
		lily_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 72)
	{
		hiden_character();
		anna();
		teks = __String::createWithFormat("\"Kedengarannya seru. Aku juga tidak keberatan, hehe.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/5.png");
		nana_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 73)
	{
		hiden_character();
		nana();
		teks = __String::createWithFormat("\"E-Eh?!\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 74)
	{
		rei();
		teks = __String::createWithFormat("\"Mereka cuma bercanda Nana.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 75)
	{
		rei();
		teks = __String::createWithFormat("\"Maaf, sepertinya otakku sudah mulai membeku. \nSampai jumpa besok.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 76)
	{
		anna();
		teks = __String::createWithFormat("\"Kamu akan ikut ke puncak kan besok?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 77)
	{
		rei();
		teks = __String::createWithFormat("\"Iya. Rasanya konyol kalau tidak ke puncak juga kali ini.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 78)
	{
		anna();
		teks = __String::createWithFormat("\"Oke. Sampai jumpa besok.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 79)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Sampai di tendaku, aku segera membungkus tubuhku dalam sleeping bag \ndan langsung terlelap karena kelelahan.")->getCString();
		teks_1->setString(teks);
	}
}


void Scene12::quit_yes(Ref* sender)
{
	HomeMenu::btn_sound();
	HomeMenu::nilai_logo = true;

	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		Director::getInstance()->replaceScene(TransitionFade::create(3, HomeMenu::scene(), Color3B(255, 255, 255)));
	})));
} //button tekan exit yes

void Scene12::quit_no(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_exit->setScale(0);
	kosong->setScale(0);
	btn_exit_no->setScale(0);
	btn_exit_yes->setScale(0);
	label_quit_no->setScale(0);
	label_quit_yes->setScale(0);
} // button tekan exit no


  ///bagian teks//////////////////
void Scene12::teksJalan(float dt)
{

	teks_satu();
}

void Scene12::teks_satu()
{
	auto mulai = teks_1->getLetter(i);
	if (!mulai)
	{
		i++;
		return;
	}
	mulai->setOpacity(255);
	mulai->setColor(Color3B::BLACK);
	i++;
	if (i == teks_1->getStringLength())
	{
		unschedule(schedule_selector(Scene12::teksJalan));
	}
}

void Scene12::rei()
{
	auto teks_nama = __String::createWithFormat("Rei")->getCString();
	nama->setString(teks_nama);
}
void Scene12::anna()
{
	auto teks_nama = __String::createWithFormat("Anna")->getCString();
	nama->setString(teks_nama);
}
void Scene12::lily()
{
	auto teks_nama = __String::createWithFormat("Lily")->getCString();
	nama->setString(teks_nama);
}
void Scene12::nana()
{
	auto teks_nama = __String::createWithFormat("Nana")->getCString();
	nama->setString(teks_nama);
}
void Scene12::nama_kosong()
{
	auto teks_nama = __String::createWithFormat("")->getCString();
	nama->setString(teks_nama);
}
void Scene12::nama_titik()
{
	auto teks_nama = __String::createWithFormat("......")->getCString();
	nama->setString(teks_nama);
}
void Scene12::wali()
{
	auto teks_nama = __String::createWithFormat("Wali Kelas")->getCString();
	nama->setString(teks_nama);
}


