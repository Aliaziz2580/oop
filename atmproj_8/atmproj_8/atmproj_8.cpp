#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
enum enstr
{
	filizla = 1,
	filadd = 2, fildeshtr = 3,
	fildelet = 4, filizlaozil = 5,
	naweminyo = 6,manag =7, exitg = 8


};
enum ennawe
{
	addmani = 1, silmane = 2, totalmain = 3, minminyo = 4
};

enum enyousar
{
	printyousar = 1, addyousar = 2, deletyousar = 3, deshteryousar = 4, minmiyou = 5
};
struct names
{
	string bencod;
	string name;
	string yesh;
	string many;
	bool bol = true;
};
struct yousar
{
	string yousarname;
	string pasword;
	string betwis;

};



enum enyousr {

	addyosar 
};
void minyo(string salahya);

void nawominyo(string salahya);
void buyukis(enstr j,string salahya);
void yolminyo(ennawe j, string salahya);
void backminyo(string salahya);
void manegminyou(string salahya);

//Â‰« ”Ê› ‰„·¡ «·ﬂÊœ «·›ﬂ Ê— 

vector <string > fallstr(string nam)
{
	vector <string > j;

	string str;
	string cod = "/##/";
	int no = 0;

	while ((no = nam.find(cod)) != string::npos)
	{

		str = nam.substr(0, no);
		if (!str.empty())
		{
			j.push_back(str);
		}
		nam.erase(0, no + cod.length());
	}

	if (!nam.empty())
	{
		j.push_back(nam);
	}
	return j;




}




names fallnam(string nam)
{
	names j;
	vector <string > strvec = fallstr(nam);

	



		// «· Õﬁﬁ „‰ √‰ «·„ ÃÂ ÌÕ ÊÌ ⁄·Ï 4 ⁄‰«’— ⁄·Ï «·√ﬁ·
		if (strvec.size() >= 4) {
			j.bencod = strvec[0];
			j.name = strvec[1];
			j.yesh = strvec[2];
			j.many = strvec[3];
		}
		else {
			//  ⁄ÌÌ‰ ﬁÌ„ «› —«÷Ì… ›Ì Õ«·… «·Œÿ√
			cerr << "Error: Invalid data format in line: " << nam << endl;
			j.bencod = "ERROR";
			j.name = "UNKNOWN";
			j.yesh = "0";
			j.many = "0";
		}
		return j;
	




}


vector <names > fallname()
{
	vector <names>n;
	string str;
	fstream fil;
	names nam;
	fil.open("ali.txt", ios::in);
	if (fil.is_open())
	{

		while (getline(fil, str))
		{

			nam = fallnam(str);
			n.push_back(nam);
		}






	}

	fil.close();
	return n;






}
//Â‰« Ì‰ ÂÌ „·¡ «·—=›ﬂ Ê— 




//  [1] ÊÂ‰« ‰⁄„· „‰ «Ã· ÿ»«⁄… «·„·› 
void men(vector < names > nam)
{
	cout << " \t\t yor fil is (" << nam.size() << ")\n";
	cout << "__________________________________________" << endl;
	cout << setw(7) << left << "your cod " << "|" << setw(11) << left << " your name " << "|" << setw(7) << left << "yash " << "|" << "  your mash \n";
	cout << "__________________________________________" << endl;
}
void  printnames(names j)
{
	cout << setw(9) << left << j.bencod << "|" << setw(11) << left << j.name << "|" << setw(7) << left << j.yesh << "| " << j.many << endl;

}
void filprint()
{
	vector <names> nam = fallname();
	men(nam);
	for (names& j : nam)
	{

		printnames(j);
	}
	cout << "__________________________________________" << endl;
}




//  [2]Â‰« ‰⁄„· «÷«›… ··„·›    
names fallj()
{
	names j;

	cout << " intar your cod ? ";
	getline(cin >> ws, j.bencod);
	cout << " intasr your name ? ";
	getline(cin, j.name);
	cout << " intar your yash   ? ";
	cin >> j.yesh;
	cout << " intar your  mash ? ";
	cin >> j.many;

	return j;



}
string perntjinfil(names j)
{
	string nj;
	nj = j.bencod + "/##/" + j.name + "/##/" + j.yesh + "/##/" + j.many;
	return nj;
}
void addfil()
{

	names j;
	j = fallj();

	fstream fil;
	fil.open("ali.txt", ios::out | ios::app);
	if (fil.is_open())
	{

		fil << endl;
		fil << perntjinfil(j);
	}
	fil.close();
	cout << " app true \n\n";
}



