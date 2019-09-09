#include "HomeMenu.h"
#include "MiniGame.h"
#include "HighScore.h"
#include "Scene1.h"
#include "Option.h"
#include "Credit.h"
#include "SaveGame.h"
#include "LoadGame.h"

USING_NS_CC;

bool HomeMenu::nilai_logo = true;
int HomeMenu::game = 0;
int HomeMenu::nilai_teks = 1;
bool HomeMenu::load_game = false;
Scene* HomeMenu::scene()
{
	return HomeMenu::create();
}

bool HomeMenu::init()
{
	if (!Scene::init())
	{
		return false;
	}
	
	bg_exit->setPosition(Vec2(1366 / 2, 768 / 2));
	bg_exit->setAnchorPoint(Vec2(0.5, 0.5));
	bg_exit->setScale(0);

	btn_exit_no->setPosition(Vec2(bg_exit->getContentSize().width / 2+30, bg_exit->getContentSize().height / 2 ));
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
	kosong->setAnchorPoint(Vec2(0,0));
	kosong->setScale(0);

	this->addChild(bg_exit, 3);
	this->addChild(kosong,2);
	bg_exit->addChild(btn_exit_yes);
	bg_exit->addChild(btn_exit_no);
	btn_exit_no->addChild(label_quit_no);
	btn_exit_yes->addChild(label_quit_yes);


	background->setPosition(1366 / 2, 768 / 2);
	background->setAnchorPoint(Vec2(0.5, 0.5));
	this->addChild(background, 0);
	judul->setPosition(-50,900);
	judul->setAnchorPoint(Vec2(0, 1));
	judul->setScale(1);
	this->addChild(judul);

	if (HomeMenu::nilai_logo == true) // boolean untuk mengecek, apakah kita membuka menu waktu awal atau tidak, jika dari awal, maka fungsi nilai_logo akan true dan lalu menjalankan jadwal, jika false, maka langsung ketampil menu
	{
		logo->setScale(0.3);
		logo->setPosition(1366 / 2, 768 / 2);
		this->addChild(logo, 1);
		background->setOpacity(0);
		judul->setOpacity(0);
		buttonStart->setOpacity(0);
		buttonStart1->setOpacity(0);
		buttonStart2->setOpacity(0);
		buttonStart3->setOpacity(0);
		buttonStart4->setOpacity(0);
		buttonStart5->setOpacity(0);
		buttonHighScore->setOpacity(0);
		buttonMiniGame->setOpacity(0);

		label_start->setOpacity(0);
		label_load->setOpacity(0);
		label_setting->setOpacity(0);
		label_credit->setOpacity(0);
		label_rate->setOpacity(0);
		label_quit->setOpacity(0);
		label_miniGame->setOpacity(0);
		label_highScore->setOpacity(0);
		schedule(schedule_selector(HomeMenu::jadwalLogo), 1.f);

	}
	else
	{
		background->setOpacity(200);
		judul->setOpacity(200);
		buttonStart->setOpacity(200);
		buttonStart1->setOpacity(200);
		buttonStart2->setOpacity(200);
		buttonStart3->setOpacity(200);
		buttonStart4->setOpacity(200);
		buttonStart5->setOpacity(200);
		buttonHighScore->setOpacity(200);
		buttonMiniGame->setOpacity(200);

		label_start->setOpacity(200);
		label_load->setOpacity(200);
		label_setting->setOpacity(200);
		label_credit->setOpacity(200);
		label_rate->setOpacity(200);
		label_quit->setOpacity(200);
		label_miniGame->setOpacity(200);
		label_highScore->setOpacity(200);
	}

	buttonStart->setPosition(Vec2(683,249));
	buttonStart1->setPosition(Vec2(796,136));
	buttonStart2->setPosition(Vec2(909,249));
	buttonStart3->setPosition(Vec2(1022,136));
	buttonStart4->setPosition(Vec2(1135,249));
	buttonStart5->setPosition(Vec2(1248,136));
	buttonHighScore->setPosition(Vec2(796, 362));
	buttonMiniGame->setPosition(Vec2(1022, 362));

	buttonStart->setAnchorPoint(Vec2(0.5,0.5));
	buttonStart1->setAnchorPoint(Vec2(0.5, 0.5));
	buttonStart2->setAnchorPoint(Vec2(0.5, 0.5));
	buttonStart3->setAnchorPoint(Vec2(0.5, 0.5));
	buttonStart4->setAnchorPoint(Vec2(0.5, 0.5));
	buttonStart5->setAnchorPoint(Vec2(0.5, 0.5));
	buttonHighScore->setAnchorPoint(Vec2(0.5, 0.5));
	buttonMiniGame->setAnchorPoint(Vec2(0.5, 0.5));

	label_start->setPosition(Vec2(buttonStart->getSize().width/2, buttonStart->getSize().height/2));
	label_load->setPosition(Vec2(buttonStart1->getSize().width / 2, buttonStart1->getSize().height / 2));
	label_setting->setPosition(Vec2(buttonStart2->getSize().width / 2, buttonStart2->getSize().height / 2));
	label_credit->setPosition(Vec2(buttonStart3->getSize().width / 2, buttonStart3->getSize().height / 2));
	label_rate->setPosition(Vec2(buttonStart4->getSize().width / 2, buttonStart4->getSize().height / 2));
	label_quit->setPosition(Vec2(buttonStart5->getSize().width / 2, buttonStart5->getSize().height / 2));
	label_highScore->setPosition(Vec2(buttonHighScore->getSize().width / 2, buttonStart5->getSize().height / 2));
	label_miniGame->setPosition(Vec2(buttonMiniGame->getSize().width / 2, buttonStart5->getSize().height / 2));

	this->addChild(buttonStart, 1);
	this->addChild(buttonStart1, 1);
	this->addChild(buttonStart2, 1);
	this->addChild(buttonStart3, 1);
	this->addChild(buttonStart4, 1);
	this->addChild(buttonStart5, 1);
	this->addChild(buttonHighScore, 1);
	this->addChild(buttonMiniGame, 1);

	buttonStart->addChild(label_start);
	buttonStart1->addChild(label_load);
	buttonStart2->addChild(label_setting);
	buttonStart3->addChild(label_credit);
	buttonStart4->addChild(label_rate);
	buttonStart5->addChild(label_quit);
	buttonMiniGame->addChild(label_miniGame);
	buttonHighScore->addChild(label_highScore);

	buttonStart->addClickEventListener(CC_CALLBACK_1(HomeMenu::startGame, this));
	buttonStart1->addClickEventListener(CC_CALLBACK_1(HomeMenu::loadGame, this));
	buttonStart2->addClickEventListener(CC_CALLBACK_1(HomeMenu::optionGame, this));
	buttonStart3->addClickEventListener(CC_CALLBACK_1(HomeMenu::creditGame, this));
	buttonStart4->addClickEventListener(CC_CALLBACK_1(HomeMenu::rateGame, this));
	buttonStart5->addClickEventListener(CC_CALLBACK_1(HomeMenu::quitGame, this));
	btn_exit_no->addClickEventListener(CC_CALLBACK_1(HomeMenu::quit_no, this));
	btn_exit_yes->addClickEventListener(CC_CALLBACK_1(HomeMenu::quit_yes, this));
	buttonMiniGame->addClickEventListener(CC_CALLBACK_1(HomeMenu::miniGame, this));
	buttonHighScore->addClickEventListener(CC_CALLBACK_1(HomeMenu::highScore, this));
	return true;
}
void HomeMenu::miniGame(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, MiniGame::scene(), Color3B(255, 255, 255)));
	})));

}
void HomeMenu::highScore(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, HighScore::scene(), Color3B(255, 255, 255)));
	})));
}

