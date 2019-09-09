#include "Scene10a.h"
#include "Scene12.h"
#include "Option.h"
#include "HomeMenu.h"
#include "SaveGame.h"
#include "LoadGame.h"
#include "MiniGame2.h"

USING_NS_CC;

Scene* Scene10a::scene()
{
	return Scene10a::create();
}

bool Scene10a::init()
{
	if (!Scene::init())
	{
		return false;
	}
	bgm->playBackgroundMusic("music/10a.mp3", true);
	HomeMenu::game = 16;
	

	//background//
	background->setPosition(Vec2(0, 0));
	background->setAnchorPoint(Vec2(0, 0));
	this->addChild(background);
	/////////////

	this->schedule(schedule_selector(Scene10a::delay_game), 1);

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
	btn_load->addClickEventListener(CC_CALLBACK_1(Scene10a::load_game, this));
	btn_save->addClickEventListener(CC_CALLBACK_1(Scene10a::save_game, this));
	btn_config->addClickEventListener(CC_CALLBACK_1(Scene10a::config, this));
	btn_exit_no->addClickEventListener(CC_CALLBACK_1(Scene10a::quit_no, this));
	btn_exit_yes->addClickEventListener(CC_CALLBACK_1(Scene10a::quit_yes, this));
	btn_tittle->addClickEventListener(CC_CALLBACK_1(Scene10a::back_title, this));
	btn_close->addClickEventListener(CC_CALLBACK_1(Scene10a::close_menu, this));
	buttonStart->addClickEventListener(CC_CALLBACK_1(Scene10a::startGame, this));
	btn_menu->addClickEventListener(CC_CALLBACK_1(Scene10a::pil_menu, this));
	///////////////////////////
	//gambar karakter//
	anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	naomi_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	hiden_character();
	this->addChild(nana_sprite);
	this->addChild(naomi_sprite);
	this->addChild(anna_sprite);
	/////////////////////////
	//background//
	if (HomeMenu::nilai_teks > 98)
		background->setTexture("bg/kamar_anna.jpg");
	/////////////
	return true;
}void Scene10a::hiden_character()
{
	anna_sprite->setScale(0);
	nana_sprite->setScale(0);
	naomi_sprite->setScale(0);
}
void Scene10a::delay_game(float dt)
{
	detik++;

	if (detik == 4)
	{
		isi_teks();
		this->schedule(schedule_selector(Scene10a::teksJalan), Option::speed_teks);
		unschedule(schedule_selector(Scene10a::delay_game));
		detik = 0;
	}
	else if (detik == 3)
		buttonStart->setScale(1);
}


void Scene10a::pil_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1400, 780)));
	btn_menu->setScale(0);

}

void Scene10a::close_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1600, 780)));
	btn_menu->setScale(1);
}

void Scene10a::back_title(Ref* sender)
{

	HomeMenu::btn_sound();
	bg_exit->setScale(1);
	kosong->setScale(1);
	btn_exit_no->setScale(1);
	btn_exit_yes->setScale(1);
	label_quit_no->setScale(1);
	label_quit_yes->setScale(1);

}

void Scene10a::config(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, Option::scene(), Color3B(255, 255, 255)));
	})));

}
void Scene10a::save_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, SaveGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene10a::load_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, LoadGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene10a::delay(float dt)
{
	if (detik == 1)
	{
		unschedule(schedule_selector(Scene10a::delay));
		buttonStart->setScale(1);
		if (HomeMenu::nilai_teks == 99)
		{
			this->schedule(schedule_selector(Scene10a::teksJalan), Option::speed_teks);
		}
		detik = 0;
	}
	detik++;
}
void Scene10a::startGame(Ref* sender)
{
	unschedule(schedule_selector(Scene10a::teksJalan));
	HomeMenu::btn_sound();
	HomeMenu::nilai_teks++;
	isi_teks();
	teks_1->setOpacity(0);
	i = 0;
	log("Nilai teks = %d", HomeMenu::nilai_teks);
	if (HomeMenu::nilai_teks == 20)
	{
		buttonStart->setScale(0);
		if (HomeMenu::nilai_teks > 98)
			background->setTexture("bg/dapur.jpg");
		this->schedule(schedule_selector(Scene10a::delay), 1.f);
	}
	else if (HomeMenu::nilai_teks == 111)
	{
		this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
		{
			Director::getInstance()->replaceScene(TransitionFade::create(3, MiniGame2::createScene(), Color3B(255, 255, 255)));
		})));
	}
	else if (HomeMenu::nilai_teks == 115)
	{
		HomeMenu::nilai_teks = 1;
		this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
		{
			Director::getInstance()->replaceScene(TransitionFade::create(3, Scene12::scene(), Color3B(255, 255, 255)));
		})));
	}
	else
		this->schedule(schedule_selector(Scene10a::teksJalan), Option::speed_teks);

}

