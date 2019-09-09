#include "MiniGame2.h"
#include "HomeMenu.h"
#include "Scene10a.h"


USING_NS_CC;

Scene* MiniGame2::createScene()
{
	return MiniGame2::create();
}

// on "init" you need to initialize your instance
bool MiniGame2::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(MiniGame2::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(MiniGame2::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(MiniGame2::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	background->setPosition(Vec2(0, 0));background->setAnchorPoint(Vec2(0, 0));
	this->addChild(background);
	Mobo->setPosition(Vec2(248+ 150, 768 - 424));
	this->addChild(Mobo,2);
	soal->setPosition(Vec2(1366 / 2 + 300, 768 / 2));
	sprite->setPosition(Vec2(255 + 150, 768-367));
	sprite2->setPosition(Vec2(146 + 150, 768-427));
	sprite3->setPosition(Vec2(194 + 150, 768-542));
	sprite4->setPosition(Vec2(32 + 150, 768-255));
	sprite5->setPosition(Vec2(34 + 150, 768-402));
	sprite6->setPosition(Vec2(369 + 150, 768-589));
	sprite7->setPosition(Vec2(416 + 150, 768-653));
	sprite8->setPosition(Vec2(429 + 150, 768-372));
	sprite->setColor(Color3B::BLACK);
	sprite2->setColor(Color3B::BLACK);
	sprite3->setColor(Color3B::BLACK);
	sprite4->setColor(Color3B::BLACK);
	sprite5->setColor(Color3B::BLACK);
	sprite6->setColor(Color3B::BLACK);
	sprite7->setColor(Color3B::BLACK);
	sprite8->setColor(Color3B::BLACK);
	this->addChild(soal,4);
	this->addChild(sprite,3);
	this->addChild(sprite2, 3);
	this->addChild(sprite3, 3);
	this->addChild(sprite4, 3);
	this->addChild(sprite5, 3);
	this->addChild(sprite6, 3);
	this->addChild(sprite7, 3);
	this->addChild(sprite8, 3);


	
	this->addChild(tulisan,4);
	tulisan->setPosition(Vec2(1200, 700));
	this->addChild(mobo_teks,3);
	mobo_teks->setAnchorPoint(Vec2(0, 0));
	mobo_teks->setPosition(Vec2(250,590));
	this->addChild(soal_teks, 3);
	soal_teks->setAnchorPoint(Vec2(0.5, 0.5));
	soal_teks->setPosition(Vec2(1366 / 2 + 300, 768 / 2+200));;
	bg_soal->setPosition(Vec2(1366 / 2 + 300, 768 / 2));
	bg_soal->setAnchorPoint(Vec2(0.5, 0.5));
	bg_soal->setScale(0.7);
	this->addChild(bg_soal, 1);
	bg_mobo->setPosition(Vec2(background->getPosition().x +50, background->getPosition().y+90));
	this->addChild(bg_mobo,1);
	bg_mobo->setAnchorPoint(Vec2(0,0));

	//hasil//
	kosong->setPosition(Vec2(0, 0));
	kosong->setAnchorPoint(Vec2(0, 0));
	this->addChild(kosong, 2);
	tampil_hasil->setPosition(Vec2(1366 / 2, 768 / 2));
	kosong->addChild(tampil_hasil);
	hasil_score->setPosition(Vec2(tampil_hasil->getContentSize().width / 2, tampil_hasil->getContentSize().height / 2 ));
	tampil_hasil->addChild(hasil_score);
	kosong->setScale(0);
	btn_next->setScale(0);
	btn_next->setPosition(Vec2(1366 / 2, 200));
	kosong->addChild(btn_next);
	////////

	bg_menu->setPosition(Vec2(1366 / 2, 768 / 2));
	label_hard->setPosition(Vec2(btn_hard->getContentSize().width / 2, btn_hard->getContentSize().height / 2));
	label_medium->setPosition(Vec2(btn_hard->getContentSize().width / 2, btn_hard->getContentSize().height / 2));
	label_easy->setPosition(Vec2(btn_hard->getContentSize().width / 2, btn_hard->getContentSize().height / 2));
	btn_hard->setPosition(Vec2(1366 / 2, 550));
	btn_medium->setPosition(Vec2(1366 / 2, 400));
	btn_easy->setPosition(Vec2(1366 / 2, 250));
	this->addChild(bg_menu, 4);
	this->addChild(btn_hard, 4);
	this->addChild(btn_medium, 4);
	this->addChild(btn_easy, 4);
	btn_hard->addChild(label_hard);
	btn_medium->addChild(label_medium);
	btn_easy->addChild(label_easy);
	btn_hard->addClickEventListener(CC_CALLBACK_1(MiniGame2::hard, this));
	btn_medium->addClickEventListener(CC_CALLBACK_1(MiniGame2::medium, this));
	btn_easy->addClickEventListener(CC_CALLBACK_1(MiniGame2::easy, this));
	btn_next->addClickEventListener(CC_CALLBACK_1(MiniGame2::next, this));
	random_soal();
	time_text->setPosition(Vec2(1366 / 2, 750));
	this->addChild(time_text);
	//schedule(schedule_selector(MiniGame2::durasi),1.f);
	return true;
}
void MiniGame2::hard(Ref* sender)
{
	HomeMenu::btn_sound();
	pil_menu = 1;
	btn_hard->setScale(0);
	btn_medium->setScale(0);
	btn_easy->setScale(0);
	bg_menu->setScale(0);
	waktu = 10;
	this->schedule(schedule_selector(MiniGame2::durasi), 1.f);
	log("Menu pilihan = %d", pil_menu);
}
void MiniGame2::medium(Ref* sender)
{
	HomeMenu::btn_sound();
	pil_menu = 2;
	btn_hard->setScale(0);
	btn_medium->setScale(0);
	btn_easy->setScale(0);
	bg_menu->setScale(0);
	waktu = 30;
	this->schedule(schedule_selector(MiniGame2::durasi), 1.f);
	log("Menu pilihan = %d", pil_menu);
}
void MiniGame2::easy(Ref* sender)
{
	HomeMenu::btn_sound();
	pil_menu = 3;
	btn_hard->setScale(0);
	btn_medium->setScale(0);
	btn_easy->setScale(0);
	bg_menu->setScale(0);
	waktu = 60;
	this->schedule(schedule_selector(MiniGame2::durasi), 1.f);
	log("Menu pilihan = %d", pil_menu);
}

bool MiniGame2::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
	CCLOG("onTouchBegan x = %f, y = %f", touch->getLocation().x, touch->getLocation().y);
	Point touchLoc = touch->getLocationInView();

	if (soal->getBoundingBox().containsPoint(touchLoc))
	{
		return true;
	}
	return false;
}

void MiniGame2::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
	CCLOG("onTouchMoved x = %f, y = %f", touch->getLocation().x, touch->getLocation().y);
	soal->setPosition(soal->getPosition() + touch->getDelta());
}

