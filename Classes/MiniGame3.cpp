#include "MiniGame3.h"
#include "HomeMenu.h"
#include "Scene5a.h"


USING_NS_CC;

Scene* MiniGame3::createScene()
{
	return MiniGame3::create();
}

// on "init" you need to initialize your instance
bool MiniGame3::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	//
	this->addChild(background);
	background->setAnchorPoint(Vec2(0, 0));
	submit->setPosition(Vec2(1366 / 2, 768 / 2 - 100));
	this->addChild(submit);
	auto teks_submit = Label::create("SUBMIT", "fonts/arial.ttf", 30);
	submit->addChild(teks_submit);
	teks_submit->setPosition(Vec2(submit->getContentSize().width/2, submit->getContentSize().height/2));
	auto rectangleNode = DrawNode::create();
	rectangleNode->drawSolidRect(Vec2(1366/2-250.f, 768/2-25.f), Vec2(1366/2+250.f, 768/2+25.f), Color4F::WHITE);
	this->addChild(rectangleNode,1);
	teksfield->setPosition(Vec2(1366/2,768/2));
	teksfield->setColor(Color3B::BLACK);
	teksfield->setMaxLength(30);
	teksfield->setMaxLengthEnabled(true);
	this->addChild(teksfield,2);
	soal->setPosition(Vec2(1366/2,600));
	soal->setColor(Color3B::BLACK);
	this->addChild(soal);
	background_jawaban->setPosition(Vec2(1366 / 2, 450));
	string_jawaban->setPosition(Vec2(1366 / 2, 450));
	string_jawaban->setColor(Color3B::BLACK);
	this->addChild(string_jawaban,2);
	this->addChild(background_jawaban,1);
	submit->addClickEventListener(CC_CALLBACK_1(MiniGame3::submit_function, this));


	//hasil//
	kosong->setPosition(Vec2(0, 0));
	kosong->setAnchorPoint(Vec2(0, 0));
	this->addChild(kosong, 2);
	tampil_hasil->setPosition(Vec2(1366 / 2, 768 / 2));
	kosong->addChild(tampil_hasil);
	hasil_benar->setPosition(Vec2(tampil_hasil->getContentSize().width / 2, tampil_hasil->getContentSize().height / 2 + 40));
	hasil_salah->setPosition(Vec2(tampil_hasil->getContentSize().width / 2, tampil_hasil->getContentSize().height / 2));
	total_soal->setPosition(Vec2(tampil_hasil->getContentSize().width / 2, tampil_hasil->getContentSize().height / 2 + 80));
	hasil_score->setPosition(Vec2(tampil_hasil->getContentSize().width / 2, tampil_hasil->getContentSize().height / 2 - 40));
	tampil_hasil->addChild(hasil_benar);
	tampil_hasil->addChild(hasil_salah);
	tampil_hasil->addChild(total_soal);
	tampil_hasil->addChild(hasil_score);
	kosong->setScale(0);
	btn_next->setScale(0);
	btn_next->setPosition(Vec2(1366 / 2, 200));
	kosong->addChild(btn_next);
	btn_next->addClickEventListener(CC_CALLBACK_1(MiniGame3::next,this));
	////////


	time_text->setPosition(Vec2(1366 / 2, 750));
	this->addChild(time_text);

	bg_menu->setPosition(Vec2(1366 / 2, 768 / 2));
	label_hard->setPosition(Vec2(btn_hard->getContentSize().width / 2, btn_hard->getContentSize().height / 2));
	label_medium->setPosition(Vec2(btn_hard->getContentSize().width / 2, btn_hard->getContentSize().height / 2));
	label_easy->setPosition(Vec2(btn_hard->getContentSize().width / 2, btn_hard->getContentSize().height / 2));
	btn_hard->setPosition(Vec2(1366 / 2, 550));
	btn_medium->setPosition(Vec2(1366 / 2, 400));
	btn_easy->setPosition(Vec2(1366 / 2, 250));
	this->addChild(bg_menu, 3);
	this->addChild(btn_hard, 4);
	this->addChild(btn_medium, 4);
	this->addChild(btn_easy, 4);
	btn_hard->addChild(label_hard);
	btn_medium->addChild(label_medium);
	btn_easy->addChild(label_easy);
	btn_hard->addClickEventListener(CC_CALLBACK_1(MiniGame3::hard, this));
	btn_medium->addClickEventListener(CC_CALLBACK_1(MiniGame3::medium, this));
	btn_easy->addClickEventListener(CC_CALLBACK_1(MiniGame3::easy, this));
	random_soal();
	return true;
}
void MiniGame3::hard(Ref* sender)
{
	HomeMenu::btn_sound();
	pil_menu = 1;
	btn_hard->setScale(0);
	btn_medium->setScale(0);
	btn_easy->setScale(0);
	bg_menu->setScale(0);
	waktu = 30;
	this->schedule(schedule_selector(MiniGame3::durasi), 1.f);
	log("Menu pilihan = %d", pil_menu);
}
void MiniGame3::medium(Ref* sender)
{
	HomeMenu::btn_sound();
	pil_menu = 2;
	btn_hard->setScale(0);
	btn_medium->setScale(0);
	btn_easy->setScale(0);
	bg_menu->setScale(0);
	waktu = 60;
	this->schedule(schedule_selector(MiniGame3::durasi), 1.f);
	log("Menu pilihan = %d", pil_menu);
}
void MiniGame3::easy(Ref* sender)
{
	HomeMenu::btn_sound();
	pil_menu = 3;
	btn_hard->setScale(0);
	btn_medium->setScale(0);
	btn_easy->setScale(0);
	bg_menu->setScale(0);
	waktu = 90;
	this->schedule(schedule_selector(MiniGame3::durasi), 1.f);
	log("Menu pilihan = %d", pil_menu);
}
void MiniGame3::durasi(float dt)
{

	auto duration = __String::createWithFormat("%.f", waktu)->getCString();
	time_text->setString(duration);
	waktu--;
	if (waktu < 0)
	{
		string_jawaban->setVisible(false);
		soal->setVisible(false);
		teksfield->setVisible(false);
		submit->setVisible(false);
		kosong->setScale(1);
		kosong->setOpacity(100);
		auto string_benar = __String::createWithFormat("Nilai Benar = %.f", benar)->getCString();
		auto string_salah = __String::createWithFormat("Nilai Salah = %.f", salah)->getCString();
		auto string_score = __String::createWithFormat("Nilai Score = FAIL")->getCString();
		hasil_benar->setString(string_benar);
		hasil_salah->setString(string_salah);
		hasil_score->setString(string_score);
		unschedule(schedule_selector(MiniGame3::durasi));
		auto label = Label::createWithTTF("WAKTU TELAH HABIS", "fonts/arial.ttf", 60);
		label->setPosition(Vec2(1366 / 2, 700));
		label->setAnchorPoint(Vec2(0.5, 1));
		this->addChild(label, 3);
		btn_next->setScale(1);
		auto next_label = Label::createWithTTF("Lanjut", "fonts/arial.ttf", 30);
		next_label->setPosition(Vec2(btn_next->getContentSize().width / 2, btn_next->getContentSize().height / 2));
		btn_next->addChild(next_label);

	}
}
void MiniGame3::submit_function(Ref* sender)
{

	HomeMenu::btn_sound();
	log("total soal = %d", total_soal_angka+2);
	auto jawaban = teksfield->getString();
	switch (nilai)
	{
	case 1:
		if (jawaban == "variable" )
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 2:
		if (jawaban == "development")
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 3:
		if (jawaban == "algoritma")
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 4:
		if (jawaban == "markup")
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 5:
		if (jawaban == "boolean")
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 6:
		if (jawaban == "looping")
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 7:
		if (jawaban == "framework")
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 8:
		if (jawaban == "bit")
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 9:
		if (jawaban == "byte")
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 10:
		if (jawaban == "string")
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 11:
		if (jawaban == "laravel")
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 12:
		if (jawaban == "android")
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 13:
		if (jawaban == "integer")
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 14:
		if (jawaban == "java")
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 15:
		if (jawaban == "prepocessor")
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 16:
		if (jawaban == "linux")
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 17:
		if (jawaban == "processor")
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 18:
		if (jawaban == "ram")
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 19:
		if (jawaban == "network")
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 20:
		if (jawaban == "application")
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 21:
		if (jawaban == "twisted")
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 22:
		if (jawaban == "cmos")
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 23:
		if (jawaban == "basic")
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 24:
		if (jawaban == "hacker")
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 25:
		if (jawaban == "framework")
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 26:
		if (jawaban == "hardware")
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 27:
		if (jawaban == "black")
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 28:
		if (jawaban == "cracker")
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 29:
		if (jawaban == "dinamis")
			benar++;
		else
			salah++;
		Selesai();
		break;
	case 30:
		if (jawaban == "parameter")
			benar++;
		else
			salah++;
		Selesai();
		break;
	default:
		break;
	}
	teksfield->setString("");
}
void MiniGame3::next(Ref* sender)
{
	HomeMenu::btn_sound();
	kosong->setOpacity(200);
	btn_next->setScale(0); tampil_hasil->setScale(0);
	schedule(schedule_selector(MiniGame3::done), 1.f);
	auto loading_label = Label::createWithTTF("LOADING", "fonts/arial.ttf", 100);
	loading_label->setPosition(Vec2(1366 / 2, 768 / 2));
	kosong->addChild(loading_label);
}
void MiniGame3::done(float dt)
{
	waktu_next--;
	if (waktu_next == -1)
	{
		HomeMenu::nilai_teks = 120;
		this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
		{
			Director::getInstance()->replaceScene(TransitionFade::create(3, Scene5a::scene(), Color3B(255, 255, 255)));
		})));
	}
}
void MiniGame3::Selesai()
{
	if (total_soal_angka <= 9)
	{
		total_soal_angka++;
		random_soal();
	}
	else
	{
		string_jawaban->setVisible(false);
		soal->setVisible(false);
		teksfield->setVisible(false);
		submit->setVisible(false);
		
		unschedule(schedule_selector(MiniGame3::durasi));
		kosong->setScale(1);
		kosong->setOpacity(100);
		btn_next->setScale(1);
		auto next_label = Label::createWithTTF("Lanjut", "fonts/arial.ttf", 30);
		next_label->setPosition(Vec2(btn_next->getContentSize().width / 2, btn_next->getContentSize().height / 2));
		btn_next->addChild(next_label);

		auto score1 = UserDefault::getInstance()->getFloatForKey("ScoreMiniGame3Hard");
		auto score2 = UserDefault::getInstance()->getFloatForKey("ScoreMiniGame3Medium");
		auto score3 = UserDefault::getInstance()->getFloatForKey("ScoreMiniGame3Easy");
		auto label_highScore = Label::create("NEW HIGH SCORE!!", "fonts/arial.ttf", 80);
		label_highScore->setColor(Color3B::BLACK);
		label_highScore->setPosition(Vec2(1366 / 2, 700));

		switch (pil_menu)
		{
		case 1:
			score = benar * waktu/3;
			if (score > score1)
			{
				UserDefault::getInstance()->setFloatForKey("ScoreMiniGame3Hard", score);
				this->addChild(label_highScore, 4);
			}
			break;
		case 2:
			score = benar * waktu / 6;
			if (score > score2)
			{
				UserDefault::getInstance()->setFloatForKey("ScoreMiniGame3Medium", score);
				this->addChild(label_highScore, 4);
			}
			break;
		case 3:
			score = benar * waktu / 9;
			if (score > score3)
			{
				UserDefault::getInstance()->setFloatForKey("ScoreMiniGame3Easy", score);
				this->addChild(label_highScore, 4);
			}
			break;
		default:
			break;
		}

		auto string_benar = __String::createWithFormat("Nilai Benar = %.f", benar)->getCString();
		auto string_salah = __String::createWithFormat("Nilai Salah = %.f", salah)->getCString();
		auto string_score = __String::createWithFormat("Nilai Score = %.2f", score)->getCString();


		log("%f", waktu);
		log("Nilai score hard = %.2f", UserDefault::getInstance()->getFloatForKey("ScoreMiniGame3Hard"));
		log("Nilai score medium = %.2f", UserDefault::getInstance()->getFloatForKey("ScoreMiniGame3Medium"));
		log("Nilai score easy = %.2f", UserDefault::getInstance()->getFloatForKey("ScoreMiniGame3Easy"));
		hasil_benar->setString(string_benar);
		hasil_salah->setString(string_salah);
		hasil_score->setString(string_score);


	}
}

