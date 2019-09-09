#include "Scene2.h"
#include "Scene2a.h"
#include "Scene2b.h"
#include "Option.h"
#include "HomeMenu.h"
#include "SaveGame.h"
#include "LoadGame.h"

USING_NS_CC;

Scene* Scene2::scene()
{
	return Scene2::create();
}

bool Scene2::init()
{
	if (!Scene::init())
	{
		return false;
	}
	bgm->playBackgroundMusic("music/2.mp3", true);
	HomeMenu::game = 4;


	//background//
	background->setPosition(Vec2(0, 0));
	background->setAnchorPoint(Vec2(0, 0));
	this->addChild(background, 1);
	background->setScale(1);
	/////////////

	this->schedule(schedule_selector(Scene2::delay_game), 1);

	buttonStart->setPosition(Vec2(1366 / 2, 10));
	buttonStart->setScale(0);
	buttonStart->setAnchorPoint(Vec2(0.5, 0));
	this->addChild(buttonStart, 2);

	//bagian button menu//
	btn_menu->setPosition(Vec2(1313, 714));
	btn_menu->setAnchorPoint(Vec2(0.5, 0.5));
	this->addChild(btn_menu, 2);
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

	//milih jawaban//
	bg_kosong->setPosition(Vec2(0, 0));
	bg_kosong->setAnchorPoint(Vec2(0, 0));
	bg_choose->setPosition(Vec2(1366 / 2, 768 / 2));
	bg_choose->setAnchorPoint(Vec2(0.5, 0.5));
	btn_choose_left->setPosition(Vec2(bg_choose->getContentSize().width / 2 - 30, bg_choose->getContentSize().height / 2));
	btn_choose_left->setAnchorPoint(Vec2(1, 0.5));
	btn_choose_right->setPosition(Vec2(bg_choose->getContentSize().width / 2 + 30, bg_choose->getContentSize().height / 2));
	btn_choose_right->setAnchorPoint(Vec2(0, 0.5));
	this->addChild(bg_choose, 5);
	this->addChild(bg_kosong, 4);
	bg_choose->addChild(btn_choose_left);
	bg_choose->addChild(btn_choose_right);
	label_choose_left->setPosition(Vec2(btn_choose_left->getContentSize().width / 2, btn_choose_left->getContentSize().height / 2));
	label_choose_right->setPosition(Vec2(btn_choose_right->getContentSize().width / 2, btn_choose_right->getContentSize().height / 2));
	label_choose_left->setAnchorPoint(Vec2(0.5, 0.5));
	label_choose_right->setAnchorPoint(Vec2(0.5, 0.5));
	btn_choose_left->addChild(label_choose_left);
	btn_choose_right->addChild(label_choose_right);
	bg_choose->setScale(0);
	bg_kosong->setScale(0);
	////////////////

	/////////////////////////
	btn_load->addClickEventListener(CC_CALLBACK_1(Scene2::load_game, this));
	btn_save->addClickEventListener(CC_CALLBACK_1(Scene2::save_game, this));
	btn_config->addClickEventListener(CC_CALLBACK_1(Scene2::config, this));
	btn_exit_no->addClickEventListener(CC_CALLBACK_1(Scene2::quit_no, this));
	btn_exit_yes->addClickEventListener(CC_CALLBACK_1(Scene2::quit_yes, this));
	btn_tittle->addClickEventListener(CC_CALLBACK_1(Scene2::back_title, this));
	btn_close->addClickEventListener(CC_CALLBACK_1(Scene2::close_menu, this));
	buttonStart->addClickEventListener(CC_CALLBACK_1(Scene2::startGame, this));
	btn_menu->addClickEventListener(CC_CALLBACK_1(Scene2::pil_menu, this));
	btn_choose_left->addClickEventListener(CC_CALLBACK_1(Scene2::choose_left, this));
	btn_choose_right->addClickEventListener(CC_CALLBACK_1(Scene2::choose_right, this));
	/////////////////////////////////////////

	//gambar karakter//
	anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	hiden_character();
	this->addChild(nana_sprite,1);
	this->addChild(anna_sprite,1);
	//////////////////
	 if (HomeMenu::nilai_teks == 33)
		background->setTexture("bg/taman.jpg");
	else if (HomeMenu::nilai_teks >= 34)
		background->setTexture("bg/kantin.jpg");
	return true;
}
void Scene2::hiden_character()
{
	anna_sprite->setScale(0);
	nana_sprite->setScale(0);
}
void Scene2::delay_game(float dt)
{
	detik++;

	if (detik == 4)
	{
		isi_teks();
		this->schedule(schedule_selector(Scene2::teksJalan), Option::speed_teks);
		unschedule(schedule_selector(Scene2::delay_game));
		detik = 0;
	}
	else if (detik == 3)
		buttonStart->setScale(1);
}


