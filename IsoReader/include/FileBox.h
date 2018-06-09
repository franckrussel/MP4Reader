/* 
 * File:   FileBox.h
 * Author: kfr
 *
 * Created on 28. Juni 2016
 */
 
 
/* internal boxtype to represent 
 * a file holding all boxes 
 * */
 
#ifndef FILEBOX_H
#define	FILEBOX_H

#include "Box.h"
#include <iostream>
//#include <string>

class FileBox : public Box {
public:
    FileBox();
    virtual ~FileBox();

    int parse(std::ifstream &ifs);
private:

};

#endif	/* FILEBOX_H */

