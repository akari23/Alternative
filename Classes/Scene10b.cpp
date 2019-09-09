#include "Scene10b.h"
#include "Scene14.h"
#include "Option.h"
#include "HomeMenu.h"
#include "SaveGame.h"
#include "LoadGame.h"

USING_NS_CC;



Scene* Scene10b::scene()
{
	return Scene10b::create();
}

bool Scene10b::init()
{
	if (!Scene::init())
	{
		return false;
	}
	bgm->playBackgroundMusic("music/10b.mp3", true);
	HomeMenu::game = 14;
	

	//background//
	background->setPosition(Vec2(0, 0));
	background->setAnchorPoint(Vec2(0, 0));
	this->addChild(background);
	/////////////

	this->schedule(schedule_selector(Scene10b::delay_game), 1);

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
	btn_load->addClickEventListener(CC_CALLBACK_1(Scene10b::load_game, this));
	btn_save->addClickEventListener(CC_CALLBACK_1(Scene10b::save_game, this));
	btn_config->addClickEventListener(CC_CALLBACK_1(Scene10b::config, this));
	btn_exit_no->addClickEventListener(CC_CALLBACK_1(Scene10b::quit_no, this));
	btn_exit_yes->addClickEventListener(CC_CALLBACK_1(Scene10b::quit_yes, this));
	btn_tittle->addClickEventListener(CC_CALLBACK_1(Scene10b::back_title, this));
	btn_close->addClickEventListener(CC_CALLBACK_1(Scene10b::close_menu, this));
	buttonStart->addClickEventListener(CC_CALLBACK_1(Scene10b::startGame, this));
	btn_menu->addClickEventListener(CC_CALLBACK_1(Scene10b::pil_menu, this));
	///////////////////////////
	//gambar karakter//
	anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	hiden_character();
	this->addChild(nana_sprite);
	this->addChild(anna_sprite);
	/////////////////////////
	//background//
	if (HomeMenu::nilai_teks > 19)
		background->setTexture("bg/dapur.jpg");
	/////////////
	return true;
}void Scene10b::hiden_character()
{
	anna_sprite->setScale(0);
	nana_sprite->setScale(0);
}
void Scene10b::delay_game(float dt)
{
	detik++;

	if (detik == 4)
	{
		isi_teks();
		this->schedule(schedule_selector(Scene10b::teksJalan), Option::speed_teks);
		unschedule(schedule_selector(Scene10b::delay_game));
		detik = 0;
	}
	else if (detik == 3)
		buttonStart->setScale(1);
}


void Scene10b::pil_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1400, 780)));
	btn_menu->setScale(0);

}

void Scene10b::close_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1600, 780)));
	btn_menu->setScale(1);
}

void Scene10b::back_title(Ref* sender)
{

	HomeMenu::btn_sound();
	bg_exit->setScale(1);
	kosong->setScale(1);
	btn_exit_no->setScale(1);
	btn_exit_yes->setScale(1);
	label_quit_no->setScale(1);
	label_quit_yes->setScale(1);

}

void Scene10b::config(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, Option::scene(), Color3B(255, 255, 255)));
	})));

}
void Scene10b::save_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, SaveGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene10b::load_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, LoadGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene10b::delay(float dt)
{
	if (detik == 1)
	{
		unschedule(schedule_selector(Scene10b::delay));
		buttonStart->setScale(1);
		if (HomeMenu::nilai_teks == 20)
		{
			nana_sprite->setScale(0.6);
			this->schedule(schedule_selector(Scene10b::teksJalan), Option::speed_teks);
		}
		detik = 0;
	}
	detik++;
}
void Scene10b::startGame(Ref* sender)
{
	unschedule(schedule_selector(Scene10b::teksJalan));
	HomeMenu::btn_sound();
	HomeMenu::nilai_teks++;
	isi_teks();
	teks_1->setOpacity(0);
	i = 0;
	log("Nilai teks = %d", HomeMenu::nilai_teks);
	if (HomeMenu::nilai_teks == 20)
	{
		hiden_character();
		buttonStart->setScale(0);
		if (HomeMenu::nilai_teks > 19)
			background->setTexture("bg/dapur.jpg");
		this->schedule(schedule_selector(Scene10b::delay), 1.f);
	}
	else if (HomeMenu::nilai_teks == 61)
	{
		HomeMenu::nilai_teks = 1;
		this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
		{
			Director::getInstance()->replaceScene(TransitionFade::create(3, Scene14::scene(), Color3B(255, 255, 255)));
		})));
	}
	else
		this->schedule(schedule_selector(Scene10b::teksJalan), Option::speed_teks);

}

