/* 
 * File:   TrackFragmentHeaderBox.h
 * Author: kfr
 *
 * Created on 28. Juni 2016
 */

 /*
 * Represent the Track Fragment Header Box
 * save only size and type
 */
 
#ifndef TRACKFRAGMENTHEADERBOX_H
#define	TRACKFRAGMENTHEADERBOX_H

#include "Box.h"

class TrackFragmentHeaderBox : public Box{

public:
    TrackFragmentHeaderBox();
    virtual ~TrackFragmentHeaderBox();
	
private:
};

#endif	/* TRACKFRAGMENTHEADERBOX_H */

