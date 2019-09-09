#include "Scene4.h"
#include "Scene5.h"
#include "Option.h"
#include "HomeMenu.h"
#include "SaveGame.h"
#include "LoadGame.h"

USING_NS_CC;



Scene* Scene4::scene()
{
	return Scene4::create();
}

bool Scene4::init()
{
	if (!Scene::init())
	{
		return false;
	}
	bgm->playBackgroundMusic("music/4.mp3", true);
	HomeMenu::game = 8;
	

	//background//
	background->setPosition(Vec2(0, 0));
	background->setAnchorPoint(Vec2(0, 0));
	this->addChild(background);
	
	/////////////

	this->schedule(schedule_selector(Scene4::delay_game), 1);

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

	btn_load->addClickEventListener(CC_CALLBACK_1(Scene4::load_game, this));
	btn_save->addClickEventListener(CC_CALLBACK_1(Scene4::save_game, this));
	btn_config->addClickEventListener(CC_CALLBACK_1(Scene4::config, this));
	btn_exit_no->addClickEventListener(CC_CALLBACK_1(Scene4::quit_no, this));
	btn_exit_yes->addClickEventListener(CC_CALLBACK_1(Scene4::quit_yes, this));
	btn_tittle->addClickEventListener(CC_CALLBACK_1(Scene4::back_title, this));
	btn_close->addClickEventListener(CC_CALLBACK_1(Scene4::close_menu, this));
	buttonStart->addClickEventListener(CC_CALLBACK_1(Scene4::startGame, this));
	btn_menu->addClickEventListener(CC_CALLBACK_1(Scene4::pil_menu, this));
	//////////////////////////

	//gambar karakter//
	anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2+50));
	nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2+50));
	hiden_character();
	this->addChild(nana_sprite);
	this->addChild(anna_sprite);
	//////////////////
	//background//
	if (HomeMenu::nilai_teks > 61 && HomeMenu::nilai_teks < 78)
		background->setTexture("bg/kafe.jpg");
	else if (HomeMenu::nilai_teks > 77 )
		background->setTexture("bg/kafe_2.jpg");
	/////////////
	return true;
}
void Scene4::hiden_character()
{
	anna_sprite->setScale(0);
	nana_sprite->setScale(0);
}
void Scene4::delay_game(float dt)
{
	detik++;

	if (detik == 4)
	{
		isi_teks();
		this->schedule(schedule_selector(Scene4::teksJalan), Option::speed_teks);
		unschedule(schedule_selector(Scene4::delay_game));
		detik = 0;
	}
	else if (detik == 3)
		buttonStart->setScale(1);
}


void Scene4::pil_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1400, 780)));
	btn_menu->setScale(0);

}

void Scene4::close_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1600, 780)));
	btn_menu->setScale(1);
}

void Scene4::back_title(Ref* sender)
{

	HomeMenu::btn_sound();
	bg_exit->setScale(1);
	kosong->setScale(1);
	btn_exit_no->setScale(1);
	btn_exit_yes->setScale(1);
	label_quit_no->setScale(1);
	label_quit_yes->setScale(1);

}

void Scene4::config(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, Option::scene(), Color3B(255, 255, 255)));
	})));

}
void Scene4::save_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, SaveGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene4::load_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, LoadGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene4::delay(float dt)
{
	if (detik == 1)
	{
		unschedule(schedule_selector(Scene4::delay));
		buttonStart->setScale(1);
		if (HomeMenu::nilai_teks == 62 || HomeMenu::nilai_teks == 78)
		{
			this->schedule(schedule_selector(Scene4::teksJalan), Option::speed_teks);
		}
		detik = 0;
	}
	detik++;
}
void Scene4::startGame(Ref* sender)
{
	unschedule(schedule_selector(Scene4::teksJalan));
	HomeMenu::btn_sound();
	HomeMenu::nilai_teks++;
	isi_teks();
	teks_1->setOpacity(0);
	i = 0;
	log("Nilai teks = %d", HomeMenu::nilai_teks);
	if (HomeMenu::nilai_teks == 62 || HomeMenu::nilai_teks == 78)
	{
		buttonStart->setScale(0);
		if (HomeMenu::nilai_teks > 61 && HomeMenu::nilai_teks < 78)
			background->setTexture("bg/kafe.jpg");
		else if (HomeMenu::nilai_teks > 77)
			background->setTexture("bg/kafe_2.jpg");
		this->schedule(schedule_selector(Scene4::delay), 1.f);
	}
	else if (HomeMenu::nilai_teks == 169)
	{
		HomeMenu::nilai_teks = 1;
		this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
		{
			Director::getInstance()->replaceScene(TransitionFade::create(3, Scene5::scene(), Color3B(255, 255, 255)));
		})));
	}
	else
		this->schedule(schedule_selector(Scene4::teksJalan), Option::speed_teks);

}

