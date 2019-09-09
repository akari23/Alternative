#include "Scene2a.h"
#include "Scene3.h"
#include "Option.h"
#include "HomeMenu.h"
#include "SaveGame.h"
#include "LoadGame.h"
#include "MiniGame1.h"

USING_NS_CC;



Scene* Scene2a::scene()
{
	return Scene2a::create();
}

bool Scene2a::init()
{
	if (!Scene::init())
	{
		return false;
	}
	bgm->playBackgroundMusic("music/2a.mp3", true);
	HomeMenu::game = 5;
	

	//background//
	background->setPosition(Vec2(0, 0));
	background->setAnchorPoint(Vec2(0, 0));
	this->addChild(background);
	 
	/////////////

	this->schedule(schedule_selector(Scene2a::delay_game), 1);

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
	btn_load->addClickEventListener(CC_CALLBACK_1(Scene2a::load_game, this));
	btn_save->addClickEventListener(CC_CALLBACK_1(Scene2a::save_game, this));
	btn_config->addClickEventListener(CC_CALLBACK_1(Scene2a::config, this));
	btn_exit_no->addClickEventListener(CC_CALLBACK_1(Scene2a::quit_no, this));
	btn_exit_yes->addClickEventListener(CC_CALLBACK_1(Scene2a::quit_yes, this));
	btn_tittle->addClickEventListener(CC_CALLBACK_1(Scene2a::back_title, this));
	btn_close->addClickEventListener(CC_CALLBACK_1(Scene2a::close_menu, this));
	buttonStart->addClickEventListener(CC_CALLBACK_1(Scene2a::startGame, this));
	btn_menu->addClickEventListener(CC_CALLBACK_1(Scene2a::pil_menu, this));
	////////////////////////////
	//gambar karakter//
	anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2+50));
	nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2+50));
	hiden_character();
	this->addChild(nana_sprite);
	this->addChild(anna_sprite);
	//////////////////
	if (HomeMenu::nilai_teks > 43 && HomeMenu::nilai_teks < 59)
		background->setTexture("bg/lab_jaringan.jpg");
	else if (HomeMenu::nilai_teks >58 && HomeMenu::nilai_teks < 63 )
		background->setTexture("bg/lorong_sb2.jpg");
	else if (HomeMenu::nilai_teks > 62 && HomeMenu::nilai_teks < 112)
		background->setTexture("bg/ruang_peralatan.jpg");
	else if (HomeMenu::nilai_teks > 111)
		background->setTexture("bg/lingkungan_kampus_2.jpg");
	return true;
}
void Scene2a::hiden_character()
{
	anna_sprite->setScale(0);
	nana_sprite->setScale(0);
}
void Scene2a::delay_game(float dt)
{
	detik++;

	if (detik == 4)
	{
		isi_teks();
		this->schedule(schedule_selector(Scene2a::teksJalan), Option::speed_teks);
		unschedule(schedule_selector(Scene2a::delay_game));
		detik = 0;
	}
	else if (detik == 3)
		buttonStart->setScale(1);
}


void Scene2a::pil_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1400, 780)));
	btn_menu->setScale(0);

}

void Scene2a::close_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1600, 780)));
	btn_menu->setScale(1);
}

void Scene2a::back_title(Ref* sender)
{

	HomeMenu::btn_sound();
	bg_exit->setScale(1);
	kosong->setScale(1);
	btn_exit_no->setScale(1);
	btn_exit_yes->setScale(1);
	label_quit_no->setScale(1);
	label_quit_yes->setScale(1);

}

