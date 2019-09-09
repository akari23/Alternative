#include "Scene1b.h"
#include "Scene2.h"
#include "Option.h"
#include "HomeMenu.h"
#include "SaveGame.h"
#include "LoadGame.h"

USING_NS_CC;



Scene* Scene1b::scene()
{
	return Scene1b::create();
}

bool Scene1b::init()
{
	if (!Scene::init())
	{
		return false;
	}
	bgm->playBackgroundMusic("music/1b.mp3", true);
	HomeMenu::game = 3;


	//background//
	background->setPosition(Vec2(0, 0));
	background->setAnchorPoint(Vec2(0, 0));
	this->addChild(background);
	background->setScale(1);
	/////////////

	this->schedule(schedule_selector(Scene1b::delay_game), 1);

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
	btn_load->addClickEventListener(CC_CALLBACK_1(Scene1b::load_game, this));
	btn_save->addClickEventListener(CC_CALLBACK_1(Scene1b::save_game, this));
	btn_config->addClickEventListener(CC_CALLBACK_1(Scene1b::config, this));
	btn_exit_no->addClickEventListener(CC_CALLBACK_1(Scene1b::quit_no, this));
	btn_exit_yes->addClickEventListener(CC_CALLBACK_1(Scene1b::quit_yes, this));
	btn_tittle->addClickEventListener(CC_CALLBACK_1(Scene1b::back_title, this));
	btn_close->addClickEventListener(CC_CALLBACK_1(Scene1b::close_menu, this));
	buttonStart->addClickEventListener(CC_CALLBACK_1(Scene1b::startGame, this));
	btn_menu->addClickEventListener(CC_CALLBACK_1(Scene1b::pil_menu, this));
	///////////////////////////////

	//gambar karakter//
	anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2+50));
	nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2+50));
	hiden_character();
	this->addChild(nana_sprite);
	this->addChild(anna_sprite);
	//////////////////

		if (HomeMenu::nilai_teks > 16)
			background->setTexture("bg/gazebo.jpg");
	return true;
}
void Scene1b::hiden_character()
{
	anna_sprite->setScale(0);
	nana_sprite->setScale(0);
}
void Scene1b::delay_game(float dt)
{
	detik++;

	if (detik == 4)
	{
		isi_teks();
		this->schedule(schedule_selector(Scene1b::teksJalan), Option::speed_teks);
		unschedule(schedule_selector(Scene1b::delay_game));
		detik = 0;
	}
	else if (detik == 3)
		buttonStart->setScale(1);
}


void Scene1b::pil_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1400, 780)));
	btn_menu->setScale(0);

}

void Scene1b::close_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1600, 780)));
	btn_menu->setScale(1);
}

void Scene1b::back_title(Ref* sender)
{

	HomeMenu::btn_sound();
	bg_exit->setScale(1);
	kosong->setScale(1);
	btn_exit_no->setScale(1);
	btn_exit_yes->setScale(1);
	label_quit_no->setScale(1);
	label_quit_yes->setScale(1);

}

void Scene1b::config(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, Option::scene(), Color3B(255, 255, 255)));
	})));

}
void Scene1b::save_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, SaveGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene1b::load_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, LoadGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene1b::delay(float dt)
{
	if (detik == 1)
	{
		isi_teks();
		unschedule(schedule_selector(Scene1b::delay));
		buttonStart->setScale(1);
		if (HomeMenu::nilai_teks == 17)
		{isi_teks();
			this->schedule(schedule_selector(Scene1b::teksJalan), Option::speed_teks);
			nana_sprite->setScale(0.6);
		}
		detik = 0;
	}
	detik++;
}
void Scene1b::startGame(Ref* sender)
{
	unschedule(schedule_selector(Scene1b::teksJalan));
	if (!textSelesai)
	{
		textSelesai = true;
		this->schedule(schedule_selector(Scene1b::teksJalan),0);
	}
	else
	{
		textSelesai = false;
		HomeMenu::nilai_teks++;
		
		teks_1->setOpacity(0);
		i = 0;
		log("Nilai teks = %d", HomeMenu::nilai_teks);
		if (HomeMenu::nilai_teks == 17)
		{
			background->setTexture("bg/gazebo.jpg");
			hiden_character();
			buttonStart->setScale(0);
			this->schedule(schedule_selector(Scene1b::delay), 1.f);
		}
		else if (HomeMenu::nilai_teks == 31)
		{
			HomeMenu::nilai_teks = 1;
			this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
			{
				Director::getInstance()->replaceScene(TransitionFade::create(3, Scene2::scene(), Color3B(255, 255, 255)));
			})));
			log(HomeMenu::nilai_teks);
		}
		else
		{
			isi_teks();
			this->schedule(schedule_selector(Scene1b::teksJalan), Option::speed_teks);
		}
			
	}
	
	HomeMenu::btn_sound();
}

