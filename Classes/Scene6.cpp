#include "Scene6.h"
#include "Scene8.h"
#include "Option.h"
#include "HomeMenu.h"
#include "SaveGame.h"
#include "LoadGame.h"

USING_NS_CC;



Scene* Scene6::scene()
{
	return Scene6::create();
}

bool Scene6::init()
{
	if (!Scene::init())
	{
		return false;
	}
	bgm->playBackgroundMusic("music/6.mp3", true);
	HomeMenu::game = 11;
	

	//background//
	background->setPosition(Vec2(0, 0));
	background->setAnchorPoint(Vec2(0, 0));
	this->addChild(background);
	 
	/////////////

	this->schedule(schedule_selector(Scene6::delay_game), 1);

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
	btn_load->addClickEventListener(CC_CALLBACK_1(Scene6::load_game, this));
	btn_save->addClickEventListener(CC_CALLBACK_1(Scene6::save_game, this));
	btn_config->addClickEventListener(CC_CALLBACK_1(Scene6::config, this));
	btn_exit_no->addClickEventListener(CC_CALLBACK_1(Scene6::quit_no, this));
	btn_exit_yes->addClickEventListener(CC_CALLBACK_1(Scene6::quit_yes, this));
	btn_tittle->addClickEventListener(CC_CALLBACK_1(Scene6::back_title, this));
	btn_close->addClickEventListener(CC_CALLBACK_1(Scene6::close_menu, this));
	buttonStart->addClickEventListener(CC_CALLBACK_1(Scene6::startGame, this));
	btn_menu->addClickEventListener(CC_CALLBACK_1(Scene6::pil_menu, this));
	///////////////////////////
	//gambar karakter//
	anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	hiden_character();
	this->addChild(nana_sprite);
	this->addChild(anna_sprite);
	this->addChild(lily_sprite);
	//////////////////
	//background//
	if (HomeMenu::nilai_teks > 22 && HomeMenu::nilai_teks < 35)
		background->setTexture("bg/lorong_sb.jpg");
	else if (HomeMenu::nilai_teks > 34 && HomeMenu::nilai_teks < 74)
		background->setTexture("bg/gazebo.jpg");
	else if (HomeMenu::nilai_teks > 73 && HomeMenu::nilai_teks < 157)
		background->setTexture("bg/halte_bus2.jpg");
	else if (HomeMenu::nilai_teks > 156)
		background->setTexture("bg/kamar.jpg");
	/////////////
	return true;
}
void Scene6::hiden_character()
{
	anna_sprite->setScale(0);
	nana_sprite->setScale(0);
	lily_sprite->setScale(0);
}
void Scene6::delay_game(float dt)
{
	detik++;

	if (detik == 4)
	{
		isi_teks();
		this->schedule(schedule_selector(Scene6::teksJalan), Option::speed_teks);
		unschedule(schedule_selector(Scene6::delay_game));
		detik = 0;
	}
	else if (detik == 3)
		buttonStart->setScale(1);
}


void Scene6::pil_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1400, 780)));
	btn_menu->setScale(0);

}

void Scene6::close_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1600, 780)));
	btn_menu->setScale(1);
}

void Scene6::back_title(Ref* sender)
{

	HomeMenu::btn_sound();
	bg_exit->setScale(1);
	kosong->setScale(1);
	btn_exit_no->setScale(1);
	btn_exit_yes->setScale(1);
	label_quit_no->setScale(1);
	label_quit_yes->setScale(1);

}

void Scene6::config(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, Option::scene(), Color3B(255, 255, 255)));
	})));

}
void Scene6::save_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, SaveGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene6::load_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, LoadGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene6::delay(float dt)
{
	if (detik == 1)
	{
		unschedule(schedule_selector(Scene6::delay));
		buttonStart->setScale(1);
		if (HomeMenu::nilai_teks == 23 || HomeMenu::nilai_teks == 35 || HomeMenu::nilai_teks == 74 || HomeMenu::nilai_teks == 157)
		{
			this->schedule(schedule_selector(Scene6::teksJalan), Option::speed_teks);
		}
		detik = 0;
	}
	detik++;
}
void Scene6::startGame(Ref* sender)
{
	unschedule(schedule_selector(Scene6::teksJalan));
	HomeMenu::btn_sound();
	HomeMenu::nilai_teks++;
	isi_teks();
	teks_1->setOpacity(0);
	i = 0;
	log("Nilai teks = %d", HomeMenu::nilai_teks);
	if (HomeMenu::nilai_teks == 23 || HomeMenu::nilai_teks == 35 || HomeMenu::nilai_teks == 74 || HomeMenu::nilai_teks == 157)
	{
		buttonStart->setScale(0);
		if (HomeMenu::nilai_teks > 22 && HomeMenu::nilai_teks < 35)
			background->setTexture("bg/lorong_sb.jpg");
		else if (HomeMenu::nilai_teks > 34 && HomeMenu::nilai_teks < 74)
			background->setTexture("bg/gazebo.jpg");
		else if (HomeMenu::nilai_teks > 73 && HomeMenu::nilai_teks < 156)
			background->setTexture("bg/halte_bus2.jpg");
		else if (HomeMenu::nilai_teks > 156)
			background->setTexture("bg/kamar.jpg");
		this->schedule(schedule_selector(Scene6::delay), 1.f);
	}
	else if (HomeMenu::nilai_teks == 190)
	{
		HomeMenu::nilai_teks = 1;
		this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
		{
			Director::getInstance()->replaceScene(TransitionFade::create(3, Scene8::scene(), Color3B(255, 255, 255)));
		})));
	}
	else
		this->schedule(schedule_selector(Scene6::teksJalan), Option::speed_teks);

}

