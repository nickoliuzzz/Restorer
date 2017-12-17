#include "filesinfo.h"

FilesInfo::FilesInfo()
{

}

FilesInfo::FilesInfo(datas sizes,QString names)
{
    data = sizes;
    name = names;
}

FilesInfo& FilesInfo::operator=(const FilesInfo& right){
    if(this == &right)
        return *this;
    data = right.data;
    name = right.name;
    return *this;
}

datas FilesInfo::getData(){
    return data;
}
QString FilesInfo::getName(){
    return name;
}
