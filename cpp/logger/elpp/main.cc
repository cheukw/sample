#include "easylogging++.h"
#include "elpp.h"


//INITIALIZE_EASYLOGGINGPP
int main()
{
	el::Loggers::addFlag(el::LoggingFlag::DisableApplicationAbortOnFatalLog);

	LOG(INFO) << "My first info log using default logger";

	//LOG(ERROR) << "error " << 2;
	//LOG(TRACE);
	//LOG(DEBUG);
	//
	//LOG(ERROR);
	//LOG(WARNING);
	//LOG(INFO);
	//VLOG(0);

	//LOG(FATAL);

	//SetConfigurations();
	SetLogger();
	return 0;
}