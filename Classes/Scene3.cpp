#include "Scene3.h"
#include "Scene4.h"
#include "Option.h"
#include "HomeMenu.h"
#include "SaveGame.h"
#include "LoadGame.h"

USING_NS_CC;

Scene* Scene3::scene()
{
	return Scene3::create();
}

bool Scene3::init()
{
	if (!Scene::init())
	{
		return false;
	}
	bgm->playBackgroundMusic("music/3.mp3", true);
	HomeMenu::game = 7;
	

	//background//
	background->setPosition(Vec2(0, 0));
	background->setAnchorPoint(Vec2(0, 0));
	this->addChild(background);

	background->setScale(1);
	/////////////

	this->schedule(schedule_selector(Scene3::delay_game), 1);

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
	btn_load->addClickEventListener(CC_CALLBACK_1(Scene3::load_game, this));
	btn_save->addClickEventListener(CC_CALLBACK_1(Scene3::save_game, this));
	btn_config->addClickEventListener(CC_CALLBACK_1(Scene3::config, this));
	btn_exit_no->addClickEventListener(CC_CALLBACK_1(Scene3::quit_no, this));
	btn_exit_yes->addClickEventListener(CC_CALLBACK_1(Scene3::quit_yes, this));
	btn_tittle->addClickEventListener(CC_CALLBACK_1(Scene3::back_title, this));
	btn_close->addClickEventListener(CC_CALLBACK_1(Scene3::close_menu, this));
	buttonStart->addClickEventListener(CC_CALLBACK_1(Scene3::startGame, this));
	btn_menu->addClickEventListener(CC_CALLBACK_1(Scene3::pil_menu, this));

	//gambar karakter//
	anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2+50));
	nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2+50));
	hiden_character();
	this->addChild(nana_sprite);
	this->addChild(anna_sprite);
	//////////////////

	//background//
		if (HomeMenu::nilai_teks > 23 && HomeMenu::nilai_teks < 55)
			background->setTexture("bg/lab_jaringan.jpg");
		else if (HomeMenu::nilai_teks > 54 && HomeMenu::nilai_teks < 145)
			background->setTexture("bg/kafe.jpg");
		else if (HomeMenu::nilai_teks > 144)
			background->setTexture("bg/kamar.jpg");
	/////////////
	return true;
}
void Scene3::hiden_character()
{
	anna_sprite->setScale(0);
	nana_sprite->setScale(0);
}
void Scene3::delay_game(float dt)
{
	detik++;

	if (detik == 4)
	{
		isi_teks();
		this->schedule(schedule_selector(Scene3::teksJalan), Option::speed_teks);
		unschedule(schedule_selector(Scene3::delay_game));
		detik = 0;
	}
	else if (detik == 3)
		buttonStart->setScale(1);
}


void Scene3::pil_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1400, 780)));
	btn_menu->setScale(0);

}

void Scene3::close_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1600, 780)));
	btn_menu->setScale(1);
}

void Scene3::back_title(Ref* sender)
{

	HomeMenu::btn_sound();
	bg_exit->setScale(1);
	kosong->setScale(1);
	btn_exit_no->setScale(1);
	btn_exit_yes->setScale(1);
	label_quit_no->setScale(1);
	label_quit_yes->setScale(1);

}

void Scene3::config(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, Option::scene(), Color3B(255, 255, 255)));
	})));

}
void Scene3::save_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, SaveGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene3::load_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, LoadGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene3::delay(float dt)
{
	if (detik == 1)
	{
		unschedule(schedule_selector(Scene3::delay));
		buttonStart->setScale(1);
		if (HomeMenu::nilai_teks == 24 || HomeMenu::nilai_teks == 55 || HomeMenu::nilai_teks == 145)
		{
			this->schedule(schedule_selector(Scene3::teksJalan), Option::speed_teks);
		}
		detik = 0;
	}
	detik++;
}
void Scene3::startGame(Ref* sender)
{
	unschedule(schedule_selector(Scene3::teksJalan));
	HomeMenu::btn_sound();
	HomeMenu::nilai_teks++;
	isi_teks();
	teks_1->setOpacity(0);
	i = 0;
	log("Nilai teks = %d", HomeMenu::nilai_teks);
	if (HomeMenu::nilai_teks == 24 || HomeMenu::nilai_teks == 55 || HomeMenu::nilai_teks == 145)
	{
		buttonStart->setScale(0);
		if (HomeMenu::nilai_teks > 23 && HomeMenu::nilai_teks < 55)
			background->setTexture("bg/lab_jaringan.jpg");
		else if (HomeMenu::nilai_teks > 54 && HomeMenu::nilai_teks < 145)
			background->setTexture("bg/kafe.jpg");
		else if (HomeMenu::nilai_teks > 144)
			background->setTexture("bg/kamar.jpg");
		this->schedule(schedule_selector(Scene3::delay), 1.f);
	}
	else if (HomeMenu::nilai_teks == 158)
	{
		HomeMenu::nilai_teks = 1;
		this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
		{
			Director::getInstance()->replaceScene(TransitionFade::create(3, Scene4::scene(), Color3B(255, 255, 255)));
		})));
	}
	else
		this->schedule(schedule_selector(Scene3::teksJalan), Option::speed_teks);

}

