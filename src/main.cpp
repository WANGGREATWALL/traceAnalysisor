#include <fstream>
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct thread {
	string threadName;
	uint32_t pid;
	uint32_t tid;
	float_t time_running;
};

int main()
{
	ifstream config("../../config.txt");
	assert(config.is_open());
	cout << "Open config.txt successed!" << endl;

	string lineInfo;
	vector<thread> threads;
	while (getline(config, lineInfo))
	{
		thread thd;
		istringstream thdStr(lineInfo);
		thdStr >> thd.threadName;
		thdStr >> thd.pid;
		thdStr >> thd.tid;
		thdStr >> thd.time_running;

		threads.push_back(thd);
	}
	config.close();

	return 0;
}