#include "Scene5.h"
#include "Scene5a.h"
#include "Option.h"
#include "HomeMenu.h"
#include "SaveGame.h"
#include "LoadGame.h"

USING_NS_CC;



Scene* Scene5::scene()
{
	return Scene5::create();
}

bool Scene5::init()
{
	if (!Scene::init())
	{
		return false;
	}
	bgm->playBackgroundMusic("music/5.mp3", true);
	HomeMenu::game = 9;
	

	//background//
	background->setPosition(Vec2(0, 0));
	background->setAnchorPoint(Vec2(0, 0));
	this->addChild(background);
	/////////////

	this->schedule(schedule_selector(Scene5::delay_game), 1);

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
	btn_load->addClickEventListener(CC_CALLBACK_1(Scene5::load_game, this));
	btn_save->addClickEventListener(CC_CALLBACK_1(Scene5::save_game, this));
	btn_config->addClickEventListener(CC_CALLBACK_1(Scene5::config, this));
	btn_exit_no->addClickEventListener(CC_CALLBACK_1(Scene5::quit_no, this));
	btn_exit_yes->addClickEventListener(CC_CALLBACK_1(Scene5::quit_yes, this));
	btn_tittle->addClickEventListener(CC_CALLBACK_1(Scene5::back_title, this));
	btn_close->addClickEventListener(CC_CALLBACK_1(Scene5::close_menu, this));
	buttonStart->addClickEventListener(CC_CALLBACK_1(Scene5::startGame, this));
	btn_menu->addClickEventListener(CC_CALLBACK_1(Scene5::pil_menu, this));
	///////////////////////
	//gambar karakter//
	anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	hiden_character();
	this->addChild(nana_sprite);
	this->addChild(anna_sprite);
	//////////////////
	//background//
	if (HomeMenu::nilai_teks > 66 && HomeMenu::nilai_teks < 78)
		background->setTexture("bg/kafe.jpg");
	else if (HomeMenu::nilai_teks > 77 && HomeMenu::nilai_teks < 93)
		background->setTexture("bg/kamar.jpg");
	else if (HomeMenu::nilai_teks > 92 && HomeMenu::nilai_teks < 96)
		background->setTexture("bg/menuju_kampus_1.jpg");
	else if (HomeMenu::nilai_teks > 95 && HomeMenu::nilai_teks < 155)
		background->setTexture("bg/kafe.jpg");
	else if (HomeMenu::nilai_teks > 154 && HomeMenu::nilai_teks < 175)
		background->setTexture("bg/kafe_2.jpg");
	else if (HomeMenu::nilai_teks > 174 && HomeMenu::nilai_teks < 211)
		background->setTexture("bg/kafe_3.jpg");
	else if (HomeMenu::nilai_teks > 211)
		background->setTexture("bg/gazebo.jpg");
	/////////////
	return true;
}
void Scene5::hiden_character()
{
	anna_sprite->setScale(0);
	nana_sprite->setScale(0);
}
void Scene5::delay_game(float dt)
{
	detik++;

	if (detik == 4)
	{
		isi_teks();
		this->schedule(schedule_selector(Scene5::teksJalan), Option::speed_teks);
		unschedule(schedule_selector(Scene5::delay_game));
		detik = 0;
	}
	else if (detik == 3)
		buttonStart->setScale(1);
}


void Scene5::pil_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1400, 780)));
	btn_menu->setScale(0);

}

void Scene5::close_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1600, 780)));
	btn_menu->setScale(1);
}

void Scene5::back_title(Ref* sender)
{

	HomeMenu::btn_sound();
	bg_exit->setScale(1);
	kosong->setScale(1);
	btn_exit_no->setScale(1);
	btn_exit_yes->setScale(1);
	label_quit_no->setScale(1);
	label_quit_yes->setScale(1);

}

void Scene5::config(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, Option::scene(), Color3B(255, 255, 255)));
	})));

}
void Scene5::save_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, SaveGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene5::load_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, LoadGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene5::delay(float dt)
{
	if (detik == 1)
	{
		unschedule(schedule_selector(Scene5::delay));
		buttonStart->setScale(1);
		if (HomeMenu::nilai_teks == 67 || HomeMenu::nilai_teks == 78 || HomeMenu::nilai_teks == 93 || HomeMenu::nilai_teks == 96 || HomeMenu::nilai_teks == 155 || HomeMenu::nilai_teks == 175 || HomeMenu::nilai_teks == 212)
		{
			if(HomeMenu::nilai_teks == 155 || HomeMenu::nilai_teks == 175)
				anna_sprite->setScale(0.6);
			this->schedule(schedule_selector(Scene5::teksJalan), Option::speed_teks);
		}
		detik = 0;
	}
	detik++;
}
void Scene5::startGame(Ref* sender)
{
	unschedule(schedule_selector(Scene5::teksJalan));
	HomeMenu::btn_sound();
	HomeMenu::nilai_teks++;
	isi_teks();
	teks_1->setOpacity(0);
	i = 0;
	log("Nilai teks = %d", HomeMenu::nilai_teks);
	if (HomeMenu::nilai_teks == 67 || HomeMenu::nilai_teks == 78 || HomeMenu::nilai_teks == 93 || HomeMenu::nilai_teks == 96 || HomeMenu::nilai_teks == 155 || HomeMenu::nilai_teks == 175 || HomeMenu::nilai_teks == 212)
	{
		hiden_character();
		buttonStart->setScale(0);
		if (HomeMenu::nilai_teks > 66 && HomeMenu::nilai_teks < 78)
			background->setTexture("bg/kafe.jpg");
		else if (HomeMenu::nilai_teks > 77 && HomeMenu::nilai_teks < 93)
			background->setTexture("bg/kamar.jpg");
		else if (HomeMenu::nilai_teks > 92 && HomeMenu::nilai_teks < 96)
			background->setTexture("bg/menuju_kampus_1.jpg");
		else if (HomeMenu::nilai_teks > 95 && HomeMenu::nilai_teks < 155)
			background->setTexture("bg/kafe.jpg");
		else if (HomeMenu::nilai_teks > 154 && HomeMenu::nilai_teks < 175)
			background->setTexture("bg/kafe_2.jpg");
		else if (HomeMenu::nilai_teks > 174 && HomeMenu::nilai_teks < 211)
			background->setTexture("bg/kafe_3.jpg");
		else if (HomeMenu::nilai_teks > 211)
			background->setTexture("bg/gazebo.jpg");
		this->schedule(schedule_selector(Scene5::delay), 1.f);
	}
	else if (HomeMenu::nilai_teks == 254)
	{
		HomeMenu::nilai_teks = 1;
		this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
		{
			Director::getInstance()->replaceScene(TransitionFade::create(3, Scene5a::scene(), Color3B(255, 255, 255)));
		})));
	}
	else
		this->schedule(schedule_selector(Scene5::teksJalan), Option::speed_teks);

}