//[Â‰« ‰⁄„· »«–‰ «··Â ⁄·Ï  €Ì—  «·„·›[3 
void sevdata(names j, vector <names >& nam)
{

	for (names& m : nam)
	{
		if (m.bencod == j.bencod)
		{
			m = j;
			break;
		}
	}

	fstream fil;

	fil.open("ali.txt", ios::out);
	if (fil.is_open())
	{
		for (names k : nam)
		{

			fil << perntjinfil(k);
			fil << endl;

		}



	}
	fil.close();

}
void cinnames(string str, names& j)
{
	j.bencod = str;
	cout << " intasr your name ? ";
	getline(cin >> ws, j.name);
	cout << " intar your yash   ? ";
	cin >> j.yesh;
	cout << " intar your telefon namper ? ";
	cin >> j.many;



}
void printj(names j)
{
	cout << " your cod     :" << j.bencod << endl;
	cout << " your name    :" << j.name << endl;
	cout << " your yash    : " << j.yesh << endl;
	cout << " your total mane : " << j.many << endl;
}
bool deshtervarmi(vector <names > nam, string str, names& j)
{
	for (names n : nam)
	{
		if (n.bencod == str)
		{
			j = n;
			return true;
		}
	}
	return false;
}
void deshter()
{
	vector <names > nam = fallname();
	names n;
	names j;
	cout << "intar your cod desh plse ? ";
	string str;
	char desh;
	cin >> str;


	if (deshtervarmi(nam, str, j))
	{
		printj(j);
		cout << " are you deshtrcak ? ";

		cin >> desh;
		if (toupper(desh) == 'Y')
		{
			cinnames(str, n);
			sevdata(n, nam);
		}
	}
	else
	{
		cout << " your (" << str << ") is not in fil agen plse :";
	}


}



//[Â‰« «·⁄„· ⁄·Ï «·Õ“› »«–‰ «··Â [4
void sevnam(vector <names > nam)
{
	fstream fil;
	fil.open("ali.txt", ios::out);
	if (fil.is_open())
	{

		for (names j : nam)
		{
			if (j.bol == true)
			{
				fil << perntjinfil(j);
				fil << endl;
			}
		}
	}
	fil.close();
}
void deltnam(string kye, vector <names>& nam)
{
	for (names& j : nam)
	{
		if (j.bencod == kye)
		{
			j.bol = false;
			break;
		}
	}
}
void deletdata()
{
	vector <names> nam = fallname();

	cout << " intar your kye ? ";
	string kye;
	cin >> kye;
	names j;
	string desh;

	if (deshtervarmi(nam, kye, j))
	{
		printj(j);
		cout << endl;
		cout << " are you delet ? ";
		cin >> desh;

		if (desh == "y" || "Y")
		{
			deltnam(kye, nam);

			sevnam(nam);
			cout << " tamam is deler :\n\n";

		}


	}
}




//[Â‰« ‰⁄„· ⁄·Ï «·»ÕÀ [5

void aryor()
{
	vector <names> nam = fallname();
	cout << " intar your kyecid ";
	string kye;
	cin >> kye;
	names j;
	if (deshtervarmi(nam, kye, j))
	{
		printj(j);
		cout << endl;
	}
	else {
		cout << "no cod agen plse : ";
	}

}






//[6] Â‰« ‰⁄„· ⁄·Ï „‰ÌÊ «·«„Ê«·


string read()
{
	string j;

	cout << "intar yor cod ? ";
	cin >> j;
	return j;
}

