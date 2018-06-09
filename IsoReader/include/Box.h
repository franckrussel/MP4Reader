/* 
 * File:   Box.h
 * Author: kfr
 *
 * Created on 28. Juni 2016
 */

#ifndef BOX_H
#define	BOX_H

#include <iostream>
#include <vector>

/*
 * Represent the structure of a box
 * contains only the size and type
 */

class Box {

public:
    Box();
    virtual ~Box();
    
    unsigned int size;						

    unsigned int data_size; //size of read data
	std::string mdat_box_content;

    virtual void print(std::ostream &ps);			

    virtual int parseChildren(std::ifstream &ifs);	
    
	virtual void setType(std::string type);
    
protected:
    std::string type;

private:
    std::vector<Box *> children;
};

#endif	/* BOX_H */

