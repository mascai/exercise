#include <iostream>
#include <fstream>

#include <unistd.h>
#include <fcntl.h>

using namespace std;

int main() {
	string str;
    cout << "______C++ string getline________" << endl;
    for (int i = 0; i < 5; ++i) {
	    ifstream fin("data/medium.log", ios_base::in);
	    int cnt = 0;
	    clock_t start = clock();
	    while (getline(fin, str)) {
	        ++cnt;
	    }
	    clock_t end = clock();
	    
	    printf("C++ getline %.3f millisecond\n", double(end - start));
	    printf("C++ getline %.3f second\n", double(end - start) / (double)CLOCKS_PER_SEC);
	    printf("%d\n", cnt);
	    printf("***************************************\n");
	    fin.close();
	}

	cout << "\n______C string fgets________" << endl;
	for (int i = 0; i < 5; ++i) {
		char buff[255];
		FILE *fd = fopen("data/medium.log", "r");
		int cnt = 0;
		clock_t start = clock();
		while (fgets(buff, 255, fd) != NULL) {
			//puts (buff);
			++cnt;
		}
		clock_t end = clock();
		    
		printf("C string fgets %.3f millisecond\n", double(end - start));
		printf("C string fgets %.3f second\n", double(end - start) / (double)CLOCKS_PER_SEC);
		printf("%d\n", cnt);
		fclose(fd);
	}
	printf("***************************************\n");
	
	cout << "\n______C syscall________" << endl;
	for (int i = 0; i < 5; ++i) {
		char buff[255];
		int cnt = 0;
	    int fd = open("data/medium.log", O_RDONLY);
	    clock_t start = clock();
	    while (read(fd, buff, 255) > 0) {
	    	++cnt;
	    }
	    clock_t end = clock();
	    printf("C syscall %.3f millisecond\n", double(end - start));
		printf("C syscall %.3f second\n", double(end - start) / (double)CLOCKS_PER_SEC);
		printf("%d\n", cnt);
		close(fd);
	}
	printf("***************************************\n");
	
}