void Scene1b::isi_teks()
{
	if (HomeMenu::nilai_teks == 1)
	{
		nama_kosong();
		teks = __String::createWithFormat("Masa bodoh. Aku pulang.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 2)
	{
		nama_kosong();
		teks = __String::createWithFormat("Bagaimanapun, permintaan tolong Anna itu memang \nbenar-benar suatu hal yang mustahil aku lakukan.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 3)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dia seharusnya tahu sendiri.\nAku ini jarang sekali berkomunikasi dengan orang lain.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 4)
	{
		nama_kosong();
		teks = __String::createWithFormat("Kalau saja tidak ada Anna, aku rasa aku bisa \ntidak mengucapkan sepatah katapun dalam sehari.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 5)
	{
		nama_kosong();
		teks = __String::createWithFormat("Anna selalu menghabiskan sebagian tenagaku yang berharga \nuntuk berbicara dengannya.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 6)
	{
		nama_kosong();
		teks = __String::createWithFormat("Memikirkan hal itu dalam benakku, membuatku sedikit merasa \nmenyesal dengan keputusanku barusan.")->getCString();
		teks_1->setString(teks);

	}
	else if (HomeMenu::nilai_teks == 7)
	{
		nama_kosong();
		teks = __String::createWithFormat("Entah kenapa. Rasanya benar-benar tidak nyaman.")->getCString();
		teks_1->setString(teks);

	}
	else if (HomeMenu::nilai_teks == 8)
	{
		nama_kosong();
		teks = __String::createWithFormat("Mungkin setidaknya aku mencari orang lain untuk menemani Nana..")->getCString();
		teks_1->setString(teks);

	}
	else if (HomeMenu::nilai_teks == 9)
	{
		nama_kosong();
		teks = __String::createWithFormat("Baiklah. Itu yang akan aku lakukan sekarang.")->getCString();
		teks_1->setString(teks);

	}
	else if (HomeMenu::nilai_teks == 10)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ketika aku hendak berbalik arah menuju kelas, \naku melihat Nana duduk di gazebo.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 11)
	{
		nama_kosong();
		teks = __String::createWithFormat("Apa yang dia lakukan di sana?\nApakah dia sedang menunggu Anna?")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");

	}
	else if (HomeMenu::nilai_teks == 12)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sementara aku masih bingung apakah harus kembali ke kelas \natau menghampiri Nana, ia menoleh ke arahku.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 13)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ia tersenyum kecil kepadaku.\nNamun aku hanya diam.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
	}
	else if (HomeMenu::nilai_teks == 14)
	{
		nama_kosong();
		teks = __String::createWithFormat("Eh?! Apa dia ingat wajahku?")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 15)
	{
		nama_kosong();
		teks = __String::createWithFormat("Seingatku kami hanya bertatapan satu kali \nketika perkenalannya di kelas tadi pagi.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");

	}
	else if (HomeMenu::nilai_teks == 16)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku rasa sekarang aku tidak punya pilihan lain \nselain menghampirinya.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 17)
	{
		voice->getInstance()->playEffect("voice/passage1b/17.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Hai, kamu.. Rei ya?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
	}
	else if (HomeMenu::nilai_teks == 18)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Ah.. Hai.. Iya.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 19)
	{
		nama_kosong();
		teks = __String::createWithFormat("Wah. Aku terkejut. Dia bahkan tahu namaku.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 20)
	{
		rei();
		teks = __String::createWithFormat("\"Menunggu Anna?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 21)
	{
		voice->getInstance()->playEffect("voice/passage1b/21.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Eh? Bukan.Loh, kamu tidak diberitahu Anna?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
	}
	else if (HomeMenu::nilai_teks == 22)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Eh? Mengenai apa?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
		 
	}
	else if (HomeMenu::nilai_teks == 23)
	{
		voice->getInstance()->playEffect("voice/passage1b/23.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Loh, kata Anna, kamu yang akan menemaniku berkeliling \ndi kampus.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
	}
	else if (HomeMenu::nilai_teks == 24)
	{
		voice->getInstance()->pauseAllEffects();
		voice->getInstance()->playEffect("voice/passage1b/24.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Tadi.. tadi Anna menyuruhku menunggumu di sini.\nTapi..\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
	}
	else if (HomeMenu::nilai_teks == 25)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Ia terlihat gelisah. Begitu juga aku.\nLalu aku menyadari sesuatu.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/7.png");
	}
	else if (HomeMenu::nilai_teks == 26)
	{
		nama_kosong();
		teks = __String::createWithFormat("Pikiranku tergunjang. Aku berada dalam batas \nantara kagum dan jengkel dengan Anna.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 27)
	{
		nama_kosong();
		teks = __String::createWithFormat("Anna telah memprediksi bahwa aku \nakan menolak permintaannya.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 28)
	{
		nama_kosong();
		teks = __String::createWithFormat("Jadi dia menyuruh Nana untuk menunggu di sini, \nagar berpapasan denganku ketika aku hendak pulang.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 29)
	{
		nama_kosong();
		teks = __String::createWithFormat("Luar biasa.\nJadi inikah kekuatan mahasiswi IPK 4.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
	else if (HomeMenu::nilai_teks == 30)
	{
		nama_kosong();
		teks = __String::createWithFormat("Menyadari perbedaan kecerdasan antara aku dan Anna, \ndengan terpaksa aku menemani mahasiswi pindahan ini \nberkeliling kampus.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
	}
}


void Scene1b::quit_yes(Ref* sender)
{
	HomeMenu::btn_sound();
	HomeMenu::nilai_logo = true;

	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		Director::getInstance()->replaceScene(TransitionFade::create(3, HomeMenu::scene(), Color3B(255, 255, 255)));
	})));
} //button tekan exit yes

void Scene1b::quit_no(Ref* sender)
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
void Scene1b::teksJalan(float dt)
{

	teks_satu();
}

void Scene1b::teks_satu()
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
			unschedule(schedule_selector(Scene1b::teksJalan));
			textSelesai = true;
		}
	}
	else
	{
		teks_1->setOpacity(255);
		teks_1->setColor(Color3B::BLACK);
		unschedule(schedule_selector(Scene1b::teksJalan));
	}
	
}

void Scene1b::rei()
{
	auto teks_nama = __String::createWithFormat("Rei")->getCString();
	nama->setString(teks_nama);
}
void Scene1b::anna()
{
	auto teks_nama = __String::createWithFormat("Anna")->getCString();
	nama->setString(teks_nama);
}
void Scene1b::nana()
{
	auto teks_nama = __String::createWithFormat("Nana")->getCString();
	nama->setString(teks_nama);
}
void Scene1b::nama_kosong()
{
	auto teks_nama = __String::createWithFormat("")->getCString();
	nama->setString(teks_nama);
}
void Scene1b::nama_titik()
{
	auto teks_nama = __String::createWithFormat("......")->getCString();
	nama->setString(teks_nama);
}
void Scene1b::wali()
{
	auto teks_nama = __String::createWithFormat("Wali Kelas")->getCString();
	nama->setString(teks_nama);
}


