#include "Scene5a.h"
#include "Scene6.h"
#include "Option.h"
#include "HomeMenu.h"
#include "SaveGame.h"
#include "LoadGame.h"
#include "MiniGame3.h"

USING_NS_CC;



Scene* Scene5a::scene()
{
	return Scene5a::create();
}

bool Scene5a::init()
{
	if (!Scene::init())
	{
		return false;
	}
	bgm->playBackgroundMusic("music/5a.mp3", true);
	HomeMenu::game = 10;
	

	//background//
	background->setPosition(Vec2(0, 0));
	background->setAnchorPoint(Vec2(0, 0));
	this->addChild(background);
	/////////////

	this->schedule(schedule_selector(Scene5a::delay_game), 1);

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
	btn_load->addClickEventListener(CC_CALLBACK_1(Scene5a::load_game, this));
	btn_save->addClickEventListener(CC_CALLBACK_1(Scene5a::save_game, this));
	btn_config->addClickEventListener(CC_CALLBACK_1(Scene5a::config, this));
	btn_exit_no->addClickEventListener(CC_CALLBACK_1(Scene5a::quit_no, this));
	btn_exit_yes->addClickEventListener(CC_CALLBACK_1(Scene5a::quit_yes, this));
	btn_tittle->addClickEventListener(CC_CALLBACK_1(Scene5a::back_title, this));
	btn_close->addClickEventListener(CC_CALLBACK_1(Scene5a::close_menu, this));
	buttonStart->addClickEventListener(CC_CALLBACK_1(Scene5a::startGame, this));
	btn_menu->addClickEventListener(CC_CALLBACK_1(Scene5a::pil_menu, this));
	///////////////////////////
	//gambar karakter//
	anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	hiden_character();
	this->addChild(nana_sprite);
	this->addChild(anna_sprite);
	//////////////////
	//background//
	if (HomeMenu::nilai_teks > 10 && HomeMenu::nilai_teks < 33)
		background->setTexture("bg/lab_jaringan.jpg");
	else if (HomeMenu::nilai_teks > 32 && HomeMenu::nilai_teks < 54)
		background->setTexture("bg/kafe.jpg");
	else if (HomeMenu::nilai_teks > 53 && HomeMenu::nilai_teks < 90)
		background->setTexture("bg/kamar.jpg");
	else if (HomeMenu::nilai_teks > 89 && HomeMenu::nilai_teks < 115)
		background->setTexture("bg/lingkungan_kampus_1.jpg");
	else if (HomeMenu::nilai_teks > 114 && HomeMenu::nilai_teks < 134)
		background->setTexture("bg/lab_database.jpg");
	else if (HomeMenu::nilai_teks > 133 )
		background->setTexture("bg/gazebo.jpg");
	/////////////
	return true;
}
void Scene5a::hiden_character()
{
	anna_sprite->setScale(0);
	nana_sprite->setScale(0);
}
void Scene5a::delay_game(float dt)
{
	detik++;

	if (detik == 4)
	{
		isi_teks();
		this->schedule(schedule_selector(Scene5a::teksJalan), Option::speed_teks);
		unschedule(schedule_selector(Scene5a::delay_game));
		detik = 0;
	}
	else if (detik == 3)
		buttonStart->setScale(1);
}


void Scene5a::pil_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1400, 780)));
	btn_menu->setScale(0);

}

void Scene5a::close_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1600, 780)));
	btn_menu->setScale(1);
}

void Scene5a::back_title(Ref* sender)
{

	HomeMenu::btn_sound();
	bg_exit->setScale(1);
	kosong->setScale(1);
	btn_exit_no->setScale(1);
	btn_exit_yes->setScale(1);
	label_quit_no->setScale(1);
	label_quit_yes->setScale(1);

}