void Scene6::isi_teks()
{
	if (HomeMenu::nilai_teks == 1)
	{
		anna();
		teks = __String::createWithFormat("\"Aku tertawa sampai perutku sakit menonton video kalian!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 2)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku berani bertaruh kalau pagi ini Anna adalah \norang dengan semangat paling tinggi di dunia ini.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 3)
	{
		anna();
		teks = __String::createWithFormat("\"Benar-benar bahaya! Aku takut kalau suatu saat aku \ntiba-tiba tertawa sendiri karena teringat wajah konyolmu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 4)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku sudah bisa membayangkan reaksi Anna sih,\njadi aku diam saja.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 5)
	{
		anna();
		teks = __String::createWithFormat("\"Rei! Benar-benar deh, aku tidak menyangka kamu memiliki \nekspresi lain selain wajah datarmu itu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 6)
	{	
		nana();
		teks = __String::createWithFormat("\"Iya kan? Aku juga terkejut ketika melihatnya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 7)
	{
		rei();
		teks = __String::createWithFormat("\"Apa memang begitu sih,\naku rasa wajahku biasa saja.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 8)
	{	
		anna();
		teks = __String::createWithFormat("\"Itu kan wajahmu sendiri,\njadi wajar saja kalau kamu tidak merasa begitu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 9)
	{	
		rei();
		teks = __String::createWithFormat("\"Tapi, dari komentar yang aku lihat,\ntidak ada yang menyinggung masalah ekspresiku.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 10)
	{
		nana();
		teks = __String::createWithFormat("\"Itu karena mereka tidak tahu seperti apa kamu \nbiasanya.\"")->getCString();
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
	else if (HomeMenu::nilai_teks == 11)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ya, itu masuk akal sih.\nSepertinya kali ini aku kalah berdebat dengan mereka.")->getCString();
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
	else if (HomeMenu::nilai_teks == 12)
	{
		anna();
		teks = __String::createWithFormat("\"Apakah hari ini akan ada video selanjutnya?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 13)
	{
		nana();
		teks = __String::createWithFormat("\"Sayangnya Rei belum mempersiapkan rekaman berikutnya,\njadi mungkin besok.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 14)
	{
		anna();
		teks = __String::createWithFormat("\"Rei, bagaimana sih,\nkamu ini serius ingin melakukkannya tidak?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 15)
	{
		nama_kosong();
		hiden_character();
		teks = __String::createWithFormat("Hei, kenapa kamu menyalahkanku begitu? Yang awalnya \nmengusulkan ide ini kan Nana, bukan aku.")->getCString();
		teks_1->setString(teks);
		
	}
	else if (HomeMenu::nilai_teks == 16)
	{
		rei();
		teks = __String::createWithFormat("\"Aku tahu kamu sudah menduganya,\ntapi masalah utamaku terletak pada komunikasi.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 17)
	{
		rei();
		teks = __String::createWithFormat("\"Bagaimana menjelaskannya ya.\nAku sudah berusaha untuk terus berbicara, ---\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 18)
	{
		rei();
		teks = __String::createWithFormat("\"tapi ketika aku merasa kalau yang aku katakan tidak bernilai,\naku tidak jadi mengatakannya.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 19)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ya. Salah satu prinsip hidupku dari dulu adalah aku \ntidak akan berbicara kalau menurutku itu tidak penting.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 20)
	{
		anna();
		teks = __String::createWithFormat("\"Hmm, kalau begitu kamu memang harus mulai membiasakan diri \nuntuk beromong kosong.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 21)
	{
		nama_kosong();
		teks = __String::createWithFormat("Seseorang tolong kutip perkataannya barusan.\nItu adalah sebuah nasehat dari mahasiswa IPK 4.")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 22)
	{
		rei();
		teks = __String::createWithFormat("\"Ya, aku akan berusaha.\nSekarang menjauhlah dari mejaku sebelum lebih banyak orang datang.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 23)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sepulang kuliah, aku berencana untuk berbicara sebentar dengan Nana,\nsekaligus memberikan rekaman baruku.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 24)
	{
		nama_kosong();
		teks = __String::createWithFormat("Saat ini, Nana telah menungguku di gazebo. Kami telah bersepakat \nuntuk membuatnya pergi terlebih dahulu, kemudian aku menyusul.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 25)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ada beberapa alasan kenapa aku melakukan hal ini.\nYang pertama, aku tidak ingin ada rumor aneh tentang kami.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 26)
	{
		nama_kosong();
		teks = __String::createWithFormat("Yang kedua, seperti biasa, aku hanya ingin merahasiakan apa yang \nsedang aku lakukan dari orang lain.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 27)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ketika hendak menuju gazebo,\naku berpapasan dengan Anna di lorong kampus.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 28)
	{
		anna();
		teks = __String::createWithFormat("\"Oh. Hai Rei! Mau ke sana?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 29)
	{
		rei();
		teks = __String::createWithFormat("\"Ya, begitulah. Kamu?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 /2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 30)
	{
		anna();
		teks = __String::createWithFormat("\"Aku baru ke sana besok.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 /2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 31)
	{
		anna();
		teks = __String::createWithFormat("\"Aku sedang terburu-buru,\nsampai jumpa besok!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 32)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Ia kemudian melesat begitu saja sebelum aku sempat mengatakan \nkalau besok aku tidak ada shift. Mungkin nanti akan aku \nberi tahu lewat pesan.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 33)
	{
		nama_kosong();
		teks = __String::createWithFormat("Mengingat kemarin Anna tidak ada shift, begitu juga hari ini,\nkelihatannya Anna memang hanya mengambil sedikit jam kerja.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 34)
	{
		nama_kosong();
		teks = __String::createWithFormat("Atau, mungkin dia masih berada dalam masa training atau semacamnya \nkarena kafenya juga belum selesai diperluas.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 35)
	{
		rei();
		teks = __String::createWithFormat("\"Aku sangat yakin kalau aku belum melakukannya dengan baik,\ntapi ini rekamanku yang kedua.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 36)
	{
		nana();
		teks = __String::createWithFormat("\"Terimakasih.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 37)
	{
		rei();
		teks = __String::createWithFormat("\"Sudah kubilang aku yang seharusnya mengatakan itu.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 38)
	{
		rei();
		teks = __String::createWithFormat("\"Ngomong-ngomong,\nbagaimana kondisi video pertama kita?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 39)
	{
		nana();
		teks = __String::createWithFormat("\"Aku rasa cukup baik untuk video pertama.\nMemang yang menonton masih sangat sedikit, tapi tidak \nada yang berkomentar buruk.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 40)
	{
		nana();
		teks = __String::createWithFormat("\"Malahan, ada beberapa orang yang ingin untuk segera menonton \nlanjutannya.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 41)
	{
		rei();
		teks = __String::createWithFormat("\"Begitu ya.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 42)
	{
		rei();
		teks = __String::createWithFormat("\"Baiklah, aku usahakan besok aku berikan rekaman ketiga\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 43)
	{
		nana();
		teks = __String::createWithFormat("\"Rei..\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 44)
	{
		rei();
		teks = __String::createWithFormat("\"Ya?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 45)
	{
		nana();
		teks = __String::createWithFormat("\"Ma-maaf sekali kalau aku salah, atau,\num.. jangan tersinggung..\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/5.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 46)
	{
		nana();
		teks = __String::createWithFormat("\"...\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/5.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 47)
	{
		nana();
		teks = __String::createWithFormat("\"Ah.. ma-maaf, sepertinya tidak jadi.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/5.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 48)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Kamu sengaja kan? Kamu sengaja membuatku penasaran kan?")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 49)
	{
		rei();
		teks = __String::createWithFormat("\"Na-\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 50)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sebenarnya aku hanya ingin memanggil namanya. ")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 51)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tapi ketika hendak mengucapkannya, aku menyadari kalau\nselama ini aku belum pernah memanggilnya langsung \ndengan namanya.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 52)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dan saat ini ketika pertama kalinya aku hendak melakukannya,\naku kesulitan melakukannya.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 53)
	{
		rei();
		teks = __String::createWithFormat("\"Kamu tidak perlu berhati-hati padaku. Katakan saja apa \nyang kamu ingin katakan padaku. Aku tidak akan keberatan.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 54)
	{
		nana();
		teks = __String::createWithFormat("\"...\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 55)
	{
		rei();
		teks = __String::createWithFormat("\"Ah, maksudku, ya, kamu tahu sendiri. Aku ini orangnya masa bodoh \ndengan apa yang orang lain katakan padaku.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 56)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sepertinya ini bukan pertama kalinya aku tidak sengaja mengatakan \nkalimat memalukan padanya.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 57)
	{
		nana();
		teks = __String::createWithFormat("\"Kalau begitu, aku ingin bertanya.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 58)
	{
		rei();
		teks = __String::createWithFormat("\"Ya.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 59)
	{
		nana();
		teks = __String::createWithFormat("\"Apa Rei sebenarnya keberatan melakukan hal ini?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 60)
	{
		rei();
		teks = __String::createWithFormat("\"Hah? Mana mungkin. Apa yang kamu pikirkan?\nIni adalah keputusanku sendiri.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 61)
	{
		rei();
		teks = __String::createWithFormat("\"Lagipula, kalau aku tidak mau melakukan sesuatu,\naku tidak akan melakukannya. Kamu lupa dengan hal itu?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(- 0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 62)
	{
		nana();
		teks = __String::createWithFormat("\"Seingatku, waktu itu Rei tidak mau menemaniku jalan-jalan,\ntapi tetap saja kamu temani.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 63)
	{
		rei();
		teks = __String::createWithFormat("\"...\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 64)
	{
		nama_kosong();
		teks = __String::createWithFormat("Benar juga")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 65)
	{
		rei();
		teks = __String::createWithFormat("\"Ya, itu.. pokoknya begitulah.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 66)
	{
		nana();
		teks = __String::createWithFormat("\"Maaf telah menanyakan hal aneh\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/5.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 67)
	{
		nana();
		teks = __String::createWithFormat("\"Soalnya, Rei terlihat lelah akhir-akhir ini\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/3.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 68)
	{
		nama_kosong();
		teks = __String::createWithFormat("Kuliah setiap hari, shift di kafe setelahnya, dan \nrekaman di malam hari. Aku akui akhir-akhir ini banyak hal yang harus \naku lakukan.")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	if (HomeMenu::nilai_teks == 69)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tapi, aku yakin aku akan terbiasa.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 70)
	{
		rei();
		teks = __String::createWithFormat("\"Lagi-lagi aku pikir kamu salah menilaiku. Bukan lelah,\naku memang tidak pernah bersemangat.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 71)
	{
		rei();
		teks = __String::createWithFormat("\"Tapi, aku rasa aku akan pulang dan beristirahat sebentar.\nSudah ya Nana, sampai besok!\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 72)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku bergegas meninggalkannya menuju kafe.\nAku tidak ingin terlambat dan merepotkan teman kerjaku lagi.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 73)
	{
		nana();
		teks = __String::createWithFormat("\"...\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/3.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 74)
	{
		nama_kosong();
		teks = __String::createWithFormat("Yang benar saja. Aku sukses membawa diriku melewati halte \ndimana aku seharusnya turun.")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 75)
	{
		nama_kosong();
		teks = __String::createWithFormat("Apakah ini karma karena telah berbohong pada Nana?")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 76)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku mengecek jam yang telah menunjukan pukul 8 malam.\nApakah aku perlu memanggil ojek?")->getCString();
		teks_1->setString(teks);

	}
	else if (HomeMenu::nilai_teks == 77)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tidak, aku rasa tidak perlu.\nAku bangkit dan memutuskan untuk berjalan.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 78)
	{
		nama_kosong();
		teks = __String::createWithFormat("Hal konyol seperti ini baru pernah terjadi 3 kali dalam hidupku.\nDan alasannya selalu sama. Kali ini juga begitu.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 79)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku terlalu lelah.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 80)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tidur di bus sebenarnya kerap aku lakukan. Tapi normalnya,\naku akan otomatis bangun sebelum halte pemberhentianku.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 81)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sambil berjalan, aku memanfaatkan waktu ini untuk membayangkan \nbagaimana rekaman ketigaku nanti akan aku lakukan.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 82)
	{
		nama_kosong();
		teks = __String::createWithFormat("Apa yang akan aku bicarakan, membuat lelucon, dan sebagainya.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 83)
	{
		nama_titik();
		teks = __String::createWithFormat("\"Kak!\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 84)
	{
		nama_titik();
		teks = __String::createWithFormat("\"Kakak!\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 85)
	{
		nama_titik();
		teks = __String::createWithFormat("\"Kakak Rei yang suram!\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 86)
	{
		nama_kosong();
		teks = __String::createWithFormat("Panggilan seorang perempuan menyadarkanku dari khayalanku.\nAku menoleh ke arahnya.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 87)
	{
		nama_titik();
		teks = __String::createWithFormat("\"Dasar, masa aku harus meneriakkan kata suram untuk memanggil \nkakak.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l2.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 88)
	{

		rei();
		teks = __String::createWithFormat("\"Aku tidak punya seorang adik, jadi bagaimana aku tahu kalau \nkamu memanggilku tanpa namaku, adik kelasku Lily?\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l2.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 89)
	{
		lily();
		teks = __String::createWithFormat("\"Seharusnya kakak tahu dari suaraku kan?\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l2.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 90)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ya, dia sedikit benar.")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l2.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 91)
	{
		lily();
		teks = __String::createWithFormat("\"Kakak pasti sedang melamun,\napa yang kakak pikirkan?\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 92)
	{
		rei();
		teks = __String::createWithFormat("\"Hal-hal yang biasa orang dewasa pikirkan,\nkamu tidak perlu tahu.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 93)
	{
		lily();
		teks = __String::createWithFormat("\"Kakak terlalu sombong, kita kan hanya beda 1 tahun\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l2.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 94)
	{
		lily();
		teks = __String::createWithFormat("\"...\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l2.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 95)
	{
		lily();
		teks = __String::createWithFormat("\"Ah! Kakak sedang memikirkan hal yang mesum ya!\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l3.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 96)
	{
		rei();
		teks = __String::createWithFormat("\"Bukan, bodoh. Selain itu, kita beda 2 tahun.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l5.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 97)
	{
		nama_kosong();
		teks = __String::createWithFormat("Akan aku perkenalkan. Gadis kecil cerewet ini \nadalah Lily Kumalasari. Tadi aku bilang kalau usia kami berjarak \n2 tahun, tapi dia ini tingkat 2.")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l5.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 98)
	{
		rei();
		teks = __String::createWithFormat("\"Jadi, kenapa kamu bisa ada di sini?\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 99)
	{
		lily();
		teks = __String::createWithFormat("\"Itu yang tadi ingin Lily tanyakan.\nBukannya rumah kakak ada di arah sana ya?\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 100)
	{
		rei();
		teks = __String::createWithFormat("\"Ke-kenapa kamu bisa tahu rumahku?!\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 101)
	{
		nama_kosong();
		teks = __String::createWithFormat("Jangan-jangan dia benar-benar adikku?!")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 102)
	{
		lily();
		teks = __String::createWithFormat("\"Kakak dulu pernah mengatakannya waktu perkenalan diri di ormawa.\nKarena daerahnya dekat dengan rumah Lily, jadi Lily ingat!\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setScaleX(-0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 103)
	{
		rei();
		teks = __String::createWithFormat("\"Eh? Jadi rumahmu ada di dekat sini? Aku baru tahu\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setScaleX(-0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 104)
	{
		lily();
		teks = __String::createWithFormat("\"Jadi kakak ke sini bukan karena mau ke rumah Lily ya?\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l3.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 105)
	{
		rei();
		teks = __String::createWithFormat("\"Untuk apa juga aku ke rumahmu\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setScaleX(-0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 106)
	{
		lily();
		teks = __String::createWithFormat("\"Mengajari Lily berbagai hal yang Lily belum tahu\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setScaleX(-0.6);
		lily_sprite->setTexture("character/lily/l5.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 107)
	{
		nama_kosong();
		teks = __String::createWithFormat("Kenapa barusan aku menelan ludahku. Kenapa?")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setScaleX(-0.6);
		lily_sprite->setTexture("character/lily/l5.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 108)
	{
		rei();
		teks = __String::createWithFormat("\"Aku ketiduran di bus, karena itu sekarang aku di sini. Kamu?\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setScaleX(-0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 109)
	{
		lily();
		teks = __String::createWithFormat("\"Aku sedang memburu makan malamku. \"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setScaleX(-0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 110)
	{
		rei();
		teks = __String::createWithFormat("\"Hati-hati ya, malam hari banyak orang mencurigakan berkeliaran.\nKalau begitu, aku pulang dulu.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setScaleX(-0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 111)
	{
		lily();
		teks = __String::createWithFormat("\"Aku barusan bertemu orang mencurigakan kok.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l5.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 112)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Aku kan? Maksudmu aku kan?")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 113)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sekarang aku ingin sedikit menjelaskan sesuatu. Di kampusku,\nsenioritas tidak begitu terasa.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 114)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tentunya adik tingkat tetap harus menghormati kakak tingkat,\ntapi hanya sebatas itu. Kami berbicara dengan santai tanpa \nmemandang tingkat.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 115)
	{
		nama_kosong();
		teks = __String::createWithFormat("Meskipun begitu, aku rasa kasusku dengan Lily ada di tingkatan \nyang berbeda.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 116)
	{
		lily();
		teks = __String::createWithFormat("\"Kakak mau Lily antar? Hari ini kakak terlihat lelah sekali.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 117)
	{
		rei();
		teks = __String::createWithFormat("\"Aku sangat senang mendengarnya. Tapi,\nkamu ini sedang naik sepeda lo\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 118)
	{
		lily();
		teks = __String::createWithFormat("\"Ah, benar juga. Hehehe\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l5.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 119)
	{
		rei();
		teks = __String::createWithFormat("\"...\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 120)
	{
		rei();
		teks = __String::createWithFormat("\"Apa aku memang terlihat sangat lelah?\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 121)
	{
		lily();
		teks = __String::createWithFormat("\"Menurut Lily sih iya. Kakak terlihat lebih suram dari biasanya.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l4.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 122)
	{
		lily();
		teks = __String::createWithFormat("\"Apa kakak harus segera pulang? Lily masih ingin bersama kakak \nsebentar lagi.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l4.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 123)
	{
		rei();
		teks = __String::createWithFormat("Ada sesuatu yang harus aku kerjakan.\nLagipula, bukannya kamu ingin mencari makan ya?")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 124)
	{
		lily();
		teks = __String::createWithFormat("Sebentar saja, ada sesuatu yang ingin Lily bicarakan.")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 125)
	{
		nama_kosong();
		teks = __String::createWithFormat("Serius apa tidak ya dia? Aku jadi sulit mengetahuinya karena \nsifatnya itu.")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 126)
	{
		lily();
		teks = __String::createWithFormat("\"Serius.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l2.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 127)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dia tidak membaca pikiranku kan ya?")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 128)
	{
		rei();
		teks = __String::createWithFormat("Aku rasa kalau sebentar saja..")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 129)
	{
		lily();
		teks = __String::createWithFormat("\"Yay!\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 130)
	{
		lily();
		teks = __String::createWithFormat("\"Jadi begini, sebentar lagi, ormawa kita akan mengadakan \npendakian gunung.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 131)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku dan Lily adalah anggota ormawa bernama wapalhi.\nMeskipun begitu, aku adalah anggota bayangan.")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	if (HomeMenu::nilai_teks == 132)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku jarang sekali datang dan berkontribusi di sana.\nAku hanya pernah beberapa kali menghadiri perkumpulan,\nitupun hanya kalau Lily memaksa.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 133)
	{
		nama_kosong();
		teks = __String::createWithFormat("Keanggotaanku di wapalhi juga karena dipaksa Lily.\nMana mungkin dengan sendirinya aku mau repot-repot \nmenambah kesibukanku. ")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 134)
	{
		nama_kosong();
		teks = __String::createWithFormat("Wapalhi sendiri adalah singkatan dari wahana pecinta lingkungan \nhidup. Sesuai namanya, kamu bisa menebak apa yang ormawa ini \nlakukan.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 135)
	{
		nama_kosong();
		teks = __String::createWithFormat("Kami pergi ke berbagai tempat seperti gunung, gua, arung jeram, \ndan sebangsanya.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 136)
	{
		rei();
		teks = __String::createWithFormat("\"Apa kamu tidak ingat sudah berapa kali kamu mengajakku \nke acara seperti itu? Kamu tahu sendiri jawabanku.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 137)
	{
		nama_kosong();
		teks = __String::createWithFormat("Mendaki gunung? Jangan bercanda. Lebih baik tubuhku menjadi kaku di \ndepan laptop.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 138)
	{
		lily();
		teks = __String::createWithFormat("\"Meskipun Lily sudah tahu kalau akan ditolak, Lily tetap \nakan mengatakannya. Lily tidak mau menyesal!\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l4.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 139)
	{
		nama_kosong();
		teks = __String::createWithFormat("Kamu sengaja membuatnya agar terdengar memiliki arti \nlain kan? Iya kan?")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l4.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 140)
	{
		lily();
		teks = __String::createWithFormat("\"Untuk event kali ini, kita benar-benar kekurangan peserta.\nBanyak sekali orang yang tidak bisa ikut.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l4.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 141)
	{
		rei();
		teks = __String::createWithFormat("\"Kenapa bisa begitu?\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setScaleX(-0.6);
		lily_sprite->setTexture("character/lily/l4.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 142)
	{
		lily();
		teks = __String::createWithFormat("\"Karena banyak anggota yang juga menjadi anggota \ndi ormawa lain, dan kebetulan banyak ormawa lain sedang \nmengadakan event.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setScaleX(-0.6);
		lily_sprite->setTexture("character/lily/l4.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 143)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku tidak suka berjanji. Dan juga sangat jujur pada \nperasaanku sendiri. Mungkin terlalu jujur. Jadi..")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setScaleX(-0.6);
		lily_sprite->setTexture("character/lily/l4.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 144)
	{
		rei();
		teks = __String::createWithFormat("\"Maaf, aku---.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setScaleX(-0.6);
		lily_sprite->setTexture("character/lily/l4.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 145)
	{
		lily();
		teks = __String::createWithFormat("\"Aaaaah! Jangan dijawab sekarang!\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l3.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 146)
	{
		nama_kosong();
		teks = __String::createWithFormat("Eh? Lalu untuk apa kamu menahanku pulang dan membuatku \nkedinginan di malam hari begini?")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 147)
	{
		lily();
		teks = __String::createWithFormat("\"Aku benar-benar butuh bantuan kakak.\nJadi aku ingin kakak benar-benar memikirkan jawabannya.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 148)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku yakin dipikir selama satu tahunpun jawabanku tetap tidak.")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 149)
	{
		rei();
		teks = __String::createWithFormat("\"Aku rasa sekarang atau kapanpun aku tetap akan meno---\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 150)
	{
		lily();
		teks = __String::createWithFormat("\"Aaahh! Sudah aku bilang jangan dijawab sekarang!\nKakak Rei bodoh! Suram!\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l2.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 151)
	{
		nama_kosong();
		teks = __String::createWithFormat("Hei, hei. Kata-katamu barusan semakin membuatku ingin \nmenolaknya lo.")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l2.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 152)
	{
		rei();
		teks = __String::createWithFormat("\"Terserah deh. Apa aku boleh pulang sekarang?\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setScaleX(-0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 153)
	{
		lily();
		teks = __String::createWithFormat("\"Iya. Terimakasih Kak Rei.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setScaleX(-0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 154)
	{
		lily();
		teks = __String::createWithFormat("\"Ngomong-ngomong, Kakak pulang sampai malam sekali padahal \ntidak punya pacar dan teman. Apa yang kakak lakukan?!\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setScaleX(-0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 155)
	{
		rei();
		teks = __String::createWithFormat("\"Orang dewasa punya urusan sendiri yang anak kecil tidak \nperlu tahu.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setScaleX(-0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 156)
	{
		lily();
		teks = __String::createWithFormat("\"Humh!\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l2.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 157)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sesampainya di rumah, keinginanku untuk membuat rekaman pergi \nterusir rasa lelah.")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	if (HomeMenu::nilai_teks == 158)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tapi, kalau aku tidak rutin memberikan rekaman baru pada Nana,\naku juga merasa tidak enak padanya.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 159)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku nyaris ketiduran ketika ponselku berdering.\nAku mengeceknya dengan malas.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 160)
	{
		nana();
		teks = __String::createWithFormat("'Rei, ada yang ingin aku diskusikan!'.\nBerikut stiker dengan ekspresi bersemangat.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 161)
	{
		rei();
		teks = __String::createWithFormat("'Sebelum itu, aku ingin meminta maaf karena suatu hal.'")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 162)
	{
		nana();
		teks = __String::createWithFormat("'Kamu tidak bisa membuat rekaman baru hari ini?'")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 163)
	{
		rei();
		teks = __String::createWithFormat("'Ya, maaf. Bukannya aku ingin beralasan, tapi aku \ntidak sedang dalam suasana untuk membuat rekaman.'")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 164)
	{
		nama_kosong();
		teks = __String::createWithFormat("Nana membalas dengan stiker berekspresi sedih.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 165)
	{
		nana();
		teks = __String::createWithFormat("'Tapi, aku rasa Rei memang tidak perlu \nmembuatnya kalau sedang merasa tidak ingin.'")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 166)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku harap jawaban tersebut tidak terus aku jadikan alasan \nuntuk tidak membuat rekaman baru kedepannya.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 167)
	{
		nama_kosong();
		teks = __String::createWithFormat("Lagipula, aku memang sangat lelah hari ini.\nBukan malas.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 168)
	{
		rei();
		teks = __String::createWithFormat("'Jadi, apa yang ingin kamu diskusikan?'")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 169)
	{
		nana();
		teks = __String::createWithFormat("'Aku ada ide untuk membantu Rei lebih banyak berbicara,\ndan juga memberi suasana baru di video kita.'")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 170)
	{
		rei();
		teks = __String::createWithFormat("'Ooh! Kedengarannya bagus. Bagaimana caranya?'")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 171)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku perlu menunggu beberapa saat sebelum ia mengirimkan \nbalasannya. Sepertinya ia sedang mengetik pesan yang \ncukup panjang.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 172)
	{
		nana();
		teks = __String::createWithFormat("'Di video berikutnya, bagaimana kalau aku ikut bermain?'")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 173)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ternyata pesannya cukup singkat-")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 174)
	{
		nama_kosong();
		teks = __String::createWithFormat("Eh?!")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 175)
	{
		nama_kosong();
		teks = __String::createWithFormat("I-ide yang sangat menarik.\nAku perlu waktu sejenak untuk memikirkannya.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 176)
	{
		rei();
		teks = __String::createWithFormat("'Bagaimana hal itu bisa membantuku untuk terus berbicara?'")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 177)
	{
		nana();
		teks = __String::createWithFormat("'Aku hanya perlu membantu Rei mendapatkan topik pembicaraan,\natau memancing Rei untuk terus berbicara'")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 178)
	{
		nama_kosong();
		teks = __String::createWithFormat("Memangnya Nana bisa melakukan hal seperti itu?")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 179)
	{
		rei();
		teks = __String::createWithFormat("'Aku tidak terlalu yakin metode itu bisa bekerja.'")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 180)
	{
		nana();
		teks = __String::createWithFormat("'Karena itu kita perlu mencobanya!'. Jawabnya dengan stiker semangat.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 181)
	{
		nana();
		teks = __String::createWithFormat("'Atau aku juga bisa menginjak kaki Rei bila Rei mulai tidak \nbanyak bicara.'")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 182)
	{
		nama_kosong();
		teks = __String::createWithFormat("Idenya benar-benar menarik. Tapi aku rasa hal itu akan \nmembuatku menjerit, bukan berbicara.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 183)
	{
		nana();
		teks = __String::createWithFormat("'Kaki tidak ikut terekam kan?\nJadi aku rasa tidak masalah.'")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 184)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ya. Memang masalahnya bukan di sana.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 185)
	{
		rei();
		teks = __String::createWithFormat("'Kalau kamu memang mau mencobanya,\naku tidak keberatan sih.'")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 186)
	{
		nana();
		teks = __String::createWithFormat("'Terimakasih!'")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 187)
	{
		nana();
		teks = __String::createWithFormat("'Kalau begitu sampai besok!'")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 188)
	{
		nama_kosong();
		teks = __String::createWithFormat("Setelah obrolan kami selesai, aku meletakkan ponselku \ndi atas meja. Sebaiknya aku segera tidur.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 189)
	{
		nama_kosong();
		teks = __String::createWithFormat("Namun ketika baru memejamkan mata,\naku terpikirkan sesuatu.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 190)
	{
		nama_kosong();
		teks = __String::createWithFormat("Apakah Nana ingin langsung melakukannya besok?")->getCString();
		teks_1->setString(teks);
		 
	}
}


void Scene6::quit_yes(Ref* sender)
{
	HomeMenu::btn_sound();
	HomeMenu::nilai_logo = true;

	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		Director::getInstance()->replaceScene(TransitionFade::create(3, HomeMenu::scene(), Color3B(255, 255, 255)));
	})));
} //button tekan exit yes

void Scene6::quit_no(Ref* sender)
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
void Scene6::teksJalan(float dt)
{

	teks_satu();
}

void Scene6::teks_satu()
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
		unschedule(schedule_selector(Scene6::teksJalan));
	}
}

void Scene6::rei()
{
	auto teks_nama = __String::createWithFormat("Rei")->getCString();
	nama->setString(teks_nama);
}
void Scene6::anna()
{
	auto teks_nama = __String::createWithFormat("Anna")->getCString();
	nama->setString(teks_nama);
}
void Scene6::nana()
{
	auto teks_nama = __String::createWithFormat("Nana")->getCString();
	nama->setString(teks_nama);
}
void Scene6::nama_kosong()
{
	auto teks_nama = __String::createWithFormat("")->getCString();
	nama->setString(teks_nama);
}
void Scene6::nama_titik()
{
	auto teks_nama = __String::createWithFormat("......")->getCString();
	nama->setString(teks_nama);
}
void Scene6::lily()
{
	auto teks_nama = __String::createWithFormat("Lily")->getCString();
	nama->setString(teks_nama);
}
void Scene6::wali()
{
	auto teks_nama = __String::createWithFormat("Wali Kelas")->getCString();
	nama->setString(teks_nama);
}