void Scene10b::isi_teks()
{
	if (HomeMenu::nilai_teks == 1)
	{
		nana();
		teks = __String::createWithFormat("\"Apakah Lily akan baik-baik saja?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 2)
	{
		rei();
		teks = __String::createWithFormat("\"Tenang saja, meskipun begitu, dia itu cerdas.\nUm, mungkin lebih tepatnya penuh rencana.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 3)
	{
		rei();
		teks = __String::createWithFormat("\"Dia pasti sudah punya cadangan orang lain yang bisa memenuhi kuota.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 4)
	{
		nana();
		teks = __String::createWithFormat("\"Tapi, sepertinya Lily benar-benar berharap kita bisa ikut.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 5)
	{
		rei();
		teks = __String::createWithFormat("\"Kalau itu, aku tidak tahu kenapa.\nMungkin.. entahlah.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 6)
	{	
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Hari ini adalah hari Jum’at. Seperti minggu lalu,\naku main ke rumah Nana untuk rekaman bersama.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 7)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku harap rutinitas ini tidak berjalan selamanya.\nSelain malas, aku tidak enak dengan sopirnya yang pasti akan \nmengantarku lagi nanti.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 8)
	{	
		nama_kosong();
		teks = __String::createWithFormat("Dan bisa jadi suatu saat aku bertemu orang tua Nana.\nUwah, membayangkan hal itu membuatku merinding.\nRasanya pasti akan canggung sekali.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 9)
	{	
		nana();
		teks = __String::createWithFormat("\"Jadi, apa yang akan kita mainkan hari ini?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 10)
	{
		rei();
		teks = __String::createWithFormat("\"Aku tidak datang dengan persiapan,\njadi bagaimana kalau game yang minggu lalu-\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 11)
	{
		nana();
		teks = __String::createWithFormat("\"Ya! Ayo kita main itu! Aku cukup yakin bisa mengimbangi Rei!\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 12)
	{
		nama_kosong();
		teks = __String::createWithFormat("Eh? Jangan bilang dia..")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 13)
	{
		rei();
		teks = __String::createWithFormat("\"Setelah terakhir kali kita bermain bersama,\nberapa kali lagi kamu main?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 14)
	{
		nana();
		teks = __String::createWithFormat("\"Setiap hari! Gamenya benar-benar seru!\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 15)
	{
		nama_kosong();
		 
		teks = __String::createWithFormat("Setelah ini aku harus benar-benar meng-uninstall game itu dari \nkomputernya.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 16)
	{
		nana();
		teks = __String::createWithFormat("\"Selain itu, penonton kita juga menyukai video yang kita buat.\nBahkan mereka memberikan berbagai tips yang tidak kamu beri tahu.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 17)
	{
		nana();
		teks = __String::createWithFormat("\"Pokoknya ayo segera bersiap!\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 18)
	{
		rei();
		teks = __String::createWithFormat("\"Ba-baiklah.\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 19)
	{
		nama_kosong();
		teks = __String::createWithFormat("Lagi-lagi, dia kalau bersemangat benar-benar berbeda.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 20)
	{
		nana();
		teks = __String::createWithFormat("\"Teh?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 21)
	{
		rei();
		teks = __String::createWithFormat("\"Um, kali ini aku mungkin akan minum susu.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 22)
	{
		nana();
		teks = __String::createWithFormat("\"...\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 23)
	{
		rei();
		teks = __String::createWithFormat("\"Kenapa?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 24)
	{
		nana();
		teks = __String::createWithFormat("\"Tidak,\naku tidak menduga kalau Rei akan minum susu.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 25)
	{
		rei();
		teks = __String::createWithFormat("\"Memangnya kenapa? Susu itu minuman untuk semua umur.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 26)
	{
		nama_kosong();
		teks = __String::createWithFormat("\"Nana kemudian membuka kulkas dan menuangkan susu ke dua gelas kaca \ndi depannya.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 27)
	{
		nana();
		teks = __String::createWithFormat("\"Ini\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 28)
	{
		rei();
		teks = __String::createWithFormat("\"Terimakasih\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 29)
	{
		nama_kosong();
		teks = __String::createWithFormat("Wah, rasanya segar sekali. Setiap kali aku bermain game bersama Nana,\nentah kenapa rasanya aku lebih banyak mengeluarkan tenaga.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 30)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku melihat ke arah Nana, dan ternyata ia masih memperhatikanku.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 31)
	{
		rei();
		teks = __String::createWithFormat("\"Apa benar-benar aneh?\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 32)
	{
		nana();
		teks = __String::createWithFormat("\"Iya, Rei jadi seperti anak kecil.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 33)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku nyaris tersedak karena ucapannya.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 34)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku benar-benar tidak ingin mendengar itu dari orang yang \njuga meminumnya.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 35)
	{
		nana();
		teks = __String::createWithFormat("\"Apa setelah ini kita bisa main lagi?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 36)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tidak akan. Apa dia tidak tahu situasinya?\nSebentar lagi orang tuanya akan pulang,\napa dia tidak keberatan dengan hal itu?")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 37)
	{
		rei();
		teks = __String::createWithFormat("\"Sekarang sudah cukup malam, selain itu tadi kita sudah \nbermain sangat lama.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 38)
	{
		nana();
		teks = __String::createWithFormat("\"Be-benar juga.\" \nNana menundukkan pandangannya.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/3.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 39)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Sepertinya dia benar-benar ingin bermain lagi. Tapi,\naku harus pulang sekarang. Harus menyimpan tenaga untuk shift \nbesok Sabtu.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 40)
	{
		nama_kosong();
		teks = __String::createWithFormat("Oh ya. Aku jadi ingat. Apa sebaiknya aku katakan sekarang \nkalau aku punya pekerjaan di kafe?")->getCString();
		teks_1->setString(teks);
		 
	}
	 else if (HomeMenu::nilai_teks == 41)
	 {
		 auto teks_nama = __String::createWithFormat("Rei & Nana")->getCString();
		 nama->setString(teks_nama);
	 	teks = __String::createWithFormat("\"Um...\"")->getCString();
	 	teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	 }
	else if (HomeMenu::nilai_teks == 42)
	{
		rei();
		teks = __String::createWithFormat("\"Ah, kamu duluan saja.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 43)
	{
		nana();
		teks = __String::createWithFormat("\"Ba-baik\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 44)
	{
		nana();
		teks = __String::createWithFormat("\"Aku besok akan pergi jalan-jalan dengan keluargaku.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 45)
	{
		rei();
		teks = __String::createWithFormat("\"Oh benarkah? Kedengarannya menyenangkan.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 46)
	{
		nana();
		teks = __String::createWithFormat("\"Iya, memang. Kami hanya ingin jalan-jalan di kota ini saja sih.\nKami belum pernah ada kesempatan sampai besok.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 47)
	{
		rei();
		teks = __String::createWithFormat("\"Eh? Kalau begitu, bukannya kamu tidak jadi jalan-jalan dengan keluargamu \nkalau kita pergi ke gunung? Jadwalnya sama kan?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 48)
	{
		nana();
		teks = __String::createWithFormat("Sebenarnya tidak masalah sih, kami bisa pergi minggu depannya lagi.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 49)
	{
		rei();
		teks = __String::createWithFormat("\"Oh, begitu.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 50)
	{
		nana();
		teks = __String::createWithFormat("\"Maaf, tidak begitu penting, aku hanya ingin menceritakannya \nsaja.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/5.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 51)
	{
		rei();
		teks = __String::createWithFormat("\"Tidak apa-apa. Besok Senin ceritakan bagaimana \nperjalananmu padaku dan Anna.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 52)
	{
		nana();
		teks = __String::createWithFormat("\"Iya. Bagaimana denganmu?\nTadi kamu ingin mengatakan sesuatu.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 53)
	{
		rei();
		teks = __String::createWithFormat("\"Ah, tidak apa-apa. Lebih tidak penting lagi.\" \nAku memutuskan untuk tidak mengatakannya.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 54)
	{
		rei();
		teks = __String::createWithFormat("\"Kalau begitu, aku tunggu ceritamu besok Senin.\nHati-hati ya, Nana.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 55)
	{
		nana();
		teks = __String::createWithFormat("\"Iya, sampai jumpa besok Senin.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 56)
	{
		rei();
		teks = __String::createWithFormat("\"Oh ya. Satu hal lagi.\nJangan.. jangan terlalu banyak bermain game.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 57)
	{
		nana();
		teks = __String::createWithFormat("\"Ahahaha. Rei bilang seperti itu?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 58)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku hanya khawatir kamu jadi sepertiku.")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 59)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku kemudian berjalan ke garasi dimana \nsopirnya Nana sudah menunggu.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 60)
	{
		nama_kosong();
		teks = __String::createWithFormat("Kali ini, aku dengan yakin duduk di sebelahnya.\nAku tidak akan bersikap kekanak-kanakan dengan menghindari \nkecanggungan dan duduk di belakang.")->getCString();
		teks_1->setString(teks);
		 
	}
}


void Scene10b::quit_yes(Ref* sender)
{
	HomeMenu::btn_sound();
	HomeMenu::nilai_logo = true;

	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		Director::getInstance()->replaceScene(TransitionFade::create(3, HomeMenu::scene(), Color3B(255, 255, 255)));
	})));
} //button tekan exit yes

void Scene10b::quit_no(Ref* sender)
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
void Scene10b::teksJalan(float dt)
{

	teks_satu();
}

void Scene10b::teks_satu()
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
		unschedule(schedule_selector(Scene10b::teksJalan));
	}
}

void Scene10b::rei()
{
	auto teks_nama = __String::createWithFormat("Rei")->getCString();
	nama->setString(teks_nama);
}
void Scene10b::anna()
{
	auto teks_nama = __String::createWithFormat("Anna")->getCString();
	nama->setString(teks_nama);
}
void Scene10b::nana()
{
	auto teks_nama = __String::createWithFormat("Nana")->getCString();
	nama->setString(teks_nama);
}
void Scene10b::nama_kosong()
{
	auto teks_nama = __String::createWithFormat("")->getCString();
	nama->setString(teks_nama);
}
void Scene10b::nama_titik()
{
	auto teks_nama = __String::createWithFormat("......")->getCString();
	nama->setString(teks_nama);
}
void Scene10b::wali()
{
	auto teks_nama = __String::createWithFormat("Wali Kelas")->getCString();
	nama->setString(teks_nama);
}