void Scene2::pil_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1400, 780)));
	btn_menu->setScale(0);

}

void Scene2::close_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1600, 780)));
	btn_menu->setScale(1);
}

void Scene2::back_title(Ref* sender)
{

	HomeMenu::btn_sound();
	bg_exit->setScale(1);
	kosong->setScale(1);
	btn_exit_no->setScale(1);
	btn_exit_yes->setScale(1);
	label_quit_no->setScale(1);
	label_quit_yes->setScale(1);

}

void Scene2::config(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, Option::scene(), Color3B(255, 255, 255)));
	})));

}
void Scene2::save_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, SaveGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene2::load_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, LoadGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene2::delay(float dt)
{
	if (detik == 1)
	{
		unschedule(schedule_selector(Scene2::delay));
		buttonStart->setScale(1);
		if (HomeMenu::nilai_teks == 33 || HomeMenu::nilai_teks == 34)
		{
			
			this->schedule(schedule_selector(Scene2::teksJalan), Option::speed_teks);
		}
		detik = 0;
	}
	detik++;
}
void Scene2::startGame(Ref* sender)
{
	unschedule(schedule_selector(Scene2::teksJalan));
	
	HomeMenu::nilai_teks++;
	isi_teks();
	teks_1->setOpacity(0);
	i = 0;
	log("Nilai teks = %d", HomeMenu::nilai_teks);
	if (HomeMenu::nilai_teks == 33 || HomeMenu::nilai_teks == 34)
	{
		buttonStart->setScale(0);
		 if (HomeMenu::nilai_teks == 33)
			background->setTexture("bg/taman.jpg");
		else if (HomeMenu::nilai_teks >= 34)
			background->setTexture("bg/kantin.jpg");
		this->schedule(schedule_selector(Scene2::delay), 1.f);
		
	}
	else if (HomeMenu::nilai_teks == 129)
	{
		bg_kosong->setScale(1);
		bg_choose->setScale(1);
	}
	else
		this->schedule(schedule_selector(Scene2::teksJalan), Option::speed_teks);
	HomeMenu::btn_sound();
}

void Scene2::choose_left(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		Director::getInstance()->replaceScene(TransitionFade::create(3, Scene2a::scene(), Color3B(255, 255, 255)));
	})));
	HomeMenu::nilai_teks = 1;
}
void Scene2::choose_right(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		Director::getInstance()->replaceScene(TransitionFade::create(3, Scene2b::scene(), Color3B(255, 255, 255)));
	})));
	HomeMenu::nilai_teks = 1;
}