void Scene3::isi_teks()
{
	if (HomeMenu::nilai_teks == 1)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sesampainya di rumah, aku langsung merebahkan \ndiriku di kasur.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 2)
	{
		nama_kosong();
		teks = __String::createWithFormat("Jalan-jalan kampus tadi membuatku pulang di jam sibuk. Yang berarti \naku harus berdiri selama satu jam lebih selama di bus dan di halte.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 3)
	{
		nama_kosong();
		teks = __String::createWithFormat("Benar-benar hari pertama semester yang tidak \nsesuai perkiraanku")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 4)
	{
		nama_kosong();
		teks = __String::createWithFormat("Setelah beberapa menit berbaring, \naku bangkit lagi untuk menyalakan laptop dan bermain game.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 5)
	{
		nama_kosong();
		teks = __String::createWithFormat("Namun ketika hendak mengeluarkan laptop, \naku menyadari lampu notifikasi ponselku berkedip-kedip.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 6)
	{	
		nama_kosong();
		teks = __String::createWithFormat("Aku membuka pesan yang masuk:")->getCString();
		teks_1->setString(teks);
		
	}
	else if (HomeMenu::nilai_teks == 7)
	{
		nama_kosong();
		teks = __String::createWithFormat("'Selamat sore Rei. Jangan lupa besok mulai kerja lagi. \nShift sore kan?'")->getCString();
		teks_1->setString(teks);
		
	}
	else if (HomeMenu::nilai_teks == 8)
	{	
		nama_kosong();
		teks = __String::createWithFormat("Itu adalah pesan dari pemilik kafe tempatku bekerja \nparuh waktu.")->getCString();
		teks_1->setString(teks);
		
	}
	else if (HomeMenu::nilai_teks == 9)
	{	
		nama_kosong();
		teks = __String::createWithFormat("Sewaktu aku sedang berkeliling di sekitar pusat kota untuk mengganti \nbaterai ponselku yang rusak, ---")->getCString();
		teks_1->setString(teks);
	
	}
	else if (HomeMenu::nilai_teks == 10)
	{
		nama_kosong();
		teks = __String::createWithFormat("aku melewati kafe yang menempelkan poster lowongan \npekerjaan.")->getCString();
		teks_1->setString(teks);
		
	}
	else if (HomeMenu::nilai_teks == 11)
	{
		nama_kosong();
		teks = __String::createWithFormat("Awalnya aku tidak tertarik untuk bekerja paruh waktu.\nNamun setelah mempertimbangkan beberapa hal ---")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 12)
	{
		nama_kosong();
		teks = __String::createWithFormat("seperti jadwalnya yang bisa disesuaikan dengan jadwal kuliahku,\nserta bayarannya yang aku rasa pantas, ---")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 13)
	{
		nama_kosong();
		teks = __String::createWithFormat("aku akhirnya mulai bekerja di sana sejak tahun lalu.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 14)
	{
		nama_kosong();
		teks = __String::createWithFormat("'Iya mas Karya. Siap.' \naku mengirimkan pesan balasanku.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 15)
	{
		nama_kosong();
		 
		teks = __String::createWithFormat("Dan juga.. aku butuh uang untuk membayar uang kuliahku.\nSayangnya aku tidak cukup pintar untuk mendapatkan beasiswa.")->getCString();
		teks_1->setString(teks);

	}
	else if (HomeMenu::nilai_teks == 16)
	{
		nama_kosong();
		teks = __String::createWithFormat("Jadi dengan bekerja, aku bisa membayar uang kuliahku \nsendiri.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 17)
	{
		nama_kosong();
		teks = __String::createWithFormat("Untungnya, uang kuliah di Polines menyesuaikan kondisi \nkeuangan tiap keluarga.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 18)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku benar-benar terbantu karena sistem itu, \nmeskipun tidak mendapat beasiswa.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 19)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sebelum mulai bermain game, \naku memutuskan untuk mencari celemek kerjaku.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 20)
	{
		nama_kosong();
		teks = __String::createWithFormat("Bulan lalu aku meminta tolong mas Karya untuk \nmemberikanku waktu libur.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 21)
	{
		nama_kosong();
		teks = __String::createWithFormat("Banyak sekali tugas-tugas yang menumpuk di akhir semester lalu,\nkarena itu aku tidak sempat bekerja.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 22)
	{
		nama_kosong();
		teks = __String::createWithFormat("Untungnya keponakan mas Karya bisa menggantikanku \nselama aku tidak masuk kerja.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 23)
	{
		nama_kosong();
		teks = __String::createWithFormat("Setelah menemukan celemek kerjaku di antara tumpukan pakaian, \naku memasukkannya ke dalam tas dan segera bermain game.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 24)
	{
		nama_kosong();
		teks = __String::createWithFormat("Hari ini, kuliah sama persis seperti kemarin.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 25)
	{
		nama_kosong();
		teks = __String::createWithFormat("Diisi dengan penyampaian kontrak kuliah untuk semester ini,\nlagi-lagi kantuk yang hebat menyerangku.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 26)
	{
		nama_kosong();
		teks = __String::createWithFormat("Untuk minggu pertama ini saja,\naku rasa aku boleh seperti ini.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 27)
	{
		nama_kosong();
		teks = __String::createWithFormat("Kemarin aku bermain sampai jam satu pagi. Alur ceritanya yang \nseru membuatku ingin terus bermain hingga akhir.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 28)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sayangnya untuk hari ini, aku harus bekerja terlebih dahulu \nsebelum bisa bermain game lainnya.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 29)
	{
		anna();
		teks = __String::createWithFormat("\"Rei..!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 30)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ah. Tidak. Tidak lagi.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 31)
	{
		anna();
		teks = __String::createWithFormat("\"Kamu pasti luang kan?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 32)
	{
		rei();
		teks = __String::createWithFormat("\"Tidak, tidak untuk hari ini. \nDan hari-hari besoknya juga.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 33)
	{
		anna();
		teks = __String::createWithFormat("\"Jadi, hari ini aku ingin kamu menemani Nana \njalan-jalan lagi.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 34)
	{
		nama_kosong();
		teks = __String::createWithFormat("Orang ini benar-benar tidak mendengarkan.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 35)
	{
		anna();
		teks = __String::createWithFormat("\"Sebenarnya, aku ingin menemaninya, tapi \nsayangnya aku harus pergi hari ini.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 36)
	{
		rei();
		teks = __String::createWithFormat("\"Aku juga harus pergi. Aku tidak bercanda.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 37)
	{
		anna();
		teks = __String::createWithFormat("\"Kemana?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 38)
	{
		rei();
		teks = __String::createWithFormat("\"Yah.. itu, ke suatu tempat.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 39)
	{
		anna();
		teks = __String::createWithFormat("\"Kamu tidak pandai membuat alasan.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 40)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Entah kenapa, aku tidak ingin memberi tahu siapapun \nkalau aku bekerja di kafe.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 41)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku rasa bukan karena malu. Tapi.. \nselama bisa aku sembunyikan akan aku sembunyikan.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 42)
	{
		rei();
		teks = __String::createWithFormat("\"Aku sudah cukup banyak membantu kemarin.\nKamu bisa minta tolong yang lain.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 43)
	{
		nana();
		teks = __String::createWithFormat("\"Mungkin lain kali saja.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 44)
	{
		rei();
		teks = __String::createWithFormat("\"Ya, benar sekali. Lain kali saja.\nTidak harus hari ini juga kan?\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 45)
	{
		anna();
		teks = __String::createWithFormat("\"Rasanya, lebih cepat Nana kenal lingkungan kampus \nkita lebih baik.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 46)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Sebelum aku membuang lebih banyak waktu,\naku segera keluar kelas.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 47)
	{
		rei();
		teks = __String::createWithFormat("\"Aku tidak akan ikut dalam acara jalan-jalan lagi.\nSudah ya, aku pergi dulu.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 48)
	{
		anna();
		teks = __String::createWithFormat("\"Mau bagaimana lagi. Sepertinya Rei tidak berbohong kalau mau \npergi ke suatu tempat.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 49)
	{
		anna();
		teks = __String::createWithFormat("\"Tapi.. kemana ya? Dia tidak ikut ormawa, tidak mungkin \njuga punya pacar.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 50)
	{
		nana();
		teks = __String::createWithFormat("\"Rasanya agak jahat kalau bilang Rei tidak mungkin punya \npacar.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 51)
	{
		anna();
		teks = __String::createWithFormat("\"Baiklah, maaf ya, kita jalan-jalan lain waktu saja. \nAku mau ke pusat kota untuk memperbaiki baterai ponselku yang rusak.\"")->getCString();
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
		nana();
		teks = __String::createWithFormat("\"Iya. Tidak apa-apa Anna.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 53)
	{
		anna();
		teks = __String::createWithFormat("\"Sampai jumpa besok.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setScaleX(-0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 54)
	{
		hiden_character();
		nana();
		teks = __String::createWithFormat("\"Sampai jumpa.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 55)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Sesampainya di kafe, aku menyapa karyawan lain yang telah lama tidak \naku temui.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 56)
	{
		nama_kosong();
		teks = __String::createWithFormat("Setelah sedikit berbincang, aku kemudian menuju ke ruang \nkaryawan di belakang. Sepertinya mas Karya tidak ada di sini.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 57)
	{
		nama_kosong();
		teks = __String::createWithFormat("Kedatangan dan lamanya dia menghabiskan waktu di kafenya \nsendiri memang tidak pasti.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 58)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dari perbincangan yang kami lakukan sebelumnya, \naku tahu bahwa dia adalah wirausahawan. \nKafe ini salah satu usahanya.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 59)
	{
		nama_kosong();
		teks = __String::createWithFormat("Kesehariannya adalah berkeliling dari satu toko-ke-toko \nlainnya untuk memantau usahanya. Terkadang bertemu pelanggan \nyang ingin Membeli banyak produk atau kerjasama.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 60)
	{
		nama_kosong();
		teks = __String::createWithFormat("Setelah beberapa kali kami bertukar kata,\naku jadi berkeinginan memiliki usaha sendiri nanti.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 61)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tentunya memulai usaha selain memerlukan modal juga \npenuh kegagalan dan rintangan. Tapi bila sudah berhasil, ---")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 62)
	{
		nama_kosong();
		teks = __String::createWithFormat("Uang bisa mengalir sembari aku bermain game.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 63)
	{
		nama_kosong();
		teks = __String::createWithFormat("Setelah menyadarkan diri dari mimpi, aku mengenakan \ncelemek kerjaku dan segera mulai bekerja.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 64)
	{
		nama_kosong();
		teks = __String::createWithFormat("Membawa buku menu dan catatan, aku menghampiri \npelanggan yang baru saja datang.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 65)
	{
		nama_kosong();
		teks = __String::createWithFormat("Di sore hari seperti ini, yang menjadi pelanggan kami adalah \npekerja kantor atau keluarga yang ingin bersantai bersama.")->getCString();
		teks_1->setString(teks);
	}
	if (HomeMenu::nilai_teks == 66)
	{
		nama_kosong();
		teks = __String::createWithFormat("Anak-anak muda biasanya baru datang setelah \njam 6 sore atau setelahnya.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 67)
	{
		nama_kosong();
		teks = __String::createWithFormat("Setelah tidak banyak yang bisa aku lakukan,\naku berdiri di belakang counter, menunggu pelanggan lain datang.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 68)
	{
		nama_kosong();
		teks = __String::createWithFormat("Rasanya aku ingin minum sesuatu.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 69)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tentunya karena kopi di sini mahal, aku tidak bisa seenaknya \nmembuat kopi untukku sendiri. Tapi kami diperbolehkan \nminum teh.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 70)
	{
		nama_kosong();
		teks = __String::createWithFormat("Namun ketika hendak mengambil teh, seorang pelanggan masuk.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 71)
	{
		rei();
		teks = __String::createWithFormat("\"Selamat data-\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 72)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku terkejut melihat pelanggan yang baru saja masuk.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 73)
	{
		nama_kosong();
		teks = __String::createWithFormat("Bukan karena dia orang terkenal..")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 74)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ah. Mungkin dia cukup terkenal di prodiku.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 75)
	{
		nama_kosong();
		teks = __String::createWithFormat("Pelanggan tersebut adalah orang yang terakhir \nkali aku harapkan untuk datang di kafe ini.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 76)
	{
		anna();
		teks = __String::createWithFormat("\"Wah, ternyata benar-benar Rei!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 77)
	{
		nama_kosong();
		teks = __String::createWithFormat("Suaramu kurang keras Anna.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 78)
	{
		nama_kosong();
		teks = __String::createWithFormat("Wajahnya benar-benar berseri-seri. Takjub. Seperti \nsedang melihat spesies yang hampir punah di kebun binatang.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 79)
	{
		anna();
		teks = __String::createWithFormat("\"Wahh!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 80)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku segera menghampirinya.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 81)
	{
		rei();
		teks = __String::createWithFormat("\"Tenanglah sedikit. Kamu mengganggu pelanggan lainnya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 82)
	{
		anna();
		teks = __String::createWithFormat("\"Wah! Kamu cocok juga memakai celemek itu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 83)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dia tidak mendengarkanku lagi seperti biasa.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 84)
	{
		rei();
		teks = __String::createWithFormat("\"Sendirian?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 85)
	{
		anna();
		teks = __String::createWithFormat("\"Iya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 86)
	{
		nama_kosong();
		teks = __String::createWithFormat("Wajahnya masih tersenyum lebar.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 87)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku sendiri juga pernah membayangkan bagaimana \nreaksinya bila melihatku menggunakan pakaian seperti ini.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 88)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku kira ia akan tertawa terbahak-bahak.\nJadi aku cukup bersyukur dengan reaksinya yang sekarang.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 89)
	{
		rei();
		teks = __String::createWithFormat("\"Mau duduk di sebelah mana?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 90)
	{
		anna();
		teks = __String::createWithFormat("\"Di counter!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 91)
	{
		rei();
		teks = __String::createWithFormat("\"Ba-baiklah.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 92)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku sudah menduganya sih.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 93)
	{
		rei();
		teks = __String::createWithFormat("\"Ini daftar menunya. Silahkan beri \ntahu saya apabila sudah memilih.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 94)
	{
		anna();
		teks = __String::createWithFormat("\"Ahahahaha! Bicaramu formal sekali.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 95)
	{
		rei();
		teks = __String::createWithFormat("\"Ah, ma-maaf, kebiasaan.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 96)
	{
		anna();
		teks = __String::createWithFormat("\"Ehehee.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 97)
	{
		rei();
		teks = __String::createWithFormat("\"Berhenti melihatku seperti itu,\nsegera pilih menunya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 98)
	{
		anna();
		teks = __String::createWithFormat("\"Yah, aku benar-benar tidak menyangka kalau kamu kerja di kafe.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 99)
	{
		anna();
		teks = __String::createWithFormat("\"Hm.. aku agak bingung. Ada rekomendasi?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
		 
	}
	else if (HomeMenu::nilai_teks == 100)
	{
		rei();
		teks = __String::createWithFormat("\"Kopi Susu?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 101)
	{
		anna();
		teks = __String::createWithFormat("\"Namanya memang kopi susu? Aku pikir nama menu \ndi kafe seperti ini lebih keren.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 102)
	{
		rei();
		teks = __String::createWithFormat("\"Aku tidak yakin apa lidahmu cocok \ndengan minuman yang namanya keren.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 103)
	{
		anna();
		teks = __String::createWithFormat("\"Kamu mengejekku ya?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 104)
	{
		rei();
		teks = __String::createWithFormat("\"Tidak, aku serius. Aku pernah mencoba salah satu \nespresso di sini dan aku terkejut dengan rasanya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 105)
	{
		anna();
		teks = __String::createWithFormat("\"Baiklah. Aku pesan kopi susu saja.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
		 
	}
	if (HomeMenu::nilai_teks == 106)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Setelah aku menyampaikan pesanan Anna di dapur, \naku kembali ke tempat Anna berada karena ia memanggilku.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 107)
	{
		anna();
		teks = __String::createWithFormat("\"Aku kira kamu yang akan membuat kopinya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 108)
	{
		rei();
		teks = __String::createWithFormat("\"Aku bisa sih, tapi aku bagianku bukan sebagai chef di sini.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 109)
	{
		anna();
		teks = __String::createWithFormat("\"Sejak kapan kamu kerja di sini?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
		 
	}
	if (HomeMenu::nilai_teks == 110)
	{
		rei();
		teks = __String::createWithFormat("\"Tahun lalu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
		 
	}
	if (HomeMenu::nilai_teks == 111)
	{
		anna();
		teks = __String::createWithFormat("\"Eh?! Lama sekali! Kamu tidak pernah cerita.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 112)
	{
		rei();
		teks = __String::createWithFormat("\"Aku hanya tidak merasa perlu untuk cerita.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 113)
	{
		anna();
		teks = __String::createWithFormat("\"Kalau aku tidak sengaja kesini,\naku tidak pernah tahu dong.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 114)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku memang berharap kamu tidak pernah tahu.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 115)
	{
		rei();
		teks = __String::createWithFormat("\"Oh ya, kenapa kamu bisa sampai di sini? \nKafe ini kan jauh dari kampus.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 116)
	{
		nama_kosong();
		teks = __String::createWithFormat("Lokasinya yang jauh dari kampus memang seharusnya membuat \nrahasiaku ini tidak pernah diketahui teman-temanku.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 117)
	{
		anna();
		teks = __String::createWithFormat("\"Baterai ponselku rusak,\njadi aku harus pergi ke service centre di tengah kota ---\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 118)
	{
		anna();
		teks = __String::createWithFormat("\"Dan, ketika pulang, aku tidak sengaja \nmelewati kafe ini dan melihatmu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 119)
	{
		nama_kosong();
		teks = __String::createWithFormat("Rasanya ceritanya mirip sekali dengan pengalaman seseorang.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 120)
	{
		rei();
		teks = __String::createWithFormat("\"Pesanan Anda, kopi susu silahkan dinikmati\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 121)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku melihat Anna tersenyum lebar.\nSial. Lagi-lagi kebiasaanku.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 122)
	{
		anna();
		teks = __String::createWithFormat("\"Wah, benar-benar enak.\nTebakanmu hebat ya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 123)
	{
		anna();
		teks = __String::createWithFormat("\"Aku suka.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 124)
	{
		rei();
		teks = __String::createWithFormat("\"Eh?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 125)
	{
		rei();
		teks = __String::createWithFormat("\"Ah.. syukurlah.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 126)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Aku sekilas salah memahami kata 'suka' yang Anna katakan.\nAku jadi malu sendiri. Benar- benar bodoh.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 127)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sebenarnya, aku hanya memilih menu yang sering \ndipesan gadis seumurannya. Tapi syukurlah ia menyukainya.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 128)
	{
		anna();
		teks = __String::createWithFormat("\"Sampai jam berapa kamu kerja?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 129)
	{
		rei();
		teks = __String::createWithFormat("\"Jam 7\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 130)
	{
		anna();
		teks = __String::createWithFormat("\"Jadi masih sempat naik bis ya?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 131)
	{
		rei();
		teks = __String::createWithFormat("\"Iya, tentunya aku sudah memikirkannya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 132)
	{
		anna();
		teks = __String::createWithFormat("\"Hari apa saja kamu kerja?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 133)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku tidak yakin apakah aku sebaiknya menjawabnya atau tidak.\nTapi, dia sudah terlanjur tahu. Jadi aku rasa tidak apa-apa.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 134)
	{
		rei();
		teks = __String::createWithFormat("\"Hampir setiap hari. Karena jam kerjaku juga pendek.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 135)
	{
		anna();
		teks = __String::createWithFormat("\"Wah, aku pikir setiap hari kamu langsung pulang dan \nmain game.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 136)
	{
		rei();
		teks = __String::createWithFormat("\"Sebenarnya, itu yang aku inginkan.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 137)
	{
		anna();
		teks = __String::createWithFormat("\"Hei, kamu sudah terlihat keren, jangan di sia-siakan.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 138)
	{
		rei();
		teks = __String::createWithFormat("\"Ha?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 139)
	{
		anna();
		teks = __String::createWithFormat("\"Kalau begitu, aku pulang dulu hari ini.\nMungkin aku akan datang bersama Nana lain kali.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 140)
	{
		rei();
		teks = __String::createWithFormat("\"Eh? Jangan oi-.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 141)
	{
		anna();
		teks = __String::createWithFormat("\"Ini uangnya. Terimakasih. Dadah..\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 142)
	{
		hiden_character();
		rei();
		teks = __String::createWithFormat("\"Bayarnya bukan di sini-\"")->getCString();
		teks_1->setString(teks);
	}
	if (HomeMenu::nilai_teks == 143)
	{
		nama_kosong();
		teks = __String::createWithFormat("Terserahlah. Berdebatpun, kalau dia sudah \nmemutuskan tidak akan bisa aku hentikan.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 144)
	{
		nama_kosong();
		teks = __String::createWithFormat("Setelah Anna pulang, aku membereskan cangkirnya \ndan membuat teh untukku yang aku tunda.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 145)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sesampainya di rumah, aku langsung merebahkan diriku di kasur.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 146)
	{
		nama_kosong();
		teks = __String::createWithFormat("Setelah sebulan tidak kerja, akhir hari ini menjadi \nterasa sangat melelahkan.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 147)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sampai-sampai, aku sempat ketiduran di bus hingga \nhampir saja melewati halteku turun.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 148)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tapi, tubuhku memiliki tenaga yang berbeda untuk game!")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 149)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku bangkit dan mempersiapkan laptopku untuk bermain game.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 150)
	{
		nama_kosong();
		teks = __String::createWithFormat("Namun ketika hendak menyalakan laptop, entah kenapa,\naku berpikir lebih waras.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 151)
	{
		nama_kosong();
		teks = __String::createWithFormat("Kemarin, aku memulai hari pertamaku dengan rasa letih \nsejak pagi karena bermain game hingga pagi.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 152)
	{
		nama_kosong();
		teks = __String::createWithFormat("Pulangnya, aku menemani Nana keliling kampus yang berujung \npada kepulanganku di jam sibuk.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 153)
	{
		nama_kosong();
		teks = __String::createWithFormat("Malamnya, aku bermain game hingga pagi, dan memulai hari ini \nsama persis dengan kemarin.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 154)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ditambah, adalah hari pertamaku kerja setelah \nsekian lama.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 155)
	{
		nama_kosong();
		teks = __String::createWithFormat("Pikiranku jadi dipenuhi rasa takut.\nAku.. tidak ingin mati muda.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 156)
	{
		nama_kosong();
		teks = __String::createWithFormat("Akhirnya, aku menutup kembali laptopku dan mematikan \nlampu kamarku.")->getCString();
		teks_1->setString(teks);
		 
	}
	if (HomeMenu::nilai_teks == 157)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku tidak ingin mati muda.")->getCString();
		teks_1->setString(teks);
		 
	}
}



void Scene3::quit_yes(Ref* sender)
{
	HomeMenu::btn_sound();
	HomeMenu::nilai_logo = true;

	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		Director::getInstance()->replaceScene(TransitionFade::create(3, HomeMenu::scene(), Color3B(255, 255, 255)));
	})));
} //button tekan exit yes

void Scene3::quit_no(Ref* sender)
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
void Scene3::teksJalan(float dt)
{

	teks_satu();
}

void Scene3::teks_satu()
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
		unschedule(schedule_selector(Scene3::teksJalan));
	}
}

void Scene3::rei()
{
	auto teks_nama = __String::createWithFormat("Rei")->getCString();
	nama->setString(teks_nama);
}
void Scene3::anna()
{
	auto teks_nama = __String::createWithFormat("Anna")->getCString();
	nama->setString(teks_nama);
}
void Scene3::nana()
{
	auto teks_nama = __String::createWithFormat("Nana")->getCString();
	nama->setString(teks_nama);
}
void Scene3::nama_kosong()
{
	auto teks_nama = __String::createWithFormat("")->getCString();
	nama->setString(teks_nama);
}
void Scene3::nama_titik()
{
	auto teks_nama = __String::createWithFormat("......")->getCString();
	nama->setString(teks_nama);
}
void Scene3::wali()
{
	auto teks_nama = __String::createWithFormat("Wali Kelas")->getCString();
	nama->setString(teks_nama);
}


