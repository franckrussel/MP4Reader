/* 
 * File:   BoxLookup.h
 * Author: kfr
 *
 * Created on 28. Juni 2016
 */

#ifndef BOXLOOKUP_H
#define	BOXLOOKUP_H

#include "Box.h"
/**
* used to generate empty boxes of a certain type
*/
class BoxLookup {
	
public:
	static Box *lookup(std::string type);
    
    /* internal boxtype to represent a file holding all boxes */
    static const char BOXTYPE_FILE[];
};

#endif	/* BOXLOOKUP_H */

