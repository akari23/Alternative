#include "Scene1a.h"
#include "Scene2.h"
#include "Option.h"
#include "HomeMenu.h"
#include "SaveGame.h"
#include "LoadGame.h"

USING_NS_CC;



Scene* Scene1a::scene()
{
	return Scene1a::create();
}

bool Scene1a::init()
{
	if (!Scene::init())
	{
		return false;
	}
	bgm->playBackgroundMusic("music/1a.mp3", true);
	HomeMenu::game = 2;
	

	//background//
	background->setPosition(Vec2(0, 0));
	background->setAnchorPoint(Vec2(0, 0));
	this->addChild(background);
	background->setScale(1);
	/////////////

	this->schedule(schedule_selector(Scene1a::delay_game), 1);

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
	btn_load->addClickEventListener(CC_CALLBACK_1(Scene1a::load_game, this));
	btn_save->addClickEventListener(CC_CALLBACK_1(Scene1a::save_game, this));
	btn_config->addClickEventListener(CC_CALLBACK_1(Scene1a::config, this));
	btn_exit_no->addClickEventListener(CC_CALLBACK_1(Scene1a::quit_no, this));
	btn_exit_yes->addClickEventListener(CC_CALLBACK_1(Scene1a::quit_yes, this));
	btn_tittle->addClickEventListener(CC_CALLBACK_1(Scene1a::back_title, this));
	btn_close->addClickEventListener(CC_CALLBACK_1(Scene1a::close_menu, this));
	buttonStart->addClickEventListener(CC_CALLBACK_1(Scene1a::startGame, this));
	btn_menu->addClickEventListener(CC_CALLBACK_1(Scene1a::pil_menu, this));
	///////////////////////////

	//gambar karakter//
	anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2+50));
	nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2+50));
	hiden_character();
	this->addChild(nana_sprite);
	this->addChild(anna_sprite);
	//////////////////

	return true;
}
void Scene1a::hiden_character()
{
	anna_sprite->setScale(0);
	nana_sprite->setScale(0);
}
void Scene1a::delay_game(float dt)
{
	detik++;

	if (detik == 4)
	{
		isi_teks();
		this->schedule(schedule_selector(Scene1a::teksJalan), Option::speed_teks);
		unschedule(schedule_selector(Scene1a::delay_game));
		detik = 0;
	}
	else if (detik == 3)
		buttonStart->setScale(1);
}


void Scene1a::pil_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1400, 780)));
	btn_menu->setScale(0);

}

void Scene1a::close_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1600, 780)));
	btn_menu->setScale(1);
}

void Scene1a::back_title(Ref* sender)
{

	HomeMenu::btn_sound();
	bg_exit->setScale(1);
	kosong->setScale(1);
	btn_exit_no->setScale(1);
	btn_exit_yes->setScale(1);
	label_quit_no->setScale(1);
	label_quit_yes->setScale(1);

}

void Scene1a::config(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, Option::scene(), Color3B(255, 255, 255)));
	})));

}
void Scene1a::save_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, SaveGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene1a::load_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, LoadGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene1a::delay(float dt)
{
	if (detik == 1)
	{
		unschedule(schedule_selector(Scene1a::delay));
		buttonStart->setScale(1);
		if (HomeMenu::nilai_teks == 15 || HomeMenu::nilai_teks == 6 || HomeMenu::nilai_teks == 10 || HomeMenu::nilai_teks == 57)
		{
			this->schedule(schedule_selector(Scene1a::teksJalan), Option::speed_teks);
		}
		detik = 0;
	}
	detik++;
}
void Scene1a::startGame(Ref* sender)
{
	unschedule(schedule_selector(Scene1a::teksJalan));
	if (!textSelesai)
	{
		textSelesai = true;
		this->schedule(schedule_selector(Scene1a::teksJalan), 0);
	}
	else
	{
		textSelesai = false;
		HomeMenu::nilai_teks++;
		isi_teks();
		teks_1->setOpacity(0);
		i = 0;
		log("Nilai teks = %d", HomeMenu::nilai_teks);
		if (HomeMenu::nilai_teks == 19)
		{
			HomeMenu::nilai_teks = 1;
			this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
			{
				Director::getInstance()->replaceScene(TransitionFade::create(3, Scene2::scene(), Color3B(255, 255, 255)));
			})));
		}
		else
			this->schedule(schedule_selector(Scene1a::teksJalan), Option::speed_teks);
	}
	
	HomeMenu::btn_sound();
}