void MiniGame2::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
	HomeMenu::btn_sound();
	switch (nilai)
	{
	case 1:
		if (soal->getBoundingBox().intersectsRect(sprite->getBoundingBox()))
		{
			soal->setPosition(Vec2(1366 / 2 + 300, 768 / 2));
			sprite->setScale(0);
			Selesai();
		}
		soal->setPosition(Vec2(1366 / 2 + 300, 768 / 2));
		break;
	case 2:
		if (soal->getBoundingBox().intersectsRect(sprite2->getBoundingBox()))
		{
			soal->setPosition(Vec2(1366 / 2 + 300, 768 / 2));
			sprite2->setScale(0);
			Selesai();
		}
		soal->setPosition(Vec2(1366 / 2 + 300, 768 / 2));
		break;
	case 3:
		if (soal->getBoundingBox().intersectsRect(sprite3->getBoundingBox()))
		{
			soal->setPosition(Vec2(1366 / 2 + 300, 768 / 2));
			sprite3->setScale(0);
			Selesai();
		}
		soal->setPosition(Vec2(1366 / 2 + 300, 768 / 2));
		break;
	case 4:
		if (soal->getBoundingBox().intersectsRect(sprite4->getBoundingBox()))
		{
			soal->setPosition(Vec2(1366 / 2 + 300, 768 / 2));
			sprite4->setScale(0);
			Selesai();
		}
		soal->setPosition(Vec2(1366 / 2 + 300, 768 / 2));
		break;
	case 5:
		if (soal->getBoundingBox().intersectsRect(sprite5->getBoundingBox()))
		{
			soal->setPosition(Vec2(1366 / 2 + 300, 768 / 2));
			sprite5->setScale(0);
			Selesai();
		}
		soal->setPosition(Vec2(1366 / 2 + 300, 768 / 2));
		break;
	case 6:
		if (soal->getBoundingBox().intersectsRect(sprite6->getBoundingBox()))
		{
			soal->setPosition(Vec2(1366 / 2 + 300, 768 / 2));
			sprite6->setScale(0);
			Selesai();
		}
		soal->setPosition(Vec2(1366 / 2 + 300, 768 / 2));
		break;
	case 7:
		if (soal->getBoundingBox().intersectsRect(sprite7->getBoundingBox()))
		{
			soal->setPosition(Vec2(1366 / 2 + 300, 768 / 2));
			sprite7->setScale(0);
			Selesai();
		}
		soal->setPosition(Vec2(1366 / 2 + 300, 768 / 2));
		break;
	case 8:
		if (soal->getBoundingBox().intersectsRect(sprite8->getBoundingBox()))
		{
			soal->setPosition(Vec2(1366 / 2 + 300, 768 / 2));
			sprite8->setScale(0);
			Selesai();
		}
		soal->setPosition(Vec2(1366 / 2 + 300, 768 / 2));
		break;
	default:
		break;
	}

}
void MiniGame2::Selesai()
{
	if (total_soal < 7)
	{
		total_soal++;
		random_soal();
	}
	else
	{
		kosong->setScale(1);
		kosongscale();
		auto score1 = UserDefault::getInstance()->getFloatForKey("ScoreMiniGame2Hard");
		auto score2 = UserDefault::getInstance()->getFloatForKey("ScoreMiniGame2Medium");
		auto score3 = UserDefault::getInstance()->getFloatForKey("ScoreMiniGame2Easy");
		auto label_highScore = Label::create("NEW HIGH SCORE!!", "fonts/arial.ttf", 80);
		label_highScore->setColor(Color3B::BLACK);
		label_highScore->setPosition(Vec2(1366 / 2, 700));

		switch (pil_menu)
		{
		case 1:
			score = waktu*10;
			if (score > score1)
			{
				UserDefault::getInstance()->setFloatForKey("ScoreMiniGame2Hard", score);
				this->addChild(label_highScore, 4);
			}
			break;
		case 2:
			score = waktu/3*10;
			if (score > score2)
			{
				UserDefault::getInstance()->setFloatForKey("ScoreMiniGame2Medium", score);
				this->addChild(label_highScore, 4);
			}
			break;
		case 3:
			score = waktu/6*10;
			if (score > score3)
			{
				UserDefault::getInstance()->setFloatForKey("ScoreMiniGame2Easy", score);
				this->addChild(label_highScore, 4);
			}
			break;
		default:
			break;
		}
		auto string_score = __String::createWithFormat("Nilai Score = %.2f", score)->getCString();
		hasil_score->setString(string_score);
		unschedule(schedule_selector(MiniGame2::durasi));
		btn_next->setScale(1);
		auto next_label = Label::createWithTTF("Lanjut", "fonts/arial.ttf", 30);
		next_label->setPosition(Vec2(btn_next->getContentSize().width / 2, btn_next->getContentSize().height / 2));
		btn_next->addChild(next_label);
	}
}