//‰÷Ì› „«· 
void addvector(vector <names> nam)
{
	fstream fil;
	fil.open("ali.txt", ios::out);
	if (fil.is_open())
	{
		for (names& j : nam)
		{
			fil << perntjinfil(j) << endl;

		}
	}
	fil.close();
}
string admanicod(string ismane, int admaine)
{
	string total;

	int j = stoi(ismane);
	if ((j + admaine) > 0)
	{
		total = to_string(j + admaine);

		cout << " total ald is  " << (j + admaine) << endl;
	}
	else
	{
		cout << " mani is olmaz " << (j + admaine) << endl;
	}

	return total;
}
void addman(string cod, int mane)
{
	vector <names> nam = fallname();

	for (names& j : nam)
	{
		if (j.bencod == cod)
		{

			j.many = admanicod(j.many, mane);
			break;
		}


	}
	cout << "are yo seve y/n ?  ";
	char chrj;
	cin >> chrj;
	if (chrj == 'y' || chrj == 'Y')
	{
		addvector(nam);
	}

}
bool truecod(string cod, names& namdata)
{
	vector <names> nam = fallname();

	for (names n : nam)
	{
		if (n.bencod == cod)
		{
			namdata = n;
			return true;
		}
	}
	return false;



}
void addmaniofan()
{
	names namdata;

	string	cod = read();


	while (!truecod(cod, namdata))
	{
		cout << " no your cod agen plse :\n ";
		cod = read();
	}

	printj(namdata);

	cout << " inta your mani plese ? ";
	int mane;
	cin >> mane;


	addman(cod, mane);








}




//Â‰« ‰Õ“› «·„«· „‰ «·„·› 

void sil()
{
	names namdata;

	string	cod = read();


	while (!truecod(cod, namdata))
	{
		cout << " no your cod agen plse : ";
		cod = read();
	}

	printj(namdata);

	cout << " inta your mani plese ? ";
	int mane;
	cin >> mane;


	addman(cod, mane * -1);


}



//Â‰« „Ã„Ê⁄ «·«„Ê«· 
int totlmaniisvector(string mane)
{
	int j;
	j = stoi(mane);
	return j;
}
void printminyo()
{
	cout << "\t\t YOUR MAINY MINYOU \n";
	cout << "_____________________________________\n";
	cout << setw(8) << left << "your cod" << setw(14) << left << "your name " << setw(9) << left << "your mane" << endl;
	cout << "_____________________________________\n";

}
void printtotal(names j)
{

	cout << setw(8) << left << j.bencod << setw(14) << left << j.name << setw(9) << left << j.many << endl;


}
void totalmaniinhj()
{
	vector <names> nam = fallname();
	int total = 0;
	printminyo();
	for (names j : nam)
	{
		printtotal(j);
		total += totlmaniisvector(j.many);
	}
	cout << " your total mani is " << total << endl;
}


//Â‰« «·„‰ÌÊ «·ÃœÌœ Ê «·„Ê“⁄ ··«›—⁄  ===4 
void yolminyo(ennawe en,string salahya)
{

	switch (en)
	{
	case ennawe::addmani:
		system("cls");
		addmaniofan();
		nawominyo(salahya);
		break;
	case ennawe::silmane:
		system("cls");
		sil();
		nawominyo(salahya);
		break;
	case ennawe::totalmain:
		system("cls");
		totalmaniinhj();
		nawominyo(salahya);
		break;
	case ennawe::minminyo:
		system("cls");
		minyo(salahya);
		break;

	}

}
void nawominyo(string salahya)
{
	int namper = 0;
	system("cls");
	cout << " \t\t YOUR MINYO MASHLAR \n";
	cout << "__________________________________\n";
	cout << "[1] add mane \n";
	cout << "[2] exit mane \n";
	cout << "[3] total mane \n";
	cout << "[4] min minyo \n";
	cout << "__________________________________\n";
	cout << "__________________________________\n";
	cout << endl;
	cout << "intar your numper ? ";

	cin >> namper;


	yolminyo((ennawe)namper ,salahya);



}








//  [7]  Â‰« ‰⁄„· ⁄·Ï „·› «·„” Œœ„Ì‰ «·Ãœœ 


// „·›  ”ÃÌ· «·œŒÊ· 
yousar fallnamusar(string str)
{
	vector <string> vecyusar = fallstr(str);
	yousar n;
	if (vecyusar.size() >= 3)
	{
	n.yousarname = vecyusar[0];
	n.pasword = vecyusar[1];
	n.betwis = vecyusar[2];
	}
	else
	{
		cout << " vector eror ";
	}


	return n;
}