void Scene1a::isi_teks()
{
	if (HomeMenu::nilai_teks == 1)
	{
		voice->getInstance()->playEffect("voice/passage1a/1.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Hai..\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 2)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Tiba-tiba Nana berada di sampingku. \nAku benar-benar gugup.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 3)
	{
		nama_kosong();
		teks = __String::createWithFormat("Meskipun sedang kesal, aku memasang wajah ramah. \nAku tidak boleh memberi kenangan buruk di hari pertamanya.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 4)
	{
		rei();
		teks = __String::createWithFormat("\"Hai, uh.. namaku Rei\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 5)
	{
		voice->getInstance()->pauseAllEffects();
		voice->getInstance()->playEffect("voice/passage1a/5.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Iya, tadi Anna sudah memberitahuku.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
	}
	else if (HomeMenu::nilai_teks == 6)
	{
		voice->getInstance()->pauseAllEffects();
		voice->getInstance()->playEffect("voice/passage1a/6.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Uh.. Maaf merepotkanmu Rei, sepertinya Anna sedang ada urusan, \nsehingga tidak bisa menemaniku berkeliling.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
	}
	else if (HomeMenu::nilai_teks == 7)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Ah.. tidak.. tidak apa-apa\" \naku berusaha tersenyum.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite-> setScaleX((-0.6));
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 8)
	{	
		nama_kosong();
		teks = __String::createWithFormat("Kalaupun seseorang harus meminta maaf, orang itu bukanlah Nana.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX((-0.6));
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 9)
	{	
		nama_kosong();
		teks = __String::createWithFormat("Ketika Nana berbicara, aku menyadari sesuatu. \nIa terdengar sedikit gelisah, mungkin gugup.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX((-0.6));
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 10)
	{
		nama_kosong();
		teks = __String::createWithFormat("Hei, hei.. bukankah ini suatu hal yang buruk? \nApa jadinya kalau kamu juga gugup?")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		 
	}
	else if (HomeMenu::nilai_teks == 11)
	{
		nama_kosong();
		teks = __String::createWithFormat("Kita tidak akan bisa melakukan percakapan kalau kita berdua gugup!")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 12)
	{
		rei();
		teks = __String::createWithFormat("\"Aku tidak tahu apakah aku orang yang tepat untuk menemanimu \nberkeliling, tapi.. aku harap kamu tidak keberatan\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 13)
	{
		nama_kosong();
		teks = __String::createWithFormat("Nana tersenyum kecil.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
	}
	else if (HomeMenu::nilai_teks == 14)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku berusaha mengatakan sesuatu, dan\nkurasa yang tadi itu cukup keren.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
	}
	else if (HomeMenu::nilai_teks == 15)
	{
		nama_kosong();
		 
		teks = __String::createWithFormat("Meskipun aku tahu dengan baik kalau aku sama sekali\nbukan orang yang tepat untuk menemaninya.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 16)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku tidak biasa berkomunikasi. Dan sekarang aku diharuskan berbicara \ndengan orang yang baru saja aku kenal.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		 
	}
	else if (HomeMenu::nilai_teks == 17)
	{
		nama_kosong();
		teks = __String::createWithFormat("Entah apa yang Anna pikirkan. Aku jadi berpikiran kalau \nsepertinya tadi aku harusnya pulang saja.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		 
	}
	else if (HomeMenu::nilai_teks == 18)
	{
		nama_kosong();
		teks = __String::createWithFormat("Namun di titik ini, sepertinya hal itu sudah tidak memungkinkan.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		 
	}
}


void Scene1a::quit_yes(Ref* sender)
{
	HomeMenu::btn_sound();
	HomeMenu::nilai_logo = true;

	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		Director::getInstance()->replaceScene(TransitionFade::create(3, HomeMenu::scene(), Color3B(255, 255, 255)));
	})));
} //button tekan exit yes

void Scene1a::quit_no(Ref* sender)
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
void Scene1a::teksJalan(float dt)
{

	teks_satu();
}

void Scene1a::teks_satu()
{
	if (!textSelesai)
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
			unschedule(schedule_selector(Scene1a::teksJalan));
			textSelesai = true;
		}
	}
	else
	{
		teks_1->setOpacity(255);
		teks_1->setColor(Color3B::BLACK);
		unschedule(schedule_selector(Scene1a::teksJalan));
	}
}


void Scene1a::rei()
{
	auto teks_nama = __String::createWithFormat("Rei")->getCString();
	nama->setString(teks_nama);
}
void Scene1a::anna()
{
	auto teks_nama = __String::createWithFormat("Anna")->getCString();
	nama->setString(teks_nama);
}
void Scene1a::nana()
{
	auto teks_nama = __String::createWithFormat("Nana")->getCString();
	nama->setString(teks_nama);
}
void Scene1a::nama_kosong()
{
	auto teks_nama = __String::createWithFormat("")->getCString();
	nama->setString(teks_nama);
}
void Scene1a::nama_titik()
{
	auto teks_nama = __String::createWithFormat("......")->getCString();
	nama->setString(teks_nama);
}
void Scene1a::wali()
{
	auto teks_nama = __String::createWithFormat("Wali Kelas")->getCString();
	nama->setString(teks_nama);
}