void MiniGame3::random_soal()
{
	nilai = random(1, 30);
	switch (nilai)
	{
	case 1:
		if (bool_soal1)
		{
			bool_soal1 = false;
			log("Soal 1");
			soal->setString("Istilah untuk tempat programmer menyimpan data \ndalam program mereka adalah _____.");
			string_jawaban->setString("v|a|b|a|i|r|e");
		}
		else random_soal();
		break;
	case 2:
		if (bool_soal2)
		{
			bool_soal2 = false;
			log("Soal2");
			soal->setString("Dalam pembangunan software, programmer menggunakan program bernama IDE \nyang merupakan singkatan dari Integrated _____ Environmet.");
			string_jawaban->setString("d|e|v|m|p|o|l|e|e|n|t");
		}
		else random_soal();
		break;
	case 3:
		if (bool_soal3)
		{
			bool_soal3 = false;
			log("Soal 3");
			soal->setString("Dalam menyusun suatu program, langkah pertama yang harus \ndilakukan adalah menyusun _____.");
			string_jawaban->setString("a|l|t|i|r|o|g|m|a");
		}
		else random_soal();
		break;
	case 4:
		if (bool_soal4)
		{
			bool_soal4 = false;
			log("Soal 4");
			soal->setString("HTML adalah bahasa pemrograman standar untuk membuat sebuah halaman website.\nSingkatan dari HTML adalah HyperText ______ Language.");
			string_jawaban->setString("m|u|k|r|a|p");
		}
		else random_soal();
		break;
	case 5:
		if (bool_soal5)
		{
			bool_soal5 = false;
			log("Soal 5");
			soal->setString("_____ adalah tipe data yang hanya berisi dua kemungkinan nilai: \nTRUE atau FALSE.");
			string_jawaban->setString("b|o|e|l|o|a|n");
		}
		else random_soal();
		break;
	case 6:
		if (bool_soal6)
		{
			bool_soal6 = false;
			log("Soal 6");
			soal->setString("_____ adalah instruksi untuk mengulang suatu baris kode program \nsampai batas yang diinginkan.");
			string_jawaban->setString("l|o|i|p|o|n|g");
		}
		else random_soal();
		break;
	case 7:
		if (bool_soal7)
		{
			bool_soal7 = false;
			log("Soal 7");
			soal->setString("Developer menggunakan ______ untuk mempermudah pembangunan software.\n_____ berisi perintah dan fungsi dasar yang umum digunakan untuk membangun software.");
			string_jawaban->setString("f|r|o|w|e|m|a|r|k");
		}
		else random_soal();
		break;
	case 8:
		if (bool_soal8)
		{
			bool_soal8 = false;
			log("Soal 8");
			soal->setString("___ adalah kependekan dari binary digit yang merupakan unit satuan terkecil \ndalam komputasi digital.");
			string_jawaban->setString("i|t|b");
		}
		else random_soal();
		break;
	case 9:
		if (bool_soal9)
		{
			bool_soal9 = false;
			log("Soal 9");
			soal->setString("____ adalah satuan komputasi digital yang mana 1 byte \nsetara dengan 8 bit.");
			string_jawaban->setString("y|e|t|b");
		}
		else random_soal();
		break;
	case 10:
		if (bool_soal10)
		{
			bool_soal10 = false;
			log("Soal 10");
			soal->setString("Untuk menampung lebih dari satu karakter \nkita menggunakan tipe data _____ .");
			string_jawaban->setString("s|n|i|r|t|g");
		}
		else random_soal();
		break;
	case 11:
		if (bool_soal11)
		{
			bool_soal11 = false;
			log("Soal 11");
			soal->setString("__ adalah salah satu framework PHP untuk membangun sebuah aplikasi web");
			string_jawaban->setString("l|v|a|e|a|r|l");
		}
		else random_soal();
		break;
	case 12:
		if (bool_soal12)
		{
			bool_soal12 = false;
			log("Soal 12");
			soal->setString("IDE resmi dari Google yang digunakan untuk pengembangan aplikasi android adalah ___ Studio");
			string_jawaban->setString("a|i|o|r|d|n|d");
		}
		else random_soal();
		break;
	case 13:
		if (bool_soal13)
		{
			bool_soal13 = false;
			log("Soal 13");
			soal->setString("Tipe data yang berupa bilangan bulat adalah _______");
			string_jawaban->setString("i|e|g|n|t|e|r");
		}
		else random_soal();
		break;
	case 14:
		if (bool_soal14)
		{
			bool_soal14 = false;
			log("Soal 14");
			soal->setString("Bahasa pemograman ______ merupakan bahasa pemograman yang multi \nplatform dan multi device");
			string_jawaban->setString("j|v|a|a");
		}
		else random_soal();
		break;
	case 15:
		if (bool_soal15)
		{
			bool_soal15 = false;
			log("Soal 15");
			soal->setString("PHP adalah bahasa pemrograman yang digunakan untuk pembuatan dan \npengembangan aplikasi web. kepanjangan dari PHP yaitu Hypertext ________");
			string_jawaban->setString("p|r|c|o|s|e|o|r|e|s|p|r");
		}
		else random_soal();
		break;
	case 16:
		if (bool_soal16)
		{
			bool_soal16 = false;
			log("Soal 16");
			soal->setString("___ merupakan sistem operasi open source dan turunan dari unix.");
			string_jawaban->setString("l|u|i|n|x");
		}
		else random_soal();
		break;
	case 17:
		if (bool_soal17)
		{
			bool_soal17 = false;
			log("Soal 17");
			soal->setString("Bagian komputer yang berfungsi sebagai otak pemrosesan data dan perhitungan adalah ___");
			string_jawaban->setString("p|c|o|s|e|s|r|o|r");
		}
		else random_soal();
		break;
	case 18:
		if (bool_soal18)
		{
			bool_soal18 = false;
			log("Soal 18");
			soal->setString("___ yaitu suatu memori tempat penyimpanan data sementara,\nketika saat komputer dijalankan dan dapat diakses secara acak (random)");
			string_jawaban->setString("m|a|r");
		}
		else random_soal();
		break;
	case 19:
		if (bool_soal19)
		{
			bool_soal19 = false;
			log("Soal 19");
			soal->setString("Tugas dari ____layer pada OSI layer yaitu menyediakan fungsi routing sehingga paket \ndapat dikirim keluar dari segment jaringan lokal ke suatu tujuan yang \nberada pada suatu jaringan lain.");
			string_jawaban->setString("n|t|r|o|w|e|k");
		}
		else random_soal();
		break;
	case 20:
		if (bool_soal20)
		{
			bool_soal20= false;
			log("Soal 20");
			soal->setString("Layer terakhir dari OSI layer yaitu ___ layer");
			string_jawaban->setString("a|c|p|i|t|o|l|p|i|a|n");
		}
		else random_soal();
		break;
	case 21:
		if (bool_soal21)
		{
			bool_soal21 = false;
			log("Soal 21");
			soal->setString("Kabel UTP adalah suatu jenis kabel yang dapat \ndipakai untuk membuat jaringan komputer.\nKepanjangan dari UTP adalah Unshielded ______ Pair");
			string_jawaban->setString("t|s|e|t|i|w|d");
		}
		else random_soal();
		break;
	case 22:
		if (bool_soal22)
		{
			bool_soal22 = false;
			log("Soal 22");
			soal->setString("baterai kecil yang berfungsi untuk memberikan daya kepada BIOS yaitu ____ Battery");
			string_jawaban->setString("s|m|o|c");
		}
		else random_soal();
		break;
	case 23:
		if (bool_soal23)
		{
			bool_soal23 = false;
			log("Soal 23");
			soal->setString("BIOS adalah sebuah chip yang memiliki fungsi sebagai kontrol seluruh perangkat (hardware) \nyang ada di komputer. Kepanjangan dari BIOS adalah ____ Input Output System");
			string_jawaban->setString("b|i|a|s|c");
		}
		else random_soal();
		break;
	case 24:
		if (bool_soal24)
		{
			bool_soal24 = false;
			log("Soal 24");
			soal->setString("_____ merupakan seseorang yang memiliki keahlian dalam komputer dan memiliki \nketertarikan yang tinggi terhadap keamanan sistem komputer");
			string_jawaban->setString("h|a|c|e|k|r");
		}
		else random_soal();
		break;
	case 25:
		if (bool_soal25)
		{
			bool_soal25 = false;
			log("Soal 25");
			soal->setString("sebuah kerangka kerja yang digunakan untuk mempermudah para developer software \ndalam membuat dan mengembangkan aplikasi adalah _____");
			string_jawaban->setString("f|r|m|r|a|o|w|e|k");
		}
		else random_soal();
		break;
	case 26:
		if (bool_soal26)
		{
			bool_soal26 = false;
			log("Soal 26");
			soal->setString("____ adalah salah satu komponen dari sebuah komputer yang sifat alat nya bisa dilihat \ndan diraba secara langsung atau yang berbentuk nyata");
			string_jawaban->setString("h|r|a|w|r|a|d|e");
		}
		else random_soal();
		break;
	case 27:
		if (bool_soal27)
		{
			bool_soal27 = false;
			log("Soal 27");
			soal->setString("CMYK adalah sebuah model warna berbasis pengurangan sebagian gelombang cahaya dan yang umum \ndipergunakan dalam pencetakan berwarna. Kepanjangan daari CMYK yaitu Cyan-Magenta-Yellow-____");
			string_jawaban->setString("b|c|l|a|k");
		}
		else random_soal();
		break;
	case 28:
		if (bool_soal28)
		{
			bool_soal28 = false;
			log("Soal 28");
			soal->setString("___ adalah orang yang masuk ke sistem orang lain dan bersifat destruktif,\nbiasanya di jaringan komputer, secara sengaja melawan keamanan komputer");
			string_jawaban->setString("c|r|e|k|a|c|r");
		}
		else random_soal();
		break;
	case 29:
		if (bool_soal29)
		{
			bool_soal29 = false;
			log("Soal 29");
			soal->setString("web yang isinya selalu berubah-ubah atau berganti tiap waktu adalah web ___");
			string_jawaban->setString("d|i|a|i|n|m|s");
		}
		else random_soal();
		break;
	case 30:
		if (bool_soal30)
		{
			bool_soal30 = false;
			log("Soal 30");
			soal->setString("____ merupakan sebuah variable yang didefinisikan oleh metode yang menerima sebuah nilai");
			string_jawaban->setString("p|a|e|a|r|m|t|e|r");
		}
		else random_soal();
		break;
	default:
		break;
	}

}