vector <yousar > fallvec()
{
	vector <yousar>n;
	string str;
	fstream fil;
	yousar nam;
	fil.open("login.txt", ios::in);
	if (fil.is_open())
	{

		while (getline(fil, str))
		{

			nam = fallnamusar(str);
			n.push_back(nam);
		}






	}
	else

	{
		cout << " aeror no shlshyourt ";
	}

	fil.close();
	return n;







}
bool isyousrhave(vector <yousar> vecyousar, string yousarnam, string pasword, string &salahya)
{


	for (yousar& nam : vecyousar)
	{
		if (nam.yousarname == yousarnam)
		{
			if (nam.pasword == pasword)
			{
				salahya = nam.betwis;
				return true;
			}
		}


	}

	return false;

}

void dontfan()
{
	cout << " _________________________\n";
	cout << " dont your bord olmaz :-(\n";
	cout << " _________________________\n";
}
void login()
{
	cout << " ______________________\n";
	cout << "         LOG IN         \n";
	cout << " ______________________\n";
	string yousarname;
	string pasword;

	cout << " intar your yousar name ? ";
	cin >> yousarname;
	cout << " \n intar your paword ? ";
	cin >> pasword;

	vector <yousar> vecyousar = fallvec();

	string salahya;

	while (! isyousrhave(vecyousar,yousarname,pasword,salahya))
	{
		cout << " YOUR NAME VE YA PASWORD YANLISH :-( \n";
		cout << " intar your yousar name ? ";
		cin >> yousarname;
		cout << " \n intar your paword ? ";
		cin >> pasword;

	}

	minyo(salahya);

	
	// ·ﬁœ  „ «÷«›  «·„” Œœ„Ì‰ «·Ãœœ ›Ì «·„‰ÌÊ Ê·«ﬂ‰ ·„ «⁄„· «·„·› »⁄œ Ê·« ‘—ÿ «·«‰ ﬁ«· «·Ï «·„‰ÌÊ «·—«Ì”Ì 


	// «·›ﬂ Ê— ›Ì «·«⁄··Ï Ì„¡ »«·” Œœ„Ì‰ ›Ì „·› «· ”ÃÌ· ÊÌ›Õ’ «‰ ﬂ«‰ «·«”„ Ê ﬂ·„… «·„—Ê— „ÿ«»ﬁ… ··œŒÊ· ÊÂ‰« ÌÃ» ⁄„· Â–« €œ« «‰ ‘«¡ «··Â 

	//  „ «‰‘«¡ «·„·› »«–‰ «··Â Ê ··Â «·Õ„œ

}




//1 Â‰« ‰⁄„· ⁄·Ï «·ÿ»«⁄… œ«Œ· „·› «·„” Œœ„Ì‰ 
void printyousarline(vector <yousar> youvec)
{
	cout << "_____________________" << (youvec.size()) << "________________\n";
	cout << setw(11) << left << "yousar name" << setw(7) << left << "pasword" << setw(7) << left << "power\n";
	cout << "_____________________________________\n";



}
void printvectoe( yousar j)
{
	cout << setw(11) << left << j.yousarname << "|" << setw(7) << left << j.pasword << "|" << setw(7) << left << j.betwis << "|\n";



}
void printyousarfan()
{
	vector <yousar> youvec = fallvec();
	printyousarline(youvec);
	
	for (yousar& j : youvec)
	{
	printvectoe(j);

	}





}

void beakmanegminyou(string salahya)
{
	cout << " are you beak manegmin list ....";
	system("pause>0");
	system("cls");
	 manegminyou(salahya);
}