void MiniGame2::random_soal()
{
	nilai = random(1, 8);

	switch (nilai)
	{
	case 1:
		if (bool_soal1)
		{
			bool_soal1 = false;
			log("Soal 1");
			soal->setTexture(__String::createWithFormat("MiniGame2/mobo%d.png", nilai)->getCString());
		}
		else random_soal();
		break;
	case 2:
		if (bool_soal2)
		{
			bool_soal2 = false;
			log("Soal 2");
			soal->setTexture(__String::createWithFormat("MiniGame2/mobo%d.png", nilai)->getCString());
		}
		else random_soal();
		break;
	case 3:
		if (bool_soal3)
		{
			bool_soal3 = false;
			log("Soal 3");
			soal->setTexture(__String::createWithFormat("MiniGame2/mobo%d.png", nilai)->getCString());
		}
		else random_soal();
		break;
	case 4:
		if (bool_soal4)
		{
			bool_soal4 = false;
			log("Soal 4");
			soal->setTexture(__String::createWithFormat("MiniGame2/mobo%d.png", nilai)->getCString());
		}
		else random_soal();
		break;
	case 5:
		if (bool_soal5)
		{
			bool_soal5 = false;
			log("Soal 5");
			soal->setTexture(__String::createWithFormat("MiniGame2/mobo%d.png", nilai)->getCString());
		}
		else random_soal();
		break;
	case 6:
		if (bool_soal6)
		{
			bool_soal6 = false;
			log("Soal 6");
			soal->setTexture(__String::createWithFormat("MiniGame2/mobo%d.png", nilai)->getCString());
		}
		else random_soal();
		break;
	case 7:
		if (bool_soal7)
		{
			bool_soal7 = false;
			log("Soal 7");
			soal->setTexture(__String::createWithFormat("MiniGame2/mobo%d.png", nilai)->getCString());
		}
		else random_soal();
		break;
	case 8:
		if (bool_soal8)
		{
			bool_soal8 = false;
			log("Soal 8");
			soal->setTexture(__String::createWithFormat("MiniGame2/mobo%d.png", nilai)->getCString());
		}
		else random_soal();
		break;
	default:
		break;
	}

}

