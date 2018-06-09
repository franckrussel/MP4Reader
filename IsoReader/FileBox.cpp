/* 
 * File:   FileBox.cpp
 * Author: kfr
 * 
 * Created on 28. Juni 2016
 */

#include "include/FileBox.h"
#include <fstream>

using namespace std;

FileBox::FileBox() {
}

FileBox::~FileBox() {
}

int FileBox::parse(std::ifstream &ifs) {
    int ret_value = 0;
	this->data_size = 0; //size and type has not been read
    // just start parsing of all child boxes
    ret_value = Box::parseChildren(ifs);
    return ret_value;
}
