#include "Scene8.h"
#include "Scene10.h"
#include "Option.h"
#include "HomeMenu.h"
#include "SaveGame.h"
#include "LoadGame.h"

USING_NS_CC;



Scene* Scene8::scene()
{
	return Scene8::create();
}

bool Scene8::init()
{
	if (!Scene::init())
	{
		return false;
	}
	bgm->playBackgroundMusic("music/8.mp3", true);
	HomeMenu::game = 12;
	

	//background//
	background->setPosition(Vec2(0, 0));
	background->setAnchorPoint(Vec2(0, 0));
	this->addChild(background);
	/////////////

	this->schedule(schedule_selector(Scene8::delay_game), 1);

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
	btn_load->addClickEventListener(CC_CALLBACK_1(Scene8::load_game, this));
	btn_save->addClickEventListener(CC_CALLBACK_1(Scene8::save_game, this));
	btn_config->addClickEventListener(CC_CALLBACK_1(Scene8::config, this));
	btn_exit_no->addClickEventListener(CC_CALLBACK_1(Scene8::quit_no, this));
	btn_exit_yes->addClickEventListener(CC_CALLBACK_1(Scene8::quit_yes, this));
	btn_tittle->addClickEventListener(CC_CALLBACK_1(Scene8::back_title, this));
	btn_close->addClickEventListener(CC_CALLBACK_1(Scene8::close_menu, this));
	buttonStart->addClickEventListener(CC_CALLBACK_1(Scene8::startGame, this));
	btn_menu->addClickEventListener(CC_CALLBACK_1(Scene8::pil_menu, this));
	///////////////////////////
	//gambar karakter//
	anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	hiden_character();
	this->addChild(nana_sprite);
	this->addChild(anna_sprite);
	this->addChild(lily_sprite);
	//background//
	if (HomeMenu::nilai_teks > 21 && HomeMenu::nilai_teks < 33)
		background->setTexture("bg/rumah_nana.jpg");
	else if (HomeMenu::nilai_teks > 32 && HomeMenu::nilai_teks < 50)
		background->setTexture("bg/ruang_tengah_nana.jpg");
	else if (HomeMenu::nilai_teks > 49 && HomeMenu::nilai_teks < 78)
		background->setTexture("bg/kamar_nana.jpg");
	else if (HomeMenu::nilai_teks > 77)
		background->setTexture("bg/dapur.jpg");
	/////////////
	return true;
}
void Scene8::hiden_character()
{
	anna_sprite->setScale(0);
	nana_sprite->setScale(0);
	lily_sprite->setScale(0);
}
void Scene8::delay_game(float dt)
{
	detik++;

	if (detik == 4)
	{
		isi_teks();
		this->schedule(schedule_selector(Scene8::teksJalan), Option::speed_teks);
		unschedule(schedule_selector(Scene8::delay_game));
		detik = 0;
	}
	else if (detik == 3)
		buttonStart->setScale(1);
}


void Scene8::pil_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1400, 780)));
	btn_menu->setScale(0);

}

void Scene8::close_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1600, 780)));
	btn_menu->setScale(1);
}

void Scene8::back_title(Ref* sender)
{

	HomeMenu::btn_sound();
	bg_exit->setScale(1);
	kosong->setScale(1);
	btn_exit_no->setScale(1);
	btn_exit_yes->setScale(1);
	label_quit_no->setScale(1);
	label_quit_yes->setScale(1);

}

