# Sample MP4 parser
 C++ application that prints the layout of a sample mp4 file and extracts the content of the MDAT box.
 It is tested and worked on Mac OS X EL Capitan (10.11.2)
 
## Development Process 
 
 The *Box* class represents the structure of a box and every other boxes inherit from him.
 
 The *FileBox* class is an internal box just to represent the mp4 file as box, so it has 
 two children boxes MOOF and MDAT.
 
 *Boxlookup* class is used to create and set the type of an empty box.
 
 *parse* method is used to parse *FileBox* and *parseChildren* for boxes with children.
 
 For boxes without children, after the size and type are read, jump to the next box.
 
 Therefore after the file is loaded, it is set as source for the *FileBox*. Then the *FileBox* is parsed,
 *parseChildren* is called for every Box with children and for the other boxes the file pointer is seek to
 the next box. *parseChildren* is leave when the data read match the size of parent box.
 
 A *saveImageToFile* method is used to save the images from MDAT box into files. Since the mdat box content
 has a xml structure, rapidxml library is used to parse the content and Cryptopp to decode the base64 encoded images.
 
## Building and Running  
 you can run IsoReader which is in Release or Debug folder with following command in a terminal:
 ```
 ./IsoReader
 ```
 The project is built in Mac OS using [CodeLite](http://codelite.org). After creating the project, add Boost library
 in CodeLite and you should be able to build without errors.

