#include "Scene1.h"
#include "Scene1b.h"
#include "Scene1a.h"
#include "Option.h"
#include "HomeMenu.h"
#include "SaveGame.h"
#include "LoadGame.h"

USING_NS_CC;



Scene* Scene1::scene()
{
	return Scene1::create();
}

bool Scene1::init()
{
	if (!Scene::init())
	{
		return false;
	}
	bgm->playBackgroundMusic("music/scene1.mp3", true);
	HomeMenu::game = 1;
	

	//background//
	background->setPosition(Vec2(0, 0));
	background->setAnchorPoint(Vec2(0, 0));	

	this->addChild(background,0);

	background->setScale(1);
	/////////////
	
	this->schedule(schedule_selector(Scene1::delay_game), 1);

	buttonStart->setPosition(Vec2(1366/2, 10));
	buttonStart->setScale(0);
	buttonStart->setAnchorPoint(Vec2(0.5, 0));
	this->addChild(buttonStart, 2);

	//bagian button menu//
	btn_menu->setPosition(Vec2(1313, 714));
	btn_menu->setAnchorPoint(Vec2(0.5, 0.5));
	this->addChild(btn_menu,2);
	bg_menu_btn->setPosition(Vec2(1600, 780)); //1255,384 (movenya)
	bg_menu_btn->setAnchorPoint(Vec2(0.5, 0.5));
	bg_menu_btn->setOpacity(150);
	this->addChild(bg_menu_btn,2);
	bg_menu_btn->addChild(btn_tittle);
	bg_menu_btn->addChild(btn_save);
	bg_menu_btn->addChild(btn_load);
	bg_menu_btn->addChild(btn_config);
	bg_menu_btn->addChild(btn_close);
	btn_tittle->setPosition(Vec2(bg_menu_btn->getContentSize().width/2-110, 330));
	btn_save->setPosition(Vec2(bg_menu_btn->getContentSize().width / 2-110, 260));
	btn_load->setPosition(Vec2(bg_menu_btn->getContentSize().width / 2-110, 190));
	btn_config->setPosition(Vec2(bg_menu_btn->getContentSize().width / 2-110, 120));
	btn_close->setPosition(Vec2(bg_menu_btn->getContentSize().width / 2-110, 50));
	btn_tittle->setAnchorPoint(Vec2(0.5, 0.5));
	btn_save->setAnchorPoint(Vec2(0.5, 0.5));
	btn_load->setAnchorPoint(Vec2(0.5, 0.5));
	btn_config->setAnchorPoint(Vec2(0.5, 0.5));
	btn_close ->setAnchorPoint(Vec2(0.5, 0.5));
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
	nama->setPosition(Vec2(50,190));
	nama->setAnchorPoint(Vec2(0, 1));
	nama->setColor(Color3B::BLACK);

	buttonStart->addChild(teks_1);
	buttonStart->addChild(nama);

	//milih jawaban//
	bg_kosong->setPosition(Vec2(0, 0));
	bg_kosong->setAnchorPoint(Vec2(0, 0));
	bg_choose->setPosition(Vec2(1366 / 2, 768 / 2));
	bg_choose->setAnchorPoint(Vec2(0.5, 0.5));
	btn_choose_left->setPosition(Vec2(bg_choose->getContentSize().width/2 -30, bg_choose->getContentSize().height / 2));
	btn_choose_left->setAnchorPoint(Vec2(1, 0.5));
	btn_choose_right->setPosition(Vec2(bg_choose->getContentSize().width/2 +30, bg_choose->getContentSize().height / 2));
	btn_choose_right->setAnchorPoint(Vec2(0, 0.5));
	this->addChild(bg_choose,5);
	this->addChild(bg_kosong,4);
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
	btn_load->addClickEventListener(CC_CALLBACK_1(Scene1::load_game, this));
	btn_save->addClickEventListener(CC_CALLBACK_1(Scene1::save_game, this));
	btn_config->addClickEventListener(CC_CALLBACK_1(Scene1::config, this));
	btn_exit_no->addClickEventListener(CC_CALLBACK_1(Scene1::quit_no, this));
	btn_exit_yes->addClickEventListener(CC_CALLBACK_1(Scene1::quit_yes, this));
	btn_tittle->addClickEventListener(CC_CALLBACK_1(Scene1::back_title, this));
	btn_close->addClickEventListener(CC_CALLBACK_1(Scene1::close_menu, this));
	buttonStart->addClickEventListener(CC_CALLBACK_1(Scene1::startGame, this));
	btn_menu->addClickEventListener(CC_CALLBACK_1(Scene1::pil_menu, this));
	btn_choose_left->addClickEventListener(CC_CALLBACK_1(Scene1::choose_left, this));
	btn_choose_right->addClickEventListener(CC_CALLBACK_1(Scene1::choose_right, this));


	//gambar karakter//
	anna_sprite->setPosition(Vec2(1366 / 2, 768 / 2+50));
	nana_sprite->setPosition(Vec2(1366 / 2, 768 / 2+50));
	hiden_character();
	this->addChild(nana_sprite);
	this->addChild(anna_sprite);
	//////////////////
		if (HomeMenu::nilai_teks > 5 && HomeMenu::nilai_teks < 11)
			background->setTexture("bg/menuju_kampus_1.jpg");
		else if (HomeMenu::nilai_teks > 10 && HomeMenu::nilai_teks < 16)
			background->setTexture("bg/halte_rumah.jpg");
		else if (HomeMenu::nilai_teks > 15 && HomeMenu::nilai_teks < 57)
			background->setTexture("bg/lingkungan_kampus_1.jpg");
		else if (HomeMenu::nilai_teks > 56)
			background->setTexture("bg/lab_database.jpg");
	return true;
}
void Scene1::hiden_character()
{
	anna_sprite->setScale(0);
	nana_sprite->setScale(0);
}
void Scene1::delay_game(float dt)
{
	detik++;

	if (detik == 4)
	{
		isi_teks();
		this->schedule(schedule_selector(Scene1::teksJalan), Option::speed_teks);
		unschedule(schedule_selector(Scene1::delay_game));
		detik = 0;
	}
	else if(detik == 3)
		buttonStart->setScale(1);
}