void Scene2::isi_teks()
{
	if (HomeMenu::nilai_teks == 1)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku mengajaknya ke bagian 'terdepan' kampus")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 2)
	{
		nama_kosong();
		teks = __String::createWithFormat("Selama melangkah ke sini, aku menyadari kalau kita \ntidak akan sempat berkeliling ke seluruh kampus dalam satu waktu.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 3)
	{
		nama_kosong();
		teks = __String::createWithFormat("Mungkin bisa, tapi akan sangat melelahkan.\nDan jelas bukan suatu hal yang akan aku coba lakukan.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 4)
	{
		rei();
		teks = __String::createWithFormat("\"Um.. Yah.. Jadi sekarang kita ada di bagian paling belakang kampus.\"\naku mencoba mulai memberikan penjelasan.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 5)
	{
		nama_kosong();
		teks = __String::createWithFormat("Nana hanya menatapku dengan bingung.\nIa terus menatapku cukup lama.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
	}
	else if (HomeMenu::nilai_teks == 6)
	{
		voice->getInstance()->playEffect("voice/passage2/6.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Bercanda?\"Ia bertanya dengan sedikit ragu-ragu.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
	}
	else if (HomeMenu::nilai_teks == 7)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Tidak, tidak.. Aku tidak sedang bercanda. \nKampus ini memang cukup unik.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
	}
	else if (HomeMenu::nilai_teks == 8)
	{
		nama_kosong();
		teks = __String::createWithFormat("Untuk kita mahasiswa elektro,\narea ini memang tampak seperti bagian depan kampus,\nnamun faktanya ini bagian belakang kampus.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 9)
	{
		rei();
		teks = __String::createWithFormat("\"Lagipula..\" \nlagipula aku sangat tidak yakin dengan kemampuanku membuat lelucon.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 10)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku tidak mungkin mencoba bercanda dengan orang yang baru aku kenal.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 11)
	{
		voice->getInstance()->playEffect("voice/passage2/11.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Lagipula?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
	}
	else if (HomeMenu::nilai_teks == 12)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Ah.. tidak, bukan apa-apa\" aku memutuskan untuk tidak mengatakannya.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		 
	}
	else if (HomeMenu::nilai_teks == 13)
	{
		nama_kosong();
		teks = __String::createWithFormat("Bisa jadi tanpa sengaja aku membuat lelucon.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 14)
	{
		rei();
		teks = __String::createWithFormat("\"Seperti yang kamu lihat, disini ada area parkir motor yang luas.\"\naku melanjutkan penjelasanku.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 15)
	{
		rei();
		teks = __String::createWithFormat("\"Buka dari sangat pagi, hingga jam 9.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}

	else if (HomeMenu::nilai_teks == 16)
	{
		rei();
		teks = __String::createWithFormat("\"Hal itu sesuai dengan waktu belajar kami di kampus \nyang dibagi menjadi jam pagi dan malam.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 17)
	{
		rei();
		teks = __String::createWithFormat("\"Jam pagi dari jam 7 sampai 2 siang,\nJam malam dari jam 2 sampai 9 malam.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 18)
	{
		rei();
		teks = __String::createWithFormat("\"Tapi tidak selalu demikian, tergantung pada \njadwal setiap program studi dan dosen nantinya.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 19)
	{
		rei();
		teks = __String::createWithFormat("\"Di parkiran ini ada CCTV dan satpam, \njadi kendaraanmu pasti aman selama kamu parkir di jam belajar kampus.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 20)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku menoleh ke arahnya. Ia terlihat tidak tertarik.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 21)
	{
		nama_kosong();
		teks = __String::createWithFormat("Maafkan aku kalau aku sangat membosankan Nana.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 22)
	{
		rei();
		teks = __String::createWithFormat("\"Emm.. Ada yang ingin kamu tanyakan?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
	}
	else if (HomeMenu::nilai_teks == 23)
	{
		nana();
		teks = __String::createWithFormat("\"Eh? Ah.. tidak. Maaf.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
		 
	}
	else if (HomeMenu::nilai_teks == 24)
	{
		nama_kosong();
		teks = __String::createWithFormat("Kenapa dia meminta maaf?\nApa dia menyadari kalau dia tidak memperhatikan ?")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 25)
	{
		voice->getInstance()->playEffect("voice/passage2/25.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Um.. maaf karena tidak memberitahumu sebelumnya, tapi..\nsepertinya aku akan diantar ke kampus setiap harinya.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 26)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Aku merasa bodoh. Jadi intinya aku tidak perlu menjelaskan \npanjang lebar mengenai parkiran ya?")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 27)
	{
		rei();
		teks = __String::createWithFormat("\"Oh, begitu.., Ahaha.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 28)
	{
		nama_kosong();
		teks = __String::createWithFormat("Diantar ya?Aku berkesimpulan kalau dia orang kaya.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 29)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku jadi teringat kalau alasan dia pindah adalah karena pekerjaan \norang tuanya.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 30)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sepertinya aku harus lebih berhati-hati dengan ucapanku.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 31)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku harap perbedaan derajat kekayaan diantara kami tidak membuatku \nterlihat bodoh lagi.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 32)
	{
		nama_kosong();
		teks = __String::createWithFormat("Kami kemudian berkeliling ke area 'depan' kampus.\nAku memperlihatkannya berbagai tempat yang cukup umum seperti \npos satpam,")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 33)
	{
		nama_kosong();
		teks = __String::createWithFormat("Taman,")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 34)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dan Kantin")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 35)
	{
		rei();
		teks = __String::createWithFormat("\"Aku rasa sebaiknya kita masuk ke dalam gedung sekolah saja.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 36)
	{
		rei();
		teks = __String::createWithFormat("\"Aku malah belum memperlihatkanmu berbagai ruangan yang \ndigunakan oleh program studi informatika\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 37)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku melangkah menuju gedung sekolah,\nnamun Nana hanya diam saja.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 38)
	{
		rei();
		teks = __String::createWithFormat("\"Ada apa?Uh..\nkalau mau tanya, tanya saja.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 39)
	{
		voice->getInstance()->playEffect("voice/passage2/39.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Ah.. tidak.., anu.. aku..\naku agak sedikit haus.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 40)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Kita memang sedang berada di kantin,\njadi aku tidak bisa menolaknya,\nmeskipun ingin segera pulang.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 41)
	{
		rei();
		teks = __String::createWithFormat("\"Baiklah, mari kita istirahat di sini sebentar\" \nkataku sambil mencari meja yang masih kosong.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
	}
	else if (HomeMenu::nilai_teks == 42)
	{
		rei();
		teks = __String::createWithFormat("\"Pesan minuman pada Ibu yang di meja itu, aku akan menunggu \ndi meja situ.\" tunjukku pada salah satu meja.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
	}
	else if (HomeMenu::nilai_teks == 43)
	{
		rei();
		teks = __String::createWithFormat("\"Kantin memang cukup ramai sepulang sekolah,\nnamun tidak seramai jam istirahat siang.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
	}
	else if (HomeMenu::nilai_teks == 44)
	{
		voice->getInstance()->playEffect("voice/passage2/44.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Eh? Kamu tidak pesan apapun?\"\nIa terlihat sungkan.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
	}
	else if (HomeMenu::nilai_teks == 45)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Tidak, jangan khawatirkan aku, aku baik-baik saja.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
	}
	else if (HomeMenu::nilai_teks == 46)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku memang tidak sedang haus, jadi aku rasa aku tidak perlu \nmembeli minuman untuk menghemat uangku.")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 47)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku tidak mengira akan menemani seorang mahasiswi \npindahan jalan-jalan hari ini.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 48)
	{
		nama_kosong();
		teks = __String::createWithFormat("Karena itu aku tidak membawa botol minum seperti biasanya.\nTadinya berencana untuk langsung pulang.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 49)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tak lama kemudian, sebelum mataku terpejam karena desiran angin sore,\nNana menuju ke tempat aku duduk dengan membawa dua gelas jus.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 50)
	{
		nama_kosong();
		teks = __String::createWithFormat("Eh?! Aku segera membuka mataku lebar.\nApakah dia beli untukku juga?")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
	}
	else if (HomeMenu::nilai_teks == 51)
	{
		rei();
		teks = __String::createWithFormat("\"Terimakasih sekali. Meskipun kamu sebenarnya tidak perlu repot-repot.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
	}
	else if (HomeMenu::nilai_teks == 52)
	{
		nama_kosong();
		teks = __String::createWithFormat("Jus ini.. seharga 6 kali perjalananku menuju kampus-rumah.\nAku benar-benar akan menikmatinya.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
	}
	else if (HomeMenu::nilai_teks == 53)
	{
		voice->getInstance()->playEffect("voice/passage2/53.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Tapi.. maaf karena tidak bertanya padamu dulu.\nAku asal memilih buah yang sama dengan yang aku ingin minum.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/3.png");
	}
	else if (HomeMenu::nilai_teks == 54)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Tidak apa-apa, aku tidak alergi ataupun benci pada apapun.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/3.png");
	}
	else if (HomeMenu::nilai_teks == 55)
	{
		nama_kosong();
		teks = __String::createWithFormat("Untuk beberapa menit, dilewati angin yang terus membelai,\nkami menikmati jus pilihannya -strawberry.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 56)
	{
		rei();
		teks = __String::createWithFormat("\"Aku pikir kamu tipe orang yang lebih asyik.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 57)
	{
		nama_kosong();
		teks = __String::createWithFormat("Setelah terlalu lama diam,\naku akhirnya mencoba membuka pembicaraan.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
	}
	else if (HomeMenu::nilai_teks == 58)
	{
		nama_kosong();
		teks = __String::createWithFormat("Entah karena jus pemberiannya atau bagaimana,\naku melakukan hal ini. Biasanya aku akan tetap diam..")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
	}
	else if (HomeMenu::nilai_teks == 59)
	{
		nama_kosong();
		teks = __String::createWithFormat("Nana menatapku dengan sedikit terkejut.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
	}
	else if (HomeMenu::nilai_teks == 60)
	{
		nama_kosong();
		teks = __String::createWithFormat("Eh?\nAku mencoba mengulang kalimatku tadi dalam benakku.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
	}
	else if (HomeMenu::nilai_teks == 61)
	{
		nama_kosong();
		teks = __String::createWithFormat("Gawat. Apakah aku malah menyinggungnya?")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
	}
	else if (HomeMenu::nilai_teks == 62)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku mencoba melihat ekspresinya lagi.\nNamun ia masih menatapku.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 63)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dan untuk beberapa saat, kami saling menatap.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 64)
	{
		nama_kosong();
		teks = __String::createWithFormat("Nana tiba-tiba tersentak dan segera mengalihkan pandangannya.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/5.png");
	}
	else if (HomeMenu::nilai_teks == 65)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku pun juga terkejut dan ikut mengalihkan pandanganku.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/5.png");
	}
	else if (HomeMenu::nilai_teks == 66)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sial. Mungkin aku seharusnya tetap diam saja.\nSuasana canggung seperti ini benar-benar \ntidak aku sukai.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/5.png");
	}
	else if (HomeMenu::nilai_teks == 67)
	{
		rei();
		teks = __String::createWithFormat("\"Maksudku.., ketika perkenalan tadi pagi di kelas.\nKamu terkesan seperti orang yang suka bergaul.\nMaaf, aku hanya..\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/5.png");
	}
	else if (HomeMenu::nilai_teks == 68)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku mencoba meluruskan maksudku sambil berusaha keluar dari suasana \ncanggung ini.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
	}
	else if (HomeMenu::nilai_teks == 69)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku menatap Nana lagi.\nSekarang entah kenapa ia tersenyum lebar.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
	}
	else if (HomeMenu::nilai_teks == 70)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ayolah mahasiswi pindahan,\nkamu benar-benar tidak membantuku kalau tidak mengatakan apa-apa.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
	}
	else if (HomeMenu::nilai_teks == 71)
	{
		voice->getInstance()->playEffect("voice/passage2/71.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Perkenalan pagi tadi itu.. Aku telah berlatih berkali-kali agar bagus.\" \nsuaranya lebih keras dari biasanya, dan ia masih tersenyum lebar.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
	}
	else if (HomeMenu::nilai_teks == 72)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Berlatih.. untuk perkenalan? Untuk apa?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
	}
	else if (HomeMenu::nilai_teks == 73)
	{
		voice->getInstance()->playEffect("voice/passage2/73.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Aku ingin memberikan kesan pertama yang bagus pada kelas.\nKarena itu aku perlu berlatih.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
	}
	else if (HomeMenu::nilai_teks == 74)
	{
		voice->getInstance()->pauseAllEffects();
		voice->getInstance()->playEffect("voice/passage2/74.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Rasanya senang mengetahui kalau hasilnya bagus.\nTerimakasih.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
	}
	else if (HomeMenu::nilai_teks == 75)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Sekarang semuanya masuk akal.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
	}
	else if (HomeMenu::nilai_teks == 76)
	{
		rei();
		teks = __String::createWithFormat("\"Tapi, apa kamu yakin kalau hal seperti itu perlu dilakukan?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 77)
	{
		nama_kosong();
		teks = __String::createWithFormat("Nana menarik kembali senyumannya, dan diam.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 78)
	{
		rei();
		teks = __String::createWithFormat("Sekarang kalau semua orang mengira kamu orangnya asyik,\nbukannya mereka malah akan kaget kalau tahu kamu \nsebenarnya bagaimana?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 79)
	{
		voice->getInstance()->playEffect("voice/passage2/79.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Tapi.. tapi aku akan berusaha agar bisa banyak bicara dengan \nteman-teman.\" suaranya terdengar keras lagi.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 80)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Kalau begitu kamu perlu lebih banyak berusaha mahasiswi pindahan...")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 81)
	{
		nama_kosong();
		teks = __String::createWithFormat("10 menit yang telah kuhabiskan denganmu sejauh ini sudah cukup \nmembuatku tahu kalau kamu mirip denganku.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 82)
	{
		nama_kosong();
		teks = __String::createWithFormat("Atau bahkan lebih parah.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 83)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tentunya aku tidak akan mengatakan itu. Lagipula sepertinya aku \ntelah mengatakan banyak hal yang tidak perlu.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 84)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku menyedot jusku.\nNana melakukan hal yang sama.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 85)
	{
		rei();
		teks = __String::createWithFormat("\"Kita telah menghabiskan terlalu banyak waktu di sini.\nAyo kita pergi ke dalam gedung sekolah.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 86)
	{
		voice->getInstance()->playEffect("voice/passage2/86.mp3", false, 1.0f, 1.0f, 1.0f);
		nama_titik();
		teks = __String::createWithFormat("\"Eeehh?? Tapi minumannya Nana masih baru terminum setengah..!\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
	}
	else if (HomeMenu::nilai_teks == 87)
	{
		voice->getInstance()->pauseAllEffects();
		voice->getInstance()->playEffect("voice/passage2/87.mp3", false, 1.0f, 1.0f, 1.0f);
		nama_titik();
		teks = __String::createWithFormat("\"Betapa jahat cowok ini.. Kalau aku sih,\nlangsung aku putusin!\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
	}
	else if (HomeMenu::nilai_teks == 88)
	{
		nama_kosong();
		teks = __String::createWithFormat("Lagi-lagi suara ini.\nSuara manusia yang paling akrab di telingaku.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		 
	}
	else if (HomeMenu::nilai_teks == 89)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku cukup yakin meskipun ia dan seratus orang berbicara bersamaan,\naku dapat mengetahui yang mana suaranya.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 90)
	{
		rei();
		teks = __String::createWithFormat("\"Kalau begitu, putuskan saja hubunganku dengannya sekarang.\nAku ingin segera pulang.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 91)
	{
		hiden_character();
		voice->getInstance()->playEffect("voice/passage2/91.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
			teks = __String::createWithFormat("\"Jadi? Bagaimana jalan-jalannya dengan Rei? \nApakah dia layak?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 92)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Aku pulang sekarang.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K1.png");
		nana_sprite->setScale(0.6);
		anna_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 93)
	{
		voice->getInstance()->playEffect("voice/passage2/93.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Eeehh??\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 94)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Apanya yang 'eh?' Sekarang kamu bisa mengantarnya \njalan-jalan sendiri kan?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K5.png");
		nana_sprite->setScale(0.6);
		anna_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 95)
	{
		rei();
		teks = __String::createWithFormat("\"Jangan lupa juga kalau aku tidak pernah setuju untuk \nmelakukan hal ini.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K5.png");
		nana_sprite->setScale(0.6);
		anna_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 96)
	{
		voice->getInstance()->playEffect("voice/passage2/96.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Tapi kamu kan tidak ada kerjaan.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K4.png");
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 97)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Ada hal yang ingin aku lakukan,\naku cukup sibuk.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K4.png");
		nana_sprite->setScale(0.6);
		anna_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 98)
	{
		voice->getInstance()->playEffect("voice/passage2/98.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Eh?! Maaf sekali mengganggumu, aku tidak bermaksud-\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K4.png");
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 99)
	{
		voice->getInstance()->pauseAllEffects();
		voice->getInstance()->playEffect("voice/passage2/99.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Tidak-tidak. Jangan meminta maaf. Malahan, jangan pernah meminta \nmaaf pada orang ini. Palingan dia hanya mau main game.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K4.png");
		nana_sprite->setScale(0.6);
		anna_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 100)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Ha?! Mana kamu tahu!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K4.png");
		nana_sprite->setScale(0.6);
		anna_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 101)
	{
		voice->getInstance()->playEffect("voice/passage2/101.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Apa aku salah?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K4.png");
		nana_sprite->setScale(0.6);
		anna_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 102)
	{
		voice->getInstance()->pauseAllEffects();
		voice->getInstance()->playEffect("voice/passage2/102.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Ah!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K4.png");
		nana_sprite->setScale(0.6);
		anna_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 103)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Aku dan Anna menoleh ke arah Nana \nyang tiba-tiba terkejut karena suatu hal.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K1.png");
		nana_sprite->setScale(0.6);
		anna_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 104)
	{
		voice->getInstance()->playEffect("voice/passage2/104.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Apa Rei dan Anna pacaran?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K1.png");
		nana_sprite->setScale(0.6);
		anna_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 105)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("HA?!Bagaimana dia bisa sampai pada kesimpulan \nyang bodoh seperti itu?!")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K6.png");
		nana_sprite->setScale(0.6);
		anna_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 106)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku sangat terkejut pada pertanyaan Nana sampai tidak bisa \nmengatakan apapun.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K6.png");
		nana_sprite->setScale(0.6);
		anna_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 107)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku memutuskan untuk tetap diam. \nAku rasa apapun yang keluar dari mulutku sekarang \nakan terdengar lebih konyol.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K6.png");
		nana_sprite->setScale(0.6);
		anna_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 108)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku kemudian menoleh kepada Anna dan melihatnya terdiam saja \nsepertiku.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K6.png");
		nana_sprite->setScale(0.6);
		anna_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 109)
	{
		rei();
		teks = __String::createWithFormat("\"Hei! Kenapa kamu malah ikut diam saja! Katakan sesuatu kek! \nKenapa di saat yang penting kamu malah diaam!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K6.png");
		nana_sprite->setScale(0.6);
		anna_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 110)
	{
		nama_kosong();
		teks = __String::createWithFormat("Anna sedikit tersentak. Sepertinya ia melamun dari tadi.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K7.png");
		nana_sprite->setScale(0.6);
		anna_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 111)
	{
		voice->getInstance()->playEffect("voice/passage2/111.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Memangnya kenapa Nana? Apa kami terlihat seperti \nsepasang kekasih? Apa kami tampak serasi?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K1.png");
		nana_sprite->setScale(0.6);
		anna_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 112)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Nana mengangguk kecil.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K1.png");
		nana_sprite->setScale(0.6);
		anna_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 113)
	{
		rei();
		teks = __String::createWithFormat("\"Apa yang malah kamu katakan!? \nJangan membuatnya tambah salah paham!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K1.png");
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 114)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sudahlah. Aku cukup dengan ini.\nSeseorang tolong hentikan.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K1.png");
		nana_sprite->setScale(0.6);anna_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 115)
	{
		voice->getInstance()->playEffect("voice/passage2/115.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Sayang sekali Nana.. hal itu tidaklah mungkin.\nKalau saja dia tidak sebodoh ini.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		nana_sprite->setScale(0.6);anna_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 116)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Entah apakah Anna benar-benar perlu menjelaskan bahwa aku bodoh atau \ntidak, tapi aku cukup lega ia telah meluruskan pemikiran Nana \nyang cukup bengkok.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		nana_sprite->setScale(0.6);anna_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 117)
	{
		rei();
		teks = __String::createWithFormat("\"Aku tidak bodoh, banyaknya orang-orang sepertimu saja \nyang membuatku jadi tergolong bodoh.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		nana_sprite->setScale(0.6);anna_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 118)
	{
		voice->getInstance()->playEffect("voice/passage2/118.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"'orang-orang sepertimu?'\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K1.png");
		nana_sprite->setScale(0.6);anna_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 119)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Oh, kamu belum tahu ya..Makhluk ini, \nmendapat IP 4 di setiap semesternya\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K1.png");
		nana_sprite->setScale(0.6);anna_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 120)
	{
		voice->getInstance()->playEffect("voice/passage2/120.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Wah! Benarkah!? Luar Biasa!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K1.png");
		nana_sprite->setScale(0.6);anna_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 121)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Nana menatap Anna dengan ekspresi kagum,\ndan Anna tersenyum dengan sangat bangga.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K1.png");
		nana_sprite->setScale(0.6);anna_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 122)
	{
		rei();
		teks = __String::createWithFormat("\"Sudah ya, aku mau pulang sekarang.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K1.png");
		nana_sprite->setScale(0.6);anna_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	 if (HomeMenu::nilai_teks == 123)
	{
		voice->getInstance()->playEffect("voice/passage2/123.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Serius mau pulang? Ayolah Rei, \njangan lari dari tanggung jawabmu\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K1.png");
		nana_sprite->setScale(0.6);anna_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	 if (HomeMenu::nilai_teks == 124)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Aku tidak memiliki tanggung jawab pada apapun\" \naku mulai sedikit ngotot.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K1.png");
		nana_sprite->setScale(0.6);anna_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	 if (HomeMenu::nilai_teks == 125)
	{
		voice->getInstance()->playEffect("voice/passage2/125.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Apakah tadi jusnya enak?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScaleX(-0.6);anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	 if (HomeMenu::nilai_teks == 126)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Dengan licik, Anna mengeluarkan teknik psikologi yang entah dari mana ia \npelajari.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScaleX(-0.6);anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	 if (HomeMenu::nilai_teks == 127)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ia berhasil membuatku merasa sungkan untuk pulang.\nKeinginanku untuk segera pulang menjadi goyah.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScaleX(-0.6);anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	 if (HomeMenu::nilai_teks == 128)
	{
		voice->getInstance()->playEffect("voice/passage2/128.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Ah, tidak, kalau Rei mau pulang, tidak apa-apa.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		nana_sprite->setScale(0.6);anna_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}

}


void Scene2::quit_yes(Ref* sender)
{
	HomeMenu::btn_sound();
	HomeMenu::nilai_logo = true;

	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		Director::getInstance()->replaceScene(TransitionFade::create(3, HomeMenu::scene(), Color3B(255, 255, 255)));
	})));
} //button tekan exit yes

void Scene2::quit_no(Ref* sender)
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
void Scene2::teksJalan(float dt)
{

	teks_satu();
}

void Scene2::teks_satu()
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
		unschedule(schedule_selector(Scene2::teksJalan));
	}
}

void Scene2::rei()
{
	auto teks_nama = __String::createWithFormat("Rei")->getCString();
	nama->setString(teks_nama);
}
void Scene2::anna()
{
	auto teks_nama = __String::createWithFormat("Anna")->getCString();
	nama->setString(teks_nama);
}
void Scene2::nana()
{
	auto teks_nama = __String::createWithFormat("Nana")->getCString();
	nama->setString(teks_nama);
}
void Scene2::nama_kosong()
{
	auto teks_nama = __String::createWithFormat("")->getCString();
	nama->setString(teks_nama);
}
void Scene2::nama_titik()
{
	auto teks_nama = __String::createWithFormat("......")->getCString();
	nama->setString(teks_nama);
}
void Scene2::wali()
{
	auto teks_nama = __String::createWithFormat("Wali Kelas")->getCString();
	nama->setString(teks_nama);
}


