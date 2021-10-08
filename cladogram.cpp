#include <iostream>
#include <cmath>
#include <array>
#include <string>

void printRepeating(const char* c, int times){
	for(int i = 0; i < times; i++){
		std::cout << c;
	}
}
void printNewRow(std::string* species, int size){
	std::cout << "+";
	for(int i = 0; i < size; i++){
		printRepeating("-", species[i].size() + 2);
		std::cout << "+";
	}
}
int dnaDifferences(std::string& dna1, std::string& dna2, int size){
	int differences = 0; 
	for(int i = 0; i < size; i++){
		if(dna1[i] != dna2[i]) differences++;
	}
	return differences;
}

int main(int argc, char** argv){
	int col1Length = 0;
	std::array<std::string, 5> species = {"Horse", "Gorilla", "Monkey", "Chimpanzee", "Human"};
	std::array<std::string, 5> dna = {
		"ggtctgttcatacacaatt",
		"ggctcagtctatagacatt",
		"acgtcagttcatagctagt",
		"aggtcagtttctagccagt",
		"aggtcagtttatagccagt",
	};
	for(int i = 0; i < species.size(); i++){
		col1Length = std::max(col1Length, (int)species[i].size());
	}

	printRepeating(" ", col1Length + 3);
	printNewRow(species.data(), species.size());
	std::cout << "\n";
	printRepeating(" ", col1Length + 3);
	std::cout << "|";
	int i = 0;
	for (i; i < species.size(); i++){
		std::cout << " " << species[i] << " |";
	}
	std::cout << "\n+";
	printRepeating("-", col1Length + 2);
	printNewRow(species.data(), species.size());

	for (i = 0; i < species.size(); i++){
		std::cout << "\n| " << species[i];
		printRepeating(" ", col1Length - species[i].size());
		std::cout << " |";
		for (int j = 0; j < species.size(); j++){
			if(i - j < 0) {
				std::cout << " ";
				for(int k = 0; k < species[j].size(); k++) std::cout << " ";
			}else {
				int differences = dnaDifferences(dna[i], dna[j], dna[i].size());
				int digits = differences < 10? 1 : log10(differences) + 1;
				std::cout << " " << differences;
				for(int k = 0; k < species[j].size()-digits; k++) std::cout << " ";
			}
			std::cout << " |";
		}
		std::cout << "\n+";
		printRepeating("-", col1Length + 2);
		printNewRow(species.data(), species.size());
	}
	std::cout << "\n\n";
	return 0;
}

