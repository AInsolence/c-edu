#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>


int main(int argc, char const *argv[])
{
	std::string first_name, second_name, full_name, part_str;
	first_name = {'A', 'n', 't', 'o', 'n'};
	second_name = "Insolence";
	full_name = first_name + ' ';
	full_name += second_name;
	copy(full_name.begin(), full_name.end(),\
			std::ostream_iterator<char>(std::cout));
	part_str.assign(full_name.begin(), full_name.begin() + 3);
	std::cout << std::endl << part_str << std::endl;
	first_name.append(" ");
	first_name.append(part_str);
	std::cout << first_name << std::endl;
	std::string *ptr_str;
	ptr_str = new std::string;
	*ptr_str = "XXXXX";
	//NOTE!!! here we use INDEX as argument, not iterator!
	first_name.insert(3, *ptr_str);
	std::cout << first_name << std::endl;
	delete ptr_str;
	copy_if(full_name.begin(), full_name.end(),\
			std::ostream_iterator<char>(std::cout),\
				[](char ob){return ob != 'X';});
	auto s_name_index = full_name.rfind("Insolence");
	std::cout << std::endl << full_name.substr(s_name_index) << std::endl;

	return 0;
}