// exobrain++.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <boost/regex.hpp>
#include <rocksdb/db.h>
#include <boost/python.hpp>
#include "exobrain2.h"

using namespace std;
//using namespace boost;

char const* greet()
{
   return "hello, world";
}

BOOST_PYTHON_MODULE(hello_ext)
{
    using namespace boost::python;
    def("greet", greet);
}

int main()
{
    rocksdb::DB* db;
    rocksdb::Options options;
    options.keep_log_file_num = 20;
    options.create_if_missing = true;
    rocksdb::Status status =
    rocksdb::DB::Open(options, "c:\\users\\chun\\testdb", &db);
    std::cout << "log number:" << options.keep_log_file_num << std::endl;
    if (!status.ok()) cerr << status.ToString() << endl;
    std::string value;
    std::string key("你好");

	rocksdb::Status s = db->Get(rocksdb::ReadOptions(), key, &value);
    if (s.ok()) std::cout << "value:" << value << std::endl;

	//if (s.ok()) s = db->Put(rocksdb::WriteOptions(), key, value);
	//if (s.ok()) s = db->Delete(rocksdb::WriteOptions(), key);
    //assert(status.ok());
    delete db;

	std::string str = "chinaen 8Glish";
	boost::regex expr("(\\w+)\\s(\\w+)");
	std::cout << boost::regex_match(str, expr) << std::endl;
	boost::smatch what;

	if (boost::regex_search(str, what, expr))//正则表达式检索
    {
        std::cout << what[0] << std::endl;
        std::cout << what[1] << std::endl;
        std::cout << what[2] << std::endl;
        std::cout << what[3] << std::endl;
    }
    else
    {
        std::cout << "检索失败" << std::endl;
    }

	return 0;
}
