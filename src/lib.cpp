#include "lib.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <pthread.h>

#define FILE_COUNT 10

using namespace std;


unsigned long soloThread()
{
	stringstream ss;
	
	unsigned long res = 0;
	
	for (size_t i = 1; i <= FILE_COUNT; ++i)
	{
		ss << "../Files/" << i << ".txt";
		ifstream inp(ss.str());
		if (inp.is_open())
		{
			while (!inp.eof())
			{
				unsigned int cur;
				inp >> cur;
				res += cur;
			}
		}
		else
		{
			cerr << "Error: File " << ss.str() << " not founded" << endl;
		}
		ss.str(string());
		inp.close();
	}
	return res;
}

struct threadInp
{
	int fileNum;
	unsigned long res;
};

void *oneThread(void *threadData){
	stringstream ss;
	threadInp *thInp = (threadInp*) threadData;
	
	ss << "../Files/" << thInp->fileNum << ".txt";
	ifstream inp(ss.str());
	if (inp.is_open())
	{
		while (!inp.eof())
		{
			unsigned int cur;
			inp >> cur;
			thInp->res += cur;
		}
	}
	else
	{
		cerr << "Error: File " << ss.str() << " not founded" << endl;
	}
	ss.str(string());
	inp.close();
}

unsigned long multiThread()
{
	pthread_t threads[10];
	
	threadInp* threadData = new threadInp[FILE_COUNT];
	unsigned long fullRes = 0;
	
	for (int i = 0; i < FILE_COUNT; ++i)
	{
		threadData[i].fileNum = i + 1;
		threadData[i].res = 0;
		pthread_create(&(threads[i]), nullptr, oneThread, &threadData[i]);
	}
	for (int i = 0; i < FILE_COUNT; ++i)
	{
		pthread_join(threads[i], nullptr);
		fullRes += threadData[i].res;
	}
	return fullRes;
}