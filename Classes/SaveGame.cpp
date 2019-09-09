#include "SaveGame.h"
#include "Option.h"
#include "HomeMenu.h"

USING_NS_CC;

Scene* SaveGame::scene()
{
	return SaveGame::create();
}

bool SaveGame::init()
{
	if (!Scene::init())
	{
		return false;
	}


	background->setAnchorPoint(Vec2(0, 0));
	background->setPosition(Vec2(0, 0));
	this->addChild(background,0);

	auto label_save = Label::createWithTTF("SAVE GAME", "fonts/arial.ttf", 50);
	label_save->setPosition(Vec2(1366 / 2, 650));
	label_save->setAnchorPoint(Vec2(0.5, 1));
	this->addChild(label_save);

	close->setAnchorPoint(Vec2(1, 1));
	close->setPosition(Vec2(1360, 760));
	this->addChild(close, 1);


	//button save lokasi//
	btn_save_1->setPosition(Vec2(233, 385));
	btn_save_2->setPosition(Vec2(677, 385));
	btn_save_3->setPosition(Vec2(1120, 385));
	btn_save_4->setPosition(Vec2(233, 156));
	btn_save_5->setPosition(Vec2(677, 156));
	btn_save_6->setPosition(Vec2(1120, 156));
	this->addChild(btn_save_1,1);
	this->addChild(btn_save_2, 1);
	this->addChild(btn_save_3, 1);
	this->addChild(btn_save_4, 1);
	this->addChild(btn_save_5, 1);
	this->addChild(btn_save_6, 1);
	/////////////////////

	//teks label save game//
	
	btn_save_1->addChild(label_save1);
	btn_save_2->addChild(label_save2);
	btn_save_3->addChild(label_save3);
	btn_save_4->addChild(label_save4);
	btn_save_5->addChild(label_save5);
	btn_save_6->addChild(label_save6);
	label_save1->setPosition(btn_save_1->getContentSize().width / 2, btn_save_1->getContentSize().height / 2);
	label_save2->setPosition(btn_save_1->getContentSize().width / 2, btn_save_1->getContentSize().height / 2);
	label_save3->setPosition(btn_save_1->getContentSize().width / 2, btn_save_1->getContentSize().height / 2);
	label_save4->setPosition(btn_save_1->getContentSize().width / 2, btn_save_1->getContentSize().height / 2);
	label_save5->setPosition(btn_save_1->getContentSize().width / 2, btn_save_1->getContentSize().height / 2);
	label_save6->setPosition(btn_save_1->getContentSize().width / 2, btn_save_1->getContentSize().height / 2);
	///////////////////////
	
	//cek kondisi save//
	log("Game ke-1 = %d",UserDefault::getInstance()->getBoolForKey("Game_ke_1",0));
	log("Game ke-2 = %d", UserDefault::getInstance()->getBoolForKey("Game_ke_2", 0));
	log("Game ke-3 = %d", UserDefault::getInstance()->getBoolForKey("Game_ke_3", 0));
	log("Game ke-4 = %d", UserDefault::getInstance()->getBoolForKey("Game_ke_4", 0));
	log("Game ke-5= %d", UserDefault::getInstance()->getBoolForKey("Game_ke_5", 0));
	log("Game ke-6= %d", UserDefault::getInstance()->getBoolForKey("Game_ke_6", 0));
	log("Nilai ke-1 = %d", UserDefault::getInstance()->getIntegerForKey("Nilai_ke_1", 0));
	log("Nilai ke-2 = %d", UserDefault::getInstance()->getIntegerForKey("Nilai_ke_2", 0));
	log("Nilai ke-3 = %d", UserDefault::getInstance()->getIntegerForKey("Nilai_ke_3", 0));
	log("Nilai ke-4 = %d", UserDefault::getInstance()->getIntegerForKey("Nilai_ke_4", 0));
	log("Nilai ke-5 = %d", UserDefault::getInstance()->getIntegerForKey("Nilai_ke_5", 0));
	log("Nilai ke-6 = %d", UserDefault::getInstance()->getIntegerForKey("Nilai_ke_6", 0));
	log("Teks ke-1= %d", UserDefault::getInstance()->getIntegerForKey("Teks_ke_1", 0));
	log("Teks ke-2= %d", UserDefault::getInstance()->getIntegerForKey("Teks_ke_2", 0));
	log("Teks ke-3= %d", UserDefault::getInstance()->getIntegerForKey("Teks_ke_3", 0));
	log("Teks ke-4= %d", UserDefault::getInstance()->getIntegerForKey("Teks_ke_4", 0));
	log("Teks ke-5= %d", UserDefault::getInstance()->getIntegerForKey("Teks_ke_5", 0));
	log("Teks ke-6= %d", UserDefault::getInstance()->getIntegerForKey("Teks_ke_6", 0));


	auto save_1 = UserDefault::getInstance()->getBoolForKey("Game_ke_1");
	auto save_2 = UserDefault::getInstance()->getBoolForKey("Game_ke_2");
	auto save_3 = UserDefault::getInstance()->getBoolForKey("Game_ke_3");
	auto save_4 = UserDefault::getInstance()->getBoolForKey("Game_ke_4");
	auto save_5 = UserDefault::getInstance()->getBoolForKey("Game_ke_5");
	auto save_6 = UserDefault::getInstance()->getBoolForKey("Game_ke_6");

	if (save_1 == 0)
	{
		teks = __String::createWithFormat("Empty Slot.")->getCString();
		label_save1->setString(teks);
	}
	else
	{
		nilai_save_game_1();
		label_save1->setString(teks);
	}
	if (save_2 == 0)
	{
		teks = __String::createWithFormat("Empty Slot.")->getCString();
		label_save2->setString(teks);
	}
	else
	{
		nilai_save_game_2();
		label_save2->setString(teks);
	}
	if (save_3 == 0)
	{
		const char* teks = __String::createWithFormat("Empty Slot.")->getCString();
		label_save3->setString(teks);
	}
	else
	{
		nilai_save_game_3();
		label_save3->setString(teks);
	}
	if (save_4 == 0)
	{
		teks = __String::createWithFormat("Empty Slot.")->getCString();
		label_save4->setString(teks);
	}
	else
	{
		nilai_save_game_4();
		label_save4->setString(teks);
	}
	if (save_5 == 0)
	{
		 teks = __String::createWithFormat("Empty Slot.")->getCString();
		label_save5->setString(teks);
	}
	else
	{
		nilai_save_game_5();
		label_save5->setString(teks);
	}
	if (save_6 == 0)
	{
		teks = __String::createWithFormat("Empty Slot.")->getCString();
		label_save6->setString(teks);
	}
	else
	{
		nilai_save_game_6();
		label_save6->setString(teks);
	}
	///////////////////


	close->addClickEventListener(CC_CALLBACK_1(SaveGame::keluar, this));
	btn_save_1->addClickEventListener(CC_CALLBACK_1(SaveGame::save_game_1, this));
	btn_save_2->addClickEventListener(CC_CALLBACK_1(SaveGame::save_game_2, this));
	btn_save_3->addClickEventListener(CC_CALLBACK_1(SaveGame::save_game_3, this));
	btn_save_4->addClickEventListener(CC_CALLBACK_1(SaveGame::save_game_4, this));
	btn_save_5->addClickEventListener(CC_CALLBACK_1(SaveGame::save_game_5, this));
	btn_save_6->addClickEventListener(CC_CALLBACK_1(SaveGame::save_game_6, this));
	return true;
}

