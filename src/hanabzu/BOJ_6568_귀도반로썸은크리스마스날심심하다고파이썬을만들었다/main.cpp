﻿/* hanabzu */
/* BOJ_6568 귀도 반 로썸은 크리스마스날 심심하다고 파이썬을 만들었다 */

#include <iostream>
#include <bitset>

using namespace std;

bitset<8> memory[32];
unsigned char adder;
unsigned char pc;
unsigned char address;
unsigned char op;

void read_case();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin.eof() == false) // loop until EOF
		read_case();
	return 0;
}

void read_case() {
	for (int i = 0; i < 32; i++) {
		cin >> memory[i];
		if (cin.eof())
			return;
	}

	adder = 0;
	pc = 0;

	while (true) {
		op = (memory[pc] >> 5).to_ulong();
		address = (memory[pc] << 3 >> 3).to_ulong();
		pc = (pc + 1) % 32; // program counter has 5 bits
		
		switch (op) {
		case 0: // STA
			memory[address] = bitset<8>(adder); // unsigned char to bitset
			break;
		case 1: // LDA
			adder = memory[address].to_ulong();
			break;
		case 2: // BEQ
			if (adder == 0) {
				pc = address;
			}
		case 3: // NOP
			break;
		case 4: // DEC
			adder -= 1;
			break;
		case 5: // INC
			adder += 1;
			break;
		case 6: // JMP
			pc = address;
			break;
		case 7: // HLT
			cout << bitset<8>(adder) << '\n';
			return;
		}
	}
}