void Scene8::config(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, Option::scene(), Color3B(255, 255, 255)));
	})));

}
void Scene8::save_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, SaveGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene8::load_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, LoadGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene8::delay(float dt)
{
	if (detik == 1)
	{
		unschedule(schedule_selector(Scene8::delay));
		buttonStart->setScale(1);
		if (HomeMenu::nilai_teks == 22 || HomeMenu::nilai_teks == 33 || HomeMenu::nilai_teks == 50 || HomeMenu::nilai_teks == 78)
		{
			if (HomeMenu::nilai_teks == 33)
			{
				nana_sprite->setScale(0.6);
			}
			this->schedule(schedule_selector(Scene8::teksJalan), Option::speed_teks);
		}
		detik = 0;
	}
	detik++;
}
void Scene8::startGame(Ref* sender)
{
	unschedule(schedule_selector(Scene8::teksJalan));
	HomeMenu::btn_sound();
	HomeMenu::nilai_teks++;
	isi_teks();
	teks_1->setOpacity(0);
	i = 0;
	log("Nilai teks = %d", HomeMenu::nilai_teks);
	if (HomeMenu::nilai_teks == 22 || HomeMenu::nilai_teks == 33 || HomeMenu::nilai_teks == 50 || HomeMenu::nilai_teks == 78)
	{
		hiden_character();
		buttonStart->setScale(0);
		if (HomeMenu::nilai_teks > 21 && HomeMenu::nilai_teks < 33)
			background->setTexture("bg/rumah_nana.jpg");
		else if (HomeMenu::nilai_teks > 32 && HomeMenu::nilai_teks < 50)
			background->setTexture("bg/ruang_tengah_nana.jpg");
		else if (HomeMenu::nilai_teks > 49 && HomeMenu::nilai_teks < 78)
			background->setTexture("bg/kamar_nana.jpg");
		else if (HomeMenu::nilai_teks > 77)
			background->setTexture("bg/dapur.jpg");
		this->schedule(schedule_selector(Scene8::delay), 1.f);
	}
	else if (HomeMenu::nilai_teks == 125)
	{
		HomeMenu::nilai_teks = 1;
		this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
		{
			Director::getInstance()->replaceScene(TransitionFade::create(3, Scene10::scene(), Color3B(255, 255, 255)));
		})));
	}
	else
		this->schedule(schedule_selector(Scene8::teksJalan), Option::speed_teks);

}

