#include "Scene14.h"
#include "Option.h"
#include "HomeMenu.h"
#include "SaveGame.h"
#include "LoadGame.h"

USING_NS_CC;



Scene* Scene14::scene()
{
	return Scene14::create();
}

bool Scene14::init()
{
	if (!Scene::init())
	{
		return false;
	}
	bgm->playBackgroundMusic("music/14.mp3", true);
	HomeMenu::game = 15;
	

	//background//
	background->setPosition(Vec2(0, 0));
	background->setAnchorPoint(Vec2(0, 0));
	this->addChild(background);
	/////////////

	this->schedule(schedule_selector(Scene14::delay_game), 1);

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
	btn_load->addClickEventListener(CC_CALLBACK_1(Scene14::load_game, this));
	btn_save->addClickEventListener(CC_CALLBACK_1(Scene14::save_game, this));
	btn_config->addClickEventListener(CC_CALLBACK_1(Scene14::config, this));
	btn_exit_no->addClickEventListener(CC_CALLBACK_1(Scene14::quit_no, this));
	btn_exit_yes->addClickEventListener(CC_CALLBACK_1(Scene14::quit_yes, this));
	btn_tittle->addClickEventListener(CC_CALLBACK_1(Scene14::back_title, this));
	btn_close->addClickEventListener(CC_CALLBACK_1(Scene14::close_menu, this));
	buttonStart->addClickEventListener(CC_CALLBACK_1(Scene14::startGame, this));
	btn_menu->addClickEventListener(CC_CALLBACK_1(Scene14::pil_menu, this));
	///////////////////////
	//gambar karakter//
	anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	this->addChild(nana_sprite);
	this->addChild(anna_sprite);
	/////////////////////////
	//background//
	if (HomeMenu::nilai_teks > 21 && HomeMenu::nilai_teks < 80)
		background->setTexture("bg/kafe_2.jpg");
	else if (HomeMenu::nilai_teks > 79)
		background->setTexture("bg/langit.jpg");
	/////////////
	hiden_character();
	return true;
}
void Scene14::hiden_character()
{
	anna_sprite->setScale(0);
	nana_sprite->setScale(0);
}
void Scene14::delay_game(float dt)
{
	detik++;

	if (detik == 4)
	{
		isi_teks();
		this->schedule(schedule_selector(Scene14::teksJalan), Option::speed_teks);
		unschedule(schedule_selector(Scene14::delay_game));
		detik = 0;
	}
	else if (detik == 3)
		buttonStart->setScale(1);
}


void Scene14::pil_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1400, 780)));
	btn_menu->setScale(0);

}

void Scene14::close_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1600, 780)));
	btn_menu->setScale(1);
}

void Scene14::back_title(Ref* sender)
{

	HomeMenu::btn_sound();
	bg_exit->setScale(1);
	kosong->setScale(1);
	btn_exit_no->setScale(1);
	btn_exit_yes->setScale(1);
	label_quit_no->setScale(1);
	label_quit_yes->setScale(1);

}

void Scene14::config(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, Option::scene(), Color3B(255, 255, 255)));
	})));

}
void Scene14::save_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, SaveGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene14::load_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, LoadGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene14::delay(float dt)
{
	if (detik == 1)
	{
		unschedule(schedule_selector(Scene14::delay));
		buttonStart->setScale(1);
		if (HomeMenu::nilai_teks == 22 || HomeMenu::nilai_teks == 80)
		{
			if (HomeMenu::nilai_teks == 2)
			{
				nana_sprite->setScale(0.6);
			}
			this->schedule(schedule_selector(Scene14::teksJalan), Option::speed_teks);
		}
		detik = 0;
	}
	detik++;
}
void Scene14::startGame(Ref* sender)
{
	unschedule(schedule_selector(Scene14::teksJalan));
	HomeMenu::btn_sound();
	HomeMenu::nilai_teks++;
	isi_teks();
	teks_1->setOpacity(0);
	i = 0;
	log("Nilai teks = %d", HomeMenu::nilai_teks);
	if (HomeMenu::nilai_teks == 22 || HomeMenu::nilai_teks == 80)
	{
		hiden_character();
		buttonStart->setScale(0);
		if (HomeMenu::nilai_teks > 21 && HomeMenu::nilai_teks < 80)
			background->setTexture("bg/kafe_2.jpg");
		else if (HomeMenu::nilai_teks > 79)
			background->setTexture("bg/langit.jpg");
		this->schedule(schedule_selector(Scene14::delay), 1.f);
	}
	else if (HomeMenu::nilai_teks == 89)
	{
		HomeMenu::nilai_teks = 1;
		this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
		{
			Director::getInstance()->replaceScene(TransitionFade::create(3, HomeMenu::scene(), Color3B(255, 255, 255)));
		})));
	}
	else
		this->schedule(schedule_selector(Scene14::teksJalan), Option::speed_teks);

}