void Scene2a::config(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, Option::scene(), Color3B(255, 255, 255)));
	})));

}
void Scene2a::save_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, SaveGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene2a::load_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, LoadGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene2a::delay(float dt)
{
	if (detik == 1)
	{
		unschedule(schedule_selector(Scene2a::delay));
		buttonStart->setScale(1);
		if (HomeMenu::nilai_teks == 44 || HomeMenu::nilai_teks == 15 || HomeMenu::nilai_teks == 59 || HomeMenu::nilai_teks == 63 || HomeMenu::nilai_teks == 112)
		{
			if (HomeMenu::nilai_teks == 63)
			{
				anna_sprite->setScale(0.6);
				voice->getInstance()->playEffect("voice/passage2a/63.mp3", false, 1.0f, 1.0f, 1.0f);
			}
			this->schedule(schedule_selector(Scene2a::teksJalan), Option::speed_teks);
		}
		detik = 0;
	}
	detik++;
}
void Scene2a::startGame(Ref* sender)
{
	unschedule(schedule_selector(Scene2a::teksJalan));
	
	HomeMenu::nilai_teks++;
	isi_teks();
	teks_1->setOpacity(0);
	i = 0;
	log("Nilai teks = %d", HomeMenu::nilai_teks);
	if (HomeMenu::nilai_teks == 44 || HomeMenu::nilai_teks == 59 || HomeMenu::nilai_teks == 63 || HomeMenu::nilai_teks == 112)
	{
		buttonStart->setScale(0);
		if (HomeMenu::nilai_teks > 43 && HomeMenu::nilai_teks < 59)
			background->setTexture("bg/lab_jaringan.jpg");
		else if (HomeMenu::nilai_teks >58 && HomeMenu::nilai_teks < 63)
			background->setTexture("bg/lorong_sb2.jpg");
		else if (HomeMenu::nilai_teks > 62 && HomeMenu::nilai_teks < 112)
			background->setTexture("bg/ruang_peralatan.jpg");
		else if (HomeMenu::nilai_teks > 111)
			background->setTexture("bg/lingkungan_kampus_2.jpg");
		this->schedule(schedule_selector(Scene2a::delay), 1.f);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 130)
	{
		HomeMenu::nilai_teks = 1;
		this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
		{
			Director::getInstance()->replaceScene(TransitionFade::create(3, Scene3::scene(), Color3B(255, 255, 255)));
		})));
	}
	else if (HomeMenu::nilai_teks == 83)
	{
		this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
		{
			Director::getInstance()->replaceScene(TransitionFade::create(1, MiniGame1::scene(), Color3B(255, 255, 255)));
		})));
	}
	else
		this->schedule(schedule_selector(Scene2a::teksJalan), Option::speed_teks);
	HomeMenu::btn_sound();
}