void Scene1::pil_menu(Ref* sender)
{
	HomeMenu::btn_sound();
		bg_menu_btn->runAction(MoveTo::create(0.2,Vec2(1400, 780)));
		btn_menu->setScale(0);

}

void Scene1::close_menu(Ref* sender)
{
	HomeMenu::btn_sound();
	bg_menu_btn->runAction(MoveTo::create(0.2, Vec2(1600, 780)));	
	btn_menu->setScale(1);
}

void Scene1::back_title(Ref* sender)
{
	
	HomeMenu::btn_sound();
	bg_exit->setScale(1);
	kosong->setScale(1);
	btn_exit_no->setScale(1);
	btn_exit_yes->setScale(1);
	label_quit_no->setScale(1);
	label_quit_yes->setScale(1);
	
}

void Scene1::config(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, Option::scene(), Color3B(255, 255, 255)));
	})));

}
void Scene1::save_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, SaveGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene1::load_game(Ref* sender)
{
	HomeMenu::btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		//Ini adalah kode untuk berpindah scene
		Director::getInstance()->pushScene(TransitionFade::create(0.5, LoadGame::scene(), Color3B(255, 255, 255)));
	})));
}
void Scene1::delay(float dt)
{	
	if (detik == 1)
	{
		unschedule(schedule_selector(Scene1::delay));
		buttonStart->setScale(1);
		if (HomeMenu::nilai_teks == 6 || HomeMenu::nilai_teks == 11 || HomeMenu::nilai_teks == 16 || HomeMenu::nilai_teks == 57)
		{
			this->schedule(schedule_selector(Scene1::teksJalan), Option::speed_teks);
		}
		detik = 0;
	}
	detik++;
}
void Scene1::startGame(Ref* sender)
{
	unschedule(schedule_selector(Scene1::teksJalan));
	if (!textSelesai)
	{
		textSelesai = true;
		//isi_teks();
		this->schedule(schedule_selector(Scene1::teksJalan),0);
	}
	else
	{
		textSelesai = false;
		HomeMenu::nilai_teks++;
		isi_teks();
		teks_1->setOpacity(0);
		i = 0;
		log("Nilai teks = %d", HomeMenu::nilai_teks);
		if (HomeMenu::nilai_teks == 6 || HomeMenu::nilai_teks == 11 || HomeMenu::nilai_teks == 16 || HomeMenu::nilai_teks == 57)
		{
			buttonStart->setScale(0);
			if (HomeMenu::nilai_teks > 5 && HomeMenu::nilai_teks < 11)
				background->setTexture("bg/menuju_kampus_1.jpg");
			else if (HomeMenu::nilai_teks > 10 && HomeMenu::nilai_teks < 16)
				background->setTexture("bg/halte_rumah.jpg");
			else if (HomeMenu::nilai_teks > 15 && HomeMenu::nilai_teks < 57)
				background->setTexture("bg/lingkungan_kampus_1.jpg");
			else if (HomeMenu::nilai_teks > 56)
				background->setTexture("bg/lab_database.jpg");
			this->schedule(schedule_selector(Scene1::delay), 1.f);
		}
		else if (HomeMenu::nilai_teks == 113)
		{
			bg_kosong->setScale(1);
			bg_choose->setScale(1);
		}
		else
			this->schedule(schedule_selector(Scene1::teksJalan), Option::speed_teks);
	}
	HomeMenu::btn_sound();
}

