/* 
 * File:   MovieFragmentHeaderBox.h
 * Author: kfr
 *
 * Created on 28. Juni 2016
 */

 /*
 * Represent the Media Fragment Header Box
 * save only size and type
 */
 
#ifndef MOVIEFRAGMENTHEADERBOX_H
#define	MOVIEFRAGMENTHEADERBOX_H

#include "Box.h"

class MovieFragmentHeaderBox : public Box{

public:
    MovieFragmentHeaderBox();
    virtual ~MovieFragmentHeaderBox();
    
private:
};

#endif	/* MOVIEFRAGMENTHEADERBOX_H */

