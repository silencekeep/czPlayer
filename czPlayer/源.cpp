#include <cstdio>
#include <chrono>
#include <Windows.h>
#include "D:\\czPlayer\\x64\\st.h"

int main() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwMode = 0;
	GetConsoleMode(hOut, &dwMode);
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(hOut, dwMode);
	printf("\033[?25l");
	while (true) {
		for (int k = 0; k < 2400; k++) {
			auto start = std::chrono::high_resolution_clock::now();
			for (int j = 5; j < 64; j++) {
				printf("\033[%d;%dH\033[38;2;%d;%d;%dm¨€¨€",
					1, j * 2 + 1,
					frame[k][1 + j * 48].R,
					frame[k][1 + j * 48].G,
					frame[k][1 + j * 48].B
				);
			}
			for (int i = 1; i < 48; i++) {
				for(int j=0;j < 64;j++){
					printf("\033[%d;%dH\033[38;2;%d;%d;%dm¨€¨€", 
						i + 1, j * 2 + 1, 
						frame[k][i + j * 48].R,
						frame[k][i + j * 48].G,
						frame[k][i + j * 48].B
					);
				}
			}
			auto end = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
			double fps = 1e9 / duration;
			printf("\033[1;1H\033[31m\033[42mFPS: %2.2lf \033[0m",fps);
		}
	}
}

