#include "Scene10.h"
#include "Scene10a.h"
#include "Scene10b.h"
#include "Option.h"
#include "HomeMenu.h"
#include "SaveGame.h"
#include "LoadGame.h"

USING_NS_CC;



Scene* Scene10::scene()
{
	return Scene10::create();
}

bool Scene10::init()
{
	if (!Scene::init())
	{
		return false;
	}
	bgm->playBackgroundMusic("music/10.mp3", true);
	HomeMenu::game = 13;


	//background//
	background->setPosition(Vec2(0, 0));
	background->setAnchorPoint(Vec2(0, 0));
	this->addChild(background, 1);
	/////////////

	this->schedule(schedule_selector(Scene10::delay_game), 1);

	buttonStart->setPosition(Vec2(1366 / 2, 10));
	buttonStart->setScale(0);
	buttonStart->setAnchorPoint(Vec2(0.5, 0));
	this->addChild(buttonStart, 2);

	//bagian button menu//
	btn_menu->setPosition(Vec2(1313, 714));
	btn_menu->setAnchorPoint(Vec2(0.5, 0.5));
	this->addChild(btn_menu, 2);
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

	//milih jawaban//
	bg_kosong->setPosition(Vec2(0, 0));
	bg_kosong->setAnchorPoint(Vec2(0, 0));
	bg_choose->setPosition(Vec2(1366 / 2, 768 / 2));
	bg_choose->setAnchorPoint(Vec2(0.5, 0.5));
	btn_choose_left->setPosition(Vec2(bg_choose->getContentSize().width / 2 - 30, bg_choose->getContentSize().height / 2));
	btn_choose_left->setAnchorPoint(Vec2(1, 0.5));
	btn_choose_right->setPosition(Vec2(bg_choose->getContentSize().width / 2 + 30, bg_choose->getContentSize().height / 2));
	btn_choose_right->setAnchorPoint(Vec2(0, 0.5));
	this->addChild(bg_choose, 5);
	this->addChild(bg_kosong, 4);
	bg_choose->addChild(btn_choose_left);
	bg_choose->addChild(btn_choose_right);
	label_choose_left->setPosition(Vec2(btn_choose_left->getContentSize().width / 2, btn_choose_left->getContentSize().height / 2));
	label_choose_right->setPosition(Vec2(btn_choose_right->getContentSize().width / 2, btn_choose_right->getContentSize().height / 2));
	label_choose_left->setAnchorPoint(Vec2(0.5, 0.5));
	label_choose_right->setAnchorPoint(Vec2(0.5, 0.5));
	btn_choose_left->addChild(label_choose_left);
	btn_choose_right->addChild(label_choose_right);
	bg_choose->setScale(0);
	bg_kosong->setScale(0);
	////////////////

	/////////////////////////
	btn_load->addClickEventListener(CC_CALLBACK_1(Scene10::load_game, this));
	btn_save->addClickEventListener(CC_CALLBACK_1(Scene10::save_game, this));
	btn_config->addClickEventListener(CC_CALLBACK_1(Scene10::config, this));
	btn_exit_no->addClickEventListener(CC_CALLBACK_1(Scene10::quit_no, this));
	btn_exit_yes->addClickEventListener(CC_CALLBACK_1(Scene10::quit_yes, this));
	btn_tittle->addClickEventListener(CC_CALLBACK_1(Scene10::back_title, this));
	btn_close->addClickEventListener(CC_CALLBACK_1(Scene10::close_menu, this));
	buttonStart->addClickEventListener(CC_CALLBACK_1(Scene10::startGame, this));
	btn_menu->addClickEventListener(CC_CALLBACK_1(Scene10::pil_menu, this));
	btn_choose_left->addClickEventListener(CC_CALLBACK_1(Scene10::choose_left, this));
	btn_choose_right->addClickEventListener(CC_CALLBACK_1(Scene10::choose_right, this));
	///////////////////////////
	//gambar karakter//
	anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	hiden_character();
	this->addChild(nana_sprite,1);
	this->addChild(anna_sprite,1);
	this->addChild(lily_sprite,1);
	/////////////////////////
	//background//
	if (HomeMenu::nilai_teks > 10 && HomeMenu::nilai_teks < 56)
		background->setTexture("bg/kafe.jpg");
	else if (HomeMenu::nilai_teks > 55 && HomeMenu::nilai_teks < 70)
		background->setTexture("bg/kafe_2.jpg");
	else if (HomeMenu::nilai_teks > 69 && HomeMenu::nilai_teks < 83)
		background->setTexture("bg/lab_jaringan.jpg");
	else if (HomeMenu::nilai_teks > 82)
		background->setTexture("bg/lorong_sb2.jpg");
	/////////////
	return true;
}void Scene10::hiden_character()
{
	anna_sprite->setScale(0);
	nana_sprite->setScale(0);
	lily_sprite->setScale(0);
}
void Scene10::delay_game(float dt)
{
	detik++;

	if (detik == 4)
	{
		isi_teks();
		this->schedule(schedule_selector(Scene10::teksJalan), Option::speed_teks);
		unschedule(schedule_selector(Scene10::delay_game));
		detik = 0;
	}
	else if (detik == 3)
		buttonStart->setScale(1);
}