void Scene5::isi_teks()
{
	if (HomeMenu::nilai_teks == 1)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tidak terasa aku telah sampai di akhir minggu.\nHari jum'at adalah hari dimana semangatku berada di titik paling tinggi.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 2)
	{
		nama_kosong();
		teks = __String::createWithFormat("Beruntunglah mata kuliah yang ada di hari ini.\nDampak dari semangat di akhir mingguku ini memberikanku fokus \nyang lebih pada apapun, termasuk pada pelajaran.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 3)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dan.. tidak disangka.\nAku sendiri juga terkejut pada kebetulan ini.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 4)
	{
		nama_kosong();
		teks = __String::createWithFormat("Hari ini adalah mata kuliah pembuatan game.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 5)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dari apa yang aku tangkap.\nDan kali ini aku yakin dengan apa yang aku tangkap, -- -")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 6)
	{	
		nama_kosong();
		teks = __String::createWithFormat("Di mata kuliah ini aku akan mempelajari penggunaan salah satu software \nuntuk pembuatan game atau biasa disebut game engine, Unity.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 7)
	{
		nama_kosong();
		teks = __String::createWithFormat("Materi lain dalam mata kuliah ini adalah mengenai logika game \ndan perancangan sistem game.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 8)
	{	
		nama_kosong();
		teks = __String::createWithFormat("Selain pembuatan game, mata kuliah hari ini adalah multimedia.\nAku telah tiga semester berturut-turut belajar multimedia.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 9)
	{	
		nama_kosong();
		teks = __String::createWithFormat("Untuk semester ini, di mata kuliah multimedia aku akan belajar editing \nvideo.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 10)
	{
		nama_kosong();
		teks = __String::createWithFormat("Menurutku mata kuliah multimedia cukup menyenangkan. Hanya saja,\ndiperlukan cukup banyak waktu untuk menyelesaikan tugas di matkul ini.")->getCString();
		teks_1->setString(teks);
		 
		 
	}
	else if (HomeMenu::nilai_teks == 11)
	{
		nama_kosong();
		teks = __String::createWithFormat("Jadi bisa disimpulkan, selama beberapa minggu ke depan di semester ini,\naku akan menantikan akhir minggu lebih dari biasanya.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 12)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku menyukai jadwal kuliahku. Mata kuliah yang cukup santai diletakkan \ndi akhir minggu.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 13)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tak lama, lima belas menit sebelum tengah siang, bel pulang telah \nberdering.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 14)
	{
		nama_kosong();
		teks = __String::createWithFormat("Di hari jum'at kami memang dijadwalkan untuk pulang lebih awal dari \nbiasanya.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 15)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sekarang, aku hanya perlu menyelesaikan shift kerjaku di kafe,\nsegera pulang, dan bermain game sampai besok.")->getCString();
		teks_1->setString(teks);

	}
	else if (HomeMenu::nilai_teks == 16)
	{
		nama_kosong();
		teks = __String::createWithFormat("Saking senangnya, tanpa sengaja aku membuat senyuman kecil \ndi wajahku.")->getCString();
		teks_1->setString(teks);

	}
	else if (HomeMenu::nilai_teks == 17)
	{
		anna();
		teks = __String::createWithFormat("\"Wah, sepertinya sekarang waktu yang cukup bagus untuk berbicara \ndengan Rei.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 18)
	{
		rei();
		teks = __String::createWithFormat("\"Kamu seharusnya sudah tahu kalau tidak ada waktu yang tepat untuk \nmengobrol denganku.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 19)
	{
		rei();
		teks = __String::createWithFormat("\"Apalagi di saat aku sedang senang seperti ini,\ntidak akan aku biarkan seseorang merusak kebahagiaanku.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 20)
	{
		anna();
		teks = __String::createWithFormat("\"Aku tidak yakin hal seperti apa yang bisa merusak kebahagiaanmu,\ntapi kami hanya ingin berbicara sebentar.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 21)
	{
		anna();
		teks = __String::createWithFormat("\"Yah.. meskipun aku bilang begitu,\nsebenarnya Nana sih yang ada perlu denganmu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 22)
	{
		nana();
		teks = __String::createWithFormat("\"Ma-maaf mengganggumu Rei, aku cuma ingin bicara sebentar.\"")->getCString();
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
		nama_kosong();
		teks = __String::createWithFormat("Kira-kira hal apa yang ingin Nana bicarakan denganku.\nKalau masalah jalan-jalan kampus,\nseharusnya sudah selesai sejak kemarin.")->getCString();
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
		nama_kosong();
		teks = __String::createWithFormat("Hmm.. aku benar-benar tidak tahu apa yang ingin dia bicarakan.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 25)
	{
		hiden_character();
		nana();
		teks = __String::createWithFormat("\"Sebelumnya aku ingin tanya sesuatu..\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 26)
	{
		nana();
		teks = __String::createWithFormat("\"...\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 27)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sepertinya ia sendiri agak kesulitan mengatakannya.\nHal ini membuatku semakin penasaran.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 28)
	{
		rei();
		teks = __String::createWithFormat("\"Ya?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 29)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku balik bertanya untuk memaksa Nana segera mengatakan \napa yang ingin dia katakan. Aku sudah tidak sabar.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 30)
	{
		nama_kosong();
		teks = __String::createWithFormat("Namun sepertinya suaraku malah terlalu keras dan \nmengejutkan Nana hingga tersentak.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 31)
	{
		nana();
		teks = __String::createWithFormat("\"Uh.. itu.. apa Rei pernah merekam.. Rei sendiri?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 32)
	{
		rei();
		teks = __String::createWithFormat("\"Hah?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 33)
	{
		nama_kosong();
		teks = __String::createWithFormat("Pertanyaan macam apa itu. Apapun dugaanku tadi,\npertanyaannya jelas-jelas diluar perkiraanku.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 34)
	{
		rei();
		teks = __String::createWithFormat("\"Maksudnya?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 35)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku melirik Anna, berharap ia bisa menjelaskan apa yang Nana maksud.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 36)
	{
		hiden_character();
		anna();
		teks = __String::createWithFormat("\"Jadi begini, ini ada kaitannya dengan mata kuliah hari ini sih..\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 37)
	{
		nana();
		teks = __String::createWithFormat("\"Ah. Sebelumnya, kamu tahu apa mata kuliah hari ini?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 38)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku tidak bisa menyalahkannya untuk melemparkan \npertanyaan seperti itu padaku.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 39)
	{
		rei();
		teks = __String::createWithFormat("\"Pembuatan game dan multimedia.\nKhususnya editing video di multimedia.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 40)
	{
		anna();
		teks = __String::createWithFormat("\"Wah, luar biasa.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 41)
	{
		nama_kosong();
		teks = __String::createWithFormat("Lagi-lagi aku tidak bisa menyalahkan reaksi Anna.\nTapi Nana, aku benar-benar berharap kamu tidak ikut terkejut juga.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/6.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 42)
	{
		hiden_character();
		nana();
		teks = __String::createWithFormat("\"Rei belum pernah merekam game yang Rei mainkan kan?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 43)
	{
		rei();
		teks = __String::createWithFormat("\"Tidak. Aku rasa tidak pernah.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 44)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sambil menjawab pertanyaannya,\naku rasa aku sedikit mengerti arah pembicaraan ini.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 45)
	{
		rei();
		teks = __String::createWithFormat("\"Maksudmu, seperti gamer di youtube atau streamer kan?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 46)
	{
		nama_kosong();
		teks = __String::createWithFormat("Meskipun aku lebih suka untuk bermain game,\naku terkadang menonton gameplay dari youtuber yang aku suka")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 47)
	{
		nama_kosong();
		teks = __String::createWithFormat("Kesenangan dari bermain game sendiri dan menonton orang \nbermain game itu berbeda.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 48)
	{
		nana();
		teks = __String::createWithFormat("\"Ya. Maksudku seperti itu.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 49)
	{
		nana();
		teks = __String::createWithFormat("\"Jadi, apa Rei tertarik untuk melakukan hal seperti itu?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 50)
	{
		rei();
		teks = __String::createWithFormat("\"Aku.. agak ragu kalau disuruh menjawab sekarang. Hmm.. entahlah.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 51)
	{
		anna();
		teks = __String::createWithFormat("\"Seperti yang aku bilang tadi,\bini berkaitan dengan mata kuliah multimedia.\"")->getCString();
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
		anna();
		teks = __String::createWithFormat("\"Sambil belajar editing video di semester ini,\nNana ingin menawarkan untuk mengedit video dari gameplaymu.\"")->getCString();
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
		teks = __String::createWithFormat("\"Ya.\nBegitulah.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 54)
	{
		rei();
		teks = __String::createWithFormat("\"Tapi aku, belum pernah melakukan hal seperti ini sebelumnya,\naku tidak yakin apa aku bisa.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 55)
	{
		rei();
		teks = __String::createWithFormat("\"Dan juga, aku tidak yakin kalau aku menarik untuk di tonton.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 56)
	{
		nana();
		teks = __String::createWithFormat("\"Karena itu aku akan mencoba untuk membuatnya terlihat menarik.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 57)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Jawabanmu bisa berarti kamu setuju kalau aku tidak menarik \nuntuk di tonton.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 58)
	{
		nama_kosong();
		teks = __String::createWithFormat("Entah kenapa Nana bersemangat pada hal ini.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 59)
	{
		rei();
		teks = __String::createWithFormat("\"Aku rasa ini terlalu tiba-tiba. Jadi seperti jawabanku tadi,\naku tidak bisa memutuskannya sekarang.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 60)
	{
		rei();
		teks = __String::createWithFormat("\"Mungkin hari Senin aku akan beri tahu keputusanku.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 61)
	{
		nana();
		teks = __String::createWithFormat("\"Oke!\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 62)
	{
		anna();
		teks = __String::createWithFormat("\"Wah, kalau begitu, kemungkinan besar Rei akan menyetujuinya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 63)
	{
		nana();
		teks = __String::createWithFormat("\"Kenapa begitu?”\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 64)
	{
		anna();
		teks = __String::createWithFormat("\"Biasanya Rei kalau tidak mau melakukan sesuatu akan langsung \ndia tolak.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 65)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Aku terkejut dengan perkataan Anna. Ia benar. Biasanya aku \nakan langsung menolak apapun yang aku anggap merepotkan.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 66)
	{
		nama_kosong();
		teks = __String::createWithFormat("Jadi sepertinya, aku tertarik dengan hal ini.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 67)
	{
		nama_kosong();
		teks = __String::createWithFormat("Kedatanganku di tempat kerja disambut kegaduhan.\nSuatu pekerjaan, mungkin renovasi sedang dilakukan di toko sebelah.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 68)
	{
		nama_kosong();
		teks = __String::createWithFormat("Saat membuka pintu masuk, aku juga menyadari kalau poster \nlowongan pekerjaan sudah tidak terpasang di tempatnya.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 69)
	{
		nama_kosong();
		teks = __String::createWithFormat("Teman kerjaku yang selalu menyambut kedatanganku dengan senyuman \nmengatakan kalau ia yang mencabut poster tersebut atas perintah \nMas Karya.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 70)
	{
		nama_kosong();
		teks = __String::createWithFormat("Shift ini adalah rintangan terakhirku sebelum bisa menikmati \nmalam yang panjang nanti.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 71)
	{
		nama_kosong();
		teks = __String::createWithFormat("Shift ini adalah rintangan terakhirku sebelum bisa menikmati \nmalam yang panjang nanti.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 72)
	{
		nama_kosong();
		teks = __String::createWithFormat("Namun ternyata, rintangan ini jauh lebih berat dari yang aku duga.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 73)
	{
		nama_kosong();
		teks = __String::createWithFormat("Selama sebulan aku meninggalkan kafe ini,\nternyata pengunjung yang datang di akhir pekan mengalami peningkatan.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 74)
	{
		nama_kosong();
		teks = __String::createWithFormat("Pengunjung semakin ramai ketika matahari mulai membenamkan dirinya.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 75)
	{
		nama_kosong();
		teks = __String::createWithFormat("Hari ini dia datang lagi tidak ya?")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 76)
	{
		nama_kosong();
		teks = __String::createWithFormat("Apa yang aku pikirkan mengejutkan diriku sendiri. Bodoh.\nSudah pasti lebih baik dia tidak datang.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 77)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku tidak ingin membuang tenagaku untuknya.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 78)
	{
		nama_kosong();
		teks = __String::createWithFormat("Shiftku hari ini akhirnya berakhir tanpa harus melayani Anna.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 79)
	{
		nama_kosong();
		teks = __String::createWithFormat("Akhirnya sekarang telah tiba waktu yang aku tunggu-tunggu.\nDengan tergesa-gesa, aku bersiap untuk bermain game.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 80)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sambil menunggu beberapa proses loading, aku melamun sejenak,\nmemikirkan permintaan Nana.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 81)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sebenarnya, aku pikir cukup keren untuk menjadi seorang gamer \ndi youtube. Tapi jiwa pemalasku sedikit mengendurkan niatku.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 82)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku memang sangat menikmati bermain game.\nAku bahkan berani mengatakan kalau aku termasuk dalam sedikit \norang yang benar-benar jatuh cinta pada game.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 83)
	{
		nama_kosong();
		teks = __String::createWithFormat("Mungkin terdengar menjijikkan, tapi aku sangat menikmati tiap detik \nyang aku lewati ketika bermain game. Aku sangat menghargainya.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 84)
	{
		nama_kosong();
		teks = __String::createWithFormat("Kalau aku mulai melakukan rekaman,\napakah aku masih bisa menikmati game seperti biasa?")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 85)
	{
		nama_kosong();
		teks = __String::createWithFormat("Pertanyaan itu adalah hal yang paling mengganggu dalam memutuskan \njawabanku kepada Nana.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 86)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sebelum dapat menjawabnya, gameku sudah siap dimainkan dan akupun \nsegera larut kedalamnya.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 87)
	{
		nama_kosong();
		teks = __String::createWithFormat("...")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 88)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dering alarm membangunkanku dari ketiduranku. Untuk yang kesekian \nkalinya dalam hidupku, aku terbangun di depan laptop.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 89)
	{
		nama_kosong();
		teks = __String::createWithFormat("Hari Sabtu, hari yang paling dicintai oleh sebagian besar \numat manusia.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 90)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku segera bangkit sebelum kesadaranku hilang lagi, \nbersiap untuk berangkat.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 91)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ya. Jangan terkejut. Kalau dari lubuk hatiku yang paling dalam,\naku ingin tetap bersantai di dalam kamarku sampai hari Senin.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 92)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tapi demi uang,\ndi hari Sabtu dan Minggu aku memutuskan untuk tetap bekerja.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 93)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dalam perjalananku menuju halte, permintaan Nana lagi-lagi \nmembesit di pikiranku. Aku berdebat dengan diriku sendiri.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 94)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sebagian diriku merasa kalau aku ingin mencobanya. Tapi, aku \ntidak pernah sekalipun membayangkan untuk melakukan hal tersebut.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 95)
	{
		nama_kosong();
		teks = __String::createWithFormat("Pada akhirnya aku hanya menghela nafas panjang.\nAku belum bisa memutuskan.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 96)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku masih bisa mendengar kegaduhan renovasi di toko sebelah.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 97)
	{
		nama_kosong();
		teks = __String::createWithFormat("Suaranya memang cukup gaduh sampai aku berpikir kalau hal ini akan \nmenurunkan kedatangan pelanggan.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 98)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tapi melihat banyaknya pelanggan di hari kemarin,\nsemoga saja tidak begitu.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 99)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sembari mengumpulkan semangat untuk mulai bekerja,\naku membuka pintu kafe.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 100)
	{
		anna();
		teks = __String::createWithFormat("\"Wah, akhirnya datang juga. Sedikit lagi kamu terlambat loh!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 101)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Aku mematung di depan pintu masuk kafe.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 102)
	{
		nama_kosong();
		teks = __String::createWithFormat("Siapapun yang ingin masuk ke kafe, aku minta maaf karena \nmenghalangi jalanmu. Kakiku sedang tidak berfungsi saat ini.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 103)
	{
		nama_kosong();
		teks = __String::createWithFormat("Yang jadi masalah bukan keberadaan Anna yang ada di kafe.\nTunggu, aku tarik kembali. Hal itu adalah masalah.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 104)
	{
		nama_kosong();
		teks = __String::createWithFormat("Namun masalah sebenarnya ada pada celemek kafe kami yang ia \nkenakan.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 105)
	{
		anna();
		teks = __String::createWithFormat("\"Hei, jangan diam terus di sana, kamu menghalangi jalan!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 106)
	{
		rei();
		teks = __String::createWithFormat("\"A-ah.. iya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 107)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sepertinya aku telah normal kembali dan bisa melangkah \nmendekati Anna.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 108)
	{
		rei();
		teks = __String::createWithFormat("\"Maaf.. tapi.. ulang tahunku, bukan hari ini\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 109)
	{
		anna();
		teks = __String::createWithFormat("\"Ha? Apa yang kamu katakan? Kamu yakin sudah bangun?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A2.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 110)
	{
		anna();
		teks = __String::createWithFormat("\"Aku tahu kok, ulang tahunmu tanggal 21 September kan?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 111)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Aku mengangguk kecil.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 112)
	{
		nama_kosong();
		teks = __String::createWithFormat("Eh? Dia ingat?")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 113)
	{
		rei();
		teks = __String::createWithFormat("\"Jadi, apa yang kamu lakukan di sini?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 114)
	{
		anna();
		teks = __String::createWithFormat("\"Aku tidak tahu kenapa kamu menanyakan hal itu,\ntapi aku pikir 'bekerja' adalah jawaban yang cukup logis.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 115)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ya. Tentu saja. Dia di sini untuk bekerja.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 116)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tapi kenapa?!")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 117)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku teringat sesuatu.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 118)
	{
		rei();
		teks = __String::createWithFormat("\"Jadi waktu itu, kamu memang mengobrol dengan Mas Karya ya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 119)
	{
		anna();
		teks = __String::createWithFormat("\"Eh? Kamu tidak tahu ya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A2.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 120)
	{
		rei();
		teks = __String::createWithFormat("\"Tidak tahu dan tidak menduganya. Kenapa juga \nMas Karya mau membuang waktunya untuk berbicara denganmu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 121)
	{
		anna();
		teks = __String::createWithFormat("\"Awalnya dia pikir aku pacarmu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 122)
	{
		nama_kosong();
		teks = __String::createWithFormat("Lagi? Setelah si murid pindahan itu,\nsekarang Mas Karyapun otaknya juga ikutan bengkok")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 123)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku rasa.. itu salah satu dampak terlalu banyak bekerja.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 124)
	{
		rei();
		teks = __String::createWithFormat("\"Tentunya kamu jawab 'tidak' kan?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 125)
	{
		anna();
		teks = __String::createWithFormat("\"Aku juga awalnya berpikir untuk menjawab 'tidak'.\nTapi karena aku pikir bakal seru, aku malah menjawab sebaliknya. \nEhehe..\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 126)
	{
		rei();
		teks = __String::createWithFormat("\"Apanya yang 'Ehehe' !\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 127)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku memasang wajah paling kesal yang bisa aku buat.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 128)
	{
		anna();
		teks = __String::createWithFormat("\"Eh?? Sebegitu keberatannya kah kamu? Cuma bercanda padahal.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A2.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 129)
	{
		rei();
		teks = __String::createWithFormat("\"Ini bukan masalah keberatan atau tidak-\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 130)
	{
		anna();
		teks = __String::createWithFormat("\"Wah, jadi sebenarnya kamu tidak keberatan.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 131)
	{
		rei();
		teks = __String::createWithFormat("\"Po-pokoknya, aku tidak menyangka bisa-bisanya Mas Karya \nmempekerjakanmu karena kamu bodohi.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 132)
	{
		anna();
		teks = __String::createWithFormat("\"Ha? Apa maksudmu?\nTadi aku sudah bilang kalau aku bercanda kan?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A2.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 133)
	{
		rei();
		teks = __String::createWithFormat("\"Eh? Oh.. Jadi kamu tidak mengaku sebagai.. yah, itu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 134)
	{
		anna();
		teks = __String::createWithFormat("\"Tidak, tenang saja, aku tidak sejahat itu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 135)
	{
		anna();
		teks = __String::createWithFormat("\"Tapi, sepertinya kamu memang tidak keberatan.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 136)
	{
		hiden_character();
		rei();
		teks = __String::createWithFormat("\"Sebaiknya kita mulai bekerja.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 137)
	{
		nama_kosong();
		teks = __String::createWithFormat("Bagaimanapun, sekarang semuanya jadi masuk akal.\nJadi Anna benar-benar adalah karyawan baru kami.\nSepertinya aku harus menerima fakta itu.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 138)
	{
		rei();
		teks = __String::createWithFormat("\"Tapi, aku tidak merasa kalau kafe ini membutuhkan lebih banyak \ntenaga kerja.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 139)
	{
		anna();
		teks = __String::createWithFormat("\"Ya memang sih, untuk sekarang sih tidak.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 140)
	{
		rei();
		teks = __String::createWithFormat("\"Untuk sekarang?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A2.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 141)
	{
		anna();
		teks = __String::createWithFormat("\"Hei, yang benar saja, masa kamu tidak tahu?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A2.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 142)
	{
		rei();
		teks = __String::createWithFormat("\"Apanya?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 143)
	{
		anna();
		teks = __String::createWithFormat("\"Toko di sebelah, sebentar lagi akan jadi bagian dari kafe ini.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 144)
	{
		rei();
		teks = __String::createWithFormat("\"Eh?! Serius? Yang benar saja!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 145)
	{
		anna();
		teks = __String::createWithFormat("\"Kamu sebagai karyawan seharusnya senang dong.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 146)
	{
		hiden_character();
		rei();
		teks = __String::createWithFormat("\"Ya. Benar juga.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 147)
	{
		nama_kosong();
		teks = __String::createWithFormat("Memangnya kafe ini menghasilkan pendapatan yang cukup besar ya?\nYah, keputusan ada di tangan Mas Karya sih.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 148)
	{
		nama_kosong();
		teks = __String::createWithFormat("Wah.. perluasan tempat ya.\nAku membayangkan kafe ini menjadi jauh lebih luas.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 149)
	{
		rei();
		teks = __String::createWithFormat("\"Ngomong-ngomong, memangnya kamu ada waktu untuk ini?\"")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 150)
	{
		rei();
		teks = __String::createWithFormat("\"Maksudku, untuk belajar dan organisasimu.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 151)
	{
		anna();
		teks = __String::createWithFormat("\"Tentunya aku tidak mengambil shift sebanyakmu.\nAku sudah melihat jadwalmu loh,\nseharusnya aku yang bertanya begitu padamu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 152)
	{
		rei();
		teks = __String::createWithFormat("\"Aku sih, baik-baik saja. Aku tidak ikut organisasi,\ndan juga.. tidak perlu belajar.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 153)
	{
		anna();
		teks = __String::createWithFormat("\"Hah?!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 154)
	{
		rei();
		teks = __String::createWithFormat("\"Yah, maksudku.. Pokoknya aku baik-baik saja.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 155)
	{
		anna();
		teks = __String::createWithFormat("\"Luar biasa.\nSeharusnya aku tidak memilih hari Sabtu untuk hari pertama kerja.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 156)
	{
		rei();
		teks = __String::createWithFormat("\"Meskipun aku seniormu, tapi sebenarnya aku sendiri juga kelelahan.\nSeingatku pelanggan kami tidak sebanyak ini\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 157)
	{
		anna();
		teks = __String::createWithFormat("\"Kamu tidak terlihat kelelahan. Lihatlah aku,\naku rasa aku sudah tidak memiliki tenaga untuk pulang.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 158)
	{
		rei();
		teks = __String::createWithFormat("\"Kalau begitu, em.. sebelum pulang mau istirahat sebentar?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 159)
	{
		anna();
		teks = __String::createWithFormat("\"Oke, kamu yang bayar ya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 160)
	{
		nama_kosong();
		teks = __String::createWithFormat("Respon yang luar biasa cepat.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 161)
	{
		rei();
		teks = __String::createWithFormat("\"Tidak masalah kalau cuma teh.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 162)
	{
		anna();
		teks = __String::createWithFormat("\"Eh? Enggak, aku ini cuma bercanda loh.\nTapi, aku tidak keberatan kalau kamu memang mau mentraktirku.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A2.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 163)
	{
		rei();
		teks = __String::createWithFormat("\"Jelas sekali kalau aku juga bercanda,\nkenapa kamu anggap serius?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A2.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 164)
	{
		anna();
		teks = __String::createWithFormat("\"Iya juga ya, mana mungkin Rei mau mentraktirku begitu saja.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 165)
	{
		rei();
		teks = __String::createWithFormat("\"Aku rasa.. bukan disitu masalahnya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 166)
	{
		anna();
		teks = __String::createWithFormat("\"Eh? Jadi dimana? Aku tidak begitu paham.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A2.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 167)
	{
		rei();
		teks = __String::createWithFormat("\"Heh.. jadi seorang ketua kelas dengan IPK 4 juga tidak bisa \nmembaca dengan teliti ya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A2.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 168)
	{
		anna();
		teks = __String::createWithFormat("\"Kamu bicara apa sih? Aku sama sekali tidak paham.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A2.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 169)
	{
		anna();
		teks = __String::createWithFormat("\"Eeh?! Jangan-jangan.. hmm, tapi bisa jadi sih,\nkaryawan disini bebas mengambil minuman?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 170)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sial. Padahal aku ingin menggodanya lebih lama lagi.\nPrediksi dari makhluk IPK 4 memang luar biasa.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 171)
	{
		rei();
		teks = __String::createWithFormat("\"Tidak bebas sih, kalau teh tidak apa-apa, dan pastinya \nair putih juga.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 172)
	{
		anna();
		teks = __String::createWithFormat("\"Kenapa kamu tidak bilang sejak awal?!\nDuh, tau begitu dari tadi aku sudah minum teh.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 173)
	{
		rei();
		teks = __String::createWithFormat("\"Aku pikir kamu sudah tahu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 174)
	{
		anna();
		teks = __String::createWithFormat("\"Dasar, aku mau minum air putih saja ragu-ragu tadi.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 175)
	{
		
		anna();
		teks = __String::createWithFormat("\"Terimakasih.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 176)
	{
		rei();
		teks = __String::createWithFormat("\"Ya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 177)
	{
		anna();
		teks = __String::createWithFormat("\"Eh?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A2.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 178)
	{
		rei();
		teks = __String::createWithFormat("\"Kadang-kadang kita bisa beruntung seperti ini.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A2.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 179)
	{
		rei();
		teks = __String::createWithFormat("\"Ini adalah kopi yang sudah cukup lama disimpan.\nJadi kita boleh membuatnya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 180)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku menatap Anna. Kenapa ia tidak bilang apa-apa?\nApa akhirnya dia tidak suka dengan kopi yang aku pilih")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 181)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tidak penting juga sih. Lagipula, aneh juga kalau aku \nbisa terus menebak rasa yang dia suka.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 182)
	{
		anna();
		teks = __String::createWithFormat("\"Ada apa?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A2.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 183)
	{
		rei();
		teks = __String::createWithFormat("\"Tidak apa-apa.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A2.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 184)
	{
		anna();
		teks = __String::createWithFormat("\"Kamu menunggu ya?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 185)
	{
		rei();
		teks = __String::createWithFormat("\"Ya, aku menunggu waktu dimana kita bisa segera pulang.\nKalau dipikir, membuatkanmu kopi malah semakin membuatku lelah.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 186)
	{
		anna();
		teks = __String::createWithFormat("\"Ahahaha, tenang saja, enak kok.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 187)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dasar, dia ini.. sengaja mengerjaiku.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 188)
	{
		rei();
		teks = __String::createWithFormat("\"Aku tidak butuh pendapatmu. Lagipula, tidak \nperlu kamu beri tahu sudah pasti enak kalau aku yang buat.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 189)
	{
		anna();
		teks = __String::createWithFormat("\"Tadi, kamu bilang kamu yang buat?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A2.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 190)
	{
		rei();
		teks = __String::createWithFormat("\"Ya, soalnya ini kan kopi gratis, jadinya aku buat sendiri.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A2.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 191)
	{
		anna();
		teks = __String::createWithFormat("\"Tapi, kayaknya ada sensasi aneh di kopinya.\nCuma perasaanku?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A2.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 192)
	{
		rei();
		teks = __String::createWithFormat("\"Itu jahe, apa kurang cocok dengan rasa kopinya?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 193)
	{
		anna();
		teks = __String::createWithFormat("\"Enggak sih, cuma unik saja.\nAku jarang minum sesuatu dengan jahe soalnya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 194)
	{
		rei();
		teks = __String::createWithFormat("\"Biasanya kalau aku terlalu capek, aku tambahkan jahe diminumanku.\nBesoknya badanku langsung segar.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 195)
	{
		anna();
		teks = __String::createWithFormat("\"Oh, begitu. Terimakasih.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 196)
	{
		rei();
		teks = __String::createWithFormat("\"Ya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 197)
	{
		anna();
		teks = __String::createWithFormat("\"...\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 198)
	{
		anna();
		teks = __String::createWithFormat("\"Kalau begitu, sampai jumpa besok Senin!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 199)
	{
		rei();
		teks = __String::createWithFormat("\"Besok kamu tidak kerja ya?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 200)
	{
		anna();
		teks = __String::createWithFormat("\"Iya, aku sengaja meluangkan hari Minggu untuk hal lainnya.\nMaaf ya!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 201)
	{
		rei();
		teks = __String::createWithFormat("\"Hah? Kenapa meminta maaf? Aku senang bisa bekerja tanpa gangguan.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 202)
	{
		anna();
		teks = __String::createWithFormat("\"Oh ya. Kamu tidak lupa dengan permintaan Nana kan?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A2.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 203)
	{
		nama_kosong();
		teks = __String::createWithFormat("Benar juga. Dikarenakan kegaduhan dari toko sebelah, dan juga \nkegaduhan orang di hadapanku ini, aku jadi melupakan hal yang terus aku \npikirkan sejak tadi malam.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A2.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 204)
	{
		rei();
		teks = __String::createWithFormat("\"Tidak.. aku.. belum memutuskan.\nAku.. masih tidak yakin.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 205)
	{
		anna();
		teks = __String::createWithFormat("\"Kamu terlalu serius. Jangan terlalu panjang memikirkannya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 206)
	{
		hiden_character();
		rei();
		teks = __String::createWithFormat("\"Benar juga. Kalau begitu, sampai jumpa besok Senin!\"")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 207)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tidak. Dia mungkin salah. Entah kenapa, aku merasa kalau \nkeputusan yang akan aku buat ini cukup serius.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 208)
	{
		nama_kosong();
		teks = __String::createWithFormat("Mungkin karena telah begitu lama sejak aku membuat keputusan.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 209)
	{
		nama_kosong();
		teks = __String::createWithFormat("Atau mungkin karena aku menangkap sekilas ekspresi sedih yang \nbarusan Anna buat.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 210)
	{
		nama_kosong();
		teks = __String::createWithFormat("Mungkin juga karena minggu ini sangat melelahkan untukku.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 211)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku harus segera pulang dan beristirahat.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 212)
	{
		nama_kosong();
		teks = __String::createWithFormat("Hari Senin sepulang sekolah. Aku mengajak Anna dan Nana \nke Gazebo untuk mendengarkan keputusanku.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 213)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tapi Anna harus mengurus sesuatu di ormawanya sehingga \ntidak bisa ikut.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 214)
	{
		nama_kosong();
		teks = __String::createWithFormat("'Nanti saja beri tahu aku', begitu katanya.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 215)
	{
		nana();
		teks = __String::createWithFormat("\"Sebenarnya,\nkamu tidak perlu harus memutuskannya sekarang.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 216)
	{
		rei();
		teks = __String::createWithFormat("\"Tidak, aku rasa tidak baik kalau menundanya.\nKemarin aku sudah janji untuk memutuskannya hari ini.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 217)
	{
		rei();
		teks = __String::createWithFormat("\"Sebelumnya, boleh aku bertanya?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 218)
	{
		nana();
		teks = __String::createWithFormat("\"I-Iya.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 219)
	{
		rei();
		teks = __String::createWithFormat("\"Tenang saja, tidak usah gugup.\nMalahan kalau kamu gugup, aku juga ikut merasa begitu.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 220)
	{
		nana();
		teks = __String::createWithFormat("\"Maaf\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/3.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 221)
	{
		rei();
		teks = __String::createWithFormat("\"Apa kamu, sangat ingin melakukan hal ini?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 222)
	{
		nana();
		teks = __String::createWithFormat("\"Aku tidak yakin kalau dengan kata 'sangat',\ntapi, aku merasa ingin melakukannya.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 223)
	{
		rei();
		teks = __String::createWithFormat("\"Jadi, kamu ingin aku menjawab 'iya'\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 224)
	{
		nana();
		teks = __String::createWithFormat("\"...\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 225)
	{
		nana();
		teks = __String::createWithFormat("\"Iya.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 226)
	{
		nama_kosong();
		teks = __String::createWithFormat("Cukup lama waktu yang ia butuhkan,\ntapi Nana menjawabnya dengan tegas")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 227)
	{
		rei();
		teks = __String::createWithFormat("\"Meskipun kita baru satu minggu bertemu,\ntapi kamu tahu aku orangnya seperti apa.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 228)
	{
		nana();
		teks = __String::createWithFormat("\"Aku.. tidak begitu paham.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 229)
	{
		rei();
		teks = __String::createWithFormat("\"Serius?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 230)
	{
		nana();
		teks = __String::createWithFormat("\"Ma-maaf, aku kurang bisa menangkap maksudmu dengan baik.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/3.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 231)
	{
		rei();
		teks = __String::createWithFormat("\"Aku rasa kamu serius, hahaha.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 232)
	{
		rei();
		teks = __String::createWithFormat("\"Aku ini, pemalas. Setiap hari, aku bermain game.\nAku terus melarikan diri kepada game.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 233)
	{
		rei();
		teks = __String::createWithFormat("\"Bodohnya lagi, meskipun aku menyadari hal itu,\naku terus melakukannya.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
		if (HomeMenu::nilai_teks == 234)
		{
			nana();
			teks = __String::createWithFormat("\"Iya, aku tahu.\"")->getCString();
			teks_1->setString(teks);
			nana_sprite->setScale(0.6);
			nana_sprite->setTexture("character/nana/1.png");
			nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
		}
		if (HomeMenu::nilai_teks == 235)
		{
			nama_kosong();
			teks = __String::createWithFormat("Terimakasih karena kejujuranmu, tapi itu juga sedikit \nmenyakitiku.")->getCString();
			teks_1->setString(teks);
			nana_sprite->setScale(0.6);
			nana_sprite->setTexture("character/nana/1.png");
			nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
		}
		if (HomeMenu::nilai_teks == 236)
		{
			nana();
			teks = __String::createWithFormat("\"Tapi, karena itulah, aku pikir tidak ada yang lebih menyukai \ngame daripada Rei.\"")->getCString();
			teks_1->setString(teks);
			nana_sprite->setScale(0.6);
			nana_sprite->setTexture("character/nana/2.png");
			nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
		}
		if (HomeMenu::nilai_teks == 237)
		{
			nama_kosong();
			teks = __String::createWithFormat("Aku tertegun dengan ucapannya. Ya.\nAku, memang sangat menyukai game. Aku mencintainya.")->getCString();
			teks_1->setString(teks);
			nana_sprite->setScale(0.6);
			nana_sprite->setTexture("character/nana/2.png");
			nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
		}
		if (HomeMenu::nilai_teks == 238)
		{
			nana();
			teks = __String::createWithFormat("\"Karena itu aku pikir, Rei bisa dengan mudah mengalahkan \nyoutube gamer lain di luar sana.\"")->getCString();
			teks_1->setString(teks);
			nana_sprite->setScale(0.6);
			nana_sprite->setTexture("character/nana/2.png");
			nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
		}
		if (HomeMenu::nilai_teks == 239)
		{
			rei();
			teks = __String::createWithFormat("\"Kamu terdengar sangat yakin sekali.\"")->getCString();
			teks_1->setString(teks);
			nana_sprite->setScale(0.6);
			nana_sprite->setScaleX(-0.6);
			nana_sprite->setTexture("character/nana/2.png");
			nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
		}
		if (HomeMenu::nilai_teks == 240)
		{
			nana();
			teks = __String::createWithFormat("\"Aku sangat yakin!\"")->getCString();
			teks_1->setString(teks);
			nana_sprite->setScale(0.6);
			nana_sprite->setScaleX(-0.6);
			nana_sprite->setTexture("character/nana/2.png");
			nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
		}
		if (HomeMenu::nilai_teks == 241)
		{
			nama_kosong();
			teks = __String::createWithFormat("Lagi-lagi ia membuatku tertegun.")->getCString();
			teks_1->setString(teks);
			nana_sprite->setScale(0.6);
			nana_sprite->setScaleX(-0.6);
			nana_sprite->setTexture("character/nana/2.png");
			nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
		}
		if (HomeMenu::nilai_teks == 242)
		{
			nana();
			teks = __String::createWithFormat("\"Aku akan membantu Rei sebisaku!\"")->getCString();
			teks_1->setString(teks);
			nana_sprite->setScale(0.6);
			nana_sprite->setScaleX(-0.6);
			nana_sprite->setTexture("character/nana/2.png");
			nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
		}
		if (HomeMenu::nilai_teks == 243)
		{
			nama_kosong();
			teks = __String::createWithFormat("Aku tertawa kecil.")->getCString();
			teks_1->setString(teks);
			nana_sprite->setScale(0.6);
			nana_sprite->setScaleX(-0.6);
			nana_sprite->setTexture("character/nana/2.png");
			nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
		}
		if (HomeMenu::nilai_teks == 244)
		{
			rei();
			teks = __String::createWithFormat("\"Maaf, kalau kamu sedang bersemangat,\nkamu seperti orang yang berbeda.\"")->getCString();
			teks_1->setString(teks);
			nana_sprite->setScale(0.6);
			nana_sprite->setTexture("character/nana/1.png");
			nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
		}
		if (HomeMenu::nilai_teks == 245)
		{
			nana();
			teks = __String::createWithFormat("\"Aku, memang sedang berusaha untuk berubah.\"")->getCString();
			teks_1->setString(teks);
			nana_sprite->setScale(0.6);
			nana_sprite->setTexture("character/nana/1.png");
			nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
		}
		if (HomeMenu::nilai_teks == 246)
		{
			rei();
			teks = __String::createWithFormat("\"Iya, aku tahu. Kamu pernah mengatakannya.\"")->getCString();
			teks_1->setString(teks);
			nana_sprite->setScale(0.6);
			nana_sprite->setTexture("character/nana/1.png");
			nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
		}
		if (HomeMenu::nilai_teks == 247)
		{
			nana();
			teks = __String::createWithFormat("\"Karena itu, kalau bisa melakukan hal yang aku inginkan,\naku pikir hal itu akan membantuku berubah.\"")->getCString();
			teks_1->setString(teks);
			nana_sprite->setScale(0.6);
			nana_sprite->setTexture("character/nana/1.png");
			nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
		}
		if (HomeMenu::nilai_teks == 248)
		{
			nana();
			teks = __String::createWithFormat("\"Sudah sejak lama juga aku memiliki hal yang ingin \naku lakukan. Jadi aku berharap Rei mau melakukannya bersamaku.\"")->getCString();
			teks_1->setString(teks);
			nana_sprite->setScale(0.6);
			nana_sprite->setTexture("character/nana/2.png");
			nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
		}
		if (HomeMenu::nilai_teks == 249)
		{
			hiden_character();
			nama_kosong();
			teks = __String::createWithFormat("Hal yang ingin dilakukan ya. Benar juga,\nselama ini aku tidak pernah memiliki hal seperti itu.")->getCString();
			teks_1->setString(teks);
			 
		}
		if (HomeMenu::nilai_teks == 250)
		{
			nama_kosong();
			teks = __String::createWithFormat("Aku hanya mengikuti arus kehidupanku.\nImpian dan cita-cita, sejak kapan aku mulai tidak memikirkannya.")->getCString();
			teks_1->setString(teks);
			 
		}
		if (HomeMenu::nilai_teks == 251)
		{
			nama_kosong();
			teks = __String::createWithFormat("Aku rasa sekarang saatnya.\nAkhirnya tiba juga waktuku untuk membuat keputusan.")->getCString();
			teks_1->setString(teks);
			 
		}
		if (HomeMenu::nilai_teks == 252)
		{
			nama_kosong();
			teks = __String::createWithFormat("Sebuah keputusan sepele, yang dari kemarin aku besar-besarkan \nhingga membuatku gelisah sampai sekarang.")->getCString();
			teks_1->setString(teks);
			 
		}
		if (HomeMenu::nilai_teks == 253)
		{
			nama_kosong();
			teks = __String::createWithFormat("Tapi aku telah memikirkannya dan memutuskan.")->getCString();
			teks_1->setString(teks);
			 
		}
}


void Scene5::quit_yes(Ref* sender)
{
	HomeMenu::btn_sound();
	HomeMenu::nilai_logo = true;

	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		Director::getInstance()->replaceScene(TransitionFade::create(3, HomeMenu::scene(), Color3B(255, 255, 255)));
	})));
} //button tekan exit yes

void Scene5::quit_no(Ref* sender)
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
void Scene5::teksJalan(float dt)
{

	teks_satu();
}

void Scene5::teks_satu()
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
		unschedule(schedule_selector(Scene5::teksJalan));
	}
}

void Scene5::rei()
{
	auto teks_nama = __String::createWithFormat("Rei")->getCString();
	nama->setString(teks_nama);
}
void Scene5::anna()
{
	auto teks_nama = __String::createWithFormat("Anna")->getCString();
	nama->setString(teks_nama);
}
void Scene5::nana()
{
	auto teks_nama = __String::createWithFormat("Nana")->getCString();
	nama->setString(teks_nama);
}
void Scene5::nama_kosong()
{
	auto teks_nama = __String::createWithFormat("")->getCString();
	nama->setString(teks_nama);
}
void Scene5::nama_titik()
{
	auto teks_nama = __String::createWithFormat("......")->getCString();
	nama->setString(teks_nama);
}
void Scene5::wali()
{
	auto teks_nama = __String::createWithFormat("Wali Kelas")->getCString();
	nama->setString(teks_nama);
}


