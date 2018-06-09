/* 
 * File:   Box.cpp
 * Author: kfr
 * 
 * Created on 28. Juni 2016
 */


#include "include/Box.h"
#include "include/MovieFragmentBox.h"
#include "include/MediaDataBox.h"
#include "include/BoxLookup.h"

#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

Box::Box() {

    this->size = 0; 
    this->type = "";
	this->data_size = 8; // 4 bytes size and 4 bytes type
}

Box::~Box() {
}

/**
* iterates over the file and save all boxes
* 
* @param input file
*/
int Box::parseChildren(ifstream &ifs) {
    
    int ret = 0;

    unsigned int box_pos = ifs.tellg();

    unsigned int box_size;
	char* box_size_char = new char[4]; 
	char box_type[5] = { 0, 0, 0, 0, 0 };
    
    //unsigned int pos = 0;

    while (true) {
		//file end
        if (!ifs.good()) {
            return -1;
        }

		// read box size - 32 bit
		ifs.read(box_size_char,4);
		//save size from char array into int using bit shifting
		box_size = (static_cast<unsigned char>(box_size_char[0]) << 24) + (static_cast<unsigned char>(box_size_char[1]) << 16) 
		+ (static_cast<unsigned char>(box_size_char[2]) << 8) + static_cast<unsigned char>(box_size_char[3]);

		// read box type - 32 bit
        ifs.read(box_type, 4);

		// create empty box
		Box *child_box = BoxLookup::lookup(box_type);
        child_box->size = box_size;
		
		//for moof and traf box parse children 
		if(child_box->type == "moof" || child_box->type == "traf") {
			ret = child_box->parseChildren(ifs);
			
		}
		//for mdat box save the content into a string
		else if(child_box->type == "mdat"){
			stringstream str_stream;
			str_stream << ifs.rdbuf();//read data from the file
			child_box->mdat_box_content = str_stream.str();
		}
		//just seek to the next box
		else {
			int pos_to_seek = child_box->size - child_box->data_size;
			ifs.seekg(pos_to_seek, ios::cur);
		}

		if(ret < 0)
			return ret;
        
        this->children.push_back(child_box);
		
		//save the size of read data
        this->data_size += child_box->size;

		// get cur file pos
       // pos = ifs.tellg();

		// end read of children when: read data size match box parent size 
        if (this->data_size == this->size ){
			break;			
        }
    }

	return 0;
}

/**
* set the type of a box
* 
* @param type of box
*/
void Box::setType(std::string type) {
    this->type = type;
}

/**
* print size and type of each box
* 
* @param output stream
*/
void Box::print(ostream &ps) {
	vector<Box *>::const_iterator ci;
	for (ci = this->children.begin(); ci != this->children.end(); ci++) {
		ps << "Found box of type " << (*ci)->type <<" and size " << (*ci)->size <<endl;
		(*ci)->print(ps);
    }
}
