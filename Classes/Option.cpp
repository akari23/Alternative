#include "Option.h"
#include "HomeMenu.h"

USING_NS_CC;

float Option::volume_suara = 1;
float Option::speed_teks = 0.08;
float Option::speed_teks_nilai = 0.8;
float Option::volume_sfx = 1;

Scene* Option::scene()
{
	return Option::create();
}

bool Option::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto teks_volume = Label::createWithTTF("VOLUME", "fonts/arial.ttf", 50);
	auto teks_sfx = Label::createWithTTF("SFX", "fonts/arial.ttf", 50);
	auto teks_speed = Label::createWithTTF("SPEED TEXT", "fonts/arial.ttf", 50);
	background_tengah->addChild(teks_volume);
	background_tengah->addChild(teks_sfx);
	background_tengah->addChild(teks_speed);
	teks_volume->setPosition(Vec2(20, background_tengah->getContentSize().height / 2 + 80));
	teks_sfx->setPosition(Vec2(20, background_tengah->getContentSize().height / 2));
	teks_speed->setPosition(Vec2(20, background_tengah->getContentSize().height / 2 - 80));
	teks_volume->setAnchorPoint(Vec2(0, 0.5));
	teks_sfx->setAnchorPoint(Vec2(0, 0.5));
	teks_speed->setAnchorPoint(Vec2(0, 0.5));

	auto label_setting = Label::createWithTTF("SETTING", "fonts/arial.ttf", 50);
	label_setting->setAnchorPoint(Vec2(0, 1));
	label_setting->setPosition(Vec2(30, 760));
	this->addChild(label_setting, 1);

	background->setPosition(Vec2(0, 0));
	background->setAnchorPoint(Vec2(0, 0));
	background_tengah->setPosition(Vec2(1366 / 2, 768 / 2));
	background_tengah->setAnchorPoint(Vec2(0.5, 0.5));
	this->addChild(background_tengah, 1);
	this->addChild(background, 0);

	close->setAnchorPoint(Vec2(1, 1));
	close->setPosition(Vec2(1360, 760));
	this->addChild(close, 1);


	background_tengah->addChild(label_volume);
	background_tengah->addChild(label_sfx);
	background_tengah->addChild(label_speed);
	label_volume->setPosition(Vec2(background_tengah->getContentSize().width / 2 + 70, background_tengah->getContentSize().height / 2 + 80));
	label_sfx->setPosition(Vec2(background_tengah->getContentSize().width / 2 + 70, background_tengah->getContentSize().height / 2));
	label_speed->setPosition(Vec2(background_tengah->getContentSize().width / 2 + 70, background_tengah->getContentSize().height / 2 - 80));
	const char* nilai_volume = __String::createWithFormat("%.f", Option::volume_suara * 10)->getCString();
	const char* nilai_sfx = __String::createWithFormat("%.f", Option::volume_sfx * 10)->getCString();
	const char* nilai_speed = __String::createWithFormat("%.f", Option::speed_teks_nilai * 10)->getCString();
	label_volume->setString(nilai_volume);
	label_sfx->setString(nilai_sfx);
	label_speed->setString(nilai_speed);

	//button ngature volume bgm//
	background_tengah->addChild(volume_bgm_pluss);
	background_tengah->addChild(volume_bgm_minus);
	background_tengah->addChild(volume_sfx_pluss);
	background_tengah->addChild(volume_sfx_minus);
	background_tengah->addChild(speed_pluss);
	background_tengah->addChild(speed_minus);
	volume_bgm_pluss->setAnchorPoint(Vec2(0, 0.5));
	volume_bgm_minus->setAnchorPoint(Vec2(1, 0.5));
	volume_sfx_pluss->setAnchorPoint(Vec2(0, 0.5));
	volume_sfx_minus->setAnchorPoint(Vec2(1, 0.5));
	speed_pluss->setAnchorPoint(Vec2(0, 0.5));
	speed_minus->setAnchorPoint(Vec2(1, 0.5));
	volume_bgm_pluss->setPosition(Vec2(background_tengah->getContentSize().width / 2 + 30 + 200, background_tengah->getContentSize().height / 2 + 80));
	volume_bgm_minus->setPosition(Vec2(background_tengah->getContentSize().width / 2 + 200, background_tengah->getContentSize().height / 2 + 80));
	volume_sfx_pluss->setPosition(Vec2(background_tengah->getContentSize().width / 2 + 30 + 200, background_tengah->getContentSize().height / 2));
	volume_sfx_minus->setPosition(Vec2(background_tengah->getContentSize().width / 2 + 200, background_tengah->getContentSize().height / 2));
	speed_pluss->setPosition(Vec2(background_tengah->getContentSize().width / 2 + 30 + 200, background_tengah->getContentSize().height / 2 - 80));
	speed_minus->setPosition(Vec2(background_tengah->getContentSize().width / 2 + 200, background_tengah->getContentSize().height / 2 - 80));
	/////////////////////////////

	close->addClickEventListener(CC_CALLBACK_1(Option::keluar, this));
	volume_bgm_minus->addClickEventListener(CC_CALLBACK_1(Option::bgm_down, this));
	volume_bgm_pluss->addClickEventListener(CC_CALLBACK_1(Option::bgm_up, this));
	volume_sfx_pluss->addClickEventListener(CC_CALLBACK_1(Option::sfx_up, this));
	volume_sfx_minus->addClickEventListener(CC_CALLBACK_1(Option::sfx_down, this));
	speed_pluss->addClickEventListener(CC_CALLBACK_1(Option::speed_up, this));
	speed_minus->addClickEventListener(CC_CALLBACK_1(Option::speed_down, this));
	return true;
}

