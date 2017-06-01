#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
	register int i;
	int BUFF_SIZE = 1024;
	char buffer_1[BUFF_SIZE], buffer_2[BUFF_SIZE];

	if (argc != 3){
		cout << "Please try again\n";
		cout << "Usage: program_name file_1 file_2\n";
		return 1;
	}

	ifstream file_1(argv[1], ios::in | ios::binary);
	ifstream file_2(argv[2], ios::in | ios::binary);

	if (!file_1 && !file_2){
		cout << "Can not open one of the files or it doesn't exist!";
		return 1;
	}

	do{
		file_1.read((char*)&buffer_1, BUFF_SIZE);
		file_2.read((char*)&buffer_2, BUFF_SIZE);

		if (file_1.gcount() != file_2.gcount()){
			file_1.close();
			file_2.close();
			cout << "Files have different length\n";
			return 0;
		}

		for(i = 0; i < file_1.gcount(); i++){
			if (buffer_1[i] != buffer_2[i]){
				file_1.close();
				file_2.close();
				cout << "Files are different\n";
				return 0;
			}
		}

	}while (!file_1.eof() && !file_2.eof());

	cout << "Files are the same!" << endl;
	file_1.close();
	file_2.close();

	return 0;
}