void Scene10a::isi_teks()
{
	if (HomeMenu::nilai_teks == 1)
	{
		anna();
		teks = __String::createWithFormat("\"Aku tidak menyangka kamu benar - benar akan datang.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 2)
	{
		rei();
		teks = __String::createWithFormat("\"Aku juga.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 3)
	{
		anna();
		teks = __String::createWithFormat("\"Baguslah kalau Rei masih sedikit khawatir dengan nilainya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 4)
	{
		nama_kosong();
		teks = __String::createWithFormat("Hari ini adalah hari jumat, empat hari setelah Lily mendatangiku ke kelas \nuntuk memaksaku ikut pergi ke gunung. ---")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 5)
	{
		nama_kosong();
		teks = __String::createWithFormat("Acara dari ormawa wapalhi akan dimulai nanti sore hingga Minggu.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 6)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tanggal merah di hari Jum’at ini membuat kami memiliki \ntiga hari libur berturut-turut. Pantas saja banyak ormawa yang juga \nmengadakan event di hari ini.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 7)
	{
		nama_kosong();
		teks = __String::createWithFormat("Kalau saja Anna tidak mendengar mengenai hal ini,\naku bisa menolak ajakan Lily. Tapi Anna malah ikut-ikutan \nmemaksaku untuk ikut pergi.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 8)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sementara itu, alasanku berada di sini, di rumah Anna,\nadalah karena ia juga memaksaku mengerjakan tugas kuliah \nuntuk minggu depan.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 9)
	{
		anna();
		teks = __String::createWithFormat("\"Apa kamu akan terus berdiri sambil membawa tas besar itu \natau bagaimana?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 10)
	{
		rei();
		teks = __String::createWithFormat("\"Benar juga.Aku agak sedikit--\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 11)
	{
		anna();
		teks = __String::createWithFormat("\"Melamun?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 12)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Ya. Aku masih tidak menyangka aku sedang mengunjungi \nrumah perempuan lagi.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 13)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tasku mengeluarkan suara jatuh yang keras ketika aku meletakkannya.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 14)
	{
		nama_kosong();
		teks = __String::createWithFormat("Butuh waktu selamanya untuk mencari dan memasukkan \nsegala benda yang aku perlukan untuk mendaki gunung.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 15)
	{
		anna();
		teks = __String::createWithFormat("\"Tapi, ini bukan kamu pertama kalinya kamu ke rumah perempuan kan?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 16)
	{
		anna();
		teks = __String::createWithFormat("\"Minggu lalu kamu baru saja ke rumah Nana.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 17)
	{
		rei();
		teks = __String::createWithFormat("\"Waktu itu aku juga terpaksa.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 18)
	{
		rei();
		teks = __String::createWithFormat("\"Dan aku tidak berharap untuk terbiasa bermain ke rumah perempuan.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 19)
	{
		anna();
		teks = __String::createWithFormat("\"Benarkah? Padahal kamu terlihat bersenang-senang di video kalian.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 20)
	{
		hiden_character();
		rei();
		teks = __String::createWithFormat("\"Kamu benar-benar salah lihat. Apa kamu tidak lihat kalau yang \nNana lakukan adalah terus berteriak di telingaku?\"")->getCString();
		teks_1->setString(teks);
	
	}
	else if (HomeMenu::nilai_teks == 21)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku terdiam sejenak untuk mengulang percakapan kami \nyang terdengar salah. Ya. Percakapan barusan terdengar sangat ambigu.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 22)
	{
		rei();
		teks = __String::createWithFormat("\"Apa ada orang lain di sini?\"")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 23)
	{
		anna();
		teks = __String::createWithFormat("\"Kenapa kamu mengkhawatirkan hal itu? \nMemangnya kenapa?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 24)
	{
		rei();
		teks = __String::createWithFormat("\"Tidak apa-apa. Lupakan saja, \naku rasa memang tidak penting.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 25)
	{
		anna();
		teks = __String::createWithFormat("\"Tenang saja, tidak ada siapa-siapa kok.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 26)
	{
		nama_kosong();
		teks = __String::createWithFormat("Apa kalian benar-benar berpikir kalau aku \nbisa tenang setelah mendengar hal itu?")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 27)
	{
		anna();
		teks = __String::createWithFormat("\"Tunggu sebentar ya, aku pergi dulu. \nKamu persiapkan buku-bukumu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 28)
	{
		anna();
		teks = __String::createWithFormat("\"Kita akan mengerjakannya di sini kan? \nAtau mungkin kamu mau ke ka--\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 29)
	{
		rei();
		teks = __String::createWithFormat("\"Di sini saja.\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 30)
	{
		nama_kosong();
		teks = __String::createWithFormat("Apa yang salah dengan mereka, \nseenaknya mengajak laki-laki ke kamar mereka.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 31)
	{
		nama_kosong();
		teks = __String::createWithFormat("Anna dan Nana sepertinya tidak menganggapku \nsebagai seorang laki-laki.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 32)
	{
		nama_kosong();
		teks = __String::createWithFormat("Atau, mungkin aku yang terlalu berlebihan? \nTidak. Aku yakin mereka yang agak kurang waras.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 33)
	{
		anna();
		teks = __String::createWithFormat("\"Oke.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 34)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku kemudian duduk dan mempersiapkan tugas yang perlu aku kerjakan.")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 35)
	{
		nama_titik();
		teks = __String::createWithFormat("\"Waa!\"")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 36)
	{
		rei();
		teks = __String::createWithFormat("\"Woa!\"")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 37)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku terkejut karena teriakan seseorang di belakangku \ndan segera membalikkan badanku.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 38)
	{
		nama_titik();
		teks = __String::createWithFormat("\"Si-siapa kamu?!\"")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/3.png");
		naomi_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 39)
	{
		rei();
		teks = __String::createWithFormat("\"A-aku--\"")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/3.png");
		naomi_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 40)
	{
		nama_titik();
		teks = __String::createWithFormat("\"A-aku panggil satpam!\"")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/3.png");
		naomi_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 41)
	{
		rei();
		teks = __String::createWithFormat("\"Hei tunggu sebentar! Dengarkan dulu!\"")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/3.png");
		naomi_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 42)
	{
		nama_titik();
		teks = __String::createWithFormat("\"Waaa! Jangan dekat-dekat!\"")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setScaleX(-0.6);
		naomi_sprite->setTexture("character/naomi/3.png");
		naomi_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 43)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dia menghempaskan tas genggamnya dan sukses mendarat di wajahku. \nDengan keras.")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setScaleX(-0.6);
		naomi_sprite->setTexture("character/naomi/3.png");
		naomi_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 44)
	{
		rei();
		teks = __String::createWithFormat("\"Ge-hok!\"")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setScaleX(-0.6);
		naomi_sprite->setTexture("character/naomi/3.png");
		naomi_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 45)
	{
		nama_titik();
		teks = __String::createWithFormat("\"Ah! Ma-maaf!\"")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/4.png");
		naomi_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 46)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ya. Tentu saja aku dengan baik hati menerima permintaan maafnya.")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/4.png");
		naomi_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 47)
	{
		rei();
		teks = __String::createWithFormat("\"Aku ini temannya Anna.\"")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/4.png");
		naomi_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 48)
	{
		nama_titik();
		teks = __String::createWithFormat("\"Bagaimana kamu bisa tahu Anna? Kamu--\"")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setScaleX(-0.6);
		naomi_sprite->setTexture("character/naomi/1.png");
		naomi_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 49)
	{
		nama_titik();
		teks = __String::createWithFormat("\"Tasmu besar sekali! Kamu mau menculik Anna ya?\"")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setScaleX(-0.6);
		naomi_sprite->setTexture("character/naomi/1.png");
		naomi_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 50)
	{
		rei();
		teks = __String::createWithFormat("\"...\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 51)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku sebenarnya tidak keberatan untuk ke polisi \nbila itu membuatku tidak mendaki gunung besok.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 52)
	{
		anna();
		teks = __String::createWithFormat("\"Kakak? Ternyata kakak sudah pulang?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 53)
	{
		nama_titik();
		teks = __String::createWithFormat("\"Anna, adikku yang imut! Aku pulang!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/2.png");
		naomi_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 54)
	{
		nama_kosong();
		teks = __String::createWithFormat("Perempuan itu bergegas memeluk Anna.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/2.png");
		naomi_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 55)
	{
		anna();
		teks = __String::createWithFormat("\"Be-berhenti.. ugh..\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/2.png");
		naomi_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 56)
	{
		anna();
		teks = __String::createWithFormat("\"Bukannya kakak baru akan pulang nanti sore?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/2.png");
		naomi_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 57)
	{
		nama_titik();
		teks = __String::createWithFormat("\"Pekerjaan hari ini bisa aku bawa pulang, \njadi aku putuskan untuk pulang saja. Aku kangen dengan adikku!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/1.png");
		naomi_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 58)
	{
		anna();
		teks = __String::createWithFormat("\"Aku bilang berhentiii!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/1.png");
		naomi_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 59)
	{
		nama_kosong();
		teks = __String::createWithFormat("Jadi kalian akan memainkan scene kasih sayang antar saudara \ndan mengabaikanku di sini begitu saja?")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/1.png");
		naomi_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 60)
	{
		nama_titik();
		teks = __String::createWithFormat("\"Oh ya! A-ada orang mencurigakan.\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/3.png");
		naomi_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 61)
	{
		rei();
		teks = __String::createWithFormat("\"Aku harap kamu bisa segera menjelaskannya.\"")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/3.png");
		naomi_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 62)
	{
		anna();
		teks = __String::createWithFormat("\"Itu temanku, namanya Rei.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/2.png");
		naomi_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 63)
	{
		nama_titik();
		teks = __String::createWithFormat("\"Oh! Rei! Rei yang itu! Kamu selalu-\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/1.png");
		naomi_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 64)
	{
		nama_titik();
		teks = __String::createWithFormat("\"Mmmmmm!!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/3.png");
		naomi_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 65)
	{
		nama_kosong();
		teks = __String::createWithFormat("Anna membungkam mulut kakaknya seperti hendak menculiknya. \nApa yang sebenarnya sedang terjadi di sini?")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/3.png");
		naomi_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 66)
	{
		anna();
		teks = __String::createWithFormat("\"Rei, perkenalkan, ini kakakku.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/1.png");
		naomi_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 67)
	{
		hiden_character();
		nama_titik();
		teks = __String::createWithFormat("\"Halo Rei, senang bertemu denganmu. \nAku Naomi, kakaknya Anna.\"")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/1.png");
		naomi_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 68)
	{
		rei();
		teks = __String::createWithFormat("\"Senang bertemu denganmu juga kak Naomi.\"")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/1.png");
		naomi_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 69)
	{
		naomi();
		teks = __String::createWithFormat("\"Maafkan aku sebelumnya, aku tidak tahu kalau kamu temannya Nana.\"")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/4.png");
		naomi_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 70)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku cukup yakin sudah mengatakannya tadi.")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/4.png");
		naomi_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 71)
	{
		naomi();
		teks = __String::createWithFormat("\"Habisnya, Anna tidak pernah membawa teman laki-laki \nke sini, jadi aku salah sangka.\"")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/4.png");
		naomi_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 72)
	{
		naomi();
		teks = __String::createWithFormat("\"Ngomong-ngomong, nanti sore kalian akan pergi \nuntuk mendaki gunung ya\"")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/1.png");
		naomi_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 73)
	{
		rei();
		teks = __String::createWithFormat("\"Iya\"")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/1.png");
		naomi_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 74)
	{
		naomi();
		teks = __String::createWithFormat("\"Enak sekali ya masih muda.\"")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/1.png");
		naomi_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 75)
	{
		anna();
		teks = __String::createWithFormat("\"Kakak cuma beda dua tahun denganku, \ntidak usah sok tua.\"")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/2.png");
		naomi_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 76)
	{
		naomi();
		teks = __String::createWithFormat("\"Jadi, apa yang kalian lakukan di sini?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		naomi_sprite->setScale(0.6);
		naomi_sprite->setScaleX(-0.6);
		naomi_sprite->setTexture("character/naomi/1.png");
		naomi_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 77)
	{
		rei();
		teks = __String::createWithFormat("\"Kami berencana mengerjakan tugas sebelum berangkat.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		naomi_sprite->setScale(0.6);
		naomi_sprite->setScaleX(-0.6);
		naomi_sprite->setTexture("character/naomi/1.png");
		naomi_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));

	}
	else if (HomeMenu::nilai_teks == 78)
	{
		naomi();
		teks = __String::createWithFormat("\"Wah, padahal nanti mau bersenang-senang. \nPasti ini idenya Anna.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		naomi_sprite->setScale(0.6);
		naomi_sprite->setScaleX(-0.6);
		naomi_sprite->setTexture("character/naomi/1.png");
		naomi_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 79)
	{
		anna();
		teks = __String::createWithFormat("\"Justru karena akan bersenang-senang makanya tugasnya \nharus dikerjakan sekarang.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		naomi_sprite->setScale(0.6);
		naomi_sprite->setScaleX(-0.6);
		naomi_sprite->setTexture("character/naomi/1.png");
		naomi_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 80)
	{
		naomi();
		teks = __String::createWithFormat("\"Sungguh pemikiran yang merepotkan, iya kan Rei?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/2.png");
		naomi_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 81)
	{
		rei();
		teks = __String::createWithFormat("\"I-iya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/2.png");
		naomi_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 82)
	{
		nama_kosong();
		teks = __String::createWithFormat("Jarang sekali aku bertemu orang yang sepemikiran denganku.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/2.png");
		naomi_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 83)
	{
		naomi();
		teks = __String::createWithFormat("\"Kalian akan mengerjakannya di sini? \nKenapa tidak di kamar saja?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/3.png");
		naomi_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 84)
	{
		anna();
		teks = __String::createWithFormat("\"Rei ingin mengerjakannya di sini saja katanya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/1.png");
		naomi_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 85)
	{
		naomi();
		teks = __String::createWithFormat("\"Benarkah Rei?\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/2.png");
		naomi_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 86)
	{
		rei();
		teks = __String::createWithFormat("\"Ke-kenapa memangnya?\"")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/2.png");
		naomi_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 87)
	{
		naomi();
		teks = __String::createWithFormat("\"Tidak, tidak. Ini ruang tamu, bukan digunakan untuk belajar. \nKalian pindah sana ke kamar.\"")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/1.png");
		naomi_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 88)
	{
		rei();
		teks = __String::createWithFormat("\"Tapi, aku seorang tamu.\"")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/1.png");
		naomi_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 89)
	{
		naomi();
		teks = __String::createWithFormat("\"Argumen yang bagus, kamu pasti sering berdebat dengan Anna. \nTapi sayang sekali aku berada di level yang berbeda.\"")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/1.png");
		naomi_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 90)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku melirik ke arah Anna dan mengangkat alisku. \n'Benarkah?'")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/1.png");
		naomi_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 91)
	{
		nama_kosong();
		teks = __String::createWithFormat("Anna sedikit mengangguk.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/1.png");
		naomi_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 92)
	{
		hiden_character();
		naomi();
		teks = __String::createWithFormat("\"Keberadaan kalian di sini tidak enak dilihat.\"")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setScaleX(-0.6);
		naomi_sprite->setTexture("character/naomi/1.png");
		naomi_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 93)
	{
		naomi();
		teks = __String::createWithFormat("\"Lagipula kalau misalnya nanti ada tamu, \ndimana aku harus menempatkannya? Di kamarku?\"")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setScaleX(-0.6);
		naomi_sprite->setTexture("character/naomi/1.png");
		naomi_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 94)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku nyaris tertawa namun menahannya karena menyadari \nkalau aku memang kalah argumen.")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setScaleX(-0.6);
		naomi_sprite->setTexture("character/naomi/1.png");
		naomi_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 95)
	{
		rei();
		teks = __String::createWithFormat("\"Oke, kami akan pergi.\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 96)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku mengangkat tasku yang berat dan mengikuti Anna ke dalam.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 97)
	{
		naomi();
		teks = __String::createWithFormat("\"Aku tidak akan mengecek ke sana kok!\"")->getCString();
		teks_1->setString(teks);
		naomi_sprite->setScale(0.6);
		naomi_sprite->setTexture("character/naomi/2.png");
		naomi_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 98)
	{
		hiden_character();
		anna();
		teks = __String::createWithFormat("\"Duh, kakak!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 99)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Aku melangkah masuk dengan hati-hati. \nAyolah Rei, ini bukan yang pertama kalinya.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 100)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tapi tetap saja, entah kenapa suasana di kamar perempuan \nmembuatku terasa tertekan.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 101)
	{
		anna();
		teks = __String::createWithFormat("\"Maafkan kelakuan kakakku.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 102)
	{
		rei();
		teks = __String::createWithFormat("\"Tidak apa-apa. Bagaimana ya, dia itu.. unik.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 103)
	{
		rei();
		teks = __String::createWithFormat("\"Jadi kalian sering berdebat? \nAku pikir kalian saudari yang saling menyayangi.\n")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 104)
	{
		anna();
		teks = __String::createWithFormat("\"Sebenarnya, aku yang selalu memulai perdebatannya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 105)
	{
		rei();
		teks = __String::createWithFormat("\"Oh, begitukah? Sama seperti yang aku alami kalau begitu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 106)
	{
		anna();
		teks = __String::createWithFormat("\"Ha?! Apa maksudmu?!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 107)
	{
		rei();
		teks = __String::createWithFormat("\"Lupakan saja. Ayo kita kerjakan tugasnya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 108)
	{
		anna();
		teks = __String::createWithFormat("\"Oke, mari kita lihat kemampuanmu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 109)
	{
		rei();
		teks = __String::createWithFormat("\"Bukannya kamu akan membantuku?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 110)
	{
		anna();
		teks = __String::createWithFormat("\"Nanti. Pertama-tama biarkan aku mengukur kemampuanmu dulu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 112)
	{
		anna();
		teks = __String::createWithFormat("\"Tidak buruk Rei. Aku yakin kamu masih bisa lulus \ndengan kemampuanmu sekarang. Tapi tentunya, kamu masih perlu \nbanyak belajar.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 113)
	{
		rei();
		teks = __String::createWithFormat("\"Mohon bimbingannya Bu.\"")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 114)
	{
		nama_kosong();
		teks = __String::createWithFormat("Setelahnya, aku dipaksa Anna untuk mengerjakan tugas-tugas \ndan belajar sampai sore hari.")->getCString();
		teks_1->setString(teks);
	}
}


void Scene10a::quit_yes(Ref* sender)
{
	HomeMenu::btn_sound();
	HomeMenu::nilai_logo = true;

	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		Director::getInstance()->replaceScene(TransitionFade::create(3, HomeMenu::scene(), Color3B(255, 255, 255)));
	})));
} //button tekan exit yes

void Scene10a::quit_no(Ref* sender)
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
void Scene10a::teksJalan(float dt)
{

	teks_satu();
}

void Scene10a::teks_satu()
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
		unschedule(schedule_selector(Scene10a::teksJalan));
	}
}

void Scene10a::rei()
{
	auto teks_nama = __String::createWithFormat("Rei")->getCString();
	nama->setString(teks_nama);
}
void Scene10a::anna()
{
	auto teks_nama = __String::createWithFormat("Anna")->getCString();
	nama->setString(teks_nama);
}
void Scene10a::naomi()
{
	auto teks_nama = __String::createWithFormat("Naomi")->getCString();
	nama->setString(teks_nama);
}
void Scene10a::nana()
{
	auto teks_nama = __String::createWithFormat("Nana")->getCString();
	nama->setString(teks_nama);
}
void Scene10a::nama_kosong()
{
	auto teks_nama = __String::createWithFormat("")->getCString();
	nama->setString(teks_nama);
}
void Scene10a::nama_titik()
{
	auto teks_nama = __String::createWithFormat("......")->getCString();
	nama->setString(teks_nama);
}
void Scene10a::wali()
{
	auto teks_nama = __String::createWithFormat("Wali Kelas")->getCString();
	nama->setString(teks_nama);
}