void Scene5a::config(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, Option::scene(), Color3B(255, 255, 255)));
	})));

}
void Scene5a::save_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, SaveGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene5a::load_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, LoadGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene5a::delay(float dt)
{
	if (detik == 1)
	{
		unschedule(schedule_selector(Scene5a::delay));
		buttonStart->setScale(1);
		if (HomeMenu::nilai_teks == 11 || HomeMenu::nilai_teks == 33 || HomeMenu::nilai_teks == 54 || HomeMenu::nilai_teks == 90 || HomeMenu::nilai_teks == 115 || HomeMenu::nilai_teks == 134)
		{
			this->schedule(schedule_selector(Scene5a::teksJalan), Option::speed_teks);
		}
		detik = 0;
	}
	detik++;
}
void Scene5a::startGame(Ref* sender)
{
	unschedule(schedule_selector(Scene5a::teksJalan));
	HomeMenu::btn_sound();
	HomeMenu::nilai_teks++;
	isi_teks();
	teks_1->setOpacity(0);
	i = 0;
	log("Nilai teks = %d", HomeMenu::nilai_teks);
	if (HomeMenu::nilai_teks == 11 || HomeMenu::nilai_teks == 33 || HomeMenu::nilai_teks == 54 || HomeMenu::nilai_teks == 90 || HomeMenu::nilai_teks == 115 || HomeMenu::nilai_teks == 134)
	{
		buttonStart->setScale(0);
		if (HomeMenu::nilai_teks > 10 && HomeMenu::nilai_teks < 33)
			background->setTexture("bg/lab_jaringan.jpg");
		else if (HomeMenu::nilai_teks > 32 && HomeMenu::nilai_teks < 54)
			background->setTexture("bg/kafe.jpg");
		else if (HomeMenu::nilai_teks > 53 && HomeMenu::nilai_teks < 90)
			background->setTexture("bg/kamar.jpg");
		else if (HomeMenu::nilai_teks > 89 && HomeMenu::nilai_teks < 115)
			background->setTexture("bg/lingkungan_kampus_1.jpg");
		else if (HomeMenu::nilai_teks > 114 && HomeMenu::nilai_teks < 134)
			background->setTexture("bg/lab_database.jpg");
		else if (HomeMenu::nilai_teks > 133)
			background->setTexture("bg/gazebo.jpg");
		this->schedule(schedule_selector(Scene5a::delay), 1.f);
	}
	else if (HomeMenu::nilai_teks == 119)
	{
		this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
		{
		Director::getInstance()->replaceScene(TransitionFade::create(3, MiniGame3::createScene(), Color3B(255, 255, 255)));
		})));
	}
	else if (HomeMenu::nilai_teks == 194)
	{
		HomeMenu::nilai_teks = 1;
		this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
		{
			Director::getInstance()->replaceScene(TransitionFade::create(3, Scene6::scene(), Color3B(255, 255, 255)));
		})));
	}
	else
		this->schedule(schedule_selector(Scene5a::teksJalan), Option::speed_teks);

}