void MiniGame2::durasi(float dt)
{

	auto duration = __String::createWithFormat("%.f", waktu)->getCString();
	time_text->setString(duration);
	waktu--;
	if (waktu < 0)
	{
		kosong->setScale(1);
		kosongscale();
		auto string_score = __String::createWithFormat("Nilai Score = FAIL")->getCString();
		hasil_score->setString(string_score);
		unschedule(schedule_selector(MiniGame2::durasi));
		auto label = Label::createWithTTF("WAKTU TELAH HABIS", "fonts/arial.ttf", 60);
		label->setPosition(Vec2(1366 / 2, 700));
		label->setAnchorPoint(Vec2(0.5, 1));
		this->addChild(label, 4);
		btn_next->setScale(1);
		auto next_label = Label::createWithTTF("Lanjut", "fonts/arial.ttf", 30);
		next_label->setPosition(Vec2(btn_next->getContentSize().width / 2, btn_next->getContentSize().height / 2));
		btn_next->addChild(next_label);

		
	}
	
}
void MiniGame2::kosongscale()
{
	sprite->setVisible(false);
	sprite2->setVisible(false);
	sprite3->setVisible(false);
	sprite4->setVisible(false);
	sprite5->setVisible(false);
	sprite6->setVisible(false);
	sprite7->setVisible(false);
	sprite8->setVisible(false);
	bg_menu->setVisible(false);
	Mobo->setVisible(false);
	soal->setVisible(false);
	tulisan->setVisible(false);
	soal_teks->setVisible(false);
	mobo_teks->setVisible(false);
	bg_soal->setVisible(false);
	bg_mobo->setVisible(false);
}
void MiniGame2::next(Ref* sender)
{
	HomeMenu::btn_sound();
	kosong->setOpacity(200);
	btn_next->setScale(0); tampil_hasil->setScale(0);
	schedule(schedule_selector(MiniGame2::done), 1.f);
	auto loading_label = Label::createWithTTF("LOADING", "fonts/arial.ttf", 100);
	loading_label->setPosition(Vec2(1366 / 2, 768 / 2));
	kosong->addChild(loading_label);
}
void MiniGame2::done(float dt)
{
	waktu_next--;
	if (waktu_next == -1)
	{
		HomeMenu::nilai_teks = 112;
		this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
		{
			Director::getInstance()->replaceScene(TransitionFade::create(3, Scene10a::scene(), Color3B(255, 255, 255)));
		})));
	}
}