void Scene4::isi_teks()
{
	if (HomeMenu::nilai_teks == 1)
	{
		nama_kosong();
		teks = __String::createWithFormat("Setelah tidur nyenyak semalam, \naku terjaga dengan baik sepanjang jam pelajaran. ")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 2)
	{
		nama_kosong();
		teks = __String::createWithFormat("Jadwal hari ini adalah pengolahan citra dan \ndatabase enterprise .")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 3)
	{
		nama_kosong();
		teks = __String::createWithFormat("Untuk lebih detail mengenai apa yang akan kami pelajari,\naku tidak tahu.Semua penjelasan dosen melesat melewatiku \nbegitu saja.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 4)
	{
		nama_kosong();
		teks = __String::createWithFormat("Meskipun begitu, ini adalah perkembangan yang bagus.\nSetidaknya untuk hari ini, aku tahu mata kuliah apa yang \nsedang aku hadiri.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 5)
	{
		nama_kosong();
		teks = __String::createWithFormat("Setelah dosen kami keluar ruangan, \naku segera menggantungkan tas ke pundakku.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 6)
	{	
		nama_kosong();
		teks = __String::createWithFormat("Hari ini aku ada jadwal kerja lagi.\nBulan ini aku memang sengaja meminta jam kerja \nyang banyak selagi masih awal semester.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 7)
	{
		nama_kosong();
		teks = __String::createWithFormat("Namun sepertinya aku harus berpapasan dengan Anna dan Nana \nterlebih dahulu sebelum bisa keluar kelas.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 8)
	{	
		anna();
		teks = __String::createWithFormat("\"Hai Rei\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 9)
	{	
		rei();
		teks = __String::createWithFormat("\"Hai.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 10)
	{
		nama_kosong();
		teks = __String::createWithFormat("Nana juga menyapaku, tapi hanya dengan \ntersenyum kecil dan mengangguk.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 11)
	{
		rei();
		teks = __String::createWithFormat("\"Hai.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 12)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Aku melihatnya membuka kecil mulutnya, \ntapi sepertinya ia tidak jadi mengatakan apapun.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 13)
	{
		nama_kosong();
		teks = __String::createWithFormat("Oh ya. Apakah Anna sudah ke seseorang mengenai \npekerjaanku?")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 14)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sudah-tidak pun sebenarnya tidak masalah sih. \nAku juga bukannya ingin menyembunyikannya.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 15)
	{
		anna();
		 
		teks = __String::createWithFormat("\"Aku benar-benar salah mengira tentang mata kuliah \npengolahan citra.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));

	}
	else if (HomeMenu::nilai_teks == 16)
	{
		rei();
		teks = __String::createWithFormat("\"Memangnya kenapa?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 17)
	{
		anna();
		teks = __String::createWithFormat("\"Aku kira kita akan belajar editing gambar.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 18)
	{
		rei();
		teks = __String::createWithFormat("\"Seingatku kita sudah belajar editing gambar di beberapa \nsemester sebelum ini.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 19)
	{
		anna();
		teks = __String::createWithFormat("\"Iya, memang, tapi itu di mata kuliah animasi.\nJadi hanya sekilas saja.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 20)
	{
		anna();
		teks = __String::createWithFormat("\"Aku pikir kita akan mendalaminya di mata kuliah ini.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 21)
	{
		rei();
		teks = __String::createWithFormat("\"Oh, begitu. Memangnya, apa yang akan kita pelajari di \nmatkul ini?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 22)
	{
		anna();
		teks = __String::createWithFormat("\"Eh? Kamu sudah lupa? Baru saja tadi pagi dijelaskan.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K6.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 23)
	{
		rei();
		teks = __String::createWithFormat("Lebih parah dari lupa.\nAku memang tidak tahu.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K6.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 24)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dan.. Nana. Berhentilah memasang ekspresi terkejut \npada kebodohanku.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K6.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 25)
	{
		hiden_character();
		anna();
		teks = __String::createWithFormat("\"Mata kuliah pengolahan citra akan mengajari kita tentang \nbagaimana mengubah elemen-elemen dari suatu citra ---\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 26)
	{
		anna();
		teks = __String::createWithFormat("\"Sehingga menghasilkan citra yang sesuai dengan keinginan\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 27)
	{
		rei();
		teks = __String::createWithFormat("\"Kedengarannya rumit.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 28)
	{
		anna();
		teks = __String::createWithFormat("\"Aku tidak yakin apakah kamu paham atau tidak,\ntapi ya! Setidaknya kamu tahu kalau ini rumit.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 29)
	{
		nana();
		teks = __String::createWithFormat("\"Hebatnya, kita nanti jadi tahu bagaimana software-software \nediting gambar yang biasa kita pakai bekerja.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 30)
	{
		anna();
		teks = __String::createWithFormat("\"Ya! Kita bahkan nanti akan membuat sendiri program \nediting gambar dari awal!\"")->getCString();
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
		hiden_character();
		rei();
		teks = __String::createWithFormat("\"Eh?! Serius? Benarkah? Wow!\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 32)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku sangat terkejut. Karena berbagai hal.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 33)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku memang sudah bilang kalau matkul ini terdengar \nrumit.. tapi.. aku tidak menyangka kalau akan serumit ini.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 34)
	{
		anna();
		teks = __String::createWithFormat("\"Kita kesampingkan pengolahan citra, aku tidak menyangka kalau \nkita akan belajar database lagi untuk kesekian kalinya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 35)
	{
		rei();
		teks = __String::createWithFormat("\"Ya, benar juga. Aku juga berpikir begitu tadi.\nSejak dulu, kita sudah banyak belajar database.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 36)
	{
		anna();
		teks = __String::createWithFormat("\"Bagaimana denganmu Nana? Platform database apa yang sudah kamu \npelajari?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 37)
	{
		nana();
		teks = __String::createWithFormat("\"Aku sudah belajar MySQL dan Microsoft Access.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 38)
	{
		rei();
		teks = __String::createWithFormat("\"Sama dengan kami kalau begitu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 39)
	{
		rei();
		teks = __String::createWithFormat("\"Eh? Kayaknya..\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 40)
	{
		anna();
		teks = __String::createWithFormat("\"Oracle?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 41)
	{
		rei();
		teks = __String::createWithFormat("\"Oh ya, kami juga belajar Oracle.\"")->getCString();
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
		nana();
		teks = __String::createWithFormat("\"Belum, aku tahu kalau itu termasuk database yang populer,\ntapi aku belum belajar.\"")->getCString();
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
	else if (HomeMenu::nilai_teks == 43)
	{
		anna();
		teks = __String::createWithFormat("\"Aku rasa kita cukup beruntung Rei. Kampus kita adalah \nmember Oracle Academy, karena itu kita sempat belajar database \nOracle.\"")->getCString();
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
	else if (HomeMenu::nilai_teks == 44)
	{
		rei();
		teks = __String::createWithFormat("\"Kalau begitu kita memang benar-benar sudah belajar banyak sekali \ndatabase. Jadi, apa yang sebenarnya akan kita pelajari nanti?\"")->getCString();
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
	else if (HomeMenu::nilai_teks == 45)
	{
		nana();
		teks = __String::createWithFormat("\"Kita akan belajar Microsoft SQL Server. Database dari Microsoft yang \nbiasa digunakan untuk memenuhi kebutuhan perusahaan atau organisasi \nbesar.\"")->getCString();
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
	else if (HomeMenu::nilai_teks == 46)
	{
		anna();
		teks = __String::createWithFormat("\"Intinya tidak ada yang perlu kamu takuti Rei, kita pasti \nbisa mempelajarinya dengan baik karena kita sudah sering \nbelajar database.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 47)
	{
		rei();
		teks = __String::createWithFormat("\"Aku harap begitu..Oh gawat!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 48)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku malah mengobrol dengan mereka,\nbukannya segera pergi ke kafe.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 49)
	{
		nana();
		teks = __String::createWithFormat("\"Ada apa?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 50)
	{
		rei();
		teks = __String::createWithFormat("\"Ah.. tidak.. aku harus.. segera pergi.\"")->getCString();
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
		nana();
		teks = __String::createWithFormat("\"Oh, begitu. Kamu memang suka pulang cepat ya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 52)
	{
		rei();
		teks = __String::createWithFormat("\"Eh?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 53)
	{
		nana();
		teks = __String::createWithFormat("\"?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 54)
	{
		rei();
		teks = __String::createWithFormat("\"Iya, begitulah. Hahaha..\"")->getCString();
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
	else if (HomeMenu::nilai_teks == 55)
	{
		nama_kosong();
		teks = __String::createWithFormat("Loh. Jadi Anna belum bilang ke Nana mengenai pekerjaanku.")->getCString();
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
	else if (HomeMenu::nilai_teks == 56)
	{
		anna();
		teks = __String::createWithFormat("\"Beginilah Rei, anak yang sangat mencintai rumah.\"")->getCString();
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
	else if (HomeMenu::nilai_teks == 57)
	{
		anna();
		teks = __String::createWithFormat("\"Tidak usah pedulikan dia.\nKita jalan-jalan lagi saja keliling kampus!\"")->getCString();
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
	else if (HomeMenu::nilai_teks == 58)
	{
		nana();
		teks = __String::createWithFormat("\"Oke.\"")->getCString();
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
		rei();
		teks = __String::createWithFormat("\"Baguslah. Jangan mengajakku lagi ya!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 60)
	{
		anna();
		teks = __String::createWithFormat("\"Tidak akan! Buat apa juga! Sudah sana pergi.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 61)
	{
		hiden_character();
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
		nama_kosong();
		teks = __String::createWithFormat("Aku sedikit jengkel mendengarnya,\ntapi aku memutuskan untuk bergegas meninggalkan kelas.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 62)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ketika berjalan dari halte bus menuju kafe,\naku melihat mobil berwana biru yang tidak asing terparkir \ndi dekat kafe.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 63)
	{
		nama_kosong();
		teks = __String::createWithFormat("Itu adalah mobil mas Karya.\nYang berarti dia sedang ada di dalam kafe.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 64)
	{
		nama_kosong();
		teks = __String::createWithFormat("Setalah masuk, aku segera menemukannya duduk di salah satu \nmeja dengan seseorang.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 65)
	{
		nama_kosong();
		teks = __String::createWithFormat("Mereka terlihat sedang mengobrol dengan asik,\nmembuatku mengurungkan niat untuk menyapanya.\nSepertinya urusan bisnis.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 66)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku memutuskan untuk segera memulai kerja, \nmenggantikan karyawan shift pagi yang wajahnya terlihat \ngembira melihat kedatanganku.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 67)
	{
		nama_kosong();
		teks = __String::createWithFormat("Namun sebelum meninggalkan kafe,\nteman kerjaku menyuruhku untuk menempelkan poster di \ndepan pintu kafe.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 68)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tanpa banyak bertanya, aku kemudian mencari berbagai alat \nyang diperlukan dan segera keluar untuk menempel poster \ntersebut.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 69)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku melihat kalau mas Karya masih sibuk \nmengobrol sejak tadi. Entah apa topiknya.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 70)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ketika hendak memasang poster tersebut,\nentah kenapa aku baru penasaran mengenai isinya.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 71)
	{
		rei();
		teks = __String::createWithFormat("\"Open Recruitment..\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 72)
	{
		rei();
		teks = __String::createWithFormat("\"Ha!?\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 73)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku tidak pernah mendengar kalau kafe ini \nmembutuhkan tenaga kerja lagi.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 74)
	{
		nama_kosong();
		teks = __String::createWithFormat("Oh ya. Aku baru teringat kalau aku baru saja masuk kemarin \nsetelah libur sebulan. Benar saja kalau aku tidak tahu mengenai hal ini.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 75)
	{
		nama_kosong();
		teks = __String::createWithFormat("Selesai menempel poster lowongan pekerjaan,\naku kembali ke dalam kafe dan mulai bekerja seperti biasanya.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 76)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dari belakang counter, aku melihat kalau perbincangan mas Karya \nsudah berakhir dengan keluarnya sang lawan bicara dari kafe.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 77)
	{
		nama_kosong();
		teks = __String::createWithFormat("Namun mas Karya masih terlihat sibuk di depan \nlaptopnya.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 78)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dari dalam kafe, aku melihat cahaya matahari mulai berhenti \nmenerangi jalan di luar.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 79)
	{
		nama_kosong();
		teks = __String::createWithFormat("Kurang lebih setengah jam lagi shift ku hari ini \nselesai.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 80)
	{
		nama_kosong();
		teks = __String::createWithFormat("Mas Karya masih saja berada di mejanya sejak tadi.\nSepertinya hari ini dia mengunjungi kafe bukan untuk memantau \nkondisi kafe.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 81)
	{
		rei();
		teks = __String::createWithFormat("\"Selamat data-\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 82)
	{
		rei();
		teks = __String::createWithFormat("\"Ah..\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 83)
	{
		nama_kosong();
		teks = __String::createWithFormat("Pelanggan yang baru saja masuk itu tersenyum dan melambaikan \ntangan pada salah satu karyawan.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 84)
	{
		nama_kosong();
		teks = __String::createWithFormat("Karena karyawan tersebut belum pernah mendapatkan perlakuan \nseperti itu sebelumnya, pelanggan tersebut mencuri perhatian lebih \nsang pemilik kafe.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 85)
	{
		nama_kosong();
		teks = __String::createWithFormat("Anna melangkah dengan pasti ke arahku, \nmenuju counter, kemudian duduk.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		 
	}
	else if (HomeMenu::nilai_teks == 86)
	{
		anna();
		teks = __String::createWithFormat("\"Hai! Aku rasa masih sempat sebelum waktu kerjamu berakhir.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 87)
	{
		nama_kosong();
		teks = __String::createWithFormat("\"Ya.. aku rasa begitu. Mungkin untuk hari ini aku pulang lebih awal saja.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 88)
	{
		anna();
		teks = __String::createWithFormat("\"Ayolah, jangan begitu, ingatlah bagaimana kamu harus \nbersikap pada pelanggan.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 89)
	{
		rei();
		teks = __String::createWithFormat("\"Baik Nona, maafkan kelancangan saya. \nApa yang sebaiknya saya sajikan untuk Nona hari ini?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 90)
	{
		anna();
		teks = __String::createWithFormat("\"Wah.. keren sekali kalimatmu. Serius. Aku harap tadi aku rekam.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
	}
	else if (HomeMenu::nilai_teks == 91)
	{
		rei();
		teks = __String::createWithFormat("\"Sayang sekali kalau begitu.\nKamu melewatkan kesempatan sekali seumur hidupmu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		 
	}
	else if (HomeMenu::nilai_teks == 92)
	{
		anna();
		teks = __String::createWithFormat("\"Apa rekomendasi untuk hari ini?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
	}
	else if (HomeMenu::nilai_teks == 93)
	{
		rei();
		teks = __String::createWithFormat("\"Eh? Aku kira kamu akan memesan menu yang kemarin saja.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
	}
	else if (HomeMenu::nilai_teks == 94)
	{
		anna();
		teks = __String::createWithFormat("\"Tidak ada rekomendasi lain?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
	}
	else if (HomeMenu::nilai_teks == 95)
	{
		rei();
		teks = __String::createWithFormat("\"Menu kafe ini tidak berubah setiap harinya Anna,\njadi aku rasa tidak.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 96)
	{
		anna();
		teks = __String::createWithFormat("\"Hmm.. aku tidak ingin memesan menu yang sama dua kali berturut-turut.\nAyolah, sarankan aku sesuatu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
	}
	else if (HomeMenu::nilai_teks == 97)
	{
		rei();
		teks = __String::createWithFormat("\"Meskipun kamu bilang begitu,\naku tidak yakin apakah kamu akan suka atau tidak.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 98)
	{
		anna();
		teks = __String::createWithFormat("\"Baiklah, aku akan pilih sendiri.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 99)
	{
		anna();
		teks = __String::createWithFormat("\"Mungkin Americano.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
	}
	else if (HomeMenu::nilai_teks == 100)
	{
		rei();
		teks = __String::createWithFormat("\"Aku sudah bilang kemarin kalau espresso itu rasanya aneh.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
	}
	if (HomeMenu::nilai_teks == 101)
	{
		anna();
		teks = __String::createWithFormat("\"Bagaimana kalau Avocado Coffee?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K6.png");
	}
	if (HomeMenu::nilai_teks == 102)
	{
		rei();
		teks = __String::createWithFormat("\"Serius? Harganya terlalu mahal,\naku juga tidak yakin kamu suka dengan rasanya atau tidak.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K6.png");
	}
	if (HomeMenu::nilai_teks == 103)
	{
		anna();
		teks = __String::createWithFormat("\"Hei...\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
	}
	if (HomeMenu::nilai_teks == 104)
	{
		rei();
		teks = __String::createWithFormat("\"Ya?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
	}
	if (HomeMenu::nilai_teks == 105)
	{
		anna();
		teks = __String::createWithFormat("\"Kamu itu.. katanya ingin aku pilih sendiri,\ntapi kamu protes terus dengan pilihanku!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
	}
	if (HomeMenu::nilai_teks == 106)
	{
		anna();
		teks = __String::createWithFormat("\"Jangan bilang selama kamu kerja kamu selalu begini.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
	}
	if (HomeMenu::nilai_teks == 107)
	{
		rei();
		teks = __String::createWithFormat("\"Ha? Mana mungkin. Aku sih tidak peduli dengan apa yang dipilih \npelanggan lain. Tapi untukmu, aku ingin yang terbaik.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 108)
	{
		anna();
		teks = __String::createWithFormat("\"...\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 109)
	{
		rei();
		teks = __String::createWithFormat("\"Ada apa?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 110)
	{
		anna();
		teks = __String::createWithFormat("\"Ngga.. kayaknya, memang lebih baik kamu saja yang pilih.\nLagipula, aku juga suka pilihanmu kemarin.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 111)
	{
		rei();
		teks = __String::createWithFormat("\"Kalau begitu yang kemarin saja..\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 112)
	{
		anna();
		teks = __String::createWithFormat("\"Selain yang kemarin! Aku sudah bilang aku tidak mau yang kemarin!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
	}
	if (HomeMenu::nilai_teks == 113)
	{
		rei();
		teks = __String::createWithFormat("\"Bagaimana kalau selain kopi?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
	}
	if (HomeMenu::nilai_teks == 114)
	{
		anna();
		teks = __String::createWithFormat("\"Benar juga, aku baru sadar kalau aku bisa pesan minuman selain kopi.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
	}
	if (HomeMenu::nilai_teks == 115)
	{
		rei();
		teks = __String::createWithFormat("\"Jadi? Siapa yang pilih?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 116)
	{
		anna();
		teks = __String::createWithFormat("\"Kamu saja. Tapi jangan kopi.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 117)
	{
		rei();
		teks = __String::createWithFormat("\"Jangan salahkan aku kalau kamu tidak suka rasanya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 118)
	{
		anna();
		teks = __String::createWithFormat("\"Iya, iya, terserah.\nKalau aku tidak suka, kamu yang bayarkan?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 119)
	{
		rei();
		teks = __String::createWithFormat("\"...\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 120)
	{
		rei();
		teks = __String::createWithFormat("\"Ngomong-ngomong, kamu pulang larut sekali.\nSelama itukah jalan-jalan sama Nana?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 121)
	{
		anna();
		teks = __String::createWithFormat("\"Tidak mungkin lah, kakiku sudah bengkok kalau aku \nberjalan selama itu. Aku tadi ke himpunan mahasiswa sebentar.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 122)
	{
		rei();
		teks = __String::createWithFormat("\"Oh.. begitu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 123)
	{
		rei();
		teks = __String::createWithFormat("\"Oh ya, kamu juga ternyata belum bilang ke Nana ya \nkalau aku kerja di kafe.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 124)
	{
		anna();
		teks = __String::createWithFormat("\"...\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
	}
	if (HomeMenu::nilai_teks == 125)
	{
		anna();
		teks = __String::createWithFormat("\"Soalnya, kamu sepertinya tidak mau orang lain \ntahu kalau kamu kerja di sini.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 126)
	{
		anna();
		teks = __String::createWithFormat("\"Kemarin waktu aku masuk ke sini saja, ekspresimu seperti melihat hantu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 127)
	{
		rei();
		teks = __String::createWithFormat("\"Benarkah? Aku tidak sadar.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 128)
	{
		rei();
		teks = __String::createWithFormat("\"Tapi sebenarnya, itu terserah kamu sih ingin cerita \npada orang lain atau tidak.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 129)
	{
		anna();
		teks = __String::createWithFormat("\"Kamu sendiri?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 130)
	{
		rei();
		teks = __String::createWithFormat("\"Mungkin sebaiknya tidak. Kalau saja aku tahu ilmu hipnotis,\nmungkin sudah aku gunakan padamu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
	}
	if (HomeMenu::nilai_teks == 131)
	{
		anna();
		teks = __String::createWithFormat("\"Kalau begitu aku tidak akan cerita.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 132)
	{
		rei();
		teks = __String::createWithFormat("\"Eh? Benarkah? Yah, tapi.. kamu tidak usah terlalu \nmerahasiakannya sih.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 133)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Aku melihat kalau minumannya Anna sudah jadi,\nkemudian segera membawakannya.")->getCString();
		teks_1->setString(teks);
	}
	if (HomeMenu::nilai_teks == 134)
	{
		rei();
		teks = __String::createWithFormat("\"Silahkan Babyccino-nya.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 135)
	{
		anna();
		teks = __String::createWithFormat("\"Bhu-hahaha. Apa aku salah dengar? Baby?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
	}
	if (HomeMenu::nilai_teks == 136)
	{
		rei();
		teks = __String::createWithFormat("\"Ya, namanya babyccino. Mungkin karena bahan utamanya susu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 137)
	{
		anna();
		teks = __String::createWithFormat("\"Imut sekali namany-\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 138)
	{
		anna();
		teks = __String::createWithFormat("\"Ah! Kamu pasti memilih ini karena namanya imut kan? \nJadi cocok untukku.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
	}
	if (HomeMenu::nilai_teks == 139)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Tidak. Menurutku bayi itu merepotkan. Bukan imut.")->getCString();
		teks_1->setString(teks);
	}
	if (HomeMenu::nilai_teks == 140)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku melihat Anna mengangkat cangkir dengan gugup.\nGugup? Kenapa?")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 141)
	{
		nama_kosong();
		teks = __String::createWithFormat("Mungkin karena setelah banyak berdebat sebelumnya,\nakan konyol kalau akhirnya dia tidak suka.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 142)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku lega ketika melihatnya tersenyum.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		 
	}
	if (HomeMenu::nilai_teks == 143)
	{
		anna();
		teks = __String::createWithFormat("\"Tebakanmu hebat ya. Padahal aku tidak pernah bilang padamu \nmengenai rasa seperti apa yang aku suka.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 144)
	{
		rei();
		teks = __String::createWithFormat("\"Aku harap aku tidak menghabiskan keberuntungan hidupku \nhanya untuk memilihkanmu kopi.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 145)
	{
		rei();
		teks = __String::createWithFormat("\"Aku.. ada kerjaan lain yang harus aku lakukan.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 146)
	{
		anna();
		teks = __String::createWithFormat("\"Okee, semangat! Sebentar lagi kan jam pulangmu?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 147)
	{
		anna();
		teks = __String::createWithFormat("\"Terimakasih baby.. apapun nama minuman ini.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 148)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Aku harap maksudnya bukan \n'terimakasih kopi minuman gratisnya.'")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 149)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku menginggalkan Anna untuk membereskan meja-meja yang \nbaru saja dipakai pelanggan lain, kemudian ke belakang untuk mencuci.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 150)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dari belakang, aku bisa melihat Pak Karya menghampiri Anna.\nAtau mungkin ia mau ke counter untuk melakukan pengecekan")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 151)
	{
		nama_kosong();
		teks = __String::createWithFormat("Selesai mencuci, aku menuju ke ruang belakang untuk mengambil \ntas dan bersiap pulang. Aku juga mengecek jadwal shift untuk memastikan \nkalau besok aku juga masuk.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 152)
	{
		nama_kosong();
		teks = __String::createWithFormat("Biasanya aku keluar kafe lewat pintu samping di ruangan ini.\nNamun untuk kali ini karena ada Anna,\nkurasa aku akan lewat pintu depan.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 153)
	{
		nama_kosong();
		teks = __String::createWithFormat("Kembali dari bagian belakang kafe,\naku melihat Anna menungguku di dekat pintu.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 154)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ia melambai-lambaikan tangannya begitu melihatku.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 155)
	{
		anna();
		teks = __String::createWithFormat("\"Ayo Rei! Kita pulang!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 156)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Aku sangat berharap ia bisa berhenti melakukan \nhal-hal yang menarik perhatian orang seperti itu.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 157)
	{
		nama_kosong();
		teks = __String::createWithFormat("Mas Karya tersenyum melihatku.\nAku membalas senyumannya sembari sedikit membungkukkan badan \nuntuk berpamitan pulang.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 158)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku kemudian menyusul Anna yang sudah keluar dari kafe.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 159)
	{
		anna();
		teks = __String::createWithFormat("\"Mau aku antar?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
	}
	if (HomeMenu::nilai_teks == 160)
	{
		rei();
		teks = __String::createWithFormat("\"Tidak, tidak perlu. Haltenya cuma di situ.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 161)
	{
		anna();
		teks = __String::createWithFormat("\"Baiklah, sampai jumpa besok! Hati-hati ya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 162)
	{
		rei();
		teks = __String::createWithFormat("\"Ya. Kamu juga.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 163)
	{
		nama_kosong();
		teks = __String::createWithFormat("Baru beberapa langkah, Anna sudah berteriak kepadaku lagi.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 164)
	{
		anna();
		teks = __String::createWithFormat("\"Jangan main game sampai pagi!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 165)
	{
		rei();
		teks = __String::createWithFormat("\"Bukan urusanmu!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	if (HomeMenu::nilai_teks == 166)
	{
		anna();
		teks = __String::createWithFormat("\"Aku ketua kelasmu!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
	}
	if (HomeMenu::nilai_teks == 167)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Anna masih saja membalas perkataanku meskipun kami sudah \ncukup jauh. Ia juga melambai-lambaikan tangannya lagi.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 168)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku hanya bisa berharap tidak banyak orang yang peduli pada kegaduhan \nkami.")->getCString();
		teks_1->setString(teks);
	}

}


void Scene4::quit_yes(Ref* sender)
{
	HomeMenu::btn_sound();
	HomeMenu::nilai_logo = true;

	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		Director::getInstance()->replaceScene(TransitionFade::create(3, HomeMenu::scene(), Color3B(255, 255, 255)));
	})));
} //button tekan exit yes

void Scene4::quit_no(Ref* sender)
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
void Scene4::teksJalan(float dt)
{

	teks_satu();
}

void Scene4::teks_satu()
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
		unschedule(schedule_selector(Scene4::teksJalan));
	}
}

void Scene4::rei()
{
	auto teks_nama = __String::createWithFormat("Rei")->getCString();
	nama->setString(teks_nama);
}
void Scene4::anna()
{
	auto teks_nama = __String::createWithFormat("Anna")->getCString();
	nama->setString(teks_nama);
}
void Scene4::nana()
{
	auto teks_nama = __String::createWithFormat("Nana")->getCString();
	nama->setString(teks_nama);
}
void Scene4::nama_kosong()
{
	auto teks_nama = __String::createWithFormat(" ")->getCString();
	nama->setString(teks_nama);
}
void Scene4::nama_titik()
{
	auto teks_nama = __String::createWithFormat("......")->getCString();
	nama->setString(teks_nama);
}
void Scene4::wali()
{
	auto teks_nama = __String::createWithFormat("Wali Kelas")->getCString();
	nama->setString(teks_nama);
}


