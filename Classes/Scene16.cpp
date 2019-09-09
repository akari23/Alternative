#include "Scene16.h"
#include "Option.h"
#include "HomeMenu.h"
#include "SaveGame.h"
#include "LoadGame.h"

USING_NS_CC;



Scene* Scene16::scene()
{
	return Scene16::create();
}

bool Scene16::init()
{
	if (!Scene::init())
	{
		return false;
	}
	bgm->playBackgroundMusic("music/16.mp3", true);
	HomeMenu::game = 18;
	

	//background//
	background->setPosition(Vec2(0, 0));
	background->setAnchorPoint(Vec2(0, 0));
	this->addChild(background);
	/////////////

	this->schedule(schedule_selector(Scene16::delay_game), 1);

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
	btn_load->addClickEventListener(CC_CALLBACK_1(Scene16::load_game, this));
	btn_save->addClickEventListener(CC_CALLBACK_1(Scene16::save_game, this));
	btn_config->addClickEventListener(CC_CALLBACK_1(Scene16::config, this));
	btn_exit_no->addClickEventListener(CC_CALLBACK_1(Scene16::quit_no, this));
	btn_exit_yes->addClickEventListener(CC_CALLBACK_1(Scene16::quit_yes, this));
	btn_tittle->addClickEventListener(CC_CALLBACK_1(Scene16::back_title, this));
	btn_close->addClickEventListener(CC_CALLBACK_1(Scene16::close_menu, this));
	buttonStart->addClickEventListener(CC_CALLBACK_1(Scene16::startGame, this));
	btn_menu->addClickEventListener(CC_CALLBACK_1(Scene16::pil_menu, this));
	//gambar karakter//
	anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	hiden_character();
	this->addChild(nana_sprite);
	this->addChild(lily_sprite);
	this->addChild(anna_sprite);
	//////////////////
	//background//
	if (HomeMenu::nilai_teks > 40)
		background->setTexture("bg/puncak.jpg");
	/////////////
	return true;
}
void Scene16::hiden_character()
{
	lily_sprite->setScale(0);
	anna_sprite->setScale(0);
	nana_sprite->setScale(0);
}
void Scene16::delay_game(float dt)
{
	detik++;

	if (detik == 4)
	{
		isi_teks();
		this->schedule(schedule_selector(Scene16::teksJalan), Option::speed_teks);
		unschedule(schedule_selector(Scene16::delay_game));
		detik = 0;
	}
	else if (detik == 3)
		buttonStart->setScale(1);
}


void Scene16::pil_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1400, 780)));
	btn_menu->setScale(0);

}

void Scene16::close_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1600, 780)));
	btn_menu->setScale(1);
}

void Scene16::back_title(Ref* sender)
{

	HomeMenu::btn_sound();
	bg_exit->setScale(1);
	kosong->setScale(1);
	btn_exit_no->setScale(1);
	btn_exit_yes->setScale(1);
	label_quit_no->setScale(1);
	label_quit_yes->setScale(1);

}

void Scene16::config(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, Option::scene(), Color3B(255, 255, 255)));
	})));

}
void Scene16::save_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, SaveGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene16::load_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, LoadGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene16::delay(float dt)
{
	if (detik == 1)
	{
		unschedule(schedule_selector(Scene16::delay));
		buttonStart->setScale(1);
		if (HomeMenu::nilai_teks == 41)
		{
			anna_sprite->setScale(0.6);
			this->schedule(schedule_selector(Scene16::teksJalan), Option::speed_teks);
		}
		detik = 0;
	}
	detik++;
}
void Scene16::startGame(Ref* sender)
{
	unschedule(schedule_selector(Scene16::teksJalan));
	HomeMenu::btn_sound();
	HomeMenu::nilai_teks++;
	isi_teks();
	teks_1->setOpacity(0);
	i = 0;
	log("Nilai teks = %d", HomeMenu::nilai_teks);
	if (HomeMenu::nilai_teks == 41)
	{
		hiden_character();
		buttonStart->setScale(0);
		if (HomeMenu::nilai_teks > 40)
			background->setTexture("bg/puncak.jpg");
		this->schedule(schedule_selector(Scene16::delay), 1.f);
	}
	else if (HomeMenu::nilai_teks == 138)
	{
		HomeMenu::nilai_teks = 1;
		this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
		{
			Director::getInstance()->replaceScene(TransitionFade::create(3, HomeMenu::scene(), Color3B(255, 255, 255)));
		})));
	}
	else
		this->schedule(schedule_selector(Scene16::teksJalan), Option::speed_teks);

}