void Scene10::pil_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1400, 780)));
	btn_menu->setScale(0);

}

void Scene10::close_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1600, 780)));
	btn_menu->setScale(1);
}

void Scene10::back_title(Ref* sender)
{

	HomeMenu::btn_sound();
	bg_exit->setScale(1);
	kosong->setScale(1);
	btn_exit_no->setScale(1);
	btn_exit_yes->setScale(1);
	label_quit_no->setScale(1);
	label_quit_yes->setScale(1);

}

void Scene10::config(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, Option::scene(), Color3B(255, 255, 255)));
	})));

}
void Scene10::save_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, SaveGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene10::load_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, LoadGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene10::delay(float dt)
{
	if (detik == 1)
	{
		unschedule(schedule_selector(Scene10::delay));
		buttonStart->setScale(1);
		if (HomeMenu::nilai_teks == 11 || HomeMenu::nilai_teks == 56 || HomeMenu::nilai_teks == 70 || HomeMenu::nilai_teks == 83)
		{
			if (HomeMenu::nilai_teks == 56)
				anna_sprite->setScale(0.6);
			this->schedule(schedule_selector(Scene10::teksJalan), Option::speed_teks);
		}
		detik = 0;
	}
	detik++;
}
void Scene10::startGame(Ref* sender)
{
	unschedule(schedule_selector(Scene10::teksJalan));
	HomeMenu::btn_sound();
	HomeMenu::nilai_teks++;
	isi_teks();
	teks_1->setOpacity(0);
	i = 0;
	log("Nilai teks = %d", HomeMenu::nilai_teks);
	if (HomeMenu::nilai_teks == 11 || HomeMenu::nilai_teks == 56 || HomeMenu::nilai_teks == 70 || HomeMenu::nilai_teks == 83)
	{
		hiden_character();
		buttonStart->setScale(0);
		if (HomeMenu::nilai_teks > 10 && HomeMenu::nilai_teks < 56)
			background->setTexture("bg/kafe.jpg");
		else if (HomeMenu::nilai_teks > 55 && HomeMenu::nilai_teks < 70)
			background->setTexture("bg/kafe_2.jpg");
		else if (HomeMenu::nilai_teks > 69 && HomeMenu::nilai_teks < 83)
			background->setTexture("bg/lab_jaringan.jpg");
		else if (HomeMenu::nilai_teks > 82)
			background->setTexture("bg/lorong_sb2.jpg");
		this->schedule(schedule_selector(Scene10::delay), 1.f);
	}
	else if (HomeMenu::nilai_teks == 122)
	{
		bg_kosong->setScale(1);
		bg_choose->setScale(1);
	}
	else
		this->schedule(schedule_selector(Scene10::teksJalan), Option::speed_teks);
}