void SaveGame::keluar(Ref* sender)
{
	HomeMenu::btn_sound();

	Director::getInstance()->popScene();
}

void SaveGame::save_game_1(Ref* sender)
{
	HomeMenu::btn_sound();
	UserDefault::getInstance()->setBoolForKey("Game_ke_1", true);
	UserDefault::getInstance()->setIntegerForKey("Teks_ke_1", HomeMenu::nilai_teks);
	UserDefault::getInstance()->setIntegerForKey("Nilai_ke_1", HomeMenu::game);
	nilai_save_game_1();
	label_save1->setString(teks);
	
}

void SaveGame::save_game_2(Ref* sender)
{
	HomeMenu::btn_sound();
	UserDefault::getInstance()->setBoolForKey("Game_ke_2",true);
	UserDefault::getInstance()->setIntegerForKey("Teks_ke_2", HomeMenu::nilai_teks);
	UserDefault::getInstance()->setIntegerForKey("Nilai_ke_2", HomeMenu::game);
	nilai_save_game_2();
	label_save2->setString(teks);
}

void SaveGame::save_game_3(Ref* sender)
{
	HomeMenu::btn_sound();
	UserDefault::getInstance()->setBoolForKey("Game_ke_3",true);
	UserDefault::getInstance()->setIntegerForKey("Teks_ke_3", HomeMenu::nilai_teks);
	UserDefault::getInstance()->setIntegerForKey("Nilai_ke_3", HomeMenu::game);
	nilai_save_game_3();
	label_save3->setString(teks);
}

