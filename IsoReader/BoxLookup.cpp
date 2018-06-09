/* 
 * File:   BoxLookup.cpp
 * Author: kfr
 * 
 * Created on 28. Juni 2016
 */

#include <string>

#include "include/BoxLookup.h"
#include "include/FileBox.h"
#include "include/UnknownBox.h"
#include "include/MediaDataBox.h"
#include "include/MovieFragmentBox.h"
#include "include/MovieFragmentHeaderBox.h"
#include "include/TrackFragmentBox.h"
#include "include/TrackFragmentHeaderBox.h"
#include "include/TrackRunBox.h"

const char BoxLookup::BOXTYPE_FILE[] = "file";

const char BOXTYPE_MOOF[] = "moof";
const char BOXTYPE_MFRA[] = "mfra";
const char BOXTYPE_MDAT[] = "mdat";
const char BOXTYPE_MFHD[] = "mfhd";
const char BOXTYPE_TRAF[] = "traf";
const char BOXTYPE_TFHD[] = "tfhd";
const char BOXTYPE_TRUN[] = "trun";

Box *BoxLookup::lookup(std::string type){

    Box *b;
    if(!type.compare(BOXTYPE_FILE)) {
        b = new FileBox();
    }
	else if(!type.compare(BOXTYPE_MOOF)) {
        b = new MovieFragmentBox();
    } 
	else if(!type.compare(BOXTYPE_MFHD)) {
        b = new MovieFragmentHeaderBox();
    } 
	else if(!type.compare(BOXTYPE_TRAF)) {
        b = new TrackFragmentBox();
    } 
	else if(!type.compare(BOXTYPE_TFHD)) {
        b = new TrackFragmentHeaderBox();
    } 
	else if(!type.compare(BOXTYPE_TRUN)) {
        b = new TrackRunBox();
    } 
	else if(!type.compare(BOXTYPE_MDAT)) {
        b = new MediaDataBox();
    } 
	else {
        b = new UnknownBox();
    }
    b->setType(type);

    return b;
}