void Scene1::choose_left(Ref* sender)
{
	HomeMenu::btn_sound();
	HomeMenu::nilai_teks = 1;
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		Director::getInstance()->replaceScene(TransitionFade::create(3, Scene1a::scene(), Color3B(255, 255, 255)));
	})));
	
}
void Scene1::choose_right(Ref* sender)
{
	HomeMenu::btn_sound();
	HomeMenu::nilai_teks = 1;
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		Director::getInstance()->replaceScene(TransitionFade::create(3, Scene1b::scene(), Color3B(255, 255, 255)));
	})));
	
}

void Scene1::isi_teks()
{
	if (HomeMenu::nilai_teks == 1)
	{	
		alarm->getInstance()->playEffect("sfx/alarm.mp3",false, 1.0f, 1.0f, 1.0f);
		teks = __String::createWithFormat("Aku terusik oleh dering alarm yang berhasil membangunkanku dari tidur.\nMungkin lebih tepatnya ketiduran.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 2)
	{
		alarm->getInstance()->pauseAllEffects();
		teks = __String::createWithFormat("Layar laptop di depanku masih menyala dengan sangat cerah dalam \nkegelapan kamarku, menampilkan menu pause dari game horor yang \naku mainkan tadi malam mungkin sampai pagi tadi.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 3)
	{
		teks = __String::createWithFormat("Masih dengan mata yang setengah tertutup, \naku meraba-raba mejaku, berusaha mencari ponselku \nyang masih terus menderingkan alarm.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 4)
	{
	
		teks = __String::createWithFormat("Aku menemukan ponselku diantara tumpukan komik \ndan segera mematikan alarmnya.\nDengan malas, aku bangkit dan meregangkan tubuh.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 5)
	{

	
		teks = __String::createWithFormat("Setelah tulangku mengeluarkan bunyi retakan yang memuaskan, \naku menyalakan lampu kamarku untuk membantuku tetap bangun.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 6)
	{
		
		teks = __String::createWithFormat("Pagi ini terasa sangat dingin.\nSampai-sampai tadi aku sempat berpikir untuk tidak mandi.\nNamun tentu pada akhirnya aku tetap mandi dengan cepat.")->getCString();
		teks_1->setString(teks);

	}
	else if (HomeMenu::nilai_teks == 7)
	{
	
		teks = __String::createWithFormat("Aku melangkah sambil berusaha mengumpulkan semangat \nuntuk memulai awal semester baru ini.\nSemester lima, dan tahun terakhir aku kuliah untuk memperoleh gelar D3.")->getCString();
		teks_1->setString(teks);
	
	}
	else if (HomeMenu::nilai_teks == 8)
	{
	
		teks = __String::createWithFormat("Meneruskan perjalananku menuju halte bus,\naku mencoba mengingat-ingat kapan aku ketiduran.")->getCString();
		teks_1->setString(teks);
	
	}
	else if (HomeMenu::nilai_teks == 9)
	{
	
		teks = __String::createWithFormat("Aku ingin mengetahui berapa lama aku tidur, \nsehingga aku setidaknya bisa mengira-ira, apakah nanti \naku akan ketiduran di kelas atau tidak.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 10)
	{
	
		teks = __String::createWithFormat("Aku akhirnya sampai pada kesimpulan dimana mungkin aku \nakan ketiduran. Yang mana, aku sebenarnya tidak peduli karena ini adalah \nhari pertama di semester baru.")->getCString();
		teks_1->setString(teks);
		
	}
	else if (HomeMenu::nilai_teks == 11)
	{
	
		teks = __String::createWithFormat("Memasuki halte, aku duduk di salah satu kursi kosong yang dingin.\nUntuk saat ini saja, aku benar - benar \ntidak boleh ketiduran.")->getCString();
		teks_1->setString(teks);

	}
	else if (HomeMenu::nilai_teks == 12)
	{
		
		teks = __String::createWithFormat("Ketinggalan bus berarti aku akan menambah poin keterlambatanku, \nyang pada semester lalu cukup banyak untuk membuatku bekerja \nsepanjang setengah waktu libur di kampus untuk kompensasi.")->getCString();
		teks_1->setString(teks);
	
	}
	else if (HomeMenu::nilai_teks == 13)
	{
		teks = __String::createWithFormat("Sedangkan tidur dalam bus bukanlah suatu masalah yang besar.")->getCString();
		teks_1->setString(teks);
		
	}
	else if (HomeMenu::nilai_teks == 14)
	{
		teks = __String::createWithFormat("Kalaupun aku terbawa hingga ke terminal. \nJaraknya cukup dekat dengan kampus, \nsehingga aku hanya perlu naik bus lagi dari terminal ke kampus.")->getCString();
		teks_1->setString(teks);
		
	}
	else if (HomeMenu::nilai_teks == 15)
	{
			
		teks = __String::createWithFormat("Namun tentunya hal itu merepotkan \ndan sebisa mungkin tidak ingin aku lakukan.")->getCString();
		teks_1->setString(teks);
	}

	else if (HomeMenu::nilai_teks == 16)
	{
		teks = __String::createWithFormat("Setelah turun dari bus di halte dekat kampus, aku menghirup udara pagi \nyang segar, berusaha mengusir kantukku.\nSuasana kampus masih cukup sepi.")->getCString();
		teks_1->setString(teks);
		
	}
	else if (HomeMenu::nilai_teks == 17)
	{
		teks = __String::createWithFormat("Inilah permasalahanku. Aku sebenarnya ingin datang \n'tepat waktu', bukan sangat pagi seperti ini.")->getCString();
		teks_1->setString(teks);
		
	}
	else if (HomeMenu::nilai_teks == 18)
	{
		teks = __String::createWithFormat("Namun, karena jadwal keberangkatan bus \nyang tidak memberiku cukup banyak pilihan, aku hanya bisa memilih \nantara datang pagi, atau datang terlambat.")->getCString();
		teks_1->setString(teks);
		
	}
	else if (HomeMenu::nilai_teks == 19)
	{
		rei();
		teks = __String::createWithFormat("\"Nanti aku pasti akan dimarahi.\" \ngumanku sambil menghela nafas.")->getCString();
		teks_1->setString(teks);
		
	}
	else if (HomeMenu::nilai_teks == 20)
	{
		voice->getInstance()->pauseAllEffects();
		voice->getInstance()->playEffect("voice/passage1/20.mp3", false, 1.0f, 1.0f, 1.0f);
		nama_titik();
		teks = __String::createWithFormat("\"Dimarahi oleh siapa?\" tanya seseorang.")->getCString();
		teks_1->setString(teks);	
	}
	else if (HomeMenu::nilai_teks == 21)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Suaranya sangat aku kenal. Mungkin karena itu adalah \nsalah satu dari sedikit suara manusia yang pernah \nmengajakku berbicara di kampus ini.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 22)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku menoleh ke arah suara itu, dan di sanalah dia, \nseorang gadis dengan wajah penuh semangat, \nberdiri di dekatku.")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 23)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku tidak pernah berhenti kagum pada wajah itu")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		
	}
	else if (HomeMenu::nilai_teks == 24)
	{
		nama_kosong();
		teks = __String::createWithFormat("Maksudku, aku hanya akan punya wajah penuh semangat \nseperti itu ketika hari tersebut adalah hari libur.")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		
	}
	else if (HomeMenu::nilai_teks == 25)
	{
		rei();
		teks = __String::createWithFormat("\"Entahlah, mungkin oleh dosen, atau mungkin olehmu\" \njawabku.")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		
	}
	else if (HomeMenu::nilai_teks == 26)
	{
		voice->getInstance()->playEffect("voice/passage1/26.mp3", false, 1.0f, 1.0f, 1.0f);
		nama_titik();
		teks = __String::createWithFormat("\"Eehh? Memangnya kenapa? \nKamu tidak mengerjakan tugas untuk hari ini?\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
	
	}
	else if (HomeMenu::nilai_teks == 27)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Dia adalah teman sekelasku, Anna. \nOrang yang paling banyak berbicara denganku.")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
	}
	else if (HomeMenu::nilai_teks == 28)
	{
		nama_kosong();
		teks = __String::createWithFormat("Namun, itu bukan berarti hal yang istimewa. \nDia berbicara dengan siapapun di kelas, karena dia adalah \nseorang ketua kelas.")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
		
	}
	else if (HomeMenu::nilai_teks == 29)
	{
		nama_kosong();
		teks = __String::createWithFormat("Eh?Aku terdiam sejenak. Mencoba menangkap apa yang dia katakan tadi.")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	
	}
	else if (HomeMenu::nilai_teks == 30)
	{
		rei();
		teks = __String::createWithFormat("\"Eh? Tugas? Ada tugas untuk hari ini?\" \ntanyaku dengan terkejut.")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	
	}
	else if (HomeMenu::nilai_teks == 31)
	{
		voice->getInstance()->playEffect("voice/passage1/31.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Ahahah, sudah kuduga, kamu pasti belum bangun. \nMana mungkin ada tugas, ini kan awal semester\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 32)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Aku berdiri bodoh di hadapannya dengan wajah kecut.")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 33)
	{
		voice->getInstance()->playEffect("voice/passage1/33.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Maaf-maaf, aku hanya mencoba mengumpulkan semangat \nuntuk awal semester\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 34)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Aku rasa semangatmu sudah lebih dari cukup, ketua kelas.\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 35)
	{
		voice->getInstance()->playEffect("voice/passage1/35.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Ehh? Apakah semester ini aku akan menjadi ketua kelas lagi?\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
	}
	else if (HomeMenu::nilai_teks == 36)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("Aku mengangkat bahu.\n\"Aku rasa iya, sampai lulus nanti.\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
	}
	else if (HomeMenu::nilai_teks == 37)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dia adalah ketua kelas kami sejak semester pertama. \nSifatnya, dan nilainya yang tinggi membuat semua orang tunduk padanya. \nMungkin 'tunduk' sedikit berlebihan.")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 38)
	{
		voice->getInstance()->playEffect("voice/passage1/38.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Jadi?\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
	}
	else if (HomeMenu::nilai_teks == 39)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\" 'Jadi?' \"")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
	}
	else if (HomeMenu::nilai_teks == 40)
	{
		voice->getInstance()->playEffect("voice/passage1/40.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Kenapa kamu berpikir kalau kamu akan dimarahi?\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
	}
	else if (HomeMenu::nilai_teks == 41)
	{
		voice->getInstance()->pauseAllEffects();	
		rei();
		teks = __String::createWithFormat("\"Entahlah, kita lihat saja nanti\" \nJawabku. Aku tidak ingin dimarahi sekarang.")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
	}
	else if (HomeMenu::nilai_teks == 42)
	{
		voice->getInstance()->playEffect("voice/passage1/42.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Hmm, terserahlah. Ngomong-ngomong, \nkamu tidak terlihat semangat hari ini.\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 43)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Apakah aku pernah terlihat bersemangat?\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 44)
	{
		rei();
		teks = __String::createWithFormat("\"Lagipula, ini adalah hari masuk setelah libur yang cukup panjang. \nAku sama sekali tidak melihat alasan untuk bersemangat di hari ini.\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 45)
	{
		voice->getInstance()->playEffect("voice/passage1/45.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Memang sih.., tapi semester ini seharusnya berbeda.\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 46)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Kenapa?\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 47)
	{
		voice->getInstance()->playEffect("voice/passage1/47.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Karena game!\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 48)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Aku berpikir sejenak. Memang sih, sebentar lagi \nada game baru yang akan rilis. \nAku tidak sabar untuk memainkannya.")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 49)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tapi bagaimana dia bisa tahu?")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 50)
	{
		voice->getInstance()->playEffect("voice/passage1/50.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Karena game!!\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 51)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Aku masih menatapnya dengan bingung.")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 52)
	{
		voice->getInstance()->playEffect("voice/passage1/52.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Duh, kamu benar-benar tidak tahu ya. Meskipun ini hari pertama, \nsetidaknya kamu perlu membaca jadwal sebelum mulai berangkat \nke kampus\"")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
	}
	else if (HomeMenu::nilai_teks == 53)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Oohh! Jangan-jangan semester ini ada mata kuliah pembuatan game?!\" \nsuaraku tiba-tiba meninggi.")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
	}
	else if (HomeMenu::nilai_teks == 54)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tapi tunggu sebentar. Aku memang menyukai game, \ntapi selama ini hanya sebatas memainkannya saja. \nAku belum tahu pasti apakah aku akan tertarik dengan pembuatan game.")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 55)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku melihat Ana mengangguk dengan penuh semangat dan tersenyum.")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 56)
	{
		nama_kosong();
		teks = __String::createWithFormat("Namun bagaimanapun juga, selama itu berkaitan dengan game, \naku rasa aku akan menyukainya.")->getCString();
		teks_1->setString(teks);
		hiden_character();
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 57)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ketika aku masuk ke dalam kelas, ruangan masih sepi seperti biasanya.")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 58)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku segera menempatkan diriku di bagian tengah ruang kelas. \nTempat yang paling cocok untukku.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 59)
	{
		nama_kosong();
		teks = __String::createWithFormat("Bagian depan adalah tempat orang-orang dengan masa depan cerah. \nOrang-orang semacam Anna. Dan juga tempat untuk orang \nyang terpaksa duduk di depan karena terlambat.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 60)
	{
		nama_kosong();
		teks = __String::createWithFormat("Sementara bagian belakang adalah untuk orang yang merasa \nsalah jurusan atau orang yang hanya peduli pada absensi saja.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 61)
	{
		nama_kosong();
		teks = __String::createWithFormat("Oh ya, di kampusku ini tidak ada istilah 'titip absen'. Tiap kelas jumlah \nmuridnya masih memungkinkan untuk diabsen dosen satu-per-satu.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 62)
	{
		nama_kosong();
		teks = __String::createWithFormat("Awalnya aku selalu duduk di paling belakang. \nNamun seiring bertambahnya pengalaman hidupku, ---")->getCString();
		teks_1->setString(teks);
		
	}
	else if (HomeMenu::nilai_teks == 63)
	{
		nama_kosong();
		teks = __String::createWithFormat("aku menyadari kalau bagian belakang cukup sering diperhatikan dosen.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 64)
	{
		nama_kosong();
		teks = __String::createWithFormat("Hanya dengan sekian detik duduk di kursi kelas,\nrasa kantuk yang sangat hebat menyerangku.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 65)
	{
		rei();
		teks = __String::createWithFormat("\"Aku seharusnya tidak bermain sampai pagi\" gumanku.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 66)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku selalu mengatakan hal itu setiap hari. \nNamun untuk hari ini saja, aku tidak benar-benar menyesal.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 67)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku rasa kita memang harus memanfaatkan waktu libur terakhir \ndengan sebaik mungkin.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 68)
	{
		bel->getInstance()->playEffect("sfx/bel.mp3", false, 1.0f, 1.0f, 1.0f);
		nama_kosong();
		teks = __String::createWithFormat("Bersamaan dengan suara keras bel yang menderu di seluruh \narea kampus, wali kelas kami memasuki ruang kelas.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 69)
	{
		bel->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Tepat waktu sekali. Namun aku tidak terlalu peduli, karena pada setiap \nawal semester, jam pertama digunakan untuk pembekalan.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 70)
	{
		nama_kosong();
		teks = __String::createWithFormat("Pembekalan berisi berbagai motivasi untuk terus \nmempertahankan/meningkatkan nilai kami dan semacamnya.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 71)
	{
		nama_kosong();
		teks = __String::createWithFormat("Wali kelas kami juga memutuskan untuk mengumumkan \nperolehan IPK tertinggi. Hal tersebut dilakukan untuk memacu semangat \npara mahasiswa.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 72)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dan tidak diragukan lagi..")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 73	)
	{
		voice->getInstance()->playEffect("voice/passage1/73.mp3", false, 1.0f, 1.0f, 1.0f);
		wali();
		teks = __String::createWithFormat("\"Anna Vitasha, dengan IP 4.\" \nseru wali kelas, disertai tepuk tangan.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 74)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Aku benar-benar tidak habis pikir, \nbagaimana seseorang bisa memperoleh nilai 4 di seluruh semester. \nBenar-benar tidak masuk akal.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 75)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku sendiri, hanya seorang mahasiswa biasa \ndengan IP rata-rata di kelas.\nMungkin sedikit dibawah rata-rata.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 76)
	{
		nama_kosong();
		teks = __String::createWithFormat("Karena itu, terkadang ketika melihat Anna, \naku merasa sedang berhadapan dengan suatu makhluk \nyang bukan manusia.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 77)
	{
		nama_kosong();
		teks = __String::createWithFormat("Tidak.., aku cukup yakin kalau dia bukan manusia.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 78)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ketika wali kelas hendak mengakhiri pembekalannya, \nketika mataku sudah benar-benar terasa berat, \nbeliau mengumumkan hal yang mengejutkan.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 79)
	{
		voice->getInstance()->playEffect("voice/passage1/79.mp3", false, 1.0f, 1.0f, 1.0f);
		wali();
		teks = __String::createWithFormat("\"Saya harap semester ini akan lebih berwarna, lebih seru, \nkarena kelas kita kedatangan seorang mahasiswi baru. Silahkan masuk.\"")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 80)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Akhir kalimat beliau dibarengi dengan berbagai sorakan, \ntepuk tangan, dan kegaduhan. Bersamaan dengan kegaduhan tersebut, \nmasuk seorang mahasiswi.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 81)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ia tampak seperti seorang putri kerajaan bagiku. \nSenyuman diwajahnya membuat suasana di \nkelas ini menjadi lebih cerah seketika.")->getCString();
		teks_1->setString(teks);
		hiden_character();
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
	}
	else if (HomeMenu::nilai_teks == 82)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku bisa melihat beberapa, mungkin semua anak laki-laki mengeluarkan\nekspresi yang berkata 'sepertinya tahun terakhirku akan lebih indah'.")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
	}
	else if (HomeMenu::nilai_teks == 83)
	{
		voice->getInstance()->playEffect("voice/passage1/83.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Selamat pagi teman-teman. Nama saya Kirana Adriani. \nSaya biasa dipanggil Nana. Saya dari Bandung.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
	}
	else if (HomeMenu::nilai_teks == 84)
	{
		voice->getInstance()->pauseAllEffects();
		voice->getInstance()->playEffect("voice/passage1/84.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Karena pekerjaan orang tua, kami sekeluarga memutuskan untuk \npindah tempat tinggal ke Semarang. Karena itu saya juga pindah kampus \ndan meneruskan kuliah di sini.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
	}
	else if (HomeMenu::nilai_teks == 85)
	{
		voice->getInstance()->pauseAllEffects();
		voice->getInstance()->playEffect("voice/passage1/85.mp3", false, 1.0f, 1.0f, 1.0f);
		nana();
		teks = __String::createWithFormat("\"Saya harap bisa berteman dengan kalian semua hingga lulus nanti.\"")->getCString();
		teks_1->setString(teks);
		nana_sprite->setScale(0.6);
		nana_sprite->setTexture("character/nana/2.png");
	}
	else if (HomeMenu::nilai_teks == 86)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Aneh sekali. Aku tidak pernah mendengar yang namanya \npenerimaan mahasiswa pindah selama ini. \nMungkin aku saja yang tidak tahu.")->getCString();
		teks_1->setString(teks);
		hiden_character();
	}
	else if (HomeMenu::nilai_teks == 87)
	{
		nama_kosong();
		teks = __String::createWithFormat("Selain itu, aku pikir sekarang adalah waktu yang buruk \nuntuk kedatangan mahasiswa baru.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 88)
	{
		nama_kosong();
		teks = __String::createWithFormat("Di kampusku, di Politeknik Negeri Semarang,\nteman sekelas kami telah ditetapkan dari semester pertama, \ndan akan selalu sama hingga akhir semester.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 89)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dengan kata lain, kami telah satu kelas selama dua tahun.\nAku harap dia tipe orang yang mudah bergaul.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 90)
	{
		nama_kosong();
		teks = __String::createWithFormat("Yah, bagaimanapun juga, aku tidak terlalu tertarik.\nHal ini tidak ada kaitannya denganku. Bukan masalahku.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 91)
	{
		nama_kosong();
		teks = __String::createWithFormat("Itulah yang aku pikirkan. Hingga sepulang sekolah..")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 92)
	{
		nama_kosong();
		teks = __String::createWithFormat("Suara gema bel membangunkanku dari tidur. \nAku terkejut karena dua hal: aku tidak menyangka sudah saatnya pulang, \ndan tidak ada yang berusaha membangunkanku.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 93)
	{
		nama_kosong();
		teks = __String::createWithFormat("Dipenuhi rasa syukur, aku segera bersiap pulang.\nTidak sabar untuk melanjutkan game yang sedang aku mainkan.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 94)
	{
		nama_kosong();
		teks = __String::createWithFormat("Seusai pembekalan tadi, ada dua mata kuliah untuk hari ini. Dan sesuai \nagenda, dosen yang datang hanya memberikan gambaran mengenai \nmata kuliah yang akan diberikan selama satu semester ke depan.")->getCString();
		teks_1->setString(teks);
	}
	else if (HomeMenu::nilai_teks == 95)
	{
		nama_kosong();
		teks = __String::createWithFormat("Minggu pertama semester memang masih cukup terasa santai.")->getCString();
		teks_1->setString(teks);

	}
	else if (HomeMenu::nilai_teks == 96)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ketika langkahku hampir mencapai pintu kelas, \naku melihat Anna dengan tergesa-gesa menghampiriku.")->getCString();
		teks_1->setString(teks);

	}
	else if (HomeMenu::nilai_teks == 97)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aduh, apakah dia tahu tadi aku tidur?\nSepertinya dia akan menceramahiku.")->getCString();
		teks_1->setString(teks);

	}
	else if (HomeMenu::nilai_teks == 98)
	{
		voice->getInstance()->playEffect("voice/passage1/98.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Rei, tunggu sebentar!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");

	}
	else if (HomeMenu::nilai_teks == 99)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Ada apa?\"\njawabku dengan memasang wajah polos.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");

	}
	else if (HomeMenu::nilai_teks == 100)
	{
		nama_kosong();
		teks = __String::createWithFormat("Aku benar-benar berharap percakapan ini \nakan selesai dalam satu-dua dialog.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");

	}
	else if (HomeMenu::nilai_teks == 101)
	{
		voice->getInstance()->playEffect("voice/passage1/101.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Aku ingin minta tolong, boleh?\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");

	}
	else if (HomeMenu::nilai_teks == 102)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Sepertinya dia tidak membahas mengenai tidurku.\nDan sepertinya percakapan ini bisa segera aku selesaikan \ndengan mengatakan 'tidak'.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");

	}
	else if (HomeMenu::nilai_teks == 103)
	{
		nama_kosong();
		teks = __String::createWithFormat("Namun aku rasa terlalu kejam bila aku langsung menolaknya.\nSetidaknya akan aku coba dengarkan permintaannya dulu.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K5.png");
	}
	else if (HomeMenu::nilai_teks == 104)
	{
		rei();
		teks = __String::createWithFormat("\"Selama itu sesuatu yang bisa aku lakukan,\ndan selama itu bisa dilakukan dengan cepat.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 105)
	{
		voice->getInstance()->playEffect("voice/passage1/105.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Aku yakin bisa kamu lakukan, \ntapi sepertinya membutuhkan cukup banyak waktu.\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		
	}
	else if (HomeMenu::nilai_teks == 106)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Anna memasang wajah penuh harapan padaku. \nNamun jawaban 'membutuhkan banyak waktu' \nmemberikanku alasan kuat untuk menolaknya.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	
	}
	else if (HomeMenu::nilai_teks == 107)
	{
		nama_kosong();
		teks = __String::createWithFormat("Ketika aku hendak membuka mulut untuk menolaknya..")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setScaleX(-0.6);
		anna_sprite->setTexture("character/anna/K1.png");
		
	}
	else if (HomeMenu::nilai_teks == 108)
	{
		voice->getInstance()->playEffect("voice/passage1/108.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Ah! Ini bukan sesuatu yang bisa kamu tolak!\nKamu harus melakukannya!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
	}
	else if (HomeMenu::nilai_teks == 109)
	{
		voice->getInstance()->pauseAllEffects();
		nama_kosong();
		teks = __String::createWithFormat("Aku rasanya ingin menampar seseorang. \nMungkin orang dihadapanku ini bila tidak ada undang-undang \nkekerasan terhadap perempuan.")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K4.png");
	}
	else if (HomeMenu::nilai_teks == 110)
	{
		voice->getInstance()->playEffect("voice/passage1/110.mp3", false, 1.0f, 1.0f, 1.0f);
		anna();
		teks = __String::createWithFormat("\"Ahh.. aku terburu-buru untuk mengurus kontrak kuliah,\nPokoknya kamu harus mengajak Nana keliling kampus ya!\"")->getCString();
		teks_1->setString(teks);
		anna_sprite->setScale(0.6);
		anna_sprite->setTexture("character/anna/K1.png");
	}
	else if (HomeMenu::nilai_teks == 111)
	{
		voice->getInstance()->pauseAllEffects();
		rei();
		teks = __String::createWithFormat("\"Hei!\" Aku berteriak untuk protes, \nnamun Anna sudah dengan cepat menghilang.")->getCString();
		teks_1->setString(teks);
		 
	}
	else if (HomeMenu::nilai_teks == 112)
	{
		rei();
		teks = __String::createWithFormat("\"Bukannya dia yang tadi disuruh mengajak keliling Nana..\" \ngerutuku.")->getCString();
		teks_1->setString(teks);
		 
	}

}


void Scene1::quit_yes(Ref* sender)
{
	HomeMenu::btn_sound();
	HomeMenu::nilai_logo = true;
	
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{
		Director::getInstance()->replaceScene(TransitionFade::create(3, HomeMenu::scene(), Color3B(255, 255, 255)));
	})));
} //button tekan exit yes

void Scene1::quit_no(Ref* sender)
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
void Scene1::teksJalan(float dt)
{
	
	teks_satu();
}

void Scene1::teks_satu()
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
			unschedule(schedule_selector(Scene1::teksJalan));
			textSelesai = true;
		}
	}
	else
	{
		teks_1->setOpacity(255);
		teks_1->setColor(Color3B::BLACK);
		unschedule(schedule_selector(Scene1::teksJalan));
	}
	
}

void Scene1::rei()
{
	auto teks_nama = __String::createWithFormat("Rei")->getCString();
	nama->setString(teks_nama);
}
void Scene1::anna()
{
	auto teks_nama = __String::createWithFormat("Anna")->getCString();
	nama->setString(teks_nama);
}
void Scene1::nana()
{
	auto teks_nama = __String::createWithFormat("Nana")->getCString();
	nama->setString(teks_nama);	
}
void Scene1::nama_kosong()
{
	auto teks_nama = __String::createWithFormat("")->getCString();
	nama->setString(teks_nama);
}
void Scene1::nama_titik()
{
	auto teks_nama = __String::createWithFormat("......")->getCString();
	nama->setString(teks_nama);
}
void Scene1::wali()
{
	auto teks_nama = __String::createWithFormat("Wali Kelas")->getCString();
	nama->setString(teks_nama);
}


