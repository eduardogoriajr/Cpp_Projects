#include <iostream>
using namespace std;
int main() {

	FILE* fp;
		fp = fopen("C:\\TW01\\demo.txt", "w");
	fclose(fp);
	system("pause > 0");
	return 0;
}