void Option::keluar(Ref* sender)
{
	HomeMenu::nilai_logo = false;
	HomeMenu::btn_sound();

	Director::getInstance()->popScene();

}

void Option::bgm_down(Ref* sender)
{
	HomeMenu::btn_sound();
	if (Option::volume_suara > 0.1)
		Option::volume_suara -= 0.1;
	else Option::volume_suara = 0;

	log("Nilai volume bg = %f", Option::volume_suara);
	HomeMenu::bgm_home_volume();
	const char* nilai_volume = __String::createWithFormat("%.f", Option::volume_suara * 10)->getCString();
	label_volume->setString(nilai_volume);
}

void Option::bgm_up(Ref* sender)
{
	HomeMenu::btn_sound();
	if (Option::volume_suara < 1)
	{
		Option::volume_suara += 0.1;
	}
	HomeMenu::bgm_home_volume();
	log("Nilai volume bg = %f", Option::volume_suara);
	const char* nilai_volume = __String::createWithFormat("%.f", Option::volume_suara * 10)->getCString();
	label_volume->setString(nilai_volume);
}

void Option::sfx_down(Ref* sender)
{

	if (Option::volume_sfx > 0.1)
		Option::volume_sfx -= 0.1;
	else Option::volume_sfx = 0;

	log("Nilai volume sfx = %f", Option::volume_sfx);
	HomeMenu::btn_sound();
	const char* nilai_volume = __String::createWithFormat("%.f", Option::volume_sfx * 10)->getCString();
	label_sfx->setString(nilai_volume);
}

void Option::sfx_up(Ref* sender)
{

	if (Option::volume_sfx < 1)
	{
		Option::volume_sfx += 0.1;
	}
	HomeMenu::btn_sound();
	log("Nilai volume sfx = %f", Option::volume_sfx);
	const char* nilai_volume = __String::createWithFormat("%.f", Option::volume_sfx * 10)->getCString();
	label_sfx->setString(nilai_volume);
}

void Option::speed_down(Ref* sender)
{
	if (Option::speed_teks_nilai > 0.1)
	{
		Option::speed_teks_nilai -= 0.1;
		Option::speed_teks += 0.01;
	}
	else Option::speed_teks_nilai = 0;

	log("Nilai volume sfx = %f", Option::speed_teks);
	HomeMenu::btn_sound();
	const char* nilai_volume = __String::createWithFormat("%.f", Option::speed_teks_nilai * 10)->getCString();
	label_speed->setString(nilai_volume);
}

void Option::speed_up(Ref* sender)
{
	if (Option::speed_teks_nilai < 1)
	{
		Option::speed_teks_nilai += 0.1;
		Option::speed_teks -= 0.01;
	}
	HomeMenu::btn_sound();
	log("Nilai volume sfx = %f", Option::speed_teks);
	const char* nilai_volume = __String::createWithFormat("%.f", Option::speed_teks_nilai * 10)->getCString();
	label_speed->setString(nilai_volume);
}