void Scene16::isi_teks()
{
	if (HomeMenu::nilai_teks == 1)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku membuka mataku dan berusaha menggerakkan tubuhku. \nRasanya sulit sekali. Butuh sejenak sampai aku menyadari kalau \naku sedang mengikuti event mendaki gunung.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 2)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku bersusah payah untuk keluar dari sleeping bag \ndan segera disambut dengan hawa dingin. Tubuhku langsung menggigil.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 3)
	{
		nama_kosong();
		teks = __String::createWithFormat("Melihat seluruh orang yang satu tenda denganku masih lengkap, \naku mengambil kesimpulan kalau aku bangun terlalu cepat.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 4)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku keluar dari tenda untuk memastikan kondisi tenda yang lain. \nDi luar aku melihat kalau suasana memang masih sepi.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 5)
	{
		anna();
		teks = __String::createWithFormat("\"Kamu bangun cepat sekali.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 6)
	{
		rei();
		teks = __String::createWithFormat("\"Wuah! Kamu mengagetkanku! Serius!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 7)
	{
		rei();
		teks = __String::createWithFormat("\"Kamu sendiri juga bangun lebih awal dariku kan?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 8)
	{
		anna();
		teks = __String::createWithFormat("\"Udaranya sangat dingin sampai membuatku terbangun.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 9)
	{
		rei();
		teks = __String::createWithFormat("\"Seingatku tadi malam aku menyimpan air panas ke dalam termos. \nMau aku buatkan sesuatu?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 10)
	{
		anna();
		teks = __String::createWithFormat("\"Babyccino?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 11)
	{
		rei();
		teks = __String::createWithFormat("\"Ahahahaha! Maaf sekali Nona, untuk saat ini kami hanya \nmenyediakan teh jahe dan kopi sachet.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 12)
	{
		anna();
		teks = __String::createWithFormat("\"Kalau begitu teh jahe saja. Jangan banyak-banyak jahenya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 13)
	{
		hiden_character();
		rei();
		teks = __String::createWithFormat("\"Baik Nona, mohon tunggu sebentar.\"")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 14)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku membuatkan teh jahe untuk Anna dan kopi untukku. \nKarena bangun pertama kali, aku memutuskan untuk merebus air \nuntuk anggota lain nantinya.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 15)
	{
		rei();
		teks = __String::createWithFormat("\"Maaf menunggu lama, silahkan teh jahenya. \nAku juga membawakan makanan ringan.\"")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 16)
	{
		anna();
		teks = __String::createWithFormat("\"Terimakasih. Untung saja Rei juga sudah bangun.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 17)
	{
		rei();
		teks = __String::createWithFormat("\"Entah kenapa aku terbangun. \nTapi bukan kamu kan yang membangunkanku?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 18)
	{
		anna();
		teks = __String::createWithFormat("\"Aku tidak mungkin menyelinap masuk \nke tenda laki-laki, bodoh.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 19)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Tepat ketika aku tidak sengaja menelan sedikit ampas kopi, \nNana tiba-tiba mendekatiku dan duduk persis di sebelahku.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 20)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku terbatuk-batuk, berusaha menyingkirkan ampas kopi \ndari tenggorokanku.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 21)
	{
		anna();
		teks = __String::createWithFormat("\"Apa-apaan reaksi itu?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 22)
	{
		rei();
		teks = __String::createWithFormat("\"Bu-bukan, ini.. aku tersedak kopi. \nTapi, apa yang kamu lakukan?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 23)
	{
		anna();
		teks = __String::createWithFormat("\"Aku tidak kuat dengan hawa dinginnya, jadi aku terpaksa.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 24)
	{
		rei();
		teks = __String::createWithFormat("\"O-oh..\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 25)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Sekarang aku jadi tidak bisa menoleh ke samping.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 26)
	{
		rei();
		teks = __String::createWithFormat("\"Bagaimana kondisi tubuhmu? Apa terasa sakit?\"")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 27)
	{
		anna();
		teks = __String::createWithFormat("\"Agak pegal sih, tapi aku yakin masih kuat \nuntuk ke puncak. Kamu?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 28)
	{
		rei();
		teks = __String::createWithFormat("\"Kurang lebih sama denganmu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 29)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Tak lama setelah kami berbincang, Lily keluar dari tendanya. \nDia menengok ke kanan dan kiri sampai akhirnya menyadari keberadaan \nkami.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 30)
	{
		lily();
		teks = __String::createWithFormat("\"Wah, kakak bangun pagi sekali.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 31)
	{
		anna();
		teks = __String::createWithFormat("\"Selamat pagi Lily.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2-300, 768 / 2 + 50));

		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2+300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 32)
	{
		hiden_character();
		rei();
		teks = __String::createWithFormat("\"Aku sudah merebus air di sana. \nTolong matikan kompornya kalau sudah mendidih.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 33)
	{
		lily();
		teks = __String::createWithFormat("\"Terimakasih Kak Rei.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 34)
	{
		hiden_character();
		rei();
		teks = __String::createWithFormat("\"Kalau Nana..\"")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 35)
	{
		rei();
		teks = __String::createWithFormat("\"Ah itu dia.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 36)
	{
		lily();
		teks = __String::createWithFormat("\"Sepertinya aku membangunkan Nana ketika hendak keluar dari tenda.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l4.png");
		lily_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 37)
	{
		rei();
		teks = __String::createWithFormat("\"Kalau begitu, sekalian aku bangunkan semua orang. \nMari kita bersiap untuk pendakian menuju puncak.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 38)
	{
		hiden_character();
		anna();
		teks = __String::createWithFormat("\"Aku juga akan membantu membangunkan orang-orang.\"")->getCString();
		teks_1->setString(teks);

	}
	else if (HomeMenu::nilai_teks == 39)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Membuat semua orang terbangun ternyata sangat merepotkan \nkarena kebanyakan dari mereka mengeluhkan hawa dingin \ndan menolak untuk bangun.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 40)
	{
		nama_kosong();
		teks = __String::createWithFormat("Seusai sarapan, kami melakukan pemanasan bersama \nuntuk mempersiapkan diri menuju puncak.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 41)
	{
		anna();
		teks = __String::createWithFormat("\"Waaahh! Akhirnya!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 42)
	{
		lily();
		teks = __String::createWithFormat("\"Sepertinya kita tepat waktu sekali sampainya.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l5.png");
		lily_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 43)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Pemandangannya sangat indah dengan matahari yang sedikit mengintip \ndari balik lembah.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 44)
	{
		anna();
		teks = __String::createWithFormat("\"Hei! Hei! Ayo kita foto bersama\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 45)
	{
		lily();
		teks = __String::createWithFormat("\"Biar aku bantu mengambilkan gambarnya kak.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 46)
	{
		rei();
		teks = __String::createWithFormat("\"Aku tidak usah. Aku tidak begitu suka foto.\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l1.png");
		lily_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 47)
	{
		hiden_character();
		nana();
		teks = __String::createWithFormat("\"Rei harus ikut juga.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 48)
	{
		anna();
		teks = __String::createWithFormat("\"Ayo! Mungkin ini terakhir kalinya kamu pergi ke puncak lho!\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/1.png");
		nana_sprite->setPosition(Vec2(1366 / 2 - 300, 768 / 2 + 50));

		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2 + 300, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 49)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Benar sekali. Aku sudah memutuskan tidak akan melakukan \nhal ini lagi. Setidaknya tidak dalam beberapa \ndekade ke depan.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 50)
	{
		nama_kosong();
		teks = __String::createWithFormat("Anna menarik tanganku untuk memaksaku berada \ndiantara Anna dan Nana.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 51)
	{
		lily();
		teks = __String::createWithFormat("\"Kakak! Wajahmu terlalu suram untuk difoto!\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l3.png");
		lily_sprite->setPosition(Vec2(1366 / 2 , 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 52)
	{
		rei();
		teks = __String::createWithFormat("\"Berisik!\"")->getCString();
		teks_1->setString(teks);
		lily_sprite->setScale(0.6);
		lily_sprite->setTexture("character/lily/l3.png");
		lily_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 53)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Mereka kemudian menghabiskan waktu untuk mengambil foto \nsementara matahari semakin naik mendaki langit.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 54)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku memutuskan untuk menikmati pemandangan yang tersaji \ndi depan mataku. Aku terkejut ketika beberapa orang \nberteriak-teriak untuk merayakan keberhasilan mereka.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 55)
	{
		nama_kosong();
		teks = __String::createWithFormat("Setelah kami menghabiskan banyak waktu di puncak dan mulai bosan, \nkami mengambil foto bersama untuk yang terakhir kalinya \nsebelum turun kembali ke tenda.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 56)
	{
		anna();
		teks = __String::createWithFormat("\"Rei.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 57)
	{
		rei();
		teks = __String::createWithFormat("\"Hm?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 58)
	{
		anna();
		teks = __String::createWithFormat("\"Tunggu sebentar, boleh?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 59)
	{
		rei();
		teks = __String::createWithFormat("\"Kenapa memangnya? Yang lain sudah mulai turun, \nayo kita bergegas.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 60)
	{
		anna();
		teks = __String::createWithFormat("\"Se-sebentar saja.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 61)
	{
		nama_kosong();
		teks = __String::createWithFormat("Orang ini, apa dia masih belum bosan melihat \npemandangan di sini?")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 62)
	{
		anna();
		teks = __String::createWithFormat("\"Um, aku ingin mengatakan sesuatu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 63)
	{
		rei();
		teks = __String::createWithFormat("\"Apa itu?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 64)
	{
		anna();
		teks = __String::createWithFormat("\"Itu.. aku..\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 65)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tunggu sebentar. Ada apa dengan situasi ini. \nKenapa kesannya seperti Anna ingin.. \nah, tidak mungkin.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 66)
	{
		rei();
		teks = __String::createWithFormat("\"Tidak kuat untuk turun ke bawah?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 67)
	{
		anna();
		teks = __String::createWithFormat("\"Bu-bukan.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 68)
	{
		rei();
		teks = __String::createWithFormat("\"Kamu ingin.. jangan-jangan..\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 69)
	{
		anna();
		teks = __String::createWithFormat("\"Ah, tidak-tidak, biar aku yang mengatakan-\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 70)
	{
		rei();
		teks = __String::createWithFormat("\"Pipis?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 71)
	{
		nama_kosong();
		teks = __String::createWithFormat("Anna menamparku dengan pelan, tapi tetap sakit.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 72)
	{
		anna();
		teks = __String::createWithFormat("\"Bo-bodoh! Rei pasti seperti ini!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 73)
	{
		rei();
		teks = __String::createWithFormat("\"Ha? Aku cuma berusaha membantumu mengatakan \napa yang ingin kamu katakan!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 74)
	{
		anna();
		teks = __String::createWithFormat("\"Tetap saja bodoh.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 75)
	{
		rei();
		teks = __String::createWithFormat("\"Kalau begitu cepat katakan apa maumu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 76)
	{
		anna();
		teks = __String::createWithFormat("\"Aku.. Aku!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 77)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku melihat Anna menggenggam erat kedua tangannya \nseolah ingin meninjuku.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 78)
	{
		nama_kosong();
		teks = __String::createWithFormat("Oi, oi. Ini tidak mungkin 'itu' kan? \nTidak, jangan bilang kalau benar. \nAku tidak siap untuk hal ini.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 79)
	{
		anna();
		teks = __String::createWithFormat("\"Aku! Suka! Padamu! Bodoh!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX (- 0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 80)
	{
		hiden_character();
		rei();
		teks = __String::createWithFormat("\"A-\"")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 81)
	{
		nama_kosong();
		teks = __String::createWithFormat("Matahari terbit sepenuhnya ketika Anna menyelesaikan \nkata-katannya. Sementara itu, tidak ada kata yang bisa keluar \ndari mulutku.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 82)
	{
		nama_kosong();
		teks = __String::createWithFormat("Kami hanya memandangi satu-sama-lain selama entah \nberapa lama. Angin yang membawa hawa dingin melewati kami \ndan membawa kesadaranku kembali.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 83)
	{
		anna();
		teks = __String::createWithFormat("\"Ka-katakan sesuatu bodoh.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 84)
	{
		rei();
		teks = __String::createWithFormat("\"I-Iya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 85)
	{
		rei();
		teks = __String::createWithFormat("\"Ah! Maksudku, bukan 'iya' untuk itu. \nAh! Tidak, bukan! Aku-\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 86)
	{
		rei();
		teks = __String::createWithFormat("\"Aku tidak tahu apa yang harus aku katakan.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 87)
	{
		rei();
		teks = __String::createWithFormat("\"Rasanya tiba-tiba dan aku tidak pernah bersiap \nuntuk berada di situasi seperti ini.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 88)
	{
		anna();
		teks = __String::createWithFormat("\"Malah aneh kalau kamu sudah mempersiapkan diri \nuntuk ini.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 89)
	{
		rei();
		teks = __String::createWithFormat("\"Benar juga.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 90)
	{
		rei();
		teks = __String::createWithFormat("\"Aku..\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 91)
	{
		anna();
		teks = __String::createWithFormat("\"Sudahlah, ayo turun ke tenda.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 92)
	{
		rei();
		teks = __String::createWithFormat("\"Eh? Tapi aku belum..\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 93)
	{
		anna();
		teks = __String::createWithFormat("\"Aku memang tidak mengharapkan jawaban sekarang. \nAku cuma mau mengatakannya saja.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 94)
	{
		anna();
		teks = __String::createWithFormat("\"Wahhh. Rasanya lega sekali.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 95)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Mengungkapkan perasaan, atau menjawab perasaan seseorang, \ntidak pernah terbesit sekalipun di kepalaku.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 96)
	{
		nama_kosong();
		teks = __String::createWithFormat("Bohong. Sebagai laki-laki, tentunya aku ingin \nhal itu bisa terjadi. Tapi, untuk benar-benar secara nyata \nberada di situasi tersebut saat ini...")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 97)
	{
		nama_kosong();
		teks = __String::createWithFormat("Anna pasti sangat berani bisa mengatakannya. \nMeskipun dia malah berteriak dan memanggilku bodoh.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 98)
	{
		rei();
		teks = __String::createWithFormat("\"Bodoh!\"")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 99)
	{
		anna();
		teks = __String::createWithFormat("\"A-apa?!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	else if (HomeMenu::nilai_teks == 100)
	{
		rei();
		teks = __String::createWithFormat("\"Aku! Juga! Suka! Padamu! Bodoh!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 101)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Kakiku terasa lemas sampai aku tidak kuat berdiri. \nAku kemudian duduk di tanah.")->getCString();
		teks_1->setString(teks);
	}
	if (HomeMenu::nilai_teks == 102)
	{
		rei();
		teks = __String::createWithFormat("\"Dasar, bagaimana kamu bisa mengatakan hal \nmemalukan seperti itu?\"")->getCString();
		teks_1->setString(teks);
	}
	if (HomeMenu::nilai_teks == 103)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku menatap matanya dan baru menyadari kalau \ndia sedikit menangis.")->getCString();
		teks_1->setString(teks);
	}
	if (HomeMenu::nilai_teks == 104)
	{
		anna();
		teks = __String::createWithFormat("\"Kamu juga barusan mengatakannya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 105)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tanpa sadar aku mengeluarkan tawa kecil yang aneh. \nGawat, sepertinya aku mulai sedikit gila.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 106)
	{
		rei();
		teks = __String::createWithFormat("\"Apa kamu yakin? Seperti yang kamu selalu \nkatakan, aku ini bodoh.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 107)
	{
		anna();
		teks = __String::createWithFormat("\"Ya, aku tahu betul mengenai hal itu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 108)
	{
		rei();
		teks = __String::createWithFormat("\"Aku juga payah dalam berbagai hal.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 109)
	{
		anna();
		teks = __String::createWithFormat("\"Tidak dalam berbagai hal.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 110)
	{
		rei();
		teks = __String::createWithFormat("\"Jadi aku memang payah ya?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 111)
	{
		anna();
		teks = __String::createWithFormat("\"Aku yakin Rei. Aku tidak akan bisa mengatakan \nhal seperti itu kalau aku tidak yakin.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 112)
	{
		rei();
		teks = __String::createWithFormat("\"Tapi aku.. astaga Anna.. perbedaan diantara kita \nterlalu jauh.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 113)
	{
		anna();
		teks = __String::createWithFormat("\"Aku tidak keberatan.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 114)
	{
		rei();
		teks = __String::createWithFormat("\"Sial, aku benar-benar memalukan untuk menjadi.. \num..\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 115)
	{
		anna();
		teks = __String::createWithFormat("\"Menjadi?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 116)
	{
		rei();
		teks = __String::createWithFormat("\"Kamu tahu apa yang aku ingin katakan. \nLihat kan, aku bahkan tidak sanggup mengatakan hal \nsepele seperti itu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 117)
	{
		anna();
		teks = __String::createWithFormat("\"Sudahlah Rei, berhenti merendahkan dirimu seperti itu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 118)
	{
		hiden_character();
		nama_kosong();
		teks = __String::createWithFormat("Anna memelukku. Aku membelalakkan mataku karena \nterkejut. Eh? Apa ini? Apa yang harus aku lakukan?")->getCString();
		teks_1->setString(teks);
	}
	if (HomeMenu::nilai_teks == 119)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku memutuskan untuk membalas pelukannya, \nnamun dengan cepat segera aku lepaskan kembali.")->getCString();
		teks_1->setString(teks);
	}
	if (HomeMenu::nilai_teks == 120)
	{
		rei();
		teks = __String::createWithFormat("\"Kemudian, uh.. apa yang harus kita lakukan \nsetelah ini?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K7.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 121)
	{
		anna();
		teks = __String::createWithFormat("\"Aku belum memikirkannya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 122)
	{
		rei();
		teks = __String::createWithFormat("\"Hah?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 123)
	{
		anna();
		teks = __String::createWithFormat("\"Habisnya, aku tidak menyangka kalau Rei \nakan menjawabnya langsung.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 124)
	{
		rei();
		teks = __String::createWithFormat("\"Hehehe. Sepertinya kamu terlalu meremehkanku.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 125)
	{
		anna();
		teks = __String::createWithFormat("\"Iya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 126)
	{
		rei();
		teks = __String::createWithFormat("\"Bagaimana kalau kita tidak membahas masalah ini sementara?\nTidak hari ini.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 127)
	{
		rei();
		teks = __String::createWithFormat("\"Maksudku, menurutku terlalu tiba-tiba untuk \nmenjelaskan hal ini pada Nana sekarang.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 128)
	{
		anna();
		teks = __String::createWithFormat("\"Benar juga. Aku setuju denganmu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 129)
	{
		rei();
		teks = __String::createWithFormat("\"Besok Senin, aku yang akan mengatakanya pada Nana.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 130)
	{
		anna();
		teks = __String::createWithFormat("\"Tidak. Bukan hanya kamu. \nAku juga akan menjelaskannya.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2 + 50));
	}
	if (HomeMenu::nilai_teks == 131)
	{
		hiden_character();
		rei();
		teks = __String::createWithFormat("\"Baiklah kalau begitu.\"")->getCString();
		teks_1->setString(teks);
	}
	if (HomeMenu::nilai_teks == 132)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku bangkit dan melihat indahnya pemandangan \ndi atas puncak gunung ini untuk yang terakhir kalinya.")->getCString();
		teks_1->setString(teks);
	}
	if (HomeMenu::nilai_teks == 133)
	{
		nama_kosong();
		teks = __String::createWithFormat("Rasanya aku baru saja melihatnya, tapi \nuntuk kali ini pemandangan itu terasa berbeda.")->getCString();
		teks_1->setString(teks);
	}
	if (HomeMenu::nilai_teks == 134)
	{
		nama_kosong();
		teks = __String::createWithFormat("Kami berdua bergegas turun ke tenda dengan membawa \nperasaan baru yang belum pernah kami rasakan sebelumnya.")->getCString();
		teks_1->setString(teks);
	}
	if (HomeMenu::nilai_teks == 135)
	{
		nama_kosong();
		teks = __String::createWithFormat("Perasaan ini terasa sangat aneh untuk berada \ndalam diriku. Seolah rasanya aku tidak cocok \nmemilikinya.")->getCString();
		teks_1->setString(teks);
	}
	if (HomeMenu::nilai_teks == 136)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tapi, aku cukup yakin akan satu hal. \nPerasaan ini...")->getCString();
		teks_1->setString(teks);
	}
	if (HomeMenu::nilai_teks == 137)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tidak buruk juga.")->getCString();
		teks_1->setString(teks);
	}
}


void Scene16::quit_yes(Ref* sender)
{
	HomeMenu::btn_sound();
	HomeMenu::nilai_logo = true;

	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		Director::getInstance()->replaceScene(TransitionFade::create(3, HomeMenu::scene(), Color3B(255, 255, 255)));
	})));
} //button tekan exit yes

void Scene16::quit_no(Ref* sender)
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
void Scene16::teksJalan(float dt)
{

	teks_satu();
}

void Scene16::teks_satu()
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
		unschedule(schedule_selector(Scene16::teksJalan));
	}
}

void Scene16::rei()
{
	auto teks_nama = __String::createWithFormat("Rei")->getCString();
	nama->setString(teks_nama);
}
void Scene16::anna()
{
	auto teks_nama = __String::createWithFormat("Anna")->getCString();
	nama->setString(teks_nama);
}
void Scene16::nana()
{
	auto teks_nama = __String::createWithFormat("Nana")->getCString();
	nama->setString(teks_nama);
}
void Scene16::lily()
{
	auto teks_nama = __String::createWithFormat("Lily")->getCString();
	nama->setString(teks_nama);
}
void Scene16::nama_kosong()
{
	auto teks_nama = __String::createWithFormat("")->getCString();
	nama->setString(teks_nama);
}
void Scene16::nama_titik()
{
	auto teks_nama = __String::createWithFormat("......")->getCString();
	nama->setString(teks_nama);
}
void Scene16::wali()
{
	auto teks_nama = __String::createWithFormat("Wali Kelas")->getCString();
	nama->setString(teks_nama);
}