void Scene8::isi_teks()
{
	if (HomeMenu::nilai_teks == 1)
	{
		nama_kosong();
		teks = __String::createWithFormat("Pagi ini, aku berpapasan dengan Nana dalam perjalanan \nmenuju kelas.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 2)
	{
		rei();
		teks = __String::createWithFormat("\"Hai.\"")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 3)
	{
		nana();
		teks = __String::createWithFormat("\"Ha-halo.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/3.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 4)
	{
		rei();
		teks = __String::createWithFormat("\"Kenapa gugup begitu? Hari ini kamu berhasil tidak terlambat lagi kan?\nMalahan, kamu biasanya tidak pernah sepagi ini.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/3.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 5)
	{
		nana();
		nana_sprite->setScale(0.6);
		teks = __String::createWithFormat("\"I-iya sih.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 6)
	{	
		rei();
		teks = __String::createWithFormat("\"Jangan-jangan kamu belum mengerjakan tugas untuk hari ini?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 7)
	{
		nana();
		teks = __String::createWithFormat("\"Eh?! Ada tugas?!\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 8)
	{	
		nana();
		teks = __String::createWithFormat("\"Gawat, aku belum mengerjakannya.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 9)
	{	
		nama_kosong();
		teks = __String::createWithFormat("Aku berani bertaruh 1 tahun gaji kerjaku kalau tidak akan ada yang tega \nmenjahili Nana setelah melihat reaksinya yang seperti itu.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 10)
	{
		rei();
		teks = __String::createWithFormat("\"Maaf, maaf. Aku hanya bercanda, tenang saja.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 11)
	{
		nana();
		teks = __String::createWithFormat("\"Eeh? Aku sempat berpikir kalau itu sungguhan.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 12)
	{
		nana();
		teks = __String::createWithFormat("\"Tapi aku juga sempat terkejut karena tidak biasanya \nRei ingat kalau ada tugas.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 13)
	{
		nama_kosong();
		teks = __String::createWithFormat("Candaanku berbalik menyerangku dengan cepat.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 14)
	{
		rei();
		teks = __String::createWithFormat("\"Ugh.. ya, aku rasa kamu benar.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 15)
	{
		nama_kosong();
		 
		teks = __String::createWithFormat("Tampaknya lelucon seperti itu memang tidak pantas dilakukan \noleh orang sepertiku.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 16)
	{
		nana();
		teks = __String::createWithFormat("\"Sebenarnya, aku tidak sempat menyelesaikan editan video kita kemarin.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/3.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 17)
	{
		rei();
		teks = __String::createWithFormat("\"Ah, tenang saja, tidak perlu membebani pikiran dengan hal \nkecil seperti itu.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/3.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 18)
	{
		nama_kosong();
		teks = __String::createWithFormat("Seseorang kutip perkataanku barusan.\nSedikit nasehat dari seseorang yang tidak pernah memikirkan apa-apa.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 19)
	{
		nana();
		teks = __String::createWithFormat("\"Aku ingin mengerjakannya nanti sepulang sekolah sih,\ntapi aku baru ingat kalau nanti aku akan rekaman dengan Rei.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 20)
	{
		rei();
		teks = __String::createWithFormat("\"Begitu ya, benar juga sih.\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 21)
	{
		rei();
		teks = __String::createWithFormat("\"Eh?\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 22)
	{
		nama_kosong();
		teks = __String::createWithFormat("Hari ini aku tidak ada shift di kafe, karena itu tidak ada alasan untuk \nmenolak ajakannya.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 23)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku juga tidak seharusnya terkejut. Kemarin malam,\notakku sudah memberi tahu kalau hal ini mungkin akan terjadi.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 24)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tapi, tidak ada yang memberitahuku kalau hari ini akan menjadi \nkali pertamanya aku berkunjung ke rumah seorang teman.\nTeman perempuan.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 25)
	{
		nama_kosong();
		teks = __String::createWithFormat("Turun dari mobil,\naku disambut oleh pemandangan menakjubkan yang mengeliliku.")->getCString();
		teks_1->setString(teks);
		
	}
	else if (HomeMenu::nilai_teks == 26)
	{
		nana();
		teks = __String::createWithFormat("\"Em.. Rei! Silahkan, segera masuk.\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 27)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku terbangun dari lamunanku. Terlepas dari ini adalah pertama kalinya \naku ke rumah seorang teman perempuan, rumah ini luar biasa besar.")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 28)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku yang tinggal di rumah kecil ini terkagum-kagum melihat kemegahan \nrumah ini.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 29)
	{
		rei();
		teks = __String::createWithFormat("\"Seingatku kamu pindah dari luar kota ya. Apa ini rumah saudaramu \natau bagaimana?\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 30)
	{
		nana();
		teks = __String::createWithFormat("\"Tidak, ini rumah kontrakan. Kami kebetulan mendapatkan \nrumah yang bagus untuk ditempati.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 31)
	{
		nama_kosong();
		teks = __String::createWithFormat("Kebetulan yang luar biasa bagus.")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 32)
	{
		rei();
		teks = __String::createWithFormat("\"Kalau begitu, maaf mengganggu.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 33)
	{
		nana();
		teks = __String::createWithFormat("\"Tenang saja Rei, hari ini tidak ada siapa-siapa kok.\nOrangtuaku pulang malam sekali.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 34)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tunggu, tunggu. Apa kamu benar-benar berpikir kalau aku bisa tenang \nsetelah mendengar hal seperti itu?")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 35)
	{
		nama_kosong();
		teks = __String::createWithFormat("Lagi-lagi mataku terpikat dengan kemewahan rumah ini.\nPerabotan-perabotan besar, lampu gantung yang berkilau, dan \ntangga raksasa di dalam rumah ini sangat menakjubkan.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 36)
	{
		nana();
		teks = __String::createWithFormat("\"Kamarku ada di lantai 2, ayo naik.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 37)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku hanya mengangguk kecil sambil masih mengamati rumah ini.")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 38)
	{
		rei();
		teks = __String::createWithFormat("\"Ka-kam-\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 39)
	{
		rei();
		teks = __String::createWithFormat("\"Kamar?!\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 40)
	{
		nana();
		teks = __String::createWithFormat("\"?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 41)
	{
		rei();
		teks = __String::createWithFormat("\"Ah.. tidak apa-apa.\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 42)
	{
		nama_kosong();
		teks = __String::createWithFormat("Entah bagaimana aku masih berhasil mempertahankan kesadaranku.\nJantungku serasa mau copot dari dadaku.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 43)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku menarik nafas panjang dan menghembuskannya.\nTenang saja, apa yang kamu khawatirkan Rei!")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 44)
	{
		nama_kosong();
		teks = __String::createWithFormat("Nana saja terlihat biasa saja.\nKenapa malah aku yang gugup begini!")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 45)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku menaiki anak-anak tangga, perlahan mengikuti Nana.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 46)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tidak! Tetap saja Nana yang aneh! Apa dia tidak mengerti situasi \nyang sedang dia alami sekarang?")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 47)
	{
		nama_kosong();
		teks = __String::createWithFormat("Akhirnya aku sampai di depan kamar Nana. Baiklah. Aku hanya perlu \nmelakukan rekaman sekitar 30 menit bersama dengan Nana,\nkemudian pulang. Itu saja. Itu saja.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 48)
	{
		nana();
		teks = __String::createWithFormat("\"Rei, kamu agak aneh.\nApa kamu benar-benar sudah istirahat kemarin?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 49)
	{
		rei();
		teks = __String::createWithFormat("\"Te-tenang saja! Aku baik-baik saja.\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 50)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku menghirup nafas panjang lagi,\ndan merasakan aroma wangi yang menenangkan.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 51)
	{
		nama_kosong();
		teks = __String::createWithFormat("Setelah beberapa saat terdiam bengong seperti orang bodoh,\naku memutuskan untuk duduk di dekat meja kecil yang ada \ndi tengah kamarnya.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 52)
	{
		nama_kosong();
		teks = __String::createWithFormat("Nana menyalakan komputer yang terletak di sudut kamarnya.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 53)
	{
		nana();
		teks = __String::createWithFormat("\"Jadi, game apa yang akan kita mainkan hari ini?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 54)
	{
		rei();
		teks = __String::createWithFormat("\"Yang jelas, bukan game yang aku mainkan di rekaman.\nGame itu single-player.\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 55)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku berpikir sejenak. Game apa ya yang mudah dimainkan? Maksudku,\ndia kan anak perempuan. Aku tidak terlalu yakin dengan kemampuannya \ndalam game.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 56)
	{
		rei();
		teks = __String::createWithFormat("\"Oh ya. Bagaimana kalau kita memainkan game yang sudah ada di \nkomputermu. Siapa tahu aku punya game yang sama di \nlaptopku.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 57)
	{
		nama_kosong();
		teks = __String::createWithFormat("Nana kemudian menyebutkan beberapa judul game kuno.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 58)
	{
		rei();
		teks = __String::createWithFormat("\"Lupakan saja, tidak jadi. Kalau kita bermain game itu,\ntidak akan ada yang menonton.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 59)
	{
		nana();
		teks = __String::createWithFormat("\"Benar juga.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 60)
	{
		rei();
		teks = __String::createWithFormat("\"...\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 61)
	{
		rei();
		teks = __String::createWithFormat("\"Ah! Aku sudah tahu apa yang sebaiknya kita mainkan.\nBoleh aku pinjam komputermu untuk mendownloadnya?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 62)
	{
		nana();
		teks = __String::createWithFormat("\"Silahkan.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 63)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku telah memutuskan. Game yang akan kami mainkan \nadalah game multiplayer online bergenre horror.")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	if (HomeMenu::nilai_teks == 64)
	{
		nama_kosong();
		teks = __String::createWithFormat("Di game ini, seorang player akan berperan sebagai pembunuh,\ndan player lainnya harus lari dan bersembunyi dari pembunuh tersebut.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 65)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku tersenyum sendiri membayangkan ekspresi ketakutan Nana.\nSekarang dia akan memakan omongannya sendiri karena telah mengejek \nekspresi ketakutanku.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 66)
	{
		nama_kosong();
		teks = __String::createWithFormat("Setelah berbagai persiapan yang panjang,\nkami akhirnya siap memulai rekaman kami.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 67)
	{
		nama_kosong();
		teks = __String::createWithFormat("Karena mejanya yang besar, aku masih bisa meletakkan laptopku \ndi sebelah monitor Nana. Jadi sekarang aku duduk di sebelah Nana.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 68)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dan, ya. Rasa gugup yang tadi telah hilang sementara,\nkembali menyerangku.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 69)
	{
		nana();
		teks = __String::createWithFormat("\"Aku pikir sebaiknya aku melihat Rei bermain dulu.\nAku benar-benar tidak tahu cara memainkannya.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 70)
	{
		rei();
		teks = __String::createWithFormat("\"Benar juga. Tapi tenang saja,\ngame ini mudah dimainkan kok.\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 71)
	{
		nama_kosong();
		teks = __String::createWithFormat("Beberapa menit kemudian, aku telah menyelesaikan satu ronde \npermainan sembari menjelaskan cara bermainnya pada Nana.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 72)
	{
		nana();
		teks = __String::createWithFormat("\"Gamenya seru sekali!\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 73)
	{
		rei();
		teks = __String::createWithFormat("\"Iya, aku tahu. Dari tadi kamu terus menjerit-jerit \ntepat di telingaku.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 74)
	{
		nana();
		teks = __String::createWithFormat("\"Ma-maaf.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/3.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 75)
	{
		rei();
		teks = __String::createWithFormat("\"Yang penting,\napa kita bisa mulai rekamannya sekarang?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/3.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 76)
	{
		nama_kosong();
		teks = __String::createWithFormat("Seumur-umur aku tidak pernah sedekat ini dengan perempuan.\nIni tidak baik untuk kesehatan jantungku, jadi aku ingin segera \nmengakhirinya.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 77)
	{
		nana();
		teks = __String::createWithFormat("\"Iya. Ayo kita mulai!\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 78)
	{
		nama_kosong();
		teks = __String::createWithFormat("Karena Nana meminta untuk bermain terus,\nkami akhirnya bermain hingga satu jam.\nAlhasil kami kelelahan dan mencari pasokan energi di dapur Nana.")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 79)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dapur di rumah ini juga tampak menarik di mataku.\nPeralatan makannya seragam dengan desain yang estetik sehingga \ntampak rapi dan indah dilihat.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 80)
	{
		nama_kosong();
		teks = __String::createWithFormat("Kullkasnya sendiri hampir seukuran lemari di rumahku.\nSepertinya isinya cukup untuk persediaan makanan satu abad.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 81)
	{
		nana();
		teks = __String::createWithFormat("\"Jus, susu, teh, atau.. em.. kalau kopi \nsepertinya harus membuatnya terlebih dahulu.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 82)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sebenarnya aku ingin kopi.\nTapi tampaknya merepotkan bila harus membuatnya lebih dulu.")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 83)
	{
		nama_kosong();
		teks = __String::createWithFormat("Susu bagus untuk nutrisi tubuhku. Tapi, apa tidak lucu \nkalau aku memilih susu? Meskipun Nana menawarkannya sih.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 84)
	{
		rei();
		teks = __String::createWithFormat("\"Aku teh saja.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 85)
	{
		nama_kosong();
		teks = __String::createWithFormat("Nana mengambil dua gelas dari rak, kemudian menuangkan teh untukku.\nIa kemudian membuka kulkas lagi untuk mengambil sekotak susu dan \nmenuangkannya untuk dirinya.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 86)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku sedikit menyesal. Tahu begitu aku juga memilih susu.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 87)
	{
		nana();
		teks = __String::createWithFormat("\"Ternyata bermain game melelahkan juga.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/3.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 88)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku nyaris tersedak melihat wajah Nana.\nDi detik berikutnya, aku berusaha menahan tawa.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/3.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 89)
	{
		nana();
		teks = __String::createWithFormat("\"Kenapa?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 90)
	{
		nana();
		teks = __String::createWithFormat("\"Jangan mengejekku yang kecapekan hanya karena bermain game.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/4.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 91)
	{
		rei();
		teks = __String::createWithFormat("\"Ti-tidak, b-bukan itu.\" \nAku susah payah berbicara.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/4.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 92)
	{
		nama_kosong();
		teks = __String::createWithFormat("Apa aku harus memberi tahunya? Kalau iya nanti dia malu.\nTapi.. aku akan memberitahunya deh.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 93)
	{
		rei();
		teks = __String::createWithFormat("\"A-ada bekas susu di atas bibirmu.\" \nKataku sambil sedikit memalingkan wajah.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 94)
	{
		nana();
		teks = __String::createWithFormat("\"O-oh?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/5.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 95)
	{
		nama_kosong();
		teks = __String::createWithFormat("Nana berusaha membersihkannya dengan bibir bawahnya.\nHal itu membuatku tertawa karena wajahnya menjadi sangat lucu.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/5.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 96)
	{
		nana();
		teks = __String::createWithFormat("\"H-hal ini biasa terjadi kalau sedang minum susu!\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/4.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 97)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku semakin kesulitan menghentikan tawaku karena alasannya..")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/4.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 98)
	{
		rei();
		teks = __String::createWithFormat("\"Kamu kan bisa meminumnya dengan pelan sehingga \nsusunya tidak sampai membekas di atas bibirmu.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 99)
	{
		nama_kosong();
		teks = __String::createWithFormat("Nana langsung meminum susunya lagi untuk mempraktekkan saranku.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 100)
	{
		nana();
		teks = __String::createWithFormat("\"Be-benar juga.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 101)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dapur kemudian sunyi setelahnya karena kami \nmemutuskan untuk minum tanpa banyak bicara.")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	if (HomeMenu::nilai_teks == 102)
	{
		nana();
		teks = __String::createWithFormat("\"Game tadi luar biasa ya! Rasanya benar-benar menegangkan \nbermain game itu!\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 103)
	{
		nama_kosong();
		teks = __String::createWithFormat("Nana tiba-tiba kembali membuka pembicaraan.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 104)
	{
		nana();
		teks = __String::createWithFormat("\"Sekarang aku kurang lebih tahu kenapa Rei sangat \nmenyukai game.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 105)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku senang kamu jadi lebih tertarik pada game,\ntapi aku harap kamu tidak sampai jatuh di lubang \nyang sama.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 106)
	{
		nama_kosong();
		teks = __String::createWithFormat("Mungkin seharusnya tadi gamenya aku uninstall dari komputer Nana \nagar dia tidak ketagihan.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 107)
	{
		nana();
		teks = __String::createWithFormat("\"Selain itu, video kita kali ini pasti akan sangat bagus!\nAku sudah tidak sabar ingin mengeditnya!\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 108)
	{
		nama_kosong();
		teks = __String::createWithFormat("Meskipun dia bilang begitu, aku bermain dengan payah tadi.\nApa yang Nana lakukan adalah terus berteriak-teriak dan \nmeminta tolong padaku.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 109)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku memang mengharapkan Nana agar ketakukan,\ntapi aku tidak menyangka Nana bisa sampai seperti itu.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 110)
	{
		nana();
		teks = __String::createWithFormat("\"Kapan-kapan ayo kita main lagi!\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 111)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku mengangguk sambil tertawa kecil.\nNana sangat terlihat gembira hari ini.")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	if (HomeMenu::nilai_teks == 112)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku.. senang melihatnya begitu.\nBerbeda dengan Nana yang pendiam.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 113)
	{
		rei();
		teks = __String::createWithFormat("\"Aku rasa, aku harus pulang sekarang.\nTerimakasih minumannya.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 114)
	{
		nana();
		teks = __String::createWithFormat("\"Aku akan panggilkan sopirku untuk mengantarmu.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 115)
	{
		rei();
		teks = __String::createWithFormat("\"Tidak usah, rumahku jauh sekali dari sini.\"")->getCString();
		teks_1->setString(teks);
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 116)
	{
		nana();
		teks = __String::createWithFormat("\"Kalau begitu aku malah akan memaksamu.\nKamu pasti nanti kelelahan di bus.\"")->getCString();
		teks_1->setString(teks);
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 117)
	{
		nana();
		teks = __String::createWithFormat("\"Aku ingin berterimakasih karena kamu telah menemaniku \nhari ini.\"")->getCString();
		teks_1->setString(teks);
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 118)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sebenarnya, aku juga menikmati hari ini. Dan aku sama sekali \ntidak lelah. Ini tidak ada apa-apanya dibandingkan shiftku \ndi kafe.")->getCString();
		teks_1->setString(teks);
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 119)
	{
		rei();
		teks = __String::createWithFormat("\"Kalau begitu, baiklah. Terimakasih kembali.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 120)
	{
		nana();
		teks = __String::createWithFormat("\"Sampai besok Rei! Oh ya, rekaman keduamu akan aku upload \nnanti malam setelah aku selesai mengeditnya.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 121)
	{
		rei();
		teks = __String::createWithFormat("\"Sudah aku bilang,\nkamu tidak perlu terlalu memikirkannya.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 122)
	{
		rei();
		teks = __String::createWithFormat("\"Kalau begitu, sudah dulu ya. Sampai besok, Nana.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 123)
	{
		nana();
		teks = __String::createWithFormat("\"!\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/5.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 124)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ya. Ini adalah pertama kalinya aku memanggilnya dengan nama,\nbukan 'kamu'.")->getCString();
		teks_1->setString(teks);
		 
	}
}


void Scene8::quit_yes(Ref* sender)
{
	HomeMenu::btn_sound();
	HomeMenu::nilai_logo = true;

	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		Director::getInstance()->replaceScene(TransitionFade::create(3, HomeMenu::scene(), Color3B(255, 255, 255)));
	})));
} //button tekan exit yes

void Scene8::quit_no(Ref* sender)
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
void Scene8::teksJalan(float dt)
{

	teks_satu();
}

void Scene8::teks_satu()
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
		unschedule(schedule_selector(Scene8::teksJalan));
	}
}

void Scene8::rei()
{
	auto teks_nama = __String::createWithFormat("Rei")->getCString();
	nama->setString(teks_nama);
}
void Scene8::anna()
{
	auto teks_nama = __String::createWithFormat("Anna")->getCString();
	nama->setString(teks_nama);
}
void Scene8::nana()
{
	auto teks_nama = __String::createWithFormat("Nana")->getCString();
	nama->setString(teks_nama);
}
void Scene8::nama_kosong()
{
	auto teks_nama = __String::createWithFormat("")->getCString();
	nama->setString(teks_nama);
}
void Scene8::nama_titik()
{
	auto teks_nama = __String::createWithFormat("......")->getCString();
	nama->setString(teks_nama);
}
void Scene8::wali()
{
	auto teks_nama = __String::createWithFormat("Wali Kelas")->getCString();
	nama->setString(teks_nama);
}


