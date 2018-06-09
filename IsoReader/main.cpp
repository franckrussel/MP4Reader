/* 
 * File:   main.cpp
 * Author: kfr
 * 
 * Created on 28. Juni 2016
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <boost/asio.hpp>

#include "include/FileBox.h"
#include "include/BoxLookup.h"

using namespace std;
/*
 * function adapted from
 * http://www.boost.org/doc/libs/1_54_0/doc/html/boost_asio/example/cpp03/iostreams/http_client.cpp
 * 
 * load file and save data into a string
 * @param server: URL path
 * @param file: file name
 * */
string loadFile(const string& server, const string& file){
	
	try
	{
		boost::asio::ip::tcp::iostream boost_stream(server, "http");
		boost_stream.expires_from_now(boost::posix_time::seconds(60));

		if (!boost_stream)
		{ 
			std::cout << "Unable to connect: " << boost_stream.error().message() << "\n";
			return ""; 
		}

		// ask for the file
		boost_stream << "GET " << file << " HTTP/1.0\r\n";
		boost_stream << "Host: " << server << "\r\n";
		boost_stream << "Accept: */*\r\n"; 
		boost_stream << "Connection: close\r\n\r\n";

		// Check that response is OK.
		string http_version;
		boost_stream >> http_version;
		unsigned int status_code;
		boost_stream >> status_code;
		string status_message;
		getline(boost_stream, status_message);
		if (!boost_stream && http_version.substr(0, 5) != "HTTP/")
		{ 
			cout << "Invalid response\n";
			return ""; 
		}
		if (status_code != 200)
		{ 
			cout << "Response returned with status code " << status_code << "\n";
			return "";
		}

		// Process the response headers, which are terminated by a blank line.
		string header;
		while (std::getline(boost_stream, header) && header != "\r"){}
		// Write the remaining data to output.
		stringstream ss;
		ss << boost_stream.rdbuf();
		return ss.str();
	}
	catch(std::exception& e)
	{
		return e.what();
	}

}
int main(int argc, char** argv) {
	//http://demo.castlabs.com/tmp/text0.mp4
	string result = loadFile("demo.castlabs.com", "/tmp/text0.mp4");
	
	if(result.size() == 0){
		cout << "Failed to load file http://demo.castlabs.com/tmp/text0.mp4"<<endl;
		return 0;
	}
	else{
		//save file locally
		std::ofstream of("text0.mp4", std::ios::binary);
		of << result;
		of.close();
		
		char *input = "text0.mp4";
		FileBox *fb;
		unsigned int input_file_size;
					
		cout << "Successfully load file http://demo.castlabs.com/tmp/text0.mp4 "<< endl;
			
		ifstream ifs;
		ifs.open(input, ios_base::in | ios_base::binary);
			
			// determine file size of input file
		ifs.seekg(0L, ios::end);
		input_file_size = ifs.tellg();
		ifs.seekg(0L, ios::beg);
		
		//parse file and save all boxes with their type and size 
		//filebox used to represent a file holding boxes
		fb = (FileBox *) BoxLookup::lookup(BoxLookup::BOXTYPE_FILE);
		fb->size = input_file_size;
		fb->parse(ifs);
		ifs.close();
		
		//print size, type and media data box content
		fb->print(cout);
		
		return 0;
	}
}