void Scene5a::isi_teks()
{
	if (HomeMenu::nilai_teks == 1)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku merebahkan tubuhku di kasur dan menghela nafas panjang.\nNafas lega. Keputusan telah aku buat.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 2)
	{
		nama_kosong();
		teks = __String::createWithFormat("Setelah Nana berkata seperti itu, aku tidak tega kalau \ntetap menolaknya. Meskipun sebenarnya kalau diingat kembali,\nakulah yang membuat Nana mengatakan hal seperti itu.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 3)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku harap nantinya aku tidak menyesal karena telah menentukan \narus hidupku sendiri untuk pertama kalinya.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 4)
	{
		nama_kosong();
		teks = __String::createWithFormat("Atau lebih baik aku beranggapan kalau aku hanya mengikuti \narus yang Nana buat.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 5)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku bangkit dari tempat tidurku,\nkemudian mengeluarkan kamera yang Nana pinjamkan kepadaku.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 6)
	{	
		nama_kosong();
		teks = __String::createWithFormat("Dia, benar-benar bersemangat untuk memulai hal ini.\nAku tidak berani membayangkan betapa kecewanya Nana kalau aku \nmengatakan 'tidak'.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 7)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sebelum memulai rekaman pertamaku,\naku berselancar di internet untuk melakukan survei.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 8)
	{	
		nama_kosong();
		teks = __String::createWithFormat("Tentunya, penonton akan lebih tertarik apabila aku \nmemainkan game baru atau yang sedang trend.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 9)
	{	
		nama_kosong();
		teks = __String::createWithFormat("Namun, aku harus mencari tahu genre apa yang paling disukai \npenonton.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 10)
	{
		nama_kosong();
		teks = __String::createWithFormat("Selang beberapa menit, setelah mantap dengan pilihanku,\naku mulai menyalakan kamera.")->getCString();
		 
	}
	else if (HomeMenu::nilai_teks == 11)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sepulang sekolah, aku menyerahkan memory card berisi \nrekaman kamera dan gameplayku pada Nana.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 12)
	{
		anna();
		teks = __String::createWithFormat("\"Wah.. aku tidak meyangka kamu akan langsung melakukannya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 13)
	{
		rei();
		teks = __String::createWithFormat("\"Sejujurnya aku sendiri juga tidak menyangkanya.\nTapi Nana terlalu bersemangat sehingga aku langsung \nmelakukannya saja.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 14)
	{
		nana();
		teks = __String::createWithFormat("\" Terimakasih Rei.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 15)
	{
		anna();
		teks = __String::createWithFormat("\"Aku jadi ingin segera menonton videonya!\nAku penasaran seperti apa Rei waktu bermain game.\"")->getCString();
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
		rei();
		teks = __String::createWithFormat("\"Hei, suaramu terlalu keras,\naku tidak ingin hal ini diketahui banyak orang.\"")->getCString();
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
		anna();
		teks = __String::createWithFormat("\"Rei memang penuh rahasia.\"")->getCString();
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
	else if (HomeMenu::nilai_teks == 18)
	{
		nana();
		teks = __String::createWithFormat("\"Selama ini aku memang tidak pernah melihatnya sih,\ntapi Rei memang tidak pernah main game di kampus ya?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 19)
	{
		rei();
		teks = __String::createWithFormat("\"Ya, ada banyak alasan kenapa aku tidak melakukannya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 20)
	{
		anna();
		teks = __String::createWithFormat("\"Kenapa? Aku tidak pernah tahu alasanmu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 21)
	{
		rei();
		teks = __String::createWithFormat("\"Cukup banyak,\nsalah satunya aku tidak ingin dikelilingi orang.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 22)
	{
		rei();
		teks = __String::createWithFormat("\"Bermain game di kampus akan membuat banyak orang lain tertarik,\nsehingga nantinya aku malah tidak bisa fokus pada gamenya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 23)
	{
		anna();
		teks = __String::createWithFormat("\"Intinya kamu tidak ingin berinteraksi dengan orang lain.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 24)
	{
		rei();
		teks = __String::createWithFormat("\"Ya, ada alasan lain juga sih.\nTapi hal itu tidak perlu dibahas.\"")->getCString();
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
	else if (HomeMenu::nilai_teks == 25)
	{
		rei();
		teks = __String::createWithFormat("\"Baiklah, aku akan segera pulang, sampai jumpa besok.\"")->getCString();
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
	else if (HomeMenu::nilai_teks == 26)
	{
		rei();
		teks = __String::createWithFormat("\"Oh ya, aku harap, kamu tidak terlalu terganggu \ndengan wajahku.\"")->getCString();
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
	else if (HomeMenu::nilai_teks == 27)
	{
		nana();
		teks = __String::createWithFormat("\"Eh? Memangnya kenapa?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 28)
	{
		anna();
		teks = __String::createWithFormat("\"Kamu tidak rekaman setelah bangun tidur kan?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
		 
	}
	else if (HomeMenu::nilai_teks == 29)
	{
		hiden_character();
		rei();
		teks = __String::createWithFormat("\"Mana mungkin.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 30)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sebelum keluar kelas, aku sejenak menatap Anna.\nApakah hari ini juga shiftnya?")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 31)
	{
		nama_kosong();
		teks = __String::createWithFormat("Anna ternyata juga menatapku, tapi aku tidak tahu \napakah maksudnya 'iya' atau 'tidak'.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 32)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sebelum mengundang kecurigaan orang lain,\naku segera keluar dan berangkat menuju kafe.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 33)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sepertinya proses penggabungan toko sebelah dengan kafe masih \nerlangsung lama. Namun aku sudah terbiasa dengan kegaduhan ini \ndan segera masuk ke dalam kafe..")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 34)
	{
		rei();
		teks = __String::createWithFormat("\"Jadi kamu juga ada shift hari ini.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 35)
	{
		anna();
		teks = __String::createWithFormat("\"Halo Rei. Aku ingin bilang padamu tapi rasanya sulit.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 36)
	{
		rei();
		teks = __String::createWithFormat("\"Iya, aku tahu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 37)
	{
		anna();
		teks = __String::createWithFormat("\"Bagaimana kalau lain kali kita berangkat bersama?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A2.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 38)
	{
		rei();
		teks = __String::createWithFormat("\"Aku rasa hal itu tidak mungkin.\nApa kamu tidak keberatan kalau dilihat orang lain?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 39)
	{
		rei();
		teks = __String::createWithFormat("\"Mereka pasti kemudian akan banyak bertanya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 40)
	{
		anna();
		teks = __String::createWithFormat("\"Aku tidak keberatan sih,\ntapi sepertinya memang tidak mungkin ya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 41)
	{
		rei();
		teks = __String::createWithFormat("\"Ya, begitulah. Tidak usah khawatirkan aku.\nAku juga biasanya naik bus ke sini.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 42)
	{
		anna();
		teks = __String::createWithFormat("\"Baiklah kalau begitu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 43)
	{
		anna();
		teks = __String::createWithFormat("\"Jadi, bagaimana rasanya merekam diri sendiri.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 44)
	{
		rei();
		teks = __String::createWithFormat("\"Beberapa menit pertama terasa sangat tidak nyaman.\nItu salahku sendiri sih, aku terlalu memikirkan banyak hal.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 45)
	{
		rei();
		teks = __String::createWithFormat("\"Seperti, apa nanti penonton akan suka, sampai hal-hal konyol \nseperti bagaimana perasaan Nana ketika mengedit rekamanku.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 46)
	{
		anna();
		teks = __String::createWithFormat("\"Maksudmu?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A2.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 47)
	{
		rei();
		teks = __String::createWithFormat("\"Mengedit rekamanku berarti ia terpaksa terus melihat wajahku dalam \nwaktu yang lama kan.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A2.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 48)
	{
		anna();
		teks = __String::createWithFormat("\"Aku rasa, Nana tidak akan mempermasalahkan hal itu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 49)
	{
		rei();
		teks = __String::createWithFormat("\"Aku harap begitu. Dia harusnya akan terbiasa nantinya.\nAku juga nanti akan terbiasa pada kamera.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 50)
	{
		rei();
		teks = __String::createWithFormat("\"Bahkan, aku sudah melupakan adanya kamera di depanku setelah \nbeberapa menit selanjutnya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 51)
	{
		anna();
		teks = __String::createWithFormat("\"Membicarakan hal ini semakin membuatku tidak sabar menonton \nvideonya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 52)
	{
		hiden_character();
		rei();
		teks = __String::createWithFormat("\"Oh ya, aku baru sadar kalau Nana tidak bilang kapan \ntepatnya dia akan upload.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 53)
	{
		nama_kosong();
		teks = __String::createWithFormat("Kedatangan seorang pelanggan memutus obrolan kami \ndan kami berdua tidak banyak mengobrol setelahnya")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 54)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sesampainya di rumah,\naku baru menyadari kalau Nana mengirimkan pesan")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 55)
	{
		nana();
		teks = __String::createWithFormat("'Rei, kamu terlalu menikmati gamemu.'")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 56)
	{
		nama_kosong();
		teks = __String::createWithFormat("Di bawah pesan tersebut ia mengirimkan stiker \nberwajah kesal.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 57)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku tertawa kecil.\nTernyata Nana menggunakan stiker di antara pesannya.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 58)
	{
		rei();
		teks = __String::createWithFormat("'Apa maksudmu? Bukannya hal itu bagus?' \nAku membalas pesannya.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 59)
	{
		rei();
		teks = __String::createWithFormat("'Oh ya maaf baru membalas pesanmu, aku tadi sedang ada urusan.' \nAku segera mengirimkan pesan tambahan.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 60)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku memang berniat menunggu pesan balasannya,\ntapi ternyata Nana membalas dengan cepat.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 61)
	{
		nana();
		teks = __String::createWithFormat("'Yang benar saja, kamu nyaris tidak berkata apa-apa'.\nSekarang ia menambahkan stiker berwajah marah.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 62)
	{
		rei();
		teks = __String::createWithFormat("Aku terdiam dan berpikir sejenak, lalu kemudian membalas.\n'Maaf sekali, kamu benar, aku terlalu menikmati gameku.'")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 63)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sepertinya tahap 'lupa kalau ada kamera' \ntidak selalu berarti baik.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 64)
	{
		nana();
		teks = __String::createWithFormat("Lagi-lagi Nana membalas dengan cepat.\n'Tapi aku akan berusaha membuatnya tetap menarik!'.\nTentunya, dengan stiker yang penuh semangat.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 65)
	{
		rei();
		teks = __String::createWithFormat("'Terimakasih, aku akan berusaha lebih banyak berbicara nanti.'")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 66)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku pikir itu adalah akhir dari tukar pesan kami,\ntapi ternyata tidak.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 67)
	{
		nana();
		teks = __String::createWithFormat("'Oh ya, Rei ternyata memiliki banyak ekspresi lucu.'.\nTulisnya sambil menambahkan stiker tertawa.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 68)
	{
		nama_kosong();
		teks = __String::createWithFormat("Di titik ini aku bingung harus membalas apa.\nAku juga tidak menyangka ia akan berbicara seperti itu.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 69)
	{
		rei();
		teks = __String::createWithFormat("'Aku rasa itu adalah hal bagus?'")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 70)
	{
		nana();
		teks = __String::createWithFormat("'Ya! Ini adalah hal yang bagus!' \njawabnya dengan stiker berwajah ceria penuh kilauan.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 71)
	{
		nama_kosong();
		teks = __String::createWithFormat("Lagi-lagi aku tertawa kecil.\nAku benar-benar tidak menyangka Nana terasa berbeda di chat.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 72)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku memutuskan untuk tidak membalas chatnya dan \nmulai mempersiapkan diri untuk rekaman keduaku.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 73)
	{
		nama_kosong();
		teks = __String::createWithFormat("Jadi aku harus berbicara lebih banyak ya.\nTapi apa yang mau aku bicarakan.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 74)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku jadi menyadari kalau youtuber yang biasa aku tonton juga \nbanyak berbicara. Tapi sekarang ketika aku berusaha mengingatnya,\naku jadi lupa apa yang biasa dia katakan.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 75)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku akhirnya memutuskan untuk menonton beberapa video \nterlebih dahulu sebelum memulai rekaman berikutnya.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 76)
	{
		nama_kosong();
		teks = __String::createWithFormat("Namun akhirnya aku malah menikmati video yang aku \ntonton dan lupa pada tujuan awalku.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 77)
	{
		rei();
		teks = __String::createWithFormat("\"Ahh! Aku memang payah!\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 78)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku kesal pada diriku sendiri dan segera memaksakan \ndiriku untuk mulai merekam.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 79)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku rasa aku hanya perlu mengatakan apa yang sedang aku \npikirkan ketika bermain.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 80)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tapi sebelumnya untuk rekaman kali ini aku perlu meminta maaf \nkarena kekuranganku sebelumnya.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 81)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tapi aku merasa kalau orang-orang tidak peduli pada hal itu \ndan mengurungkan niatku.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 82)
	{
		rei();
		teks = __String::createWithFormat("\"Halo semuanya, kembali lagi bersama Rei!\nDi video kali ini aku akan melanjutkan gameplay dari video sebelumnya.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 83)
	{
		rei();
		teks = __String::createWithFormat("\"Untuk kalian yang belum nonton video sebelumnya,\naku sarankan untuk menontonnya terlebih dahulu.\" ---")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 84)
	{
		rei();
		teks = __String::createWithFormat("\"Apabila link tidak ada di deskripsi,\nsalahkan yang edit dan upload video ini.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 85)
	{
		rei();
		teks = __String::createWithFormat("\"Sebelum saya membuang lebih banyak waktu dan kuota Anda,\napabila Anda menggunakan data, mari kita mulai mainkan saja gamenya.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 86)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku berhasil mengatakannya dengan lancar dan jelas.\nAwal yang bagus! Aku menjadi bersemangat.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 87)
	{
		nama_kosong();
		teks = __String::createWithFormat("Setengah jam kemudian, aku menyadari kalau aku terlalu fokus \nke dalam gameku dan tidak banyak berbicara sepanjang rekaman.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 88)
	{
		rei();
		teks = __String::createWithFormat("\"...\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 89)
	{
		rei();
		teks = __String::createWithFormat("\"Gwaaahh!!\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 90)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku menghirup udara segar sebanyak mungkin dan menghembuskannya.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 91)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku harap Nana tidak kecewa karena aku tidak membawakan \nrekaman baru hari ini.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 92)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sepertinya aku harus rela untuk melakukan rekaman ulang \nuntuk video keduaku.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 93)
	{
		anna();
		teks = __String::createWithFormat("\"Selamat pagi Rei!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 94)
	{
		rei();
		teks = __String::createWithFormat("\"Hai.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 95)
	{
		anna();
		teks = __String::createWithFormat("\"Tidak ada semangatnya sama sekali seperti biasa.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 96)
	{
		rei();
		teks = __String::createWithFormat("\"Ya, begitulah.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 97)
	{
		anna();
		teks = __String::createWithFormat("\"Tapi sepertinya hari ini berbeda.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 98)
	{
		rei();
		teks = __String::createWithFormat("\"Aku mengacaukan banyak hal.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 99)
	{
		rei();
		teks = __String::createWithFormat("\"Ah, mungkin lebih tepatnya aku mengacaukan satu hal \nyang sama dua kali.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 100)
	{
		anna();
		teks = __String::createWithFormat("\"Hal seperti apa? Tidak mengerjakan tugas?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 101)
	{
		rei();
		teks = __String::createWithFormat("\"Meskipun itu aku, aku tidak akan termakan lelucon yang \nsama dua kali.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 102)
	{
		anna();
		teks = __String::createWithFormat("\"Sudah kuduga.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 103)
	{
		rei();
		teks = __String::createWithFormat("\"Haha. Sudah kubilang aku tidak akan termakan-\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 104)
	{
		rei();
		teks = __String::createWithFormat("\"Bercanda kan? Ini minggu kedua lho.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 105)
	{
		anna();
		teks = __String::createWithFormat("\"Tenang saja, ini masih pagi. Masih sempat kok.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 106)
	{
		rei();
		teks = __String::createWithFormat("\"Serius kah? Kalau begitu aku memang mengacaukan \nbeberapa hal.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 107)
	{
		anna();
		teks = __String::createWithFormat("\"Rekaman videomu? Seperti apa kamu mengacaukannya?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 108)
	{
		rei();
		teks = __String::createWithFormat("\"Hmm.. tidak ada hubungannya denganmu sih,\njadi aku rasa tidak perlu dibahas.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 109)
	{
		anna();
		teks = __String::createWithFormat("...")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 110)
	{
		anna();
		teks = __String::createWithFormat("\"Aku tidak akan memberikanmu tugasku.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 111)
	{
		rei();
		teks = __String::createWithFormat("\"Ha? Kenapa tiba-tiba?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 112)
	{
		rei();
		teks = __String::createWithFormat("\"Ayolah, katamu masih sempat kan?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 113)
	{
		anna();
		teks = __String::createWithFormat("\"Masa bodoh.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 114)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Ha? Kenapa sih. Terserahlah.\nSepertinya dia sedang mengerjaiku.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 115)
	{
		nama_kosong();
		teks = __String::createWithFormat("Bercandanya sudah keterlaluan,\nAnna benar-benar tidak mengijinkanku melihat tugasnya.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 116)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sementara itu aku merasa enggan untuk meminta orang lain.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 117)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku akan terkesan menyedihkan kalau hanya berbicara \npada mereka bila perlu tugas saja.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 118)
	{
		rei();
		teks = __String::createWithFormat("Sepertinya aku harus mengerjakannya sendiri. Tenang saja. Pasti \nmasih sempat. Lagipula ini baru minggu kedua, pasti bisa aku kerjakan.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 120)
	{
		nama_kosong();
		teks = __String::createWithFormat("Akhirnya aku berhasil menyelesaikan tugasku.\nEntah benar atau tidak.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 121)
	{
		nama_kosong();
		teks = __String::createWithFormat("Beberapa saat kemudian,\ndosen memasuki ruang kelas dan memulai pelajaran.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 122)
	{
		nama_kosong();
		teks = __String::createWithFormat("Namun ketika kami di absen,\ntidak ada seorangpun membalas panggilan nama 'Kirana Adriani'.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 123)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku terkejut karena baru menyadarinya.\nNana belum hadir di ruangan ini.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 124)
	{
		nama_kosong();
		teks = __String::createWithFormat("Nana baru masuk kelas 30 menit setelah pelajaran dimulai.\nPoin kompensasi pertamanya di kampus ini.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 125)
	{
		nama_kosong();
		teks = __String::createWithFormat("Bila aku berpikiran buruk, sisi baiknya adalah ini berarti \naku ada teman ketika menjalani hukuman kompensasi nanti.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 126)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ya. Aku sangat yakin suatu hari di semester ini aku akan telat.\nHal itu sudah terbukti selama 5 semester ini.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 127)
	{
		nana();
		teks = __String::createWithFormat("\"Tenang saja, aku tidak apa-apa kok.\nAku hanya bangun kesiangan.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 128)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Beberapa anak laki-laki terlihat mengkhawatirkan princess baru \ndi kelas ini.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 129)
	{
		nama_kosong();
		teks = __String::createWithFormat("Meskipun bilang begitu,\nbukan berarti aku tidak khawatir sama sekali sih.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 130)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku cuma bukan tipe orang yang akan menghampirinya dan mengatakan \n'Kamu kenapa? Baik-baik saja kan?'")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 131)
	{
		nama_kosong();
		teks = __String::createWithFormat("Uwaaah, hanya membayangkan aku melakukan hal seperti itu saja \nsudah membuatku merinding.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 132)
	{
		anna();
		teks = __String::createWithFormat("\"Sudahlah, kalian malah mengganggu Nana kalau mengelilinginya \nterus.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 133)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Ya. Benar sekali Anna. Apa yang mereka lakukan dengan \nmengerubunginya seperti gorengan.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 134)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sepulang kuliah, Nana mengajakku ke Gazebo.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 135)
	{
		nana();
		teks = __String::createWithFormat("\"Sebenarnya aku ingin menguploadnya langsung,\ntapi aku merasa ingin menunjukkannya padamu dulu.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 136)
	{
		rei();
		teks = __String::createWithFormat("\"Memangnya kenapa? Aku juga bisa menontonnya di youtube kok.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 137)
	{
		nana();
		teks = __String::createWithFormat("\"Ya, memang sih, tapi kalau ada bagian yang tidak kamu suka,\nkamu bisa mengatakannya padaku.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 138)
	{
		rei();
		teks = __String::createWithFormat("\"Sepertinya aku tidak akan keberatan dengan editan apapun \nyang kamu lakukan. Tapi baiklah, nanti akan aku tonton.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 139)
	{
		nana();
		teks = __String::createWithFormat("\"Nanti?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/3.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 140)
	{
		rei();
		teks = __String::createWithFormat("\"Iya, nanti, aku akan kabari kalau-\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/3.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 141)
	{
		nama_kosong();
		teks = __String::createWithFormat("Eh? Kenapa Nana memasang ekspresi sedih begitu.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/3.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 142)
	{
		rei();
		teks = __String::createWithFormat("\"Em... sekarang?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 143)
	{
		nama_kosong();
		teks = __String::createWithFormat("Nana menganggukkan kepala dengan wajah ceria.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 144)
	{
		rei();
		teks = __String::createWithFormat("\"Em.. ya.. baiklah.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
		 
	}
	if (HomeMenu::nilai_teks == 145)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Sementara Nana menyalakan laptopnya,\naku mengirim pesan pada teman kerjaku.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 146)
	{
		nama_kosong();
		teks = __String::createWithFormat("'Maaf sekali! Aku akan terlambat sedikit.'")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 147)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku sempat berpikiran untuk mengirimkannya pada Anna,\ntapi sepulang sekolah dia langsung menghilang tanpa sempat mengatakan \napakah dia ada shift atau tidak.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 148)
	{
		nana();
		teks = __String::createWithFormat("\"Ini. Silahkan dilihat. Katakan saja kalau ada bagian yang \ntidak kamu suka.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 149)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku mengira dia akan menyerahkan laptopnya padaku,\ntapi Nana malah meletakkannya di depannya.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 150)
	{
		rei();
		teks = __String::createWithFormat("\"Ya, baiklah.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 151)
	{
		nana();
		teks = __String::createWithFormat("\"Aku memang baru saja mengeditnya,\ntapi aku ingin melihatnya lagi dari awal.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 152)
	{
		nama_kosong();
		teks = __String::createWithFormat("Kami kemudian diam melihat video yang kami buat.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 153)
	{
		rei();
		teks = __String::createWithFormat("\"Sejauh ini tidak ada masalah. Aku suka kok.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 154)
	{
		nana();
		teks = __String::createWithFormat("\"Benarkah? Terimakasih.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 155)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku memang sangat menyukainya. Videonya.\nMeskipun aku memang payah karena jarang berbicara, ---")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 156)
	{
		nama_kosong();
		teks = __String::createWithFormat("Nana berhasil membuatnya menarik untuk terus di tonton.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 157)
	{
		nana();
		teks = __String::createWithFormat("\"Ah. Aku suka bagian ini. Sebentar lagi.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 158)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dia benar-benar menyukainya.\nIa tertawa ketika melihatku terkejut ketakutan di rekaman tersebut.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 159)
	{
		rei();
		teks = __String::createWithFormat("\"Kamu tidak tahu rasanya memainkan gamenya langsung.\nCoba saja kalau berani.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 160)
	{
		nana();
		teks = __String::createWithFormat("\"Tidak usah, bukannya aku takut,\ntapi aku lebih suka melihatmu memainkannya saja.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 161)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Akhirnya, video berdurasi 20 menit itu selesai.\nAku akui Nana mengerjakannya dengan baik.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 162)
	{
		rei();
		teks = __String::createWithFormat("\"Oh ya, berarti kamu memang bisa mengedit video ya?\nMata kuliah multimedia kan belum mulai.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 163)
	{
		nana();
		teks = __String::createWithFormat("\"Tidak kok, aku baru belajar sedikit-sedikit dari minggu lalu.\nAku yakin lama-lama aku bisa mengedit lebih bagus.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 164)
	{
		rei();
		teks = __String::createWithFormat("\"Aku yakin pasti bisa lebih bagus nantinya.\nMaksudku, ini saja sudah bagus.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 165)
	{
		nana();
		teks = __String::createWithFormat("\"Terimakasih.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 166)
	{
		rei();
		teks = __String::createWithFormat("\"Hah?!\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 167)
	{
		nana();
		teks = __String::createWithFormat("\"A-ada apa?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 168)
	{
		rei();
		teks = __String::createWithFormat("\"Kamu belajar dari minggu lalu?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 169)
	{
		nana();
		teks = __String::createWithFormat("\"Iya, aku sengaja mempersiapkannya dari awal sehingga kemarin \naku bisa segera mulai mengedit.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 170)
	{
		hiden_character();
		rei();
		teks = __String::createWithFormat("\"...\"")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 171)
	{
		rei();
		teks = __String::createWithFormat("\"Ka-kalau.. kalau saja..\"")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 172)
	{
		nama_kosong();
		teks = __String::createWithFormat("Kalau saja kemarin lusa aku menolak tawaran Nana,\napa yang akan dia rasakan")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 173)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku mengepalkan tanganku. Tidak bisa membayangkan betapa kecewanya \nNana bila aku menolaknya.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 174)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tapi, nantinya kami akan belajar editing video sih,\njadi belajar dari awal juga tidak ada salahnya.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 175)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tapi, tetap saja.. bukan itu masalahnya.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 176)
	{
		rei();
		teks = __String::createWithFormat("\"Aku minta maaf!\" \naku menundukkan wajahku kebawah.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 177)
	{
		nana();
		teks = __String::createWithFormat("\"E-ehh? Untuk apa?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 178)
	{
		rei();
		teks = __String::createWithFormat("\"Hari ini aku tidak bawa rekaman baru.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 179)
	{
		rei();
		teks = __String::createWithFormat("\"Aku sudah rekaman, tapi lagi-lagi aku lupa untuk lebih banyak berbicara,\njadi, untuk hari ini..\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 180)
	{
		nana();
		teks = __String::createWithFormat("\"Tidak apa-apa, tidak usah terlalu dipikirkan.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 181)
	{
		nana();
		teks = __String::createWithFormat("\"Kita masih baru saja mulai, jadi pelan-pelan saja.\nLagipula, kita sudah berhasil membuat satu video.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 182)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku lega dia tidak terlihat begitu kecewa--")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 183)
	{
		nana();
		teks = __String::createWithFormat("\"Tapi, tetap saja rasanya sayang sekali karena nanti tidak ada video yang bisa aku kerjakan.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/3.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 184)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ya, maaf sekali.\nTapi aku sudah bilang dari awal kalau aku ini payah.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 185)
	{
		rei();
		teks = __String::createWithFormat("\"Besok akan aku usahakan membawa rekaman baru.\nSekarang aku harus pergi dulu. Sampai jumpa.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 186)
	{
		nana();
		teks = __String::createWithFormat("\"Sampai jumpa besok. Terimakasih Rei.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 187)
	{
		rei();
		teks = __String::createWithFormat("\"Aku yang harusnya berterima kasih.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 188)
	{
		rei();
		teks = __String::createWithFormat("\"Oh ya, karena nanti tidak ada yang kamu kerjakan, pastikan kamu \nberistirahat nanti. Jadi besok kamu tidak terlambat lagi.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 189)
	{
		nama_kosong();
		teks = __String::createWithFormat("Nana terkejut mendengar ucapanku.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 190)
	{
		rei();
		teks = __String::createWithFormat("\"Dasar bodoh, tentu saja aku tahu. Kalau kamu terlambat lagi,\naku tidak akan memberikanmu rekaman lagi.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 191)
	{
		nana();
		teks = __String::createWithFormat("\"A-aku tidak akan terlambat lagi.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/5.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 192)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Dasar. Apa yang sebenarnya aku katakan.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 193)
	{
		nama_kosong();
		teks = __String::createWithFormat("Hanya karena perasaan tidak ingin kalah dari laki-laki lain  dikelasku,\naku mengatakan hal yang tidak perlu.")->getCString();
		teks_1->setString(teks);
	}

}


void Scene5a::quit_yes(Ref* sender)
{
	HomeMenu::btn_sound();
	HomeMenu::nilai_logo = true;

	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		Director::getInstance()->replaceScene(TransitionFade::create(3, HomeMenu::scene(), Color3B(255, 255, 255)));
	})));
} //button tekan exit yes

void Scene5a::quit_no(Ref* sender)
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
void Scene5a::teksJalan(float dt)
{

	teks_satu();
}

void Scene5a::teks_satu()
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
		unschedule(schedule_selector(Scene5a::teksJalan));
	}
}

void Scene5a::rei()
{
	auto teks_nama = __String::createWithFormat("Rei")->getCString();
	nama->setString(teks_nama);
}
void Scene5a::anna()
{
	auto teks_nama = __String::createWithFormat("Anna")->getCString();
	nama->setString(teks_nama);
}
void Scene5a::nana()
{
	auto teks_nama = __String::createWithFormat("Nana")->getCString();
	nama->setString(teks_nama);
}
void Scene5a::nama_kosong()
{
	auto teks_nama = __String::createWithFormat("")->getCString();
	nama->setString(teks_nama);
}
void Scene5a::nama_titik()
{
	auto teks_nama = __String::createWithFormat("......")->getCString();
	nama->setString(teks_nama);
}
void Scene5a::wali()
{
	auto teks_nama = __String::createWithFormat("Wali Kelas")->getCString();
	nama->setString(teks_nama);
}


