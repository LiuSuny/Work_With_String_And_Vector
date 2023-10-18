#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
enum Color
{
	Black, Blue, Green, Cyan, Red, Magenta, Brown,
	LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
void setColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
enum Direction { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, Esc = 27 };
void setCursor(int x, int y)
{
	COORD myCoords = { x,y };
	SetConsoleCursorPosition(hStdOut, myCoords);
}

void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time_t(NULL));

	//2. Напечатать самое длинное и самое короткое слово в этой строке.

	
	//создали доп строку
	//скопировали в неё оригинал
	//****удалили все знаки препинания
	//находим первую букву (символ, не являюзийся пробелом. заком препинания) - копируем данные от начала до первого пробела в переменную слово
	//сформированное слово добавляем в вектор
	//удаляем фрагмент строки, который копировали в вектор
	//vector<string>MyString;
	//cout << "Введите строку:" << endl;
	//string mystr, word;
	//getline(cin, mystr);
	//cout << mystr << endl;
	//string temp;
	//temp = mystr;
	//int pos;

	//int pos_end;
	//do
	//{
	//	pos = temp.find_first_not_of(".,!? ");//нашли первую букву слова
	//	if (pos != temp.npos)
	//	{
	//		//удалить участок до найденного символа
	//		temp.erase(temp.begin(), temp.begin() + pos);
	//	}
	//	cout << temp << endl;

	//	pos_end = temp.find_first_of(".,!? ");
	//	if (pos_end != temp.npos)
	//	{
	//		word.assign(temp.begin(), temp.begin() + pos_end);
	//		MyString.push_back(word);
	//		temp.erase(temp.begin(), temp.begin() + pos_end);
	//	}
	//} while (pos_end != temp.npos);
	//cout << "\n\n";
	////на тот случай, если строка не заканчивалась одним из разделителей ".,!? ", то последнее слово не записалось в вектор
	////днлаем проверку - если в строке остались символы - это и есть последнее слово в строке - добавляем его в вектор
	//if (!temp.empty())
	//{
	//	MyString.push_back(temp);
	//}
	//for (auto var : MyString)
	//{
	//	cout << var << endl;
	//}
	//string word_min = MyString.at(0), word_max = MyString[0];
	//for (auto var : MyString)
	//{
	//	if (var.size() > word_max.size())
	//	{
	//		word_max = var;
	//	}
	//	if (var.size() < word_min.size())
	//	{
	//		word_min = var;
	//	}
	//}
	//cout << "max: " << word_max << "  min: " << word_min << endl;





	/*4. Найдите все имена в строке - т.е. все слова, начинающиеся с Карл и Клар.
	После -  выведите их на экран.

	Карл у Клары забрал кораллы, Клара у Карла забрала кларнет. Карлуша был хорошим мальчиком, его связывали
	тёплые. дружески отношения с Кларочкой.*/


	vector<string> mystr;
	string user_str = "Karl took the Korals from Klara, Klara took the klarinet from Karl. Karlusha was a good boy, he had warm, friendly relations with Klarochka.";
	//cout << "user_str" << user_str << endl;
	string tmp = user_str;
	string words;
	int pos, pos1, pos_end;
	//cout << "tmp = " << tmp << "\n";
	do
	{

		pos = tmp.find("Karl");
		cout << pos << "\n";
		pos1 = tmp.find("Klar");
		cout << pos1 << "\n";
		if (pos < pos1)
		{
			pos_end = tmp.find_first_of(",.!? ", pos);
			cout << pos_end << "\n";
			if (pos_end != tmp.npos)
			{
				words.assign(tmp.begin() + pos, tmp.begin() + pos_end);
				mystr.push_back(words);
				//delete part of the string to the end
				tmp.erase(tmp.begin(), tmp.begin() + pos_end);
				//cout << tmp << "\n";
			}
		}
		else /*(pos1 < pos)*/
		{

			pos_end = tmp.find_first_of(",.!? ", pos1);
			cout << pos_end << "\n";
			if (pos_end != tmp.npos)
			{
				words.assign(tmp.begin() + pos1, tmp.begin() + pos_end);
				mystr.push_back(words);
				//delete part of the string to the end
				tmp.erase(tmp.begin(), tmp.begin() + pos_end);
				//cout << tmp << "\n";
			}
		}
	} while (pos_end != tmp.npos);

	/*if (!tmp.empty())
	{
	mystr.push_back(tmp);*/
	// }
	for (string var : mystr)
	{
		cout << "result =  " << var << endl;
	}

}