void Scene14::isi_teks()
{
	if (HomeMenu::nilai_teks == 1)
	{
		anna();
		teks = __String::createWithFormat("\"Hei!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A7.png");
		anna_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 2)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku terbangun dari lamunanku.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A7.png");
		anna_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 3)
	{
		rei();
		teks = __String::createWithFormat("\"Hai.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 4)
	{
		anna();
		teks = __String::createWithFormat("\"Itu bukan sapaan bodoh. Ada pelanggan di sana yang memanggil kita.\nAku sedang melayani pelanggan lain jadi kamu cepat ke sana.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 5)
	{
		hiden_character();
		rei();
		teks = __String::createWithFormat("\"O-oke.\"")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 6)
	{	
		rei();
		teks = __String::createWithFormat("\"Maaf\"")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 7)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku segera bergegas menghampiri pelanggan tersebut.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 8)
	{	
		nama_kosong();
		teks = __String::createWithFormat("Hari Sabtu, satu minggu setelah terakhir kali aku bermain \nke rumah Nana.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 9)
	{	
		nama_kosong();
		teks = __String::createWithFormat("Aku masih belum bisa bersikap dengan normal meskipun \nsudah berhari-hari bermalas-malasan di kamar.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 10)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku baru menyadari kalau tindakanku itu sangat bodoh dan tidak berguna \ndi hari keenam. Meski begitu, aku sebenarnya masih ingin tetap \nmengurung diri di kamar.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 11)
	{
		nama_kosong();
		teks = __String::createWithFormat("Setelah mencatat pesanan pelanggan,\naku pergi ke dapur untuk menyerahkan catatan tersebut.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 12)
	{
		anna();
		teks = __String::createWithFormat("\"Sebenarnya kamu tidak perlu memaksakan diri untuk berangkat.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 13)
	{
		rei();
		teks = __String::createWithFormat("\"Aku sudah melewati terlalu banyak shift. Tidak apa-apa,\naku memang ingin masuk kerja hari ini.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 14)
	{
		anna();
		teks = __String::createWithFormat("\"...\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 15)
	{
		anna(); 
		teks = __String::createWithFormat("\"Baiklah kalau begitu. Bilang saja kalau kamu ingin istirahat.\nAku bisa menggantikanmu sebentar.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 16)
	{
		rei();
		teks = __String::createWithFormat("\"Seorang junior mengatakan hal seperti itu kepada senior.\nAku benar-benar menyedihkan.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 17)
	{
		anna();
		teks = __String::createWithFormat("\"Tidak, aku tidak bermaksud seperti itu. Um..\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 18)
	{
		rei();
		teks = __String::createWithFormat("\"Sudahlah, tidak apa-apa. Kamu hanya ingin membantu kan?\nMeskipun setiap minggu kamu selalu mengeluhkan shift di hari Sabtu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 19)
	{
		anna();
		teks = __String::createWithFormat("\"A-aku rasa aku sudah terbiasa.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 20)
	{
		rei();
		teks = __String::createWithFormat("\"Ahahaha, baguslah kalau begitu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 21)
	{
		rei();
		teks = __String::createWithFormat("\"Ada yang memanggil. Aku saja yang pergi.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 22)
	{
		anna();
		teks = __String::createWithFormat("\"...\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 23)
	{
		hiden_character();
		rei();
		teks = __String::createWithFormat("\"Akhirnya selesai juga. Benar-benar melelahkan.\nSepertinya tubuhku jadi kaku setelah seminggu di kamar.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 24)
	{
		anna();
		teks = __String::createWithFormat("\"Rei..\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 25)
	{
		rei();
		teks = __String::createWithFormat("\"Ya?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 26)
	{
		anna();
		teks = __String::createWithFormat("\"Aku.. aku tidak yakin kalau sebaiknya memang seperti ini.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 27)
	{
		rei();
		teks = __String::createWithFormat("\"Seperti ini?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 28)
	{
		anna();
		teks = __String::createWithFormat("\"Maksudku..\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 29)
	{
		anna();
		teks = __String::createWithFormat("\"...\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 30)
	{
		anna();
		teks = __String::createWithFormat("\"Aku tahu kalau Rei bukan orang yang suka mengatakan \nmasalahnya pada orang lain.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 31)
	{
		anna();
		teks = __String::createWithFormat("\"Tapi untuk kali ini, aku rasa.. menurutku Rei \nsebaiknya tidak memendamnya sendiri.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 32)
	{
		rei();
		teks = __String::createWithFormat("\"...\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 33)
	{
		rei();
		teks = __String::createWithFormat("\"Aku tidak suka menyebarkan aura negatifku kepada orang lain.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 34)
	{
		anna();
		teks = __String::createWithFormat("\"Aku tidak keberatan.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 35)
	{
		rei();
		teks = __String::createWithFormat("\"Aku tidak ingin membuat orang lain ikut sedih.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 36)
	{
		anna();
		teks = __String::createWithFormat("\"Kamu! Kamu pikir aku tidak sedih?!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 37)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku sedikit terkejut. Dan juga merasa lebih sadar.\nSeolah selama ini aku belum sepenuhnya terbangun.")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 38)
	{
		nama_kosong();
		teks = __String::createWithFormat("Meskipun tidak melihatnya langsung, \naku bisa merasakan semua orang di kafe ini menatap ke arah kami.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 39)
	{
		rei();
		teks = __String::createWithFormat("\"Aku tidak ingin berdebat. Apalagi saat ini.\nTapi aku sangat yakin kalau apa yang aku rasakan berbeda denganmu.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 40)
	{
		anna();
		teks = __String::createWithFormat("\"Kamu serius mengatakan itu?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 41)
	{
		nama_kosong();
		teks = __String::createWithFormat("Anna mengecilkan suaranya,\ntapi nadanya masih terdengar sangat kesal.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 42)
	{
		anna();
		teks = __String::createWithFormat("\"Nana itu, dia... salah satu sahabat terbaikku.\nMeskipun kami baru berteman beberapa minggu,\ntapi aku berani mengatakannya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 43)
	{
		rei();
		teks = __String::createWithFormat("\"Ya. Begitu juga untukku.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 44)
	{
		rei();
		teks = __String::createWithFormat("\"Tapi, terlalu banyak hal yang aku sesali.\nTerutama di hari itu, aku sangat bodoh.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 45)
	{
		rei();
		teks = __String::createWithFormat("\"Aku.. benar-benar bodoh. Aku tahu aku bodoh,\ntapi ini pertama kalinya aku menyesalinya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 46)
	{
		anna();
		teks = __String::createWithFormat("\"Kamu hanya terlalu menyalahkan dirimu sendiri.\nKamu sama sekali tidak melakukan hal bodoh.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 47)
	{
		rei();
		teks = __String::createWithFormat("\"Aku selalu terlambat menyerahkan rekamanku padanya.\nPadahal dia selalu bersemangat untuk mengeditnya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 48)
	{
		rei();
		teks = __String::createWithFormat("\"Aku juga masih merahasiakan darinya kalau aku bekerja di kafe.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 49)
	{
		anna();
		teks = __String::createWithFormat("\"...\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 50)
	{
		rei();
		teks = __String::createWithFormat("\"Aku menolak untuk bermain lebih lama dengannya hanya karena aku \nmerasa canggung untuk bertemu dengan orang tuanya.\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 51)
	{
		rei();
		teks = __String::createWithFormat("\"Dan aku.. seandainya aku memutuskan untuk pergi ke gunung,\nmeskipun itu melelahkan dan merepotkan,\nkita bertiga.. masih bisa..\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 52)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku bisa merasakan mataku sedikit berair. Aku kemudian mengalihkan \npandanganku ke dinding di samping kami.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 53)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku kemudian merasakan genggaman di tanganku.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 54)
	{
		anna();
		teks = __String::createWithFormat("\"Apapun yang kamu katakan, sebanyak apapun,\naku akan terus membantahmu dan mengatakan kalau kamu tidak salah.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 55)
	{
		rei();
		teks = __String::createWithFormat("\"Ahaha. Kamu benar-benar suka berdebat denganku ya?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 56)
	{
		nama_kosong();
		teks = __String::createWithFormat("Anna tersenyum dengan sangat ramah. Sesaat kemudian, pipiku \nterasa sedikit basah. Namun Anna masih tetap menatapku \nsambil tersenyum.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 57)
	{
		anna();
		teks = __String::createWithFormat("\"Seminggu ini, kamu benar-benar terus di kamarmu?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 58)
	{
		rei();
		teks = __String::createWithFormat("\"Belum seminggu penuh. Tapi, ya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 59)
	{
		anna();
		teks = __String::createWithFormat("\"Kalau begitu, kamu belum menemui orang tuanya Nana?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A2.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 60)
	{
		rei();
		teks = __String::createWithFormat("\"Tidak. Aku rasa.. tidak usah saja.\nLagipula mereka juga tidak mengenalku.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A2.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 61)
	{
		anna();
		teks = __String::createWithFormat("\"Bagaimana mungkin? Kamu kan salah satu teman Nana \nyang paling dekat.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 62)
	{
		rei();
		teks = __String::createWithFormat("\"Tapi, tidak berarti mereka mengenalku kan?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 63)
	{
		anna();
		teks = __String::createWithFormat("\"Tapi ketika aku menemui mereka,\nmereka menanyakanmu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 64)
	{
		nama_kosong();
		teks = __String::createWithFormat("Eh? Kenapa? Apa Nana bercerita mengenaiku pada orang tuanya?")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 65)
	{
		anna();
		teks = __String::createWithFormat("\"Ketika aku mengenalkan diriku, mereka langsung bertanya \n'Apa Rei datang bersamamu?'\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 66)
	{
		rei();
		teks = __String::createWithFormat("\"Apa yang kamu katakan?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 67)
	{
		anna();
		teks = __String::createWithFormat("\"Um, aku tidak tahu apa kamu menyukai jawabanku.\nAku bilang kalau kamu mungkin masih belum siap untuk datang.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 68)
	{
		rei();
		teks = __String::createWithFormat("\"Oh, begitu. Terimakasih.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 69)
	{
		rei();
		teks = __String::createWithFormat("\"Aku tidak berpikir kalau Nana bercerita tentangku pada orang tuanya\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 70)
	{
		anna();
		teks = __String::createWithFormat("\"Ya, aku rasa kamu tidak salah sih. Kamu pasti juga bukan tipe orang yang \nakan bercerita mengenai teman-temanmu pada orang tuamu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 71)
	{
		rei();
		teks = __String::createWithFormat("\"Apa memang sudah pada umumnya kalau mahasiswa bercerita mengenai \nteman mereka pada orang tuanya?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 72)
	{
		anna();
		teks = __String::createWithFormat("\"Hm, aku tidak yakin sih.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 73)
	{
		rei();
		teks = __String::createWithFormat("\"Kalau kamu?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 74)
	{
		anna();
		teks = __String::createWithFormat("\"Aku.. pernah beberapa kali.\nTerkadang aku bercerita tentangmu\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 75)
	{
		rei();
		teks = __String::createWithFormat("\"Eh? Kenapa memangnya?\nMenurutku tidak ada yang menarik dariku untuk diceritakan.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 76)
	{
		anna();
		teks = __String::createWithFormat("\"Ya.. begitulah. Yang penting kamu harus segera pergi \nmenemui orang tua Nana.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 77)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku tidak tahu apa yang harus aku katakan kalau bertemu dengan mereka.\nLagipula, rasa sesal ini, meskipun Nana bilang kalau aku tidak salah,\ntetap saja..")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 78)
	{
		rei();
		teks = __String::createWithFormat("\"Baiklah. Aku mungkin akan menemui mereka besok.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 79)
	{
		anna();
		teks = __String::createWithFormat("\"Aku bisa menggantikanmu untuk shift besok\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 80)
	{
		rei();
		teks = __String::createWithFormat("\"Terimakasih\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 81)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku melangkahkan kakiku menuju halte bus.\nTerkadang aku memang merasa seperti masih dalam mimpi.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 82)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dalam hanya beberapa minggu, terlalu banyak hal yang terjadi \ndalam hidupku. Nana, adalah salah satu orang yang benar-benar merubah \nkeseharianku.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 83)
	{
		nama_kosong();
		teks = __String::createWithFormat("Minggu lalu, yang bagiku terasa seperti kemarin, aku baru saja \nbermain dengannya. Dia baru saja berada di sampingku.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 84)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dadaku terasa sakit. Aku berusaha mengambil napas dalam dan menggigit \nbibirku agar tidak menjatuhkan air mata lagi.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 85)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku menatap panjang ke depan. Meskipun Nana tidak akan lagi aku temui,\naku berjanji tidak akan melupakannya.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 86)
	{
		nama_kosong();
		teks = __String::createWithFormat("Hal-hal yang dia ajarkan kepadaku, seperti memiliki mimpi, \natau sesuatu yang ingin dilakukan, mulai sekarang \naku akan memikirkannya.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 87)
	{
		nama_kosong();
		teks = __String::createWithFormat("Mulai sekarang, akan aku pastikan kalau aku sendiri yang menentukan \narus hidupku.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 88)
	{
		nama_kosong();
		teks = __String::createWithFormat("Terimakasih, Kirana Adriani.")->getCString();
		teks_1->setString(teks);
		 
	}
}


void Scene14::quit_yes(Ref* sender)
{
	HomeMenu::btn_sound();
	HomeMenu::nilai_logo = true;

	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		Director::getInstance()->replaceScene(TransitionFade::create(3, HomeMenu::scene(), Color3B(255, 255, 255)));
	})));
} //button tekan exit yes

void Scene14::quit_no(Ref* sender)
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
void Scene14::teksJalan(float dt)
{

	teks_satu();
}

void Scene14::teks_satu()
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
		unschedule(schedule_selector(Scene14::teksJalan));
	}
}

void Scene14::rei()
{
	auto teks_nama = __String::createWithFormat("Rei")->getCString();
	nama->setString(teks_nama);
}
void Scene14::anna()
{
	auto teks_nama = __String::createWithFormat("Anna")->getCString();
	nama->setString(teks_nama);
}
void Scene14::nana()
{
	auto teks_nama = __String::createWithFormat("Nana")->getCString();
	nama->setString(teks_nama);
}
void Scene14::nama_kosong()
{
	auto teks_nama = __String::createWithFormat("")->getCString();
	nama->setString(teks_nama);
}
void Scene14::nama_titik()
{
	auto teks_nama = __String::createWithFormat("......")->getCString();
	nama->setString(teks_nama);
}
void Scene14::wali()
{
	auto teks_nama = __String::createWithFormat("Wali Kelas")->getCString();
	nama->setString(teks_nama);
}