void Scene10::choose_left(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		Director::getInstance()->replaceScene(TransitionFade::create(3, Scene10a::scene(), Color3B(255, 255, 255)));
	})));
	HomeMenu::nilai_teks = 1;
}
void Scene10::choose_right(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		Director::getInstance()->replaceScene(TransitionFade::create(3, Scene10b::scene(), Color3B(255, 255, 255)));
	})));
	HomeMenu::nilai_teks = 1;
}

void Scene10::isi_teks()
{
	if (HomeMenu::nilai_teks == 1)
	{
		nama_kosong();
		teks = __String::createWithFormat("Setelah berterimakasih kepada sopir pribadi Nana,\naku masuk ke dalam rumah.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 2)
	{
		nama_kosong();
		teks = __String::createWithFormat("Karena diantar menggunakan mobil, aku menghemat waktuku hingga \nsetengah jam untuk perjalanan pulang.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 3)
	{
		nama_kosong();
		teks = __String::createWithFormat("Meskipun begitu, aku harus menghadapi rasa canggung selama perjalanan.\nAdalah kesalahanku menempatkan diriku di sebelah sopir.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 4)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tapi, normalnya ketika hanya ada dua orang dalam mobil,\nposisinya akan begitu kan?")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 5)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ketika aku membuka pintu masuk di sebelah sopir, aku baru \nmenyadari kesalahanku dan tidak bisa mengulangnya.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 6)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku duduk sejenak di atas kasurku, memutuskan apa yang \nakan aku lakukan sekarang.")->getCString();
		teks_1->setString(teks);

	}
	else if (HomeMenu::nilai_teks == 7)
	{
		nama_kosong();
		teks = __String::createWithFormat("Memikirkan Nana yang pasti saat ini sedang bersemangat \nmengedit video, aku akhirnya membuat rekaman baru.")->getCString();
		teks_1->setString(teks);

	}
	else if (HomeMenu::nilai_teks == 8)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dengan rekaman yang akan aku buat ini, berarti aku sudah membuat \nempat rekaman. Tidak terasa aku sudah membuat sebanyak itu sejak aku \nmemutuskan untuk memulai hal ini.")->getCString();
		teks_1->setString(teks);

	}
	else if (HomeMenu::nilai_teks == 9)
	{
		nama_kosong();
		teks = __String::createWithFormat("Selesai membuat rekaman, aku \nbermain game 'lagi' hingga tengah malam. ")->getCString();
		teks_1->setString(teks);

	}
	else if (HomeMenu::nilai_teks == 10)
	{
		nama_kosong();
		teks = __String::createWithFormat("Setelah itu, aku beristirahat untuk mempersiapkan diriku di shift besok.\nShift penuh hari Sabtu.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 11)
	{
		anna();
		teks = __String::createWithFormat("\"...\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 12)
	{
		rei();
		teks = __String::createWithFormat("\"Se-selamat pagi..\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 13)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tidak biasanya Anna menyambutku dengan wajah marah.\nHal itu membuatku bingung.")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 14)
	{
		rei();
		teks = __String::createWithFormat("\"Kamu datang cepat seperti biasanya ya,\nhaha.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 15)
	{
		rei();
		 
		teks = __String::createWithFormat("\"Maaf aku datang terlambat,\nwalau sebenarnya aku tepat waktu.. haha..\"")->getCString();
		teks_1->setString(teks);

	}

	else if (HomeMenu::nilai_teks == 16)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku kehabisan kalimat untuk dilontarkan,\nsementara Anna masih saja membuat wajah marah.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 17)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku berniat untuk masa bodoh dan fokus pada pekerjaanku,\nnamun aku tidak bisa. Rasanya mengganggu sekali melihat \nAnna seperti ini.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 18)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ketika aku sedikit luang karena tidak ada sedang perlu \naku kerjakan, aku berusaha berbicara pada Anna lagi.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 19)
	{
		rei();
		teks = __String::createWithFormat("\"Ada apa denganmu? Apa terjadi sesuatu?\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 20)
	{
		rei();
		teks = __String::createWithFormat("\"Mimpi buruk?\" Tidak, itu tidak masuk akal..")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 21)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku melihat Anna masih diam saja.\nKemudian sesuatu terlintas di kepalaku.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 22)
	{
		rei();
		teks = __String::createWithFormat("\"Oh. Jangan-jangan..\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 23)
	{
		rei();
		teks = __String::createWithFormat("\"Kamu sedang.. itu.. ya, itu.. umm...\" \naku mengecilkan suaraku.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 24)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tiba-tiba Anna tertawa, namun segera menahannya.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 25)
	{
		anna();
		teks = __String::createWithFormat("\"Apa kamu bodoh?\" \nNana masih sedikit tertawa.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 26)
	{
		nama_kosong();
		teks = __String::createWithFormat("Secara harfiah,\naku memang bodoh kalau dibandingkan denganmu.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 27)
	{
		anna();
		teks = __String::createWithFormat("\"Tidak sopan menanyakan hal itu kepada wanita secara langsung.\nApalagi kamu laki-laki.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 28)
	{
		rei();
		teks = __String::createWithFormat("\"Ma-maaf. Jadi.. memang..\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 29)
	{
		anna();
		teks = __String::createWithFormat("\"Bukan, bodoh!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 30)
	{
		anna();
		teks = __String::createWithFormat("\"Aaahhh! Sebenarnya aku ingin terus marah padamu hari ini.\nAku sama sekali tidak menyangka kamu akan menanyakan hal \nseperti itu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 31)
	{
		rei();
		teks = __String::createWithFormat("\"Jadi, kenapa kamu harus marah padaku seharian?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 32)
	{
		anna();
		teks = __String::createWithFormat("\"...\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 33)
	{
		anna();
		teks = __String::createWithFormat("“Hmm, setelah aku pikir, mungkin bukan salahmu juga sih.”")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 34)
	{
		nama_kosong();
		teks = __String::createWithFormat("Membingungkan sekali orang ini!")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 35)
	{
		anna();
		teks = __String::createWithFormat("\"Kemarin kamu tidak memberitahuku kalau kamu tidak ada shift,\npadahal aku sudah bilang padamu kalau aku ada.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 36)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku sedikit membuka mulutku, tidak yakin apakah untuk \nmengucapkan sesuatu, atau untuk mengeluarkan sedikit jeritan.")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 37)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku lupa sama sekali!\nAku belum memberi tahu Anna!")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 38)
	{
		rei();
		teks = __String::createWithFormat("\"Maaf sekali! Aku benar-benar lupa! Ah.\nTapi kalau diingat-ingat, itu salahmu juga.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 39)
	{
		anna();
		teks = __String::createWithFormat("\"Hah?!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 40)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dasar bodoh secara harfiah.\nKenapa aku malah menyalahkannya.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 41)
	{
		rei();
		teks = __String::createWithFormat("\"Waktu itu, waktu sepulang sekolah,\nwaktu kamu bilang kalau besok kamu ada shift,\nsebenarnya aku ingin menjawab kalau aku tidak ada shift.---\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 42)
	{
		rei();
		teks = __String::createWithFormat("\"Tapi kamu terburu-buru dan langsung pergi begitu saja.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 43)
	{
		nama_kosong();
		teks = __String::createWithFormat("Anna terdiam sejenak.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 44)
	{
		anna();
		teks = __String::createWithFormat("\"Benar juga. Oh, jadi begitu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 45)
	{
		anna();
		teks = __String::createWithFormat("\"Tapi kamu setidaknya bisa memberi tahuku lewat pesan kan?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A2.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 46)
	{
		rei();
		teks = __String::createWithFormat("\"K-kalau itu memang salahku. Aku lupa.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 47)
	{
		anna();
		teks = __String::createWithFormat("Aku tidak mengira akan menemani seorang mahasiswi \npindahan jalan-jalan hari ini.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 48)
	{
		anna();
		teks = __String::createWithFormat("\"Tapi, kamu sebenarnya ingin mengirimkan pesan kan?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A2.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 49)
	{
		rei();
		teks = __String::createWithFormat("\"Iya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 50)
	{
		anna();
		teks = __String::createWithFormat("\"Lain kali kalau kamu tidak ada shift kirimi aku pesan.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 51)
	{
		rei();
		teks = __String::createWithFormat("\"Oke.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 52)
	{
		anna();
		teks = __String::createWithFormat("\"Kalau ada apa-apa, kamu juga harus kirim pesan.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 53)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku mengangguk.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 54)
	{
		anna();
		teks = __String::createWithFormat("\"Baiklah! Sekarang ayo kita selesaikan shift \nyang melelahkan ini!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 55)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku mengangguk lagi dan sedikit mengembangkan bibirku.\nRasanya lega masalahku sudah terselesaikan.")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 56)
	{
		anna();
		teks = __String::createWithFormat("\"Sepertinya masih perlu waktu lama sampai \naku terbiasa dengan shift di hari Sabtu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 57)
	{
		rei();
		teks = __String::createWithFormat("\"Hahaha, sepertinya begitu.\nAku jadi ingat sewaktu aku pertama kali bekerja di sini.\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 58)
	{
		rei();
		teks = __String::createWithFormat("\"Sama sepertimu, aku benar-benar kewelahan.\nPadahal dulu pelanggannya lebih sedikit dari sekarang.\nJadi wajar kalau kamu kelelahan.\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 59)
	{
		nama_kosong();
		teks = __String::createWithFormat("Setelah hari benar-benar menjadi gelap,\nkami bersiap untuk pulang.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 60)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku berencana untuk langsung tidur karena \nbesok masih ada shift seharian.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 61)
	{
		anna();
		teks = __String::createWithFormat("\"Kalau begitu, sudah dulu ya Rei.\nSampai jumpa besok Senin.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 62)
	{
		rei();
		teks = __String::createWithFormat("\"Ya, sampai jumpa lagi.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 63)
	{
		anna();
		teks = __String::createWithFormat("\"Dan juga.. um..\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 64)
	{
		anna();
		teks = __String::createWithFormat("\"Maaf aku tadi bersikap bodoh.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 65)
	{
		rei();
		teks = __String::createWithFormat("\"Tidak apa-apa, menurutku aku juga salah.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 66)
	{
		anna();
		teks = __String::createWithFormat("\"Tidak! Rei tidak salah sama sekali.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 67)
	{
		anna();
		teks = __String::createWithFormat("\"Ya, mungkin sedikit.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/A1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 68)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dasar. Dia plin-plan sekali hari ini. Tapi,\naku memang berpikir kalau aku yang salah.\nJadi apa boleh buat.")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 69)
	{
		nama_kosong();
		teks = __String::createWithFormat("Setelah Anna pergi,\naku melangkahkan kakiku ke halte terdekat.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 70)
	{
		nama_kosong();
		teks = __String::createWithFormat("Setelah shift yang panjang di hari Sabtu dan Minggu,\naku akhirnya sampai di hari Senin dengan baik-baik saja.")->getCString();
		teks_1->setString(teks);
		
	}
	else if (HomeMenu::nilai_teks == 71)
	{
		nama_kosong();
		teks = __String::createWithFormat("Masalahnya adalah, aku tidak membuat rekaman baru.\nAku hanya bermain game untuk melepas rasa lelahku,\ndan benar-benar lelah untuk membuat rekaman.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 72)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku merasa kalau sebaiknya aku segera memberi tahu Nana \ntentang pekerjaanku di kafe.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 73)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku memang sudah berniat untuk mengurangi shiftku,\ntapi itu baru bisa dilakukan bulan depan.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 74)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tapi justru karena itu aku tidak perlu memberi tahunya.\nToh bulan depan aku sudah punya banyak waktu luang.\nArgh, aku jadi bingung sendiri.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 75)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dan tepat sekali ketika aku dibingungkan oleh pikiranku sendiri,\nseseorang yang berkemampuan untuk menambah beban pikiranku \ndatang.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 76)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku tersibukkan dengan berbagai hal sampai melupakan dirinya.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 77)
	{
		lily();
		teks = __String::createWithFormat("\"Kakak!\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 78)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ke-kenapa dia di sini?")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 79)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tidak, aku tahu alasan kenapa dia kesini. Hanya saja aku \nsama sekali tidak menduga ia akan menghampiriku ke kelasku.")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 80)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku segera bangkit dari kursiku dan menghampirinya sebelum ia \nmasuk ke kelas dan membuat keributan.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 81)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dan, ya. Sesuai yang aku duga, dampak dari tindakanku ini adalah \ntatapan dan bisikan-bisikan dari teman-teman sekelasku.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 82)
	{
		nama_kosong();
		teks = __String::createWithFormat("Masa bodoh sih dengan hal itu.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 83)
	{
		rei();
		teks = __String::createWithFormat("\"...\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 84)
	{
		lily();
		teks = __String::createWithFormat("\"...\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 85)
	{
		lily();
		teks = __String::createWithFormat("\"Jadi?\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 86)
	{
		rei();
		teks = __String::createWithFormat("\"Langsung ke intinya ya..\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 87)
	{
		lily();
		teks = __String::createWithFormat("\"Kakak tidak suka basa-basi kan?\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 88)
	{
		rei();
		teks = __String::createWithFormat("\"Iya, hanya saja..\naku masih berusaha menerima keberadaanmu di sini.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 89)
	{
		lily();
		teks = __String::createWithFormat("\"Eh? Memangnya Lily tidak boleh ke sini?\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setScaleX(-0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 90)
	{
		rei();
		teks = __String::createWithFormat("\"Kurang lebih begitu sih,\njadi langsung aku jawab saja. Tidak.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setScaleX(-0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 91)
	{
		lily();
		teks = __String::createWithFormat("\"Eh? Jahat sekali.\nPadahal Lily sudah beri waktu beberapa hari untuk memikirkannya.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l4.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 92)
	{
		nama_kosong();
		teks = __String::createWithFormat("Iya, dan aku juga sudah bilang padamu kalau aku \ntetap akan mengatakan tidak.")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l4.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 93)
	{
		lily();
		teks = __String::createWithFormat("\"Kalau begini, Lily harus mencari orang lagi..\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l4.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 94)
	{
		nama_kosong();
		teks = __String::createWithFormat("Maaf, aku merasa tidak enak padamu. Tapi, bagaimanapun,\nmendaki gunung itu sesuatu yang rasanya mustahil aku lakukan.")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l4.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 95)
	{
		lily();
		teks = __String::createWithFormat("\"Ah! Bagaimana kalau aku ajak mereka?\nTeman dari kelas kakak?\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l3.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 96)
	{
		rei();
		teks = __String::createWithFormat("\"Eh?\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 97)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku menoleh ke belakang.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 98)
	{
		nama_kosong();
		teks = __String::createWithFormat("Yang benar saja. Anna dan Nana mengintipku dari balik pintu.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 99)
	{
		rei();
		teks = __String::createWithFormat("\"Apa yang kalian-\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 100)
	{
		lily();
		teks = __String::createWithFormat("\"Selamat pagi kakak!\" \nLily dengan cepat menghampiri mereka")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 101)
	{
		anna();
		teks = __String::createWithFormat("\"Selamat pagi!\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));

		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 102)
	{
		hiden_character();
		nana();
		teks = __String::createWithFormat("\"Hai.\"")->getCString();
		teks_1->setString(teks);
		 
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 103)
	{
		hiden_character();
		lily();
		teks = __String::createWithFormat("\"Apa kakak-kakak temannya Kak Rei?\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setScaleX(-0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 104)
	{
		anna();
		teks = __String::createWithFormat("\"Ya, begitulah. Salam kenal, aku Anna.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setScaleX(-0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));

		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 105)
	{
		hiden_character();
		nana();
		teks = __String::createWithFormat("\"Aku Nana.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setScaleX(-0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 106)
	{
		hiden_character();
		rei();
		teks = __String::createWithFormat("\"Kalau begitu, aku kembali ke kelas.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setScaleX(-0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 107)
	{
		hiden_character();
		anna();
		teks = __String::createWithFormat("\"Hei, tunggu sebentar.\nYang kenal dia itu kamu kan? Bagaimana sih kamu?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 108)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Aku melihat Lily tersenyum.\nSi-sial.")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l5.png");
		lily_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 109)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Beberapa menit kemudian, gadis-gadis ini telah asyik mengobrol.\nSebenarnya, tidak ada salahnya aku tadi kembali ke kelas saja.")->getCString();
		
	}
	else if (HomeMenu::nilai_teks == 110)
	{
		anna();
		teks = __String::createWithFormat("\"Wah, kedengarannya asyik juga, iya kan Nana?\"")->getCString();
		teks_1->setString(teks);
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 111)
	{
		nama_kosong();
		teks = __String::createWithFormat("Nana mengangguk.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
		nana_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2+300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 112)
	{
		hiden_character();
		anna();
		teks = __String::createWithFormat("\"Rei, kenapa kamu tidak pernah memberi tahu kami?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K6.png");
		anna_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 113)
	{
		rei();
		teks = __String::createWithFormat("\"Aku kan dari awal tidak ingin ikut,\nmana mungkin aku malah mengajak orang untuk ikut serta.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K6.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 114)
	{
		
		lily();
		teks = __String::createWithFormat("\"Kalau begitu, kalian bertiga akan ikut serta kan?\nTerima kasih! Semakin ramai akan semakin seru!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 115)
	{
		rei();
		teks = __String::createWithFormat("\"Tidak, hei, aku tidak-\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 116)
	{
		anna();
		teks = __String::createWithFormat("\"Iya! Pasti seru kalau kita bertiga pergi bersama!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 117)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Dua orang ini.. serasi sekali.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 118)
	{
		rei();
		teks = __String::createWithFormat("\"Kalau kamu bagaimana Nana? Apa kamu benar-benar ingin ikut?\"")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 119)
	{
		nana();
		teks = __String::createWithFormat("\"Aku.. kalau Rei ikut, aku juga ikut.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 120)
	{
		nana();
		teks = __String::createWithFormat("\"Ah! Maksudku, kalau mau pergi,\nseharusnya kita bertiga pergi bersama-sama.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/5.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 121)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Mereka bertiga menatapku dengan antusias.\nJadi, keputusan masih ada di tanganku ya.")->getCString();
		teks_1->setString(teks);
		 
	}

}


void Scene10::quit_yes(Ref* sender)
{
	HomeMenu::btn_sound();
	HomeMenu::nilai_logo = true;

	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		Director::getInstance()->replaceScene(TransitionFade::create(3, HomeMenu::scene(), Color3B(255, 255, 255)));
	})));
} //button tekan exit yes

void Scene10::quit_no(Ref* sender)
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
void Scene10::teksJalan(float dt)
{

	teks_satu();
}

void Scene10::teks_satu()
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
		unschedule(schedule_selector(Scene10::teksJalan));
	}
}

void Scene10::rei()
{
	auto teks_nama = __String::createWithFormat("Rei")->getCString();
	nama->setString(teks_nama);
}
void Scene10::anna()
{
	auto teks_nama = __String::createWithFormat("Anna")->getCString();
	nama->setString(teks_nama);
}
void Scene10::nana()
{
	auto teks_nama = __String::createWithFormat("Nana")->getCString();
	nama->setString(teks_nama);
}
void Scene10::nama_kosong()
{
	auto teks_nama = __String::createWithFormat("")->getCString();
	nama->setString(teks_nama);
}
void Scene10::lily()
{
	auto teks_nama = __String::createWithFormat("Lily")->getCString();
	nama->setString(teks_nama);
}
void Scene10::nama_titik()
{
	auto teks_nama = __String::createWithFormat("......")->getCString();
	nama->setString(teks_nama);
}
void Scene10::wali()
{
	auto teks_nama = __String::createWithFormat("Wali Kelas")->getCString();
	nama->setString(teks_nama);
}