void Scene2a::isi_teks()
{
	if (HomeMenu::nilai_teks == 1)
	{
		nama_kosong();
		teks = __String::createWithFormat("Suasana dalam gedung sekolah sangat sepi ketika \nkami berjalan menyusuri lorongnya.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 2)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sekarang adalah waktu di mana mahasiswa 'pagi' sudah pulang atau \nberada di ormawa (organisasi mahasiswa), dan mahasiswa \n'sore/malam' berada dalam kelas.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 3)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ya. Saat ini adalah waktu di mana seharusnya aku duduk dengan santai \nmemainkan game.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 4)
	{
		nama_kosong();
		teks = __String::createWithFormat("Namun karena Anna menyinggunggku dengan sangat keras,\nkurasa aku akan tetap menemani Nana sebagai rasa terimakasih \nkarena telah membelikanku minuman.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 5)
	{
		voice->getInstance()->playEffect("voice/passage2a/5.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Kamu itu bagaimana sih, seharusnya kamu mengajak Nana ke dalam \ngedung sekolah dulu. Bagian terpentingnya kan di sini.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
	}
	else if (HomeMenu::nilai_teks == 6)
	{
		voice->getInstance()->pauseAllEffects();
		voice->getInstance()->playEffect("voice/passage2a/6.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Selain itu, sekarang sudah banyak ruang yang sedang di pakai \nuntuk perkuliahan.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
	}
	else if (HomeMenu::nilai_teks == 7)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Maafkan aku, aku tidak berpikir sejauh itu. Tadi aku \nberencana untuk memulai dari paling depan, kemudian ke belakang.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 8)
	{
		voice->getInstance()->playEffect("voice/passage2a/8.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Yah, aku memang tidak berharap banyak pada mu sih.. Tapi sudahlah,\nkita akan coba lihat-lihat ruangan yang tidak terpakai.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 9)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Ha? Apa coba maksudnya. Aku memasang wajah kesal selama mungkin. \nBerharap Anna melihatnya.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 10)
	{
		nama_kosong();
		teks = __String::createWithFormat("Selain itu, aku tidak mendengar ucapan terimakasih-nya sejak tadi.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 11)
	{
		nama_kosong();
		teks = __String::createWithFormat("Apa dia tidak sadar betapa menakjubkannya aku masih berada di sini \nmenemani kalian.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 12)
	{
		voice->getInstance()->playEffect("voice/passage2a/12.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Ah. Ruang kelas yang tadi kita pakai sedang digunakan.\nIni berarti ada beberapa laboratorium yang kosong di lantai atas. Ayo!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 13)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Ini adalah salah satu kelas teori, sesuai namanya, digunakan untuk \nbelajar teori saja.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 14)
	{
		rei();
		teks = __String::createWithFormat("\"Kelas teori lain ada di gedung lain. Karena jauh dan tidak ada \nyang menarik, kita tidak perlu ke sana.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 15)
	{
		nama_kosong();
		teks = __String::createWithFormat("Nana mengangguk kecil.\nAnna tersenyum menggoda padaku.")->getCString();
		teks_1->setString(teks);

		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 16)
	{
		voice->getInstance()->playEffect("voice/passage2a/16.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Ternyata sepertinya Rei melakukan tugasnya dengan baik ya? \nBagaimana menurutmu?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 17)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Lagi-lagi Nana hanya mengangguk kecil.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 18)
	{
		rei();
		teks = __String::createWithFormat("\"Sebenarnya apa maksudmu menyuruhku menemani Nana \nkalau kamu sebegitu tidak yakinnya?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 19)
	{
		voice->getInstance()->playEffect("voice/passage2a/19.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Aku sangat yakin kok.. Malahan, aku pikir Rei adalah \norang yang paling cocok.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 20)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Kenapa?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 21)
	{
		voice->getInstance()->playEffect("voice/passage2a/21.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Karena kalian berdua mirip kan?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 22)
	{
		voice->getInstance()->pauseAllEffects();
		voice->getInstance()->playEffect("voice/passage2a/22.mp3", false, 1.0f, 1.0f, 1.0f);
		auto teks_nama = __String::createWithFormat("Rei & Nana")->getCString();
		nama->setString(teks_nama);
		teks = __String::createWithFormat("\"Eh?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 23)
	{
		voice->getInstance()->pauseAllEffects();
		voice->getInstance()->playEffect("voice/passage2a/23.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Ya kan?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 24)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Apanya yang 'kan?'. Aku sama sekali tidak melihat kemiripan diantara \naku dan Nana. Apalagi kami beda jenis kelamin.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 25)
	{
		voice->getInstance()->playEffect("voice/passage2a/25.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Masa kalian tidak tahu sih?Kalian ini sama-sama bermasalah \ndalam komunikasi!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 26)
	{
		voice->getInstance()->pauseAllEffects();
		voice->getInstance()->playEffect("voice/passage2a/26.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Eehh???\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 27)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Aku sebenarnya juga terkejut, namun tidak seheboh Nana.\nAku rasa karena alasan kami berbeda.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 28)
	{
		nama_kosong();
		teks = __String::createWithFormat("Nana pasti heran bagaimana Anna bisa tahu kalau ia buruk \ndalam berkomunikasi.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 29)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sepertinya Nana benar-benar berpikir kalau ia telah terlihat \nseperti orang 'normal'.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 30)
	{
		rei();
		teks = __String::createWithFormat("Tentunya orang pasti tahu karena dia selalu diam saja,\nditambah cara berbicaranya yang seperti itu.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 31)
	{
		nama_kosong();
		teks = __String::createWithFormat("Namun aku tidak ingin mengatakan fakta itu pada Nana.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 32)
	{
		voice->getInstance()->playEffect("voice/passage2a/32.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Aku mungkin seperti itu, tapi.. aku rasa Rei tidak sama denganku\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 33)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Wah, ia menerima fakta bahwa penyamarannya telah terbongkar \nbegitu saja.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 34)
	{
		rei();
		teks = __String::createWithFormat("\"Ya, dia benar. Aku tidak sama dengannya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 35)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku bukan sulit berkomunikasi. Berbeda dengan Nana.\nAku hanya tidak ingin berbicara bila tidak benar - benar diperlukan.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}

	else if (HomeMenu::nilai_teks == 36)
	{
		voice->getInstance()->playEffect("voice/passage2a/36.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Tidak-tidak, kalian itu sama, karena itu aku pikir akan \nbagus bila Rei yang menemani Nana untuk keliling kampus.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 37)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Tidak-tidak, meskipun IPK-mu 4, aku benar-benar merasa kalau \ncara berpikirmu itu salah.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 38)
	{
		nama_kosong();
		teks = __String::createWithFormat("Apanya yang bagus menyuruh orang yang malas berbicara \nuntuk menemani orang yang tidak bisa berbicara?")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 39)
	{
		voice->getInstance()->playEffect("voice/passage2a/39.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Tapi, Rei berbicara dengan santai pada Anna.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 40)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Apa iya? Aku berpikir sejenak. Apa iya?")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 41)
	{
		voice->getInstance()->playEffect("voice/passage2a/41.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Mungkin lebih cocok disebut berdebat daripada berbicara.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 42)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Ah. Benar sekali. Kami hanya terlalu sering berdebat.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 43)
	{
		nama_kosong();
		teks = __String::createWithFormat("Nana hanya menatap kami dengan wajah setuju-tidak setuju.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 44)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sesampainya di lantai dua, kami menemukan salah satu laboratorium \nyang tidak sedang digunakan, dan memperkenalkan Nana pada \nruang tersebut.")->getCString();
		teks_1->setString(teks);
		hiden_character();
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 45)
	{
		voice->getInstance()->playEffect("voice/passage2a/41.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Mungkin kamu sempat melihat papan nama di depan,\ntapi mari aku kenalkan padamu, laboratorium jaringan komputer!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 46)
	{
		voice->getInstance()->pauseAllEffects();
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Nana melangkah ke tengah ruangan dan berjalan berkeliling.\nTampaknya ia ingin menanyakan sesuatu, dan hal itu disadari Anna.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 47)
	{
		voice->getInstance()->playEffect("voice/passage2a/47.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Monitor dan CPU-nya tertanam di dalam meja, \nkarena ada banyak aktivitas di atas meja ketika jam perkuliahan.\"")->getCString();
		teks_1->setString(teks);

		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 48)
	{
		voice->getInstance()->pauseAllEffects();
		voice->getInstance()->playEffect("voice/passage2a/49.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Aktivitas di atas meja?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 49)
	{
		voice->getInstance()->pauseAllEffects();
		voice->getInstance()->playEffect("voice/passage2a/49.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Hei, kamu jangan diam saja, bantu aku menjelaskan.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 50)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Eeh?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 51)
	{
		rei();
		hiden_character();
		teks = __String::createWithFormat("\"Yah.. maksudnya adalah.. praktikum jarkom (jaringan komputer) biasanya \nmenghubungkan komputer atau laptop dengan switch atau \naccess point...\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("jarkom.jpg");
		anna_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 ));
	}
	else if (HomeMenu::nilai_teks == 52)
	{
		hiden_character();
		rei();
		teks = __String::createWithFormat("\"Sehingga banyak kabel dan hal yang terjadi di atas meja.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 53)
	{
		voice->getInstance()->playEffect("voice/passage2a/53.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Ya, karena itu, untuk menghindari resiko monitor tersenggol ketika \npraktikum, berbeda dengan laboratorium lainnya, monitor di lab ini di \nmasukkan dalam meja.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 54)
	{
		voice->getInstance()->pauseAllEffects();
		voice->getInstance()->playEffect("voice/passage2a/54.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Tapi, anu.. sepertinya.. di lab ini tidak ada banyak alat.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 55)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Anna menatapku.Eh? Lagi? Ayolah..")->getCString();
		teks_1->setString(teks);

		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 56)
	{
		rei();
		teks = __String::createWithFormat("\"Itu karena semua peralatan jarkom di simpan di ruang lain.\"")->getCString();
		teks_1->setString(teks);

		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 57)
	{
		rei();
		teks = __String::createWithFormat("\"Setiap perkuliahan jarkom, kita mengambil alat yang diperlukan saja \ndi ruang tersebut.\"")->getCString();
		teks_1->setString(teks);

		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 58)
	{
		voice->getInstance()->playEffect("voice/passage2a/58.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Nanti kita akan ke ruangan itu. Sekarang ayo kita keluar dan \nlihat apakah ada laboratorium kosong lainnya.\"")->getCString();
		teks_1->setString(teks);

		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 59)
	{
		voice->getInstance()->pauseAllEffects();
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Kami keluar dari laboratorium jaringan komputer, lalu mengintip kaca \ntiap laboratorium untuk memastikan apakah ruang itu sedang \ndigunakan atau tidak.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 60)
	{
		voice->getInstance()->playEffect("voice/passage2a/60.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Sayang sekali, banyak laboratorium yang digunakan saat ini.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 61)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Benar-benar disayangkan.Aku berusaha menahan senyumku,\nnamun Anna menyadarinya dan melotot kepadaku.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 62)
	{
		rei();
		teks = __String::createWithFormat("\"Karena itu, sebaiknya kita segera berkunjung ke ruang peralatan...\" \nkataku dengan segera, menghindari tatapan Anna.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 63)
	{
		voice->getInstance()->playEffect("voice/passage2a/63.mp3", false, 1.0f, 1.0f, 1.0f);
		hiden_character();
		anna();
		teks = __String::createWithFormat("\"Permisi..!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
		 
	}
	else if (HomeMenu::nilai_teks == 64)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Para teknisinya tidak sedang di sini.\nMungkin ada panggilan di ruang lain.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 65)
	{
		voice->getInstance()->playEffect("voice/passage2a/65.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Selamat datang di ruang paling mahal di program studi informatika!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 66	)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Paling mahal?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 67)
	{
		voice->getInstance()->playEffect("voice/passage2a/67.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Ya! Menurutku semua barang yang ada di sini kalau di total \nbisa mencapai satu miliar. Atau mungin lebih!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 68)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Ah. Benar juga. Sudah dua tahun aku kuliah di sini tapi \nbaru pertama kali ini aku menyadarinya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 69)
	{
		voice->getInstance()->playEffect("voice/passage2a/69.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Eeh? Apa bukan suatu masalah bila kita berada di sini?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 70)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Entahlah. Kamu benar juga. Mungkin kita sebaiknya segera-\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 71)
	{
		voice->getInstance()->playEffect("voice/passage2a/71.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Tidak ada masalah sama sekali!\" \nkata Anna sambil mencubit punggungku sehingga tidak terlihat Nana.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 72)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Ahh-ah!\" aku mengeluarkan teriakan kecil yang terdengar aneh.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 73)
	{
		nama_kosong();
		teks = __String::createWithFormat("Nana menyadarinya dan menoleh ke arahku, namun Anna segera \nmelanjutkan pembicaraan.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 74)
	{
		voice->getInstance()->playEffect("voice/passage2a/74.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Di ruangan ini, dan tentunya di setiap ruangan, ada CCTV,\njadi selama kita bertindak wajar, tidak akan ada masalah.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 75)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Ya, begitulah. Dan seperti yang kamu lihat, ada banyak sekali peralatan \ndi sini untuk mendukung kegiatan pembelajaran kita.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 76)
	{
		voice->getInstance()->playEffect("voice/passage2a/76.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Sok tahu sekali kamu. Memangnya kamu tahu fungsi dan kegunaan \nalat-alat di sini?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 77)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Heh. Kamu terlalu meremehkanku.\nAkupun bisa menyebutkan empat fungsi alat di sini.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 78)
	{
		nama_kosong();
		teks = __String::createWithFormat("Anna tersenyum mengejek, bahkan Nana tertawa kecil.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 79)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sial. Aku tidak bermaksud bercanda padahal.\nApa empat alat terlalu sedikit?")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 80)
	{
		voice->getInstance()->playEffect("voice/passage2a/80.mp3", false, 1.0f, 1.0f, 1.0f);
		rei();
		teks = __String::createWithFormat("\"Coba sebutkan saja. Jangan mempermalukan program studi \ndan kampus kita.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 81)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Kalau begitu kamu saja yang menyebutkan.\nAku jadi tidak terlalu yakin dengan ingatanku.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 82)
	{
		nama_kosong();
		teks = __String::createWithFormat("Mungkin kenyataannya aku hanya tahu dua fungsi alat di ruangan ini.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 84)
	{
		voice->getInstance()->playEffect("voice/passage2a/83.mp3", false, 1.0f, 1.0f, 1.0f);
		hiden_character();
		anna();
		teks = __String::createWithFormat("\"Rei memang hanya bisa menyebutkan beberapa alat saja, \ndan semuanya peralatan jaringan komputer.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 85)
	{
		voice->getInstance()->pauseAllEffects();

		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Aku berusaha semampuku.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 86)
	{
		voice->getInstance()->playEffect("voice/passage2a/85.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Tapi tentunya masih banyak alat yang ada di sini, \ndan bukan hanya untuk mata kuliah jarkom saja.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 87)
	{
		voice->getInstance()->pauseAllEffects();
		hiden_character();
		rei();
		teks = __String::createWithFormat("\"Eh, benarkah?\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 88)
	{
		voice->getInstance()->playEffect("voice/passage2a/87.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Ya, itulah kenapa kamu perlu melihat jadwal perkuliahan.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 89)
	{
		voice->getInstance()->pauseAllEffects();
		voice->getInstance()->playEffect("voice/passage2a/88.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Di semester ini, kita akan menerima mata kuliah embedded system, \nyang berkaitan erat dengan IoT.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 90)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"IoT? Rasanya aku pernah mendengarnya..\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 91)
	{
		hiden_character();
		voice->getInstance()->playEffect("voice/passage2a/90.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"IoT adalah singkatan dari Internet of Things---\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.4);
		anna_sprite->setTexture("iot.jpg");
		anna_sprite->setPosition(Vec2(1366 / 2 , 768 / 2+50 ));

	}
	else if (HomeMenu::nilai_teks == 92)
	{
		hiden_character();
		voice->getInstance()->pauseAllEffects();
		voice->getInstance()->playEffect("voice/passage2a/91.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"konsep dimana berbagai macam objek terus terhubung ke internet \nuntuk mengirim data.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.4);
		anna_sprite->setTexture("iot.jpg");
		anna_sprite->setPosition(Vec2(1366 / 2 , 768 / 2+50));
	}
	else if (HomeMenu::nilai_teks == 93)
	{
		hiden_character();
		voice->getInstance()->pauseAllEffects();
		voice->getInstance()->playEffect("voice/passage2a/92.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Membayangkan berbagai hal terhubung ke internet rasanya seperti \nberada di masa depan.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 94)
	{
		rei();
		teks = __String::createWithFormat("\"Hoo.. memang terdengar keren.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 95)
	{
		rei();
		teks = __String::createWithFormat("\"Kamu tahu banyak juga..\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 96)
	{
		voice->getInstance()->playEffect("voice/passage2a/95.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Ah.. tidak.. karena aku mahasiswa TI aku jadi sering mendengarnya \nsaja.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 97)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("Anna tersenyum mengejek padaku.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 98)
	{
		hiden_character();
		rei();
		teks = __String::createWithFormat("\"Jadi.. Alat IoT seperti apa yang ada di sini?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("sensor.jpg");
		anna_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 ));
	}
	else if (HomeMenu::nilai_teks == 99)
	{
		hiden_character();
		voice->getInstance()->playEffect("voice/passage2a/98.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Kalau itu.. aku sendiri belum tahu. Tapi yang jelas ada banyak sensor \natau alat untuk membaca berbagai jenis kondisi lingkungan.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 100)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Oh ya, aku baru ingat. Disini juga ada peralatan untuk \nmembongkar komputer.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 101)
	{
		voice->getInstance()->playEffect("voice/passage2a/100.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Meskipun begini, Rei ini ahli membongkar komputer.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 102)
	{
		voice->getInstance()->pauseAllEffects();
		voice->getInstance()->playEffect("voice/passage2a/101.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Wah.. benarkah?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 103)
	{
		voice->getInstance()->pauseAllEffects();
		voice->getInstance()->playEffect("voice/passage2a/102.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Iya! Tapi sayangnya dia tidak bisa mengembalikannya seperti semula.\nHanya bisa membongkar saja.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/3.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 104)
	{
		voice->getInstance()->pauseAllEffects();
		voice->getInstance()->playEffect("voice/passage2a/103.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Oh.. sayang sekali..\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/3.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 105)
	{
		nama_kosong();
		teks = __String::createWithFormat("Nana menatapku dengan iba. Mahasiswi pindahan ini benar-benar \nmenganggap serius perkataan Anna.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/3.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 106)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku sendiri memutuskan untuk tidak membela diri. \nMeskipun faktanya aku jago dalam membongkar-pasang komputer maupun laptop.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 107)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sebagai seorang gamer, aku sering membersihkan bagian \ndalam laptopku untuk mendapatkan performa terbaik.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 108)
	{
		rei();
		teks = __String::createWithFormat("\"Aku rasa, keliling kampus hari ini cukup sampai disini.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 109)
	{
		voice->getInstance()->playEffect("voice/passage2a/108.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Ya, sepertinya begitu. Mau bagaimana lagi, \nuntuk saat ini sudah tidak ada ruangan yang bisa kita kunjungi lagi.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 110)
	{
		voice->getInstance()->pauseAllEffects();
		voice->getInstance()->playEffect("voice/passage2a/109.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Kapan-kapan kita lanjutkan lagi.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 111)
	{
		hiden_character();
		rei();
		teks = __String::createWithFormat("\"Jangan ikutkan aku dalam kata 'kita' oke?\"")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 112)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Aku harus memastikan aku tidak ikut dalam acara \njalan-jalan ini lagi.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 113)
	{
		voice->getInstance()->playEffect("voice/passage2a/112.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Kamu pulang naik apa Nana?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 114)
	{
		voice->getInstance()->pauseAllEffects();
		voice->getInstance()->playEffect("voice/passage2a/113.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Aku.. sebentar lagi aku akan dijemput.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 115)
	{
		voice->getInstance()->pauseAllEffects();
		voice->getInstance()->playEffect("voice/passage2a/114.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Oh begitu, apa perlu kami tunggu dulu?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 116)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Hei-hei. Apa maksudnya dengan 'kami'.\nBerhenti seenaknya mengikut-campurkanku dalam segala hal.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 117)
	{
		voice->getInstance()->playEffect("voice/passage2a/116.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Tidak perlu, aku sudah terlalu merepotkan.\nKalian pulang duluan saja.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 118)
	{
		voice->getInstance()->pauseAllEffects();
		voice->getInstance()->playEffect("voice/passage2a/117.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Te.. te-terima kasih.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 119)
	{
		voice->getInstance()->pauseAllEffects();
		voice->getInstance()->playEffect("voice/passage2a/118.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Sama-sama. Baiklah kalau begitu, \naku pulang duluan ya. Sampai jumpa besok!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 120)
	{
		voice->getInstance()->pauseAllEffects();
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Anna menuju parkiran, meninggalkan kami berdua.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
		 
	}
	if (HomeMenu::nilai_teks == 121)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku juga ingin segera pergi, namun bingung apakah perlu \nmengatakan sesuatu kepadanya atau tidak.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 122)
	{
		nama_kosong();
		teks = __String::createWithFormat("Seperti.. ucapan selamat tinggal atau semacamnya.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 123)
	{
		rei();
		teks = __String::createWithFormat("\"Em.. aku juga..\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 124)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sial. Aku bingung dengan apa yang harus aku ucapkan.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 125)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dari awal seharusnya aku langsung pergi saja.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 126)
	{
		voice->getInstance()->playEffect("voice/passage2a/125.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Te-terima kasih Rei.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 127)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Eh.. Ya..\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 128)
	{
		nama_kosong();
		teks = __String::createWithFormat("Seingatku dia sudah mengucapkan terimakasih tadi.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 129)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku memutuskan untuk menganggukkan kepala sebagai bentuk \nucapan selamat tinggalku dan bergegas menuju halte.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}

}


void Scene2a::quit_yes(Ref* sender)
{
	HomeMenu::btn_sound();
	HomeMenu::nilai_logo = true;

	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		Director::getInstance()->replaceScene(TransitionFade::create(3, HomeMenu::scene(), Color3B(255, 255, 255)));
	})));
} //button tekan exit yes

void Scene2a::quit_no(Ref* sender)
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
void Scene2a::teksJalan(float dt)
{

	teks_satu();
}

void Scene2a::teks_satu()
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
		unschedule(schedule_selector(Scene2a::teksJalan));
	}
}

void Scene2a::rei()
{
	auto teks_nama = __String::createWithFormat("Rei")->getCString();
	nama->setString(teks_nama);
}
void Scene2a::anna()
{
	auto teks_nama = __String::createWithFormat("Anna")->getCString();
	nama->setString(teks_nama);
}
void Scene2a::nana()
{
	auto teks_nama = __String::createWithFormat("Nana")->getCString();
	nama->setString(teks_nama);
}
void Scene2a::nama_kosong()
{
	auto teks_nama = __String::createWithFormat("")->getCString();
	nama->setString(teks_nama);
}
void Scene2a::nama_titik()
{
	auto teks_nama = __String::createWithFormat("......")->getCString();
	nama->setString(teks_nama);
}
void Scene2a::wali()
{
	auto teks_nama = __String::createWithFormat("Wali Kelas")->getCString();
	nama->setString(teks_nama);
}


