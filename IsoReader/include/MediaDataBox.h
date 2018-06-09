/* 
 * File:   MediaDataBox.h
 * Author: kfr
 *
 * Created on 28. Juni 2016
 */
 
 /*
 * Represent the Media Data Box
 * save only size, type and content
 */

#ifndef MEDIADATABOX_H
#define	MEDIADATABOX_H

#include "Box.h"

class MediaDataBox : public Box {

public:
    MediaDataBox();
    virtual ~MediaDataBox();

	void print(std::ostream &ps);
	void saveImageToFile();

private:
};

#endif	/* MEDIADATABOX_H */