void SaveGame::save_game_4(Ref* sender)
{
	HomeMenu::btn_sound();
	UserDefault::getInstance()->setBoolForKey("Game_ke_4",true);
	UserDefault::getInstance()->setIntegerForKey("Teks_ke_4", HomeMenu::nilai_teks);
	UserDefault::getInstance()->setIntegerForKey("Nilai_ke_4", HomeMenu::game);
	nilai_save_game_4();
	label_save4->setString(teks);
}

void SaveGame::save_game_5(Ref* sender)
{
	HomeMenu::btn_sound();
	UserDefault::getInstance()->setBoolForKey("Game_ke_5", true);
	UserDefault::getInstance()->setIntegerForKey("Teks_ke_5", HomeMenu::nilai_teks);
	UserDefault::getInstance()->setIntegerForKey("Nilai_ke_5", HomeMenu::game);
	nilai_save_game_5();
	label_save5->setString(teks);
}

void SaveGame::save_game_6(Ref* sender)
{
	HomeMenu::btn_sound();
	UserDefault::getInstance()->setIntegerForKey("Teks_ke_6", HomeMenu::nilai_teks);
	UserDefault::getInstance()->setBoolForKey("Game_ke_6", true);
	UserDefault::getInstance()->setIntegerForKey("Nilai_ke_6", HomeMenu::game);
	nilai_save_game_6();
	label_save6->setString(teks);
}

