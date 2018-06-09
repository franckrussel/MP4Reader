/* 
 * File:   MediaDataBox.cpp
 * Author: kfr
 * 
 * Created on 28. Juni 2016
 */

#include "include/MediaDataBox.h"

#include <fstream>
#include <sstream>

//#include "libs/cryptopp561/osrng.h"
#include "libs/cryptopp561/modes.h"
//#include "libs/cryptopp561/hex.h"
#include "libs/cryptopp561/base64.h"

#include "libs/rapidxml/rapidxml.hpp"
#include "libs/rapidxml/rapidxml_print.hpp"
#include "libs/rapidxml/rapidxml_utils.hpp"

using namespace std;
using namespace rapidxml;

MediaDataBox::MediaDataBox() {
}

MediaDataBox::~MediaDataBox() {
}

/**
* parse xml and save image 
* to file
* 
*/
void MediaDataBox::saveImageToFile(){
	vector<char> xml_copy(this->mdat_box_content.begin(), this->mdat_box_content.end());
	xml_copy.push_back('\0');

	xml_document<> doc;
	doc.parse<0>(xml_copy.data());

	xml_node<>* metadata_node = doc.first_node("tt")->first_node("head")->first_node("metadata");
	if(metadata_node != 0) {
		int counter = 1;
		string image_b64, image;
		for (xml_node<>* node = metadata_node->first_node(); node; node = node->next_sibling()) {
			image_b64 = node->value();
			
			//decode base64 encoded image data
			CryptoPP::StringSource ss((byte*)image_b64.data(), image_b64.size(), true,
				new CryptoPP::Base64Decoder(
					new CryptoPP::StringSink(image)
				) // Base64Decoder
			);
			
			//save images to file
			stringstream filename_stream;
			filename_stream<< "image00" <<counter <<".PNG";
			string filename = filename_stream.str();
			std::ofstream image_file;
			//imageFile << image;
			image_file.open(filename.c_str(), ios::out | ios::binary);
			image_file.write(image.c_str(), image.size());
			image_file.close();
			counter++;
		}
			
	}
	else{
		cout << "metadata node was not found" <<endl;
	}
}

/**
* print Media Data Box content
* 
* @param output stream
*/
void MediaDataBox::print(std::ostream &ps) {
	ps << "Content of mdat box is: " << this->mdat_box_content << endl;
	this->saveImageToFile();
}
