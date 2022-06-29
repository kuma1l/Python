#include"Project.h"
	MyChar::MyChar(){
		c = '\0';
		this->ch_size = 0;
	}
	MyChar::MyChar(const char newC){
		this->c = newC;
		ch_size++;
	}
	MyChar&MyChar::operator=(const MyChar &obj){
		this->c = obj.c;
		return *this;
	}
	ifstream & operator >>(ifstream &cin, MyChar &obj){
		cin.get(obj.c);
		return cin;
	}
	ostream &operator<<(ostream &cout, const MyChar &obj){
		cout << obj.c;
		return cout;
	}
	
	bool MyChar::operator==(const MyChar &obj){
		bool flag = false;
		if (this->c == obj.c|| this->c==obj.c+32 || this->c == obj.c-32){
			flag = true;
		}
		else{
			flag = false;
		}
		return flag;
	}
	bool MyChar:: operator>=(const MyChar &obj){
		bool flag = false;
		if (this->c >= obj.c){
			flag = true;
		}
		else{
			flag = false;
		}
		return flag;
	}
	bool MyChar::operator<=(const MyChar &obj){
		bool flag = false;
		if (this->c <= obj.c){
			flag = true;
		}
		else{
			flag = false;
		}
		return flag;
	}
	bool MyChar::operator!=(const MyChar &obj){
		bool flag = false;
		if (this->c != obj.c){
			flag = true;
		}
		else{
			flag = false;
		}
		return flag;
	}
	MyChar MyChar::operator +(const int num){
		this->c = this->c + num;
		return *this;
	}
	MyChar MyChar::operator -(const int num){
		this->c = this->c - num;
		return *this;
	}
	void MyChar::setchar(const char x){
		this->c = x;
	}
	const char MyChar::getchar()const{
		return this->c;
	}
	const int MyChar::getchsize()const{
		return this->ch_size;
	}

	MyWord::MyWord(){
		word = nullptr;
		word_Size = 0;
	}
	MyWord::MyWord(MyChar *arr) :word(arr){
		;
	}
	 ifstream &operator>>(ifstream &cin, MyWord &obj){

		MyChar *h = new MyChar[20];
		int itr = 0;
		for (int i = 0; i<20; i++){
			cin >> h[i];
			itr++;
			if (h[i] == ' '){
				break;
			}
		}
		delete[]obj.word;
		obj.word = new MyChar[itr + 1];
		for (int i = 0; i < itr; i++){
			obj.word[obj.word_Size++] = h[i];
		}

		return cin;
	}
	 ostream &operator <<(ostream &cout, const MyWord &obj){

		for (int i = 0; i < obj.word_Size; i++){
			cout << obj.word[i];
		}
		cout << endl;
		return cout;
	}
	 MyWord &MyWord::operator=(const MyWord &obj){
		this->word = new MyChar[obj.getwsize() + 1];
		for (int i = 0; i < obj.getwsize(); i++){
			word[i] = obj.word[i];
		}
		return *this;
	}
	 const int MyWord::getwsize()const{
		return this->word_Size;
	}

	Sentence::Sentence(){
		this->Sent_Size = 0;
	}
	Sentence::Sentence(MyChar *obj) :sent(obj){
		;
	}
	 ifstream &operator>>(ifstream &cin, Sentence &obj){
		MyChar *arr = new MyChar[200];
		int itr = 0;
		for (int i = 0; i < 200; i++){
			cin >> arr[i];
			if (arr[i] == '.'){
				break;
			}
			else{
				itr++;
			}
		}
		obj.sent = new MyChar[itr + 1];
		for (int i = 0; i < itr; i++){
			obj.sent[obj.Sent_Size++] = arr[i];
		}
		return cin;
	}
	 ostream &operator<<(ostream &cout, const Sentence &obj){
		for (int i = 0; i < obj.Sent_Size; i++){
			cout << obj.sent[i];
		}
		return cout;
	}
	 MyChar &Sentence::operator [](int i){
		if (i >= 0 && i < this->getSize()){
			return sent[i];
		}
	}
	 const int Sentence::getSize()const{
		return this->Sent_Size;
	}

	 MyChar*Sentence::getsent()const{
		return this->sent;
	}

	Paragraph::Paragraph(){
		Psize = 0;
	}
	Paragraph::Paragraph(MyChar *arr) :Para(arr){
		;
	}
	ifstream &operator>>(ifstream &cin, Paragraph &obj){
		MyChar *arr = new MyChar[1000];
		int itr = 0;
		for (int i = 0; i < 1000; i++){
			cin >> arr[i];
			if (arr[i] == '\n'){
				break;
			}
			else{
				itr++;
			}
		}
		obj.Para = new MyChar[itr + 1];
		for (int i = 0; i < itr; i++){
			obj.Para[obj.Psize++] = arr[i];
		}
		return cin;
	}
	 ostream &operator<<(ostream &bout, const Paragraph &obj){
		for (int i = 0; i < obj.Psize; i++){
			bout << obj.Para[i];
		}
		bout << endl;
		return bout;
	}
	ofstream &operator<<(ofstream &cout, const Paragraph &obj){
		for (int i = 0; i < obj.Psize; i++){
			cout << obj.Para[i];
		}
		cout << endl;
		return cout;
	}
	void Paragraph::operator+(){
		for (int i = 0; i < this->Psize; i++){
			if (Para[i] >= 'a'&& Para[i] <= 'z')
			this->Para[i] - 32;
		}
	}
	void Paragraph::operator-(){
		for (int i = 0; i < this->Psize; i++){
			if (Para[i] >= 'A'&& Para[i] <= 'Z')
				this->Para[i] +32;
		}
	}
	void Paragraph::countpunc()const{
		int ch = 0;
		for (int i = 0; i < this->Psize; i++){
			if (Para[i] >= 65 && Para[i] <= 90){
				ch++;
			}
			else if (Para[i] >= 97 && Para[i] <= 122){
				ch++;
			}
			else if (Para[i] == '.' || Para[i] == '?' || Para[i] == ';' || Para[i] == ':' || Para[i] == '!', Para[i] == '"', Para[i] == ','){
				ch++;
			}
		}
		cout << "Number of Pronounciation And Punctuation Characters are: " << ch << endl;
	}
	int Paragraph::countsent(){
		int count = 0;
		for (int i = 0; i < Psize; i++){
			if (this->Para[i] == '.'){
				count++;
			}
		}
		return count;
	}
	void Paragraph::countwords(ofstream &fout){
		int sent = 0;
		int chwrds = 0;
		int wrd = 0;
		bool flag = true;
		for (int i = 0; i < this->Psize; i++){
			if (flag == true){
				fout << "Sentence " << sent + 1 << endl;
			}
			if (Para[i] != ' '){
				chwrds++;
				flag = false;
			}
			else if (Para[i] == ' '){
				wrd++;
				fout << "Word " << wrd << " of Sentence " << sent + 1 << " Contains " << chwrds << " Characters" << endl;
				chwrds = 0;
			}
			if (Para[i] == '.'){
				i++;
				wrd++;
				fout << "Word " << wrd << " of Sentence " << sent + 1 << " Contains " << --chwrds << " Characters" << endl;
				fout << "Words in Sentence " << sent + 1 << " are " << wrd << endl;
				sent++;
				wrd = 0;
				chwrds = 0;
				flag = true;
			}
		}
	}
	void Paragraph::countwords(int a){
		int sent = 0;
		int chwrds = 0;
		int wrd = 0;
		bool flag = true;
		for (int i = 0; i < this->Psize; i++){
			if (flag == true){
				cout << "Sentence " << sent + 1 << endl;
			}
			if (Para[i] != ' '){
				chwrds++;
				flag = false;
			}
			else if (Para[i] == ' '){
				wrd++;
				cout << "Word " << wrd << " of Sentence " << sent + 1 << " Contains " << chwrds << " Characters" << endl;
				chwrds = 0;
			}
			if (Para[i] == '.'){
				i++;
				wrd++;
				cout << "Word " << wrd << " of Sentence " << sent + 1 << " Contains " << --chwrds << " Characters" << endl;
				cout << "Words in Sentence " << sent + 1 << " are " << wrd << endl;
				sent++;
				wrd = 0;
				chwrds = 0;
				flag = true;
			}
		}
	}
	void Paragraph::countwords(){
		int sent = 0;
		int chwrds = 0;
		int wrd = 0;
		for (int i = 0; i < this->Psize; i++){
			if (Para[i] != ' '){
				chwrds++;
			}
			else if (Para[i] == ' '){
				wrd++;
				cout << "Word " << wrd << " of Sentence " << sent + 1 << " Contains " << chwrds << " Characters" << endl;
				chwrds = 0;
			}
			if (Para[i] == '.'){
				i++;
				wrd++;
				cout << "Word " << wrd << " of Sentence " << sent + 1 << " Contains " << --chwrds << " Characters" << endl;
				sent++;
				wrd = 0;
				chwrds = 0;
			}
		}
	}
	Paragraph &Paragraph::operator %(const int num){
		for (int i = 0; i < this->Psize; i++){
			if (this->Para[i] >= 65 && this->Para[i] <= 90)
			{
				this->Para[i] = this->Para[i] + num;

				if (this->Para[i] >= 91)
				{
					this->Para[i] = this->Para[i] - 'Z' + 'A' - 1;
				}
			}
			else if (this->Para[i] >= 97 && this->Para[i] <= 122)
			{
				this->Para[i] = this->Para[i] + num;
				if (this->Para[i] >= 123)
				{
					this->Para[i] = this->Para[i] - 'z' + 'a' - 1;
				}
			}
		}
		return *this;
	}
	Paragraph &Paragraph::operator +(const Paragraph &obj){
		if (this->Psize != 0 || obj.Psize != 0){
			this->Psize += obj.Psize;
			MyChar *temp = new MyChar[this->Psize + obj.Psize + 1];
			int i = 0;
			for (; i < Psize / 2; i++){
				temp[i] = this->Para[i];
			}
			for (int j = 0; j<obj.Psize; j++,i++){
				temp[i] = obj.Para[j];
			}
			temp[i] = '\0';
			cout << endl;
			delete[]this->Para;
			this->Para = temp;
			temp = nullptr;
		}
		return *this;
	}
	Paragraph &Paragraph::operator *(const int num){
		for (int i = 0; i < this->Psize; i++){
			if (this->Para[i] >= 65 && this->Para[i] <= 90)
			{
				this->Para[i] = this->Para[i] - num;

				if (this->Para[i] <= 64)
				{
					this->Para[i] = this->Para[i] + 'Z' - 'A' + 1;
				}
			}
			else if (this->Para[i] >= 97 && this->Para[i] <= 122)
			{
				this->Para[i] = this->Para[i] - num;
				if (this->Para[i] <= 96)
				{
					this->Para[i] = this->Para[i] + 'z' - 'a' + 1;
				}
			}
		}
		return *this;
	}
	bool Paragraph::operator==(const Paragraph &obj){
		bool flag = false;
		for (int i = 0; i < this->Psize; i++){
			if (this->Para[i] == obj.Para[i]){
				flag = true;
			}
			else{
				flag = false;
				break;
			}
		}
		return flag;
	}
	void Paragraph::wrdCheck()const{

		int itr = 0;
		bool end = false;
		while (1)
		{

			MyChar *arr = new MyChar[25];
			int size = 0;
			if (itr == this->Psize){
				end = true;
				break;
			}
			for (; itr < this->Psize; itr++)
			{
				if (Para[itr] != ' '&& Para[itr] != '.')
				{
					arr[size++] = Para[itr];
				}
				else
				{
					itr++;
					break;
				}
			}
			if (end == true)
			{
				break;
			}
			else
			{

				ifstream dict;
				ofstream write;
				dict.open("Dictionary.txt");
				write.open("Dictionary.txt",ios::app);
				bool found = false;
				while (!dict.eof())
				{
					bool same = true;
					MyChar *arr1 = new MyChar[25];
					int asize = 0;

					while (1)
					{
						if (dict.eof()){
							break;
						}
						MyChar a;
						dict >> a;
						if (a == '\n' || a == ' ' || a == '.')
						{
							break;
						}
						else
						{
							arr1[asize++] = a;
						}
					}
					if (size != asize)
					{
						same = false;
					}
					else
					{
						for (int i = 0; i < size; i++)
						{
							if (arr[i] != arr1[i])
							{
								same = false;
								break;
							}
						}
					}
					if (same == true)
					{
						found = true;
						break;
					}
				}
				if (found == true)
				{
					cout << "Word '";
					for (int i = 0; i < size; i++)
					{
						cout << arr[i];
					}
					cout << "' is in Dictionary" << endl;
				}
				else
				{
					cout << "Word '";
					for (int i = 0; i < size; i++)
					{
						cout << arr[i];
					}
					for (int i = 0; i < size; i++){
						write << arr[i];
					}
					write << endl;
					cout << "' is not in Dictionary" << endl;
				}
				dict.close();
			}
		}
	}
	void Paragraph::operator !(){
		int asize = 0;
		int save = 0;
		int fsize = 0;
		MyChar *arr=new MyChar[this->Psize];
		for (int i = 0; i < this->Psize; i++){
			arr[i] = this->Para[i];
		}
		for (int i = 0; i < this->Psize; i++){
			if (this->Para[i] != ' '&& this->Para[i]!='.'){
				asize++;
			}
			else {
				if (asize>0){
					save = i;
					i = i - asize;
					this->Para[i++] = asize + 48;
					for (; i < save; i++){
						this->Para[i] = ' ';
					}
					fsize++;
					asize = 0;
				}
			}
		}
		for (int i = 0; i < this->Psize; i++){
			cout << Para[i];
		}
		cout << endl;
		for (int i = 0; i < Psize; i++){
			this->Para[i] = arr[i];
		}
		cout << "Compression Ratio is: " << Psize/fsize << "%" << endl;
	}
	void Paragraph::operator ^ (int d){
		for (int i = 0; i < this->Psize; i++){
			cout << Para[i];
		}
		cout << endl;
	}
	const MyChar* Paragraph::getpara()const{
		return this->Para;
	}
	void Menu(){
		cout << "1. Reads a paragraph from a file, using the insertion operator >>" << endl;
		cout << "2. Check if two Paragraphs are Equal." << endl;
		cout << "3. Add two Paragraphs." << endl;
		cout << "4. Count Sentences in Whole text." << endl;
		cout << "5. Count Words in whole Text." << endl;
		cout << "6. Count Everything in Whole Text." << endl;
		cout << "7. Enter 7 to Exit." << endl;
		cout << "Enter A choice: ";
	}
	void submenu(){
		cout << "1. Write the paragraph to a file, using the extraction operator <<" << endl;
		cout << "2. Display the paragraph on screen, using the extraction operator <<" << endl;
		cout << "3. Convert all characters of the paragraph to UPPERCASE or lowercase" << endl;
		cout << "4. Count the number of English and Punctuation characters in the paragraph" << endl;
		cout << "5. Count number of characters in every word of every sentence." << endl;
		cout << "6. Encrypt Paragraph" << endl;
		cout << "7. Decrypt Paragraph" << endl;
		cout << "8. SpellCheck Words" << endl;
		cout << "9. Compress Paragraph" << endl;
		cout << "10. DeCompress Paragraph" << endl;
		cout << "-99. Return to Main Menu." << endl;
		cout << "\nEnter A Choice: ";

	}