void SaveGame::nilai_save_game_1()
{
	i = UserDefault::getInstance()->getIntegerForKey("Nilai_ke_1");
	teks_save(1);
}
void SaveGame::nilai_save_game_2()
{
	i = UserDefault::getInstance()->getIntegerForKey("Nilai_ke_2");
	teks_save(2);
}
void SaveGame::nilai_save_game_3()
{
	i = UserDefault::getInstance()->getIntegerForKey("Nilai_ke_3");
	teks_save(3);
}
void SaveGame::nilai_save_game_4()
{
	i = UserDefault::getInstance()->getIntegerForKey("Nilai_ke_4");
	teks_save(4);
}
void SaveGame::nilai_save_game_5()
{
	i = UserDefault::getInstance()->getIntegerForKey("Nilai_ke_5");
	teks_save(5);
}
void SaveGame::nilai_save_game_6()
{
	i = UserDefault::getInstance()->getIntegerForKey("Nilai_ke_6");
	teks_save(6);
}
void SaveGame::teks_save(int teks_ke)
{
	const char* nilai_teks_ke;
	if (teks_ke == 1)
	{
		nilai_teks_ke = "Teks_ke_1";
	}
	else if (teks_ke == 2)
	{
		nilai_teks_ke = "Teks_ke_2";
	}
	else if (teks_ke == 3)
	{
		nilai_teks_ke = "Teks_ke_3";
	}
	else if (teks_ke == 4)
	{
		nilai_teks_ke = "Teks_ke_4";
	}
	else if (teks_ke == 5)
	{
		nilai_teks_ke = "Teks_ke_5";
	}
	else if (teks_ke == 6)
	{
		nilai_teks_ke = "Teks_ke_6";
	}

	if (i == 1)
	{
	teks = __String::createWithFormat("Hari yang Santai -  %d", UserDefault::getInstance()->getIntegerForKey(nilai_teks_ke))->getCString();
	}
	else if (i == 2)
	{
		teks = __String::createWithFormat("Keputusan Pertama -  %d", UserDefault::getInstance()->getIntegerForKey(nilai_teks_ke))->getCString();
	}
	else if (i == 3)
	{
		teks = __String::createWithFormat("Diatas Cerdas -  %d", UserDefault::getInstance()->getIntegerForKey(nilai_teks_ke))->getCString();
	}
	else if (i == 4)
	{
		teks = __String::createWithFormat("Gadis Strawberry -  %d", UserDefault::getInstance()->getIntegerForKey(nilai_teks_ke))->getCString();
	}
	else if (i == 5)
	{
		teks = __String::createWithFormat("Kemiripan Kami -  %d", UserDefault::getInstance()->getIntegerForKey(nilai_teks_ke))->getCString();
	}
	else if (i == 6)
	{
		teks = __String::createWithFormat("Anna dan Nana -  %d", UserDefault::getInstance()->getIntegerForKey(nilai_teks_ke))->getCString();
	}
	else if (i == 7)
	{
		teks = __String::createWithFormat("Kafe -  %d", UserDefault::getInstance()->getIntegerForKey(nilai_teks_ke))->getCString();
	}
	else if (i == 8)
	{
		teks = __String::createWithFormat("Bayi itu merepotkan -  %d", UserDefault::getInstance()->getIntegerForKey(nilai_teks_ke))->getCString();
	}
	else if (i == 9)
	{
		teks = __String::createWithFormat("Segalanya Berubah -  %d", UserDefault::getInstance()->getIntegerForKey(nilai_teks_ke))->getCString();
	}
	else if (i == 10)
	{
		teks = __String::createWithFormat("Recording -  %d", UserDefault::getInstance()->getIntegerForKey(nilai_teks_ke))->getCString();
	}
	else if (i == 11)
	{
		teks = __String::createWithFormat("Lambang Kesucian -  %d", UserDefault::getInstance()->getIntegerForKey(nilai_teks_ke))->getCString();
	}
	else if (i == 12)
	{
		teks = __String::createWithFormat("Ini Bukan Mimpi -  %d", UserDefault::getInstance()->getIntegerForKey(nilai_teks_ke))->getCString();
	}
	else if (i == 13)
	{
		teks = __String::createWithFormat("Apakah Kamu Sedang.. -  %d", UserDefault::getInstance()->getIntegerForKey(nilai_teks_ke))->getCString();
	}
	else if (i == 14)
	{
		teks = __String::createWithFormat("Rei yang Bodoh -  %d", UserDefault::getInstance()->getIntegerForKey(nilai_teks_ke))->getCString();
	}
	else if (i == 15)
	{
		teks = __String::createWithFormat("Kirana Adriani -  %d", UserDefault::getInstance()->getIntegerForKey(nilai_teks_ke))->getCString();
	}
	else if (i == 16)
	{
		teks = __String::createWithFormat("Perempuan yang unik -  %d", UserDefault::getInstance()->getIntegerForKey(nilai_teks_ke))->getCString();
	}
	else if (i == 17)
	{
		teks = __String::createWithFormat("Tidak Buruk Juga -  %d", UserDefault::getInstance()->getIntegerForKey(nilai_teks_ke))->getCString();
	}
	else if (i == 18)
	{
		teks = __String::createWithFormat("Anna Vitasha -  %d", UserDefault::getInstance()->getIntegerForKey(nilai_teks_ke))->getCString();
	}
}