void HomeMenu::loadGame(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, LoadGame::scene(), Color3B(255, 255, 255)));
	})));
}

void HomeMenu::jadwalLogo(float dt) // fungsi untuk membikin splash screen awal ketika game dibuka
{

	log("Nilai Waktu = %d", waktu);


	
	if (waktu == 0) // menyetop schedule
	{
	
		unschedule(schedule_selector(HomeMenu::jadwalLogo));
		unschedule(schedule_selector(HomeMenu::judulTampil));
	}
	else if(waktu == 2)
	{
		background->setOpacity(200);
		buttonStart->setOpacity(200);
		buttonStart1->setOpacity(200);
		buttonStart2->setOpacity(200);
		buttonStart3->setOpacity(200);
		buttonStart4->setOpacity(200);
		buttonStart5->setOpacity(200);
		buttonHighScore->setOpacity(200);
		buttonMiniGame->setOpacity(200);
		label_start->setOpacity(200);
		label_load->setOpacity(200);
		label_setting->setOpacity(200);
		label_credit->setOpacity(200);
		label_rate->setOpacity(200);
		label_quit->setOpacity(200);
		label_miniGame->setOpacity(200);
		label_highScore->setOpacity(200);
		bgm->playBackgroundMusic("music/menu.mp3", true);
		
		schedule(schedule_selector(HomeMenu::judulTampil),0.01f);
	}
	else if(waktu == 3)
		logo->setOpacity(0);
	waktu -= 1;
}

void HomeMenu::judulTampil(float dt) // durasi logo keluar saat splashscreen
{
	nilaiJudul += 1;
	judul->setOpacity(nilaiJudul);
}

void HomeMenu::startGame(Ref* sender)
{
	btn_sound();
	log("Mulai Game");
	HomeMenu::nilai_teks = 1;
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->replaceScene(TransitionFade::create(3, Scene1::scene(), Color3B(255, 255, 255)));
	})));
}


void HomeMenu::optionGame(Ref* sendder)
{
	btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(1, Option::scene(), Color3B(255, 255, 255)));
	})));
}

void HomeMenu::creditGame(Ref* sender)
{
	btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(1, Credit::scene(), Color3B(255, 255, 255)));
	})));
}

void HomeMenu::rateGame(Ref* sender)
{
	btn_sound();
	Application::getInstance()->openURL("https://play.google.com/");
}

void HomeMenu::quitGame(Ref* sender)
{
	btn_sound();
	bg_exit->setScale(1);
	kosong->setScale(1);
	btn_exit_no->setScale(1);
	btn_exit_yes->setScale(1);
	label_quit_no->setScale(1);
	label_quit_yes->setScale(1);
}

void HomeMenu::quit_yes(Ref* sender)
{	
	btn_sound();
	Director::getInstance()->end();
} //button tekan exit yes

void HomeMenu::quit_no(Ref* sender)
{
	btn_sound();
	bg_exit->setScale(0);
	kosong->setScale(0);
	btn_exit_no->setScale(0);
	btn_exit_yes->setScale(0);
	label_quit_no->setScale(0);
	label_quit_yes->setScale(0);
} // button tekan exit no

void HomeMenu::btn_sound()
{	

	SimpleAudioEngine* sfx = SimpleAudioEngine::getInstance();
	sfx->playEffect("music/button.mp3", false, 1.0f, 1.0f, 1.0f);
	sfx->setEffectsVolume(Option::volume_sfx);
}

void HomeMenu::bgm_home_volume()
{
	SimpleAudioEngine* bgm = SimpleAudioEngine::getInstance();
	bgm->setBackgroundMusicVolume(Option::volume_suara);
}