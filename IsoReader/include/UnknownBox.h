/* 
 * File:   UnknownBox.h
 * Author: kfr
 *
 * Created on 28. Juni 2016
 */
 
  /*
 * Represent the uuid box
 * contains only the size and type
 */

#ifndef UNKNOWNBOX_H
#define	UNKNOWNBOX_H

#include "Box.h"

class UnknownBox : public Box {

public:
    UnknownBox();
    virtual ~UnknownBox();
	
private:
};

#endif	/* UNKNOWNBOX_H */

