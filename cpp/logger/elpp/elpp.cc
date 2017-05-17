#define ELPP_STL_LOGGING
#include "easylogging++.h"
#include "elpp.h"

INITIALIZE_EASYLOGGINGPP
void SetConfigurations()
{
	el::Configurations defaultConf;
	defaultConf.setToDefault();
	LOG(INFO) << "Using el::Configurations class";

	/// 重新设置INFO级别的配置项FORMAT的值  
	defaultConf.set(el::Level::Info, el::ConfigurationType::Format, "%datetime %level %msg");
	/// 重新设置配置  
	el::Loggers::reconfigureLogger("default", defaultConf);
	LOG(INFO) << "Using el::Configurations class";

	/// 重新设置GLOBAL级别的配置项FORMAT的值  
	defaultConf.setGlobally(el::ConfigurationType::Format, "%datetime %msg");
	/// 重新设置配置  
	el::Loggers::reconfigureLogger("default", defaultConf);
	LOG(INFO) << "Using el::Configurations class";
}

el::Logger* new_logger = el::Loggers::getLogger("network");

void SetLogger()
{
	CLOG(INFO, "testlog");

	el::Logger* new_logger = el::Loggers::getLogger("testlog");
	CLOG(INFO, "testlog") << "this is a new logger";

	std::vector<std::string> allLoggers;
	el::Loggers::populateAllLoggerIds(&allLoggers);
	LOG(INFO) << allLoggers;

	if (el::Loggers::hasLogger("network")) {
		LOG(INFO) << "has network";
	}
	else {
		LOG(INFO) << "not has network";
	}

	if (el::Loggers::hasLogger("testlog")) {
		LOG(INFO) << "has ccc network";
	}
	else {
		LOG(INFO) << "not ccc has network";
	}
}

// SetLogger();