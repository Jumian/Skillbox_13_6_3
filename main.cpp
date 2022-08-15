#include <iostream>
#include "vector"


int input(std::string prompt){
    int val=0;
    std::cout << prompt;
    std::cin >> val;
    return val;
}

void print (std::vector<int> vec,int head,int realsize){
    int index=(20+head-realsize)%20;
    for(int i =index;i<realsize+index;++i) std::cout  << /* i%20 << ":"<< */ vec[i%20] << " ";
    std::cout << std::endl<< "head = " << head <<" used size = "<< realsize  << std::endl;
}

int main() {
    std::vector<int> db(20);
    db={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int current=0,realSize=0, val=-1;
    std::printf("Circular buffer size is 20. Please fill items\n");
    do {
        val = input(/*"head = "+std::to_string(current)". "*/+ "Input next:");
//        std::cout << val<<std::endl;
        if (val==-1) print(db,current,realSize);
        else {
            if (current<db.size()&&current>=0){
                db[current]=val;
                ++current;
                if(current>=db.size()) current=0;
                if (realSize<db.size()) ++realSize;
            }
        }
    } while (true);
    return 0;
}