// Â‰« ‰⁄„· »›÷· «··Â ⁄·Ï «÷«›… „” Œœ„  2
bool yousrnameistrue(string j)
{
	vector < yousar> nam = fallvec();
	
	for (yousar& you : nam)
	{
		if (you.yousarname == j)
		{
			return true;
		}
	}
	return false;

}
string pawor()
{

	

	
		int salahyat = 0;
		string j;


		 string messages[]
			
		={
			"fil izla", "fil add", "fil deshtr", "fil delet", "sersh ozla", "naw minyo", "manega usar"
		};

		for (int i = 0; i < 7; ++i) 
		{

			cout << "\n\t intar no [" << i + 1 << "] " << messages[i] << " : y/n? ";
			cin >> j;
			if (j == "y") salahyat |= (1 << (i + 1));

		}

		return to_string(salahyat);
	

	
}
yousar folyousar()
{
	yousar j;

	cout << " intar newa yousr name : ";
	cin >> j.yousarname;

	while (yousrnameistrue(j.yousarname))
	{
		cout << " your name " << j.yousarname << " whe have ";
		cout << " intar newa yousr name : ";
		cin >> j.yousarname;
	}

	cout << " intar your pasword\n";
	cin >> j.pasword;



	cout << " are pawor dont limet y/n";
	string limet;
	cin >> limet;
	if (limet == "y")
	{
		j.betwis = "-1";
	}
	else
	{
		j.betwis = pawor();
	}


	return j;


}
string stringyousarpower( yousar nam)
{
	string j;

	j = nam.yousarname + "/##/" + nam.pasword + "/##/" + nam.betwis + "\n";
	return j;
}

void addyousarfan()
{
	fstream mfile;
	yousar nam;
	mfile.open("login.txt", ios::out | ios::app);
	
	if (mfile.is_open())
	{
		nam = folyousar();
		mfile << stringyousarpower(nam) << endl;
		
	}

	mfile.close();

}




//Â‰« ‰⁄„· ⁄·Ï  €Ì— ’·«ÕÌ«  «·„” Œœ„ 3

bool isadmin( string inpotdata)
{
	vector <yousar> nam = fallvec();
	for (yousar& j : nam)
	{
		if (j.yousarname == inpotdata)
		{
			return (j.betwis == "-1");
		}
	 }

	return false;
}
vector <yousar>  deshteryousrpaw(yousar inpotdata )

{

	vector <yousar> nam = fallvec();


	while (!yousrnameistrue(inpotdata.yousarname) || isadmin( inpotdata.yousarname))
	{
		cout << " your name " << inpotdata.yousarname << " whe dot'have or admin ";
		cout << " intar  yousr name : ";
		cin >> inpotdata.yousarname;
	}
	


	cout << " intar your pasword\n";
	cin >> inpotdata.pasword;



	cout << " are pawor dont limet y/n";
	string limet;
	cin >> limet;
	if (limet == "y")
	{
		inpotdata.betwis = "-1";
	}
	else
	{
		inpotdata.betwis = pawor();
	}


	for (yousar& j : nam)
	{
		if (inpotdata.yousarname == j.yousarname)
		{
			j.pasword = inpotdata.pasword;
			j.betwis = inpotdata.betwis;
			break;
		}
	}




	return nam;

}
void deshteryousarpawer()
{
	fstream mfile;
	vector <yousar> nam;
	yousar inpotdata;

	cout << " intar yousr name is yousar ? ";
	cin >> inpotdata.yousarname;

	 nam= deshteryousrpaw(inpotdata);





	 mfile.open("login.txt", ios::out);
	 if (mfile.is_open())
	 {
		 for (yousar j : nam)
		 {
			 mfile << stringyousarpower(j) << endl;
		 }


	 }
	 else
	 {
		 cout << " no is dont open\n";
	 }

	 mfile.close();

}






//Â‰« ‰⁄„· ⁄·Ï „”Õ „” Œœ„ 4
void printoneyousar(string yousarname)
{
	vector <yousar> nam = fallvec();

	cout << "___________your yousar ___________\n";
	for (yousar n : nam)
	{
		if (n.yousarname == yousarname)
		{
			cout << " yousr name : " << n.yousarname << endl;
			cout << " youser pasw : " << n.pasword << endl;
			cout << " yousr pawor : " << n.betwis << endl;
		}
	}
}
void deletyousardate(string yousarname)
{
	vector <yousar> nam = fallvec();
fstream file;

file.open("login.txt" , ios::out | ios::trunc);
if (file.is_open())
{
	for (yousar &j : nam)
	{
		if (j.yousarname != yousarname)

		{
			file << stringyousarpower(j) << endl;
		}
		
	}


}
else
{
	cout << " no is dont open\n";
}

file.close();



}
void deletyousard()
{

	string yousarname;
	

	cout << " intar name yousar \n";
	cin >> yousarname;


	while (!yousrnameistrue(yousarname) || isadmin(yousarname))
	{
		cout << " your name " << yousarname << " whe dot'have or admin ";
		cout << " intar  yousr name : ";
		cin >> yousarname;
	}

	printoneyousar(yousarname);
	string yes;


	cout << " are you delet yousar y/n";
	cin >> yes;

	if (yes == "y" || yes == "Y")
	{
		  
		deletyousardate(yousarname);



	}




}




// «·„Ê“⁄
void manegbegminyho(enyousar namper,string salahya)
{
	switch (namper)
	{
	case enyousar::printyousar:
		system("cls");
		printyousarfan();
		beakmanegminyou(salahya);
		break;

	case enyousar::addyousar:
		system("cls");
		addyousarfan();
		beakmanegminyou(salahya);
		break;
	case enyousar::deshteryousar:
		system("cls");
		deshteryousarpawer();
		beakmanegminyou(salahya);
	case enyousar::deletyousar:
		system("cls");
		deletyousard();
		beakmanegminyou(salahya);
		break;
	case enyousar::minmiyou:
		system("cls");
		minyo(salahya);
		break;
	}



}
void manegminyou(string salahya)
{
	cout << "print your uosar   [1] \n";
	cout << "add your uosar     [2] \n";
	cout << "delet your uosar   [3] \n";
	cout << "dashtir ish uosar  [4] \n";
	cout << "baek ind min minyu [5] \n";
	cout << "____________________________\n";
	cout << "\n intar your namper ? ";
	int inpotyosar;
	cin >> inpotyosar;

	manegbegminyho((enyousar)inpotyosar, salahya);


}
















//[8]Â‰« «·«‰Â«¡
void printend()
{
	login();
}
void minyo(string salahya)
{
	system("cls");
	cout << "\tbezim minyo buyryn \n";
	cout << "___________________________________\n";
	cout << "___________________________________\n";
	cout << "\t intar no [1] fil izla   : \n";
	cout << "\t intar no [2] fil add    : \n";
	cout << "\t intar no [3] fil deshtr :\n ";
	cout << "\t intar no [4] fil delet  :\n ";
	cout << "\t intar no [5] sersh ozla : \n";
	cout << "\t intar no [6] naw minyo  :\n ";
	cout << "\t intar no [7] manega usar: \n";
	cout << "\t intar no [8] log out    : \n";
	cout << "___________________________________\n";
	cout << "___________________________________\n";

	cout << "intar yor namper ? ";
	int j = 0;
	cin >> j;
	int x = stoi(salahya);
	if (x == -1)
	{
		buyukis((enstr)j,salahya);

	}
	if(x & (1 << j))
	{
		buyukis((enstr)j, salahya);
	}
	else
	{
		system("cls");
		dontfan();
		backminyo(salahya);
	}


	



}
void backminyo(string salahya )
{
	cout << " ar you back minyo .....";
	system("pause> 0");
	minyo(salahya);
}
void buyukis(enstr j , string salahya)
{


	switch (j)
	{
	case enstr::filizla:
		system("cls");
		filprint();
		backminyo(salahya);
		break;
	case enstr::filadd:
		system("cls");
		addfil();
		backminyo(salahya);
		break;
	case enstr::fildeshtr:
		system("cls");
		deshter();
		backminyo(salahya);
		break;
	case enstr::fildelet:
		system("cls");
		deletdata();
		backminyo(salahya);
		break;
	case enstr::filizlaozil:
		system("cls");
		aryor();
		backminyo(salahya);
		break;
	case enstr::naweminyo:
		system("cls");
		nawominyo(salahya);
		break;
	case enstr::manag:
		system("cls");
		manegminyou(salahya);
		break;
	case enstr::exitg:
		system("cls");
		printend();
		break;






	}
}


int main()
{
	login();
	
	
	
}